#include "myscene.h"
#include "qevent.h"
#include <QGraphicsView>
#include <QDebug>
#include <vector>
#include <QTimer>
#include<bits/stdc++.h>
#include <map>
#define TIMER_TIMEOUT   (500)
myScene::myScene(QObject *parent) : QGraphicsScene{parent}
{
 //this->item= new myItem;
 //item->setPos(1,1);
 //item->setOffset(10000,100000);
 //myItem *item2 =new myItem;
 //this->addItem(this->item);
 //item2->setPos(2000,20000);
 //this->addItem(item2);
    index_enemy=0;index_healthBag=0;
    Num_enemies=10;
    Num_healthpacks=3;
    ratio=0.5;
    Num_P_enemies= ratio*Num_enemies;
 QString map = ":/img/worldmap.png";
 world = std::make_unique<World>();
 world->createWorld(map,Num_enemies,Num_healthpacks,ratio);
 enemies = world->getEnemies();
 tiles = world->getTiles();
 healthpacks = world->getHealthPacks();
 prot= world->getProtagonist();
 height = world->getRows() ;
 width = world->getCols();
 flag=1;
 attackFlag=1;
 soulFlag=1;
 skeletonFlag=1;
 showUseHealthBagFlag=1;
 a=0;
// this->setFocusItem(protpixmapItem);
//QPoint cursorPoint;

scalNum=100;
timer = new QTimer(this);
timersoul = new QTimer(this);
timerSkeleton = new QTimer(this);
timerUseHealth = new QTimer(this);
drawWorld(scalNum);
setItemIndexMethod(QGraphicsScene::NoIndex);
}

void myScene::keyPressEvent(QKeyEvent *event)
{

if(event->key() == Qt::Key_J)
{
   attackTimeSignal();
   index_enemy=checkIsEnemy(prot->getXPos(),prot->getYPos());
   if(index_enemy != -1)
   {
       if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) {
       PEnemyDieSignal();//showEffectOfPoisoning();qDebug()<<"gggggggggggg";
       }
       else
       { enemyDieSignal();}
   }

   qDebug()<<"jjjjjjjjjjjjjj";
  }
