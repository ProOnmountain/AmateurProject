#include "serialsender.h"
#include "ui_serialsender.h"
#include <QDebug>

SerialSender::SerialSender(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialSender)
{
    ui->setupUi(this);
    time = 0;
    serialportInit();
}

SerialSender::~SerialSender()
{
    delete ui;
}

void SerialSender::serialportInit()
{
    serialPort = new QSerialPort();
    sendTimer = new QTimer(this);
    sendTimer->setInterval(100);
    QObject::connect(sendTimer, SIGNAL(timeout()), this, SLOT(sendData()));
    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();
    if(serialPortInfoList.isEmpty()){
        return;
    }
    QList<QSerialPortInfo>::iterator iter = serialPortInfoList.begin();
    //将所有端口添加到界面的下拉列表中
    while(iter!=serialPortInfoList.end()){
        ui->comboBox->addItem(iter->portName());
        iter++;
    }
    return;
}

void SerialSender::sendData()
{
    time += 1;
    QByteArray messageSend;
    messageSend.append((char *)&time, sizeof(time));
    qDebug() <<time <<":" << messageSend;
    serialPort->write(messageSend);
}

void SerialSender::on_pushButton_clicked()
{
    if(serialPort->isOpen())
    {
        qDebug() << serialPort->portName();
        return;
    }
    else
    {
        serialPort->setPortName(ui->comboBox->currentText());
        if(!serialPort->open(QIODevice::ReadWrite))
        {
            qDebug() << "打开失败";
        }
        serialPort->setBaudRate(QSerialPort::Baud115200);//设置波特率
        serialPort->setDataBits(QSerialPort::Data8);//设置数据位数
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);
    }
}

void SerialSender::on_pushButton_2_clicked()
{
    sendTimer->start();
}
