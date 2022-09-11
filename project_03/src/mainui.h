#ifndef MAINUI_H
#define MAINUI_H

#include "./configui.h"
#include "./floatbutton.h"
#include "./function.h"
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>

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
    void on_pushButton_correct_clicked();//点击打开配置界面
    void setTimeCycle(QAction *action);//设置周期
    void appendLinePoint(QList<QPointF> &points);
    void setVisibleIndex(int index1, int index2);//设置可见曲线序号

private:
    void initUI();//初始化界面
    void loadQss();//加载UI界面样式文件
    void setLineVisible();//设置曲线可见

private:
    Ui::MainUI *ui;
    ConfigUI *configUI;//配置界面
    FloatButton *cycleButton;//浮动按钮
    Function *function;//计算
    int timeCycle;//周期
    QList<QSplineSeries *> lines;//曲线
    QList<QValueAxis *> axisesY;//y轴
    int lineNum;//曲线数量
    int showIndex[2];//可显示的曲线
};

#endif // MAINUI_H
