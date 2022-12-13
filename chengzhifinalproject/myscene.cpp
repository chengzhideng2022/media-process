#include "myscene.h"
#include "qevent.h"
#include <QGraphicsView>
#include <QDebug>
#include <vector>
#include <QTimer>
#define TIMER_TIMEOUT   (100)
myScene::myScene(QObject *parent) : QGraphicsScene{parent}
{
 //this->item= new myItem;
 //item->setPos(1,1);
 //item->setOffset(10000,100000);
 //myItem *item2 =new myItem;
 //this->addItem(this->item);
 //item2->setPos(2000,20000);
 //this->addItem(item2);
    Num_enemies=20;
    Num_healthpacks=20;
    ratio=0.25;
    Num_P_enemies= ratio*Num_enemies;
 QString map = ":/img/worldmap.png";
 world = std::make_unique<World>();
 world->createWorld(map,20,20,0.25);
 enemies = world->getEnemies();
 tiles = world->getTiles();
 healthpacks = world->getHealthPacks();
 prot= world->getProtagonist();
 height = world->getRows() ;
 width = world->getCols();
 flag=1;
 attackFlag=1;
 a=0;
// this->setFocusItem(protpixmapItem);
//QPoint cursorPoint;

scalNum=100;


drawWorld(scalNum);

}

void myScene::keyPressEvent(QKeyEvent *event)
{
    //float difficulty= checkwall(prot->getXPos()-1,prot->getYPos());
if(event->key() == Qt::Key_J)
{
   attackTimeSignal();
   qDebug()<<"jjjjjjjjjjjjjj";
  }


    else if (event->key() == Qt::Key_Left && checkwall(prot->getXPos()-1,prot->getYPos())) { // 向左移动
      userMoveView(); protpixmapItem ->moveBy(-scalNum,0); prot->setXPos(prot->getXPos()-1);emit moveViewSignal();}
    else if (event->key() == Qt::Key_Left && !checkwall(prot->getXPos()-1,prot->getYPos())){
      userMoveView(); protpixmapItem ->moveBy(scalNum,0); prot->setXPos(prot->getXPos()+1);
    }



    else if (event->key() == Qt::Key_Right && checkwall(prot->getXPos()+1,prot->getYPos())) {// 向右移动
      userMoveView();protpixmapItem ->moveBy(scalNum, 0); prot->setXPos(prot->getXPos()+1);emit moveViewSignal();
    }
    else if (event->key() == Qt::Key_Right  && !checkwall(prot->getXPos()+1,prot->getYPos())){
      userMoveView(); protpixmapItem ->moveBy(-scalNum,0); prot->setXPos(prot->getXPos()-1);
    }




    else if (event->key() == Qt::Key_Up && checkwall(prot->getXPos(),prot->getYPos()-1)) {// 向上移动
       userMoveView(); protpixmapItem->moveBy(0, -scalNum);prot->setYPos(prot->getYPos()-1);emit moveViewSignal();}
    else if (event->key() == Qt::Key_Up && !checkwall(prot->getXPos(),prot->getYPos()-1)) {// 向上移动
      userMoveView();  protpixmapItem->moveBy(0, +scalNum);prot->setYPos(prot->getYPos()+1);
    }


    else if (event->key() == Qt::Key_Down && checkwall(prot->getXPos(),prot->getYPos()+1)){ // 向下移动
      userMoveView();  protpixmapItem->moveBy(0, scalNum);prot->setYPos(prot->getYPos()+1);emit moveViewSignal();}
    else if (event->key() == Qt::Key_Down && !checkwall(prot->getXPos(),prot->getYPos()+1)){ // 向下移动
      userMoveView();  protpixmapItem->moveBy(0, -scalNum);prot->setYPos(prot->getYPos()-1);
    }
}

