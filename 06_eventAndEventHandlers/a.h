#ifndef A_H
#define A_H

#include <QLabel>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>

class A : public QLabel
{
    Q_OBJECT
public:
    explicit A(QWidget *parent = nullptr);

    bool event(QEvent *e) override {
        if (e->type() == QEvent::MouseButtonRelease) {
            qDebug() << "A event";
        }
        return QLabel::event(e);
    }

    void mouseReleaseEvent(QMouseEvent *e) override {
        qDebug() << "A event handler";
        e->ignore();
    }

signals:
};

#endif // A_H
