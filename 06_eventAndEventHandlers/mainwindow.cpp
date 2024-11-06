#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "a.h"
#include "b.h"
#include "c.h"
#include <QFrame>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(800, 800);

    c = new C(this);
    c->resize(700, 700);
    c->move(50, 50);
    c->setFrameStyle(QFrame::Panel | QFrame::Plain);
    c->setLineWidth(3);
    c->setMidLineWidth(3);

    b = new B(c);
    b->resize(500, 500);
    b->move(100, 100);
    b->setFrameStyle(QFrame::Panel | QFrame::Plain);
    b->setLineWidth(3);
    b->setMidLineWidth(3);

    a = new A(b);
    a->resize(300, 300);
    a->move(150, 150);
    a->setFrameStyle(QFrame::Panel | QFrame::Plain);
    a->setLineWidth(3);
    a->setMidLineWidth(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
