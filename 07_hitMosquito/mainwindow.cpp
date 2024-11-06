#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QFrame>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _score(0)
{
    ui->setupUi(this);
    resize(1200, 600);
    score = new QLabel(this);
    score->move(1000, 300);
    score->setText("当前分数：0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scoreSlot() {
    _score++;
    score->setText(QString("当前分数：%1").arg(_score));
}
