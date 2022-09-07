#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class CheckList;
}

class CheckList : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckList(QWidget *parent = 0);
    ~CheckList();

private slots:
    void singleChoose(bool state);//设置单选

    void on_pushButton_save_clicked();//保存文件，按下保存按钮后执行的函数

private:
    void init();//初始化

    void readCSV();


private:
    Ui::CheckList *ui;
    int dataLen;
    QMap<QString, QStringList> checkData;
    QStringList projectList;
};

#endif // CHECKLIST_H
