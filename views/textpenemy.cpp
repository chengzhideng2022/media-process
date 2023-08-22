#include "textpenemy.h"

TextPEnemy::TextPEnemy(int x, int y, QObject *parent)
    : TextEnemy{x, y, parent}
{
    enemyView = regularImgs[regularImgIndex];

}

void TextPEnemy::showDie()
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

void TextPEnemy::showAnimation()
{
    enemyView = regularImgs[regularImgIndex++];

    emit tellTextViewUpdate();


    if(regularImgIndex>= (int)regularImgs.size())
    {
        regularImgIndex = 0;
    }
}
