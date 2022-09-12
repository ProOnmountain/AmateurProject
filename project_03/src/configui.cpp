#include "configui.h"
#include "ui_configui.h"
#include "function.h"
#include  <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>

const QString configDir("../config/");//配置目录
const QString lastConfigFile("../config/.lastConfig");//上一次关机配置
const QString defaultFile("../config/.default");//默认配置文件

ConfigUI::ConfigUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigUI)
{
    ui->setupUi(this);
    init();
}

ConfigUI::~ConfigUI()
{
    delete ui;
}  

void ConfigUI::init()
{
    QDir configDirInfo(configDir);
    QStringList fileList = configDirInfo.entryList();
    qDebug() << fileList;
    fileList.removeOne(".");
    fileList.removeOne("..");
    ui->comboBox_config->addItems(fileList);
    load(lastConfigFile);//加载上一次配置

    //初始化数据存储
    matrix1 = new float*[3];
    matrix2 = new float*[3];
    matrix3 = new float*[3];
    for(int i = 0; i < 3; ++i)
    {
        matrix1[i] = new float[3];
        matrix2[i] = new float[3];
        matrix3[i] = new float[3];
    }
    offset1 = new float[3];
    offset2 = new float[3];
    other = new float[8];
}

void ConfigUI::closeEvent(QCloseEvent *event)
{
    qDebug() << "close";
    on_pushButton_apply_clicked();
}

void ConfigUI::on_pushButton_apply_clicked()
{
    save(lastConfigFile);//保存当前配置

    //获取界面输入
    //获取矩阵输入
    getMatrixOffset();
    //获取其他参数
    other[0] = (ui->comboBox_warn->currentIndex());
    other[1] = (ui->doubleSpinBox_THm->text().toFloat());
    other[2] = (ui->doubleSpinBox_THa->text().toFloat());
    other[3] = (ui->spinBox_MGmax->text().toFloat());
    other[4] = (ui->spinBox_sampleRate->text().toFloat());
    other[5] = (ui->spinBox_MT->text().toFloat());
    other[6] = (ui->spinBox_ML->text().toFloat());
    other[7] = (ui->spinBox_DT->text().toFloat());

    //把数据传到主界面
    emit showLineIndex(ui->comboBox_line1->currentIndex() - 1, ui->comboBox_line2->currentIndex() - 1);
    emit sendConfig(matrix1, matrix2, matrix3, offset1, offset2, other);
    this->hide();
}

