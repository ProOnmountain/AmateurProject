#include "function.h"
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>      // 提供系统中存在的串口信息
#include <QFile>
#include <QtMath>
Function::Function(QObject *parent) : QObject(parent)
{
    serialHandler = nullptr;
    config.matrix1 = nullptr;
    config.matrix2 = nullptr;
    config.matrix3 = nullptr;
    config.offset1 = nullptr;
    config.offset2 = nullptr;
    config.other = nullptr;
}

Function::~Function()
{

}
bool Function::configSerialPort()
{
    if(serialHandler != nullptr)
    {
        QString configFileDir("../ini/serialConfig.ini");
        QFile fileHandler(configFileDir);
        if(!fileHandler.open(QIODevice::ReadOnly))
        {
            return false;
        }
        QTextStream textStream(&fileHandler);
        QStringList rawData = textStream.readAll().split("\n", QString::SkipEmptyParts);
        qDebug() << rawData;
        for(int i = 0; i < rawData.count(); ++i)
        {
            if(rawData[i] == "[serialPort]")
            {
                for(int j = 0; j < 5; ++j)
                {
                    QStringList infoList = rawData[i + j + 1].split("=", QString::SkipEmptyParts);
//                    qDebug() << infoList;
                    if(infoList[0] ==  "baudRate")
                    {
                        int baudRate =infoList[1].toInt();
//                        qDebug() << baudRate;
                        serialHandler->setBaudRate(baudRate);
                    }
                    if(infoList[0] == "dataBit")
                    {
                        int dataBit = infoList[1].toInt();
//                        qDebug() << dataBit;
                        serialHandler->setDataBits(QSerialPort::DataBits(dataBit));
                    }
                    if(infoList[0] == "parity")
                    {
                        int parity = infoList[1].toInt();
//                        qDebug() << parity;
                        serialHandler->setParity(QSerialPort::Parity(parity));
                    }
                    if(infoList[0] == "stopBits")
                    {
                        int stopBits = infoList[1].toInt();
//                        qDebug() << stopBits;
                        serialHandler->setStopBits(QSerialPort::StopBits(stopBits));
                    }
                    if(infoList[0] == "flowControl")
                    {
                        int flowControl = infoList[1].toInt();
//                        qDebug() << flowControl;
                        serialHandler->setFlowControl(QSerialPort::FlowControl(flowControl));
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void Function::readSerialData(QString serialPort)
{
    //配置串口
    if(serialHandler == nullptr)
    {
        serialHandler = new QSerialPort;
    }
    if(!serialHandler->isOpen())
    {
        serialHandler->setPortName(serialPort);
        while(!serialHandler->open(QIODevice::ReadWrite))
        {
            qDebug() << "尝试打开串口";

        }
        if(!configSerialPort())
        {
            qDebug() << "串口配置失败";
            return;
        }
    }
    qDebug() << "串口启动";
    //接收数据

    while(serialHandler->waitForReadyRead())
    {
        QByteArray recvData;
        recvData.append(serialHandler->readAll());
        if(!recvData.isEmpty())
        {
            dealRawData(recvData);
        }

    }
}

void Function::dealRawData(QByteArray &rawData)
{
    QList<QPointF> points;
    double time;
    memcpy(&time, rawData.data(), sizeof(double));
    for(int i = 0; i < 6; ++i)
    {
        QPointF p(time, qSin(time) * (i + 1));
        points.append(p);
    }
    emit drawPoint(points);
}

QStringList Function::getSerialList()
{
    QStringList portList;
    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();
    QList<QSerialPortInfo>::iterator iter = serialPortInfoList.begin();

    while(iter!=serialPortInfoList.end()){
        qDebug() << iter->portName();
        portList.append(iter->portName());
        iter++;
    }
    return portList;
}

float **Function::matrixMultip(vector<vector<float> > &A, vector<vector<float> > &B)
{
    int rows = 3;
    int cols = 3;
    float * sum;
    for(int i = 0; i < rows; ++i)
    {
        vector<float> rowVector(cols, 0);
        sum.push_back(rowVector);
    }


    if(A[0].size() != B.size())
    {
        qDebug() <<"不能相乘";
       return sum;
    }

    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<A[0].size(); j++)
        {

            for(int k = 0; k<B[0].size(); k++)
            {
                sum[i][k] += A[i][j]*B[j][k];
            }
        }
    }

    return sum;
}

vector<vector<float>> Function::matrixSub(vector<vector<float> > &A, vector<vector<float> > &B)
{
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<float>> sum;
    for(int i = 0; i < rows; ++i)
    {
        vector<float> rowVector(cols, 0);
        sum.push_back(rowVector);
    }


    if(A.size() != B.size() || A[0].size() != B[0].size())
    {
        qDebug() <<"不能相减";
       return sum;
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0;j < cols; ++j)
        {
            sum[i][j] = A[i][j] - B[i][j];
        }
    }

    return sum;
}

void Function::updateConfig(float **matrix1, float **matrix2, float **matrix3, float *offset1, float *offset2, float *other)
{
    config.matrix1 = matrix1;
    qDebug() << matrix1[0][0];
    config.matrix2 = matrix2;
    config.matrix3 = matrix3;
    config.offset1 = offset1;
    config.offset2 = offset2;
    config.other = other;
    qDebug() << "参数更新";
}
