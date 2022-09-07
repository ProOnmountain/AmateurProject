#include "checklist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CheckList w;
    w.show();

    return a.exec();
}
