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
void showEnemydie();
void showPEnemydie();
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
 int attackFlag;
 int soulFlag,skeletonFlag;
 float ratio;
 int a;
 int index_enemy;
 //std::unordered_map<int, Enemy> enemiesList;
 QTimer *timer;
 QTimer *timersoul,*timerSkeleton;
 std::unique_ptr<World> world;
 std::vector<std::unique_ptr<Tile>> tiles;
QImage bg;
QGraphicsPixmapItem *protpixmapItem;
QGraphicsPixmapItem *enemypixmapItem[5];
QPixmap pm;
std::vector<int> PEnemiesX;
std::vector<int> PEnemiesY;
std::unique_ptr<Protagonist> prot;
std::array<std::unique_ptr<Protagonist>,4> protList;
std::vector<std::unique_ptr<Enemy>> enemies_temp;
std::vector<std::unique_ptr<Enemy>> enemies;
std::vector<PEnemy> PEnemies;
std::vector<std::unique_ptr<Tile>> healthpacks;
std::vector<int> PEnemyIndex;
//std::vector<std::shared_ptr<poisonedTile>> poisonedTiles;
bool gameStop = false;
char activeProtsAmount = 1;
float **array;
};

#endif // MYSCENE_H
