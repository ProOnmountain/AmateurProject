#include "mainui.h"
#include "ui_mainui.h"
#include "battery.h"
#include <QFile>
#include <QDebug>
#include <thread>
#include <QMetaType>

const QString qssFileDir(":/mainuistyle.qss");
const QString serialPortName("ttyS1");

MainUI::MainUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainUI)
{
    ui->setupUi(this);
    initUI();
}

MainUI::~MainUI()
{
    delete ui;
}

void MainUI::initUI()
{
    ui->mainToolBar->hide();
//    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    timeCycle = 10;
    lineNum = 11;
    //添加电池
    Battery *battery_1 = new Battery(this);//添加电池图标
    Battery *battery_2 = new Battery(this);//添加电池图标
    battery_1->setValue(10);
    battery_2->setValue(30);
    QVBoxLayout *batteryBox = new QVBoxLayout();
    batteryBox->addWidget(battery_1);
    batteryBox->addWidget(battery_2);
    ui->horizontalLayout_3->addLayout(batteryBox, 1);

    //创建浮动按钮
    cycleButton = new FloatButton(this);
    for(int i = 5; i <= 320; i = i *2)
    {
        cycleButton->addAction(new QAction(QString("%1").arg(i) + " s"));
    }
    cycleButton->setArrowType(Qt::NoArrow);
    cycleButton->show();
    QObject::connect(cycleButton,SIGNAL(triggered(QAction*)), this, SLOT(setTimeCycle(QAction*)));

    //创建配置界面
    configUI = new ConfigUI(this);
    QObject::connect(configUI, SIGNAL(showLineIndex(int, int)), this, SLOT(setVisibleIndex(int, int)));
    configUI->setWindowModality(Qt::ApplicationModal);
    configUI->show();

    //初始化绘图界面
    QChart *paint_chart = new QChart;
    ui->widget_painter->setChart(paint_chart);

    //初始化曲线和坐标轴
    QValueAxis *xAxis = new QValueAxis;
    xAxis->setRange(0, 1);
    QValueAxis *yAxis1 = new QValueAxis;
    yAxis1->setRange(0, 1);
    yAxis1->setVisible(false);
    axisesY.append(yAxis1);
    QValueAxis *yAxis2 = new QValueAxis;
    yAxis2->setRange(0, 1);
    yAxis2->setVisible(false);
    axisesY.append(yAxis2);
    paint_chart->addAxis(xAxis, Qt::AlignBottom);
    paint_chart->addAxis(yAxis1, Qt::AlignLeft);
    paint_chart->addAxis(yAxis2, Qt::AlignRight);
    for(int i = 0; i < lineNum; ++i)
    {
        QSplineSeries *line = new QSplineSeries;
        lines.append(line);
        paint_chart->addSeries(line);
        line->setVisible(false);
        line->attachAxis(xAxis);
    }

    //开启接收数据的线程
    function = new Function;
    std::thread *functionThread = new std::thread(&Function::readSerialData, function, serialPortName);
    functionThread->detach();
    qRegisterMetaType<QList<QPointF>>("QList<QPointF> &");
    QObject::connect(function, SIGNAL(drawPoint(QList<QPointF>&)), this, SLOT(appendLinePoint(QList<QPointF>&)));
    QObject::connect(configUI, SIGNAL(sendConfig(float**,float**,float**,float*,float*,float*)),
                     function, SLOT(updateConfig(float**,float**,float**,float*,float*,float*)));
}

void MainUI::loadQss()
{
    QFile qssFile(qssFileDir);
    if(qssFile.open(QFile::ReadOnly))
    {
        qDebug() << "load qss";
        this->setStyleSheet(qssFile.readAll());
        qssFile.close();
        return;
    }
    qDebug() <<"load qss failed";
}

void MainUI::on_pushButton_correct_clicked()
{
    if(configUI != nullptr)
    {
        configUI->show();
    }
}

void MainUI::setTimeCycle(QAction *action)
{
    QStringList textList = action->text().split(" ", QString::SkipEmptyParts);
    timeCycle = textList[0].toInt();
    qDebug() << timeCycle;
}

void MainUI::appendLinePoint(QList<QPointF> &points)
{
    for(int i = 0; i < lineNum; ++i)
    {
        lines[i]->append(points[i]);
        //调整x轴范围
        if(points[i].x() > timeCycle)
        {
            ui->widget_painter->chart()->axisX()->setRange(points[i].x() - timeCycle, points[i].x());
        }
        //调整y轴范围
        QValueAxis *yAxis1 = axisesY[0];
        QValueAxis *yAxis2 = axisesY[1];
        if(i == showIndex[0])
        {
            yAxis1->setMax(yAxis1->max() > points[i].y() ? yAxis1->max() : points[i].y() + 1);
            yAxis1->setMin(yAxis1->min() > points[i].y() ? points[i].y() - 1 : yAxis1->min());
        }
        else if(i == showIndex[1])
        {
            yAxis2->setMax(yAxis2->max() > points[i].y() ? yAxis2->max() : points[i].y() + 1);
            yAxis2->setMin(yAxis2->min() > points[i].y() ? points[i].y() - 1 : yAxis2->min());
        }
    }
}

void MainUI::setLineVisible()
{
    int index1 = showIndex[0];
    int index2 = showIndex[1];

    for(int i = 0; i < lineNum; ++i)
    {
        if(index1 == i)
        {
            lines[i]->setVisible(true);
            axisesY[0]->setVisible(true);
            lines[i]->attachAxis(axisesY[0]);
        }
        else if(index2 == i)
        {
            lines[i]->setVisible(true);
            axisesY[1]->setVisible(true);
            lines[i]->attachAxis(axisesY[1]);
        }
        else
        {
            lines[i]->setVisible(false);
        }
    }

}

void MainUI::setVisibleIndex(int index1, int index2)
{
    showIndex[0] = index1;
    showIndex[1] = index2;
    setLineVisible();
}

