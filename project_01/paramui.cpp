#include "paramui.h"
#include "ui_paramui.h"
#include <QDebug>
#include <stdlib.h>
#include <QFile>
#include <QFileDialog>
#include <iostream>

ParamUi::ParamUi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParamUi)
{
    ui->setupUi(this);
}

ParamUi::~ParamUi()
{
    delete ui;
}

bool ParamUi::saveParam(QString fileDir)
{
    QFile fileHandle(fileDir);
    if(!fileHandle.open(QIODevice::WriteOnly))
    {
        return false;
    }
//    fileHandle.open(QIODevice::WriteOnly);
    QTextStream stream(&fileHandle);
    QString begin_step("begin_step = " + ui->lineEditbegin_step->text() + "\n");
    stream << begin_step;
    QString end_step("end_step = " + ui->lineEditend_step->text() + "\n");
    stream << end_step;
    QString int_width("int_width = " + ui->lineEditint_width->text() + "\n");
    stream << int_width;
    QString Nx("Nx = " + ui->lineEditNx->text() + "\n");
    stream << Nx;
    QString Ny("Ny = " + ui->lineEditNy->text() + "\n");
    stream << Ny;
    QString Nz("Nz = " + ui->lineEditNz->text() + "\n");
    stream << Nz;
    QString dx("dx = " + ui->lineEditDx->text() + "\n");
    stream << dx;
    QString dt("dt = " + ui->lineEditdt->text() + "\n");
    stream << dt;
    QString int_grad("int_grad = " + QString("%1").arg(ui->comboBoxint_grad->currentIndex()) + "\n");
    stream << int_grad;
    QString int_pot("int_pot = " + QString("%1").arg(ui->comboBoxint_pot->currentIndex())+ "\n");
    stream << int_pot;
    QString phi_incre_limit("phi_incre_limit = " + ui->lineEditphi_incre_limit->text() + "\n");
    stream << phi_incre_limit;
    QString file_output_step("file_output_step = " + ui->lineEditdataFile_output_step->text() + "\n");
    stream << file_output_step;
    QString screen_output_step("screen_output_step = " + ui->lineEditscreen_output_step->text() + "\n");
    stream << screen_output_step;
    QString is_write_datafile("is_write_datafile = " + ui->comboBoxis_write_datafile->currentText() + "\n");
    stream << is_write_datafile;
    QString is_init_byDatafile("is_init_byDatafile = " + ui->comboBoxis_init_byDatafile->currentText() + "\n");
    stream << is_init_byDatafile;
    QString isPhiOutput("isPhiOutput = " + ui->comboBoxisPhiOutput->currentText() + "\n");
    stream << isPhiOutput;
    QString dataFile_output_step("dataFile_output_step = " + ui->lineEditdataFile_output_step->text() + "\n");
    stream <<dataFile_output_step;
    QString box_position("box_position = (" + ui->lineEdit_box_positionX->text() + ","
                         + ui->lineEdit_box_positionY->text() + ","
                         + ui->lineEdit_box_positionZ->text() + ")\n");
    stream << box_position;
    QString box_size("box_size = (" + ui->lineEditbox_sizeX->text() + ","
                     + ui->lineEditbox_sizeY->text() + ","
                     + ui->lineEditbox_sizeZ->text() + ")\n");
    stream << box_size;
    QString grain_number("grain_number = " + ui->lineEditgrain_number->text() + "\n");
    stream << grain_number;
    QString generate_step("generate_step = " + ui->lineEditgenerate_step->text() + "\n");
    stream <<generate_step;
    QString Xi_abc("Xi_abc = " + ui->lineEditXi_abc->text() + "\n");
    stream << Xi_abc;
    fileHandle.close();
    return true;
}

void ParamUi::on_pushButtonRun_clicked()
{

    QFileDialog *file_dialog = new QFileDialog(this);
    file_dialog->setWindowTitle("打开文件");
    QDir cur_path(QCoreApplication::applicationDirPath());
    file_dialog->setDirectory(cur_path);
    file_dialog->setNameFilter(tr("exe File(*.exe)"));
    QString appName;
    QString appDir;
    if(file_dialog->exec() == QDialog::Accepted)
    {
        appName = file_dialog->selectedFiles().first();
        appDir = file_dialog->directory().absolutePath();
        ui->lineEditExeDir->setText(appName);
    }
    if(appName !="")
    {
        qDebug() << appDir;
        if(saveParam(appDir + "\\multi_grain.mid.input"))
        {
            QString command = QString("cd ") + appDir + "&&" + appName;
//            system(cdCommand.toLatin1().data());
//            system(appName.toLatin1().data());
            qDebug() <<command.toLatin1().data();
            system(command.toLatin1().data());
        }
        else
        {
            qDebug() << "param save failed";
        }
    }
    else
    {
        qDebug() << "wrong exe file";
    }

}
