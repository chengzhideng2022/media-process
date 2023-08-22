#include "graphicactor.h"

GraphicActor::GraphicActor(int size, int x, int y, QObject *parent)
    : QObject{parent}, size{size}, x{x}, y{y}
{


}

int GraphicActor::getX() const
{
    return x;
}

void GraphicActor::setX(int newX)
{
    x = newX;
}

int GraphicActor::getY() const
{
    return y;
}

void GraphicActor::setY(int newY)
{
    y = newY;
}
