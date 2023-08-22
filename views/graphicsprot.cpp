#include "graphicsprot.h"

GraphicsProt::GraphicsProt(int size, int x, int y, QObject *parent ): GraphicActor(size, x, y, parent)
{
    protAttackTimer = std::make_unique<QTimer>(this);
    connect(protAttackTimer.get(), &QTimer::timeout, this , &GraphicsProt::showAttack);

    protDieTimer = std::make_unique<QTimer>(this);
    connect(protDieTimer.get(), &QTimer::timeout, this , &GraphicsProt::showDie);

    protUseHealthPackTimer = std::make_unique<QTimer>(this);
    connect(protUseHealthPackTimer.get(), &QTimer::timeout, this , &GraphicsProt::showUseHealthPack);


    protAnimationTimer = std::make_unique<QTimer>(this);
    connect(protAnimationTimer.get(), &QTimer::timeout, this ,&GraphicsProt::showAnimation);


    protPoisonedTimer = std::make_unique<QTimer>(this);
    connect(protPoisonedTimer.get(), &QTimer::timeout, this ,&GraphicsProt::stopPoisoned);


    QPixmap pix;
    pix.load(aniImgs[aniImgIndex]);
    pix=pix.scaled(size, size, Qt::KeepAspectRatio);
    this->setPixmap(pix);

    protAnimationTimer->start(regular_ani_interval);


}

int GraphicsProt::getRegular_ani_interval() const
{
    return regular_ani_interval;
}

void GraphicsProt::setRegular_ani_interval(int newRegular_ani_interval)
{
    regular_ani_interval = newRegular_ani_interval;
    protAnimationTimer->setInterval(regular_ani_interval);
}


void GraphicsProt::die()
{
   if(protAnimationTimer->isActive()) protAnimationTimer->stop();
   if(protUseHealthPackTimer->isActive()) protUseHealthPackTimer->stop();
   if(protAttackTimer->isActive()) protAttackTimer->stop();
    protDieTimer->start(die_ani_interval);
}

void GraphicsProt::attack()
{
   if(protAnimationTimer->isActive()) protAnimationTimer->stop();
   if(protUseHealthPackTimer->isActive()) protUseHealthPackTimer->stop();
    protAttackTimer->start(attack_ani_interval);
}

void GraphicsProt::showAnimation()
{

    QPixmap pix;
    pix.load(aniImgs[aniImgIndex++]);
    pix=pix.scaled(size, size, Qt::KeepAspectRatio);

    this->setPixmap(changeColorIfPoisoned(pix));


    if(aniImgIndex>= (int)aniImgs.size())
    {
        aniImgIndex = 0;
    }

}


QPixmap& GraphicsProt::changeColorIfPoisoned(QPixmap& pix)
{
    if(poisoned)
    {
        QImage image = pix.toImage();

        for (int x = 0; x < image.width(); ++x) {
            for (int y = 0; y < image.height(); ++y) {
                QColor pixelColor = image.pixelColor(x, y);

               if (pixelColor.red() < 50 && pixelColor.green() < 50 && pixelColor.blue() < 50 &&
                       pixelColor.red()!= 0 && pixelColor.green()!= 0 && pixelColor.blue()!= 0)
               {
                    image.setPixelColor(x, y, QColor(0, 0, 255));
               }
            }
        }

        pix = QPixmap::fromImage(image);
    }

    return pix;

}



void GraphicsProt::useHealthPack()
{
    if(protAnimationTimer->isActive()) protAnimationTimer->stop();
    if(protAttackTimer->isActive()) protAttackTimer->stop();

    protUseHealthPackTimer->start(useHp_interval);

}

void GraphicsProt::stopPoisoned()
{
    poisoned = false;
    protPoisonedTimer->stop();

}


void GraphicsProt::showAttack()
{
    QPixmap pix;
    if(attackImgIndex >= (int)attackImgs.size())
    {
        pix.load(aniImgs[aniImgIndex]);
        pix=pix.scaled(size, size, Qt::KeepAspectRatio);
        attackImgIndex = 0;
        protAttackTimer->stop();
        this->setPixmap(changeColorIfPoisoned(pix));
        protAnimationTimer->start(regular_ani_interval);


    }
    else
    {

        pix.load(attackImgs[attackImgIndex++]);
        pix=pix.scaled(size, size, Qt::KeepAspectRatio);
        this->setPixmap(changeColorIfPoisoned(pix));
    }

}

void GraphicsProt::showDie()
{
    if(dieImgIndex >= (int)dieImgs.size())
    {
        dieImgIndex = 0;
        protDieTimer->stop();
        emit gameOver();
    }
    else
    {
        QPixmap pix;
        pix.load(dieImgs[dieImgIndex++]);
        pix=pix.scaled(size, size, Qt::KeepAspectRatio);
        this->setPixmap(changeColorIfPoisoned(pix));
    }

}

void GraphicsProt::showUseHealthPack()
{
    QPixmap pix;
    if(useHPImgIndex >= (int)useHPImgs.size())
    {

        pix.load(aniImgs[aniImgIndex]);
        pix=pix.scaled(size, size, Qt::KeepAspectRatio);
        useHPImgIndex = 0;
        protUseHealthPackTimer->stop();
        this->setPixmap(changeColorIfPoisoned(pix));
        protAnimationTimer->start(regular_ani_interval);

    }
    else
    {
        pix.load(useHPImgs[useHPImgIndex++]);
        pix=pix.scaled(size, size, Qt::KeepAspectRatio);
        this->setPixmap(changeColorIfPoisoned(pix));
    }

}

void GraphicsProt::showPoisoned()
{
    QPixmap image = this->pixmap();
    this->setPixmap(changeColorIfPoisoned(image));

   if(poisoned)
   {
      protPoisonedTimer->start(protPoisonedTimer->remainingTime()+poisoned_interval);
   }
   else
   {
       poisoned = true;
       protPoisonedTimer->start(poisoned_interval);
   }


}



