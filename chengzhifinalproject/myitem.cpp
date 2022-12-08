#include "myitem.h"
#include <QPixmap>
#include <QString>
#include "world.h"
#include <QDebug>

myItem::myItem()
{

     QPixmap pix;
     pix.load(":/img/golem2.png");
   QString map = ":/img/maze3.png";
    world = std::make_unique<World>();
    world->createWorld(map,20,20,0.0);
    tiles = world->getTiles();

    height = world->getRows() - 1;
    width = world->getCols() - 1;

     // qDebug() <<height<<"  "<<width;


    for ( auto &tile : tiles )
    {
        std::unique_ptr<Tile> newTile = std::move(tile);
        float val = newTile->getValue();
        if(val != std::numeric_limits<float>::infinity()){
            newTile->setValue(1-val);
        }
        else
        {
          newTile->setValue(1);
        }
       // qDebug() <<newTile->getValue()<<"  ";
        //tiles.push_back( newTile );
    }

      this->setPixmap(pix);
}

//vector<unique_ptr<Tile>> myItem::getTiles() const
//{
  //  return this->tiles;
//}
