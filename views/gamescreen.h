#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include "worldfactory.h"
#include "gamewidget.h"
#include "gametype.h"
#include <map>
#include <QKeyEvent>
#include "dashboard.h"
#include "pathplanner.h"

class GameScreen : public QWidget
{
    Q_OBJECT
public:
    GameScreen(QWidget *parent = nullptr);
    void setUp(QString map);

    void moveProt(int id, int x, int y);
    void penemyPoisonTiles(std::shared_ptr<PEnemy> penemy);





    int getProtSpeed() const;
    void setProtSpeed(int newProtSpeed);

    bool getAutoPlay() const;
    void setAutoPlay(bool newAutoPlay);

    void attackNearest(int id);
    void takeNearestHp(int id);
private:
     std::unique_ptr<WorldFactory> worldFactory = std::make_unique<WorldFactory>();
     std::shared_ptr<GameWorld> world;
     std::unique_ptr<PathPlanner> pathPlanner;

     int protSpeed{100};

     QMap<int, std::pair<QRegularExpression, QString>> instructions;




     Type currentType;

     std::unordered_map<Type, std::shared_ptr<GameWidget>> gameWidgets;
     std::unique_ptr<DashBoard> dashBoard;

     std::unique_ptr<QBoxLayout> hLayout;


     std::vector<std::shared_ptr<std::vector<QPoint>>> paths;
     std::vector<std::shared_ptr<QTimer>> protMoveTimers;

     int protSpeedTimes{1};

     bool autoPlay{false};






signals:
    void removeHpFromGameWidget(int x, int y);
    void tellProtAttack(int x , int y);
    void tellProtUseHp(int x , int y);
    void tellProtDie(int x, int y);
    void tellEnemyAttack(int x , int y);
    void tellGameWidgetPaint(int x, int y, int poisonLevel);
    void tellGameWidgetPosionedProt(int x, int y);
    void tellGameWidgetWin();
    void tellGameWidgetLose();
    void returnToChooseMap();
    void tellGameWidgetAddPlayer();
    void colorGameWidgetTile(int x, int y, int R, int G, int B);





public slots:
     void switchGameWidget(Type type);
     void paintPoisonTile(int x, int y, int poisonLevel);
     void exitCurrentGame();
     void gameWidgetAddPlayer();
     void nextStep(int id);
     void changeProtSpeed(int times);

     void toFindPath(int id, QPoint endPos);

     void autoplay();
     void processCommand(QString command);

     void showCommandList();
protected:
     void keyPressEvent(QKeyEvent *event) override;
};

#endif // GAMESCREEN_H
