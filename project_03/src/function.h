#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include <QPointF>
#include <QtSerialPort/QSerialPort>
#include <vector>
using std::vector;
class Function : public QObject
{
    Q_OBJECT
public:
    explicit Function(QObject *parent = nullptr);
    ~Function();
    void readSerialData(QString serialPort);//获取串口数据

signals:
    void drawPoint(QList<QPointF> &points);//发送绘制信号

public slots:
    void updateConfig(float **matrix1, float **matrix2, float **matrix3, float *offset1, float *offset2, float *other);

public:
    QStringList getSerialList();//获取本机串口列表
    float ** matrixMultip(vector<vector<float>>& A,vector<vector<float>>& B);//矩阵乘法
    vector<vector<float>> matrixSub(vector<vector<float>>& A,vector<vector<float>>& B);//矩阵减法
private:
    bool configSerialPort();//配置串口
    void dealRawData(QByteArray &rawData);//处理串口数据

private:
    QSerialPort *serialHandler;
    struct Config
    {
        float **matrix1;
        float **matrix2;
        float **matrix3;
        float *offset1;
        float *offset2;
        float *other;
    } config;
};


#endif // FUNCTION_H
