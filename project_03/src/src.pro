#-------------------------------------------------
#
# Project created by QtCreator 2022-09-07T18:14:30
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += charts
QT       +=  multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainui.cpp \
    battery.cpp \
    floatbutton.cpp \
    function.cpp \
    painterbase.cpp \
    configui.cpp \
    sound.cpp \
    numberkeyboard.cpp

HEADERS += \
        mainui.h \
    battery.h \
    floatbutton.h \
    function.h \
    painterbase.h \
    configui.h \
    define.h \
    sound.h \
    numberkeyboard.h

FORMS += \
        mainui.ui \
    configui.ui \
    numberkeyboard.ui

RESOURCES += \
    source/mainuisource.qrc

DISTFILES +=
