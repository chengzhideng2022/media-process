#ifndef TEXTHP_H
#define TEXTHP_H

#include <QObject>
#include <QTimer>
#include <QPoint>

class TextHp : public QObject
{
    Q_OBJECT
public:
    explicit TextHp(int x, int y, QObject *parent = nullptr);

    void showAnimation();

    int getAni_interval() const;
    void setAni_interval(int newAni_interval);

    void setPosX(int x);
    void setPosY(int y);
    void setPos(int x, int y);


    QPoint getPos() const;

    const QString &getHpView() const;

private:
    std::unique_ptr<QTimer> animationTimer;

    QString hpView;
    QPoint pos;


    int regularImgIndex{0};
    int ani_interval{500};

    std::vector<QString> regularImgs = {
        "<td><h3 style=\"background-color:#ffe0de;\">(ツ)♡</h3></td>",
        "<td><h3 style=\"background-color:#ffa9a3;\">(ツ)♡</h3></td>",
        "<td><h3 style=\"background-color:#ff756b;\">(ツ)♡</h3></td>",

        };

signals:
    void tellTextViewUpdate();

};

#endif // TEXTHP_H