if(event->key() == Qt::Key_K)
{
   index_healthBag=checkIsHealthBag(prot->getXPos(),prot->getYPos());
   if(index_healthBag != -1)
   {
       qDebug()<<index_healthBag<<"indexindexinedx";
       QPixmap pix;
       pix.load(":/myimg/soul/Soul_die5.png");
      // pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
      // this->removeItem(healthpixmapItem[index_healthBag]);
       healthpixmapItem[index_healthBag]->setPixmap(pix);
      useHealthSignal();
   }

   qDebug()<<"kkkkkkkkkk";
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

       int i = -1;
    for ( auto &enemy : enemies )
    {
        i++;
        QPixmap pix;
        qDebug()<<QString::fromStdString(enemy->serialize());
        qDebug()<<(QString::fromStdString(enemy->serialize())).split(',').length()-1;
       // qDebug()<<stringArray[0]<<"yyyyyyyyy"<<stringArray[1]<<"yyyyyyyyy"<<stringArray[2]<<"yyyyyyyyy"<<stringArray[3]<<"yyyyyyyyy";
        int numberOfparameter =(QString::fromStdString(enemy->serialize())).split(',').length()-1;

        if(numberOfparameter==3)
        {
           pix.load(":/myimg/Soul11.png");
        }
        else
        {
           QVector<QString> stringArray(5);
           stringArray=(QString::fromStdString(enemy->serialize())).split(',');
           int x=stringArray[0].toInt(0);
           int y=stringArray[1].toInt(0);
           int s=stringArray[2].toInt(0);
           int d=stringArray[3].toInt(0);
           int p=stringArray[4].toInt(0);
           pix.load(":/myimg/Skeleton21.png");
           PEnemyIndex.push_back(i);
          /*
           PEnemy *PEnemy_temp = new PEnemy(x,y,s);
           PEnemy_temp->setDefeated(d);
           PEnemy_temp->setPoisonLevel(p);
           PEnemies->push_back(*PEnemy_temp);
           */
        }

            pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
            enemypixmapItem[i] = new QGraphicsPixmapItem();
            enemypixmapItem[i]->setPixmap(pix);
            enemypixmapItem[i]->setPos(enemy->getXPos()*scalNum, enemy->getYPos()*scalNum);
            enemypixmapItem[i]->setZValue(1);
            this->addItem(enemypixmapItem[i]);
    }
      int j=0;
    for ( auto &healthpack : healthpacks)
    {

        QPixmap pix;
        pix.load(":/img/pill1.png");
        pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
         healthpixmapItem[j] = new QGraphicsPixmapItem();
         healthpixmapItem[j]->setPixmap(pix);
         healthpixmapItem[j]->setPos(healthpack->getXPos()*scalNum, healthpack->getYPos()*scalNum);
         healthpixmapItem[j]->setZValue(1);
         this->addItem(healthpixmapItem[j]);
         j++;
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
    case 9: pix.load(":/myimg/combo/GavielG_Combo9.png");attackFlag=0;timer ->stop();break;
    default :pix.load(":/myimg/combo/GavielG_Combo9.png");attackFlag++; timer->start(TIMER_TIMEOUT);break;
    }
    pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
    protpixmapItem->setPixmap(pix);
}
void myScene::attackTimeSignal()
{
   connect(timer, SIGNAL(timeout()), this, SLOT(attack()));
   timer->start(TIMER_TIMEOUT);

}
void myScene::enemyDieSignal()
{
   connect(timersoul, SIGNAL(timeout()), this, SLOT(showEnemydie()));
   timersoul->start(TIMER_TIMEOUT);
}
void myScene::PEnemyDieSignal()
{
   connect(timerSkeleton, SIGNAL(timeout()), this, SLOT(showPEnemydie()));
   timerSkeleton->start(TIMER_TIMEOUT);
}
void myScene::useHealthSignal()
{
    connect(timerUseHealth, SIGNAL(timeout()), this, SLOT(showUseHealthBag()));
    timerUseHealth->start(TIMER_TIMEOUT);
}
int myScene::checkIsEnemy(int x, int y)
{
    x=prot->getXPos();
    y=prot->getYPos();
    int i=0;
     for ( auto &enemy : enemies )
     {
         if((x==enemy->getXPos()-1)&&(y==enemy->getYPos())){
            return i;
         }
       i++;
     }
     int j=0;
     for ( auto &enemy : enemies )
     {
         if((x==enemy->getXPos())&&(y==enemy->getYPos())){
            return j;
         }
       j++;
     }

     return -1;
}

int myScene::checkIsHealthBag(int x, int y)
{
    x=prot->getXPos();
    y=prot->getYPos();
    int i=0;
     for ( auto &healthpack : healthpacks)
     {
         if((x==healthpack->getXPos()-1)&&(y==healthpack->getYPos())){
            return i;
         }
      i++;
     }
     int j= 0;
     for ( auto &healthpack : healthpacks )
     {
         if((x==healthpack->getXPos())&&(y==healthpack->getYPos())){
            return j;
         }
   j++;
     }

     return -1;

}

