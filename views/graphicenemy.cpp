#include "graphicenemy.h"

GraphicEnemy::GraphicEnemy(int size,int x, int y, QObject *parent): GraphicActor(size,x,y, parent)
{

    enmeyAttackTimer = std::make_unique<QTimer>(this);
    connect(enmeyAttackTimer.get(), &QTimer::timeout, this , &GraphicEnemy::showAttack);

    enmeyDieTimer = std::make_unique<QTimer>(this);
    connect(enmeyDieTimer.get(), &QTimer::timeout, this , &GraphicEnemy::showDie);

    animationTimer = std::make_unique<QTimer>(this);
    connect(animationTimer.get(), &QTimer::timeout, this ,&GraphicEnemy::showAnimation);


    QPixmap pix;
    pix.load(regularImgs[regularImgIndex]);
    pix=pix.scaled(size, size, Qt::KeepAspectRatio);
    this->setPixmap(pix);

    animationTimer->start(regular_ani_interval);
}






void GraphicEnemy::die()
{
    if(enmeyAttackTimer->isActive()) enmeyAttackTimer->stop();
    if(animationTimer->isActive())animationTimer->stop();

    enmeyDieTimer->start(die_ani_interval);

}

void GraphicEnemy::attack()
{
    if(animationTimer->isActive()) animationTimer->stop();

    enmeyAttackTimer->start(attack_ani_interval);

}

void GraphicEnemy::showAttack()
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

void GraphicEnemy::showDie()
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

void GraphicEnemy::showAnimation()
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


int GraphicEnemy::getRegular_ani_interval() const
{
    return regular_ani_interval;
}

void GraphicEnemy::setRegular_ani_interval(int newRegular_ani_interval)
{
    regular_ani_interval = newRegular_ani_interval;
    animationTimer->setInterval(regular_ani_interval);
}

int GraphicEnemy::getDie_ani_interval() const
{
    return die_ani_interval;
}

void GraphicEnemy::setDie_ani_interval(int newDie_ani_interval)
{
    die_ani_interval = newDie_ani_interval;
}

int GraphicEnemy::getAttack_ani_interval() const
{
    return attack_ani_interval;
}

void GraphicEnemy::setAttack_ani_interval(int newAttack_ani_interval)
{
    attack_ani_interval = newAttack_ani_interval;
}

