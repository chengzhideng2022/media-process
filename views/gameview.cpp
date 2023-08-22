#include "gameview.h"
#include "qevent.h"

GameView::GameView(int width, int height,QWidget *parent) : QGraphicsView{parent},width{width}, height{height}
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setFixedHeight(height);
    this->setFixedWidth(width);
    this->setFocusPolicy( Qt::NoFocus );

}

int GameView::getWidth() const
{
    return width;
}

void GameView::setWidth(int newWidth)
{
    width = newWidth;
    this->setFixedWidth(width);
}

int GameView::getHeight() const
{
    return height;
}

void GameView::setHeight(int newHeight)
{
    height = newHeight;
    this->setFixedHeight(height);
}

void GameView::mousePressEvent(QMouseEvent *event)
{
    QPoint viewPos = event->pos();

    QPointF scenePos = mapToScene(viewPos);

    emit tellClickedPos(scenePos);

}



