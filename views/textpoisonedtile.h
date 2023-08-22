#ifndef TEXTPOISONEDTILE_H
#define TEXTPOISONEDTILE_H

#include <QObject>
#include <QPoint>

class TextPoisonedTile : public QObject
{
    Q_OBJECT
public:
    explicit TextPoisonedTile(int x, int y, int poisonLevel, QObject *parent = nullptr);


    void setPosX(int x);
    void setPosY(int y);
    void setPos(int x, int y);
    QPoint getPos() const;

    int getPoisonLevel() const;
    void setPoisonLevel(int newPoisonLevel);

private:
    QPoint pos;
    int poisonLevel;


signals:

};

#endif // TEXTPOISONEDTILE_H
