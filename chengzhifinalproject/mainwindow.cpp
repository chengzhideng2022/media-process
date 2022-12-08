#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPainter painter(this);
    QPixmap pix;
     this->sc = new myScene;
    this->ui->gameview->setScene(sc);
}

MainWindow::~MainWindow()
{
    delete ui;
}

