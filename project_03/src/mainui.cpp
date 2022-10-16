#include "mainui.h"
#include "ui_mainui.h"
#include "define.h"
#include <QFile>
#include <QDebug>
#include <thread>
#include <QMetaType>
#include <math.h>

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
    this->setWindowFlags(Qt::CustomizeWindowHint |Qt::WindowTitleHint);
    this->showFullScreen();
    showIndex[0] = -1;
    showIndex[1] = -1;
    ui->mainToolBar->hide();
    timeCycle = 10000;
    playTime = 0;
    mutex = new std::mutex;
    //曲线名字
    lineName.append("B1");
    lineName.append("B2");
    lineName.append("B3");
    lineName.append("B1-B2");
    lineName.append("a");
    lineName.append("B1x");
    lineName.append("B1y");
    lineName.append("B1z");
    lineName.append("B2x");
    lineName.append("B2y");
    lineName.append("B2z");

    //曲线颜色
    lineColor.append(QColor(0xff, 0x8c, 0x00));
    lineColor.append(QColor(0x99, 0x32, 0xcc));
    lineColor.append(QColor(0xff, 0x14, 0x93));
    lineColor.append(QColor(0x00, 0xbf, 0xff));
    lineColor.append(QColor(0xb2, 0x22, 0x22));
    lineColor.append(QColor(0xff, 0xd7, 0x00));
    lineColor.append(QColor(0x00, 0x00, 0xff));
    lineColor.append(QColor(0xff, 0x8c, 0x00));
    lineColor.append(QColor(0x00, 0x54, 0x00));
    lineColor.append(QColor(0x7f, 0xff, 0x00));
    lineColor.append(QColor(0xff, 0xff, 0xff));

    //添加电池
    battery_1 = new Battery(this);//添加电池图标
    battery_1->setValue(0);
    QVBoxLayout *batteryBox = new QVBoxLayout();
    batteryBox->addWidget(battery_1);
    ui->horizontalLayout_4->addLayout(batteryBox, 1);

    //创建浮动周期按钮
    cycleButton = new FloatButton(ui->widget_painter);
    QMenu *timeMenu = new QMenu(this);
    for(int i = 5; i <= 320; i = i *2)
    {
        timeMenu->addAction(new QAction(QString("%1").arg(i) + " s"));
    }
    cycleButton->setMenu(timeMenu);

    cycleButton->setGeometry(ui->widget_painter->width()/2 - cycleButton->width()/2, 10, cycleButton->width(), cycleButton->height());
    cycleButton->show();
    QObject::connect(cycleButton,SIGNAL(triggered(QAction*)), this, SLOT(setTimeCycle(QAction*)));
    //创建配置界面
    configUI = new ConfigUI;
    QObject::connect(configUI, SIGNAL(showLineIndex(int, int)), this, SLOT(setVisibleIndex(int, int)));
    configUI->showFullScreen();
    configUI->show();

    //初始化绘图界面
    QChart *paint_chart = new QChart;
    ui->widget_painter->setChart(paint_chart);
    paint_chart->setBackgroundVisible(false);
    paint_chart->setMargins(QMargins(0, 0, 0, 0));
    ui->widget_painter->isMove = true;
    QObject::connect(ui->widget_painter, SIGNAL(playStop()), this, SLOT(playStop()));
    //隐藏原始图列
    QLegend *legend = paint_chart->legend();
    legend->setVisible(false);

    //初始化曲线和坐标轴
    QValueAxis *xAxis = new QValueAxis;
    xAxis->setRange(0, timeCycle);
    xAxis->setLabelsColor(Qt::white);
    xAxis->setGridLinePen(QPen(QBrush(Qt::white), 1, Qt::DashLine));
    QValueAxis *yAxis1 = new QValueAxis;
    yAxis1->setRange(0, 1);
    yAxis1->setLabelsColor(Qt::white);
    yAxis1->setGridLinePen(QPen(QBrush(Qt::white), 1, Qt::DashLine));
    axisesY.append(yAxis1);
    QValueAxis *yAxis2 = new QValueAxis;
    yAxis2->setRange(0, 1);
    yAxis2->setLabelsColor(Qt::white);
    yAxis2->setGridLinePen(QPen(QBrush(Qt::white), 1, Qt::DashLine));
    axisesY.append(yAxis2);
    paint_chart->addAxis(xAxis, Qt::AlignBottom);
    paint_chart->addAxis(yAxis1, Qt::AlignLeft);
    paint_chart->addAxis(yAxis2, Qt::AlignRight);
    for(int i = 0; i < lineNum; ++i)
    {
        QLineSeries *line = new QLineSeries;
        line->setName(lineName[i]);
        line->setPen(QPen(QBrush(QColor(lineColor[i])), lineWidth));

        lines.append(line);
        paint_chart->addSeries(line);
        line->setVisible(false);
        line->attachAxis(xAxis);
    }
    loadQss();

    //开启接收数据的线程
    function = new Function;
    std::thread *functionThread = new std::thread(&Function::readSerialData, function, serialPortName, mutex);
    functionThread->detach();
    qRegisterMetaType<QList<QPointF>>("QList<QPointF> &");
    QObject::connect(function, SIGNAL(drawPoint(QList<QPointF>&)), this, SLOT(appendLinePoint(QList<QPointF>&)));
    QObject::connect(configUI, SIGNAL(sendConfig(float**,float**,float**,float*,float*,float*)),
                     function, SLOT(updateConfig(float**,float**,float**,float*,float*,float*)));
    QObject::connect(function, SIGNAL(updateMainUI(float*,float*, float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*)),
                     this, SLOT(updateMainUI(float*,float*, float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*)));
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

