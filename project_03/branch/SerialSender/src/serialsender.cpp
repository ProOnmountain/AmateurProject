#include "serialsender.h"
#include "ui_serialsender.h"
#include <QDebug>
#include <qmath.h>

SerialSender::SerialSender(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialSender)
{
    ui->setupUi(this);
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
float mindex = 0;
void SerialSender::sendData()
{
    char * data = new char[85];
    data[0] = 0x01;
    data[1] = 0x03;
    data[2] = 0x50;
    float B1x = qSin(mindex) * 1;
    float B1y = qSin(mindex) + 1;
    float B1z = qSin(mindex) + 2;
    convertBigSmall(data + 3, (char *)&B1x, 4);
    convertBigSmall(data + 7, (char *)&B1y, 4);
    convertBigSmall(data + 11, (char *)&B1z, 4);
    float B2x = qSin(mindex) * 2;
    float B2y = B2x + 1;
    float B2z = B1x + 2;
    convertBigSmall(data + 15, (char *)&B2x, 4);
    convertBigSmall(data + 19, (char *)&B2y, 4);
    convertBigSmall(data + 23, (char *)&B2z, 4);
    float accx = qSin(mindex) * 3;
    float accy = accx + 1;
    float accz = accx + 2;
    convertBigSmall(data + 27, (char *)&accx, 4);
    convertBigSmall(data + 31, (char *)&accy, 4);
    convertBigSmall(data + 35, (char *)&accz, 4);
    float angle1 = qSin(mindex) * 4;
    float angle2 = angle1 + 1;
    float angle3 = angle1 + 2;
    convertBigSmall(data + 39, (char *)&angle1, 4);
    convertBigSmall(data + 43, (char *)&angle2, 4);
    convertBigSmall(data + 47, (char *)&angle3, 4);
    float speed1 = qSin(mindex) * 4;
    float speed2 = speed1 + 1;
    float speed3 = speed1 + 2;
    convertBigSmall(data + 51, (char *)&speed1, 4);
    convertBigSmall(data + 55, (char *)&speed2, 4);
    convertBigSmall(data + 59, (char *)&speed3, 4);
    float gpsTime = 123456;
    convertBigSmall(data + 63, (char *)&gpsTime, 4);
    float locate = qSin(mindex);
    convertBigSmall(data + 67, (char *)&locate, 4);
    float starNum = 7;
    convertBigSmall(data + 71, (char *)&starNum, 4);
    float battery = (qSin(mindex) + 1) * 100;
    convertBigSmall(data + 75, (char *)&battery, 4);

    QByteArray messageSend(data, 85);
    serialPort->write(messageSend);
    mindex++;
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
            return;
        }
        serialPort->setBaudRate(-1);//设置波特率
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

void SerialSender::convertBigSmall(char *dest, char *src, int len)
{
    if(dest != nullptr)
    {
        int j = 0;
        for(int i = len - 1; i >= 0; --i)
        {
            memcpy(dest + i, src + j, sizeof(char));
            ++j;
        }
    }
}
