#ifndef B_H
#define B_H

#include <QLabel>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>

class B : public QLabel
{
    Q_OBJECT
public:
    explicit B(QWidget *parent = nullptr);

    bool event(QEvent *e) override {
        if (e->type() == QEvent::MouseButtonRelease) {
            qDebug() << "B event";
            return false;
        }
        return QLabel::event(e);
    }

    void mouseReleaseEvent(QMouseEvent *e) override {
        qDebug() << "B event handler";
        e->ignore();
    }

signals:
};

#endif // B_H
