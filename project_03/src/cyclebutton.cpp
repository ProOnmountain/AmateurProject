#include "cyclebutton.h"
#include <QPainter>
CycleButton::CycleButton(QWidget *parent) : QPushButton(parent)
{
    radius = 20;
}

CycleButton::~CycleButton()
{

}

void CycleButton::paintEvent(QPaintEvent *event)
{
    //绘制准备工作,启用反锯齿
    QPainter painter(this);
//    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.save();
//    QColor borderColorStart = QColor(Qt::gray);
//    int borderWidth = 1;
//    painter.setPen(QPen(borderColorStart, borderWidth));
//    QPointF topLeft(borderWidth, borderWidth);
//    QPointF bottomRight(2 * radius, 2 * radius);
//    QBrush brush;
//    brush.setColor(Qt::gray);//设置颜色
//    brush.setStyle(Qt::SolidPattern);
//    painter.setBrush(brush);
//    painter.drawEllipse(QRectF(topLeft, bottomRight));
//    painter.restore();
    QPixmap setUpImage(":/image/setUp.png");
//    QPixmap setUpPix = setUpImage.scaled(QSize(2 *radius, 2 *radius), Qt::KeepAspectRatio);
    painter.drawPixmap(2 *radius, 2 *radius, 2 *radius, 2 *radius, setUpImage);
    painter.restore();
}
