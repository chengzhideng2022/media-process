#ifndef WORLDFACTORY_H
#define WORLDFACTORY_H
#include <world.h>
#include <models/gameworld.h>

class WorldFactory
{
public:
    WorldFactory()=default;
    std::shared_ptr<GameWorld> createWorld(QString filename);
};

#endif // WORLDFACTORY_H
