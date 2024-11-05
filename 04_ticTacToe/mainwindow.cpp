#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton00, &QPushButton::clicked, this, &MainWindow::clickedSlot);
    QObject::connect(ui->pushButton01, &QPushButton::clicked, this, &MainWindow::clickedSlot);
    QObject::connect(ui->pushButton02, &QPushButton::clicked, this, &MainWindow::clickedSlot);
    QObject::connect(ui->pushButton10, &QPushButton::clicked, this, &MainWindow::clickedSlot);
    QObject::connect(ui->pushButton11, &QPushButton::clicked, this, &MainWindow::clickedSlot);
    QObject::connect(ui->pushButton12, &QPushButton::clicked, this, &MainWindow::clickedSlot);
    QObject::connect(ui->pushButton20, &QPushButton::clicked, this, &MainWindow::clickedSlot);
    QObject::connect(ui->pushButton21, &QPushButton::clicked, this, &MainWindow::clickedSlot);
    QObject::connect(ui->pushButton22, &QPushButton::clicked, this, &MainWindow::clickedSlot);
    QObject::connect(ui->buttonUndo, &QPushButton::clicked, this, &MainWindow::undoSlot);
    QObject::connect(ui->buttonClear, &QPushButton::clicked, this, &MainWindow::clear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickedSlot() {
    QPushButton *qpb = qobject_cast<QPushButton*>(sender());
    if (qpb->text() == "") {
        if ((step.size() & 1) == 1) {
            qpb->setText("X");
            step.push_back(qpb);
            ui->label->setText("轮到O方");
        } else {
            qpb->setText("O");
            step.push_back(qpb);
            ui->label->setText("轮到X方");
        }
    }

    // 输赢判断
    if (isWin()) {
        if ((step.size() & 1) == 1) {
            ui->label->setText("O方赢");
            clear();
        } else {
            ui->label->setText("X方赢");
            clear();
        }
    }

    if (step.size() == 9) {
        ui->label->setText("平局");
        clear();
    }
}

bool MainWindow::isWin() {
    if (ui->pushButton00->text() == "X") {
        if (ui->pushButton01->text() == "X") {
            if (ui->pushButton02->text() == "X") {
                return true;
            }
        }
        if (ui->pushButton10->text() == "X") {
            if (ui->pushButton20->text() == "X") {
                return true;
            }
        }
        if (ui->pushButton11->text() == "X") {
            if(ui->pushButton22->text() == "X") {
                return true;
            }
        }
    }

    if (ui->pushButton11->text() == "X") {
        if(ui->pushButton01->text() == "X") {
            if (ui->pushButton21->text() == "X") {
                return true;
            }
        }
        if (ui->pushButton10->text() == "X") {
            if (ui->pushButton12->text() == "X") {
                return true;
            }
        }
        if (ui->pushButton02->text() == "X") {
            if (ui->pushButton20->text() == "X") {
                return true;
            }
        }
    }

    if (ui->pushButton22->text() == "X") {
        if (ui->pushButton12->text() == "X") {
            if (ui->pushButton02->text() == "X") {
                return true;
            }
        }
        if (ui->pushButton21->text() == "X") {
            if (ui->pushButton20->text() == "X") {
                return true;
            }
        }
    }

    if (ui->pushButton00->text() == "O") {
        if (ui->pushButton01->text() == "O") {
            if (ui->pushButton02->text() == "O") {
                return true;
            }
        }
        if (ui->pushButton10->text() == "O") {
            if (ui->pushButton20->text() == "O") {
                return true;
            }
        }
        if (ui->pushButton11->text() == "O") {
            if(ui->pushButton22->text() == "O") {
                return true;
            }
        }
    }

    if (ui->pushButton11->text() == "O") {
        if(ui->pushButton01->text() == "O") {
            if (ui->pushButton21->text() == "O") {
                return true;
            }
        }
        if (ui->pushButton10->text() == "O") {
            if (ui->pushButton12->text() == "O") {
                return true;
            }
        }
        if (ui->pushButton02->text() == "O") {
            if (ui->pushButton20->text() == "O") {
                return true;
            }
        }
    }

    if (ui->pushButton22->text() == "O") {
        if (ui->pushButton12->text() == "O") {
            if (ui->pushButton02->text() == "O") {
                return true;
            }
        }
        if (ui->pushButton21->text() == "O") {
            if (ui->pushButton20->text() == "O") {
                return true;
            }
        }
    }
    return false;
}

void MainWindow::undoSlot()
{
    if (step.size() > 0) {
        step.back()->setText("");
        if ((step.size() & 1) == 1) {
            ui->label->setText("轮到O方");
        } else {
            ui->label->setText("轮到X方");
        }
        step.pop_back();
    }
}

void MainWindow::clear() {
    step.clear();
    ui->pushButton00->setText("");
    ui->pushButton01->setText("");
    ui->pushButton02->setText("");
    ui->pushButton10->setText("");
    ui->pushButton11->setText("");
    ui->pushButton12->setText("");
    ui->pushButton20->setText("");
    ui->pushButton21->setText("");
    ui->pushButton22->setText("");
}
