#include "a.h"
#include <QObject>
#include <QDebug>

A::A(QObject *parent)
    : QObject{parent}
{
    QObject::connect(this, &A::aSignal, &A::bSlot);
    QObject::connect(this, &A::aSignal, &A::cSlot);
    QObject::connect(this, &A::bSignal, &A::cSlot);
    QObject::connect(this, &A::cSignal, &A::aSignal);
}

void A::bSlot() {
    qDebug() << "bSlot()";
}

void A::cSlot() {
    qDebug() << "cSlot()";
}
