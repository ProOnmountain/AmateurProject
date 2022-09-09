#ifndef MAINUI_H
#define MAINUI_H

#include "./correctui.h"
#include "./floatbutton.h"
#include "./cyclebutton.h"
#include <QMainWindow>

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

private:
    void initUI();//初始化界面
    void loadQss();//加载UI界面样式文件

private:
    Ui::MainUI *ui;
    CorrectUI *correctUI;
    FloatButton *cycleButton;
    CycleButton *correctButton;
};

#endif // MAINUI_H
