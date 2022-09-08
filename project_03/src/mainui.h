#ifndef MAINUI_H
#define MAINUI_H

#include "./correctui.h"
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
    void on_pushButton_correct_clicked();

private:
    void initUI();
    void loadQss();//加载UI界面样式文件

private:
    Ui::MainUI *ui;
    CorrectUI *correctUI;
};

#endif // MAINUI_H
