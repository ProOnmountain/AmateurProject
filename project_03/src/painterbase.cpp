#include "painterbase.h"
#include <QLabel>

PainterBase::PainterBase(QWidget *parent) : QChartView(parent)
{
    init();
}

void PainterBase::init()
{
}
