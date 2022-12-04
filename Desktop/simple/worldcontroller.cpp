#include "worldcontroller.h"
#include "world.h"
WorldController::WorldController()
{    map = ":/img/worldmap4.png";
    world = std::make_shared<World>();
    world->createWorld(map,20,20,0.0);
}
