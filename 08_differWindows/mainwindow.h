#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class WindowProperties;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void on_actionProperties_triggered();

    void typeSlot(Qt::WindowFlags &flags);

private:
    Ui::MainWindow *ui;
    WindowProperties *wp;
};
#endif // MAINWINDOW_H
