#include "a.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    A a;
    A b;
    A c;
    qDebug() << "a signal";
    emit a.aSignal();

    qDebug();

    qDebug() << "b signal";
    emit b.bSignal();

    qDebug();

    qDebug() << "c signal";
    emit c.cSignal();
    return 0;
}
