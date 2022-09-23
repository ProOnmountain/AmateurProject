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

private:
    void init();
signals:

public slots:
};

#endif // PAINTERBASE_H
