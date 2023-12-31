#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>

#include <QMainWindow>
#include "item.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
     shared_ptr<Item> item;
     QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
