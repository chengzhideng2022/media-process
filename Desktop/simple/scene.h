#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>

class scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit scene(QObject *parent = nullptr);

signals:

};

#endif // SCENE_H
