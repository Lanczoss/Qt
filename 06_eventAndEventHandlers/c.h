#ifndef C_H
#define C_H

#include <QLabel>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>

class C : public QLabel
{
    Q_OBJECT
public:
    explicit C(QWidget *parent = nullptr);

    bool event(QEvent *e) override {
        if (e->type() == QEvent::MouseButtonRelease) {
            qDebug() << "C event";
        }
        return QLabel::event(e);
    }

    void mouseReleaseEvent(QMouseEvent *e) override {
        qDebug() << "C event handler";
        e->accept();
    }
signals:
};

#endif // C_H
