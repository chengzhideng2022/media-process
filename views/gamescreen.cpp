#include "gamescreen.h"
#include "graphicgamewidget.h"
#include "models/gameworld.h"
#include "textgamewidget.h"

GameScreen::GameScreen(QWidget *parent)
    : QWidget{parent}
{
  this->setFocusPolicy(Qt::ClickFocus);

  instructions[0] = std::make_pair(QRegularExpression ("(up|u)\\s+(\\d+)"), QString("up protId"));
  instructions[1] = std::make_pair(QRegularExpression ("(right|r)\\s+(\\d+)"), QString("right protId"));
  instructions[2] = std::make_pair(QRegularExpression ("(left|l)\\s+(\\d+)"), QString("left protId"));
  instructions[3] = std::make_pair(QRegularExpression ("(down|d)\\s+(\\d+)"), QString("down protId"));
  instructions[4] = std::make_pair(QRegularExpression ("(goto|g)\\s+(\\d+)\\s+(\\d+)\\s+(\\d+)"), QString("goto protId x y"));
  instructions[5] = std::make_pair(QRegularExpression ("(attack|a)\\s+(\\d+)"), QString("attack protId"));
  instructions[6] = std::make_pair(QRegularExpression ("(take|t)\\s+(\\d+)"), QString("take protId"));
  instructions[7] = std::make_pair(QRegularExpression ("(help|h)"), QString("help"));
  instructions[8] = std::make_pair(QRegularExpression ("(addPlayer|add)"),QString("addPlayer"));
  instructions[9] = std::make_pair(QRegularExpression ("(zoomIn|In)"), QString("zoomIn"));
  instructions[10] = std::make_pair(QRegularExpression ("(zoomOut|Out)"), QString("zoomOut"));
  instructions[11] = std::make_pair(QRegularExpression ("(exit)"), QString("exit"));

}

void GameScreen::setUp(QString map)
{
    hLayout = std::make_unique<QHBoxLayout>(this);
    hLayout->setAlignment(Qt::AlignTop);
    world = worldFactory->createWorld(map);


    pathPlanner = std::make_unique<PathPlanner>(world);

    auto newTimer = std::make_shared<QTimer>();
    protMoveTimers.push_back(std::move(newTimer));

    connect(protMoveTimers[0].get(), &QTimer::timeout, this, [=]{
        nextStep(0);
    });

    paths.push_back(nullptr);

    gameWidgets.insert_or_assign(Type::Graphics, std::make_shared<GraphicGameWidget>(this)) ;

    gameWidgets.insert_or_assign(Type::Text, std::make_shared<TextGameWidget>(this)) ;


    dashBoard = std::make_unique<DashBoard>(this);

    connect(dashBoard.get(), &DashBoard::showGraphicsView, this, [=]{
        this->switchGameWidget(Type::Graphics);
    });
    connect(dashBoard.get(), &DashBoard::showTextView, this, [=]{
        this->switchGameWidget(Type::Text);
    });

    connect(dashBoard.get(), &DashBoard::exitGame, this, &GameScreen::exitCurrentGame);
    connect(dashBoard.get(), &DashBoard::addPlayerToGameWidget, this, &GameScreen::gameWidgetAddPlayer);
    connect(dashBoard.get(), &DashBoard::changeAnimationSpeed, this, &GameScreen::changeProtSpeed);
    connect(dashBoard.get(), &DashBoard::openPathFinder, this, [&]{
        toFindPath(0, world->getGoalPosition());
    });

    connect(dashBoard.get(), &DashBoard::changeHeuristicsWeight, this, [&](float newValue){
        pathPlanner->setHeuristicWeight(newValue);//(float)(100)
    });


    connect(dashBoard.get(), &DashBoard::autoPlayOn, this, [&]{
        autoPlay = true;
        autoplay();
    });


    connect(dashBoard.get(), &DashBoard::autoPlayOff, this, [&]{
        autoPlay = false;
    });

    connect(dashBoard.get(), &DashBoard::upLoadCommand, this, &GameScreen::processCommand);


    currentType = Type::Graphics;
    for(auto& gameWidget : gameWidgets)
    {
        gameWidget.second->setUpGameWidget(world, map);
        connect(this, &GameScreen::removeHpFromGameWidget, gameWidget.second.get(), &GameWidget::removeHpView);
        connect(this, &GameScreen::tellProtAttack, gameWidget.second.get(), &GameWidget::showProtAttack);

        connect(this, &GameScreen::tellProtUseHp, gameWidget.second.get(), &GameWidget::showProtUseHp);
        connect(this, &GameScreen::tellEnemyAttack, gameWidget.second.get(), &GameWidget::showEnemyAttack);
        connect(this, &GameScreen::tellGameWidgetPaint, gameWidget.second.get(), &GameWidget::paintPoisonedTile);
        connect(this, &GameScreen::tellProtDie, gameWidget.second.get(), &GameWidget::showProtDie);


        connect(this, &GameScreen::tellGameWidgetPosionedProt, gameWidget.second.get(), &GameWidget::toPoisonProt);
        connect(this, &GameScreen::tellGameWidgetWin, gameWidget.second.get(), &GameWidget::showGameWin);
        connect(this, &GameScreen::tellGameWidgetLose, gameWidget.second.get(), &GameWidget::showGameLose);
        connect(this, &GameScreen::tellGameWidgetAddPlayer, gameWidget.second.get(), &GameWidget::addPlayer);
        connect(this, &GameScreen::colorGameWidgetTile, gameWidget.second.get(), &GameWidget::colorTile);

        connect(gameWidget.second.get(), &::GameWidget::tellPathEndPos, this, &GameScreen::toFindPath);


        connect(dashBoard.get(), SIGNAL(zoomInGameWidget()), gameWidget.second.get(), SLOT(zoomIn()));
        connect(dashBoard.get(), SIGNAL(zoomOutGameWidget()), gameWidget.second.get(), SLOT(zoomOut()));
        connect(dashBoard.get(), &DashBoard::changeAnimationSpeed, gameWidget.second.get(), &GameWidget::changeAniSpeed);


        hLayout->addWidget(gameWidget.second.get());

        if(gameWidget.first==currentType)
        {
            gameWidget.second->show();
            gameWidget.second->setFocus();
            gameWidget.second->setActive(true);


        }
        else
        {
            gameWidget.second->hide();
            gameWidget.second->setActive(false);
        }

    }




     hLayout->addWidget(dashBoard.get());



}

