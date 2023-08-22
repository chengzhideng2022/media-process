#ifndef TEXTPROT_H
#define TEXTPROT_H

#include <QObject>
#include <QTimer>
#include <QPoint>

class TextProt : public QObject
{
    Q_OBJECT
public:
    explicit TextProt(int x, int y, QObject *parent = nullptr);


    const QString &getProtView() const;
    void setProtView(const QString &newProtView);

    QPoint getViewPos() const;

    QPoint getProtPos() const;

    void setProtViewPosX(int x);
    void setProtViewPosY(int y);
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


    QPoint viewPos;
    QPoint protPos;
    QString protView;

    std::vector<QString> aniImgs = {
        "<td><h3 style=\"background-color:#4287f5;\">Prot</h3></td>",
        "<td><h3 style=\"background-color:#42f560;\">Prot</h3></td>",
        "<td><h3 style=\"background-color:#f2f542;\">Prot</h3></td>",

    };

    std::vector<QString> attackImgs = {
        "<td><h3 style=\"background-color:#ff0000;\">.Prot|</h3></td>",
         "<td><h3 style=\"background-color:#ff8a8a;\">.Prot/</h3></td>",
         "<td><h3 style=\"background-color:#ffdbdb;\">.Prot-</h3></td>",
        "<td><h3 style=\"background-color:#ffdbdb;\">.Prot_</h3></td>",
        "<td><h3 style=\"background-color:#ffdbdb;\">.Prot-</h3></td>",
        "<td><h3 style=\"background-color:#ffdbdb;\">.Prot/</h3></td>",
    };


    std::vector<QString> dieImgs = {
        "<td><h3 style=\"background-color:#ffffff;\">\\囧/</h3></td>",
        "<td><h3 style=\"background-color:#ffe0de;\">-囧-</h3></td>",
        "<td><h3 style=\"background-color:#ffa9a3;\">/囧\\</h3></td>",
        "<td><h3 style=\"background-color:#ff756b;\">.囧.</h3></td>",
        "<td><h3 style=\"background-color:#ff483b;\">.死.</h3></td>",
        "<td><h3 style=\"background-color:#ff1100;\">.死.</h3></td>",
    };

    std::vector<QString> useHPImgs = {
         "<td><h3 style=\"background-color:#d4d4d4;\">Prot</h3></td>",
        "<td><h3 style=\"background-color:#d4d4d4;\">\\Prot/</h3></td>",
        "<td><h3 style=\"background-color:#ffc400;\">|Prot|</h3></td>",
        "<td><h3 style=\"background-color:#b7ff00;\">/Prot\\</h3></td>",
        "<td><h3 style=\"background-color:#1aff00;\">|Prot|</h3></td>",
    };

    QString changeColorIfPoisoned(QString protView);


signals:
    void tellTextViewUpdate();


public slots:
    void move(int x, int y);
    void showAttack();
    void showDie();
    void showUseHealthPack();
    void showPoisoned();
    void useHealthPack();

    void stopPoisoned();


    void die() ;
    void attack();
    void showAnimation() ;
    void setProtPos(int x, int y);
    void setProtViewPos(int x, int y);



};

#endif // TEXTPROT_H
