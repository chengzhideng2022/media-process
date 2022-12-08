#include "myscene.h"

myScene::myScene(QObject *parent) : QGraphicsScene{parent}
{
 //this->item= new myItem;
 //item->setPos(1,1);
 //item->setOffset(10000,100000);
 //myItem *item2 =new myItem;
 //this->addItem(this->item);
 //item2->setPos(2000,20000);
 //this->addItem(item2);
 QString map = ":/img/worldmap4.png";
 world = std::make_unique<World>();
 world->createWorld(map,20,20,0.0);
 tiles = world->getTiles();

 height = world->getRows() - 1;
 width = world->getCols() - 1;

 /*for ( auto &tile : tiles )
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
         QGraphicsRectItem *rectItem = new QGraphicsRectItem();
         rectItem->setRect(newTile->getXPos(),newTile->getYPos(), 1, 1);
     }
*/


                                     //  tiles = item->getTiles();
  QGraphicsRectItem *rectItem = new QGraphicsRectItem();
  rectItem->setRect(100000,1000, 10, 10);


  rectItem-> setPen(QPen(Qt::NoPen));;
  rectItem->setBrush(QBrush(QColor(255, 0, 255)));
  rectItem->setPos(1000,10000);
  rectItem->setFlag(QGraphicsItem::ItemIsMovable);
 // this->addItem(rectItem);

     //QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem();
drawWorld();
}

void myScene::drawWorld()
{
    bg = QImage(":/img/maze3.png");
    for ( auto &tile : tiles )
    {
        int xpos = tile->getXPos();
        int ypos = tile->getYPos();
        float val = tile->getValue();
        if(val==std::numeric_limits<float>::infinity()){
            bg.setPixelColor(xpos, ypos, QColor(0,0,0));
        }else{
            bg.setPixelColor(xpos, ypos, QColor(255,255,255)
                                   // (int)(floor(255*val/2)+125),
                                    //(int)(floor(255*(1-val))),
                                 //  (int)(floor(255*(1-val)/2)))
                                );
        }
    }
    pm.convertFromImage(bg);
    pixmapman.setPixmap(pm);
   this->addItem(&pixmapman);
}