void GameScreen::moveProt(int id,int x, int y)//Direction direction)
{

    if(world->getGameStop()) return;

    if(id>=0 && id<(int)world->getProtagonistes().size())
    {
        if(world->checkIsProtDead(id)) return;

        std::shared_ptr<Protagonist> prot = world->getProtagonistes().at(id);

        if(!world->positionAvaliable(x,y)) return;


        prot->setPos(x,y);


        if(world->isPoisoned(x,y))
        {
            if(world->getPoisonedTile(x,y)->getPoisonLevel()!=0)
            {
                emit tellGameWidgetPosionedProt(x,y);

            }
            world->protGainHealth(id, world->getPoisonTileHealthLose(x,y));
        }


        if(world->isHp(x,y))
        {
            emit tellProtUseHp(x,y);

            world->removeHp(x,y);
            emit removeHpFromGameWidget(x,y);
            world->protGainHealth(id, world->getHpHealthGain());

        }

        auto surroundEnemies = world->getSurroundALiveEnemies(x,y);

        if(!surroundEnemies.empty())
        {
            emit tellProtAttack(x,y);
        }
        else
        {
            //qDebug()<<-(world->getTile(x,y)->getValue());//*100.0*world->getEnergyConstant()*0.5;
            world->protGainEnergy(id, -(world->getTile(x,y)->getValue())*100.0*world->getEnergyConstant()*0.5);
        }


        for (auto& enemy : surroundEnemies)
       {
            emit tellEnemyAttack(enemy->getXPos(),enemy->getYPos());

            enemy->setDefeated(true);
            world->defeatOneEnemy();
            if(std::dynamic_pointer_cast<PEnemy>(enemy)) //if the enemy is PEnemy.
            {

                penemyPoisonTiles(std::dynamic_pointer_cast<PEnemy>(enemy));

                emit tellGameWidgetPosionedProt(x,y);


                world->protGainHealth(id, world->getPenemyHealthLose());

            }
            else
            {
                world->protGainHealth(id, world->getEnemyHealthLose());

            }

            world->protGainEnergy(id, world->getPenemyEnergyGain());

       }


       if(world->checkIsProtDead(id))
       {
           emit tellProtDie(x,y);
       }

       if(world->checkIsLose())
       {
           world->setLose(true);
           world->setWin(false);
           world->setGameStop(true);

           emit tellGameWidgetLose();
       }
       else if(world->isGoalState())
       {
           world->setWin(true);
           world->setLose(false);
           world->setGameStop(true);
           emit tellGameWidgetWin();
       }






    }

}

