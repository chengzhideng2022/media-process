#ifndef GRAPHICACTOR_H
#define GRAPHICACTOR_H
#include "qgraphicsscene.h"
#include <QGraphicsPixmapItem>
#include <world.h>
#include <QObject>
#include <QTimer>






class GraphicActor : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    GraphicActor(int size, int x, int y, QObject *parent = nullptr);


    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

protected:
    int size;
    int x;
    int y;


signals:
    void setCenter();
    void repaintView();


public slots:
    virtual void move(int x, int y)
    {
        this->x=x;
        this->y=y;
        setPos(x*size, y*size);
        emit repaintView();
        emit setCenter();
    }
    virtual void die() = 0;
    virtual void showAnimation() = 0;

};

#endif // GRAPHICACTOR_H
