#include "model.h"
#include "qtimer.h"
#include <QTimer>
#include<bits/stdc++.h>
#include <map>
#include <QDebug>
#include <vector>
#include <QString>
   model::model()
{
    index_enemy=0;index_healthBag=0;
    Num_enemies=10;
    Num_healthpacks=3;
    ratio=0.5;
    Num_P_enemies= ratio*Num_enemies;

 QString map = ":/img/worldmap.png";

  world=  std::make_shared<World>();
  world->createWorld(map,Num_enemies,Num_healthpacks,ratio);

   int i = -1;
  for ( auto &enemy : world->getEnemies() )
  {  qDebug()<<QString::fromStdString(enemy->serialize());
      int numberOfparameter =(QString::fromStdString(enemy->serialize())).split(',').length()-1;
      // qDebug()<<"222222222222222222222222222222222";
      std::shared_ptr<Enemy> newEnemy = std::move(enemy);
      std::shared_ptr<Enemy> pnewEnemy = std::move(enemy);
      std::shared_ptr<Enemy> snewEnemy = std::move(enemy);
      enemies.push_back( newEnemy );
      i++;//qDebug()<<"11111111111111111111111111";
          if(numberOfparameter==3)
         { // qDebug()<<"******************************";
              //qDebug()<<QString::fromStdString(snewEnemy->serialize());qDebug()<<"3333333333333333333333333";
              soulEnemies.push_back(snewEnemy);// qDebug()<<"44444444444444444444444";
         }
         else

         { // qDebug()<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
             // qDebug()<<QString::fromStdString(pnewEnemy ->serialize()); qDebug()<<"555555555555555555555555555";

            //  QVector<QString> stringArray(5); //qDebug()<<"66666666666666666666";
            //  stringArray=(QString::fromStdString(snewEnemy->serialize())).split(',');qDebug()<<"777777777777777777777777777";
            //  int p=stringArray[4].toInt(0);PPEnemy.push_back(p); qDebug()<<"8888888888888888888888";
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

  scalNum=100;
  timer = new QTimer(this);
  timersoul = new QTimer(this);
  timerSkeleton = new QTimer(this);
  timerUseHealth = new QTimer(this);
  timerShowPoisodisapperEffect =new QTimer(this);
  timerShowProtDie = new QTimer(this);
  timerEnemyAttack = new QTimer(this);timerPEnemyAttack = new QTimer(this);


 /*
  for ( auto &enemy : enemies)
  {
     qDebug()<<"QString::fromStdString(enemy->serialize())";
   i++;
      int numberOfparameter =(QString::fromStdString(enemy->serialize())).split(',').length()-1;
      std::shared_ptr<Enemy> newEnemy = std::move(enemy);
       if(numberOfparameter==3)
      {   qDebug()<<QString::fromStdString(enemy->serialize());
           soulEnemies.push_back(newEnemy);
      }
      else
      { qDebug()<<QString::fromStdString(enemy->serialize());
           PEnemies.push_back(newEnemy);
           QVector<QString> stringArray(5);
           stringArray=(QString::fromStdString(enemy->serialize())).split(',');
           int p=stringArray[4].toInt(0);PPEnemy.push_back(p);
           PEnemyIndex.push_back(i);
       }
  }
*/
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
float model::checkwall(int protx, int proty)
{
     protx=prot->getXPos();
     proty=prot->getYPos();
float difficulty = array[proty][protx];

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
