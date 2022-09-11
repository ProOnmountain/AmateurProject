#ifndef SERIALSENDER_H
#define SERIALSENDER_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>         // 提供访问串口的功能
#include <QtSerialPort/QSerialPortInfo>      // 提供系统中存在的串口信息
#include <QTimer>

namespace Ui {
class SerialSender;
}

class SerialSender : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialSender(QWidget *parent = 0);
    ~SerialSender();

private slots:
    void on_pushButton_clicked();
    void sendData();

    void on_pushButton_2_clicked();

private:
    void serialportInit();

private:
    Ui::SerialSender *ui;
    QSerialPort *serialPort;
    QTimer *sendTimer;
    double time;
};

#endif // SERIALSENDER_H
