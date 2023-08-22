#ifndef POSITONSEARCHWORLD_H
#define POSITONSEARCHWORLD_H

#include "gameworld.h"
#include <QPoint>

class PositonSearchWorld : public GameWorld
{
public:
    PositonSearchWorld(int goalXPos, int goalYPos);

    bool isGoalState() override;


    QPoint getGoalPositon() const;
    void setGoalPositon(int goalXPos, int goalYPos);

private:

    QPoint goalPositon;

};

#endif // POSITONSEARCHWORLD_H