void myScene::showEnemydie(){
     QPixmap pix;

     switch (soulFlag)
     {
     case 1: pix.load(":/myimg/soul/Soul_fly.png");soulFlag++;break;
     case 2: pix.load(":/myimg/soul/Soul_die1.png");soulFlag++;break;
     case 3: pix.load(":/myimg/soul/Soul_die2.png");soulFlag++;break;
     case 4: pix.load(":/myimg/soul/Soul_die3.png");soulFlag++;break;
     case 5: pix.load(":/myimg/soul/Soul_die4.png");soulFlag++;break;
     case 6: pix.load(":/myimg/soul/die5.png");soulFlag=0;timersoul->stop();break;
     default :pix.load(":/myimg/soul/Soul_fly.png");soulFlag++; timersoul->start(TIMER_TIMEOUT);break;
     }
     pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);

     enemypixmapItem[index_enemy]->setPixmap(pix);

}
void myScene::showPEnemydie(){
     QPixmap pix;
      qDebug()<<index_enemy<<"indexindexinedx";
     switch (skeletonFlag)
     {
     case 1: pix.load(":/myimg/skeleto/Skeleton_fly.png");skeletonFlag++;break;
     case 2: pix.load(":/myimg/skeleto/Skeleton_die1.png");skeletonFlag++;break;
     case 3: pix.load(":/myimg/skeleto/Skeleton_die2.png");skeletonFlag++;break;
     case 4: pix.load(":/myimg/skeleto/Skeleton_die3.png");skeletonFlag++;break;
     case 5: pix.load(":/myimg/skeleto/Skeleton_die4.png"); skeletonFlag=0;timerSkeleton->stop();showEffectOfPoisoning();break;
     default :pix.load(":/myimg/skeleto/Skeleton_fly.png");skeletonFlag++; timerSkeleton->start(TIMER_TIMEOUT);break;
     }
     pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
     enemypixmapItem[index_enemy]->setPixmap(pix);
}
void myScene::showUseHealthBag(){
     QPixmap pix;

     switch (showUseHealthBagFlag)
     {
     case 1: pix.load(":/myimg/Accumulate/Angel Feature1.pngg");showUseHealthBagFlag++;break;
     case 2: pix.load(":/myimg/Accumulate/Angel Feature2.png");showUseHealthBagFlag++;break;
     case 3: pix.load(":/myimg/Accumulate/GavielG_Accu1.png");showUseHealthBagFlag++;break;
     case 4: pix.load(":/myimg/Accumulate/GavielG_Accu2.png");showUseHealthBagFlag++;break;
     case 5: pix.load(":/myimg/Accumulate/GavielG_Accu3.png");showUseHealthBagFlag++;break;
     case 6: pix.load(":/myimg/Accumulate/GavielG_Accu4.png");showUseHealthBagFlag++;break;
     case 7: pix.load(":/myimg/Accumulate/GavielG_Accu5.png");showUseHealthBagFlag++;break;
     case 8: pix.load(":/myimg/Accumulate/GavielG_Accu6.png");showUseHealthBagFlag++;break;
     case 9: pix.load(":/myimg/Buff/GavielG_Buff1.png");showUseHealthBagFlag=0;timerUseHealth->stop();break;
     default :pix.load(":/myimg/Buff/GavielG_Buff1.png");showUseHealthBagFlag++; timerUseHealth->start(TIMER_TIMEOUT);break;
     }
     pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);

     protpixmapItem->setPixmap(pix);

}
void myScene::showEffectOfPoisoning()
{
    int x = enemies[index_enemy]->getXPos();
    int y = enemies[index_enemy]->getYPos();
   // PEnemy p = move(enemies[index_enemy]);
    QGraphicsRectItem *rectItem[8];
    for (int i=0;i<8;i++)
    {
        rectItem[i] = new QGraphicsRectItem();
        rectItem[i]->setPen(QPen(Qt::NoPen));
        rectItem[i]->setBrush(QBrush(QColor(255, 0, 0)));
        rectItem[i]->setOpacity(0.5);
    }
     rectItem[0]->setRect((x+1)*scalNum,y*scalNum, scalNum, scalNum);
     rectItem[1]->setRect((x-1)*scalNum,y*scalNum, scalNum, scalNum);
     rectItem[2]->setRect(x*scalNum,(y+1)*scalNum, scalNum, scalNum);
     rectItem[3]->setRect(x*scalNum,(y-1)*scalNum, scalNum, scalNum);
     rectItem[4]->setRect((x+1)*scalNum,(y+1)*scalNum, scalNum, scalNum);
     rectItem[5]->setRect((x+1)*scalNum,(y-1)*scalNum, scalNum, scalNum);
     rectItem[6]->setRect((x-1)*scalNum,(y+1)*scalNum, scalNum, scalNum);
     rectItem[7]->setRect((x-1)*scalNum,(y-1)*scalNum, scalNum, scalNum);
      for (int i=0;i<8;i++)
      {
       this->addItem(rectItem[i]);
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
