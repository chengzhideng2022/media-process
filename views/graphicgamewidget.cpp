#include "graphicgamewidget.h"
#include "graphicpenemy.h"



GraphicGameWidget::GraphicGameWidget(QWidget *parent)
    : GameWidget{parent}
{

    layout = std::make_unique<QVBoxLayout>(this);

}

const std::unordered_map<int, std::shared_ptr<ProtStateBars> > &GraphicGameWidget::getProtsBars() const
{
    return protsBars;
}

const std::vector<std::shared_ptr<GraphicHp> > &GraphicGameWidget::getHps() const
{
    return hps;
}

void GraphicGameWidget::addProtBars(int id)
{

        auto protStateBars = std::make_shared<ProtStateBars>();
        protStateBars->energyBar = std::make_shared<QProgressBar>(this);
        protStateBars->healthBar = std::make_shared<QProgressBar>(this);
        protStateBars->energyBar->setStyleSheet("QProgressBar { border: 1px solid black; border-radius: 10px; }"
                                                "QProgressBar::chunk {background-color: blue;border-radius: 10px; }");
        protStateBars->healthBar->setStyleSheet("QProgressBar { background-color: white; }"
                                                "QProgressBar { border: 1px solid black; border-radius: 10px; }"
                                                "QProgressBar::sub-page { background-color: white; }"
                                                "QProgressBar::chunk { background-color: red; border-radius: 10px; }");

        protStateBars->healthBarLabel = std::make_shared<QLabel>(this);
        protStateBars->energyBarLabel = std::make_shared<QLabel>(this);

        QFont font("Arial", 10, QFont::Bold);
        protStateBars->healthBarLabel->setText("Prot "+QString::number(id)+" Health");
        protStateBars->healthBarLabel->setFont(font);
        protStateBars->healthBarLabel->setAlignment(Qt::AlignCenter);
        protStateBars->healthBarLabel->setFixedSize(200, 20);

        protStateBars->energyBarLabel->setText("Prot "+QString::number(id)+" Energy");
        protStateBars->energyBarLabel->setFont(font);
        protStateBars->energyBarLabel->setAlignment(Qt::AlignCenter);
        protStateBars->energyBarLabel->setFixedSize(200, 20);

        protStateBars->energyBar->setOrientation(Qt::Horizontal);
        protStateBars->healthBar->setOrientation(Qt::Horizontal);

        protStateBars->energyBar->setFixedWidth(700);
        protStateBars->energyBar->setFixedHeight(30);

        protStateBars->healthBar->setFixedWidth(700);
        protStateBars->healthBar->setFixedHeight(30);


        layout->addWidget(protStateBars->energyBarLabel.get(),0,Qt::AlignTop);
        layout->addWidget(protStateBars->energyBar.get(),0,Qt::AlignTop);
        layout->addWidget(protStateBars->healthBarLabel.get(),0,Qt::AlignTop);
        layout->addWidget(protStateBars->healthBar.get(),0,Qt::AlignTop);

        protsBars.insert_or_assign(id, protStateBars);


}

void GraphicGameWidget::updateHealthBar(int id, float value)
{
        auto pos = protsBars.find(id);
        if(pos != protsBars.end())
        {
             protsBars[id]->healthBarLabel->setText("Prot "+QString::number(id)+" Health "+QString::number(value));
             protsBars[id]->healthBar->setValue(value);

        }

}

void GraphicGameWidget::updateEnergyBar(int id, float value)
{
        auto pos = protsBars.find(id);
        if(pos != protsBars.end())
        {
            protsBars[id]->energyBarLabel->setText("Prot "+QString::number(id)+" Energy "+QString::number(value));
            protsBars[id]->energyBar->setValue(value);

        }

}

const std::vector<std::shared_ptr<GraphicEnemy> > &GraphicGameWidget::getEnemies() const
{
    return enemies;
}

const std::vector<std::shared_ptr<GraphicsProt> > &GraphicGameWidget::getProts() const
{
    return prots;
}



