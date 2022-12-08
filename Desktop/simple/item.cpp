#include "item.h"
#include <QPixmap>
#include <QPainter>
Item::Item()
{
 // this->setPixmap(new QPixmap(":/img/worldmap4.png"));

    //wc = std::make_shared<WorldController>(":/img/worldmap4.png");
    pathmap = wc->getMapPath();
    world = QImage(":/img/worldmap4.png");
    if(world.isNull()){
        qDebug()<<"读取图片错误";
    }
    else{
        world.save(":/img/worldmap4.png","PNG");
    }
    world.convertTo(QImage::Format_RGB888);
    pm.convertFromImage(world);
    pixmapman.setPixmap(pm);
    pixmapman.setScale(tilesize);
    scene->addItem(&pixmapman);

    fillworld();
}

void Item::fillworld()
{
    for ( auto &tile : wc->getTiles() )
    {
        int xpos = tile->getXPos();
        int ypos = tile->getYPos();
        float val = tile->getValue();
        if(tile->getValue()==std::numeric_limits<float>::infinity()){
            world.setPixelColor(xpos, ypos, QColor(0,0,0));
        }else{
            world.setPixelColor(xpos, ypos, QColor(
                                    (int)(floor(255*val/2)+125),
                                    (int)(floor(255*(1-val))),
                                    (int)(floor(255*(1-val)/2)))
                                );
        }
    }
    pm.convertFromImage(world);
    pixmapman.setPixmap(pm);
   // gv->repaint();
}
 QGraphicsScene*  Item::getScene() const
 {
     return scene;
 }
