#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *e) override {
        QPointF mouse = e->position();
        if (((mouse.x() - mosquito_x >= 0) && (mouse.x() - mosquito_x <= 20))|| ((mouse.y() - mosquito_y >= 0) && (mouse.y() - mosquito_y <= 20))) {
            getRandomMosPosition();
            emit addScore();
            update();
        }
        e->accept();
    }

    void paintEvent(QPaintEvent *e) override {
        QPainter qp(this);
        QPixmap map(":/new/prefix1/mos.jpg");
        qp.drawPixmap(mosquito_x, mosquito_y, 20, 20, map);
        e->accept();
    }

    void getRandomMosPosition();

signals:
    void addScore();

private:
    double mosquito_x;
    double mosquito_y;
};

#endif // GAMEWINDOW_H
