#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWheelEvent>
#include <QKeyEvent>
#include <QGraphicsView>
#include <qdebug.h>
#include <QToolBar>


MainWindow::MainWindow(QWidget *parent,QString map) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_qrScaledNum=1;

    this->ui->gameview->setMouseTracking(true);
    //this->ui->gameview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏水平条
    //this->ui->gameview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖条
    this->ui->gameview->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->ui->gameview->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

    this->sc = new myScene(nullptr,map);
    this->ui->gameview->setScene(sc);
    this->ui->gameview->centerOn(this->sc->getProtX(), this->sc->getProtY());
    this->ui->gameview->grabKeyboard();
    //showFullScreen();
     showMaximized();
     connect(this->sc,SIGNAL(moveViewSignal()),this,SLOT(moveView()));
     connect(this->sc,SIGNAL(moveViewSignal()),this,SLOT(showHP()));

     showHP();
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::wheelEvent(QWheelEvent *event)
{
      //QPointF scenePos = this->ui->gameview->mapToScene(QPoint(cursorPoint.x(), cursorPoint.y()));

        if (event->modifiers() == Qt::CTRL)
        {
            int wheelDeltaValue = event->angleDelta().y();


                     if((wheelDeltaValue > 0)&&(m_qrScaledNum >= 10))//最大放大到原始图像的50倍
                     {
                        return;
                     }
                     else if((wheelDeltaValue < 0)&&(m_qrScaledNum <= 0.01))//图像缩小到自适应大小之后就不继续缩小
                     {
                         return;//重置图片大小和位置，使之自适应控件窗口大小
                     }
                     else
                     {
                         // 向上滚动，放大
                         if (wheelDeltaValue > 0.5)
                         {
                             m_qrScaledNum=m_qrScaledNum*1.2;
                            this->ui->gameview->scale(1.2, 1.2);

                         }

                         // 向下滚动，缩小
                         else  if (wheelDeltaValue < -0.5)
                         {
                              m_qrScaledNum=m_qrScaledNum/1.2;
                              this->ui->gameview->scale(1.0 / 1.2, 1.0 / 1.2);

                         }
                         update();
                     }


        }
     // 获取当前鼠标相对于view的位置;
   //  QPointF cursorPoint = event->globalPosition();
     // 获取当前鼠标相对于scene的位置;


     // 获取view的宽高;
     //qreal viewWidth = this->ui->gameview->width();
     //qreal viewHeight = this->ui->gameview->height();

     // 获取当前鼠标位置相当于view大小的横纵比例;
    // qreal hScale = cursorPoint.x() / viewWidth;
    // qreal vScale = cursorPoint.y() / viewHeight;

     // 当前放缩倍数;
    // qreal scaleFactor = this->ui->gameview->matrix().m11();
    // 获取鼠标滚轮的距离

  //  this->ui->gameview->horizontalScrollBar()->setValue(2);//int(cursorPoint.x() - viewWidth * hScale)
    //this->ui->gameview->verticalScrollBar()->setverticalScrollBar(int(cursorPoint.y() - viewHeight * vScale));
}

void MainWindow::moveView() //Vision follow the protagonist
{
    int n = this->sc->getscalNum();

     int x = this->sc->getProtX();

     int y = this->sc->getProtY();
     qDebug()<<x<<"   "<<y;
       // this->ui->gameview->centerOn(this->sc->getProtX(), this->sc->getProtY());
     this->ui->gameview->centerOn(x*n, y*n);

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"cursorcursorcursorcursorcursor";
     cursorPoint=event->pos();
    QKeyEvent *keyEventLeft = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
    QKeyEvent *keyEventRight = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    QKeyEvent *keyEventUp = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    QKeyEvent *keyEventDown = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);

       int ScalNum =this->sc->getmodel()->getScalNum();
     //kevent->key() = Qt::Key_Left;
     int x=cursorPoint.x();
     int y=cursorPoint.y();
     x=x/ScalNum;
     y=y/ScalNum;
     qDebug()<<x<<"xxxxxxxx";qDebug()<<y<<"yyyyyyy";
     int xp=this->sc->getProtX();
     int yp=this->sc->getProtY();
     if(x>xp)
     {
         for (int i=0;i<x-xp;i++)
         {
           this->sc->keyPressEvent(keyEventRight);
         }
         if(y>yp)
         {
             for (int i=0;i<y-yp;i++)
             {
            this->sc->keyPressEvent(keyEventDown);
             }
         }
         else
         {
             for (int i=0;i<yp-y;i++)
             {
            this->sc->keyPressEvent(keyEventUp);
             }
         }

     }
      else
     {
         for (int i=0;i<xp-x;i++)
         {
           this->sc->keyPressEvent(keyEventLeft);
         }
         if(y>yp)
         {
             for (int i=0;i<y-yp;i++)
             {
            this->sc->keyPressEvent(keyEventDown);
             }
         }
         else
         {
             for (int i=0;i<yp-y;i++)
             {
            this->sc->keyPressEvent(keyEventUp);
             }
         }

     }

      if (event->button() == Qt::LeftButton) {
qDebug()<<"cursorcursorcursorcursorcursor";}

 qDebug()<<"mousemousemouse";
}

void MainWindow::showHP()
{
     int hp =this->sc->getmodel()->getProtNeedDieFlag();
     QPalette palette = this->ui->HPBar->palette();
     palette.setColor(QPalette::Highlight, Qt::red);
     this->ui->HPBar->setFormat("%p%");
     this->ui->HPBar->setPalette(palette);
     this->ui->HPBar->setValue(hp);

}
void MainWindow::showEP()
{

}
