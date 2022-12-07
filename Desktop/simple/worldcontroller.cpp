#include "worldcontroller.h"
#include "world.h"
#include "struct.h"
WorldController::WorldController(QString map)
{    map = ":/img/worldmap4.png";
    world = std::make_shared<World>();
    world->createWorld(map,20,20,0.0);

    height = world->getRows() - 1;
    width = world->getCols() - 1;

     for ( auto &enemy : world->getEnemies() )
     {
         std::shared_ptr<Enemy> newEnemy = std::move(enemy);
         enemies_temp.push_back( newEnemy );
         enemies.push_back( newEnemy );
     }

     for ( auto &tile : world->getTiles() )
     {
         std::shared_ptr<Tile> newTile = std::move(tile);
         float val = newTile->getValue();
         if(val != std::numeric_limits<float>::infinity()){
             newTile->setValue(1-val);
         }
         tiles.push_back( newTile );


         combo pack;
         pack.tile = newTile;

         combos.push_back(pack);
     }
}

std::vector<std::shared_ptr<Tile>> WorldController::getTiles() const
{
    return tiles;
}

QString WorldController::getMapPath() const
{
    return map;
}

int WorldController::getHeight() const
{
    return height;
}

int WorldController::getWidth() const
{
    return width;
}

const std::vector<std::shared_ptr<Enemy> > &WorldController::getEnemies() const
{
    return enemies;
}

const std::vector<std::shared_ptr<Tile> > &WorldController::getHealthpacks() const
{
    return healthpacks;
}

void WorldController::makeWall(int x, int y)
{
    for( std::shared_ptr<Tile> tile : tiles ){
        if(tile->getXPos() == x && tile->getYPos() == y )
        {
            tile->setValue( std::numeric_limits<float>::infinity() );
        }
    }
}
std::shared_ptr<Tile> WorldController::getTile(int x, int y)
{
    if( x>width || y>height ){ return nullptr; }
    /*
    for(auto tempTile : tiles)
    {
        if(tempTile->getXPos() == x && tempTile->getYPos() == y)
            return tempTile;
    }
    return nullptr;
    */
    return tiles.at( y*(width+1) + x );
}
