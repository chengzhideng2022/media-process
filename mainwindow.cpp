#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setUp();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUp()
{
    chooseMap = make_unique<ChooseMap>(this);
    chooseMap->setAttribute(Qt::WA_DeleteOnClose);
    gameScreen = nullptr;

    this->setCentralWidget(chooseMap.get());
    connect(chooseMap.get(), &ChooseMap::choose, this, &MainWindow::openMap);

}

void MainWindow::openMap(QString map)
{
  chooseMap->close();
  chooseMap = nullptr;
  gameScreen = make_unique<GameScreen>(this);
  gameScreen->setUp(map);
  connect(gameScreen.get(), &GameScreen::returnToChooseMap, this, &MainWindow::resetPage);
  gameScreen->setAttribute(Qt::WA_DeleteOnClose);
  gameScreen->show();
  this->setCentralWidget(gameScreen.get());
}

void MainWindow::resetPage()
{
    gameScreen->close();
    setUp();
}



