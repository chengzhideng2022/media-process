#include "textpoisonedtile.h"

TextPoisonedTile::TextPoisonedTile(int x, int y, int poisonLevel, QObject *parent)
    : QObject{parent}, poisonLevel{poisonLevel}
{
    pos.setX(x);
    pos.setY(y);

}


void TextPoisonedTile::setPosX(int x)
{
    pos.setX(x);

}

void TextPoisonedTile::setPosY(int y)
{
    pos.setY(y);

}

void TextPoisonedTile::setPos(int x, int y)
{
    pos.setX(x);
    pos.setY(y);

}

QPoint TextPoisonedTile::getPos() const
{
    return pos;
}

int TextPoisonedTile::getPoisonLevel() const
{
    return poisonLevel;
}

void TextPoisonedTile::setPoisonLevel(int newPoisonLevel)
{
    poisonLevel = newPoisonLevel;
}
