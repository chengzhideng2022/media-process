#ifndef MYSCENE_H
#define MYSCENE_H

#include "myitem.h"
#include <QObject>
#include <QGraphicsScene>
class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);

signals:


private:
 myItem *item;
};

#endif // MYSCENE_H
