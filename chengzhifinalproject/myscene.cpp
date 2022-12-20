#include "myscene.h"
#include "qevent.h"
#include <QGraphicsView>
#include <QDebug>
#include <vector>
#include <QTimer>
#include<bits/stdc++.h>
#include <map>
#include "model.h"
#define TIMER_TIMEOUT   (500)
myScene::myScene(QObject *parent) : QGraphicsScene{parent}
{
    m= new model();
    index_enemy=0;index_healthBag=0;
   // Num_enemies=10;
   // Num_healthpacks=3;
   // ratio=0.5;
   // Num_P_enemies= ratio*Num_enemies;
 //QString map = ":/img/worldmap.png";
 //world = std::make_unique<World>();
 //world->createWorld(map,Num_enemies,Num_healthpacks,ratio);
 enemies = m->getEnemies();
 tiles = m->getTiles();
 healthpacks = m->getHealthpack();
// prot= world->getProtagonist();
 height = m->getHeight();
 width = m->getWidth();
 PEnemies = m->getPEnemies();
 soulEnemies = m->getsoulEnemies();
 flag=1; checkProtNeedDieFlag=10;
 attackFlag=1;
 soulFlag=1;
 skeletonFlag=1;
 showUseHealthBagFlag=1;
 showProtDieFlag=1;
 showEnemyAttackFlag=1;showPEnemyAttackFlag=1;
 checkIsPoisoItemFlag=0;

scalNum=m->getScalNum();
timer = new QTimer(this);
timersoul = new QTimer(this);
timerSkeleton = new QTimer(this);
timerUseHealth = new QTimer(this);
timerShowPoisodisapperEffect =new QTimer(this);
timerShowProtDie = new QTimer(this);
timerEnemyAttack = new QTimer(this);timerPEnemyAttack = new QTimer(this);
array=m->GetColorDepth();  qDebug()<<array[1][2];
drawWorld(scalNum);

setItemIndexMethod(QGraphicsScene::NoIndex);

}


void myScene::keyPressEvent(QKeyEvent *event)
{

if(event->key() == Qt::Key_J)
{
   attackTimeSignal();
   index_enemy=checkIsEnemy(m->getProtX(),m->getProtY());
   if(index_enemy != -1)
   {
       if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) {
       PEnemyDieSignal();
       }
       else
       { enemyDieSignal();}
   }
   qDebug()<<"jjjjjjjjjjjjjj";
  }
else if(event->key() == Qt::Key_K)
{
   index_healthBag=checkIsHealthBag(m->getProtX(),m->getProtY());
   if(index_healthBag != -1)
   {
       qDebug()<<index_healthBag<<"indexindexinedx";
       QPixmap pix;
       pix.load(":/myimg/soul/Soul_die5.png");
       healthpixmapItem[index_healthBag]->setPixmap(pix);
      useHealthSignal();
   }


  }
else if(event->key() == Qt::Key_L)
{

    protDieSignal();


  }

else if (event->key() == Qt::Key_Left && checkwall(m->getProtX()-1,m->getProtY())) { // 向左移动
  userMoveView(); protpixmapItem ->moveBy(-scalNum,0); m->setProtX(m->getProtX()-1);emit moveViewSignal();
  index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
  if (! enemies[index_enemy]->getDefeated()) {
      checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
  if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
}}

else if (event->key() == Qt::Key_Left && !checkwall(m->getProtX()-1,m->getProtY())){
  userMoveView(); protpixmapItem ->moveBy(scalNum,0); m->setProtX(m->getProtX()+1);
  index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
  if (! enemies[index_enemy]->getDefeated()) {
      checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
  if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
}}



else if (event->key() == Qt::Key_Right && checkwall(m->getProtX()+1,m->getProtY())) {// 向右移动
  userMoveView();protpixmapItem ->moveBy(scalNum, 0); m->setProtX(m->getProtX()+1);emit moveViewSignal();
  index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
  if (! enemies[index_enemy]->getDefeated()) {
      checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
  if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
}}
else if (event->key() == Qt::Key_Right  && !checkwall(m->getProtX()+1,m->getProtY())){
  userMoveView(); protpixmapItem ->moveBy(-scalNum,0); m->setProtX(m->getProtX()-1);
  index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
  if (! enemies[index_enemy]->getDefeated()) {
      checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
  if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) {showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
}}




