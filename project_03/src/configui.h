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
    void sendConfig(float **, float **, float **, float *, float *, float *);

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
    void getMatrixOffset();
    virtual void closeEvent(QCloseEvent *event);

private:
    Ui::ConfigUI *ui;
    float **matrix1;
    float **matrix2;
    float **matrix3;
    float *offset1;
    float *offset2;
    float *other;

};

#endif // ConfigUI_H
