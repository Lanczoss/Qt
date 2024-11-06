#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QMouseEvent>
#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *e) override {
        emit aSignal(e->position().x(), e->position().y());
    }

signals:
    void aSignal(double, double);

public slots:
    void bSlot(double, double);
};

#endif // MYBUTTON_H