else if (event->key() == Qt::Key_Up && checkwall(m->getProtX(),m->getProtY()-1)) {// 向上移动
   userMoveView(); protpixmapItem->moveBy(0, -scalNum);m->setProtY(m->getProtY()-1);emit moveViewSignal();
   index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
       if (! enemies[index_enemy]->getDefeated()) {
               checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
   if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
}}

else if (event->key() == Qt::Key_Up && !checkwall(m->getProtX(),m->getProtY()-1)) {// 向上移动
  userMoveView();  protpixmapItem->moveBy(0, +scalNum);m->setProtY(m->getProtY()+1);
  index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
   if (! enemies[index_enemy]->getDefeated()) {
      checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
  if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) {showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
}}


else if (event->key() == Qt::Key_Down && checkwall(m->getProtX(),m->getProtY()+1)){ // 向下移动
  userMoveView();  protpixmapItem->moveBy(0, scalNum);m->setProtY(m->getProtY()+1);emit moveViewSignal();
  index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
   if (! enemies[index_enemy]->getDefeated()) {
      checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
  if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
}}
else if (event->key() == Qt::Key_Down && !checkwall(m->getProtX(),m->getProtY()+1)){ // 向下移动
  userMoveView();  protpixmapItem->moveBy(0, -scalNum);m->setProtY(m->getProtY()-1);
  index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
  if (! enemies[index_enemy]->getDefeated()) {
      checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
  if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
}}
/*
    else if (event->key() == Qt::Key_Left && checkwall(m->getProtX()-1,m->getProtY())) { // 向左移动
      userMoveView(); protpixmapItem ->moveBy(-scalNum,0); m->setProtX(m->getProtX()-1);emit moveViewSignal();
      index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
      if (! enemies[index_enemy]->getDefeated()) {
          checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
      if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
    }}

    else if (event->key() == Qt::Key_Left && !checkwall(m->getProtX()-1,m->getProtY())){
      userMoveView(); protpixmapItem ->moveBy(scalNum,0); m->setProtX(m->getProtX()+1);
      index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
      if (! enemies[index_enemy]->getDefeated()) {
          checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
      if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
    }}



    else if (event->key() == Qt::Key_Right && checkwall(m->getProtX()+1,m->getProtY())) {// 向右移动
      userMoveView();protpixmapItem ->moveBy(scalNum, 0); m->setProtX(m->getProtX()+1);emit moveViewSignal();
      index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
      if (! enemies[index_enemy]->getDefeated()) {
          checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
      if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
    }}
    else if (event->key() == Qt::Key_Right  && !checkwall(m->getProtX()+1,m->getProtY())){
      userMoveView(); protpixmapItem ->moveBy(-scalNum,0); m->setProtX(m->getProtX()-1);
      index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
      if (! enemies[index_enemy]->getDefeated()) {
          checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
      if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) {showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
    }}




    else if (event->key() == Qt::Key_Up && checkwall(m->getProtX(),m->getProtY()-1)) {// 向上移动
       userMoveView(); protpixmapItem->moveBy(0, -scalNum);m->setProtY(m->getProtY()-1);emit moveViewSignal();
       index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
           if (! enemies[index_enemy]->getDefeated()) {
                   checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
       if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
    }}

    else if (event->key() == Qt::Key_Up && !checkwall(m->getProtX(),m->getProtY()-1)) {// 向上移动
      userMoveView();  protpixmapItem->moveBy(0, +scalNum);m->setProtY(m->getProtY()+1);
      index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
       if (! enemies[index_enemy]->getDefeated()) {
          checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
      if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) {showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
    }}


    else if (event->key() == Qt::Key_Down && checkwall(m->getProtX(),m->getProtY()+1)){ // 向下移动
      userMoveView();  protpixmapItem->moveBy(0, scalNum);m->setProtY(m->getProtY()+1);emit moveViewSignal();
      index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
       if (! enemies[index_enemy]->getDefeated()) {
          checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
      if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
   }}
    else if (event->key() == Qt::Key_Down && !checkwall(m->getProtX(),m->getProtY()+1)){ // 向下移动
      userMoveView();  protpixmapItem->moveBy(0, -scalNum);m->setProtY(m->getProtY()-1);
      index_enemy=checkIsEnemy( m->getProtX(),m->getProtY()); checkIsPoisoItem(); if (index_enemy != -1) {
      if (! enemies[index_enemy]->getDefeated()) {
          checkProtNeedDieFlag=checkProtNeedDieFlag-1;checkProtNeedDie();
      if (std::count(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy)) { showPEnemyAttackSignal();}else{showEnemyAttackSignal(); }}
    }}
    */
}