void GameScreen::penemyPoisonTiles(std::shared_ptr<PEnemy> penemy)
{
    penemy->setPoisonLevel(100);


    auto poisonedGroup = std::make_shared<PoisonedGroup>(penemy);

    world->addPoisonedGroup(poisonedGroup);

    auto needToPoisonedTiles = world->getSurroundTiles(penemy->getXPos(), penemy->getYPos());
    needToPoisonedTiles.push_back(world->getTile(penemy->getXPos(), penemy->getYPos()));

    for(auto& tile : needToPoisonedTiles)
   {
        auto poisonedTile = world->getPoisonedTile(tile->getXPos(),tile->getYPos());
        if(poisonedTile)
       {
            poisonedTile->addParent(penemy);
            emit penemy->poisonLevelUpdated(penemy->getPoisonLevel());

       }
        else
       {
            auto newPoisonedTile = std::make_shared<PoisonedTile>(tile);
            newPoisonedTile->addParent(penemy);
            world->addPoisonedTile(newPoisonedTile);
            connect(newPoisonedTile.get(),&PoisonedTile::paintPoisonTile, this, &GameScreen::paintPoisonTile);
            emit penemy->poisonLevelUpdated(penemy->getPoisonLevel());

       }


   }

   poisonedGroup->startTimer();

}

int GameScreen::getProtSpeed() const
{
    return protSpeed;
}

void GameScreen::setProtSpeed(int newProtSpeed)
{
    protSpeed = newProtSpeed;
}

bool GameScreen::getAutoPlay() const
{
    return autoPlay;
}

void GameScreen::setAutoPlay(bool newAutoPlay)
{
    autoPlay = newAutoPlay;
}

void GameScreen::switchGameWidget(Type type)
{
    if(currentType==type) return;
    if(gameWidgets.find(type)==gameWidgets.end()) return;

    gameWidgets[currentType]->setActive(false);
    gameWidgets[currentType]->hide();
    gameWidgets[type]->setActive(true);
    gameWidgets[type]->show();
    currentType = type;

}

void GameScreen::paintPoisonTile(int x, int y, int poisonLevel)
{
    emit tellGameWidgetPaint(x, y, poisonLevel);

}

void GameScreen::exitCurrentGame()
{
    emit returnToChooseMap();

}

void GameScreen::gameWidgetAddPlayer()
{
    world->addProt();


    auto newTimer = std::make_shared<QTimer>();
    protMoveTimers.push_back(std::move(newTimer));

    int id = world->getProtagonistes().size()-1;

    connect(protMoveTimers[id].get(), &QTimer::timeout, this, [=]{
        nextStep(id);
    });

    paths.push_back(nullptr);

    emit tellGameWidgetAddPlayer();

}

void GameScreen::nextStep(int id)
{
  if(paths[id]!=nullptr)
  {
      moveProt(id, paths[id]->at(paths[id]->size()-1).rx(), paths[id]->at(paths[id]->size()-1).ry());
      paths[id]->pop_back();

      if(paths[id]->empty())
      {
         paths[id] = nullptr;
         protMoveTimers[id]->stop();
         autoplay();
      }
  }

}

void GameScreen::changeProtSpeed(int times)
{
    if(times >= protSpeedTimes)
    {
        int div = times/protSpeedTimes;
        protSpeedTimes = times;
        protSpeed/=div;
    }
    else
    {
        int div = protSpeedTimes/times;
        protSpeedTimes = times;
        protSpeed*=div;
    }
    for(auto& timer : protMoveTimers)
    {
        timer->setInterval(protSpeed);
    }

}

