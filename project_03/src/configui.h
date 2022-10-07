#ifndef ConfigUI_H
#define ConfigUI_H

#include <QMainWindow>
#include <numberkeyboard.h>

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
    void showLineIndex(int index1, int index2);//发送显示的曲线
    void sendConfig(float **, float **, float **, float *, float *, float *);//发送配置信息

private slots:
    void on_pushButton_apply_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_load_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_matrix1_clicked();

    void on_pushButton_matrix2_clicked();

    void on_pushButton_matrix3_clicked();

private:
    void init();
    bool save(QString fileName);//保存参数文件
    bool load(QString fileName);//加载参数文件
    void getMatrixOffset();//获取矩阵和偏移
    virtual void closeEvent(QCloseEvent *event);

private:
    Ui::ConfigUI *ui;
    float **matrix1;
    float **matrix2;
    float **matrix3;
    float *offset1;
    float *offset2;
    float *other;

    NumberKeyboard *keyBoard;//键盘
    QWidget *currentInputWidget;//当前输入对象
};

#endif // ConfigUI_H
