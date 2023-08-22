#include "textprot.h"
#include <QRegularExpression>

TextProt::TextProt(int x, int y,QObject *parent)
    : QObject{parent}
{
    setProtPos(x , y);
    protAttackTimer = std::make_unique<QTimer>(this);
    connect(protAttackTimer.get(), &QTimer::timeout, this , &TextProt::showAttack);

    protDieTimer = std::make_unique<QTimer>(this);
    connect(protDieTimer.get(), &QTimer::timeout, this , &TextProt::showDie);

    protUseHealthPackTimer = std::make_unique<QTimer>(this);
    connect(protUseHealthPackTimer.get(), &QTimer::timeout, this , &TextProt::showUseHealthPack);


    protAnimationTimer = std::make_unique<QTimer>(this);
    connect(protAnimationTimer.get(), &QTimer::timeout, this ,&TextProt::showAnimation);


    protPoisonedTimer = std::make_unique<QTimer>(this);
    connect(protPoisonedTimer.get(), &QTimer::timeout, this ,&TextProt::stopPoisoned);



    protView = aniImgs[aniImgIndex];


    protAnimationTimer->start(regular_ani_interval);



}

const QString &TextProt::getProtView() const
{
    return protView;
}

void TextProt::setProtView(const QString &newProtView)
{
    protView = newProtView;
}

QPoint TextProt::getViewPos() const
{
    return viewPos;
}

QPoint TextProt::getProtPos() const
{
    return protPos;
}

void TextProt::move(int x, int y)
{

   setProtPos(x ,y);
   emit tellTextViewUpdate();

}

void TextProt::showAttack()
{

    if(attackImgIndex >= (int)attackImgs.size())
    {
        protView = changeColorIfPoisoned(aniImgs[aniImgIndex]);


        attackImgIndex = 0;
        protAttackTimer->stop();
        protAnimationTimer->start(regular_ani_interval);
    }
    else
    {
        protView = changeColorIfPoisoned(attackImgs[attackImgIndex++]);

    }
    emit tellTextViewUpdate();

}

void TextProt::showDie()
{
    if(dieImgIndex >= (int)dieImgs.size())
    {
        dieImgIndex = 0;
        protDieTimer->stop();

    }
    else
    {

        protView = dieImgs[dieImgIndex++];
        emit tellTextViewUpdate();
    }

}

void TextProt::showUseHealthPack()
{

    if(useHPImgIndex >= (int)useHPImgs.size())
    {

        protView = changeColorIfPoisoned(aniImgs[aniImgIndex]);

        useHPImgIndex = 0;
        protUseHealthPackTimer->stop();
        protAnimationTimer->start(regular_ani_interval);

    }
    else
    {
        protView = changeColorIfPoisoned(useHPImgs[useHPImgIndex++]);

    }

    emit tellTextViewUpdate();


}

void TextProt::showPoisoned()
{


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

void TextProt::useHealthPack()
{
    if(protAnimationTimer->isActive()) protAnimationTimer->stop();
    if(protAttackTimer->isActive()) protAttackTimer->stop();

    protUseHealthPackTimer->start(useHp_interval);

}

void TextProt::stopPoisoned()
{
    poisoned = false;
    protPoisonedTimer->stop();

}

void TextProt::die()
{
    if(protAnimationTimer->isActive()) protAnimationTimer->stop();
    if(protUseHealthPackTimer->isActive()) protUseHealthPackTimer->stop();
    if(protAttackTimer->isActive()) protAttackTimer->stop();
     protDieTimer->start(die_ani_interval);

}

void TextProt::attack()
{
    if(protAnimationTimer->isActive()) protAnimationTimer->stop();
    if(protUseHealthPackTimer->isActive()) protUseHealthPackTimer->stop();
     protAttackTimer->start(attack_ani_interval);
}

void TextProt::showAnimation()
{


    protView = changeColorIfPoisoned(aniImgs[aniImgIndex++]);


    emit tellTextViewUpdate();


    if(aniImgIndex>= (int)aniImgs.size())
    {
        aniImgIndex = 0;
    }



}


QString TextProt::changeColorIfPoisoned(QString protView)
{
    if(poisoned)
    {
     QString purpleColorCode = "#800080";

     QRegularExpression colorRegex("#[0-9a-fA-F]{6}");

     protView = protView.replace(colorRegex, purpleColorCode);

    }
    return protView;
}

void TextProt::setProtPos(int x, int y)
{
   protPos.setX(x);
   protPos.setY(y);

}

void TextProt::setProtViewPos(int x, int y)
{
   viewPos.setX(x);
   viewPos.setY(y);
}

void TextProt::setProtViewPosX(int x)
{
    viewPos.setX(x);
}

void TextProt::setProtViewPosY(int y)
{
    viewPos.setY(y);
}

int TextProt::getRegular_ani_interval() const
{
    return regular_ani_interval;
}

void TextProt::setRegular_ani_interval(int newRegular_ani_interval)
{
    regular_ani_interval = newRegular_ani_interval;
    protAnimationTimer->setInterval(regular_ani_interval);
}
