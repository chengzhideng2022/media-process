#include "model.h"
#include "qtimer.h"
#include <QTimer>
#include<bits/stdc++.h>
#include <map>
#include <QDebug>
#include <vector>
#include <QString>
#include <QKeyEvent>
   model::model()
{
    index_enemy=0;index_healthBag=0;
    Num_enemies=10;
    Num_healthpacks=3;
    ratio=0.5;
    Num_P_enemies= ratio*Num_enemies;
   scalNum=100;
 QString map = ":/img/worldmap.png";

  world=  std::make_shared<World>();
  world->createWorld(map,Num_enemies,Num_healthpacks,ratio);

   int i = -1;
  for ( auto &enemy : world->getEnemies() )
  {  qDebug()<<QString::fromStdString(enemy->serialize());
      int numberOfparameter =(QString::fromStdString(enemy->serialize())).split(',').length()-1;

      std::shared_ptr<Enemy> newEnemy = std::move(enemy);
      std::shared_ptr<Enemy> pnewEnemy = std::move(enemy);
      std::shared_ptr<Enemy> snewEnemy = std::move(enemy);
      enemies.push_back( newEnemy );
      i++;
          if(numberOfparameter==3)
         {
              soulEnemies.push_back(snewEnemy);
         }
         else

         {
           //  QVector<QString> stringArray(5);
            //  stringArray=(QString::fromStdString(snewEnemy->serialize())).split(',');
            //  int p=stringArray[4].toInt(0);PPEnemy.push_back(p);
              PEnemyIndex.push_back(i);
              PEnemies.push_back(pnewEnemy);
          }
  }


  for ( auto &tile : world->getTiles())
  {
      std::shared_ptr<Tile> newTile = std::move(tile);
      tiles.push_back( newTile );
  }


  for ( auto &healthpack : world->getHealthPacks())
  {
      std::shared_ptr<Tile> newTile = std::move(healthpack);
      healthpacks.push_back( newTile );
  }

  prot= world->getProtagonist();
  height = world->getRows() ;
  width = world->getCols();
  flag=1; checkProtNeedDieFlag=10;
  attackFlag=1;
  soulFlag=1;
  skeletonFlag=1;
  showUseHealthBagFlag=1;
  showProtDieFlag=1;
  showEnemyAttackFlag=1;showPEnemyAttackFlag=1;
  checkIsPoisoItemFlag=0;

  timer = new QTimer(this);
  timersoul = new QTimer(this);
  timerSkeleton = new QTimer(this);
  timerUseHealth = new QTimer(this);
  timerShowPoisodisapperEffect =new QTimer(this);
  timerShowProtDie = new QTimer(this);
  timerEnemyAttack = new QTimer(this);timerPEnemyAttack = new QTimer(this);

 }
std::vector<std::shared_ptr<Tile>> model::getHealthpack()
{
    return healthpacks;
}

std::vector<std::shared_ptr<Tile>> model::getTiles()
{
    return tiles;
}

std::vector<std::shared_ptr<Enemy>> model::getEnemies()
{
    return enemies;
}
int model::getHeight()
{
   return height;
}
int model::getWidth()
{
   return width;
}
int model::getScalNum()
{
    return scalNum;
}
int model::getProtX()
{
    return prot->getXPos();
}
int model::getProtY()
{
    return prot->getYPos();
}
void model::setProtX(int x)
{
    prot->setXPos(x);
}
void model::setProtY(int y)
{
    prot->setYPos(y);
}
std::vector<std::shared_ptr<Enemy>> model::getPEnemies()
{
    return PEnemies;
}
std::vector<std::shared_ptr<Enemy>> model::getsoulEnemies()
{
    return soulEnemies;
}
std::vector<int> model::getPPenemy()
{
     return PPEnemy;
}
std::vector<int> model::getPEnemyIndex()
{
    return PEnemyIndex;
}
float model::checkwall(int x, int y)
{

float difficulty = array[y][x];

return difficulty;

}
float ** model::GetColorDepth()
{
    int rows = height;
    int cols = width;
    array = new float*[rows];
    for (int i = 0; i < rows; i++) {
    array[i] = new float[cols];}

    for ( auto &tile : tiles )
        {
            std::shared_ptr<Tile> newTile = std::move(tile);
            float val = newTile->getValue();
            int tx = newTile->getXPos();
            int ty = newTile->getYPos();
            if(val == std::numeric_limits<float>::infinity()){
                newTile->setValue(0);
            }

             val = newTile->getValue();
             array[ty][tx]=val;
        }
    return array;
}

int model::checkIsEnemy(int x, int y)
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

int model::checkIsHealthBag(int x, int y)
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

bool model::checkProtNeedDie()
{
    if (checkProtNeedDieFlag<=0)
    {
        return true;qDebug()<<"diediediediedie";
    }
    else {return false;}
}
void model::protHurt()
{
    checkProtNeedDieFlag=checkProtNeedDieFlag-1;
    qDebug()<<checkProtNeedDieFlag<<"checkProtNeedDieFlag";
}
