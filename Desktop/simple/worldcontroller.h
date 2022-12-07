#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

//#include "./viewers/GraphicsViewer.h"
#include "world.h"
#include "struct.h"
//#include "./controllers/WorldController.h"

#include <iostream>
#include <QObject>
#include <QMainWindow>
#include <tuple>

class LogicController;

using namespace std;

class WorldController : public QObject
{
    Q_OBJECT

    public:
        WorldController(QString map);

        int getHeight() const;
        int getWidth() const;

        bool isHealthPack(int x, int y, bool kill);
        bool isPoisined(int x, int y);
        shared_ptr<Tile> getHealthPack(int x, int y);
        shared_ptr<poisonedTile> getPoisonedTile(int x, int y);
        vector<shared_ptr<Tile>>  getTiles() const;
        const vector<shared_ptr<Enemy> > &getEnemies() const;
        const vector<shared_ptr<Tile> > &getHealthpacks() const;

        void makeWall(int x, int y);

        std::shared_ptr<Tile> getTile(int x, int y);

        bool checkpossible(int x, int y);
        std::vector<damage_struct> checksurroundings(int x, int y, char id);
        void killSurrounding(int x, int y);

        shared_ptr<Enemy> isEnemy(int x, int y, bool kill, bool fast);
        //shared_ptr<Enemy> isPEnemy(int x, int y);
        std::shared_ptr<Enemy> getEnemy(int x, int y);

        const std::vector<std::shared_ptr<Tile> > &getWalkedOnTiles() const;
        void setWalkedOnTiles(std::shared_ptr<Tile> newWalkedOnTiles);

        void poisonTilesAround(int x , int y, int spread, std::shared_ptr<PEnemy> parent);

        const std::vector<std::shared_ptr<poisonedTile> > &getPoisonedTiles() const;

        void addProt();

        std::shared_ptr<Protagonist> getProt(char id) const;
        int getProtListSize() const;

        QString getMapPath() const;

        void findFirstAvailable(char id);

        void deleteEnemy(int x, int y);

        void deletePsnTile(int x, int y);


        point getStart();
        point getExit();



        void createCustomEnemies();

        bool getGameStop() const;
        void setGameStop(bool newGameStop);

        char getActiveProtsAmount() const;


private:
        int spread = 2;
        std::shared_ptr<World> world;
        std::shared_ptr<World> initialWorld;
        std::vector<std::shared_ptr<Tile>> tiles;
        std::vector<combo> combos;
        std::vector<std::shared_ptr<Tile>> walkedOnTiles;
        int height;
        int width;
        point exit;
        point start;

        std::shared_ptr<Protagonist> prot;
        std::array<std::shared_ptr<Protagonist>,4> protList;
        std::vector<std::shared_ptr<Enemy>> enemies_temp;
        std::vector<std::shared_ptr<Enemy>> enemies;
        std::vector<std::shared_ptr<Tile>> healthpacks;
        std::vector<std::shared_ptr<poisonedTile>> poisonedTiles;
        bool gameStop = false;
        char activeProtsAmount = 1;
        QString map;

signals:
        void madeWall(int x, int y);
        void direction(int dir);
        void removeHP(int x, int y);
        void gameWon();
public slots:


};

#endif // WORLDCONTROLLER_H
