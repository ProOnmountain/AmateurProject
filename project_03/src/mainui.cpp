#include "mainui.h"
#include "ui_mainui.h"
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
    loadQss();
    correctUI = new CorrectUI(this);

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

