#include "myitem.h"
#include <QPixmap>

myItem::myItem()
{

     QPixmap pix;
     pix.load(":/img/maze3.png");
      this->setPixmap(pix);
}
