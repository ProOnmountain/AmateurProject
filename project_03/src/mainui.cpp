#include "mainui.h"
#include "ui_mainui.h"
#include "battery.h"
#include <QFile>
#include <QDebug>

const QString qssFileDir = ":/mainuistyle.qss";

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
    ui->pushButton_correct->setStyleSheet("QPushButton{border-radius:10}");
    //添加电池
    Battery *battery_1 = new Battery(this);//添加电池图标
    Battery *battery_2 = new Battery(this);//添加电池图标
    battery_1->setValue(10);
    battery_2->setValue(30);
    QVBoxLayout *batteryBox = new QVBoxLayout();
    batteryBox->addWidget(battery_1);
    batteryBox->addWidget(battery_2);
    ui->horizontalLayout_3->addLayout(batteryBox, 1);
    //添加定位和卫星图标
    QPixmap pixGPS(":/image/GPS.png");
    QPixmap GPS=pixGPS.scaled(ui->label_GPS->size(),Qt::KeepAspectRatio);
    ui->label_GPS->setPixmap(GPS);
    QPixmap pixStar(":/image/star.png");
    QPixmap star=pixStar.scaled(ui->label_star->size(),Qt::KeepAspectRatio);
    ui->label_star->setPixmap(star);

    //创建浮动按钮
    cycleButton = new FloatButton(this);
    cycleButton->show();

    //创建配置界面
    correctUI = new CorrectUI(this);
    loadQss();
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
    if(correctUI != nullptr)
    {
        correctUI->show();
    }
}

