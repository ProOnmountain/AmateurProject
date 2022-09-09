#ifndef CYCLEBUTTON_H
#define CYCLEBUTTON_H

#include <QPushButton>

class CycleButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CycleButton(QWidget *parent = nullptr);
    ~CycleButton();
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:

private:
    int radius;
};

#endif // CYCLEBUTTON_H
