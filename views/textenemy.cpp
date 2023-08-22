#include "textenemy.h"

TextEnemy::TextEnemy(int x, int y, QObject *parent)
    : QObject{parent}
{

    pos.setX(x);
    pos.setY(y);

    enmeyDieTimer = std::make_unique<QTimer>(this);
    connect(enmeyDieTimer.get(), &QTimer::timeout, this , &TextEnemy::showDie);

    animationTimer = std::make_unique<QTimer>(this);
    connect(animationTimer.get(), &QTimer::timeout, this ,&TextEnemy::showAnimation);


    enemyView = regularImgs[regularImgIndex];

    animationTimer->start(regular_ani_interval);

}

const QString &TextEnemy::getEnemyView() const
{
    return enemyView;
}

void TextEnemy::setEnemyView(const QString &newEnemyView)
{
    enemyView = newEnemyView;
}

QPoint TextEnemy::getPos() const
{
    return pos;
}

int TextEnemy::getRegular_ani_interval() const
{
    return regular_ani_interval;
}

void TextEnemy::setRegular_ani_interval(int newRegular_ani_interval)
{
    regular_ani_interval = newRegular_ani_interval;
    animationTimer->setInterval(regular_ani_interval);
}

void TextEnemy::die()
{
    if(animationTimer->isActive())animationTimer->stop();

    enmeyDieTimer->start(die_ani_interval);
}

void TextEnemy::showAnimation()
{
    enemyView = regularImgs[regularImgIndex++];

    emit tellTextViewUpdate();


    if(regularImgIndex>= (int)regularImgs.size())
    {
        regularImgIndex = 0;
    }
}

void TextEnemy::setPosX(int x)
{
    pos.setX(x);

}

void TextEnemy::setPosY(int y)
{
    pos.setY(y);

}

void TextEnemy::setPos(int x, int y)
{
    pos.setX(x);
    pos.setY(y);

}

void TextEnemy::showDie()
{

    if(dieImgIndex >= (int)dieImgs.size())
    {
        dieImgIndex = 0;
        enmeyDieTimer->stop();

    }
    else
    {
        enemyView = dieImgs[dieImgIndex++];
        emit tellTextViewUpdate();
    }

}
