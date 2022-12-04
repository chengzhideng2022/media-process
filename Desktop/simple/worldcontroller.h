#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include <QMainWindow>
#include <QObject>
#include "world.h"
class WorldController
{
public:
    WorldController();
private:
    std::shared_ptr<World> world;
    QString map;
};

#endif // WORLDCONTROLLER_H
