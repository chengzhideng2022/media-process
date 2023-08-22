#ifndef TEXTPENEMY_H
#define TEXTPENEMY_H

#include "textenemy.h"

class TextPEnemy : public TextEnemy
{
public:
    explicit TextPEnemy(int x, int y, QObject *parent = nullptr);

private:

    std::vector<QString> regularImgs = {
        "<td><h3 style=\"background-color: #42f360;\">(PEnemy)</h3></td>",
        "<td><h3 style=\"background-color: #f2f542;\">(PEnemy)</h3></td>",
    };

    std::vector<QString> dieImgs = {
        "<td><h3 style=\"background-color:#ffffff;\">\\DeadP/</h3></td>",
        "<td><h3 style=\"background-color:#ffe0de;\">-DeadP-</h3></td>",
        "<td><h3 style=\"background-color:#ffa9a3;\">/DeadP\\</h3></td>",
        "<td><h3 style=\"background-color:#ff756b;\">.DeadP.</h3></td>",
        "<td><h3 style=\"background-color:#ff483b;\">.DeadP.</h3></td>",
        "<td><h3 style=\"background-color:#ff1100;\">.DeadP.</h3></td>",

    };

public slots:
    void showDie() override;
    void showAnimation() override;
};

#endif // TEXTPENEMY_H