void myScene::drawWorld(int scalNum)
{    QPixmap pix;

    for ( auto &tile : tiles )
        {
            std::shared_ptr<Tile> newTile = std::move(tile);
            int tx = newTile->getXPos();
            int ty = newTile->getYPos();     
            float val= array[ty][tx];
            QGraphicsRectItem *rectItem = new QGraphicsRectItem();
            rectItem->setRect(newTile->getXPos()*scalNum,newTile->getYPos()*scalNum, scalNum, scalNum);
            rectItem-> setPen(QPen(Qt::NoPen));
            rectItem->setBrush(QBrush(QColor(val*255, 255, val*255)));
            this->addItem(rectItem);
        }


    int i = -1;

    for ( auto &enemy : enemies )
    {
        i++;
        QPixmap pix;

        int numberOfparameter =(QString::fromStdString(enemy->serialize())).split(',').length()-1;

        if(numberOfparameter==3)
        {
           pix.load(":/myimg/Soul11.png");
        }
        else
        {
           QVector<QString> stringArray(5);
           stringArray=(QString::fromStdString(enemy->serialize())).split(',');
           int x=stringArray[0].toInt(0);XPEnemy.push_back(x);
           int y=stringArray[1].toInt(0);YPEnemy.push_back(y);
           int s=stringArray[2].toInt(0);SPEnemy.push_back(s);
           int d=stringArray[3].toInt(0);DPEnemy.push_back(d);
           int p=stringArray[4].toInt(0);PPEnemy.push_back(p);
           pix.load(":/myimg/Skeleton21.png");
           PEnemyIndex.push_back(i);


        }

            pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
            enemypixmapItem[i] = new QGraphicsPixmapItem();
            enemypixmapItem[i]->setPixmap(pix);
            enemypixmapItem[i]->setPos(enemy->getXPos()*scalNum, enemy->getYPos()*scalNum);
            enemypixmapItem[i]->setZValue(1);      
            this->addItem(enemypixmapItem[i]);
    }

  // qDebug()<<m->getsoulEnemies().size()<<"yyyyyyyyyyyyyyy";
/*
    qDebug()<<"222222222222222222222222222222222";
    for (auto &enemy : soulEnemies)
    {  i++; // qDebug()<<QString::fromStdString(enemy->serialize());
        qDebug()<<"111111111111111111111111";
        QPixmap pix; pix.load(":/myimg/Soul11.png"); qDebug()<<"333333333333333333333333333";
         pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);qDebug()<<"44444444444444444444444444";
         enemypixmapItem[i] = new QGraphicsPixmapItem();qDebug()<<"555555555555555555555555555555";
         enemypixmapItem[i]->setPixmap(pix);qDebug()<<"6666666666666666666666666666666";
         enemypixmapItem[i]->setPos((enemy->getXPos())*scalNum, (enemy->getYPos())*scalNum);qDebug()<<"777777777777777777777777777777";
         enemypixmapItem[i]->setZValue(1);qDebug()<<"8888888888888888888888888888";
         this->addItem(enemypixmapItem[i]);qDebug()<<"9999999999999999999999999999999";
    }
    for (auto &enemy : PEnemies)
    {i++; // qDebug()<<QString::fromStdString(enemy->serialize());
        qDebug()<<"0000000000000000000000000000";
         QPixmap pix;pix.load(":/myimg/Skeleton21.png");
         pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
         enemypixmapItem[i] = new QGraphicsPixmapItem();
         enemypixmapItem[i]->setPixmap(pix);
         enemypixmapItem[i]->setPos(enemy->getXPos()*scalNum, enemy->getYPos()*scalNum);
         enemypixmapItem[i]->setZValue(1);
         this->addItem(enemypixmapItem[i]);
    }
*/






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

    pix.load(":/myimg/Run11.png");
    pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
    protpixmapItem = new QGraphicsPixmapItem();
    protpixmapItem->setPixmap(pix);
    protpixmapItem->setPos(m->getProtX()*scalNum, m->getProtY()*scalNum);
    protpixmapItem->setZValue(1);
    this->setFocusItem(protpixmapItem);
    this->addItem(protpixmapItem);

}

