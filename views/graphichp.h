#ifndef GRAPHICHP_H
#define GRAPHICHP_H

#include "graphicactor.h"


class GraphicHp: public GraphicActor
{
public:
    GraphicHp(int size,int x, int y, QObject *parent = nullptr);

    void showAnimation() override;
    void die() override;
    std::string toString();





    int getAni_interval() const;
    void setAni_interval(int newAni_interval);

private:
    std::unique_ptr<QTimer> animationTimer;

    int regularImgIndex{0};
    int ani_interval{500};

    std::vector<QString> regularImgs = {
        ":/pic/img/pill1.png",
        ":/pic/img/pill2.png",
        ":/pic/img/pill3.png",
        ":/pic/img/pill4.png",

        };
};

#endif // GRAPHICHP_H
