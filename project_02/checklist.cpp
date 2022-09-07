#include "checklist.h"
#include "ui_checklist.h"
#include <QDateTime>
#include <QDebug>
#include <QCheckBox>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QTextBlock>
#include <QMessageBox>

CheckList::CheckList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckList)
{
    ui->setupUi(this);
    init();

}

CheckList::~CheckList()
{
    delete ui;
}

//初始化
void CheckList::init()
{
    QString dateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss ddd");//获取当前日期和时间
    ui->label_dateTime->setText(dateTime);
    ui->tableWidget_checkList->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableWidget_checkList->horizontalHeader()->setStretchLastSection(true);
//    ui->tableWidget_checkList->setSelectionBehavior(QTableWidget::SelectRows);
//    ui->tableWidget_checkList->setStyleSheet("selection-background-color: red");
    this->setWindowState(Qt::WindowMaximized);

    //设置表格内容
    readCSV();
    if(checkData.count() > 0)//如果读取了csv文件，重新设置表格
    {
        ui->tableWidget_checkList->clearContents();
        ui->tableWidget_checkList->setRowCount(dataLen);
        int row = 0;
        for(auto it : projectList)
        {
            QString projectName = it;
            QStringList contentList = checkData[it];
            QTableWidgetItem *rowHead = new QTableWidgetItem(projectName);
            ui->tableWidget_checkList->setItem(row, 0, rowHead);
            rowHead->setFlags(rowHead->flags() & (~Qt::ItemIsSelectable));
            for(int i = 0; i < contentList.count(); ++i)
            {
                ui->tableWidget_checkList->setItem(row + i, 1, new QTableWidgetItem(QString("%1").arg(i+1)));
                ui->tableWidget_checkList->setItem(row + i, 2, new QTableWidgetItem(contentList.at(i)));
            }
            row += contentList.count();
        }
    }

    //设置前三列不可编辑
    QTableWidgetItem* pItem = nullptr;
    int tableRowCount = ui->tableWidget_checkList->rowCount();
    for(int i = 0; i < tableRowCount; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            pItem = ui->tableWidget_checkList->item(i, j);;
            if(pItem != nullptr )
            {
                pItem->setFlags(pItem->flags() & (~Qt::ItemIsEditable));
            }
        }
    }

    //合并第一列单元格
    if(checkData.count() > 0)
    {
        int row = 0;
        for(auto it : projectList)
        {
            int rowCount = checkData[it].count();
            ui->tableWidget_checkList->setSpan(row, 0, rowCount, 1);
            row += rowCount;
        }
    }
    else
    {
        ui->tableWidget_checkList->setSpan(0, 0, 20, 1);
        ui->tableWidget_checkList->setSpan(20, 0, 18, 1);
        ui->tableWidget_checkList->setSpan(38, 0, 4, 1);
        ui->tableWidget_checkList->setSpan(42, 0, 6, 1);
    }

    //添加checkButton
    for(int i = 0; i < tableRowCount; ++i)
    {
        QCheckBox *checkYes = new QCheckBox("是", ui->tableWidget_checkList);
        ui->tableWidget_checkList->setCellWidget(i, 3, checkYes);
        connect(checkYes, SIGNAL(clicked(bool)), this, SLOT(singleChoose(bool)));
        QCheckBox *checkNo = new QCheckBox("否", ui->tableWidget_checkList);
        ui->tableWidget_checkList->setCellWidget(i, 4, checkNo);
        connect(checkNo, SIGNAL(clicked(bool)), this, SLOT(singleChoose(bool)));
    }
}

