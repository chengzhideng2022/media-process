#include "model.h"
#include "qtimer.h"
#include <QTimer>
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

  for ( auto &enemy : world->getEnemies() )
  {
      std::shared_ptr<Enemy> newEnemy = std::move(enemy);
      enemies.push_back( newEnemy );
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
