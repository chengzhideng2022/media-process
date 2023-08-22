#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{

}

bool GameWidget::getActive() const
{
    return active;
}

void GameWidget::setActive(bool newActive)
{
    active = newActive;
}
