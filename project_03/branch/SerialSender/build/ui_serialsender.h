/********************************************************************************
** Form generated from reading UI file 'serialsender.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALSENDER_H
#define UI_SERIALSENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialSender
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SerialSender)
    {
        if (SerialSender->objectName().isEmpty())
            SerialSender->setObjectName(QStringLiteral("SerialSender"));
        SerialSender->resize(400, 300);
        centralWidget = new QWidget(SerialSender);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        SerialSender->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SerialSender);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        SerialSender->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SerialSender);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SerialSender->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SerialSender);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SerialSender->setStatusBar(statusBar);

        retranslateUi(SerialSender);

        QMetaObject::connectSlotsByName(SerialSender);
    } // setupUi

    void retranslateUi(QMainWindow *SerialSender)
    {
        SerialSender->setWindowTitle(QApplication::translate("SerialSender", "SerialSender", Q_NULLPTR));
        label->setText(QApplication::translate("SerialSender", "\344\270\262\345\217\243\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SerialSender", "\346\211\223\345\274\200", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SerialSender", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialSender: public Ui_SerialSender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALSENDER_H
