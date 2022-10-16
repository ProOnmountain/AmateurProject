#include "function.h"
#include "define.h"
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>      // 提供系统中存在的串口信息
#include <QFile>
#include <QtMath>
#include <QMetaType>
#include <thread>
#include <QStringList>
#include "stdio.h"
Function::Function(QObject *parent) : QObject(parent)
{
    serialHandler = nullptr;
    config.matrix1 = nullptr;
    config.matrix2 = nullptr;
    config.matrix3 = nullptr;
    config.offset1 = nullptr;
    config.offset2 = nullptr;
    config.other = nullptr;
    time = 0;
    warnCount = 0;
    MA1 = 0;
    qRegisterMetaType<int8_t>("int8_t");
    soundTimer = new QTimer();
    QObject::connect(soundTimer, SIGNAL(timeout()), this, SLOT(warnStop()));
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
                    if(infoList[0] ==  "baudRate")
                    {
                        int baudRate =infoList[1].toInt();
                        serialHandler->setBaudRate(baudRate);
                    }
                    if(infoList[0] == "dataBit")
                    {
                        int dataBit = infoList[1].toInt();
                        serialHandler->setDataBits(QSerialPort::DataBits(dataBit));
                    }
                    if(infoList[0] == "parity")
                    {
                        int parity = infoList[1].toInt();
                        serialHandler->setParity(QSerialPort::Parity(parity));
                    }
                    if(infoList[0] == "stopBits")
                    {
                        int stopBits = infoList[1].toInt();
                        serialHandler->setStopBits(QSerialPort::StopBits(stopBits));
                    }
                    if(infoList[0] == "flowControl")
                    {
                        int flowControl = infoList[1].toInt();
                        serialHandler->setFlowControl(QSerialPort::FlowControl(flowControl));
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void Function::configSerialPort(int baudRate, int dataBit, int parity, int stopBits, int flowControl)
{
    if(serialHandler != nullptr)
    {
        serialHandler->setBaudRate(baudRate);
        serialHandler->setDataBits(QSerialPort::DataBits(dataBit));
        serialHandler->setParity(QSerialPort::Parity(parity));
        serialHandler->setStopBits(QSerialPort::StopBits(stopBits));
        serialHandler->setFlowControl(QSerialPort::FlowControl(flowControl));
    }
}

void Function::readSerialData(QString serialPort, std::mutex *mutex)
{
    //配置串口
    if(serialHandler == nullptr)
    {
        serialHandler = new QSerialPort;
    }
    while(!serialHandler->isOpen())
    {
        QStringList serialList = getSerialList();
        for(int i = 0; i < serialList.count(); ++i)
        {
            QString tempPort = serialList.at(i);
            if(tempPort.contains(serialPortName))
            {
                serialHandler->setPortName(serialList.at(i));

                qDebug() << "INFO: 正在尝试打开串口";
                if(serialHandler->open(QIODevice::ReadWrite))
                {
                    serialPort = serialList.at(i);
                    break;
                }
            }

        }
        qDebug() << "INFO: 找不到匹配的串口， 再次尝试";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    configSerialPort(115280);
    qDebug() << "INFO: 串口已启动，准备接收数据";

    //接收数据
    QByteArray rawData;
    while(true)
    {   
        while(serialHandler->waitForReadyRead())
        {
//            qDebug() <<"INFO: before dealRaw clear";
            rawData.clear();
            rawData.append(serialHandler->readAll());
            if(!rawData.isEmpty())
            {
//                qDebug() <<"INFO: before dealRaw";
                dealRawData(rawData, mutex);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        if(!serialHandler->isOpen())
        {
            serialHandler->setPortName(serialPort);
            qDebug() << "INFO: 尝试打开串口，串口名字：" << serialPort;
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        else if(serialHandler->isOpen())
        {
            qDebug() << "INFO: 数据延迟";
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        else
        {
            qDebug() << "INFO: 串口断开链接，无法重联";
            break;
        }
    }
}
int i = 0;
void Function::dealRawData(QByteArray &rawData, std::mutex *mutex)
{
    //按字节读取数据
    if(rawData.size() != rawDataSize)
    {
        qDebug() << "ERROR：读取数据长度不符";
        return;
    }

    mutex->lock();
    //磁通门1
    char *p = rawData.data();
    convertBigSmall((char*)&B1[0], p + 3, 4);
    convertBigSmall((char*)&B1[1], p + 7, 4);
    convertBigSmall((char*)&B1[2], p + 11, 4);
    qDebug() <<"次同门1：" <<B1[0];
    qDebug() <<"次同门2：" <<B1[2];
    qDebug() <<"次同门3：" <<B1[3];
//    qDebug() <<"INFO: 次同门1";
    //磁通门2
    convertBigSmall((char*)&B2[0], p + 15, 4);
    convertBigSmall((char*)&B2[1], p + 19, 4);
    convertBigSmall((char*)&B2[2], p + 23, 4);
    //加速率
    convertBigSmall((char*)&acc[0], p + 27, 4);
    convertBigSmall((char*)&acc[1], p + 31, 4);
    convertBigSmall((char*)&acc[2], p + 35, 4);
    //方位角
    convertBigSmall((char*)&angle[0], p + 39, 4);
    convertBigSmall((char*)&angle[1], p + 43, 4);
    convertBigSmall((char*)&angle[2], p + 47, 4);
    //速度
    convertBigSmall((char*)&speed[0], p + 51, 4);
    convertBigSmall((char*)&speed[1], p + 55, 4);
    convertBigSmall((char*)&speed[2], p + 59, 4);
//    qDebug() <<"INFO: before GPS";
    //GPS
    convertBigSmall((char*)gpsTime, p + 63, 4);
    //定位状态
    convertBigSmall((char*)locate, p + 67, 4);
    //卫星数量
    convertBigSmall((char*)starNum, p + 71, 4);
    //电池电量
    convertBigSmall((char*)battery, p + 75, 4);
    //全场原子磁力计
    convertBigSmall((char*)atomic, p + 79, 4);
    //CRCC_16
    convertBigSmall((char*)CRCC, p + 83, 2);
   //探头1、2、分量校准
    if(config.matrix1 != nullptr && config.offset1 != nullptr)
    {
        adjust_B1 = adjustAlgorithm(config.matrix1, B1, config.offset1);
    }
    if(config.matrix2 != nullptr && config.offset2 != nullptr)
    {
        adjust_B2 = adjustAlgorithm(config.matrix2, B2, config.offset2);
    }

    //预警
    if(config.other != nullptr)
    {
        int warnType = config.other[0];
        float MT = config.other[5];
        float DT = config.other[7];
        float warnTypeData;
        if(warnType == 0)//B1
        {
            warnTypeData = sqrt(pow(adjust_B1[0], 2) +pow(adjust_B1[1], 2) + pow(adjust_B1[2], 2));
        }
        if(warnType == 1)//B2
        {
            warnTypeData = sqrt(pow(adjust_B2[0], 2) +pow(adjust_B2[1], 2) + pow(adjust_B2[2], 2));
        }
        if(warnType == 2)//B3
        {
            warnTypeData = *atomic;
        }
        if(warnType == 3)//B1-B2
        {
            warnTypeData = sqrt(pow(adjust_B1[0] - adjust_B2[0], 2) +pow(adjust_B1[1] - adjust_B2[1], 2) + pow(adjust_B1[2] - adjust_B2[2], 2));
        }
        if(warnData.size() == MT)
        {
            warnData.pop_front();
        }
        warnData.push_back(warnTypeData);
        warnCount += 1;
        if(warnCount == DT)
        {
            warnCount = 0;
            warnAlgorithm();
        }
    }
//    qDebug() << "INFO: deal data " << i++ ;
    emit updateMainUI(adjust_B1, adjust_B2, B1, B2, acc, angle, speed, gpsTime, locate, starNum, battery, atomic, CRCC);
    mutex->unlock();
}

QStringList Function::getSerialList()
{
    QStringList portList;
    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();
    QList<QSerialPortInfo>::iterator iter = serialPortInfoList.begin();
    qDebug() << "INFO: 当前串口设备：";
    while(iter!=serialPortInfoList.end()){
        qDebug() << "     " << iter->portName();
        portList.append(iter->portName());
        iter++;
    }
    return portList;
}

void Function::updateConfig(float **matrix1, float **matrix2, float **matrix3, float *offset1, float *offset2, float *other)
{
    config.matrix1 = matrix1;
    config.matrix2 = matrix2;
    config.matrix3 = matrix3;
    config.offset1 = offset1;
    config.offset2 = offset2;
    config.other = other;
    qDebug() << "参数更新";
}

float* Function::adjustAlgorithm(float **matrix, float *rawVector, float *offset)
{
    if(matrix != nullptr && rawVector != nullptr && offset != nullptr)
    {
        float *res = new float[3];
        for(int i = 0; i < 3; ++i)
        {
            res[i] = 0;
            for(int j = 0; j < 3; ++j)
            {
                res[i] += matrix[i][j] * rawVector[j];
            }
            res[i] -= offset[i];
        }
        return res;
    }
    return nullptr;
}

float* Function::consistencyAdjustAlgorithm(float **matrix, float *adjustVector)
{
    if(matrix != nullptr && adjustVector != nullptr)
    {
        float *res = new float[3];
        for(int i = 0; i < 3; ++i)
        {
            res[i] = 0;
            for(int j = 0; j < 3; ++j)
            {
                res[i] += matrix[i][j] * adjustVector[j];
            }
        }
        return res;
    }
    return nullptr;
}

void Function::warnAlgorithm()
{
//    qDebug() <<"INFO: 预警";
    //计算预警信息
    float THm = 0;
    float THa = 0;
    float MGmax = 0;
    float sampleRate = 0;
    float MA2 = 0;
    float coefficient = 0;
//    qDebug() <<"INFO: warnData size: " << warnData.size();
    for(int i = 0; i < warnData.size(); ++i)
    {
        MA2 += warnData[i];
    }
    if(warnData.size() > 0)
    {
        MA2 = MA2 / warnData.size();
    }
//    qDebug() <<"INFO: warnData after";
    if(config.other != nullptr)
    {
//        qDebug() << "INFO: config before";
        THm = config.other[1];
        THa = config.other[2];
        MGmax = config.other[3];
        sampleRate = config.other[4];
        coefficient = config.other[8];
        float ML = config.other[6];
        float DT = config.other[7];
//        qDebug() << "INFO: config after";
        float tempMG = (MA2 - MA1)/ DT * sampleRate;
        MA1 = MA2;
        if(MG.size() == ML)
        {
            MG.pop_front();
        }
        MG.push_back(tempMG);
    }
    bool isWarn = true;
    for(unsigned int i = 0; i < MG.size(); ++i)
    {
        if(MG[0] > 0)
        {
            if(MG[i] < 0)
            {
                isWarn = false;
                break;
            }
        }
        if(MG[0] < 0)
        {
            if(MG[i] > 0)
            {
                isWarn = false;
                break;
            }
        }
        if(abs(MG[i]) < THm)
        {
            isWarn =false;
            break;
        }
        if(sqrt(pow(acc[0], 2) + pow(acc[1], 2) + pow(acc[2], 2)) > THa)
        {
            isWarn = false;
            break;
        }
    }
//    qDebug() << "INFO: before if";
    if(isWarn == true)
    {

        int freq = (int)(MG.back() * coefficient);//设置蜂鸣频率
        if(MG.back() >= MGmax)
        {
            freq = (int)(MGmax * coefficient);
        }
        warnPlay(freq);
        qDebug() << "INFO：开启蜂鸣器，频率：" << freq;
    }
}

void Function::convertBigSmall(char *dest, char *src, int len)
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

void Function::warnPlay(int8_t freq)
{
    //下发指令
    if(serialHandler != nullptr)
    {
        char *command = new char[4];
        command[0] = 'F';
        command[1] = 'M';
        command[2] = 'Q';
        memcpy(&command[3], &freq, sizeof(int8_t));
        serialHandler->write(command, 4);//串口下发
//        qDebug() << "INFO: before timer";
        soundTimer->start(warnTime * 1000);//控制蜂鸣持续时间，4s
    }

}

void Function::warnStop()
{
    soundTimer->stop();
    //下发停止指令
    if(serialHandler != nullptr)
    {
        char *command = new char[4];
        command[0] = 'F';
        command[1] = 'M';
        command[2] = 'Q';
        memset(&command[3], 0, sizeof(int8_t));
        serialHandler->write(command, 4);
    }
}
