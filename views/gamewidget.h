#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "models/gameworld.h"
#include "gametype.h"


class GameWidget : public QWidget
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = nullptr);
    virtual void setUpGameWidget(std::shared_ptr<GameWorld> world, QString map) = 0;
    virtual void updateGameWidget() = 0;
    virtual void drawWorld() = 0;
    virtual void placeEnemies()= 0;
    virtual void placeHealthPacks() = 0;
    virtual void placeProts() = 0;
    virtual void originalColorTile(int x, int y) = 0;
    virtual void toPoisonProt(int x, int y) = 0;
    virtual void addProtBars(int id) = 0;
    virtual void updateHealthBar(int id, float value) = 0;
    virtual void updateEnergyBar(int id, float value) = 0;




    bool getActive() const;
    void setActive(bool newActive);

protected:
    bool active;
    int animationSpeedTimes{1};
    std::shared_ptr<GameWorld> gameWorld;

public slots:
    virtual void zoomIn()=0;
    virtual void zoomOut() =0;
    virtual void removeHpView(int x, int y) = 0;
    virtual void showProtAttack(int x, int y) = 0;
    virtual void showEnemyAttack(int x, int y) = 0;
    virtual void showProtDie(int x, int y) = 0;
    virtual void showProtUseHp(int x, int y) = 0;
    virtual void paintPoisonedTile(int x, int y, int poisonLevel)=0;
    virtual void repaintGameWidget()=0;
    virtual void showGameWin() = 0;
    virtual void showGameLose() = 0;
    virtual void changeAniSpeed(int times)=0;
    virtual void addPlayer() = 0;
    virtual void colorTile(int x, int y, int R, int G, int B) = 0;



signals:
    void tellPathEndPos(int id, QPoint pos);

};

#endif // GAMEWIDGET_H
