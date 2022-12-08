#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>

class myscene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myscene(QObject *parent = nullptr);

signals:

};

#endif // MYSCENE_H
