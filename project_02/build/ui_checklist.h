/********************************************************************************
** Form generated from reading UI file 'checklist.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKLIST_H
#define UI_CHECKLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckList
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_dateTime;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_project;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_manager;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *tableWidget_checkList;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CheckList)
    {
        if (CheckList->objectName().isEmpty())
            CheckList->setObjectName(QStringLiteral("CheckList"));
        CheckList->resize(646, 707);
        centralWidget = new QWidget(CheckList);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_dateTime = new QLabel(centralWidget);
        label_dateTime->setObjectName(QStringLiteral("label_dateTime"));

        horizontalLayout_3->addWidget(label_dateTime);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_project = new QLineEdit(centralWidget);
        lineEdit_project->setObjectName(QStringLiteral("lineEdit_project"));

        horizontalLayout->addWidget(lineEdit_project);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_manager = new QLineEdit(centralWidget);
        lineEdit_manager->setObjectName(QStringLiteral("lineEdit_manager"));

        horizontalLayout_4->addWidget(lineEdit_manager);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 4);

        verticalLayout->addLayout(horizontalLayout_5);

        tableWidget_checkList = new QTableWidget(centralWidget);
        if (tableWidget_checkList->columnCount() < 6)
            tableWidget_checkList->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_checkList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_checkList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_checkList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_checkList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_checkList->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_checkList->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget_checkList->rowCount() < 48)
            tableWidget_checkList->setRowCount(48);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(7, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(8, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(9, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(10, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(11, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(12, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(13, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(14, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(15, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(16, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(17, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(18, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(19, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(20, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(21, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(22, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(23, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(24, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(25, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(26, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(27, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(28, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(29, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(30, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(31, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(32, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(33, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(34, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(35, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(36, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(37, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(38, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(39, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(40, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(41, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(42, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(43, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(44, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(45, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(46, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget_checkList->setVerticalHeaderItem(47, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_checkList->setItem(0, 0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget_checkList->setItem(0, 1, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget_checkList->setItem(0, 2, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget_checkList->setItem(1, 1, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget_checkList->setItem(1, 2, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget_checkList->setItem(2, 1, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget_checkList->setItem(2, 2, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget_checkList->setItem(3, 1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget_checkList->setItem(3, 2, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget_checkList->setItem(4, 1, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget_checkList->setItem(4, 2, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget_checkList->setItem(5, 1, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget_checkList->setItem(5, 2, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget_checkList->setItem(6, 1, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget_checkList->setItem(6, 2, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget_checkList->setItem(7, 1, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget_checkList->setItem(7, 2, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget_checkList->setItem(8, 1, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget_checkList->setItem(8, 2, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget_checkList->setItem(9, 1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget_checkList->setItem(9, 2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget_checkList->setItem(10, 1, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget_checkList->setItem(10, 2, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget_checkList->setItem(11, 1, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget_checkList->setItem(11, 2, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        tableWidget_checkList->setItem(12, 1, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        tableWidget_checkList->setItem(12, 2, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        tableWidget_checkList->setItem(13, 1, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget_checkList->setItem(13, 2, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget_checkList->setItem(14, 1, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        tableWidget_checkList->setItem(14, 2, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        tableWidget_checkList->setItem(15, 1, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        tableWidget_checkList->setItem(15, 2, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        tableWidget_checkList->setItem(16, 1, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        tableWidget_checkList->setItem(16, 2, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        tableWidget_checkList->setItem(17, 1, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        tableWidget_checkList->setItem(17, 2, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        tableWidget_checkList->setItem(18, 1, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        tableWidget_checkList->setItem(18, 2, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        tableWidget_checkList->setItem(19, 1, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        tableWidget_checkList->setItem(19, 2, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        __qtablewidgetitem95->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_checkList->setItem(20, 0, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        tableWidget_checkList->setItem(20, 1, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        tableWidget_checkList->setItem(20, 2, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        tableWidget_checkList->setItem(21, 1, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        tableWidget_checkList->setItem(21, 2, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        tableWidget_checkList->setItem(22, 1, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        tableWidget_checkList->setItem(22, 2, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        tableWidget_checkList->setItem(23, 1, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        tableWidget_checkList->setItem(23, 2, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        tableWidget_checkList->setItem(24, 1, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        tableWidget_checkList->setItem(24, 2, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        tableWidget_checkList->setItem(25, 1, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        tableWidget_checkList->setItem(25, 2, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        tableWidget_checkList->setItem(26, 1, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        tableWidget_checkList->setItem(26, 2, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        tableWidget_checkList->setItem(27, 1, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        tableWidget_checkList->setItem(27, 2, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        tableWidget_checkList->setItem(28, 1, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        tableWidget_checkList->setItem(28, 2, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        tableWidget_checkList->setItem(29, 1, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        tableWidget_checkList->setItem(29, 2, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        tableWidget_checkList->setItem(30, 1, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        tableWidget_checkList->setItem(30, 2, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        tableWidget_checkList->setItem(31, 1, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        tableWidget_checkList->setItem(31, 2, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        tableWidget_checkList->setItem(32, 1, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        tableWidget_checkList->setItem(32, 2, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        tableWidget_checkList->setItem(33, 1, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        tableWidget_checkList->setItem(33, 2, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        tableWidget_checkList->setItem(34, 1, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        tableWidget_checkList->setItem(34, 2, __qtablewidgetitem125);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        tableWidget_checkList->setItem(35, 1, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        tableWidget_checkList->setItem(35, 2, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        tableWidget_checkList->setItem(36, 1, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        tableWidget_checkList->setItem(36, 2, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        tableWidget_checkList->setItem(37, 1, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        tableWidget_checkList->setItem(37, 2, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        __qtablewidgetitem132->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_checkList->setItem(38, 0, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        tableWidget_checkList->setItem(38, 1, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        tableWidget_checkList->setItem(38, 2, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        tableWidget_checkList->setItem(39, 1, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        tableWidget_checkList->setItem(39, 2, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        tableWidget_checkList->setItem(40, 1, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        tableWidget_checkList->setItem(40, 2, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        tableWidget_checkList->setItem(41, 1, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        tableWidget_checkList->setItem(41, 2, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        __qtablewidgetitem141->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_checkList->setItem(42, 0, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        tableWidget_checkList->setItem(42, 1, __qtablewidgetitem142);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        tableWidget_checkList->setItem(42, 2, __qtablewidgetitem143);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        tableWidget_checkList->setItem(43, 1, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        tableWidget_checkList->setItem(43, 2, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        tableWidget_checkList->setItem(44, 1, __qtablewidgetitem146);
        QTableWidgetItem *__qtablewidgetitem147 = new QTableWidgetItem();
        tableWidget_checkList->setItem(44, 2, __qtablewidgetitem147);
        QTableWidgetItem *__qtablewidgetitem148 = new QTableWidgetItem();
        tableWidget_checkList->setItem(45, 1, __qtablewidgetitem148);
        QTableWidgetItem *__qtablewidgetitem149 = new QTableWidgetItem();
        tableWidget_checkList->setItem(45, 2, __qtablewidgetitem149);
        QTableWidgetItem *__qtablewidgetitem150 = new QTableWidgetItem();
        tableWidget_checkList->setItem(46, 1, __qtablewidgetitem150);
        QTableWidgetItem *__qtablewidgetitem151 = new QTableWidgetItem();
        tableWidget_checkList->setItem(46, 2, __qtablewidgetitem151);
        QTableWidgetItem *__qtablewidgetitem152 = new QTableWidgetItem();
        tableWidget_checkList->setItem(47, 1, __qtablewidgetitem152);
        QTableWidgetItem *__qtablewidgetitem153 = new QTableWidgetItem();
        tableWidget_checkList->setItem(47, 2, __qtablewidgetitem153);
        tableWidget_checkList->setObjectName(QStringLiteral("tableWidget_checkList"));
        tableWidget_checkList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget_checkList->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_checkList->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget_checkList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        horizontalLayout_2->addWidget(pushButton_save);


        verticalLayout->addLayout(horizontalLayout_2);

        CheckList->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CheckList);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 23));
        CheckList->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CheckList);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CheckList->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CheckList);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CheckList->setStatusBar(statusBar);

        retranslateUi(CheckList);

        QMetaObject::connectSlotsByName(CheckList);
    } // setupUi

    void retranslateUi(QMainWindow *CheckList)
    {
        CheckList->setWindowTitle(QApplication::translate("CheckList", "CheckList", Q_NULLPTR));
        label_3->setText(QApplication::translate("CheckList", "PCB_Design_CheckList", Q_NULLPTR));
        label_dateTime->setText(QString());
        label->setText(QApplication::translate("CheckList", "\346\211\200\345\261\236\351\241\271\347\233\256\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("CheckList", "\351\241\271\347\233\256\350\264\237\350\264\243\344\272\272\357\274\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_checkList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CheckList", "\351\241\271\347\233\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_checkList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CheckList", "\345\272\217\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_checkList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CheckList", "\346\243\200\346\237\245\345\206\205\345\256\271", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_checkList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CheckList", "yes\357\274\210\345\277\205\345\241\253\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_checkList->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CheckList", "no\357\274\210\345\277\205\345\241\253\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_checkList->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("CheckList", "\346\267\273\345\212\240\345\244\207\346\263\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_checkList->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("CheckList", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_checkList->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("CheckList", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_checkList->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("CheckList", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_checkList->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("CheckList", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_checkList->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("CheckList", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_checkList->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("CheckList", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_checkList->verticalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("CheckList", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_checkList->verticalHeaderItem(7);
        ___qtablewidgetitem13->setText(QApplication::translate("CheckList", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_checkList->verticalHeaderItem(8);
        ___qtablewidgetitem14->setText(QApplication::translate("CheckList", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_checkList->verticalHeaderItem(9);
        ___qtablewidgetitem15->setText(QApplication::translate("CheckList", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_checkList->verticalHeaderItem(10);
        ___qtablewidgetitem16->setText(QApplication::translate("CheckList", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_checkList->verticalHeaderItem(11);
        ___qtablewidgetitem17->setText(QApplication::translate("CheckList", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_checkList->verticalHeaderItem(12);
        ___qtablewidgetitem18->setText(QApplication::translate("CheckList", "13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_checkList->verticalHeaderItem(13);
        ___qtablewidgetitem19->setText(QApplication::translate("CheckList", "14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_checkList->verticalHeaderItem(14);
        ___qtablewidgetitem20->setText(QApplication::translate("CheckList", "15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_checkList->verticalHeaderItem(15);
        ___qtablewidgetitem21->setText(QApplication::translate("CheckList", "16", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_checkList->verticalHeaderItem(16);
        ___qtablewidgetitem22->setText(QApplication::translate("CheckList", "17", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_checkList->verticalHeaderItem(17);
        ___qtablewidgetitem23->setText(QApplication::translate("CheckList", "18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_checkList->verticalHeaderItem(18);
        ___qtablewidgetitem24->setText(QApplication::translate("CheckList", "19", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_checkList->verticalHeaderItem(19);
        ___qtablewidgetitem25->setText(QApplication::translate("CheckList", "20", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_checkList->verticalHeaderItem(20);
        ___qtablewidgetitem26->setText(QApplication::translate("CheckList", "21", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_checkList->verticalHeaderItem(21);
        ___qtablewidgetitem27->setText(QApplication::translate("CheckList", "22", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_checkList->verticalHeaderItem(22);
        ___qtablewidgetitem28->setText(QApplication::translate("CheckList", "23", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_checkList->verticalHeaderItem(23);
        ___qtablewidgetitem29->setText(QApplication::translate("CheckList", "24", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_checkList->verticalHeaderItem(24);
        ___qtablewidgetitem30->setText(QApplication::translate("CheckList", "25", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_checkList->verticalHeaderItem(25);
        ___qtablewidgetitem31->setText(QApplication::translate("CheckList", "26", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_checkList->verticalHeaderItem(26);
        ___qtablewidgetitem32->setText(QApplication::translate("CheckList", "27", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_checkList->verticalHeaderItem(27);
        ___qtablewidgetitem33->setText(QApplication::translate("CheckList", "28", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_checkList->verticalHeaderItem(28);
        ___qtablewidgetitem34->setText(QApplication::translate("CheckList", "29", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_checkList->verticalHeaderItem(29);
        ___qtablewidgetitem35->setText(QApplication::translate("CheckList", "30", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_checkList->verticalHeaderItem(30);
        ___qtablewidgetitem36->setText(QApplication::translate("CheckList", "31", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_checkList->verticalHeaderItem(31);
        ___qtablewidgetitem37->setText(QApplication::translate("CheckList", "32", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_checkList->verticalHeaderItem(32);
        ___qtablewidgetitem38->setText(QApplication::translate("CheckList", "33", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_checkList->verticalHeaderItem(33);
        ___qtablewidgetitem39->setText(QApplication::translate("CheckList", "34", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_checkList->verticalHeaderItem(34);
        ___qtablewidgetitem40->setText(QApplication::translate("CheckList", "35", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_checkList->verticalHeaderItem(35);
        ___qtablewidgetitem41->setText(QApplication::translate("CheckList", "36", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_checkList->verticalHeaderItem(36);
        ___qtablewidgetitem42->setText(QApplication::translate("CheckList", "37", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_checkList->verticalHeaderItem(37);
        ___qtablewidgetitem43->setText(QApplication::translate("CheckList", "38", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_checkList->verticalHeaderItem(38);
        ___qtablewidgetitem44->setText(QApplication::translate("CheckList", "39", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_checkList->verticalHeaderItem(39);
        ___qtablewidgetitem45->setText(QApplication::translate("CheckList", "40", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_checkList->verticalHeaderItem(40);
        ___qtablewidgetitem46->setText(QApplication::translate("CheckList", "41", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_checkList->verticalHeaderItem(41);
        ___qtablewidgetitem47->setText(QApplication::translate("CheckList", "42", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_checkList->verticalHeaderItem(42);
        ___qtablewidgetitem48->setText(QApplication::translate("CheckList", "43", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_checkList->verticalHeaderItem(43);
        ___qtablewidgetitem49->setText(QApplication::translate("CheckList", "44", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_checkList->verticalHeaderItem(44);
        ___qtablewidgetitem50->setText(QApplication::translate("CheckList", "45", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget_checkList->verticalHeaderItem(45);
        ___qtablewidgetitem51->setText(QApplication::translate("CheckList", "46", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget_checkList->verticalHeaderItem(46);
        ___qtablewidgetitem52->setText(QApplication::translate("CheckList", "47", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget_checkList->verticalHeaderItem(47);
        ___qtablewidgetitem53->setText(QApplication::translate("CheckList", "48", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget_checkList->isSortingEnabled();
        tableWidget_checkList->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget_checkList->item(0, 0);
        ___qtablewidgetitem54->setText(QApplication::translate("CheckList", "schematic", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget_checkList->item(0, 1);
        ___qtablewidgetitem55->setText(QApplication::translate("CheckList", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget_checkList->item(0, 2);
        ___qtablewidgetitem56->setText(QApplication::translate("CheckList", "\347\241\256\350\256\244\346\211\200\346\234\211\345\231\250\344\273\266\345\260\201\350\243\205\346\230\257\345\220\246\346\255\243\347\241\256.", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget_checkList->item(1, 1);
        ___qtablewidgetitem57->setText(QApplication::translate("CheckList", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget_checkList->item(1, 2);
        ___qtablewidgetitem58->setText(QApplication::translate("CheckList", "\346\257\215\346\235\277\344\270\216\345\255\220\346\235\277\357\274\214\345\215\225\346\235\277\344\270\216\350\203\214\346\235\277\357\274\214\347\241\256\350\256\244\344\277\241\345\217\267\345\257\271\345\272\224\357\274\214\344\275\215\347\275\256\345\257\271\345\272\224\357\274\214\350\277\236\346\216\245\345\231\250\346\226\271\345\220\221\345\217\212\344\270\235\345\215\260\346\240\207\350\257\206\346\255\243\347\241\256\357\274\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget_checkList->item(2, 1);
        ___qtablewidgetitem59->setText(QApplication::translate("CheckList", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget_checkList->item(2, 2);
        ___qtablewidgetitem60->setText(QApplication::translate("CheckList", "\345\205\203\345\231\250\344\273\266\346\230\257\345\220\246100% \346\224\276\347\275\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget_checkList->item(3, 1);
        ___qtablewidgetitem61->setText(QApplication::translate("CheckList", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget_checkList->item(3, 2);
        ___qtablewidgetitem62->setText(QApplication::translate("CheckList", "\346\211\223\345\274\200\345\231\250\344\273\266TOP\345\222\214BOTTOM\345\261\202\347\232\204place-bound\357\274\214 \346\237\245\347\234\213\351\207\215\345\217\240\345\274\225\350\265\267\347\232\204DRC\346\230\257\345\220\246\345\205\201\350\256\270", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget_checkList->item(4, 1);
        ___qtablewidgetitem63->setText(QApplication::translate("CheckList", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget_checkList->item(4, 2);
        ___qtablewidgetitem64->setText(QApplication::translate("CheckList", "Mark\347\202\271\346\230\257\345\220\246\350\266\263\345\244\237\344\270\224\345\277\205\350\246\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget_checkList->item(5, 1);
        ___qtablewidgetitem65->setText(QApplication::translate("CheckList", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget_checkList->item(5, 2);
        ___qtablewidgetitem66->setText(QApplication::translate("CheckList", "\350\276\203\351\207\215\347\232\204\345\205\203\345\231\250\344\273\266\357\274\214\345\272\224\350\257\245\345\270\203\346\224\276\345\234\250\351\235\240\350\277\221PCB\346\224\257\346\222\221\347\202\271\346\210\226\346\224\257\346\222\221\350\276\271\347\232\204\345\234\260\346\226\271\357\274\214\344\273\245\345\207\217\345\260\221PCB\347\232\204\347\277\230\346\233\262", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget_checkList->item(6, 1);
        ___qtablewidgetitem67->setText(QApplication::translate("CheckList", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget_checkList->item(6, 2);
        ___qtablewidgetitem68->setText(QApplication::translate("CheckList", "\344\270\216\347\273\223\346\236\204\347\233\270\345\205\263\347\232\204\345\231\250\344\273\266\345\270\203\345\245\275\345\261\200\345\220\216\346\234\200\345\245\275\351\224\201\344\275\217\357\274\214\351\230\262\346\255\242\350\257\257\346\223\215\344\275\234\347\247\273\345\212\250\344\275\215\347\275\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget_checkList->item(7, 1);
        ___qtablewidgetitem69->setText(QApplication::translate("CheckList", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget_checkList->item(7, 2);
        ___qtablewidgetitem70->setText(QApplication::translate("CheckList", "\345\216\213\346\216\245\346\217\222\345\272\247\345\221\250\345\233\2645mm\350\214\203\345\233\264\345\206\205\357\274\214\346\255\243\351\235\242\344\270\215\345\205\201\350\256\270\346\234\211\351\253\230\345\272\246\350\266\205\350\277\207\345\216\213\346\216\245\346\217\222\345\272\247\351\253\230\345\272\246\347\232\204\345\205\203\344\273\266\357\274\214\350\203\214\351\235\242\344\270\215\345\205\201\350\256\270\346\234\211\345\205\203\344\273\266\346\210\226\347\204\212\347\202\271", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget_checkList->item(8, 1);
        ___qtablewidgetitem71->setText(QApplication::translate("CheckList", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget_checkList->item(8, 2);
        ___qtablewidgetitem72->setText(QApplication::translate("CheckList", "\347\241\256\350\256\244\345\231\250\344\273\266\345\270\203\345\261\200\346\230\257\345\220\246\346\273\241\350\266\263\345\267\245\350\211\272\346\200\247\350\246\201\346\261\202\357\274\210\351\207\215\347\202\271\345\205\263\346\263\250BGA\343\200\201PLCC\343\200\201\350\264\264\347\211\207\346\217\222\345\272\247\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget_checkList->item(9, 1);
        ___qtablewidgetitem73->setText(QApplication::translate("CheckList", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget_checkList->item(9, 2);
        ___qtablewidgetitem74->setText(QApplication::translate("CheckList", "\351\207\221\345\261\236\345\243\263\344\275\223\347\232\204\345\205\203\345\231\250\344\273\266\357\274\214\347\211\271\345\210\253\346\263\250\346\204\217\344\270\215\350\246\201\344\270\216\345\205\266\345\256\203\345\205\203\345\231\250\344\273\266\347\233\270\347\242\260\357\274\214\350\246\201\347\225\231\346\234\211\350\266\263\345\244\237\347\232\204\347\251\272\351\227\264\344\275\215\347\275\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget_checkList->item(10, 1);
        ___qtablewidgetitem75->setText(QApplication::translate("CheckList", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget_checkList->item(10, 2);
        ___qtablewidgetitem76->setText(QApplication::translate("CheckList", "\346\216\245\345\217\243\347\233\270\345\205\263\347\232\204\345\231\250\344\273\266\345\260\275\351\207\217\351\235\240\350\277\221\346\216\245\345\217\243\346\224\276\347\275\256\357\274\214\350\203\214\346\235\277\346\200\273\347\272\277\351\251\261\345\212\250\345\231\250\345\260\275\351\207\217\351\235\240\350\277\221\350\203\214\346\235\277\350\277\236\346\216\245\345\231\250\346\224\276\347\275\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget_checkList->item(11, 1);
        ___qtablewidgetitem77->setText(QApplication::translate("CheckList", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget_checkList->item(11, 2);
        ___qtablewidgetitem78->setText(QApplication::translate("CheckList", "\346\263\242\345\263\260\347\204\212\351\235\242\347\232\204CHIP\345\231\250\344\273\266\346\230\257\345\220\246\345\267\262\347\273\217\350\275\254\346\215\242\346\210\220\346\263\242\345\263\260\347\204\212\345\260\201\350\243\205\357\274\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget_checkList->item(12, 1);
        ___qtablewidgetitem79->setText(QApplication::translate("CheckList", "13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget_checkList->item(12, 2);
        ___qtablewidgetitem80->setText(QApplication::translate("CheckList", "\346\211\213\345\267\245\347\204\212\347\202\271\346\230\257\345\220\246\350\266\205\350\277\20750\344\270\252", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget_checkList->item(13, 1);
        ___qtablewidgetitem81->setText(QApplication::translate("CheckList", "14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget_checkList->item(13, 2);
        ___qtablewidgetitem82->setText(QApplication::translate("CheckList", "\345\234\250PCB\344\270\212\350\275\264\345\220\221\346\217\222\350\243\205\350\276\203\351\253\230\347\232\204\345\205\203\344\273\266\357\274\214\345\272\224\350\257\245\350\200\203\350\231\221\345\215\247\345\274\217\345\256\211\350\243\205\343\200\202\347\225\231\345\207\272\345\215\247\346\224\276\347\251\272\351\227\264\343\200\202\345\271\266\344\270\224\350\200\203\350\231\221\345\233\272\345\256\232\346\226\271\345\274\217\357\274\214\345\246\202\346\231\266\346\214\257\347\232\204\345\233\272\345\256\232\347\204\212\347\233\230", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget_checkList->item(14, 1);
        ___qtablewidgetitem83->setText(QApplication::translate("CheckList", "15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem84 = tableWidget_checkList->item(14, 2);
        ___qtablewidgetitem84->setText(QApplication::translate("CheckList", "\351\234\200\350\246\201\344\275\277\347\224\250\346\225\243\347\203\255\347\211\207\347\232\204\345\231\250\344\273\266\357\274\214\347\241\256\350\256\244\344\270\216\345\205\266\345\256\203\345\231\250\344\273\266\346\234\211\350\266\263\345\244\237\351\227\264\350\267\235\357\274\214\345\271\266\344\270\224\346\263\250\346\204\217\346\225\243\347\203\255\347\211\207\350\214\203\345\233\264\345\206\205\344\270\273\350\246\201\345\231\250\344\273\266\347\232\204\351\253\230\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem85 = tableWidget_checkList->item(15, 1);
        ___qtablewidgetitem85->setText(QApplication::translate("CheckList", "16", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem86 = tableWidget_checkList->item(15, 2);
        ___qtablewidgetitem86->setText(QApplication::translate("CheckList", "\346\225\260\346\250\241\346\267\267\345\220\210\346\235\277\347\232\204\346\225\260\345\255\227\347\224\265\350\267\257\345\222\214\346\250\241\346\213\237\347\224\265\350\267\257\345\231\250\344\273\266\345\270\203\345\261\200\346\227\266\346\230\257\345\220\246\345\267\262\347\273\217\345\210\206\345\274\200\357\274\214\344\277\241\345\217\267\346\265\201\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem87 = tableWidget_checkList->item(16, 1);
        ___qtablewidgetitem87->setText(QApplication::translate("CheckList", "17", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem88 = tableWidget_checkList->item(16, 2);
        ___qtablewidgetitem88->setText(QApplication::translate("CheckList", "A/D\350\275\254\346\215\242\345\231\250\350\267\250\346\250\241\346\225\260\345\210\206\345\214\272\346\224\276\347\275\256\343\200\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem89 = tableWidget_checkList->item(17, 1);
        ___qtablewidgetitem89->setText(QApplication::translate("CheckList", "18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem90 = tableWidget_checkList->item(17, 2);
        ___qtablewidgetitem90->setText(QApplication::translate("CheckList", "\346\227\266\351\222\237\345\231\250\344\273\266\345\270\203\345\261\200\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem91 = tableWidget_checkList->item(18, 1);
        ___qtablewidgetitem91->setText(QApplication::translate("CheckList", "19", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem92 = tableWidget_checkList->item(18, 2);
        ___qtablewidgetitem92->setText(QApplication::translate("CheckList", "\351\253\230\351\200\237\344\277\241\345\217\267\345\231\250\344\273\266\345\270\203\345\261\200\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem93 = tableWidget_checkList->item(19, 1);
        ___qtablewidgetitem93->setText(QApplication::translate("CheckList", "20", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem94 = tableWidget_checkList->item(19, 2);
        ___qtablewidgetitem94->setText(QApplication::translate("CheckList", "\347\253\257\346\216\245\345\231\250\344\273\266\346\230\257\345\220\246\345\267\262\345\220\210\347\220\206\346\224\276\347\275\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem95 = tableWidget_checkList->item(20, 0);
        ___qtablewidgetitem95->setText(QApplication::translate("CheckList", "placement", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem96 = tableWidget_checkList->item(20, 1);
        ___qtablewidgetitem96->setText(QApplication::translate("CheckList", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem97 = tableWidget_checkList->item(20, 2);
        ___qtablewidgetitem97->setText(QApplication::translate("CheckList", "\357\274\210\346\272\220\347\253\257\345\214\271\351\205\215\344\270\262\351\230\273\345\272\224\346\224\276\345\234\250\344\277\241\345\217\267\347\232\204\351\251\261\345\212\250\347\253\257\357\274\233\344\270\255\351\227\264\345\214\271\351\205\215\347\232\204\344\270\262\351\230\273\346\224\276\345\234\250\344\270\255\351\227\264\344\275\215\347\275\256\357\274\233\347\273\210\347\253\257\345\214\271\351\205\215\344\270\262\351\230\273\345\272\224\346\224\276\345\234\250\344\277\241\345\217\267\347\232\204\346\216\245\346\224\266\347\253\257\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem98 = tableWidget_checkList->item(21, 1);
        ___qtablewidgetitem98->setText(QApplication::translate("CheckList", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem99 = tableWidget_checkList->item(21, 2);
        ___qtablewidgetitem99->setText(QApplication::translate("CheckList", "IC\345\231\250\344\273\266\347\232\204\345\216\273\350\200\246\347\224\265\345\256\271\346\225\260\351\207\217\345\217\212\344\275\215\347\275\256\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem100 = tableWidget_checkList->item(22, 1);
        ___qtablewidgetitem100->setText(QApplication::translate("CheckList", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem101 = tableWidget_checkList->item(22, 2);
        ___qtablewidgetitem101->setText(QApplication::translate("CheckList", "\344\277\241\345\217\267\347\272\277\344\273\245\344\270\215\345\220\214\347\224\265\345\271\263\347\232\204\345\271\263\351\235\242\344\275\234\344\270\272\345\217\202\350\200\203\345\271\263\351\235\242\357\274\214\345\275\223\350\267\250\350\266\212\345\271\263\351\235\242\345\210\206\345\211\262\345\214\272\345\237\237\346\227\266\357\274\214\345\217\202\350\200\203\345\271\263\351\235\242\351\227\264\347\232\204\350\277\236\346\216\245\347\224\265\345\256\271\346\230\257\345\220\246\351\235\240\350\277\221\344\277\241\345\217\267\347\232\204\350\265\260\347\272\277\345\214\272\345\237\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem102 = tableWidget_checkList->item(23, 1);
        ___qtablewidgetitem102->setText(QApplication::translate("CheckList", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem103 = tableWidget_checkList->item(23, 2);
        ___qtablewidgetitem103->setText(QApplication::translate("CheckList", "\344\277\235\346\212\244\347\224\265\350\267\257\347\232\204\345\270\203\345\261\200\346\230\257\345\220\246\345\220\210\347\220\206\357\274\214\346\230\257\345\220\246\345\210\251\344\272\216\345\210\206\345\211\262", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem104 = tableWidget_checkList->item(24, 1);
        ___qtablewidgetitem104->setText(QApplication::translate("CheckList", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem105 = tableWidget_checkList->item(24, 2);
        ___qtablewidgetitem105->setText(QApplication::translate("CheckList", "\345\215\225\346\235\277\347\224\265\346\272\220\347\232\204\344\277\235\351\231\251\344\270\235\346\230\257\345\220\246\346\224\276\347\275\256\345\234\250\350\277\236\346\216\245\345\231\250\351\231\204\350\277\221\357\274\214\344\270\224\345\211\215\351\235\242\346\262\241\346\234\211\344\273\273\344\275\225\347\224\265\350\267\257\345\205\203\344\273\266", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem106 = tableWidget_checkList->item(25, 1);
        ___qtablewidgetitem106->setText(QApplication::translate("CheckList", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem107 = tableWidget_checkList->item(25, 2);
        ___qtablewidgetitem107->setText(QApplication::translate("CheckList", "\347\241\256\350\256\244\345\274\272\344\277\241\345\217\267\344\270\216\345\274\261\344\277\241\345\217\267\357\274\210\345\212\237\347\216\207\347\233\270\345\267\25630dB\357\274\211\347\224\265\350\267\257\345\210\206\345\274\200\345\270\203\350\256\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem108 = tableWidget_checkList->item(26, 1);
        ___qtablewidgetitem108->setText(QApplication::translate("CheckList", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem109 = tableWidget_checkList->item(26, 2);
        ___qtablewidgetitem109->setText(QApplication::translate("CheckList", "\346\230\257\345\220\246\346\214\211\347\205\247\350\256\276\350\256\241\346\214\207\345\215\227\346\210\226\345\217\202\350\200\203\346\210\220\345\212\237\347\273\217\351\252\214\346\224\276\347\275\256\345\217\257\350\203\275\345\275\261\345\223\215EMC\345\256\236\351\252\214\347\232\204\345\231\250\344\273\266\343\200\202\345\246\202\357\274\232\351\235\242\346\235\277\347\232\204\345\244\215\344\275\215\347\224\265\350\267\257\350\246\201\347\250\215\351\235\240\350\277\221\345\244\215\344\275\215\346\214\211\351\222\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem110 = tableWidget_checkList->item(27, 1);
        ___qtablewidgetitem110->setText(QApplication::translate("CheckList", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem111 = tableWidget_checkList->item(27, 2);
        ___qtablewidgetitem111->setText(QApplication::translate("CheckList", "\345\257\271\347\203\255\346\225\217\346\204\237\347\232\204\345\205\203\344\273\266\357\274\210\345\220\253\346\266\262\346\200\201\344\273\213\350\264\250\347\224\265\345\256\271\343\200\201\346\231\266\346\214\257\357\274\211\345\260\275\351\207\217\350\277\234\347\246\273\345\244\247\345\212\237\347\216\207\347\232\204\345\205\203\345\231\250\344\273\266\343\200\201\346\225\243\347\203\255\345\231\250\347\255\211\347\203\255\346\272\220", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem112 = tableWidget_checkList->item(28, 1);
        ___qtablewidgetitem112->setText(QApplication::translate("CheckList", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem113 = tableWidget_checkList->item(28, 2);
        ___qtablewidgetitem113->setText(QApplication::translate("CheckList", "\345\270\203\345\261\200\346\230\257\345\220\246\346\273\241\350\266\263\347\203\255\350\256\276\350\256\241\350\246\201\346\261\202\357\274\214\346\225\243\347\203\255\351\200\232\351\201\223\357\274\210\346\240\271\346\215\256\345\267\245\350\211\272\350\256\276\350\256\241\346\226\207\344\273\266\346\235\245\346\211\247\350\241\214\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem114 = tableWidget_checkList->item(29, 1);
        ___qtablewidgetitem114->setText(QApplication::translate("CheckList", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem115 = tableWidget_checkList->item(29, 2);
        ___qtablewidgetitem115->setText(QApplication::translate("CheckList", "\346\230\257\345\220\246IC\347\224\265\346\272\220\350\267\235\347\246\273IC\350\277\207\350\277\234", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem116 = tableWidget_checkList->item(30, 1);
        ___qtablewidgetitem116->setText(QApplication::translate("CheckList", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem117 = tableWidget_checkList->item(30, 2);
        ___qtablewidgetitem117->setText(QApplication::translate("CheckList", "LDO\345\217\212\345\221\250\345\233\264\347\224\265\350\267\257\345\270\203\345\261\200\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem118 = tableWidget_checkList->item(31, 1);
        ___qtablewidgetitem118->setText(QApplication::translate("CheckList", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem119 = tableWidget_checkList->item(31, 2);
        ___qtablewidgetitem119->setText(QApplication::translate("CheckList", "\346\250\241\345\235\227\347\224\265\346\272\220\347\255\211\345\221\250\345\233\264\347\224\265\350\267\257\345\270\203\345\261\200\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem120 = tableWidget_checkList->item(32, 1);
        ___qtablewidgetitem120->setText(QApplication::translate("CheckList", "13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem121 = tableWidget_checkList->item(32, 2);
        ___qtablewidgetitem121->setText(QApplication::translate("CheckList", "\347\224\265\346\272\220\347\232\204\346\225\264\344\275\223\345\270\203\345\261\200\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem122 = tableWidget_checkList->item(33, 1);
        ___qtablewidgetitem122->setText(QApplication::translate("CheckList", "14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem123 = tableWidget_checkList->item(33, 2);
        ___qtablewidgetitem123->setText(QApplication::translate("CheckList", "\346\230\257\345\220\246\346\211\200\346\234\211\344\273\277\347\234\237\347\272\246\346\235\237\351\203\275\345\267\262\347\273\217\346\255\243\347\241\256\345\212\240\345\210\260Constraint Manager\344\270\255", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem124 = tableWidget_checkList->item(34, 1);
        ___qtablewidgetitem124->setText(QApplication::translate("CheckList", "15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem125 = tableWidget_checkList->item(34, 2);
        ___qtablewidgetitem125->setText(QApplication::translate("CheckList", "\346\230\257\345\220\246\346\255\243\347\241\256\350\256\276\347\275\256\347\211\251\347\220\206\345\222\214\347\224\265\346\260\224\350\247\204\345\210\231\357\274\210\346\263\250\346\204\217\347\224\265\346\272\220\347\275\221\347\273\234\345\222\214\345\234\260\347\275\221\347\273\234\347\232\204\347\272\246\346\235\237\350\256\276\347\275\256\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem126 = tableWidget_checkList->item(35, 1);
        ___qtablewidgetitem126->setText(QApplication::translate("CheckList", "16", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem127 = tableWidget_checkList->item(35, 2);
        ___qtablewidgetitem127->setText(QApplication::translate("CheckList", "Test Via\343\200\201Test Pin\347\232\204\351\227\264\350\267\235\350\256\276\347\275\256\346\230\257\345\220\246\350\266\263\345\244\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem128 = tableWidget_checkList->item(36, 1);
        ___qtablewidgetitem128->setText(QApplication::translate("CheckList", "17", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem129 = tableWidget_checkList->item(36, 2);
        ___qtablewidgetitem129->setText(QApplication::translate("CheckList", "\345\217\240\345\261\202\347\232\204\345\216\232\345\272\246\345\222\214\346\226\271\346\241\210\346\230\257\345\220\246\346\273\241\350\266\263\350\256\276\350\256\241\345\222\214\345\212\240\345\267\245\350\246\201\346\261\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem130 = tableWidget_checkList->item(37, 1);
        ___qtablewidgetitem130->setText(QApplication::translate("CheckList", "18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem131 = tableWidget_checkList->item(37, 2);
        ___qtablewidgetitem131->setText(QApplication::translate("CheckList", "\346\211\200\346\234\211\346\234\211\347\211\271\346\200\247\351\230\273\346\212\227\350\246\201\346\261\202\347\232\204\345\267\256\345\210\206\347\272\277\351\230\273\346\212\227\346\230\257\345\220\246\345\267\262\347\273\217\347\273\217\350\277\207\350\256\241\347\256\227\357\274\214\345\271\266\347\224\250\350\247\204\345\210\231\346\216\247\345\210\266", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem132 = tableWidget_checkList->item(38, 0);
        ___qtablewidgetitem132->setText(QApplication::translate("CheckList", "layout", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem133 = tableWidget_checkList->item(38, 1);
        ___qtablewidgetitem133->setText(QApplication::translate("CheckList", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem134 = tableWidget_checkList->item(38, 2);
        ___qtablewidgetitem134->setText(QApplication::translate("CheckList", "\346\230\257\345\220\246IC\347\224\265\346\272\220\350\267\235\347\246\273IC\350\277\207\350\277\234", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem135 = tableWidget_checkList->item(39, 1);
        ___qtablewidgetitem135->setText(QApplication::translate("CheckList", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem136 = tableWidget_checkList->item(39, 2);
        ___qtablewidgetitem136->setText(QApplication::translate("CheckList", "LDO\345\217\212\345\221\250\345\233\264\347\224\265\350\267\257\345\270\203\345\261\200\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem137 = tableWidget_checkList->item(40, 1);
        ___qtablewidgetitem137->setText(QApplication::translate("CheckList", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem138 = tableWidget_checkList->item(40, 2);
        ___qtablewidgetitem138->setText(QApplication::translate("CheckList", "\346\250\241\345\235\227\347\224\265\346\272\220\347\255\211\345\221\250\345\233\264\347\224\265\350\267\257\345\270\203\345\261\200\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem139 = tableWidget_checkList->item(41, 1);
        ___qtablewidgetitem139->setText(QApplication::translate("CheckList", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem140 = tableWidget_checkList->item(41, 2);
        ___qtablewidgetitem140->setText(QApplication::translate("CheckList", "\347\224\265\346\272\220\347\232\204\346\225\264\344\275\223\345\270\203\345\261\200\346\230\257\345\220\246\345\220\210\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem141 = tableWidget_checkList->item(42, 0);
        ___qtablewidgetitem141->setText(QApplication::translate("CheckList", "dfm", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem142 = tableWidget_checkList->item(42, 1);
        ___qtablewidgetitem142->setText(QApplication::translate("CheckList", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem143 = tableWidget_checkList->item(42, 2);
        ___qtablewidgetitem143->setText(QApplication::translate("CheckList", "\345\231\250\344\273\266\344\275\215\345\217\267\346\230\257\345\220\246\351\201\227\346\274\217\357\274\214\344\275\215\347\275\256\346\230\257\345\220\246\350\203\275\346\255\243\347\241\256\346\240\207\350\257\206\345\231\250\344\273\266", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem144 = tableWidget_checkList->item(43, 1);
        ___qtablewidgetitem144->setText(QApplication::translate("CheckList", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem145 = tableWidget_checkList->item(43, 2);
        ___qtablewidgetitem145->setText(QApplication::translate("CheckList", "\345\231\250\344\273\266\344\275\215\345\217\267\345\221\275\345\220\215\346\230\257\345\220\246\345\207\206\347\241\256\357\274\214\346\214\211\347\205\247\345\210\206\347\261\273\345\220\246\347\254\246\345\220\210\350\246\201\346\261\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem146 = tableWidget_checkList->item(44, 1);
        ___qtablewidgetitem146->setText(QApplication::translate("CheckList", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem147 = tableWidget_checkList->item(44, 2);
        ___qtablewidgetitem147->setText(QApplication::translate("CheckList", "\347\241\256\350\256\244\345\231\250\344\273\266\347\232\204\347\256\241\350\204\232\346\216\222\345\210\227\351\241\272\345\272\217\357\274\214 \347\254\2541\350\204\232\346\240\207\345\277\227\357\274\214\345\231\250\344\273\266\347\232\204\346\236\201\346\200\247\346\240\207\345\277\227\357\274\214\350\277\236\346\216\245\345\231\250\347\232\204\346\226\271\345\220\221\346\240\207\350\257\206\347\232\204\346\255\243\347\241\256\346\200\247", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem148 = tableWidget_checkList->item(45, 1);
        ___qtablewidgetitem148->setText(QApplication::translate("CheckList", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem149 = tableWidget_checkList->item(45, 2);
        ___qtablewidgetitem149->setText(QApplication::translate("CheckList", "\350\203\214\346\235\277\346\230\257\345\220\246\346\255\243\347\241\256\346\240\207\350\257\206\344\272\206\346\247\275\344\275\215\345\220\215\343\200\201\346\247\275\344\275\215\345\217\267\343\200\201\347\253\257\345\217\243\345\220\215\347\247\260\343\200\201\346\212\244\345\245\227\346\226\271\345\220\221", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem150 = tableWidget_checkList->item(46, 1);
        ___qtablewidgetitem150->setText(QApplication::translate("CheckList", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem151 = tableWidget_checkList->item(46, 2);
        ___qtablewidgetitem151->setText(QApplication::translate("CheckList", "\347\241\256\350\256\244\345\267\262\347\273\217\346\224\276\347\275\256\346\234\211\351\230\262\351\235\231\347\224\265\345\222\214\345\260\204\351\242\221\346\235\277\346\240\207\350\257\206\357\274\210\345\260\204\351\242\221\346\235\277\344\275\277\347\224\250\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem152 = tableWidget_checkList->item(47, 1);
        ___qtablewidgetitem152->setText(QApplication::translate("CheckList", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem153 = tableWidget_checkList->item(47, 2);
        ___qtablewidgetitem153->setText(QApplication::translate("CheckList", "\347\241\256\350\256\244PCB\347\274\226\347\240\201\346\255\243\347\241\256\357\274\214\344\270\224\346\240\271\346\215\256\350\207\252\350\272\253\345\205\254\345\217\270\346\203\205\345\206\265\357\274\214\350\256\276\347\275\256PCB\347\274\226\347\240\201\350\247\204\350\214\203\343\200\202", Q_NULLPTR));
        tableWidget_checkList->setSortingEnabled(__sortingEnabled);

        pushButton_save->setText(QApplication::translate("CheckList", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CheckList: public Ui_CheckList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKLIST_H