void MainUI::on_pushButton_config_clicked()
{
    if(configUI != nullptr)
    {
        for(int i = 0; i < 2; ++i)
        {
            if(showIndex[i] != -1)
            {
                lines[showIndex[i]]->hide();
            }
        }
        configUI->showFullScreen();
        configUI->show();
    }
}

void MainUI::setTimeCycle(QAction *action)
{
    QStringList textList = action->text().split(" ", QString::SkipEmptyParts);
    timeCycle = textList[0].toInt() * 1000;
    qDebug() << "周期： " <<timeCycle;
}

void MainUI::appendLinePoint(QList<QPointF> &points)
{
    for(int i = 0; i < lineNum; ++i)
    {
        lines[i]->append(points[i]);
        if(lines[i]->points().count() > 2500)
        {
            lines[i]->removePoints(0, 1000);
//            qDebug() << "delete 1000 points, ramains: " << lines[i]->points().count();
        }
        //调整x轴范围
        double xmin = ((QValueAxis *)(ui->widget_painter->chart()->axisX()))->min();
        if(ui->widget_painter->isMove == true)
        {       
            if(points[i].x() > timeCycle)
            {
                ui->widget_painter->chart()->axisX()->setRange(points[i].x() - timeCycle, points[i].x());
            }
            else
            {
                ui->widget_painter->chart()->axisX()->setRange(xmin, xmin + timeCycle);
            }
        }
    }
}

void MainUI::setLineVisible()
{
    int index1 = showIndex[0];
    int index2 = showIndex[1];
    if(index1 == -1)
    {
        ui->label_line1->setText("");
        ui->label_legend1->setStyleSheet(QString("QLabel#label_legend1{background-color:rgb(%1,%2,%3);border-radius:5;}").arg(0).arg(0).arg(0));
        ui->label_sub1->setText("");
    }
    if(index2 == -1)
    {
        ui->label_line2->setText("");
        ui->label_legend2->setStyleSheet(QString("QLabel#label_legend2{background-color:rgb(%1,%2,%3);border-radius:5;}").arg(0).arg(0).arg(0));
        ui->label_sub2->setText("");
    }
    for(int i = 0; i < lineNum; ++i)
    {
        if(index1 == i)
        {
            lines[i]->setVisible(true);
            QColor color = lines[i]->color();
            ui->label_legend1->setStyleSheet(QString("QLabel#label_legend1{background-color:rgb(%1,%2,%3);border-radius:5;}").arg(color.red()).arg(color.green()).arg(color.blue()));
            ui->label_line1->setText(lines[i]->name());
            lines[i]->detachAxis(axisesY[1]);
            lines[i]->attachAxis(axisesY[0]);
        }
        else if(index2 == i)
        {      
            lines[i]->setVisible(true);
            QColor color = lines[i]->color();
            ui->label_legend2->setStyleSheet(QString("QLabel#label_legend2{background-color:rgb(%1,%2,%3);border-radius:5;}").arg(color.red()).arg(color.green()).arg(color.blue()));
            ui->label_line2->setText(lines[i]->name());
            lines[i]->detachAxis(axisesY[0]);
            lines[i]->attachAxis(axisesY[1]);
        }
        else
        {
            lines[i]->setVisible(false);
        }
    }
    if(index1 == index2)
    {
        ui->label_line2->setText("");
        ui->label_legend2->setStyleSheet(QString("QLabel#label_legend2{background-color:rgb(%1,%2,%3);border-radius:5;}").arg(0).arg(0).arg(0));
        ui->label_sub2->setText("");
    }
}

void MainUI::setVisibleIndex(int index1, int index2)
{
    showIndex[0] = index1;
    showIndex[1] = index2;
    setLineVisible();
}

