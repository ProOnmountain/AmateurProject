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

signals:

public slots:
};

#endif // PAINTERBASE_H
