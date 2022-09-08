#ifndef CORRECTUI_H
#define CORRECTUI_H

#include <QMainWindow>

namespace Ui {
class CorrectUI;
}

class CorrectUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit CorrectUI(QWidget *parent = 0);
    ~CorrectUI();

private:
    Ui::CorrectUI *ui;
};

#endif // CORRECTUI_H
