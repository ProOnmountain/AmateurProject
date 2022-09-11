#ifndef ConfigUI_H
#define ConfigUI_H

#include <QMainWindow>

namespace Ui {
class ConfigUI;
}

class ConfigUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConfigUI(QWidget *parent = 0);
    ~ConfigUI();

signals:
    void showLineIndex(int index1, int index2);

private slots:
    void on_pushButton_apply_clicked();

private:
    Ui::ConfigUI *ui;
};

#endif // ConfigUI_H
