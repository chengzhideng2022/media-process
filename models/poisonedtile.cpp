#include "poisonedtile.h"

PoisonedTile::PoisonedTile(std::shared_ptr<Tile> tile, QObject *parent): QObject{parent}, tile{tile}
{

}

void PoisonedTile::addParent(std::shared_ptr<PEnemy> &parent)
{
    connect(parent.get(), &PEnemy::poisonLevelUpdated, this, &PoisonedTile::setPoisonLevel );
    poisonLevel+=parent->getPoisonLevel();
    parents.push_back(parent);
    emit paintPoisonTile(tile->getXPos(), tile->getYPos(), poisonLevel);

}

const std::shared_ptr<Tile> &PoisonedTile::getTile() const
{
    return tile;
}

void PoisonedTile::setTile(const std::shared_ptr<Tile> &newTile)
{
    tile = newTile;
}

int PoisonedTile::getPoisonLevel() const
{
    return poisonLevel;
}


void PoisonedTile::setPoisonLevel(int newlevel)
{
  if(poisonLevel-100+newlevel>0)
  {
      poisonLevel = poisonLevel-100+newlevel;
  }
  else
  {
      poisonLevel = 0;
  }

  emit paintPoisonTile(tile->getXPos(), tile->getYPos(), poisonLevel);

}
