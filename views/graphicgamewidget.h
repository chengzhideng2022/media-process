#ifndef GRAPHICGAMEWIDGET_H
#define GRAPHICGAMEWIDGET_H

#include <QWidget>
#include "views/gameview.h"
#include <QPushButton>
#include <QBoxLayout>
#include "gamewidget.h"


#include <QGraphicsPixmapItem>
#include "graphicsprot.h"
#include "graphicenemy.h"
#include "graphichp.h"
#include <iostream>
#include <QGraphicsScene>
#include <world.h>

#include <QProgressBar>
#include <QLabel>


struct ProtStateBars{
    std::shared_ptr<QLabel> healthBarLabel;
    std::shared_ptr<QProgressBar> healthBar;
    std::shared_ptr<QLabel> energyBarLabel;
    std::shared_ptr<QProgressBar> energyBar;
};

class GraphicGameWidget : public GameWidget
{
    Q_OBJECT
public:
    GraphicGameWidget(QWidget *parent = nullptr);




private:

    std::unique_ptr<QBoxLayout> layout;
    std::unique_ptr<QGraphicsScene> gameScene;
    std::unique_ptr<GameView> gameView;


    QImage worldImage;
    QGraphicsPixmapItem worldImageItem;
    QGraphicsPixmapItem LoseImageItem;

    QPixmap pixMap;

    std::vector<std::shared_ptr<GraphicsProt>> prots;
    std::vector<std::shared_ptr<GraphicEnemy>> enemies;
    std::vector<std::shared_ptr<GraphicHp>> hps;


    std::unordered_map<int, std::shared_ptr<ProtStateBars>> protsBars;


    int tile_size = 30;
    float zoomFactor = 1;
    float maxZoomFactor = 8;
    float minZoomFactor = 0.25;



signals:
    void reset();



public:
    void setUpGameWidget(std::shared_ptr<GameWorld> world, QString map) override;
    void updateGameWidget() override;
    void drawWorld() override;
    void placeEnemies() override;
    void placeHealthPacks() override;
    void placeProts() override;

    std::optional<std::shared_ptr<GraphicHp>> getHpView(int x, int y);
    std::optional<std::shared_ptr<GraphicsProt>> getProtView(int x, int y);
    std::optional<std::shared_ptr<GraphicEnemy>> getEnemyView(int x, int y);
    void originalColorTile(int x, int y) override;




    const std::vector<std::shared_ptr<GraphicsProt> > &getProts() const;

    const std::vector<std::shared_ptr<GraphicEnemy> > &getEnemies() const;

    const std::vector<std::shared_ptr<GraphicHp> > &getHps() const;


    void addProtBars(int id) override;
    void updateHealthBar(int id, float value) override;
    void updateEnergyBar(int id, float value) override;

    const std::unordered_map<int, std::shared_ptr<ProtStateBars> > &getProtsBars() const;

public slots:
    void zoomIn() override;
    void zoomOut() override;
    void removeHpView(int x, int y) override;
    void showProtAttack(int x, int y) override;
    void showProtUseHp(int x, int y) override;
    void showEnemyAttack(int x, int y) override;
    void paintPoisonedTile(int x, int y, int poisonLevel) override;
    void repaintGameWidget() override;
    void toPoisonProt(int x, int y) override;
    void showGameWin() override;
    void showGameLose() override;
    void showProtDie(int x, int y) override;
    void changeAniSpeed(int times) override;
    void addPlayer() override;
    void on_clicked_gv(QPointF pos);
    void colorTile(int x, int y, int R, int G, int B) override;
};

#endif // GRAPHICGAMEWIDGET_H
