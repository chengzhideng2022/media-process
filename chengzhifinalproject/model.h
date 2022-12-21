#ifndef MODEL_H
#define MODEL_H

#include "world.h"
#include "qevent.h"
#include <QGraphicsView>
#include <QDebug>
#include <vector>
#include <QTimer>
#include <QObject>
#include <QString>
#include <QKeyEvent>
#include<bits/stdc++.h>
class model : public QGraphicsScene
{
     Q_OBJECT
public:
    model(QString map = ":/img/worldmap.png");

std::vector<std::shared_ptr<Tile>> getHealthpack();
std::vector<std::shared_ptr<Tile>> getTiles();
std::vector<std::shared_ptr<Enemy>> getEnemies();
int getHeight(); int getWidth(); int getScalNum();
int getProtX(); int getProtY(); void setProtX(int x);void setProtY(int y);
int getProtNeedDieFlag();
std::vector<std::shared_ptr<Enemy>> getPEnemies();
std::vector<std::shared_ptr<Enemy>> getsoulEnemies();

std::vector<int> getPPenemy();
std::vector<int> getPEnemyIndex();
int getindex_enemy();
float ** GetColorDepth();

float checkwall(int protx, int proty);
int checkIsEnemy(int x, int y);
int checkIsHealthBag(int x, int y);
bool checkProtNeedDie();
void protHurt();



private:
  std::shared_ptr<World> world;
  float **array;
  int height;
  int width;
  int scalNum;
  int Num_enemies;
  int Num_healthpacks;
  int Num_P_enemies;
  int checkProtNeedDieFlag;

  float ratio;
  int index_enemy,index_healthBag;
  int indexInPenemyList=-1;
 QString map;
  std::vector<int> PEnemiesX;
  std::vector<int> PEnemiesY;
  std::shared_ptr<Protagonist> prot;
  std::array<std::shared_ptr<Protagonist>,4> protList;
  std::vector<std::shared_ptr<Enemy>> PEnemies;
  std::vector<std::shared_ptr<Enemy>> enemies;
  std::vector<std::shared_ptr<Enemy>> soulEnemies;
   std::vector<std::shared_ptr<Tile>> tiles;
  // std::vector<PEnemy> *PEnemies;
  std::vector<std::shared_ptr<Tile>> healthpacks;
  std::vector<int> PEnemyIndex;
  std::vector<int> XPEnemy,YPEnemy,PPEnemy,DPEnemy,SPEnemy;

  QTimer *timer,*timerShowPoisodisapperEffect,*timerShowProtDie;
  QTimer *timersoul,*timerSkeleton,*timerUseHealth;
  QTimer *timerEnemyAttack,*timerPEnemyAttack;


};

#endif // MODEL_H
