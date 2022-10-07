#ifndef PAINTERBASE_H
#define PAINTERBASE_H

#include <QWidget>
#include <QChartView>
using namespace QtCharts;
class PainterBase : public QChartView
{
    Q_OBJECT
public:
    explicit PainterBase(QWidget *parent = nullptr);
    virtual void mouseDoubleClickEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);

private:
    void init();

signals:
    void playStop();
public:
    bool isMove = true;
    int mouse_x, mouse_y;
    
};

#endif // PAINTERBASE_H
