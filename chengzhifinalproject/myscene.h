#ifndef MYSCENE_H
#define MYSCENE_H
#include <map>
#include "myitem.h"
#include <QObject>
#include <QGraphicsScene>
using namespace std;
class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);
void drawWorld(int scal);
void userMoveView();

void keyPressEvent(QKeyEvent *event);
float checkwall(int x, int y);
int checkIsEnemy(int x, int y);
int checkIsHealthBag(int x, int y);
int getProtX();
int getProtY();
int getscalNum();
void showEnemyAttack();
void showPEnemyAttack();




public slots:

void attack();

signals:
void moveViewSignal();

public slots:
void attackTimeSignal();
void enemyDieSignal();
void PEnemyDieSignal();
void useHealthSignal();
void protDieSignal();
void showEffectOfPoisoningSignal();

void showEnemydie();
void showPEnemydie();
void showProtDie();
void showUseHealthBag();
void showEffectOfPoisoning();
void showPoisoningDisappear();
//void moveView();

private:
 myItem *item;
 int height;
 int width;
 int scalNum;
 int Num_enemies;
 int Num_healthpacks;
 int Num_P_enemies;
 int flag;
 int attackFlag,showProtDieFlag;
 int soulFlag,skeletonFlag,showUseHealthBagFlag;
 float ratio;
 int a;
 int index_enemy,index_healthBag;
 int indexInPenemyList=-1;
 //std::unordered_map<int, Enemy> enemiesList;
 QTimer *timer,*timerShowPoisodisapperEffect,*timerShowProtDie;
 QTimer *timersoul,*timerSkeleton,*timerUseHealth;
 std::unique_ptr<World> world;
 std::vector<std::unique_ptr<Tile>> tiles;
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
std::vector<std::unique_ptr<Enemy>> enemies;
std::vector<PEnemy> *PEnemies;
std::vector<std::unique_ptr<Tile>> healthpacks;
std::vector<int> PEnemyIndex;
std::vector<int> XPEnemy,YPEnemy,PPEnemy,DPEnemy,SPEnemy;
//std::vector<std::shared_ptr<poisonedTile>> poisonedTiles;
bool gameStop = false;
char activeProtsAmount = 1;
float **array;
};

#endif // MYSCENE_H
