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

void MainWindow::moveView()
{
    int n = this->sc->getscalNum();

     int x = this->sc->getProtX();

     qDebug()<<x;
     int y = this->sc->getProtY();
     qDebug()<<y;
       // this->ui->gameview->centerOn(this->sc->getProtX(), this->sc->getProtY());
     this->ui->gameview->centerOn(x*n, y*n);

}

