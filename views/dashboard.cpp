#include "dashboard.h"


DashBoard::DashBoard(QWidget *parent)
    : QWidget{parent}
{
    layout = std::make_unique<QGridLayout>(this);
    layout->setAlignment(Qt::AlignCenter);



    dashBoardLabel = std::make_unique<QLabel>(this);
    dashBoardLabel->setText("<h1>DashBoard</h1>");
    dashBoardLabel->setFocusPolicy(Qt::NoFocus);
    QFont font("Arial", 10, QFont::Bold);
    dashBoardLabel->setFont(font);
    dashBoardLabel->setAlignment(Qt::AlignCenter);
    dashBoardLabel->setStyleSheet("border: 1px solid black;");

    gameViewLabel = std::make_unique<QLabel>(this);
    gameViewLabel->setText("<h1>View Settings</h1>");
    gameViewLabel->setFocusPolicy(Qt::NoFocus);
    gameViewLabel->setFont(font);
    gameViewLabel->setAlignment(Qt::AlignCenter);


    zoomIn = std::make_unique<QPushButton>("Zoom In + ", this);
    zoomIn->setFocusPolicy(Qt::NoFocus);
    zoomOut = std::make_unique<QPushButton>("Zoom Out - ", this);
    zoomOut->setFocusPolicy(Qt::NoFocus);

    textView = std::make_unique<QPushButton>("TextView", this);
    textView->setFocusPolicy(Qt::NoFocus);
    graphicsView = std::make_unique<QPushButton>("GraphicsView", this);
    graphicsView->setFocusPolicy(Qt::NoFocus);


    gameSettingLabel = std::make_unique<QLabel>(this);
    gameSettingLabel->setFocusPolicy(Qt::NoFocus);
    gameSettingLabel->setText("<h1>Game Settings</h1>");
    gameSettingLabel->setFont(font);
    gameSettingLabel->setAlignment(Qt::AlignCenter);


    addPlayer = std::make_unique<QPushButton>("addPlayer", this);
    addPlayer->setFocusPolicy(Qt::NoFocus);

    autoPlay = std::make_unique<QCheckBox>("Auto Play",this);
    autoPlay->setFocusPolicy(Qt::NoFocus);

    animationSpeed = std::make_unique<QComboBox>(this);
    animationSpeed->setFocusPolicy(Qt::NoFocus);
    animationSpeed->addItem("1");
    animationSpeed->addItem("2");
    animationSpeed->addItem("4");
    animationSpeed->addItem("8");
    animationSpeed->setCurrentIndex(0);



    heuristicsSliderLabel = std::make_unique<QLabel>(this);
    heuristicsSliderLabel->setFocusPolicy(Qt::NoFocus);
    heuristicsSliderLabel->setText("<h1>Heuristics Weight</h1>");
    QFont font2("Arial", 5, QFont::Bold);
    heuristicsSliderLabel->setFont(font2);
    heuristicsSliderLabel->setFixedHeight(20);

    heuristicsSlider =  std::make_unique<QSlider>(Qt::Horizontal, this);
    heuristicsSlider->setFocusPolicy(Qt::NoFocus);
    heuristicsSlider->setTickPosition(QSlider::TicksBothSides);
    heuristicsSlider->setTickInterval(10);
    heuristicsSlider->setSingleStep(5);
    heuristicsSlider->setFixedWidth(400);
    heuristicsSlider->setSliderPosition(50);


    pathFinder = std::make_unique<QPushButton>("Path Finder", this);
    pathFinder->setFocusPolicy(Qt::NoFocus);

    exit = std::make_unique<QPushButton>("Exit", this);
    exit->setFocusPolicy(Qt::NoFocus);


    save = std::make_unique<QPushButton>("Save", this);
    save->setFocusPolicy(Qt::NoFocus);

    load = std::make_unique<QPushButton>("Load", this);
    load->setFocusPolicy(Qt::NoFocus);


    layout->addWidget(dashBoardLabel.get(), 0, 0, 1, 3); //Label
    layout->addWidget(gameViewLabel.get(), 1, 0, 1, 3);//Label gameView

    layout->addWidget(textView.get(), 2 , 0);
    layout->addWidget(graphicsView.get(), 2 , 2);
    layout->addWidget(zoomIn.get(), 3 , 0);
    layout->addWidget(zoomOut.get(), 3 , 2);


    layout->addWidget(gameSettingLabel.get(), 4, 0, 1, 3); //Label gameSetting

    layout->addWidget(autoPlay.get(), 5 , 0);
    layout->addWidget(addPlayer.get(), 5 , 2);
    layout->addWidget(animationSpeed.get(), 6 , 0);
    layout->addWidget(pathFinder.get(), 6 , 2);

    layout->addWidget(heuristicsSliderLabel.get(), 7 , 0, 1 , 3);//Label heuristics
    layout->addWidget(heuristicsSlider.get(), 8 , 0, 1 , 3);

    layout->addWidget(exit.get(), 9 , 0);
    layout->addWidget(save.get(), 9 , 1);
    layout->addWidget(load.get(), 9 , 2);




    editerLabel = std::make_unique<QLabel>(this);

    editerLabel->setFocusPolicy(Qt::NoFocus);
    editerLabel->setText("Type your input here");
    editerLabel->setFont(font);
    editerLabel->setFixedHeight(20);

    textInput = std::make_shared<CommandEdit>(this);



    connect(textInput.get(), &CommandEdit::submitCommand, this, [=](QString command){
        emit upLoadCommand(command);
    });

    layout->addWidget(editerLabel.get(),10,0);

    layout->addWidget(textInput.get(),11,0,3,3);




    connect(zoomIn.get(), &QPushButton::clicked, this, [=] {emit zoomInGameWidget();});
    connect(zoomOut.get(), &QPushButton::clicked, this, [=] {emit zoomOutGameWidget();});

    connect(addPlayer.get(), &QPushButton::clicked, this, [=] {emit addPlayerToGameWidget();});
    connect(pathFinder.get(), &QPushButton::clicked, this, [=] {emit openPathFinder();});





    connect(exit.get(), &QPushButton::clicked, this, [=] {emit exitGame();});



    connect(autoPlay.get(), &QCheckBox::stateChanged, this ,[=](int state) {
            if (state == Qt::Checked) {
                emit autoPlayOn();
            } else {
                 emit autoPlayOff();
            }
        });


    connect(animationSpeed.get(), QOverload<int>::of(&QComboBox::currentIndexChanged), [&](int index) {
                emit changeAnimationSpeed(animationSpeed->itemText(index).toInt());
        });


    connect(heuristicsSlider.get(), &QSlider::valueChanged, this, [=](float newValue){
        emit changeHeuristicsWeight(newValue);
    });


    connect(textView.get(), &QPushButton::clicked, this, [=]{
        emit showTextView();
    });

    connect(graphicsView.get(), &QPushButton::clicked, this, [=]{
        emit showGraphicsView();
    });

    connect(exit.get(), &QPushButton::clicked, this, [=]{
        emit exitGame();
    });


}

const std::shared_ptr<CommandEdit> &DashBoard::getTextInput() const
{
    return textInput;
}

void DashBoard::mousePressEvent(QMouseEvent *event)
{
    textInput->clearFocus();

}