void ConfigUI::on_pushButton_save_clicked()
{
    QString fileName = QInputDialog::getText(this, tr("输入文件名"), tr("请输入保存文件名"), QLineEdit::Normal);
    if(fileName != "")
    {
        if(!fileName.contains(".config"))
        {
            fileName += ".config";
        }
        QString totalFileName = configDir + fileName;
        save(totalFileName);
        ui->comboBox_config->addItem(fileName);
    }
    else
    {
        QMessageBox::critical(this, tr("警告"), tr("文件名不能为空！"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

bool ConfigUI::save(QString fileName)
{
    if(fileName == "")
    {
        QMessageBox::critical(this, tr("警告"), tr("文件名不能为空！"), QMessageBox::Ok, QMessageBox::Ok);
        return false;
    }
    QFile fileHandle(fileName);
    if(!fileHandle.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, tr("警告"), tr("文件保存失败，请检查文件！"), QMessageBox::Ok, QMessageBox::Ok);
        return false;
    }
    QTextStream fileStream(&fileHandle);
    //保存探头1矩阵
    fileStream << ui->doubleSpinBox_1_M11->text() << "," << ui->doubleSpinBox_1_M12->text() << "," << ui->doubleSpinBox_1_M13->text() << "\n"
               << ui->doubleSpinBox_1_M21->text() << "," << ui->doubleSpinBox_1_M22->text() << "," << ui->doubleSpinBox_1_M23->text() << "\n"
               << ui->doubleSpinBox_1_M31->text() << "," << ui->doubleSpinBox_1_M32->text() << "," << ui->doubleSpinBox_1_M33->text() << "\n"
               << ui->doubleSpinBox_1x->text() << "," << ui->doubleSpinBox_1y->text() << "," << ui->doubleSpinBox_1z->text() <<"\n";
    //保存探头2矩阵
    fileStream << ui->doubleSpinBox_2_M11->text() << "," << ui->doubleSpinBox_2_M12->text() << "," << ui->doubleSpinBox_2_M13->text() << "\n"
               << ui->doubleSpinBox_2_M21->text() << "," << ui->doubleSpinBox_2_M22->text() << "," << ui->doubleSpinBox_2_M23->text() << "\n"
               << ui->doubleSpinBox_2_M31->text() << "," << ui->doubleSpinBox_1_M32->text() << "," << ui->doubleSpinBox_2_M33->text() << "\n"
               << ui->doubleSpinBox_2x->text() << "," << ui->doubleSpinBox_2y->text() << "," << ui->doubleSpinBox_2z->text() <<"\n";
    //保存分量矩阵
    fileStream << ui->doubleSpinBox_3_M11->text() << "," << ui->doubleSpinBox_3_M12->text() << "," << ui->doubleSpinBox_3_M13->text() << "\n"
               << ui->doubleSpinBox_3_M21->text() << "," << ui->doubleSpinBox_3_M22->text() << "," << ui->doubleSpinBox_3_M23->text() << "\n"
               << ui->doubleSpinBox_3_M31->text() << "," << ui->doubleSpinBox_3_M32->text() << "," << ui->doubleSpinBox_3_M33->text() << "\n";
    //保存显示曲线
    fileStream << ui->comboBox_line1->currentText() << "," << ui->comboBox_line2->currentText() << "\n";
    //保存阈值信息
    fileStream << ui->comboBox_warn->currentText() << "," << ui->doubleSpinBox_THm->text() << "," << ui->doubleSpinBox_THa->text() << ","
               << ui->spinBox_MGmax->text() << "," << ui->spinBox_sampleRate->text() << "\n";
    //保存数据处理配置
    fileStream << ui->spinBox_MT->text() << "," << ui->spinBox_ML->text() << "," << ui->spinBox_DT->text() <<"\n";
    fileHandle.close();
    qDebug().noquote() << "配置保存成功: " << fileHandle.fileName() ;
}

bool ConfigUI::load(QString fileName)
{
    if(!fileName.contains(".config") && !fileName.contains(".lastConfig") && !fileName.contains(".default"))
    {
        QMessageBox::critical(this, tr("警告"), tr("错误的文件，加载默认配置！"), QMessageBox::Ok, QMessageBox::Ok);
        fileName = defaultFile;
    }
    QFile fileHandle(fileName);
    if(!fileHandle.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, tr("警告"), tr("文件打开失败，请检查文件！"), QMessageBox::Ok, QMessageBox::Ok);
        return false;
    }
    QTextStream * read = new QTextStream(&fileHandle);
    QStringList rawData = read->readAll().split("\n",QString::SkipEmptyParts);//提取原始的文件数据
//    qDebug() << rawData;
    for(int i = 0; i < rawData.count(); ++i)
    {
        QStringList strLine = rawData.at(i).split(",");//每条数据是以逗号分开的
        if(i == 0)
        {
            ui->doubleSpinBox_1_M11->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_1_M12->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_1_M13->setValue(strLine[2].toDouble());
        }
        if(i == 1)
        {
            ui->doubleSpinBox_1_M21->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_1_M22->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_1_M23->setValue(strLine[2].toDouble());
        }
        if(i == 2)
        {
            ui->doubleSpinBox_1_M31->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_1_M32->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_1_M33->setValue(strLine[2].toDouble());
        }
        if(i == 3)
        {
            ui->doubleSpinBox_1x->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_1y->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_1z->setValue(strLine[2].toDouble());
        }
        if(i == 4)
        {
            ui->doubleSpinBox_2_M11->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_2_M12->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_2_M13->setValue(strLine[2].toDouble());
        }
        if(i == 5)
        {
            ui->doubleSpinBox_2_M21->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_2_M22->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_2_M23->setValue(strLine[2].toDouble());
        }
        if(i == 6)
        {
            ui->doubleSpinBox_2_M31->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_2_M32->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_2_M33->setValue(strLine[2].toDouble());
        }
        if(i == 7)
        {
            ui->doubleSpinBox_2x->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_2y->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_2z->setValue(strLine[2].toDouble());
        }
        if(i == 8)
        {
            ui->doubleSpinBox_3_M11->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_3_M12->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_3_M13->setValue(strLine[2].toDouble());
        }
        if(i == 9)
        {
            ui->doubleSpinBox_3_M21->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_3_M22->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_3_M23->setValue(strLine[2].toDouble());
        }
        if(i == 10)
        {
            ui->doubleSpinBox_3_M31->setValue(strLine[0].toDouble());
            ui->doubleSpinBox_3_M32->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_3_M33->setValue(strLine[2].toDouble());
        }
        if(i == 11)
        {
            QString line1 = strLine[0];
            QString line2 = strLine[1];
            int len = ui->comboBox_line1->count();
            for(int i = 0; i < len; ++i)
            {
                if(ui->comboBox_line1->itemText(i) == line1)
                {
                    ui->comboBox_line1->setCurrentIndex(i);
                }
                if(ui->comboBox_line2->itemText(i) == line2)
                {
                    ui->comboBox_line2->setCurrentIndex(i);
                }
            }
        }
        if(i == 12)
        {
            QString warn = strLine[0];
            int len = ui->comboBox_warn->count();
            for(int i = 0; i < len; ++i)
            {
                if(ui->comboBox_warn->itemText(i) == warn)
                {
                    ui->comboBox_warn->setCurrentIndex(i);
                }
            }
            ui->doubleSpinBox_THm->setValue(strLine[1].toDouble());
            ui->doubleSpinBox_THa->setValue(strLine[2].toDouble());
            ui->spinBox_MGmax->setValue(strLine[3].toInt());
            ui->spinBox_sampleRate->setValue(strLine[4].toInt());
        }
        if(i == 13)
        {
            ui->spinBox_MT->setValue(strLine[0].toInt());
            ui->spinBox_ML->setValue(strLine[1].toInt());
            ui->spinBox_DT->setValue(strLine[2].toInt());
        }
    }
    fileHandle.close();
}

void ConfigUI::on_pushButton_load_clicked()
{
    int index = ui->comboBox_config->currentIndex();
    QString fileName;
    if(index == 0)
    {
        fileName = lastConfigFile;
    }
    else if(index == 1)
    {
        fileName = defaultFile;
    }
    else
    {
        fileName = configDir + ui->comboBox_config->currentText();
    }
    load(fileName);

}

void ConfigUI::getMatrixOffset()
{
    for(int i = 0; i < 3; ++i)
    {
        if(i == 0)
        {
            matrix1[i][0] = ui->doubleSpinBox_1_M11->text().toFloat();
            matrix2[i][0] = ui->doubleSpinBox_2_M11->text().toFloat();
            matrix3[i][0] = ui->doubleSpinBox_3_M11->text().toFloat();
            matrix1[i][1] = (ui->doubleSpinBox_1_M12->text().toFloat());
            matrix2[i][1] = (ui->doubleSpinBox_2_M12->text().toFloat());
            matrix3[i][1] = (ui->doubleSpinBox_3_M12->text().toFloat());
            matrix1[i][2] = (ui->doubleSpinBox_1_M13->text().toFloat());
            matrix2[i][2] = (ui->doubleSpinBox_2_M13->text().toFloat());
            matrix3[i][2] = (ui->doubleSpinBox_3_M13->text().toFloat());

        }
        if(i == 1)
        {
            matrix1[i][0] = (ui->doubleSpinBox_1_M21->text().toFloat());
            matrix2[i][0] = (ui->doubleSpinBox_2_M21->text().toFloat());
            matrix3[i][0] = (ui->doubleSpinBox_3_M21->text().toFloat());
            matrix1[i][1] = (ui->doubleSpinBox_1_M22->text().toFloat());
            matrix2[i][1] = (ui->doubleSpinBox_2_M22->text().toFloat());
            matrix3[i][1] = (ui->doubleSpinBox_3_M22->text().toFloat());
            matrix1[i][2] = (ui->doubleSpinBox_1_M23->text().toFloat());
            matrix2[i][2] = (ui->doubleSpinBox_2_M23->text().toFloat());
            matrix3[i][2] = (ui->doubleSpinBox_3_M23->text().toFloat());
        }
        if(i == 2)
        {
            matrix1[i][0] = (ui->doubleSpinBox_1_M31->text().toFloat());
            matrix2[i][0] = (ui->doubleSpinBox_2_M31->text().toFloat());
            matrix3[i][0] = (ui->doubleSpinBox_3_M31->text().toFloat());
            matrix1[i][1] = (ui->doubleSpinBox_1_M32->text().toFloat());
            matrix2[i][1] = (ui->doubleSpinBox_2_M32->text().toFloat());
            matrix3[i][1] = (ui->doubleSpinBox_3_M32->text().toFloat());
            matrix1[i][2] = (ui->doubleSpinBox_1_M33->text().toFloat());
            matrix2[i][2] = (ui->doubleSpinBox_2_M33->text().toFloat());
            matrix3[i][2] = (ui->doubleSpinBox_3_M33->text().toFloat());
        }
    }
    for(int i = 0; i < 3; ++i)
    {
        if(i == 0)
        {
            offset1[0] = (ui->doubleSpinBox_1x->text().toFloat());
            offset2[0] = (ui->doubleSpinBox_2x->text().toFloat());
        }
        if(i == 1)
        {
            offset1[1] = (ui->doubleSpinBox_1y->text().toFloat());
            offset2[1] = (ui->doubleSpinBox_2y->text().toFloat());
        }
        if(i == 2)
        {
            offset1[2] = (ui->doubleSpinBox_1z->text().toFloat());
            offset2[2] = (ui->doubleSpinBox_2z->text().toFloat());
        }
    }
}

void ConfigUI::on_pushButton_delete_clicked()
{
    int currentIndex = ui->comboBox_config->currentIndex();
    if(currentIndex > 1)
    {
        QString fileName = configDir + ui->comboBox_config->currentText();
        if(fileName.contains(".config"))
        {
            QFile fileHandle(fileName);
            fileHandle.remove();
        }
        ui->comboBox_config->removeItem(currentIndex);
        load(configDir + ui->comboBox_config->currentText());
    }
}

//void ConfigUI::on_comboBox_config_currentIndexChanged(int index)
//{
//    QString fileName;
//    if(index == 0)
//    {
//        fileName = lastConfigFile;
//    }
//    else if(index == 1)
//    {
//        fileName = defaultFile;
//    }
//    else
//    {
//        fileName = configDir + ui->comboBox_config->currentText();
//    }
//    load(fileName);
//}

void ConfigUI::on_pushButton_matrix1_clicked()
{
    getMatrixOffset();
    emit showLineIndex(ui->comboBox_line1->currentIndex() - 1, ui->comboBox_line2->currentIndex() - 1);
    emit sendConfig(matrix1, matrix2, matrix3, offset1, offset2, other);
}

void ConfigUI::on_pushButton_matrix2_clicked()
{
    getMatrixOffset();
    emit showLineIndex(ui->comboBox_line1->currentIndex() - 1, ui->comboBox_line2->currentIndex() - 1);
    emit sendConfig(matrix1, matrix2, matrix3, offset1, offset2, other);
}

void ConfigUI::on_pushButton_matrix3_clicked()
{
    getMatrixOffset();
    emit showLineIndex(ui->comboBox_line1->currentIndex() - 1, ui->comboBox_line2->currentIndex() - 1);
    emit sendConfig(matrix1, matrix2, matrix3, offset1, offset2, other);
}
