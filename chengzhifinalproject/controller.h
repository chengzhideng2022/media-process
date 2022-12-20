#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
class controller :public QGraphicsScene
{
    Q_OBJECT
public:
    controller();
    public slots:
   // void protDieSignal();
    /*
public slots:
void attack();
void attackTimeSignal();
void enemyDieSignal();
void PEnemyDieSignal();
void useHealthSignal();
void protDieSignal();
void showEffectOfPoisoningSignal();

void showEnemyAttackSignal();
void showPEnemyAttackSignal();
*/
private:
    QTimer *timer,*timerShowPoisodisapperEffect,*timerShowProtDie;
    QTimer *timersoul,*timerSkeleton,*timerUseHealth;
    QTimer *timerEnemyAttack,*timerPEnemyAttack;

};

#endif // CONTROLLER_H
