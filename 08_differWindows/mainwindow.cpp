#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowproperties.h"

#include <QObject>
#include <QRadioButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wp = new WindowProperties(this, Qt::Window);
    wp->setWindowTitle("属性");
    QObject::connect(wp, &WindowProperties::signalType, this, &MainWindow::typeSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionProperties_triggered()
{
    wp->show();
}

void MainWindow::typeSlot(Qt::WindowFlags &flags) {
    setWindowFlags(flags);
    wp->update();
    show();
}