void MainUI::updateMainUI(float *adjust_B1, float *adjust_B2, float *B1, float *B2, float *acc, float *angle, float *speed,
                  float *gpsTime, float *locate, float *starNum, float *battery, float *atomic, float *CRCC)
{
    mutex->lock();
    //界面数据更新
    //显示信息更新
    int batteryValue = ((*(battery)) - 6.5) / (8.2 - 6.5) * 100;
//    battery_1->setValue(batteryValue);
    qDebug() << batteryValue;
    ui->label_starNum->setText(QString::number(int(*(starNum)), 'f', 0));
    ui->label_GPS->setText(QString::number(*(locate), 'f', 0));
    //曲线更新
    //曲线顺序B1、B2、B3、B1-B2、a、B1x、B1y、B1z、B2x、B2y、B2z
    QList<QPointF> points;
    if(adjust_B1 != nullptr && adjust_B2 != nullptr)
    {
        double temp1 = sqrt(pow(adjust_B1[0], 2) +pow(adjust_B1[1], 2) + pow(adjust_B1[2], 2));
        double temp2 = sqrt(pow(adjust_B2[0], 2) +pow(adjust_B2[1], 2) + pow(adjust_B2[2], 2));
        points.append(QPointF(playTime, temp1));
        ui->label_B1->setText(QString("B1: ") + QString::number(temp1, 'f', 1));
        points.append(QPointF(playTime, temp2));
        ui->label_B2->setText(QString("B2: ") + QString::number(temp2, 'f', 1));
    }
    else
    {
        points.append(QPointF(playTime, 0));
        points.append(QPointF(playTime, 0));
    }
    if(atomic != nullptr)
    {
        points.append(QPointF(playTime, *atomic));
        ui->label_B3->setText(QString("B3: ")+ QString::number(*atomic, 'f', 1));
    }
    if(adjust_B1 != nullptr && adjust_B2 != nullptr)
    {
        double temp3 = sqrt(pow(adjust_B1[0] - adjust_B2[0], 2) +pow(adjust_B1[1] - adjust_B2[1], 2) + pow(adjust_B1[2] - adjust_B2[2], 2));
        points.append(QPointF(playTime, temp3));
        ui->label_B1B2->setText(QString("B1-B2: ")+ QString::number(temp3, 'f', 1));
    }
    else
    {
        points.append(QPointF(playTime, 0));
    }
    points.append(QPointF(playTime, *acc));
    ui->label_acc->setText(QString("a: ")+ QString::number(*acc, 'f', 2));
    points.append(QPointF(playTime, B1[0]));
    points.append(QPointF(playTime, B1[1]));
    points.append(QPointF(playTime, B1[2]));
    points.append(QPointF(playTime, B2[0]));
    points.append(QPointF(playTime, B2[1]));
    points.append(QPointF(playTime, B2[2]));
    ui->label_show->setText(QString("\nB1:") +
                            QString("\n") + QString::number(B1[0], 'f', 1) +
                            QString("\n") + QString::number(B1[1], 'f', 1) +
                            QString("\n") + QString::number(B1[2], 'f', 1) +
                            QString("\n\n") + QString("B2:") +
                            QString("\n") + QString::number(B2[0], 'f', 1) +
                            QString("\n") + QString::number(B2[1], 'f', 1) +
                            QString("\n") + QString::number(B2[2], 'f', 1));
    maxSubMin();
    appendLinePoint(points);
    playTime += timeStep;
//    qDebug() << "INFO ：append point";
    mutex->unlock();
}

void MainUI::maxSubMin()
{
    QList<QPointF> pointList1;
    QList<QPointF> pointList2;
    if(showIndex[0] >= 0)
    {
        pointList1 = lines[showIndex[0]]->points();
    }
    if(showIndex[1] >= 0 && showIndex[0] != showIndex[1])
    {
        pointList2 = lines[showIndex[1]]->points();
    }
    if(!pointList1.empty())
    {
        float min1 = 999999999;
        float max1 = -999999999;
        int len = pointList1.length();
        float xAxis_min = ((QValueAxis *)(ui->widget_painter->chart()->axisX()))->min();
        for(int i = 0; i < len; ++i)
        {
            if(pointList1[i].x() > xAxis_min)
            {
                min1 = min1 > pointList1[i].y() ? pointList1[i].y() : min1;
                max1 = max1 > pointList1[i].y() ? max1 : pointList1[i].y();
            }
        }
        ui->label_sub1->setText(QString::number(max1 - min1, 'f', 1));
        if(ui->widget_painter->isMove == true)
        {
            QValueAxis *yAxis1 = axisesY[0];
            yAxis1->setMax(max1 + 5);
            yAxis1->setMin(min1 - 5);
        }
    }
    if(!pointList2.empty())
    {
        float min2 = 999999999;
        float max2 = -999999999;
        int len = pointList2.length();
        float xAxis_min = ((QValueAxis *)(ui->widget_painter->chart()->axisX()))->min();
        for(int i = 0; i < len; ++i)
        {
            if(pointList2[i].x() > xAxis_min)
            {
                min2 = min2 > pointList2[i].y() ? pointList2[i].y() : min2;
                max2 = max2 > pointList2[i].y() ? max2 : pointList2[i].y();
            }
        }
        if(showIndex[0] != showIndex[1])
        {
            ui->label_sub2->setText(QString::number(max2 - min2, 'f', 1));
        }
        if(ui->widget_painter->isMove == true)
        {
            QValueAxis *yAxis2 = axisesY[1];
            yAxis2->setMax(max2 + 5);
            yAxis2->setMin(min2 - 5);
        }
    }
}

void MainUI::playStop()
{
    ui->widget_painter->isMove = false;
}
