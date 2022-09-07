#include "serialsender.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialSender w;
    w.show();

    return a.exec();
}
