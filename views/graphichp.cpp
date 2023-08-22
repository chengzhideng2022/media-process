#include "graphichp.h"


GraphicHp::GraphicHp(int size,int x, int y, QObject *parent ):GraphicActor(size,x, y, parent)
{

    animationTimer = std::make_unique<QTimer>(this);
    connect(animationTimer.get(), &QTimer::timeout, this ,&GraphicHp::showAnimation);


    QPixmap pix;
    pix.load(regularImgs[regularImgIndex]);
    pix=pix.scaled(size, size, Qt::KeepAspectRatio);
    this->setPixmap(pix);

    animationTimer->start(ani_interval);

}

void GraphicHp::showAnimation()
{
    QPixmap pix;
    pix.load(regularImgs[regularImgIndex++]);
    pix=pix.scaled(size, size, Qt::KeepAspectRatio);
    this->setPixmap(pix);

    if(regularImgIndex>= (int)regularImgs.size())
    {
        regularImgIndex = 0;
    }

}

void GraphicHp::die()
{
    this->setVisible(false);
}

std::string GraphicHp::toString()
{
   return "hp at ";

}

int GraphicHp::getAni_interval() const
{
    return ani_interval;
}

void GraphicHp::setAni_interval(int newAni_interval)
{
    ani_interval = newAni_interval;
    animationTimer->setInterval(ani_interval);
}
