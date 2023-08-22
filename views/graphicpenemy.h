#ifndef GRAPHICPENEMY_H
#define GRAPHICPENEMY_H

#include "graphicenemy.h"

class GraphicPEnemy: public GraphicEnemy
{
public:
    GraphicPEnemy(int size,int x, int y, QObject *parent = nullptr);


private:

    std::vector<QString> attackImgs = {

        ":/skeleto/img/skeleto/Skeleton_Attack1.png",
        ":/skeleto/img/skeleto/Skeleton_Attack2.png",
        ":/skeleto/img/skeleto/Skeleton_Attack3.png",
        ":/skeleto/img/skeleto/Skeleton_Attack4.png",
        ":/skeleto/img/skeleto/Skeleton_Attack1.png",
        ":/skeleto/img/skeleto/Skeleton_Attack2.png",
        ":/skeleto/img/skeleto/Skeleton_Attack3.png",
        ":/skeleto/img/skeleto/Skeleton_Attack4.png",
        ":/skeleto/img/skeleto/Skeleton_Attack1.png",
        ":/skeleto/img/skeleto/Skeleton_Attack2.png",
        ":/skeleto/img/skeleto/Skeleton_Attack3.png",
        ":/skeleto/img/skeleto/Skeleton_Attack4.png",

        };


    std::vector<QString> dieImgs = {
        ":/skeleto/img/skeleto/Skeleton_fly.png",
        ":/skeleto/img/skeleto/Skeleton_die1.png",
        ":/skeleto/img/skeleto/Skeleton_die2.png",
        ":/skeleto/img/skeleto/Skeleton_die3.png",
        ":/skeleto/img/skeleto/Skeleton_die4.png",
    };

    std::vector<QString> regularImgs = {
        ":/skeleto/img/skeleto/Skeleton_Idle1.png",
        ":/skeleto/img/skeleto/Skeleton_Idle2.png",
        ":/skeleto/img/skeleto/Skeleton_Idle3.png",
        ":/skeleto/img/skeleto/Skeleton_Idle4.png",
    };


public slots:
     void die() override;
     void attack() override;
     void showAttack() override;
     void showDie() override;
     void showAnimation() override;


     //void showPoisoning(int poisonLevel);
     //void showPoisonDisappear();
};

#endif // GRAPHICPENEMY_H
