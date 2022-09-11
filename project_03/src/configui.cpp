#include "configui.h"
#include "ui_configui.h"
#include "function.h"

ConfigUI::ConfigUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigUI)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
}

ConfigUI::~ConfigUI()
{
    delete ui;
}  

void ConfigUI::on_pushButton_apply_clicked()
{
    Function function;
    vector<vector<float>> matrix1;
    vector<vector<float>> matrix2;
    //获取界面输入

    //计算
    emit showLineIndex(ui->comboBox_line1->currentIndex() - 1, ui->comboBox_line2->currentIndex() - 1);
}
