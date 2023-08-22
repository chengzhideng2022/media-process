#include "texthp.h"

TextHp::TextHp(int x, int y, QObject *parent)
    : QObject{parent}
{

    pos.setX(x);
    pos.setY(y);

    animationTimer = std::make_unique<QTimer>(this);
    connect(animationTimer.get(), &QTimer::timeout, this ,&TextHp::showAnimation);




    hpView = regularImgs[regularImgIndex];

    animationTimer->start(ani_interval);

}

void TextHp::showAnimation()
{
    hpView = regularImgs[regularImgIndex++];

    emit tellTextViewUpdate();


    if(regularImgIndex>= (int)regularImgs.size())
    {
        regularImgIndex = 0;
    }

}

int TextHp::getAni_interval() const
{
    return ani_interval;
}

void TextHp::setAni_interval(int newAni_interval)
{
    ani_interval = newAni_interval;
    animationTimer->setInterval(ani_interval);
}


void TextHp::setPosX(int x)
{
    pos.setX(x);

}

void TextHp::setPosY(int y)
{
    pos.setY(y);

}

void TextHp::setPos(int x, int y)
{
    pos.setX(x);
    pos.setY(y);

}

QPoint TextHp::getPos() const
{
    return pos;
}

const QString &TextHp::getHpView() const
{
    return hpView;
}
