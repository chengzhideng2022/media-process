#ifndef TEXTGAMEWIDGET_H
#define TEXTGAMEWIDGET_H

#include "gamewidget.h"
#include <QTextBrowser>
#include <QWidget>
#include "textprot.h"
#include "textenemy.h"
#include "texthp.h"
#include <QBoxLayout>
#include "textpoisonedtile.h"

#include <QLabel>


struct ProtStateLabels{
    std::shared_ptr<QHBoxLayout> hlayout;
    std::shared_ptr<QLabel> healthBarLabel;
    std::shared_ptr<QLabel> energyBarLabel;
};

class TextGameWidget : public GameWidget
{
    Q_OBJECT
public:
    TextGameWidget(QWidget *parent);




    // GameWidget interface
public:
    void setUpGameWidget(std::shared_ptr<GameWorld> world, QString map) override;
    void updateGameWidget() override;
    std::optional<std::shared_ptr<TextHp>> getHpView(int x, int y);
    std::optional<std::shared_ptr<TextProt>> getProtView(int x, int y);
    std::optional<std::shared_ptr<TextEnemy>> getEnemyView(int x, int y);
    std::optional<std::shared_ptr<TextPoisonedTile>> getPoisonedTileView(int x, int y);
    bool isPoisonedTile(int x, int y);
    void drawWorld() override;
    void placeEnemies() override;
    void placeHealthPacks() override;
    void placeProts() override;
    void originalColorTile(int x, int y) override;
    void toPoisonProt(int x, int y) override;
    void addProtBars(int id) override;
    void updateHealthBar(int id, float value) override;
    void updateEnergyBar(int id, float value) override;


    const std::vector<std::shared_ptr<TextPoisonedTile> > &getPoisonedTiles() const;
    void setPoisonedTiles(const std::vector<std::shared_ptr<TextPoisonedTile> > &newPoisonedTiles);

    QString getPoisonedColor(int poisonLevel, QString normalTile);



public slots:
    void zoomIn() override;
    void zoomOut() override;
    void removeHpView(int x, int y) override;
    void showProtAttack(int x, int y) override;
    void showEnemyAttack(int x, int y) override;
    void showProtDie(int x, int y) override;
    void showProtUseHp(int x, int y) override;
    void paintPoisonedTile(int x, int y, int poisonLevel) override;
    void repaintGameWidget() override;
    void showGameWin() override;
    void showGameLose() override;
    void changeAniSpeed(int times) override;
    void addPlayer() override;
    void colorTile(int x, int y, int R, int G, int B) override;

private:
    std::unique_ptr<QBoxLayout> layout;
    std::unique_ptr<QTextBrowser> textBrowser{nullptr};
    QString worldContent{""};
    std::vector<std::shared_ptr<TextProt>> prots;
    std::vector<std::shared_ptr<TextEnemy>> enemies;
    std::vector<std::shared_ptr<TextHp>> hps;
    std::vector<std::shared_ptr<TextPoisonedTile>> poisonedTiles;
    bool gameStop{false};


    float viewWidth = 20;
    float viewHeight = 20;

    std::unordered_map<int, std::shared_ptr<ProtStateLabels>> protsLabels;



    void replaceTableCellContent(int x, int y, const QString &newContent);
    QString getNormalTileText(int x, int y);
    void calculateViewPos();
};

#endif // TEXTGAMEWIDGET_H
