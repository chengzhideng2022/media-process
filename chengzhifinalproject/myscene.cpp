#include "myscene.h"
#include "qevent.h"
#include <QGraphicsView>

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
 enemies = world->getEnemies();
 tiles = world->getTiles();
 healthpacks = world->getHealthPacks();
 prot= world->getProtagonist();
 height = world->getRows() ;
 width = world->getCols();
//QPoint cursorPoint;




drawWorld();

}
void myScene::keyPressEvent(QKeyEvent *event)
{
    float difficulty= checkwall(prot->getXPos()-1,prot->getYPos());


    if (event->key() == Qt::Key_Left && checkwall(prot->getXPos()-1,prot->getYPos())) { // 向左移动
       protpixmapItem ->moveBy(-2,0); prot->setXPos(prot->getXPos()-1);}
    else if (event->key() == Qt::Key_Right && checkwall(prot->getXPos()+1,prot->getYPos())) {// 向右移动
       protpixmapItem ->moveBy(2, 0); prot->setXPos(prot->getXPos()+1);}
    else if (event->key() == Qt::Key_Up && checkwall(prot->getXPos(),prot->getYPos()-1)) {// 向上移动
        protpixmapItem->moveBy(0, -2);prot->setYPos(prot->getYPos()-1);}
    else if (event->key() == Qt::Key_Down && checkwall(prot->getXPos()-1,prot->getYPos()+1)){ // 向下移动
        protpixmapItem->moveBy(0, 2);prot->setYPos(prot->getYPos()+1);}
}
void myScene::drawWorld()
{
    int rows = height;
    int cols = width;





    // 动态分配一个 rows * cols 大小的数组
    array = new float*[rows];
    for (int i = 0; i < rows; i++) {
    array[i] = new float[cols];}

    for ( auto &tile : tiles )
        {
            std::unique_ptr<Tile> newTile = std::move(tile);
            float val = newTile->getValue();
            int tx = newTile->getXPos();
            int ty = newTile->getYPos();
            if(val == std::numeric_limits<float>::infinity()){
                newTile->setValue(0);
            }

             val = newTile->getValue();
             array[ty][tx]=val;
            QGraphicsRectItem *rectItem = new QGraphicsRectItem();
            rectItem->setRect(newTile->getXPos()*2,newTile->getYPos()*2, 2, 2);
            rectItem-> setPen(QPen(Qt::NoPen));;
            rectItem->setBrush(QBrush(QColor(val*255, 255, val*255)));
            this->addItem(rectItem);
        }


 /*   for ( auto enemy : enemies_temp )
    {
        if(getTile(enemy->getXPos(), enemy->getYPos())->getValue() != std::numeric_limits<float>::infinity()){
            enemies.push_back( enemy );
        }

    }
*/


    for ( auto &enemy : enemies )
    {
        QPixmap pix;
        pix.load(":/img/virus4.png");
        QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();
        pixmapItem->setPixmap(pix);
         pixmapItem->setPos(enemy->getXPos()*2, enemy->getYPos()*2);
         pixmapItem->setZValue(1);
         pixmapItem->grabKeyboard();
         this->addItem(pixmapItem);
    }

    for ( auto &healthpack : healthpacks)
    {
        QPixmap pix;
        pix.load(":/img/pill1.png");
        QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();
        pixmapItem->setPixmap(pix);
         pixmapItem->setPos(healthpack->getXPos()*2, healthpack->getYPos()*2);
         pixmapItem->setZValue(1);
         this->addItem(pixmapItem);
    }
    QPixmap pix;
    pix.load(":/img/prot1.png");
    protpixmapItem = new QGraphicsPixmapItem();
    protpixmapItem->setPixmap(pix);
    protpixmapItem->setPos(prot->getXPos()*2, prot->getYPos()*2);
    protpixmapItem->setZValue(1);
     this->addItem(protpixmapItem);
 /*   for ( auto &hp : world->getHealthPacks() )
    {
        std::shared_ptr<Tile> newHp= std::move(hp);
        healthpacks.push_back( newHp );
    }

*/

}

float myScene::checkwall(int protx, int proty)
{
     protx=prot->getXPos();
     proty=prot->getYPos();
float difficulty = array[proty][protx];

return difficulty;


}
/*
void myScene::userMove()

{
    static int speed = 10;
    if(->state == userTank::moving){
       QPointF srcPos = tank->pos();

       switch(tank->movedir){
       case  userTank::down:
           srcPos.setY(qMin(srcPos.y()+speed,scene->sceneRect().height()-tank->size.rheight()));
           break;
       case  userTank::up:
           srcPos.setY(qMax(srcPos.y()-speed,0.0));
           break;
       case  userTank::right:
           srcPos.setX(qMin(srcPos.x()+speed,scene->sceneRect().width()-tank->size.rwidth()));
           break;
       default:
           srcPos.setX(qMax(srcPos.x()-speed,0.0));
       }
       //this->sc->getprot()->setPos(srcPos);
       this->sc->prot->setPos(srcPos);

   }
   */
//std::unique_ptr<Protagonist> myScene::getprot()
//{
   // return prot;
//}

/*
 * void myScene::drawWorld()
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
*/
