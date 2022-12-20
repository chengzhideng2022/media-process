#ifndef MODEL_H
#define MODEL_H

#include "world.h"
class model
{
public:
    model();

std::vector<std::shared_ptr<Tile>> getHealthpack();
std::vector<std::shared_ptr<Tile>> getTiles();
std::vector<std::shared_ptr<Enemy>> getEnemies();
private:
  std::shared_ptr<World> world;

  int height;
  int width;
  int scalNum;
  int Num_enemies;
  int Num_healthpacks;
  int Num_P_enemies;
  int flag,checkProtNeedDieFlag,checkIsPoisoItemFlag;
  int attackFlag,showProtDieFlag,showEnemyAttackFlag,showPEnemyAttackFlag;
  int soulFlag,skeletonFlag,showUseHealthBagFlag;
  float ratio;
  int index_enemy,index_healthBag;
  int indexInPenemyList=-1;
  std::vector<int> PEnemiesX;
  std::vector<int> PEnemiesY;
  std::shared_ptr<Protagonist> prot;
  std::array<std::shared_ptr<Protagonist>,4> protList;
  //std::vector<std::unique_ptr<Enemy>> PEnemies;
  std::vector<std::shared_ptr<Enemy>> enemies;
   std::vector<std::shared_ptr<Tile>> tiles;
  std::vector<PEnemy> *PEnemies;
  std::vector<std::shared_ptr<Tile>> healthpacks;
  std::vector<int> PEnemyIndex;
  std::vector<int> XPEnemy,YPEnemy,PPEnemy,DPEnemy,SPEnemy;

};

#endif // MODEL_H
