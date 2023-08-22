#include "gameworld.h"
#include <iostream>


void GameWorld::createGameWorld(QString map, std::unique_ptr<World> world)
{
     std::cout<<world->getProtagonist()->getXPos()<<" "<<world->getProtagonist()->getYPos()<<std::endl;
    for ( auto &tile : world->getTiles())
    {

        std::unique_ptr<Tile> newTile = std::move(tile);
        float val = newTile->getValue();
        if(val != std::numeric_limits<float>::infinity()){
           if(val<1)  newTile->setValue(1-val); //
        }
        tiles.push_back( std::move(newTile) );
    }


    for ( auto &enemy : world->getEnemies())
    {
        std::unique_ptr<Enemy> newEnemy = std::move(enemy);
        enemies.push_back( std::move(newEnemy) );
    }

    protagonistes.push_back(world->getProtagonist());

    numOfaliveProts= protagonistes.size();

    for ( auto &healthPack : world->getHealthPacks())
    {
        std::unique_ptr<Tile> newHealthPack = std::move(healthPack);
        healthPacks.push_back( std::move(newHealthPack) );
    }


    rows = world->getRows();
    cols = world->getCols();


    energyConstant = 2.0*(float)enemies.size()/((float)tiles.size());


    if(map==":/pic/img/worldmap.png")
    {
        protagonistes.at(0)->setPos(0, 0);
        setGoalPosition(29, 29);

    }
    else if(map==":/pic/img/worldmap4.png")
    {
        protagonistes.at(0)->setPos(0, 45);
        setGoalPosition(999, 938);

    }
    else if(map==":/pic/img/maze1.png")
    {
        protagonistes.at(0)->setPos(5, 5);
        setGoalPosition(6, 6);

    }

    else if(map==":/pic/img/maze3.png")
    {

        protagonistes.at(0)->setPos(0,22);
        setGoalPosition(1200, 1205);

    }


}

void GameWorld::addProt()
{
    std::unique_ptr<Protagonist> newProt = std::make_unique<Protagonist>();

    for(auto& prot : protagonistes)
    {
        if(positionAvaliable(prot->getXPos()-1, prot->getYPos()))
        {
            newProt->setPos(prot->getXPos()-1, prot->getYPos());
            break;
        }
        else if(positionAvaliable(prot->getXPos(), prot->getYPos()-1))
        {
            newProt->setPos(prot->getXPos(), prot->getYPos()-1);
            break;
        }
        else if(positionAvaliable(prot->getXPos()+1, prot->getYPos()))
        {
            newProt->setPos(prot->getXPos()+1, prot->getYPos());
            break;
        }
        else if(positionAvaliable(prot->getXPos(), prot->getYPos()+1))
        {
            newProt->setPos(prot->getXPos(), prot->getYPos()+1);
            break;
        }

    }

    protagonistes.push_back(std::move(newProt));

}

std::vector<std::shared_ptr<Tile>> &GameWorld::getTiles()
{
    return tiles;
}

std::vector<std::shared_ptr<Enemy> > &GameWorld::getEnemies()
{
    return enemies;
}

std::vector<std::shared_ptr<Protagonist> > &GameWorld::getProtagonistes()
{
    return protagonistes;
}

std::vector<std::shared_ptr<Tile> > &GameWorld::getHealthPacks()
{
    return healthPacks;
}

bool GameWorld::positionAvaliable(int x, int y)
{

    if(!checkPositonInput(x,y)|| isWall(x,y) || isEnemy(x,y) || isProt(x,y)) return false;//|| isProt(x,y)

    return true;
}


std::optional<std::shared_ptr<Enemy>> GameWorld::getEnemy(int x, int y)
{
    for( auto& enemy : enemies )
    {
        if( enemy->getXPos() == x && enemy->getYPos() == y)
        {
            return enemy;
        }
    }
    return std::nullopt;
}

std::optional<std::shared_ptr<Tile>> GameWorld::getHp(int x, int y)
{
    for( auto& hp : healthPacks )
    {
        if( hp->getXPos() == x && hp->getYPos() == y )
        {
            return std::optional<std::shared_ptr<Tile>>{hp};
        }
    }
    return std::nullopt;

}

std::vector<std::shared_ptr<Enemy>> GameWorld::getAliveEnemies()
{
    std::vector<std::shared_ptr<Enemy>> alives;
    for(auto & enemy : enemies)
    {
        if(!enemy->getDefeated())
        {
            alives.push_back(enemy);
        }
    }
    return alives;
}

std::vector<std::shared_ptr<Enemy>> GameWorld::getSurroundALiveEnemies(int x, int y)
{
    std::vector<std::shared_ptr<Enemy>> surroundEnemies;
    if(auto enemy = getEnemy(x-1,y))
    {
        if(!enemy.value()->getDefeated())
        {
            surroundEnemies.push_back(enemy.value());
        }

    }
    if(auto enemy = getEnemy(x+1,y))
    {
        if(!enemy.value()->getDefeated())
        {
            surroundEnemies.push_back(enemy.value());
        }

    }
    if(auto enemy = getEnemy(x,y-1))
    {
        if(!enemy.value()->getDefeated())
        {
            surroundEnemies.push_back(enemy.value());
        }

    }
    if(auto enemy = getEnemy(x,y+1))
    {
        if(!enemy.value()->getDefeated())
        {
            surroundEnemies.push_back(enemy.value());
        }

    }

    return surroundEnemies;
}

