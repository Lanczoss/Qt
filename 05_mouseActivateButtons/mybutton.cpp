#include "mybutton.h"

MyButton::MyButton(QWidget *parent)
    : QPushButton(parent)
{}

void MyButton::bSlot(double x, double y) {
    move(10 * x + 400, 10 * y + 150);
}
