#include "worldfactory.h"



#include <world.h>
#include <models/gameworld.h>
#include <iostream>



std::shared_ptr<GameWorld> WorldFactory::createWorld(QString filename)
{
    std::unique_ptr<World> world = std::make_unique<World>();

    if(filename==":/pic/img/worldmap.png")
    {
        world->createWorld(filename, 20, 20, 0.5);

    }
    else if(filename==":/pic/img/worldmap4.png")
    {
        //world->createWorld(filename, 5000, 5000, 0.5);
        world->createWorld(filename, 20, 20, 0.5);

    }
    else if(filename==":/pic/img/maze1.png")
    {
        //world->createWorld(filename, 5555, 5555, 0.5);
        world->createWorld(filename, 20, 20, 0.5);

    }
    else if(filename==":/pic/img/maze2.png")
    {
        //world->createWorld(filename, 7786, 7786, 0.5);
        world->createWorld(filename, 20, 20, 0.5);
    }
    else if(filename==":/pic/img/maze3.png")
    {
        //world->createWorld(filename, 7786, 7786, 0.5);
        world->createWorld(filename, 20, 20, 0.5);

    }

    std::shared_ptr<GameWorld> gameWorld = std::make_shared<GameWorld>();
    gameWorld->createGameWorld(filename, std::move(world));


    return gameWorld;

}
