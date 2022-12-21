#ifndef CHOSEMAPPAGE_H
#define CHOSEMAPPAGE_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class choseMapPage;
}

class choseMapPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit choseMapPage(QWidget *parent = nullptr);
    ~choseMapPage();

    Ui::choseMapPage* getui();
private:
    Ui::choseMapPage *ui;
    QString map;
    //Mainwindow *mp;
};

#endif // CHOSEMAPPAGE_H
