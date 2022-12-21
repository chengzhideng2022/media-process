#ifndef MYSCENE_H
#define MYSCENE_H
#include <map>
#include "model.h"
#include "myitem.h"
#include <QObject>
#include <QGraphicsScene>
#include <QMouseEvent>

using namespace std;
class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr,QString maps = ":/img/worldmap.png");
void drawWorld(int scal);
void userMoveView();
void showPath();
void keyPressEvent(QKeyEvent *event);
void getmousePressEvent(QMouseEvent *event);

//these func are all get return from model
int getProtX();
int getProtY();
int getscalNum();
float checkwall(int x, int y);
int checkIsEnemy(int x, int y);
int checkIsHealthBag(int x, int y);


void checkProtNeedDie();
void checkIsPoisoItem();
//these func are all get return from model








signals:
void moveViewSignal();

public slots:
void protAttackView();
void attackTimeSignal();
void enemyDieSignal();
void PEnemyDieSignal();
void useHealthSignal();
void protDieSignal();
void showEffectOfPoisoningSignal();

void showEnemyAttackSignal();
void showPEnemyAttackSignal();
void showEnemydie();
void showPEnemydie();
void showProtDie();
void showUseHealthBag();
void showEffectOfPoisoning();
void showPoisoningDisappear();

void showEnemyAttack();
void showPEnemyAttack();
//void moveView();

private:
model *m;
 myItem *item;
 int height;
 int width;
 int scalNum;
 int Num_enemies;
 int Num_healthpacks;
 int Num_P_enemies;
 int flag;//for prot move
 int attackFlag,showProtDieFlag,showEnemyAttackFlag,showPEnemyAttackFlag;
 int soulFlag,skeletonFlag,showUseHealthBagFlag;
 float ratio;
 int index_enemy,index_healthBag;
 int indexInPenemyList=-1;
  QPointF cursorPoint;

 QTimer *timer,*timerShowPoisodisapperEffect,*timerShowProtDie;
 QTimer *timersoul,*timerSkeleton,*timerUseHealth;
 QTimer *timerEnemyAttack,*timerPEnemyAttack;
 std::unique_ptr<World> world;
 std::vector<std::shared_ptr<Tile>> tiles;
QImage bg;
QGraphicsPixmapItem *protpixmapItem;
QGraphicsPixmapItem *enemypixmapItem[20];
QGraphicsPixmapItem *healthpixmapItem[20];
QGraphicsRectItem *poisorectItem[8];
QPixmap pm;
std::vector<int> PEnemiesX;
std::vector<int> PEnemiesY;
std::unique_ptr<Protagonist> prot;
std::array<std::unique_ptr<Protagonist>,4> protList;
//std::vector<std::unique_ptr<Enemy>> PEnemies;
std::vector<std::shared_ptr<Enemy>> enemies;
std::vector<std::shared_ptr<Enemy>>PEnemies;
std::vector<std::shared_ptr<Enemy>>soulEnemies;
std::vector<std::shared_ptr<Tile>> healthpacks;
std::vector<int> PEnemyIndex;
std::vector<int> XPEnemy,YPEnemy,PPEnemy,DPEnemy,SPEnemy;
//std::vector<std::shared_ptr<poisonedTile>> poisonedTiles;
bool gameStop = false;
char activeProtsAmount = 1;
float **array;
};

#endif // MYSCENE_H
