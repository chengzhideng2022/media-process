#ifndef POISONEDTILE_H
#define POISONEDTILE_H

#include <QObject>
#include <world.h>


class PoisonedTile : public QObject
{
    Q_OBJECT
public:
    PoisonedTile(std::shared_ptr<Tile> tile, QObject *parent = nullptr);
    void addParent(std::shared_ptr<PEnemy>& parent);


    const std::shared_ptr<Tile> &getTile() const;
    void setTile(const std::shared_ptr<Tile> &newTile);

    int getPoisonLevel() const;

private:
    int poisonLevel{0};
    std::shared_ptr<Tile> tile;
    std::vector<std::shared_ptr<PEnemy>> parents;



public slots:
    void setPoisonLevel(int newlevel);

signals:
    void paintPoisonTile(int x, int y, int poisonLevel);


};

#endif // POISONEDTILE_H
