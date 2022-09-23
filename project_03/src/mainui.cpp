#include "mainui.h"
#include "ui_mainui.h"
#include "define.h"
#include <QFile>
#include <QDebug>
#include <thread>
#include <QMetaType>
#include <math.h>
//#include <QAudioFormat>
//#include <QAudioOutput>

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
    timeCycle = 10000;
    playTime = 0;
    mutex = new std::mutex;
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

    //蜂鸣
    QAudioFormat audioFormat;
    audioFormat.setCodec("audio/pcm");
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat.setSampleRate(44100);
    audioFormat.setChannelCount(2);
    audioFormat.setSampleSize(16);
    audioFormat.setSampleType(QAudioFormat::SignedInt);
    soundPlay = new QAudioOutput(QAudioDeviceInfo::defaultOutputDevice(), audioFormat);
    sound = new Sound();
    sound->open(QIODevice::ReadWrite);
    soundTimer = new QTimer();
    QObject::connect(soundTimer, SIGNAL(timeout()), this, SLOT(warnStop()));

    //添加电池
    battery_1 = new Battery(this);//添加电池图标
    battery_2 = new Battery(this);//添加电池图标
    battery_1->setValue(100);
    battery_2->setValue(100);
    QVBoxLayout *batteryBox = new QVBoxLayout();
    batteryBox->addWidget(battery_1);
    batteryBox->addWidget(battery_2);
    ui->horizontalLayout_4->addLayout(batteryBox, 1);

    //创建浮动按钮
    cycleButton = new FloatButton(ui->widget_painter);
    for(int i = 5; i <= 320; i = i *2)
    {
        cycleButton->addAction(new QAction(QString("%1").arg(i) + " s"));
    }
    cycleButton->setGeometry(ui->widget_painter->width()/2 - cycleButton->width()/2, 10, cycleButton->width(), cycleButton->height());
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
    paint_chart->setBackgroundVisible(false);
    paint_chart->setMargins(QMargins(0, 0, 0, 0));
//    QGraphicsScene *chart_scene = ui->widget_painter->scene();
//    QGraphicsAnchorLayout *chart_layout = new QGraphicsAnchorLayout;
//    QGraphicsProxyWidget *labelProxy = chart_scene->addWidget(new QLabel);
//    chart_layout->addItem(labelProxy);
//    paint_chart->setLayout(chart_layout);
//    chart_scene->addItem(paint_chart);
    QLegend *legend = paint_chart->legend();
    legend->setLabelColor(Qt::white);
    legend->setMarkerShape(QLegend::MarkerShapeCircle);
    legend->setAlignment(Qt::AlignRight);
    qDebug() << legend->size().width();

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
        QSplineSeries *line = new QSplineSeries;
        line->setName(lineName[i]);
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
    QObject::connect(function, SIGNAL(warn(int)), this, SLOT(warnPlay(int)));
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
    timeCycle = textList[0].toInt() * 1000;
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
            lines[i]->detachAxis(axisesY[1]);
            lines[i]->attachAxis(axisesY[0]);
        }
        else if(index2 == i)
        {
            lines[i]->setVisible(true);
            axisesY[1]->setVisible(true);
            lines[i]->detachAxis(axisesY[0]);
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

void MainUI::updateMainUI(float *adjust_B1, float *adjust_B2, float *B1, float *B2, float *acc, float *angle, float *speed,
                  float *gpsTime, float *locate, float *starNum, float *battery, float *atomic, float *CRCC)
{
    mutex->lock();
    //界面所以更新都在这里
    //显示信息更新
    battery_1->setValue(int(*(battery)));
    ui->label_starNum->setText(QString("%1").arg(int(*(starNum))));
    ui->label_GPS->setText(QString("%1").arg(*(locate)));
    //曲线更新
    //曲线顺序B1、B2、B3、B1-B2、a、B1x、B1y、B1z、B2x、B2y、B2z
    QList<QPointF> points;
    if(adjust_B1 != nullptr && adjust_B2 != nullptr)
    {
        double temp1 = sqrt(pow(adjust_B1[0], 2) +pow(adjust_B1[1], 2) + pow(adjust_B1[2], 2));
        double temp2 = sqrt(pow(adjust_B2[0], 2) +pow(adjust_B2[1], 2) + pow(adjust_B2[2], 2));
        points.append(QPointF(playTime, temp1));
        ui->label_B1->setText(QString("B1: %1").arg(temp1));
        points.append(QPointF(playTime, temp2));
        ui->label_B2->setText(QString("B2: %1").arg(temp2));
    }
    else
    {
        points.append(QPointF(playTime, 0));
        points.append(QPointF(playTime, 0));
    }
    points.append(QPointF(playTime, *atomic));
    ui->label_B3->setText(QString("B3: %1").arg(*atomic));
    if(adjust_B1 != nullptr && adjust_B2 != nullptr)
    {
        double temp3 = sqrt(pow(adjust_B1[0] - adjust_B2[0], 2) +pow(adjust_B1[1] - adjust_B2[1], 2) + pow(adjust_B1[2] - adjust_B2[2], 2));
        points.append(QPointF(playTime, temp3));
        ui->label_B1B2->setText(QString("B1-B2: %1").arg(temp3));
    }
    else
    {
        points.append(QPointF(playTime, 0));
    }
    points.append(QPointF(playTime, *acc));
    ui->label_acc->setText(QString("加速度: %1").arg(*acc));
    points.append(QPointF(playTime, B1[0]));
    ui->label_B1x->setText(QString("B1x: %1").arg(B1[0]));
    points.append(QPointF(playTime, B1[1]));
    ui->label_B1y->setText(QString("B1y: %1").arg(B1[1]));
    points.append(QPointF(playTime, B1[2]));\
    ui->label_B1z->setText(QString("B1z: %1").arg(B1[2]));
    points.append(QPointF(playTime, B2[0]));
    ui->label_B2x->setText(QString("B2x: %1").arg(B2[0]));
    points.append(QPointF(playTime, B2[1]));
    ui->label_B2y->setText(QString("B2y: %1").arg(B2[1]));
    points.append(QPointF(playTime, B2[2]));
    ui->label_B2z->setText(QString("B2z: %1").arg(B2[2]));
    appendLinePoint(points);
    playTime += timeStep;
    mutex->unlock();
}

void MainUI::warnPlay(int freq)
{
    if(sound != nullptr)
    {
        sound->setFreq(freq);
        soundPlay->start(sound);
        soundTimer->start(warnTime * 1000);
    }
}

void MainUI::warnStop()
{
    soundPlay->stop();
}
