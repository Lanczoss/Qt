#ifndef WINDOWPROPERTIES_H
#define WINDOWPROPERTIES_H

#include <QWidget>
#include <QRadioButton>
#include <QCheckBox>

namespace Ui {
class WindowProperties;
}

class WindowProperties : public QWidget
{
    Q_OBJECT

public:
    explicit WindowProperties(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~WindowProperties();

    void checkProperties(Qt::WindowFlags &flags);


signals:
    void signalType(Qt::WindowFlags &flags);

private slots:
    void typeToggled(bool checked);

public:
    Ui::WindowProperties *ui;
};

#endif // WINDOWPROPERTIES_H
