#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscene.h"
#include <QPoint>
#include <QGraphicsView>
#include "chosemappage.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,QString map = ":/img/worldmap.png");
    ~MainWindow();
   //  explicit choseMapPage(QWidget *parent = 0);
    void wheelEvent(QWheelEvent *event);
    void getmousePressEvent(QMouseEvent *event);


    //void keyPressEvent(QKeyEvent *event);
 //   void keyReleaseEvent(QKeyEvent *event);
   // void userMove();
private slots:
   void moveView();
private:
    Ui::MainWindow *ui;
    myScene *sc;
    QPointF cursorPoint;
    qreal m_qrScaledNum;
    enum{up,down,left,right}movedir;  //坦克移动方向
    enum{moving,stop}state; //移动状态


};
#endif // MAINWINDOW_H
