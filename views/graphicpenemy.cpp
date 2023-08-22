#include <QPen>
#include "graphicpenemy.h"

GraphicPEnemy::GraphicPEnemy(int size,int x, int y, QObject *parent): GraphicEnemy{size,x, y, parent}
{

    QPixmap pix;
    pix.load(regularImgs[regularImgIndex]);
    pix=pix.scaled(size, size, Qt::KeepAspectRatio);
    this->setPixmap(pix);

}


void GraphicPEnemy::die()
{
    if(enmeyAttackTimer->isActive()) enmeyAttackTimer->stop();
    if(animationTimer->isActive()) animationTimer->stop();

    enmeyDieTimer->start(die_ani_interval);

}

void GraphicPEnemy::attack()
{
    if(animationTimer->isActive()) animationTimer->stop();
    enmeyAttackTimer->start(attack_ani_interval);

}

void GraphicPEnemy::showAttack()
{

    QPixmap pix;
    if(attackImgIndex >= (int)attackImgs.size())
    {
        pix.load(attackImgs[regularImgIndex]);
        pix=pix.scaled(size, size, Qt::KeepAspectRatio);
        attackImgIndex = 0;
        enmeyAttackTimer->stop();
        this->setPixmap(pix);

    }
    else
    {
        pix.load(attackImgs[attackImgIndex++]);
        pix=pix.scaled(size, size, Qt::KeepAspectRatio);
        this->setPixmap(pix);
    }

}

void GraphicPEnemy::showDie()
{

    if(dieImgIndex >= (int)dieImgs.size())
    {
        dieImgIndex = 0;
        enmeyDieTimer->stop();

    }
    else
    {
        QPixmap pix;
        pix.load(dieImgs[dieImgIndex++]);
        pix=pix.scaled(size, size, Qt::KeepAspectRatio);
        this->setPixmap(pix);
    }

}

void GraphicPEnemy::showAnimation()
{
    QPixmap pix;
    pix.load(regularImgs[regularImgIndex++]);
    pix=pix.scaled(size, size, Qt::KeepAspectRatio);
    this->setPixmap(pix);

    if(regularImgIndex>=(int)regularImgs.size())
    {
        regularImgIndex = 0;
    }


}

