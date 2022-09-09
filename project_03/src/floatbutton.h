#ifndef FLOATBUTTON_H
#define FLOATBUTTON_H

#include <QPushButton>
#include <QComboBox>
#include <QToolButton>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class FloatButton;
}

class FloatButton : public QToolButton
{
    Q_OBJECT

public:
    explicit FloatButton(QWidget *parent = 0);
    ~FloatButton();
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

private:
    void init();

private:
    Ui::FloatButton *ui;
    QPoint m_start;//起始点
    QPoint m_end;//结束点
    bool m_leftButtonPressed;//鼠标左键按下标记
    bool isMove;
};

#endif // FLOATBUTTON_H
