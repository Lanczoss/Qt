#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
{
    ::srand(::time(NULL));
}


void GameWindow::getRandomMosPosition() {
    mosquito_x = rand() % 600;
    mosquito_y = rand() % 400;
}
