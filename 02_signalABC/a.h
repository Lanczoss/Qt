#ifndef A_H
#define A_H

#include <QObject>

class A : public QObject
{
    Q_OBJECT
public:
    explicit A(QObject *parent = nullptr);

signals:
    void aSignal();
    void bSignal();
    void cSignal();
public slots:
    void bSlot();
    void cSlot();
};

#endif // A_H