void GameScreen::toFindPath(int id ,QPoint endPos)
{
   if(!world->positionAvaliable(endPos.rx(), endPos.ry()))
   {
       std::cout<<"not avaliable position to go"<<std::endl;
       return;
   }

   auto directions =  pathPlanner->findPath(world->getProtagonistes().at(id)->getXPos(), world->getProtagonistes().at(id)->getYPos(),
                          endPos.rx(), endPos.ry());

   if(!directions) return;

   for(auto iterator = directions->rbegin(); iterator!=directions->rend(); iterator++)
   {
       emit colorGameWidgetTile((*iterator).rx(), (*iterator).ry(),0,0,255);

   }

   paths[id] = std::move(directions);

   protMoveTimers[id]->start(protSpeed);



}

void GameScreen::autoplay()
{
 if(!autoPlay) return;

 if(!world->getEnemies().empty() && !world->getGameStop())
 {
     auto aliveEnemis = world->getAliveEnemies();
     auto enemy = pathPlanner->fineNearst(0, aliveEnemis);
     auto hp =  pathPlanner->fineNearst(0, world->getHealthPacks());

     float healthLose;

     if(std::dynamic_pointer_cast<PEnemy>(enemy))
     {

         healthLose =  world->getPenemyHealthLose();

     }
     else
     {

         healthLose = world->getEnemyHealthLose();

     }



     if(world->getProtagonistes().at(0)->getHealth() > (50-healthLose) || !hp)
     {
         std::cout<<world->getProtagonistes().at(0)->getHealth()<<std::endl;
         int xToGo;
         int yToGo;

         if(world->positionAvaliable(enemy->getXPos()-1, enemy->getYPos()))
         {
             xToGo = enemy->getXPos()-1;
             yToGo = enemy->getYPos();
         }
         else if(world->positionAvaliable(enemy->getXPos()+1, enemy->getYPos()))
         {
             xToGo = enemy->getXPos()+1;
             yToGo = enemy->getYPos();
         }
         else if(world->positionAvaliable(enemy->getXPos(), enemy->getYPos()-1))
         {
             xToGo = enemy->getXPos();
             yToGo = enemy->getYPos()-1;
         }
         else if(world->positionAvaliable(enemy->getXPos(), enemy->getYPos()+1))
         {
             xToGo = enemy->getXPos();
             yToGo = enemy->getYPos()+1;
         }

         toFindPath(0,QPoint(xToGo, yToGo));

     }

     else
     {

         toFindPath(0,QPoint(hp->getXPos(), hp->getYPos()));
     }
 }

}

void GameScreen::processCommand(QString command)
{
    int index{-1};
    QRegularExpressionMatch match;
    for (auto it = instructions.begin(); it != instructions.end(); ++it) {
        int key = it.key();
        const QRegularExpression &regex = it.value().first;
        match = regex.match(command);
        if (match.hasMatch()) {
            index = key;
            break;
        }
    }

    if(index==-1)
    {
        dashBoard->getTextInput()->setText("Invalid input");
        return;
    }

    dashBoard->getTextInput()->clear();
    int protIndex;
    int x;
    int y;


    switch(index)
    {
    case 0:
        protIndex = match.captured(2).toInt();
        if(protIndex>=(int)world->getProtagonistes().size()) break;
        x = world->getProtagonistes().at(protIndex)->getXPos();
        y = world->getProtagonistes().at(protIndex)->getYPos()-1;
        moveProt(protIndex, x, y);
        break;
    case 1:
        protIndex = match.captured(2).toInt();
        if(protIndex>=(int)world->getProtagonistes().size()) break;
        x = world->getProtagonistes().at(protIndex)->getXPos()+1;
        y = world->getProtagonistes().at(protIndex)->getYPos();
        moveProt(protIndex, x, y);
        break;
    case 2:
        protIndex = match.captured(2).toInt();
        if(protIndex>=(int)world->getProtagonistes().size()) break;
        x = world->getProtagonistes().at(protIndex)->getXPos()-1;
        y = world->getProtagonistes().at(protIndex)->getYPos();
        moveProt(protIndex, x, y);
        break;
    case 3:
        protIndex = match.captured(2).toInt();
        if(protIndex>=(int)world->getProtagonistes().size()) break;
        x = world->getProtagonistes().at(protIndex)->getXPos();
        y = world->getProtagonistes().at(protIndex)->getYPos()+1;
        moveProt(protIndex, x, y);
        break;
    case 4:
        protIndex = match.captured(2).toInt();
        if(protIndex>=(int)world->getProtagonistes().size()) break;
        x = match.captured(3).toInt();
        y = match.captured(4).toInt();
        toFindPath(protIndex, QPoint(x, y));
        break;
    case 5:
        protIndex = match.captured(2).toInt();
        if(protIndex>=(int)world->getProtagonistes().size()) break;
        attackNearest(protIndex);
        break;
    case 6:
        protIndex = match.captured(2).toInt();
        if(protIndex>=(int)world->getProtagonistes().size()) break;
        takeNearestHp(protIndex);
        break;
    case 7:
        showCommandList();
        break;
    case 8:
        gameWidgetAddPlayer();
        break;
    case 9:
        emit dashBoard->zoomInGameWidget();
        break;
    case 10:
        emit dashBoard->zoomOutGameWidget();
        break;
    case 11:
        exitCurrentGame();
        break;
    default:
        break;
    }




}


