#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->button0, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->button1, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->button2, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->button3, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->button4, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->button5, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->button6, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->button7, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->button8, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->button9, &QPushButton::clicked, this, &MainWindow::numberSlot);
    QObject::connect(ui->buttonDec, &QPushButton::clicked, this, &MainWindow::decSlot);
    QObject::connect(ui->buttonBin, &QPushButton::clicked, this, &MainWindow::binSlot);
    QObject::connect(ui->buttonOct, &QPushButton::clicked, this, &MainWindow::octSlot);
    QObject::connect(ui->buttonHex, &QPushButton::clicked, this, &MainWindow::hexSlot);
    QObject::connect(ui->buttonDel, &QPushButton::clicked, this, &MainWindow::delSlot);
    QObject::connect(ui->buttonClear, &QPushButton::clicked, this, &MainWindow::clearSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberSlot() {
    QPushButton *nb = qobject_cast<QPushButton*>(sender());
    QString temp = ui->lineEdit->text();
    temp.append(nb->text());
    ui->lineEdit->setText(temp);
}

void MainWindow::clearSlot()
{
    ui->lineEdit->setText("");
}


void MainWindow::delSlot()
{
    QString temp = ui->lineEdit->text();
    temp.chop(1);
    ui->lineEdit->setText(temp);
}


void MainWindow::octSlot()
{
    int temp = ui->lineEdit->text().toInt();
    ui->lineEdit->setText(QString("%1").arg(temp, 0, 8));
}


void MainWindow::hexSlot()
{
    int temp = ui->lineEdit->text().toInt();
    ui->lineEdit->setText(QString("%1").arg(temp, 0, 16));
}


void MainWindow::decSlot()
{
    int temp = ui->lineEdit->text().toInt();
    ui->lineEdit->setText(QString("%1").arg(temp, 0, 10));
}


void MainWindow::binSlot()
{
    int temp = ui->lineEdit->text().toInt();
    ui->lineEdit->setText(QString("%1").arg(temp, 0, 2));
}


