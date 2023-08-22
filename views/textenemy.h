#ifndef TEXTENEMY_H
#define TEXTENEMY_H

#include <QObject>
#include <QTimer>
#include <QPoint>

class TextEnemy : public QObject
{
    Q_OBJECT
public:
    explicit TextEnemy(int x, int y, QObject *parent = nullptr);


    const QString &getEnemyView() const;
    void setEnemyView(const QString &newEnemyView);

    QPoint getPos() const;

    int getRegular_ani_interval() const;
    void setRegular_ani_interval(int newRegular_ani_interval);

private:


    std::vector<QString> dieImgs = {
        "<td><h3 style=\"background-color:#ffffff;\">\\DeadE/</h3></td>",
        "<td><h3 style=\"background-color:#ffe0de;\">-DeadE-</h3></td>",
        "<td><h3 style=\"background-color:#ffa9a3;\">/DeadE\\</h3></td>",
        "<td><h3 style=\"background-color:#ff756b;\">.DeadE.</h3></td>",
        "<td><h3 style=\"background-color:#ff483b;\">.DeadE.</h3></td>",
        "<td><h3 style=\"background-color:#ff1100;\">.DeadE.</h3></td>",

    };

    std::vector<QString> regularImgs = {
        "<td><h3 style=\"background-color: #42f360;\">(Enemy)</h3></td>",
        "<td><h3 style=\"background-color: #f2f542;\">(Enemy)</h3></td>",
    };



protected:
    QString enemyView;
    QPoint pos;
    std::unique_ptr<QTimer> enmeyDieTimer;
    std::unique_ptr<QTimer> animationTimer;

    int dieImgIndex{0};
    int regularImgIndex{0};

    int regular_ani_interval{500};
    int die_ani_interval{30};


public slots:
     void die() ;
     virtual void showAnimation() ;
     virtual void showDie();

     void setPosX(int x);
     void setPosY(int y);
     void setPos(int x, int y);



signals:
     void tellTextViewUpdate();

};

#endif // TEXTENEMY_H