void GraphicGameWidget::setUpGameWidget(std::shared_ptr<GameWorld> world, QString map)
{
    gameWorld = world;

    worldImage = QImage(map);



    gameView = std::make_unique<GameView>(700,700,this);
    gameView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    connect(gameView.get(), &GameView::tellClickedPos, this, &GraphicGameWidget::on_clicked_gv);

    gameScene = std::make_unique<QGraphicsScene>(this);

    pixMap.convertFromImage(worldImage);
    worldImageItem.setPixmap(pixMap);
    worldImageItem.setScale(tile_size);
    gameScene->addItem(&worldImageItem);

    gameView->setScene(gameScene.get());
    layout->addWidget(gameView.get(),0,Qt::AlignTop);

    drawWorld();
    placeProts();
    placeEnemies();
    placeHealthPacks();



}

void GraphicGameWidget::updateGameWidget()
{

}

void GraphicGameWidget::drawWorld()
{
    for(auto &tile : gameWorld->getTiles())
    {
        int xpos = tile->getXPos();
        int ypos = tile->getYPos();
        float val = tile->getValue();

        if(tile->getValue()==std::numeric_limits<float>::infinity()){
            worldImage.setPixelColor(xpos, ypos, QColor(0,0,0));
        }else if(tile->getValue()==1)
        {
            worldImage.setPixelColor(xpos, ypos, QColor(
                                    255,
                                    255,
                                    255)
                                );
        }
        else{

            worldImage.setPixelColor(xpos, ypos, QColor(
                                    255*(1-val), //255*(5-val)
                                    255,
                                    255*(1-val))
                                );
        }

    }
    pixMap = QPixmap::fromImage(worldImage);
    worldImageItem.setPixmap(pixMap);

}

void GraphicGameWidget::placeEnemies()
{
    for(auto &enemyModel: gameWorld->getEnemies())
    {
        int numberOfparameter =(QString::fromStdString(enemyModel->serialize())).split(',').length()-1;

        if(numberOfparameter==3)
        {
           std::shared_ptr<GraphicEnemy> enemyView = std::make_shared<GraphicEnemy>(tile_size, enemyModel->getXPos(), enemyModel->getYPos());
           connect(enemyModel.get(), &Enemy::dead, enemyView.get(), &GraphicEnemy::die);
           enemyView->setPos(enemyModel->getXPos()*tile_size, enemyModel->getYPos()*tile_size);
           enemyView->setZValue(1);
           gameScene->addItem(enemyView.get());
           enemies.push_back(enemyView);
        }
        else
        {

            PEnemy*  penemyModel = static_cast<PEnemy*>(enemyModel.get());
            std::shared_ptr<GraphicEnemy> penemyView = std::make_shared<GraphicPEnemy>(tile_size, enemyModel->getXPos(), enemyModel->getYPos());
            connect( penemyModel, &Enemy::dead, static_cast<GraphicPEnemy*>(penemyView.get()), &GraphicPEnemy::die);
            penemyView->setPos(enemyModel->getXPos()*tile_size, enemyModel->getYPos()*tile_size);
            penemyView->setZValue(1);
            gameScene->addItem(penemyView.get());

            enemies.push_back(penemyView);

        }



    }


}

void GraphicGameWidget::placeHealthPacks()
{

    for( auto & hp : gameWorld->getHealthPacks())
    {
        std::shared_ptr<GraphicHp> hpView = std::make_shared<GraphicHp>(tile_size,hp->getXPos(), hp->getYPos());
        hpView->setPos(hp->getXPos()*tile_size, hp->getYPos()*tile_size);
        hpView->setZValue(1);
        gameScene->addItem(hpView.get());
        hps.push_back(hpView);

    }

}

void GraphicGameWidget::placeProts()
{
    int id = 0;
    for(auto &protModel: gameWorld->getProtagonistes())
    {
        std::shared_ptr<GraphicsProt> protView = std::make_shared<GraphicsProt>(tile_size,protModel->getXPos(), protModel->getYPos());
        protView->setPos(protModel->getXPos()*tile_size, protModel->getYPos()*tile_size);
        protView->setZValue(1);
        gameScene->addItem(protView.get());
        gameView->centerOn(protView.get());
        connect(protModel.get(), &Protagonist::posChanged, protView.get(), &GraphicsProt::move);
        connect(protView.get(), &GraphicsProt::setCenter, gameView.get(), [=]{
            gameView->centerOn(protView.get());
        });
        connect(protView.get(), &GraphicsProt::repaintView, this, &GraphicGameWidget::repaintGameWidget);

        prots.push_back(protView);

        addProtBars(id);
        connect(gameWorld->getProtagonistes().at(id).get(), &Protagonist::energyChanged, this, [=](int newValue){
            updateEnergyBar(id, newValue);
        });

        connect(gameWorld->getProtagonistes().at(id).get(), &Protagonist::healthChanged, this, [=](int newValue){
            updateHealthBar(id, newValue);
        });



        gameWorld->getProtagonistes().at(id)->setEnergy(100);
        gameWorld->getProtagonistes().at(id)->setHealth(100);


        id++;

    }

}



