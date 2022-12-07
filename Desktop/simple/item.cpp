#include "item.h"
#include <QPixmap>
Item::Item()
{
 // this->setPixmap(new QPixmap(":/img/worldmap4.png"));

    std::shared_ptr<WorldController> wc = std::make_shared<WorldController>(":/img/worldmap4.png");
    pathmap = wc->getMapPath();
    world = QImage(pathmap);
    world.convertTo(QImage::Format_RGB888);
    pm.convertFromImage(world);
    pixmapman.setPixmap(pm);
    pixmapman.setScale(tilesize);
   // scene->addItem(&pixmapman);

   // fillworld();
}