//设置单选
void CheckList::singleChoose(bool state)
{
    QCheckBox *checkSender = dynamic_cast<QCheckBox *>(QObject::sender());
    QCheckBox *neighbor = nullptr;
    if(checkSender != nullptr)
    {
        //获取自己在表中的位置
        int x = checkSender->mapToParent(QPoint(0, 0)).x();
        int y = checkSender->mapToParent(QPoint(0, 0)).y();
        QModelIndex index = ui->tableWidget_checkList->indexAt(QPoint(x, y));
        int row = index.row();
        int colum = index.column();

//        ui->tableWidget_checkList->setCurrentCell(row, colum);//设置当前选中的单元格
        if(colum == 3)
        {
             neighbor = dynamic_cast<QCheckBox *>(ui->tableWidget_checkList->cellWidget(row, 4));
             for(int i = 1; i < ui->tableWidget_checkList->columnCount(); ++i)
             {
                 QTableWidgetItem *it = ui->tableWidget_checkList->item(row, i);
                 if(it != nullptr)
                 {
                     it->setBackgroundColor(Qt::white);
                 }
                 else
                 {
                     QWidget *widget = ui->tableWidget_checkList->cellWidget(row, i);
                     //qDebug() << widget;
                     if(widget != nullptr)
                     {
                         widget->setStyleSheet("background-color:white;");
                     }
                 }
             }
        }
        if(colum == 4)
        {
             neighbor = dynamic_cast<QCheckBox *>(ui->tableWidget_checkList->cellWidget(row, 3));
             for(int i = 1; i < ui->tableWidget_checkList->columnCount(); ++i)
             {
                 QTableWidgetItem *it = ui->tableWidget_checkList->item(row, i);
                 if(it != nullptr)
                 {
                     it->setBackgroundColor(Qt::red);
                 }
                 else
                 {
                     QWidget *widget = ui->tableWidget_checkList->cellWidget(row, i);
                     //qDebug() << widget;
                     if(widget != nullptr)
                     {
                         widget->setStyleSheet("background-color:red;");
                     }
                 }
             }
        }
        neighbor->setCheckState(Qt::Unchecked);
    }
}

