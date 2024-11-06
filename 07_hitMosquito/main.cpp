#include "mainwindow.h"
#include "gamewindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("打蚊子");

    GameWindow *gw = new GameWindow(&w);
    gw->move(50, 50);
    gw->resize(600, 400);

    QObject::connect(gw, &GameWindow::addScore, &w, &MainWindow::scoreSlot);


    w.show();
    return a.exec();
}