float myScene::checkwall(int x, int y)
{
    return m->checkwall(x,y);
}

int myScene::getProtX()
{
    return m->getProtX();
}
int myScene::getProtY()
{
    return m->getProtY();
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

void myScene::protAttackView()
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
   connect(timer, SIGNAL(timeout()), this, SLOT(protAttackView()));
   timer->start(TIMER_TIMEOUT);

}
void myScene::enemyDieSignal()
{  enemies[index_enemy]->setDefeated(1);
   connect(timersoul, SIGNAL(timeout()), this, SLOT(showEnemydie()));
   timersoul->start(TIMER_TIMEOUT);
}
void myScene::protDieSignal()
{
    connect(timerShowProtDie, SIGNAL(timeout()), this, SLOT(showProtDie()));
   timerShowProtDie ->start(TIMER_TIMEOUT);
}
void myScene::PEnemyDieSignal()
{  enemies[index_enemy]->setDefeated(1);
   connect(timerSkeleton, SIGNAL(timeout()), this, SLOT(showPEnemydie()));
   timerSkeleton->start(TIMER_TIMEOUT);
}
void myScene::useHealthSignal()
{
    connect(timerUseHealth, SIGNAL(timeout()), this, SLOT(showUseHealthBag()));
    timerUseHealth->start(TIMER_TIMEOUT);
}
void myScene::showEffectOfPoisoningSignal()
{
    connect(timerShowPoisodisapperEffect, SIGNAL(timeout()), this, SLOT(showPoisoningDisappear()));
    timerShowPoisodisapperEffect->start(TIMER_TIMEOUT);
}
void myScene::showEnemyAttackSignal()
{
    connect(timerEnemyAttack, SIGNAL(timeout()), this, SLOT(showEnemyAttack()));
    timerEnemyAttack->start(TIMER_TIMEOUT);
}

void myScene::showPEnemyAttackSignal()
{   checkIsPoisoItemFlag=1;
    QPixmap pix; pix.load(":/myimg/Stuck/GavielG_Charge.png");
     pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
     protpixmapItem->setPixmap(pix);
    connect(timerPEnemyAttack, SIGNAL(timeout()), this, SLOT(showPEnemyAttack()));
    timerPEnemyAttack->start(TIMER_TIMEOUT);
}