//保存
void CheckList::on_pushButton_save_clicked()
{
    //检查是否选择所有项目
    int chooseCount = 0;
    for(int i = 0; i < ui->tableWidget_checkList->rowCount(); ++i)
    {
        QCheckBox *checkYes = dynamic_cast<QCheckBox *>(ui->tableWidget_checkList->cellWidget(i, 3));
        QCheckBox *checkNo = dynamic_cast<QCheckBox *>(ui->tableWidget_checkList->cellWidget(i, 4));
        if(checkYes->isChecked() || checkNo->isChecked())
        {
            chooseCount++;
        }
        if(checkNo->isChecked())
        {
            QTableWidgetItem *it = ui->tableWidget_checkList->item(i, 5);
            if(it == nullptr || it->text() == "")
            {
                int ret = QMessageBox::critical(this, tr("警告"), tr("请添加相关备注！"), QMessageBox::Ok, QMessageBox::Ok);
                return;
            }
        }
    }
    if(chooseCount != ui->tableWidget_checkList->rowCount())
    {
        int ret = QMessageBox::critical(this, tr("警告"), tr("请勾选所有项目！"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    //保存文件
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存文件"), tr(""), tr("PDF(*.pdf)"));
    if(!fileName.contains(".pdf"))
    {
        fileName += ".pdf";
    }

    QString htmlForSave;
    //抬头部分
    htmlForSave += "<h2 align=\"center\">PCB_Design_CheckList</h2>";
    htmlForSave += "<h4 align =\"center\">" + ui->label_dateTime->text() + "</h4>";
    htmlForSave += "<h3 align = \"center\">所属项目：" + ui->lineEdit_project->text() +
                    "       项目负责人：" + ui->lineEdit_manager->text() + "</h3>";
    //表格部分
    htmlForSave += "<table margin=\"auto\" border=\"0.2\" cellspacing=\"0\" cellpadding=\"0\"  style=\" 100%; height: 100%;\">";
    int tableRowCount = ui->tableWidget_checkList->rowCount();
    int tableColumCount = ui->tableWidget_checkList->columnCount();
    //表头
    htmlForSave += "<tr>";
    for(int j = 0; j < tableColumCount; ++j)
    {
        if(j == 3)
        {
            htmlForSave += "<th>所选项目</th>";
        }
        else if(j == 4)
        {
            continue;
        }
        else
        {
            htmlForSave += "<th>" + ui->tableWidget_checkList->horizontalHeaderItem(j)->text() + "</th>";
        }
    }
    htmlForSave == "</tr>";

    //表格内容
    QTableWidgetItem* pItem = nullptr;
    for(int i = 0; i < tableRowCount; ++i)
    {
        htmlForSave += "<tr>";
        for(int j = 0; j < tableColumCount; ++j)
        {
            //除勾选框外的内容保存
            if(j != tableColumCount - 3 && j != tableColumCount -2)
            {

                pItem = ui->tableWidget_checkList->item(i, j);
                if(pItem != nullptr)
                {
                    QString content = pItem->text();
                    //合并第一列的单元格
                    if(j == 0)
                    {
                        if(dataLen > 0)
                        {
                            htmlForSave += "<td rowspan=\"" + QString("%1").arg(checkData[content].count()) + "\" " +
                                    "align=\"center\" valign=\"middle\">" + content +"</td>";
                        }
                        else
                        {
                            if(i == 0)
                            {
                                htmlForSave += "<td rowspan=\"20\" align=\"center\" valign=\"middle\">" + content +"</td>";
                            }
                            if(i == 20)
                            {
                                htmlForSave += "<td rowspan=\"18\" align=\"center\" valign=\"middle\">" + content +"</td>";
                            }
                            if(i == 38)
                            {
                                htmlForSave += "<td rowspan=\"4\" align=\"center\" valign=\"middle\">" + content +"</td>";
                            }
                            if(i == 42)
                            {
                                htmlForSave += "<td rowspan=\"6\" align=\"center\" valign=\"middle\">" + content +"</td>";
                            }
                        }
                    }
                    else//保存序号和检查内容这两列的内容
                    {
                        QCheckBox *checkButton = dynamic_cast<QCheckBox *>(ui->tableWidget_checkList->cellWidget(i, 3));
                        if(checkButton->isChecked())
                        {
                            htmlForSave += "<td>" + content + "</td>";
                        }
                        else
                        {
                            htmlForSave += "<td ><font color=\"red\">" + content + "</font></td>";
                        }
                    }
                }
            }
            else//保存勾选框的内容
            {
                QCheckBox *checkButton = dynamic_cast<QCheckBox *>(ui->tableWidget_checkList->cellWidget(i, j));
                if(checkButton != nullptr)
                {
                    QString temp;
                    if(checkButton->isChecked())
                    {
                        if(checkButton->text() == "是")
                        {
                            temp = "<td align=\"center\">是</td>";
                        }
                        else
                        {
                            temp = "<td align=\"center\"><font color=\"red\">否</font></td>";
                        }
                    }

                    htmlForSave += temp;
                }
            }
        }
        htmlForSave += "<\tr>";
    }
    htmlForSave += "</tr></table>";

    QPrinter printer_text;
    printer_text.setOutputFormat(QPrinter::PdfFormat);
    printer_text.setPageSize(QPrinter::A4);
    printer_text.setPageMargins(QMarginsF(0,0,0,0));
    printer_text.setOutputFileName(fileName);//fileName为要保存的pdf文件名
    QTextDocument text_document;
    text_document.setHtml(htmlForSave);
    text_document.print(&printer_text);
}

void CheckList::readCSV()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择文件"), "./", tr("csv (*.csv)"));//选取csv文件
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        int ret = QMessageBox::critical(this, tr("警告"), tr("csv文件打开失败，展示默认内容"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    //开始提取csv文件
    QTextStream * read = new QTextStream(&file);
    QStringList rawData = read->readAll().split("\r\n",QString::SkipEmptyParts);//提取原始的文件数据
    dataLen = rawData.count();//记录数据条数
    int i = 0;
    while(i < rawData.count())
    {
        QStringList strLine = rawData.at(i).split(",");//每条数据是以逗号分开的
        if(strLine.at(0) != "")
        {
            QString projectName = strLine.at(0);
            projectList.append(projectName);
            QStringList contentList;
            contentList.append(strLine.at(2));
            ++i;
            strLine = rawData.at(i).split(",");//提取数据
            while(strLine.at(0) == "")
            {
                contentList.append(strLine.at(2));
                ++i;
                if(i >= rawData.count())
                {
                    break;
                }
                strLine = rawData.at(i).split(",");
            }
            checkData[projectName] = contentList;
        }
    }
}
