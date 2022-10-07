#ifndef FUNCTION_H
#define FUNCTION_H

#include "define.h"
#include <QObject>
#include <QPointF>
#include <QtSerialPort/QSerialPort>
#include <vector>
#include <mutex>
#include <deque>
using std::vector;
class Function : public QObject
{
    Q_OBJECT
public:
    explicit Function(QObject *parent = nullptr);
    ~Function();
    void readSerialData(QString serialPort, std::mutex *mutex);//获取串口数据

signals:
    void drawPoint(QList<QPointF> &points);//发送绘制信号
    void drawPoint(QPointF *points);
    void updateMainUI(float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float *);//更新界面
    void warn(int8_t freq, QSerialPort *serialHandler);//蜂鸣器控制

public slots:
    void updateConfig(float **matrix1, float **matrix2, float **matrix3, float *offset1, float *offset2, float *other);//接收配置更新

public:
    QStringList getSerialList();//获取本机串口列表

private:
    bool configSerialPort();//配置串口，从默认文件配置
    void configSerialPort(int baudRate = 115280, int dataBit = 8, int parity = 0, int stopBits = 1, int flowControl = 0);//配置串口，从参数输入
    void convertBigSmall(char *dest, char *src, int len);//数据大小端转化
    void dealRawData(QByteArray &rawData, std::mutex *mutex);//处理串口数据
    float *adjustAlgorithm(float **matrix, float *rawVector, float *offset);//校准算法
    float *consistencyAdjustAlgorithm(float **matrix, float *adjustVector);//分量一致性校准算法
    void warnAlgorithm();//预警处理

private:
    QSerialPort *serialHandler;
    double time;//时间（ms）
    struct Config
    {
        float **matrix1;
        float **matrix2;
        float **matrix3;
        float *offset1;
        float *offset2;
        float *other;
    } config;
    float *adjust_B1 = new float;
    float *adjust_B2 = new float;
    float *B1 = new float[3];
    float *B2 = new float[3];
    float *acc = new float[3];
    float *angle = new float[3];
    float *speed = new float[3];
    float *gpsTime = new float;
    float *locate = new float;
    float *starNum = new float;
    float *battery = new float;
    float *atomic = new float;
    float *CRCC = new float;
    std::deque<float> MG;
    std::deque<float> warnData;//用来存放计算预警的数据
    float warnCount;//用来判断是否进行预警计算
    float MA1;
};


#endif // FUNCTION_H