int myScene::checkIsEnemy(int x, int y)
{
    x=m->getProtX();
    y=m->getProtY();
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
    x=m->getProtX();
    y=m->getProtY();
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
void myScene::checkProtNeedDie()
{
    if (checkProtNeedDieFlag<=0)
    {
        protDieSignal();
    }
}
void myScene::checkIsPoisoItem()
{   /*
    int x,y;
    if(checkIsPoisoItemFlag)
    {
        for (int i=0;i<8;i++)
        {
            x=  poisorectItem[i]->x(); y=poisorectItem[i]->y();
            if(m->getProtX()==x && m->getProtY()==y)
            {QPixmap pix;
                pix.load(":/myimg/Stuck/GavielG_Charge.png");
             protpixmapItem->setPixmap(pix);
            }
        }
    }


*/
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
     case 1: pix.load(":/myimg/Accumulate/Angel Feature1.png");showUseHealthBagFlag++;break;
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

    auto it = find(PEnemyIndex.begin(), PEnemyIndex.end(), index_enemy);
    if (it != PEnemyIndex.end()) {
        indexInPenemyList = it - PEnemyIndex.begin();
    }
    int p=0;
    if(indexInPenemyList != -1)
    {

       p = PPEnemy[indexInPenemyList];
    }


      double temp=(double)p/100;
    for (int i=0;i<8;i++)
    {
       poisorectItem[i]=new QGraphicsRectItem;
        poisorectItem[i]->setPen(QPen(Qt::NoPen));
        poisorectItem[i]->setBrush(QBrush(QColor(255, 0, 255)));
        poisorectItem[i]->setOpacity(temp);
    }

    qDebug()<<PPEnemy[indexInPenemyList]<<"fffffffffffff";
    qDebug()<<indexInPenemyList<<"xxxxxxxxxxx";
    qDebug()<<PPEnemy;
    qDebug()<<p<<"pppppppppppp";
    qDebug()<<temp<<"temptemptemptemptemp";

     poisorectItem[0]->setRect((x+1)*scalNum,y*scalNum, scalNum, scalNum);
     poisorectItem[1]->setRect((x-1)*scalNum,y*scalNum, scalNum, scalNum);
     poisorectItem[2]->setRect(x*scalNum,(y+1)*scalNum, scalNum, scalNum);
     poisorectItem[3]->setRect(x*scalNum,(y-1)*scalNum, scalNum, scalNum);
     poisorectItem[4]->setRect((x+1)*scalNum,(y+1)*scalNum, scalNum, scalNum);
     poisorectItem[5]->setRect((x+1)*scalNum,(y-1)*scalNum, scalNum, scalNum);
     poisorectItem[6]->setRect((x-1)*scalNum,(y+1)*scalNum, scalNum, scalNum);
     poisorectItem[7]->setRect((x-1)*scalNum,(y-1)*scalNum, scalNum, scalNum);
      for (int i=0;i<8;i++)
      {
       this->addItem(poisorectItem[i]);
      }
     showEffectOfPoisoningSignal();
}


void myScene::showPoisoningDisappear()
{
    PPEnemy[indexInPenemyList]=PPEnemy[indexInPenemyList]-2;
    if(PPEnemy[indexInPenemyList]<0)
    {
      PPEnemy[indexInPenemyList]=0;timerShowPoisodisapperEffect->stop();
    }
     double temp=(double)PPEnemy[indexInPenemyList]/100;
    for (int i=0;i<8;i++)
    {
      poisorectItem[i]->setOpacity(temp);
    }
}
void myScene::showProtDie(){
     QPixmap pix;

     switch (showProtDieFlag)
     {
     case 1: pix.load(":/myimg/Die/GavielG_Die1.png");showProtDieFlag++;break;
     case 2: pix.load(":/myimg/Die/GavielG_Die2.png");showProtDieFlag++;break;
     case 3: pix.load(":/myimg/Die/GavielG_Die3.png");showProtDieFlag++;break;
     case 4: pix.load(":/myimg/Die/GavielG_Die4.png");showProtDieFlag++;break;
     case 5: pix.load(":/myimg/Die/GavielG_Die5.png");showProtDieFlag++;break;
     case 6: pix.load(":/myimg/gameover.png");showProtDieFlag=0;timerShowProtDie->stop();break;
     default :pix.load(":/myimg/Die/GavielG_Die1.png");showProtDieFlag++; timerShowProtDie->start(TIMER_TIMEOUT);break;
     }
     pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);

     protpixmapItem->setPixmap(pix);

}
void myScene::showEnemyAttack(){
     QPixmap pix;

     switch (showEnemyAttackFlag)
     {
     case 1: pix.load(":/myimg/soul/Soul_attack1.png");showEnemyAttackFlag++;break;
     case 2: pix.load(":/myimg/soul/Soul_attack2.png");showEnemyAttackFlag++;break;
     case 3: pix.load(":/myimg/soul/Soul_attack3.png");showEnemyAttackFlag++;break;
     case 4: pix.load(":/myimg/soul/Soul_attack4.png");showEnemyAttackFlag++;break;
     case 5: pix.load(":/myimg/soul/Soul_attack1.png");showEnemyAttackFlag++;break;
     case 6: pix.load(":/myimg/soul/Soul_attack2.png");showEnemyAttackFlag++;break;
     case 7: pix.load(":/myimg/soul/Soul_attack3.png");showEnemyAttackFlag++;break;
     case 8: pix.load(":/myimg/soul/Soul_attack4.png");showEnemyAttackFlag++;break;
     case 9: pix.load(":/myimg/soul/Soul_attack1.png");showEnemyAttackFlag++;break;
     case 10: pix.load(":/myimg/soul/Soul_attack2.png");showEnemyAttackFlag++;break;
     case 11: pix.load(":/myimg/soul/Soul_attack3.png");showEnemyAttackFlag++;break;
     case 12: pix.load(":/myimg/soul/Soul_attack4.png");showEnemyAttackFlag++;break;
     case 13: pix.load(":/myimg/Soul11.png");showEnemyAttackFlag=0;timerEnemyAttack->stop();break;
     default :pix.load(":/myimg/soul/Soul_attack1.png");showEnemyAttackFlag++; timerEnemyAttack->start(TIMER_TIMEOUT);break;
     }
     pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);

     enemypixmapItem[index_enemy]->setPixmap(pix);

}
void myScene::showPEnemyAttack(){
     QPixmap pix;

     switch (showPEnemyAttackFlag)
     {
     case 1: pix.load(":/myimg/skeleto/Skeleton_Attack1.png");showPEnemyAttackFlag++;break;
     case 2: pix.load(":/myimg/skeleto/Skeleton_Attack2.png");showPEnemyAttackFlag++;break;
     case 3: pix.load(":/myimg/skeleto/Skeleton_Attack3.png");showPEnemyAttackFlag++;break;
     case 4: pix.load(":/myimg/skeleto/Skeleton_Attack4.png");showPEnemyAttackFlag++;break;
     case 5: pix.load(":/myimg/skeleto/Skeleton_Attack1.png");showPEnemyAttackFlag++;break;
     case 6: pix.load(":/myimg/skeleto/Skeleton_Attack2.png");showPEnemyAttackFlag++;break;
     case 7: pix.load(":/myimg/skeleto/Skeleton_Attack3.png");showPEnemyAttackFlag++;break;
     case 8: pix.load(":/myimg/skeleto/Skeleton_Attack4.png");showPEnemyAttackFlag++;break;
     case 9: pix.load(":/myimg/skeleto/Skeleton_Attack1.png");showPEnemyAttackFlag++;break;
     case 10: pix.load(":/myimg/skeleto/Skeleton_Attack2.png");showPEnemyAttackFlag++;break;
     case 11: pix.load(":/myimg/skeleto/Skeleton_Attack3.png");showPEnemyAttackFlag++;break;
     case 12: pix.load(":/myimg/skeleto/Skeleton_Attack4.png");showPEnemyAttackFlag++;break;
     case 13: pix.load(":/myimg/Skeleton21.png");showPEnemyAttackFlag=0;timerPEnemyAttack->stop();break;
     default :pix.load(":/myimg/skeleto/Skeleton_Attack1.png");showPEnemyAttackFlag++; timerPEnemyAttack->start(TIMER_TIMEOUT);break;
     }
     pix=pix.scaled(scalNum, scalNum, Qt::KeepAspectRatio);
     enemypixmapItem[index_enemy]->setPixmap(pix);

}
void myScene::getmousePressEvent(QMouseEvent *event)
 {
    /*
     cursorPoint=event->pos();
     int x=cursorPoint.x();
     int y=cursorPoint.y();
     int xp=m->getProtY();
     int yp=m->getProtX();
*/
 }