std::optional<std::shared_ptr<GraphicHp>> GraphicGameWidget::getHpView(int x, int y)
{

    for (auto& hp: hps)
    {
        if(hp->getX()==x && hp->getY()==y)
        {
            return hp;
        }
    }
    return  std::nullopt;

}

std::optional<std::shared_ptr<GraphicsProt>> GraphicGameWidget::getProtView(int x, int y)
{
    for (auto& prot: prots)
    {
        if(prot->getX()==x && prot->getY()==y)
        {
            return prot;
        }
    }
    return  std::nullopt;

}


std::optional<std::shared_ptr<GraphicEnemy>> GraphicGameWidget::getEnemyView(int x, int y)
{
    for (auto& enemy: enemies)
    {
        if(enemy->getX()==x && enemy->getY()==y)
        {
            return enemy;
        }
    }
    return  std::nullopt;

}

void GraphicGameWidget::removeHpView(int x, int y)
{
    auto hpItem = getHpView(x,y);
    if(hpItem)
    {
       hpItem.value()->setVisible(false);
       hps.erase(std::remove(hps.begin(), hps.end(), hpItem.value()),hps.end());
       hpItem.reset();
    }


}




void GraphicGameWidget::showProtAttack(int x, int y)
{
    auto protItem = getProtView(x,y);
    if(protItem)
    {
       protItem.value()->attack();

    }
}

void GraphicGameWidget::showProtUseHp(int x, int y)
{
    auto protItem = getProtView(x,y);
    if(protItem)
    {
       protItem.value()->useHealthPack();

    }

}

void GraphicGameWidget::showEnemyAttack(int x, int y)
{
    auto enemyItem = getEnemyView(x,y);
    if(enemyItem)
    {
       enemyItem.value()->attack();

    }

}

void GraphicGameWidget::paintPoisonedTile(int x, int y, int poisonLevel)
{
    if(poisonLevel>0)
    {
        if(poisonLevel<205)
        {
            colorTile(x,y,255-poisonLevel, 0, 255-poisonLevel);
        }
        else
        {
            colorTile(x,y,50, 0, 50);
        }

    }
    else
    {
        originalColorTile(x,y);
    }

}

void GraphicGameWidget::repaintGameWidget()
{
    gameView->update();
}

void GraphicGameWidget::toPoisonProt(int x, int y)
{
    auto protItem = getProtView(x,y);
    if(protItem)
    {
       protItem.value()->showPoisoned();

    }

}

void GraphicGameWidget::showGameWin()
{
    QImage image (":/Buff/img/Buff/GavielG_Buff1.png");

    QPixmap pix;
    pix.convertFromImage(image);
    LoseImageItem.setPixmap(pix.scaled(gameView->viewport()->size()));
    gameScene->addItem(&LoseImageItem);
    LoseImageItem.setPos(gameView->mapToScene(gameView->viewport()->rect()).boundingRect().topLeft());

    repaintGameWidget();
}

void GraphicGameWidget::showGameLose()
{
    QImage image (":/pic/img/gameover.png");
    QPixmap pix;
    pix.convertFromImage(image);
    LoseImageItem.setPixmap(pix.scaled(gameView->viewport()->size()));
    gameScene->addItem(&LoseImageItem);
    LoseImageItem.setPos(gameView->mapToScene(gameView->viewport()->rect()).boundingRect().topLeft());

    repaintGameWidget();

}

void GraphicGameWidget::showProtDie(int x, int y)
{
    auto protItem = getProtView(x,y);
    if(protItem)
    {
       protItem.value()->die();

    }

}

