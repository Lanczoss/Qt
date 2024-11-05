#include "mainwindow.h"
#include "mysignalsandslots.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySignalsAndSlots ms;
    emit ms.mySignal();
    return a.exec();
}
