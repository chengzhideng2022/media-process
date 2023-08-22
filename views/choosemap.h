#ifndef CHOOSEMAP_H
#define CHOOSEMAP_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>


using namespace std;

class ChooseMap : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseMap(QWidget *parent = nullptr);



private:
    vector<QString> maps = {
        ":/pic/img/worldmap.png",
        ":/pic/img/worldmap4.png",
        ":/pic/img/maze1.png",
        ":/pic/img/maze2.png",
        ":/pic/img/maze3.png",
    };

    vector<std::unique_ptr<QPushButton>> mapButtons;

    int mapSize{200};

    std::unique_ptr<QBoxLayout> layOut;
    std::unique_ptr<QBoxLayout> hLayOut;
    std::unique_ptr<QLabel> label;


signals:
    void choose(QString map);




};

#endif // CHOOSEMAP_H
