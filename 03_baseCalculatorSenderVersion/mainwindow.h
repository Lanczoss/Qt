#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void numberSlot();
    void decSlot();
    void octSlot();
    void hexSlot();
    void binSlot();
    void delSlot();
    void clearSlot();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
