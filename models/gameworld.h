#ifndef GAMEWORLD_H
#define GAMEWORLD_H


#include <world.h>
#include <QTimer>
#include <QObject>
#include "poisonedtile.h"



class PoisonedGroup

{

private:
    std::shared_ptr<PEnemy> pEnemy;
    std::shared_ptr<QTimer> poisonTimer = std::make_shared<QTimer>();

    int de_interval{1000};
    int de_value{30};

public:
    PoisonedGroup(const std::shared_ptr<PEnemy> &pEnemy);
    void startTimer();

};



class GameWorld
{

public:
    GameWorld() = default;
    void createGameWorld(QString map, std::unique_ptr<World> world);
    void addProt();


    std::vector<std::shared_ptr<Tile> > &getTiles();

    std::vector<std::shared_ptr<Enemy> > &getEnemies() ;

    std::vector<std::shared_ptr<Protagonist> > &getProtagonistes() ;

    std::vector<std::shared_ptr<Tile> > &getHealthPacks();


    bool positionAvaliable(int x, int y);

    std::shared_ptr<Tile> getTile(int x, int y);
    std::vector<std::shared_ptr<Tile>> getSurroundTiles(int x, int y);
    std::optional<std::shared_ptr<Enemy>> getEnemy(int x, int y);
    std::optional<std::shared_ptr<Tile>> getHp(int x, int y);
    std::vector<std::shared_ptr<Enemy>> getSurroundALiveEnemies(int x, int y);
    void removeHp(int x, int y);

    bool isEnemy(int x, int y);
    bool isProt(int x, int y);
    bool isWall(int x, int y);
    bool isHp(int x, int y);

    bool isPoisoned(int x, int y);
    std::shared_ptr<PoisonedTile> getPoisonedTile(int x, int y);

    int getRows() const;

    int getCols() const;

    bool getWin() const;
    void setWin(bool newWin);

    bool getLose() const;
    void setLose(bool newLose);

    void addPoisonedTile(std::shared_ptr<PoisonedTile>& poisonedTile);
    void addPoisonedGroup(std::shared_ptr<PoisonedGroup>& poisonedGroup);



    const std::vector<std::shared_ptr<PoisonedGroup> > &getPoisonedGroups() const;

    const std::vector<std::shared_ptr<PoisonedTile> > &getPoisonedTiles() const;

    virtual bool isGoalState();
    virtual bool checkIsLose();

    bool checkIsProtDead(int id);

    bool getGameStop() const;
    void setGameStop(bool newGameStop);
    bool enemyAllDefeated();

    void defeatOneEnemy();

    int getNumOfDefeatedEnemies() const;

    float getEnemyEnergyGain() const;
    void setEnemyEnergyGain(float newEnemyEnergyGain);

    float getPenemyEnergyGain() const;
    void setPenemyEnergyGain(float newPenemyEnergyGain);

    void protGainEnergy(int id, float energy);
    void protGainHealth(int id, float health);


    float getEnemyHealthLose() const;
    void setEnemyHealthLose(float newEnemyHealthLose);

    float getPenemyHealthLose() const;
    void setPenemyHealthLose(float newPenemyHealthLose);

    float getHpHealthGain() const;
    void setHpHealthGain(float newHpHealthGain);

    float getPoisonTileHealthLose(int x, int y);

    int getNumOfaliveProts() const;
    void setNumOfaliveProts(int newNumOfaliveProts);

    float getEnergyConstant() const;
    void setEnergyConstant(float newEnergyConstant);

    std::vector<std::shared_ptr<Tile> > getSuccessorTiles(int x, int y);
    void setGoalPosition(int x, int y);
    QPoint getGoalPosition() const;

    std::vector<std::shared_ptr<Enemy> > getAliveEnemies();
protected:
    QPoint goalPosition;
    std::vector<std::shared_ptr<Tile>> tiles;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Protagonist>> protagonistes;
    std::vector<std::shared_ptr<Tile>> healthPacks;
    std::vector<std::shared_ptr<PoisonedTile>> poisonedTiles;
    std::vector<std::shared_ptr<PoisonedGroup>> poisonedGroups;

    bool checkPositonInput(int x, int y);

    int rows;
    int cols;


    bool win{false};
    bool lose{false};
    bool gameStop{false};

    int numOfDefeatedEnemies{0};


    float enemyEnergyGain{100.0};
    float penemyEnergyGain{100.0};

    float enemyHealthLose{-15.0};
    float penemyHealthLose{-20.0};

    float hpHealthGain{50.0};

    int numOfaliveProts{0};

    float energyConstant;




};

#endif // GAMEWORLD_H
