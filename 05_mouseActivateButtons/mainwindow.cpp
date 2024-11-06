#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800, 600);

    a = new MyButton(this);
    a->move(0, 0);
    b = new MyButton(this);
    b->move(400, 150);

    QObject::connect(a, &MyButton::aSignal, b, &MyButton::bSlot);

}

MainWindow::~MainWindow()
{
    delete ui;
}
