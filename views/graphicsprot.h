#ifndef GRAPHICSPROT_H
#define GRAPHICSPROT_H

#include "graphicactor.h"




class GraphicsProt : public GraphicActor
{
    Q_OBJECT
public:
    GraphicsProt(int size,int x, int y,QObject *parent = nullptr);









    int getRegular_ani_interval() const;
    void setRegular_ani_interval(int newRegular_ani_interval);

private:
    std::unique_ptr<QTimer> protAttackTimer;
    std::unique_ptr<QTimer> protDieTimer;
    std::unique_ptr<QTimer> protUseHealthPackTimer;
    std::unique_ptr<QTimer> protAnimationTimer;
    std::unique_ptr<QTimer> protPoisonedTimer;


    int attackImgIndex{0};
    int dieImgIndex{0};
    int useHPImgIndex{0};
    int aniImgIndex{0};


    int regular_ani_interval{500};
    int die_ani_interval{100};
    int attack_ani_interval{100};
    int useHp_interval{50};

    int poisoned_interval{1000};

    bool poisoned{false};

    QString poisonedProtImg{":/Stuck/img/Stuck/GavielG_Charge.png"};


    std::vector<QString> aniImgs = {
       ":/pic/img/Run11.png",
       ":/pic/img/Run21.png",
       ":/pic/img/Run31.png",
       ":/pic/img/Run41.png",

    };

    std::vector<QString> attackImgs = {
        ":/combo/img/combo/GavielG_Combo1.png",
        ":/combo/img/combo/GavielG_Combo2.png",
        ":/combo/img/combo/GavielG_Combo3.png",
        ":/combo/img/combo/GavielG_Combo4.png",
        ":/combo/img/combo/GavielG_Combo5.png",
        ":/combo/img/combo/GavielG_Combo6.png",
        ":/combo/img/combo/GavielG_Combo7.png",
        ":/combo/img/combo/GavielG_Combo8.png",
        ":/combo/img/combo/GavielG_Combo9.png"
    };


    std::vector<QString> dieImgs = {
        ":/Die/img/Die/GavielG_Die1.png",
        ":/Die/img/Die/GavielG_Die2.png",
        ":/Die/img/Die/GavielG_Die3.png",
        ":/Die/img/Die/GavielG_Die4.png",
        ":/Die/img/Die/GavielG_Die5.png"
    };

    std::vector<QString> useHPImgs = {
        ":/Buff/img/Buff/GavielG_Buff1.png",
        ":/Accumulate/img/Accumulate/Angel Feature1.png",
        ":/Accumulate/img/Accumulate/Angel Feature2.png",
        ":/Accumulate/img/Accumulate/GavielG_Accu1.png",
        ":/Accumulate/img/Accumulate/GavielG_Accu2.png",
        ":/Accumulate/img/Accumulate/GavielG_Accu3.png",
        ":/Accumulate/img/Accumulate/GavielG_Accu4.png",
        ":/Accumulate/img/Accumulate/GavielG_Accu5.png",
        ":/Accumulate/img/Accumulate/GavielG_Accu6.png",
        ":/Buff/img/Buff/GavielG_Buff1.png"
    };




    QPixmap regularPix;




    QPixmap &changeColorIfPoisoned(QPixmap &pix);
signals:
    void gameOver();
    void gameWin();




public slots:
    void showAttack();
    void showDie();
    void showUseHealthPack();
    void showPoisoned();
    void useHealthPack();

    void stopPoisoned();


    void die() override;
    void attack();
    void showAnimation() override;
};

#endif // GRAPHICSPROT_H
