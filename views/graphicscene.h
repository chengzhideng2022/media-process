#ifndef GRAPHICSCENE_H
#define GRAPHICSCENE_H

#include <QGraphicsPixmapItem>
#include "graphicsprot.h"
#include "graphicenemy.h"
#include <iostream>
#include <QGraphicsScene>
#include <world.h>
#include "models/gameworld.h"





class GraphicScene : public QGraphicsScene
{
public:
    GraphicScene(QString map, std::shared_ptr<GameWorld> world,QObject *parent = nullptr);



private:
    std::shared_ptr<GameWorld> world;
    QString map;
    QGraphicsPixmapItem mapItem;
    QPixmap pixMap;
    std::vector<std::shared_ptr<GraphicsProt>> prots;
    std::vector<std::shared_ptr<GraphicEnemy>> enemies;







public:
    void fillWorld() ;

    // QGraphicsScene interface
    const std::vector<std::shared_ptr<GraphicsProt> > &getProts() const;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // GRAPHICSCENE_H
