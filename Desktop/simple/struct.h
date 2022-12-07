#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <memory>
#include "world.h"
//#include "./viewers/GraphicsHP.h"

struct poisonedTile
{
    std::shared_ptr<Tile> tile;
    std::shared_ptr<PEnemy> parent;
};

struct animate_position
{
    bool animate;
    long position;
};

struct damage_struct
{
    int direction;
    std::shared_ptr<Enemy> enemy;
};

struct set_sizes {
    int width;
    int height;
};

struct coloredTile {
    QString colorInHex;
    set_sizes position;
};

struct enemy {

};

struct point {
    int xCoordinate;
    int yCoordinate;
};

struct wrapperHP {
    int x;
    int y;
   // GraphicsHP * hp;
};

struct euclidian {
    Tile actor;
    int distance;
};

struct PlannerNode{
    //std::shared_ptr<PlannerNode> m_pParent; //men path
    int m_cellX, m_cellY;
    float finalCost;
    float givenCost;
    int valueTile;

    int lastX;
    int lastY;
    bool inUsedlist;

};

struct combo{
    std::shared_ptr<Tile> tile;
    std::shared_ptr<Enemy> enemy;
};

#endif // STRUCTS_H
