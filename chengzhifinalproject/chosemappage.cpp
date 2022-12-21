#include "chosemappage.h"
#include "ui_chosemappage.h"
#include "mainwindow.h"

choseMapPage::choseMapPage(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::choseMapPage)
{
    ui->setupUi(this);


    connect(this->ui->mapbutton1,&QPushButton::clicked,[=](){
        this->hide();
        map=":/img/worldmap.png";
        MainWindow *mp;
        mp = new MainWindow(nullptr,map);
         mp->setParent(nullptr);
        mp->show();
    });
    connect(this->ui->mapbutton2,&QPushButton::clicked,[=](){
        this->hide();
        map=":/img/worldmap4.png";
        MainWindow *mp;
        mp = new MainWindow(nullptr,map);
        mp->setParent(nullptr);
        mp->show();
    });
    connect(this->ui->mapbutton3,&QPushButton::clicked,[=](){
        this->hide();
        map=":/img/maze3.png";
        MainWindow *mp;
        mp = new MainWindow(nullptr,map);
        mp->setParent(nullptr);
        mp->show();
    });
    connect(this->ui->mapbutton4,&QPushButton::clicked,[=](){
        this->hide();
        map=":/img/maze2.png";
        MainWindow *mp;
        mp = new MainWindow(nullptr,map);
        mp->show();
    });
    connect(this->ui->mapbutton5,&QPushButton::clicked,[=](){
        this->hide();
        map=":/img/maze1.png";
        MainWindow *mp;
        mp = new MainWindow(nullptr,map);
        mp->setParent(nullptr);
        mp->show();
    });

}

choseMapPage::~choseMapPage()
{
    delete ui;
}
Ui::choseMapPage* choseMapPage::getui()
{
    return ui;
}
