#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "views/choosemap.h"
#include "views/gamescreen.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUp();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<ChooseMap> chooseMap;
    std::unique_ptr<GameScreen> gameScreen;



private slots:
    void openMap(QString map);
    void resetPage();


};
#endif // MAINWINDOW_H
