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

signals:


private:
 myItem *item;
 int height;
 int width;
 std::unique_ptr<World> world;
 std::vector<std::unique_ptr<Tile>> tiles;
QImage bg;
QGraphicsPixmapItem pixmapman;
QPixmap pm;
};

#endif // MYSCENE_H
