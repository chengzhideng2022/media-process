#ifndef GRAPHICENEMY_H
#define GRAPHICENEMY_H

#include "graphicactor.h"

class GraphicEnemy: public GraphicActor
{
public:
    GraphicEnemy(int size,int x, int y, QObject *parent = nullptr);



    int getRegular_ani_interval() const;
    void setRegular_ani_interval(int newRegular_ani_Interval);

    int getDie_ani_interval() const;
    void setDie_ani_interval(int newDie_ani_interval);

    int getAttack_ani_interval() const;
    void setAttack_ani_interval(int newAttack_ani_interval);

private:
    std::vector<QString> attackImgs = {

        ":/soul/img/soul/Soul_attack1.png",
        ":/soul/img/soul/Soul_attack2.png",
        ":/soul/img/soul/Soul_attack3.png",
        ":/soul/img/soul/Soul_attack4.png",
        ":/soul/img/soul/Soul_attack1.png",
        ":/soul/img/soul/Soul_attack2.png",
        ":/soul/img/soul/Soul_attack3.png",
        ":/soul/img/soul/Soul_attack4.png",
        ":/soul/img/soul/Soul_attack1.png",
        ":/soul/img/soul/Soul_attack2.png",
        ":/soul/img/soul/Soul_attack3.png",
        ":/soul/img/soul/Soul_attack4.png",

        };


    std::vector<QString> dieImgs = {
        ":/soul/img/soul/Soul_fly.png",
        ":/soul/img/soul/Soul_die1.png",
        ":/soul/img/soul/Soul_die2.png",
        ":/soul/img/soul/Soul_die3.png", //":/soul/img/soul/Soul_die4.png"


    };

    std::vector<QString> regularImgs = {
        ":/soul/img/soul/Soul1.png",
        ":/soul/img/soul/Soul2.png",
        ":/soul/img/soul/Soul3.png",
    };



protected:
    std::unique_ptr<QTimer> enmeyDieTimer;
    std::unique_ptr<QTimer> enmeyAttackTimer;
    std::unique_ptr<QTimer> animationTimer;

    int attackImgIndex{0};
    int dieImgIndex{0};
    int regularImgIndex{0};

    int regular_ani_interval{500};
    int die_ani_interval{30};
    int attack_ani_interval{100};


public slots:
     void die() override;
     virtual void attack() ;
     void showAnimation() override;


     virtual void showAttack();
     virtual void showDie();


};

#endif // GRAPHICENEMY_H