void GameWorld::removeHp(int x, int y)
{
    auto hp = getHp(x,y);
    if(hp)
    {
       healthPacks.erase(std::remove(healthPacks.begin(), healthPacks.end(), hp.value()),healthPacks.end());
       hp.reset();
    }

}

bool GameWorld::isEnemy(int x, int y)
{
  for(auto& enemy : enemies)
  {
      if(enemy->getXPos()==x && enemy->getYPos()==y)
      {
          return true;
      }
  }
  return false;
}

bool GameWorld::isProt(int x, int y)
{
    for(auto& prot : protagonistes)
    {
        if(prot->getXPos()==x && prot->getYPos()==y)
        {
            return true;
        }
    }
    return false;
}

bool GameWorld::isWall(int x, int y)
{
    if(getTile(x,y))
    {
        if(getTile(x,y)->getValue()==std::numeric_limits<float>::infinity())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;

}

bool GameWorld::isHp(int x, int y)
{
    for(auto& hp : healthPacks)
    {
        if(hp->getXPos()==x && hp->getYPos()==y)
        {
            return true;
        }
    }
    return false;

}

bool GameWorld::isPoisoned(int x, int y)
{
    for(auto& poisonedTile : poisonedTiles)
    {
        if(poisonedTile->getTile()->getXPos()==x && poisonedTile->getTile()->getYPos()==y)
        {
            return true;
        }
    }
    return false;

}

std::shared_ptr<PoisonedTile> GameWorld::getPoisonedTile(int x, int y)
{
    for(auto& poisonedTile : poisonedTiles)
    {
        if(poisonedTile->getTile()->getXPos()==x && poisonedTile->getTile()->getYPos()==y)
        {
            return poisonedTile;
        }
    }
    return nullptr;

}

std::shared_ptr<Tile> GameWorld::getTile(int x, int y)
{

    if(!checkPositonInput(x,y)) return nullptr;

    return tiles.at(y*cols+x);

}

std::vector<std::shared_ptr<Tile>> GameWorld::getSurroundTiles(int x, int y)
{
    std::vector<std::shared_ptr<Tile>> tiles;
    if(!isWall(x-1,y-1) && getTile(x-1, y-1)) tiles.push_back(getTile(x-1, y-1));
    if(!isWall(x,y-1) && getTile(x, y-1)) tiles.push_back(getTile(x, y-1));
    if(!isWall(x+1,y-1) && getTile(x+1, y-1)) tiles.push_back(getTile(x+1, y-1));
    if(!isWall(x-1,y) && getTile(x-1, y)) tiles.push_back(getTile(x-1, y));
    if(!isWall(x+1,y) && getTile(x+1, y)) tiles.push_back(getTile(x+1, y));
    if(!isWall(x-1,y+1) && getTile(x-1, y+1)) tiles.push_back(getTile(x-1, y+1));
    if(!isWall(x,y+1) && getTile(x, y+1)) tiles.push_back(getTile(x, y+1));
    if(!isWall(x+1,y+1) && getTile(x+1, y+1)) tiles.push_back(getTile(x+1, y+1));

    return tiles;

}


std::vector<std::shared_ptr<Tile>> GameWorld::getSuccessorTiles(int x, int y)
{
    std::vector<std::shared_ptr<Tile>> tiles;

    if(positionAvaliable(x,y-1)) tiles.push_back(getTile(x, y-1));

    if(positionAvaliable(x-1,y)) tiles.push_back(getTile(x-1, y));
    if(positionAvaliable(x+1,y)) tiles.push_back(getTile(x+1, y));

    if(positionAvaliable(x,y+1)) tiles.push_back(getTile(x, y+1));

    return tiles;

}

void GameWorld::setGoalPosition(int x, int y)
{
  goalPosition.setX(x);
  goalPosition.setY(y);
}

QPoint GameWorld::getGoalPosition() const
{
    return goalPosition;
}



int GameWorld::getRows() const
{
    return rows;
}

int GameWorld::getCols() const
{
    return cols;
}



bool GameWorld::checkPositonInput(int x, int y)
{
    if(x<0 || y<0) return false;

    if(x>=cols || y>=rows) return false;

    return true;

}

float GameWorld::getEnergyConstant() const
{
    return energyConstant;
}

void GameWorld::setEnergyConstant(float newEnergyConstant)
{
    energyConstant = newEnergyConstant;
}

int GameWorld::getNumOfaliveProts() const
{
    return numOfaliveProts;
}

void GameWorld::setNumOfaliveProts(int newNumOfaliveProts)
{
    numOfaliveProts = newNumOfaliveProts;
}

float GameWorld::getHpHealthGain() const
{
    return hpHealthGain;
}

void GameWorld::setHpHealthGain(float newHpHealthGain)
{
    hpHealthGain = newHpHealthGain;
}

float GameWorld::getPoisonTileHealthLose(int x, int y)
{
   return -(getPoisonedTile(x,y)->getPoisonLevel()/10.0);

}

float GameWorld::getPenemyHealthLose() const
{
    return penemyHealthLose;
}

void GameWorld::setPenemyHealthLose(float newPenemyHealthLose)
{
    penemyHealthLose = newPenemyHealthLose;
}

float GameWorld::getEnemyHealthLose() const
{
    return enemyHealthLose;
}

void GameWorld::setEnemyHealthLose(float newEnemyHealthLose)
{
    enemyHealthLose = newEnemyHealthLose;
}

float GameWorld::getPenemyEnergyGain() const
{
    return penemyEnergyGain;
}

void GameWorld::setPenemyEnergyGain(float newPenemyEnergyGain)
{
    penemyEnergyGain = newPenemyEnergyGain;
}

void GameWorld::protGainEnergy(int id, float energy)
{
    if(id >=0 && id<(int)protagonistes.size() )
    {
        if(energy+protagonistes.at(id)->getEnergy()>100.0f)
        {
            protagonistes.at(id)->setEnergy(100.0f);
        }
        else if(energy+protagonistes.at(id)->getEnergy()<0.0f)
        {
            protagonistes.at(id)->setEnergy(0.0f);

        }
        else
        {
            protagonistes.at(id)->setEnergy(energy+protagonistes.at(id)->getEnergy());
        }

    }

}

void GameWorld::protGainHealth(int id, float health)
{
    if(id >=0 && id<(int)protagonistes.size() )
    {
        if(health+protagonistes.at(id)->getHealth()>100.0f)
        {
            protagonistes.at(id)->setHealth(100.0f);
        }
        else if(health+protagonistes.at(id)->getHealth()<0.0f)
        {
            protagonistes.at(id)->setHealth(0.0f);


        }
        else
        {
            protagonistes.at(id)->setHealth(health+protagonistes.at(id)->getHealth());
        }
    }

}

float GameWorld::getEnemyEnergyGain() const
{
    return enemyEnergyGain;
}

void GameWorld::setEnemyEnergyGain(float newEnemyEnergyGain)
{
    enemyEnergyGain = newEnemyEnergyGain;
}

int GameWorld::getNumOfDefeatedEnemies() const
{
    return numOfDefeatedEnemies;
}

bool GameWorld::getGameStop() const
{
    return gameStop;
}

void GameWorld::setGameStop(bool newGameStop)
{
    gameStop = newGameStop;
}

bool GameWorld::enemyAllDefeated()
{
    for( auto& enemy : enemies)
    {
        if (!enemy->getDefeated())
        {
            return false;
        }
    }

    return true;

    //return numOfDefeatedEnemies==(int)enemies.size();

}

void GameWorld::defeatOneEnemy()
{
    numOfDefeatedEnemies++;
}

bool GameWorld::getLose() const
{
    return lose;
}

void GameWorld::setLose(bool newLose)
{
    lose = newLose;
}

void GameWorld::addPoisonedTile(std::shared_ptr<PoisonedTile> &poisonedTile)
{
  if(poisonedTile)
  {
      poisonedTiles.push_back(poisonedTile);
  }
}

void GameWorld::addPoisonedGroup(std::shared_ptr<PoisonedGroup> &poisonedGroup)
{
    if(poisonedGroup)
    {
        poisonedGroups.push_back(poisonedGroup);
    }

}

const std::vector<std::shared_ptr<PoisonedGroup> > &GameWorld::getPoisonedGroups() const
{
    return poisonedGroups;
}

const std::vector<std::shared_ptr<PoisonedTile> > &GameWorld::getPoisonedTiles() const
{
    return poisonedTiles;
}

bool GameWorld::isGoalState()
{
    return enemyAllDefeated();

}

bool GameWorld::checkIsLose()
{

    for (int i = 0; i<(int)protagonistes.size(); i++)
    {
        if(!checkIsProtDead(i))
        {
            return false;
        }

    }
    return true;
}

bool GameWorld::checkIsProtDead(int id)
{

   if(protagonistes.at(id)->getEnergy()<=0 || protagonistes.at(id)->getHealth()<=0)
   {
       return true;
   }
   else
   {
       return false;
   }

}

bool GameWorld::getWin() const
{
    return win;
}

void GameWorld::setWin(bool newWin)
{
    win = newWin;
}



PoisonedGroup::PoisonedGroup(const std::shared_ptr<PEnemy> &pEnemy) : pEnemy(pEnemy)
{
    QObject::connect(poisonTimer.get(), &QTimer::timeout, pEnemy.get(), [=]{
        if(pEnemy->getPoisonLevel()-de_value>0)
        {
            pEnemy->setPoisonLevel(pEnemy->getPoisonLevel()-de_value);
        }
        else
        {
            pEnemy->setPoisonLevel(0);
            poisonTimer->stop();
        }
        emit pEnemy->poisonLevelUpdated(pEnemy->getPoisonLevel());

    });
}

void PoisonedGroup::startTimer()
{
    poisonTimer->start(de_interval);

}


