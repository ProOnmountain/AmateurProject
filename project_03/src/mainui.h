#ifndef MAINUI_H
#define MAINUI_H

#include "./configui.h"
#include "./floatbutton.h"
#include "./function.h"
#include "./battery.h"
#include "./sound.h"
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <mutex>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QTimer>


namespace Ui {
class MainUI;
}

class MainUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainUI(QWidget *parent = 0);
    ~MainUI();

private slots:
    void on_pushButton_config_clicked();//点击打开配置界面
    void setTimeCycle(QAction *action);//设置周期
    void appendLinePoint(QList<QPointF> &points);
    void setVisibleIndex(int index1, int index2);//设置可见曲线序号
    void updateMainUI(float * adjust_B1, float * adjust_B2, float *B1, float *B2, float *acc, float *angle, float *speed,
                      float *gpsTime, float *locate, float *starNum, float *battery, float *atomic, float *CRCC);//更新界面
    void playStop();

private:
    void initUI();//初始化界面
    void loadQss();//加载UI界面样式文件
    void setLineVisible();//设置曲线可见
    void maxSubMin();

private:
    Ui::MainUI *ui;
    Battery *battery_1;
    ConfigUI *configUI;//配置界面
    FloatButton *cycleButton;//浮动按钮
    Function *function;//计算
    int timeCycle;//周期
    QList<QLineSeries *> lines;//曲线
    QList<QString> lineName;//曲线名字
    QList<QColor> lineColor;
    QList<QValueAxis *> axisesY;//y轴
    int showIndex[2];//可显示的曲线
    std::mutex *mutex;
    double playTime;
};

#endif // MAINUI_H
