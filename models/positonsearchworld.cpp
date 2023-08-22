#include "positonsearchworld.h"

PositonSearchWorld::PositonSearchWorld(int goalXPos, int goalYPos): goalPositon(goalXPos, goalYPos)
{

}

bool PositonSearchWorld::isGoalState()
{
    for(auto& prot : protagonistes)
    {
        if(prot->getXPos()==goalPositon.rx() && prot->getYPos()==goalPositon.ry())
        {
            return true;
        }
    }
    return false;

}

QPoint PositonSearchWorld::getGoalPositon() const
{
    return goalPositon;
}

void PositonSearchWorld::setGoalPositon(int goalXPos, int goalYPos)
{
    goalPositon.setX(goalXPos);
    goalPositon.setY(goalYPos);
}