void myScene::drawWorld(int scalNum)
{

    int rows = height;
    int cols = width;





    // 动态分配一个 rows * cols 大小的数组
    array = new float*[rows];
    for (int i = 0; i < rows; i++) {
    array[i] = new float[cols];}

    for ( auto &tile : tiles )
        {
            std::unique_ptr<Tile> newTile = std::move(tile);
            float val = newTile->getValue();
            int tx = newTile->getXPos();
            int ty = newTile->getYPos();
            if(val == std::numeric_limits<float>::infinity()){
                newTile->setValue(0);
            }

             val = newTile->getValue();
             array[ty][tx]=val;
            QGraphicsRectItem *rectItem = new QGraphicsRectItem();
            rectItem->setRect(newTile->getXPos()*scalNum,newTile->getYPos()*scalNum, scalNum, scalNum);
            rectItem-> setPen(QPen(Qt::NoPen));;
            rectItem->setBrush(QBrush(QColor(val*255, 255, val*255)));
            this->addItem(rectItem);
        }

       int i = 0;
    for ( auto &enemy : enemies )
    {

        QPixmap pix;
        pix.load(":/myimg/Soul11.png");
        pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);

        QPixmap ppix;
        ppix.load(":/myimg/Skeleton21.png");
        ppix=ppix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);


        QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();

        if(i< Num_enemies - Num_P_enemies)
        {
            pixmapItem->setPixmap(pix);
            pixmapItem->setPos(enemy->getXPos()*scalNum, enemy->getYPos()*scalNum);
            pixmapItem->setZValue(1);
            this->addItem(pixmapItem);
            i++;
        }
        else
        {
           // PEnemy p1;
           // std::shared_ptr<PEnemy> newEnemy = std::move(enemy);
           // PEnemies.push_back(enemy);
            pixmapItem->setPixmap(ppix);
            pixmapItem->setPos(enemy->getXPos()*scalNum, enemy->getYPos()*scalNum);
            pixmapItem->setZValue(1);
            this->addItem(pixmapItem);
            i++;
        }

    }

    for ( auto &healthpack : healthpacks)
    {
        QPixmap pix;
        pix.load(":/img/pill1.png");
        pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
        QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();
        pixmapItem->setPixmap(pix);
         pixmapItem->setPos(healthpack->getXPos()*scalNum, healthpack->getYPos()*scalNum);
         pixmapItem->setZValue(1);
         this->addItem(pixmapItem);
    }
    QPixmap pix;
    pix.load(":/myimg/Run11.png");
    pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
    protpixmapItem = new QGraphicsPixmapItem();
    protpixmapItem->setPixmap(pix);
    protpixmapItem->setPos(prot->getXPos()*scalNum, prot->getYPos()*scalNum);
    protpixmapItem->setZValue(1);
    this->setFocusItem(protpixmapItem);
    this->addItem(protpixmapItem);


}

float myScene::checkwall(int protx, int proty)
{
     protx=prot->getXPos();
     proty=prot->getYPos();
float difficulty = array[proty][protx];

return difficulty;


}

int myScene::getProtX()
{
    return prot->getXPos();
}
int myScene::getProtY()
{
    return prot->getYPos();
}
int myScene::getscalNum()
{
    return scalNum;
}

void myScene::userMoveView()

{
    QPixmap pix;
    if (flag==1)
    { pix.load(":/myimg/Run11.png"); flag++; }
    else if (flag==2)
    {pix.load(":/myimg/Run21.png"); flag++;}
    else if (flag==3)
    {pix.load(":/myimg/Run31.png"); flag++;}
    else if (flag==4)
    {pix.load(":/myimg/Run41.png"); flag=1;}

     pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
     protpixmapItem->setPixmap(pix);
   }

void myScene::attack()
{ QPixmap pix;
    switch (attackFlag)
    {
    case 1: pix.load(":/myimg/combo/GavielG_Combo1.png");attackFlag++;break;
    case 2: pix.load(":/myimg/combo/GavielG_Combo2.png");attackFlag++;break;
    case 3: pix.load(":/myimg/combo/GavielG_Combo3.png");attackFlag++;break;
    case 4: pix.load(":/myimg/combo/GavielG_Combo4.png");attackFlag++;break;
    case 5: pix.load(":/myimg/combo/GavielG_Combo5.png");attackFlag++;break;
    case 6: pix.load(":/myimg/combo/GavielG_Combo6.png");attackFlag++;break;
    case 7: pix.load(":/myimg/combo/GavielG_Combo7.png");attackFlag++;break;
    case 8: pix.load(":/myimg/combo/GavielG_Combo8.png");attackFlag++;break;
    case 9: pix.load(":/myimg/combo/GavielG_Combo9.png");attackFlag=0;break;
        default :pix.load(":/myimg/combo/GavielG_Combo1.png");break;
    }
    pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
    protpixmapItem->setPixmap(pix);
}
void myScene::attackTimeSignal()
{QTimer *timer = new QTimer(this);
    if (a==0)
    {
        qDebug()<<"ttttttttttttt";
            connect(timer, SIGNAL(timeout()), this, SLOT(attack()));
        timer->start(TIMER_TIMEOUT);qDebug()<<"ssssssssssss";a=1;
    }
    else
        {
             timer ->stop();
        }


    if(attackFlag==0) {
        timer ->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(attack()));
        qDebug()<<"ppppppppppp";
    }
}

/*
 * void myScene::drawWorld()
{
    bg = QImage(":/img/maze3.png");
    for ( auto &tile : tiles )
    {
        int xpos = tile->getXPos();
        int ypos = tile->getYPos();
        float val = tile->getValue();
        if(val==std::numeric_limits<float>::infinity()){
            bg.setPixelColor(xpos, ypos, QColor(0,0,0));
        }else{
            bg.setPixelColor(xpos, ypos, QColor(255,255,255)
                                   // (int)(floor(255*val/2)+125),
                                    //(int)(floor(255*(1-val))),
                                 //  (int)(floor(255*(1-val)/2)))
                                );
        }
    }
    pm.convertFromImage(bg);
    pixmapman.setPixmap(pm);
   this->addItem(&pixmapman);
}
*/
