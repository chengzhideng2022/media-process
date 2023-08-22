#ifndef CUSTOMIZEDENEMY_H
#define CUSTOMIZEDENEMY_H

#include <world.h>


class CustomizedEnemy : public Enemy
{
public:
    CustomizedEnemy(int xPosition, int yPosition, float strength);
    virtual void action()=0;
};

#endif // CUSTOMIZEDENEMY_H
