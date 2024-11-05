#ifndef MYSIGNALSANDSLOTS_H
#define MYSIGNALSANDSLOTS_H

#include <QObject>

class MySignalsAndSlots : public QObject
{
    Q_OBJECT
public:
    explicit MySignalsAndSlots(QObject *parent = nullptr);

signals:
    void mySignal();

public slots:
    void mySlot();
};

#endif // MYSIGNALSANDSLOTS_H
