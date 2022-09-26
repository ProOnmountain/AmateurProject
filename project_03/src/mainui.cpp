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
    lineColor.append(Qt::white);
    lineColor.append(Qt::red);
    lineColor.append(Qt::green);
    lineColor.append(Qt::blue);
    lineColor.append(Qt::cyan);
    lineColor.append(Qt::magenta);
    lineColor.append(Qt::yellow);
    lineColor.append(Qt::darkYellow);
    lineColor.append(Qt::darkYellow);
    lineColor.append(Qt::gray);
    lineColor.append(Qt::darkBlue);

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
//    battery_2 = new Battery(this);//添加电池图标
    battery_1->setValue(100);
//    battery_2->setValue(100);
    QVBoxLayout *batteryBox = new QVBoxLayout();
    batteryBox->addWidget(battery_1);
//    batteryBox->addWidget(battery_2);
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
    configUI = new ConfigUI(this);
    QObject::connect(configUI, SIGNAL(showLineIndex(int, int)), this, SLOT(setVisibleIndex(int, int)));
    configUI->setWindowModality(Qt::ApplicationModal);
    configUI->show();

    //初始化绘图界面
    QChart *paint_chart = new QChart;
    ui->widget_painter->setChart(paint_chart);
    paint_chart->setBackgroundVisible(false);
    paint_chart->setMargins(QMargins(0, 0, 0, 0));

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
            yAxis1->setMax(yAxis1->max() > points[i].y() ? yAxis1->max() : points[i].y() + 0.1);
            yAxis1->setMin(yAxis1->min() > points[i].y() ? points[i].y() - 0.1 : yAxis1->min());
        }
        else if(i == showIndex[1])
        {
            yAxis2->setMax(yAxis2->max() > points[i].y() ? yAxis2->max() : points[i].y() + 0.1);
            yAxis2->setMin(yAxis2->min() > points[i].y() ? points[i].y() - 0.1 : yAxis2->min());
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
            QColor color = lines[i]->color();
            ui->label_legend1->setStyleSheet(QString("QLabel#label_legend1{background-color:rgb(%1,%2,%3,%4);border-radius:5;}").arg(color.red()).arg(color.green()).arg(color.black()).arg(color.alpha()));
            ui->label_line1->setText(lines[i]->name());
            axisesY[0]->setVisible(true);
            lines[i]->detachAxis(axisesY[1]);
            lines[i]->attachAxis(axisesY[0]);
        }
        else if(index2 == i)
        {
            lines[i]->setVisible(true);
            QColor color = lines[i]->color();
            ui->label_legend2->setStyleSheet(QString("QLabel#label_legend2{background-color:rgb(%1,%2,%3,%4);border-radius:5;}").arg(color.red()).arg(color.green()).arg(color.black()).arg(color.alpha()));
            ui->label_line1->setText(lines[i]->name());
            axisesY[0]->setVisible(true);
            ui->label_line2->setText(lines[i]->name());
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
    //界面数据更新
    //显示信息更新
    battery_1->setValue(int(*(battery)));
    ui->label_starNum->setText(QString::number(int(*(starNum)), 'f', 1));
    ui->label_GPS->setText(QString::number(*(locate), 'f', 1));
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
    points.append(QPointF(playTime, *atomic));
    ui->label_B3->setText(QString("B3: ")+ QString::number(*atomic, 'f', 1));
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
    ui->label_show->setText(QString("B1:") +
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

void MainUI::maxSubMin()
{
    if(showIndex[0] >= 0 && showIndex[1] >= 0)
    {
        QList<QPointF> pointList1 = lines[showIndex[0]]->points();
        QList<QPointF> pointList2 = lines[showIndex[1]]->points();
        if((!pointList1.empty()) && (!pointList2.empty()))
        {
            float min1 = 99999;
            float min2 = 99999;
            float max1 = -99999;
            float max2 = -99999;
            int len = pointList1.length();
            float xAxis_min = ((QValueAxis *)(ui->widget_painter->chart()->axisX()))->min();
            //        float xAxis_max = (QValueAxis *)(ui->widget_painter->chart()->axisX())->max();
            for(int i = 0; i < len; ++i)
            {
                if(pointList1[i].x() > xAxis_min)
                {
                    min1 = min1 > pointList1[i].y() ? pointList1[i].y() : min1;
                    max1 = max1 > pointList1[i].y() ? max1 : pointList1[i].y();
                }
                if(pointList2[i].x() > xAxis_min)
                {
                    min2 = min2 > pointList2[i].y() ? pointList2[i].y() : min2;
                    max2 = max2 > pointList2[i].y() ? max2 : pointList2[i].y();
                }
            }

            ui->label_sub1->setText(QString::number(max1 - min1, 'f', 1));
            if(showIndex[0] != showIndex[1])
            {
                ui->label_sub2->setText(QString::number(max2 - min2, 'f', 1));
            }
        }
    }
}
