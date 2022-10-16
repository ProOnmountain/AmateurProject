#ifndef NUMBERKEYBOARD_H
#define NUMBERKEYBOARD_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
class NumberKeyboard;
}

class NumberKeyboard : public QWidget
{
    Q_OBJECT

public:
    explicit NumberKeyboard(QWidget *parent = 0);
    ~NumberKeyboard();

private slots:
    void emitKeyEvent();
    void updateInputWidget(QWidget *old,QWidget *inputWidget);

private:
    void connectNumberBtn();//连接数字按钮和获取数字的函数

private:
    Ui::NumberKeyboard *ui;
public:
    QWidget *currentInputWidget;

};

#endif // NUMBERKEYBOARD_H
