#ifndef BATTERY_H
#define BATTERY_H
#include <QWidget>

class Battery : public QWidget
{
    Q_OBJECT


public:
    explicit Battery(QWidget *parent = 0);
    ~Battery();

protected:
    void paintEvent(QPaintEvent *);
    void drawBorder(QPainter *painter);
    void drawBg(QPainter *painter);
    void drawHead(QPainter *painter);

private:
    double minValue;                //最小值
    double maxValue;                //最大值
    double alarmValue;              //电池电量警戒值

    int borderWidth;                //边框粗细
    QColor borderColorStart;        //边框渐变开始颜色
    QColor borderColorEnd;          //边框渐变结束颜色

    QColor alarmColorStart;         //电池低电量时的渐变开始颜色
    QColor alarmColorEnd;           //电池低电量时的渐变结束颜色

    QColor normalColorStart;        //电池正常电量时的渐变开始颜色
    QColor normalColorEnd;          //电池正常电量时的渐变结束颜色

    bool isForward;                 //是否往前移
    double currentValue;            //当前电量
    QRectF batteryRect;             //电池主体区域

public:
    //设置电池电量值
    void setValue(double value);

    //设置电池电量警戒值
    void setAlarmValue(double alarmValue);
};

#endif // BATTERY_H
