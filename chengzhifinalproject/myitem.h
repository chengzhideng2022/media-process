#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsPixmapItem>
#include "world.h"
using namespace std;
class myItem : public QGraphicsPixmapItem
{
public:
    myItem();
    std::vector<std::unique_ptr<Tile>> getTiles()const;

private:
    int height;
    int width;
    std::unique_ptr<World> world;
    std::vector<std::unique_ptr<Tile>> tiles;
};

#endif // MYITEM_H
