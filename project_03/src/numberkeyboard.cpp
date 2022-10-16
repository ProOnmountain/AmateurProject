#include "numberkeyboard.h"
#include "ui_numberkeyboard.h"
#include <QDebug>
#include <QPushButton>
#include <QApplication>
#include <QDoubleSpinBox>
#include <QKeyEvent>
#include <QDesktopWidget>

NumberKeyboard::NumberKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberKeyboard)
{
    ui->setupUi(this);
    this->setFixedSize(width(), height());
    this->setWindowFlags(Qt::CustomizeWindowHint |Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
    this->hide();
    currentInputWidget = nullptr;
    connectNumberBtn();
    connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(updateInputWidget(QWidget*, QWidget*)));
}

NumberKeyboard::~NumberKeyboard()
{
    delete ui;
}

void NumberKeyboard::connectNumberBtn()
{
    connect(ui->pushButton_0, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_1, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_3, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_4, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_5, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_6, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_7, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_8, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_9, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_point, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
    connect(ui->pushButton_del, SIGNAL(pressed()), this, SLOT(emitKeyEvent()));
}


void NumberKeyboard::emitKeyEvent()
{
    QObject *btn = sender();
    QString keyValue = dynamic_cast<QPushButton*>(btn)->text();
    QKeyEvent *keyEvent = nullptr;
    if(keyValue == "0")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_0, Qt::NoModifier, keyValue);
    }
    if(keyValue == "1")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_1, Qt::NoModifier, keyValue);
    }
    if(keyValue == "2")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_2, Qt::NoModifier, keyValue);
    }
    if(keyValue == "3")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_3, Qt::NoModifier, keyValue);
    }
    if(keyValue == "4")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_4, Qt::NoModifier, keyValue);
    }
    if(keyValue == "5")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_5, Qt::NoModifier, keyValue);
    }
    if(keyValue == "6")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_6, Qt::NoModifier, keyValue);
    }
    if(keyValue == "7")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_7, Qt::NoModifier, keyValue);
    }
    if(keyValue == "8")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_8, Qt::NoModifier, keyValue);
    }
    if(keyValue == "9")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_9, Qt::NoModifier, keyValue);
    }
    if(keyValue == "Del")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, keyValue);
    }
    if(keyValue == ".")
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_Period, Qt::NoModifier, keyValue);
    }
    if(currentInputWidget != nullptr)
    {
        QApplication::postEvent(currentInputWidget, keyEvent);
    }
}

void NumberKeyboard::updateInputWidget(QWidget *old, QWidget *inputWidget)
{
    if(old != nullptr)
    {
        if(inputWidget != nullptr && !inputWidget->inherits("NumberKeyboard"))
        if(old->objectName().contains("doubleSpinBox") ||
           old->objectName().contains("spinBox"))
        {

            if(old->objectName().contains("doubleSpinBox"))
            {
                QDoubleSpinBox *temp = dynamic_cast<QDoubleSpinBox*>(old);
                if(temp->text() == "")
                {
                    temp->setValue(0);
                }
            }
            if(old->objectName().contains("spinBox"))
            {
                QSpinBox *temp = dynamic_cast<QSpinBox*>(old);
                if(temp->text() == "")
                {
                    temp->setValue(0);
                }
            }
        }
    }
    if(inputWidget != nullptr)
    {
        if(inputWidget->objectName().contains("doubleSpinBox") ||
           inputWidget->objectName().contains("spinBox"))
        {
            this->show();
            if(currentInputWidget != inputWidget)
            {
                currentInputWidget = inputWidget;
                currentInputWidget->setFocus();
                QDesktopWidget *d=QApplication::desktop();
                int width=d->width(); //屏幕的宽度
                int height=d->height(); //屏幕的高度
                this->setGeometry(width / 2, height - this->height(), this->width(), this->height());
                if(currentInputWidget->objectName().contains("doubleSpinBox"))
                {
                    QDoubleSpinBox *temp = dynamic_cast<QDoubleSpinBox*>(currentInputWidget);
                    temp->clear();
                }
                if(currentInputWidget->objectName().contains("spinBox"))
                {
                    QSpinBox *temp = dynamic_cast<QSpinBox*>(currentInputWidget);
                    temp->clear();
                }
            }

        }
        else
        {
            this->hide();
            currentInputWidget = nullptr;
        }
    }
}

