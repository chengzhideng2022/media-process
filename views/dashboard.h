#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <qslider.h>
#include <QGridLayout>
#include "commandedit.h"



class DashBoard : public QWidget
{
    Q_OBJECT
public:
    explicit DashBoard(QWidget *parent = nullptr);


    const std::shared_ptr<CommandEdit> &getTextInput() const;

private:
    std::unique_ptr<QGridLayout> layout;

    std::unique_ptr<QLabel> dashBoardLabel;

    std::unique_ptr<QLabel> gameViewLabel;

    std::unique_ptr<QPushButton> zoomIn;
    std::unique_ptr<QPushButton> zoomOut;
    std::unique_ptr<QPushButton> textView;
    std::unique_ptr<QPushButton> graphicsView;

    std::unique_ptr<QLabel> gameSettingLabel;
    std::unique_ptr<QPushButton> addPlayer;
    std::unique_ptr<QCheckBox> autoPlay;
    std::unique_ptr<QComboBox> animationSpeed;

    std::unique_ptr<QLabel> heuristicsSliderLabel;
    std::unique_ptr<QSlider> heuristicsSlider;

    std::unique_ptr<QPushButton> pathFinder;

    std::unique_ptr<QPushButton> exit;
    std::unique_ptr<QPushButton> save;
    std::unique_ptr<QPushButton> load;


    std::unique_ptr<QLabel> editerLabel;


    std::shared_ptr<CommandEdit> textInput;








signals:
    void zoomInGameWidget();
    void zoomOutGameWidget();
    void addPlayerToGameWidget();
    void changeAnimationSpeed(int times);
    void openPathFinder();
    void exitGame();

    void autoPlayOn();
    void autoPlayOff();

    void changeHeuristicsWeight(float newValue);
    void showGraphicsView();
    void showTextView();
    void upLoadCommand(QString command);





public slots:



    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // DASHBOARD_H
