#ifndef PARAMUI_H
#define PARAMUI_H

#include <QMainWindow>

namespace Ui {
class ParamUi;
}

class ParamUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit ParamUi(QWidget *parent = 0);
    ~ParamUi();

private slots:
    void on_pushButtonRun_clicked();

private:
    bool saveParam(QString fileDir);

private:
    Ui::ParamUi *ui;
};

#endif // PARAMUI_H
