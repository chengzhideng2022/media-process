#ifndef MYSCENE_H
#define MYSCENE_H

#include "myitem.h"
#include <QObject>
#include <QGraphicsScene>
using namespace std;
class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);
void drawWorld();
//std::unique_ptr<Protagonist> getprot();
void userMove();
void keyPressEvent(QKeyEvent *event);
float checkwall(int x, int y);

signals:


private:
 myItem *item;
 int height;
 int width;
 std::unique_ptr<World> world;
 std::vector<std::unique_ptr<Tile>> tiles;
QImage bg;
QGraphicsPixmapItem *protpixmapItem;
QPixmap pm;
std::unique_ptr<Protagonist> prot;
std::array<std::unique_ptr<Protagonist>,4> protList;
std::vector<std::unique_ptr<Enemy>> enemies_temp;
std::vector<std::unique_ptr<Enemy>> enemies;
std::vector<std::unique_ptr<Tile>> healthpacks;
//std::vector<std::shared_ptr<poisonedTile>> poisonedTiles;
bool gameStop = false;
char activeProtsAmount = 1;
float **array;
};

#endif // MYSCENE_H
