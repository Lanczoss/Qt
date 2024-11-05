#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>

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

    void clickedSlot();
    void undoSlot();
    bool isWin();
    void clear();

private:
    Ui::MainWindow *ui;
    QVector<QPushButton *> step;
};
#endif // MAINWINDOW_H