void GameScreen::showCommandList()
{

    QString text{"Command List:\n"};
    for (auto it = instructions.begin(); it != instructions.end(); ++it) {

        text+=it.value().second+"\n";

    }

    text+="Press Enter to submit";

    dashBoard->getTextInput()->setText(text);
}


void GameScreen::takeNearestHp(int id)
{
    if(id>=(int)world->getProtagonistes().size()) return;
    auto hp =  pathPlanner->fineNearst(id, world->getHealthPacks());
    if(!hp) return;
    toFindPath(id,QPoint(hp->getXPos(), hp->getYPos()));

}


void GameScreen::attackNearest(int id)
{
    if(id>=(int)world->getProtagonistes().size()) return;
    auto aliveEnemis = world->getAliveEnemies();
    auto enemy = pathPlanner->fineNearst(id, aliveEnemis);
    int xToGo;
    int yToGo;

    if(!enemy)
    {
        return;
    }

    if(world->positionAvaliable(enemy->getXPos()-1, enemy->getYPos()))
    {
        xToGo = enemy->getXPos()-1;
        yToGo = enemy->getYPos();
    }
    else if(world->positionAvaliable(enemy->getXPos()+1, enemy->getYPos()))
    {
        xToGo = enemy->getXPos()+1;
        yToGo = enemy->getYPos();
    }
    else if(world->positionAvaliable(enemy->getXPos(), enemy->getYPos()-1))
    {
        xToGo = enemy->getXPos();
        yToGo = enemy->getYPos()-1;
    }
    else if(world->positionAvaliable(enemy->getXPos(), enemy->getYPos()+1))
    {
        xToGo = enemy->getXPos();
        yToGo = enemy->getYPos()+1;
    }
    else
    {
        return;
    }

    toFindPath(id,QPoint(xToGo, yToGo));

}





void GameScreen::keyPressEvent(QKeyEvent *event)
{
        switch (event->key()) {

            case Qt::Key_Up:    moveProt(0, world->getProtagonistes().at(0)->getXPos(), world->getProtagonistes().at(0)->getYPos()-1);   break;
            case Qt::Key_Down:  moveProt(0, world->getProtagonistes().at(0)->getXPos(), world->getProtagonistes().at(0)->getYPos()+1);   break;
            case Qt::Key_Left:  moveProt(0, world->getProtagonistes().at(0)->getXPos()-1, world->getProtagonistes().at(0)->getYPos());   break;
            case Qt::Key_Right: moveProt(0, world->getProtagonistes().at(0)->getXPos()+1, world->getProtagonistes().at(0)->getYPos());   break;


            case Qt::Key_W:    moveProt(1, world->getProtagonistes().at(1)->getXPos(), world->getProtagonistes().at(1)->getYPos()-1);    break;
            case Qt::Key_S:    moveProt(1, world->getProtagonistes().at(1)->getXPos(), world->getProtagonistes().at(1)->getYPos()+1);    break;
            case Qt::Key_A:    moveProt(1, world->getProtagonistes().at(1)->getXPos()-1, world->getProtagonistes().at(1)->getYPos());    break;
            case Qt::Key_D:    moveProt(1, world->getProtagonistes().at(1)->getXPos()+1, world->getProtagonistes().at(1)->getYPos());    break;


        }

}