void GraphicGameWidget::changeAniSpeed(int times)
{

    if(times >= animationSpeedTimes)
    {
        int div = times/animationSpeedTimes;
        animationSpeedTimes = times;

        for(auto& prot : prots)
        {
            prot->setRegular_ani_interval(prot->getRegular_ani_interval()/div);
        }

        for(auto& enemy : enemies)
        {
            enemy->setRegular_ani_interval(enemy->getRegular_ani_interval()/div);
        }

        for(auto& hp : hps)
        {
            hp->setAni_interval(hp->getAni_interval()/div);
        }

    }
    else
    {
        int div = animationSpeedTimes/times;
        animationSpeedTimes = times;

        for(auto& prot : prots)
        {
            prot->setRegular_ani_interval(prot->getRegular_ani_interval()*div);
        }

        for(auto& enemy : enemies)
        {
            enemy->setRegular_ani_interval(enemy->getRegular_ani_interval()*div);
        }

        for(auto& hp : hps)
        {
            hp->setAni_interval(hp->getAni_interval()*div);
        }


    }




}

void GraphicGameWidget::addPlayer()
{

    int id = gameWorld->getProtagonistes().size()-1;

    std::shared_ptr<Protagonist> protModel = gameWorld->getProtagonistes().at(id);

    std::shared_ptr<GraphicsProt> protView = std::make_shared<GraphicsProt>(tile_size,protModel->getXPos(), protModel->getYPos());

    protView->setPos(protModel->getXPos()*tile_size, protModel->getYPos()*tile_size);
    protView->setZValue(1);
    gameScene->addItem(protView.get());
    gameView->centerOn(protView.get());
    connect(protModel.get(), &Protagonist::posChanged, protView.get(), &GraphicsProt::move);
    connect(protView.get(), &GraphicsProt::setCenter, gameView.get(), [=]{
        gameView->centerOn(protView.get());
    });
    connect(protView.get(), &GraphicsProt::repaintView, this, &GraphicGameWidget::repaintGameWidget);

    prots.push_back(std::move(protView));

    addProtBars(id);
    connect(gameWorld->getProtagonistes().at(id).get(), &Protagonist::energyChanged, this, [=](int newValue){
        updateEnergyBar(id, newValue);
    });

    connect(gameWorld->getProtagonistes().at(id).get(), &Protagonist::healthChanged, this, [=](int newValue){
        updateHealthBar(id, newValue);
    });


    gameWorld->getProtagonistes().at(id)->setEnergy(100);
    gameWorld->getProtagonistes().at(id)->setHealth(100);



}

void GraphicGameWidget::on_clicked_gv(QPointF pos)
{
    int x = std::floor(pos.rx()/(float)(tile_size));

    int y = std::floor(pos.ry()/(float)(tile_size));


    emit tellPathEndPos(0, QPoint(x,y)); //prot 0

}


void GraphicGameWidget::colorTile(int x, int y, int R, int G, int B)
{
    if(R>255){
        worldImage.setPixelColor(x,y,QColor(
                                ((worldImage.pixelColor(x,y).red()+R-255)/2)%255,
                                ((worldImage.pixelColor(x,y).green()+G-255)/2)%255,
                                ((worldImage.pixelColor(x,y).blue()+B-255)/2)%255
                                ));
    }else
    {
        worldImage.setPixelColor(x,y,QColor(R,G,B));
    }

    pixMap = QPixmap::fromImage(worldImage);
    worldImageItem.setPixmap(pixMap);

}

void GraphicGameWidget::originalColorTile(int x, int y)
{

    auto tile = gameWorld->getTile(x,y);
    float val = tile->getValue();

    if(tile->getValue()==std::numeric_limits<float>::infinity()){
        worldImage.setPixelColor(x, y, QColor(0,0,0));
    }else if(tile->getValue()==1)
    {
        worldImage.setPixelColor(x, y, QColor(
                                255,
                                255,
                                255)
                            );
    }
    else{

        worldImage.setPixelColor(x, y, QColor(
                                255*(1-val),
                                255,
                                255*(1-val))
                            );
    }

    pixMap = QPixmap::fromImage(worldImage);
    worldImageItem.setPixmap(pixMap);

}

void GraphicGameWidget::zoomIn()
{


    if(zoomFactor<maxZoomFactor)
    {
        zoomFactor*=2;
        gameView->scale(2, 2);
    }


}


void GraphicGameWidget::zoomOut()
{

    zoomFactor*=0.5;
    gameView->scale(0.5, 0.5);


}









