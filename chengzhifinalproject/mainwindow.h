#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscene.h"
#include <QPoint>
#include <QGraphicsView>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void wheelEvent(QWheelEvent *event);
    void getmousePressEvent(QMouseEvent *event);
    void moveView(QKeyEvent *event);
    //void keyPressEvent(QKeyEvent *event);
 //   void keyReleaseEvent(QKeyEvent *event);
   // void userMove();
private:
    Ui::MainWindow *ui;
    myScene *sc;
    QPointF cursorPoint;
    qreal m_qrScaledNum;
    enum{up,down,left,right}movedir;  //坦克移动方向
    enum{moving,stop}state; //移动状态


};
#endif // MAINWINDOW_H
