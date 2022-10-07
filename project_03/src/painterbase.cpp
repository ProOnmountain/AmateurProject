#include "painterbase.h"
#include <QLabel>
#include <QValueAxis>
#include <QDebug>

PainterBase::PainterBase(QWidget *parent) : QChartView(parent)
{
    init();
}

void PainterBase::init()
{

}

void PainterBase::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        if(isMove == true)
        {
            emit playStop();
        }
        else
        {
            isMove = true;
        }
        mouse_x = e->x();
        mouse_y = e->y();
    }
}

void PainterBase::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        if(isMove == false)
        {
            int cur_mouse_x = e->x();
            int cur_mouse_y = e->y();
            QValueAxis *axisX = dynamic_cast<QValueAxis*>(this->chart()->axisX());
            if(cur_mouse_x < mouse_x)
            {
                this->chart()->scroll(10, 0);
            }
            else
            {
                if(axisX->min() > 0)
                {
                    this->chart()->scroll(-10, 0);
                }
                if(axisX->min() < 0)
                {
                    axisX->setMin(0);
                }

            }
            mouse_x = cur_mouse_x;
            mouse_y = cur_mouse_y;
        }
    }
}
