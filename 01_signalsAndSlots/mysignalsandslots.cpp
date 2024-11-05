#include "mysignalsandslots.h"
#include <QDebug>
#include <QObject>

MySignalsAndSlots::MySignalsAndSlots(QObject *parent)
    : QObject{parent}
{
    QObject::connect(this, &MySignalsAndSlots::mySignal, &MySignalsAndSlots::mySlot);
}

void MySignalsAndSlots::mySlot() {
    qDebug() << "mySlot()";
}
