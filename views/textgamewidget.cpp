#include "textgamewidget.h"
#include <QTextTable>
#include "textpenemy.h"


TextGameWidget::TextGameWidget(QWidget *parent): GameWidget{parent}
{
    layout = std::make_unique<QVBoxLayout>(this);

}

void TextGameWidget::setUpGameWidget(std::shared_ptr<GameWorld> world, QString map)
{
    gameWorld = world;
    textBrowser = std::make_unique<QTextBrowser>();
    textBrowser->setMaximumHeight(2000);
    textBrowser->setMaximumWidth(2000);
    textBrowser->setFixedWidth(1000);

    textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    layout->addWidget(textBrowser.get());

    placeProts();
    placeEnemies();
    placeHealthPacks();

    drawWorld();

}

void TextGameWidget::updateGameWidget()
{


    if(gameStop) return;

    worldContent.clear();
    worldContent =  "<style>"
                       "table { border-collapse: collapse; }"
                       "td { border: 1px dashed black; width: 30px; height: 30px; text-align: center;}"
                    "</style>";

        auto& prot = prots.at(0);

        calculateViewPos();

        worldContent.append("<table>");
        for (int i = prot->getViewPos().ry(); i< prot->getViewPos().ry() + viewHeight; i++)
        {
            worldContent+="<tr>";
            for (int j = prot->getViewPos().rx(); j< prot->getViewPos().rx() + viewWidth; j++)
            {

                if(gameWorld->isProt(j,i))
                {
                    worldContent+=getProtView(j,i).value()->getProtView();

                }
                else if(gameWorld->isEnemy(j,i))
                {
                    worldContent+=getEnemyView(j,i).value()->getEnemyView();

                }
                else if(gameWorld->isHp(j,i))
                {

                    worldContent+=getHpView(j,i).value()->getHpView();
                }
                else
                {
                    auto tile = getPoisonedTileView(j,i);
                    if(tile)
                    {
                        worldContent+=getPoisonedColor(tile.value()->getPoisonLevel(), getNormalTileText(j,i));

                    }
                    else
                    {
                        worldContent+="<td>"+getNormalTileText(j,i)+"</td>";
                    }

                }

        }

            worldContent+="</tr>";

     }

    textBrowser->setHtml(worldContent);
}


QString TextGameWidget::getPoisonedColor(int poisonLevel, QString normalTile) {


    if (poisonLevel > 80) {
        QString bgColor = "#2E0854";
        return QString("<td style=\"background-color: %1;\">%2</td>").arg(bgColor, normalTile);
    } else if (poisonLevel >= 40) {
        QString bgColor = "#800080";
        return QString("<td style=\"background-color: %1;\">%2</td>").arg(bgColor, normalTile);
    } else if(poisonLevel >0){
        QString bgColor = "#DA70D6";
        return QString("<td style=\"background-color: %1;\">%2</td>").arg(bgColor, normalTile);
    }
    else
    {
        return "<td>"+normalTile+"</td>";
    }

}

std::optional<std::shared_ptr<TextHp> > TextGameWidget::getHpView(int x, int y)
{
    for (auto& hp: hps)
    {
        if(hp->getPos().rx()==x && hp->getPos().ry()==y)
        {
            return hp;
        }
    }
    return  std::nullopt;



}

std::optional<std::shared_ptr<TextProt> > TextGameWidget::getProtView(int x, int y)
{
    for (auto& prot: prots)
    {
        if(prot->getProtPos().rx()==x && prot->getProtPos().ry()==y)
        {
            return prot;
        }
    }
    return  std::nullopt;

}

std::optional<std::shared_ptr<TextEnemy>> TextGameWidget::getEnemyView(int x, int y)
{
    for (auto& enemy: enemies)
    {
        if(enemy->getPos().rx()==x && enemy->getPos().ry()==y)
        {
            return enemy;
        }
    }
    return  std::nullopt;

}

std::optional<std::shared_ptr<TextPoisonedTile> > TextGameWidget::getPoisonedTileView(int x, int y)
{
    for (auto& tile: poisonedTiles)
    {
        if(tile->getPos().rx()==x && tile->getPos().ry()==y)
        {
            return tile;
        }
    }
    return  std::nullopt;

}

bool TextGameWidget::isPoisonedTile(int x, int y)
{
    for (auto& tile: poisonedTiles)
    {
        if(tile->getPos().rx()==x && tile->getPos().ry()==y)
        {
            return true;

        }
    }
    return  false;

}

void TextGameWidget::drawWorld()
{
    updateGameWidget();
}


QString TextGameWidget::getNormalTileText(int x, int y)
{

    float value = gameWorld->getTile(x,y)->getValue();
    if(value==std::numeric_limits<float>::infinity())
    {
       return (" XXX ");
    }
    else if(100*value>75)
    {
       return (" ... ");
    }
    else if(100*value>50) return (" ,,, ");
    else if(100*value>25) return (" _-_ ");
    else return (" //\\ ");
}



void TextGameWidget::calculateViewPos()
{
    int id =0 ;
    for (auto & prot : prots)
    {
        prot->setProtViewPos(0,0);
        std::shared_ptr<Protagonist> protModel = gameWorld->getProtagonistes().at(id);

        if(prot->getProtPos().rx() - ceil(viewWidth/2.0) < 0) prot->setProtViewPosX(0);
        else if (prot->getProtPos().rx() + round(viewWidth/2.0) > gameWorld->getCols()) prot->setProtViewPosX(gameWorld->getCols() - viewWidth);
        else prot->setProtViewPosX(prot->getProtPos().rx() - ceil(viewWidth/2.0));

        if(prot->getProtPos().ry() - ceil(viewHeight/2.0) < 0) prot->setProtViewPosY(0);
        else if (prot->getProtPos().ry() + round(viewHeight/2.0) > gameWorld->getRows())
            prot->setProtViewPosY(gameWorld->getRows() - viewHeight) ;
        else
            prot->setProtViewPosY(prot->getProtPos().ry() - ceil(viewHeight/2.0));

        id++;

    }

}

void TextGameWidget::placeEnemies()
{
    for(auto &enemyModel: gameWorld->getEnemies())
    {
        int numberOfparameter =(QString::fromStdString(enemyModel->serialize())).split(',').length()-1;


        if(numberOfparameter==3)
        {
           std::shared_ptr<TextEnemy> enemyView = std::make_shared<TextEnemy>(enemyModel->getXPos(), enemyModel->getYPos());
           connect(enemyModel.get(), &Enemy::dead, enemyView.get(), &TextEnemy::die);

           enemies.push_back(enemyView);
        }
        else
        {

            PEnemy*  penemyModel = static_cast<PEnemy*>(enemyModel.get());
            std::shared_ptr<TextEnemy> penemyView = std::make_shared<TextPEnemy>(enemyModel->getXPos(), enemyModel->getYPos());
            connect( penemyModel, &Enemy::dead, static_cast<TextPEnemy*>(penemyView.get()), &TextPEnemy::die);

            enemies.push_back(penemyView);

        }

    }


}

void TextGameWidget::placeHealthPacks()
{
    for( auto & hp : gameWorld->getHealthPacks())
    {
        std::shared_ptr<TextHp> hpView = std::make_shared<TextHp>(hp->getXPos(), hp->getYPos());
        hps.push_back(hpView);

    }

}

void TextGameWidget::placeProts()
{
    int id = 0;
    for(auto &protModel: gameWorld->getProtagonistes())
    {
        std::shared_ptr<TextProt> protView = std::make_shared<TextProt>(protModel->getXPos(), protModel->getYPos());

        connect(protModel.get(), &Protagonist::posChanged, protView.get(), &TextProt::move);
        connect(protView.get(), &TextProt::tellTextViewUpdate, this, &TextGameWidget::updateGameWidget);

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



void TextGameWidget::colorTile(int x, int y, int R, int G, int B)
{


}

void TextGameWidget::originalColorTile(int x, int y)
{



}

void TextGameWidget::toPoisonProt(int x, int y)
{
    auto protItem = getProtView(x,y);
    if(protItem)
    {
       protItem.value()->showPoisoned();

    }

}

void TextGameWidget::addProtBars(int id)
{
    auto protStateLabels = std::make_shared<ProtStateLabels>();


    protStateLabels->healthBarLabel = std::make_shared<QLabel>(this);
    protStateLabels->energyBarLabel = std::make_shared<QLabel>(this);
    protStateLabels->hlayout = std::make_shared<QHBoxLayout>(this);
    protStateLabels->hlayout->setAlignment(Qt::AlignCenter);

    QFont font("Arial", 20, QFont::Bold);
    protStateLabels->healthBarLabel->setText("Prot "+QString::number(id)+" Health");
    protStateLabels->healthBarLabel->setFont(font);
    protStateLabels->healthBarLabel->setAlignment(Qt::AlignCenter);
    protStateLabels->healthBarLabel->setFixedSize(300, 100);

    protStateLabels->energyBarLabel->setText("Prot "+QString::number(id)+" Energy");
    protStateLabels->energyBarLabel->setFont(font);
    protStateLabels->energyBarLabel->setAlignment(Qt::AlignCenter);
    protStateLabels->energyBarLabel->setFixedSize(300, 100);


    protStateLabels->hlayout->addWidget(protStateLabels->energyBarLabel.get(),0,Qt::AlignTop);

    protStateLabels->hlayout->addWidget(protStateLabels->healthBarLabel.get(),0,Qt::AlignTop);

    layout->addLayout(protStateLabels->hlayout.get());

    protsLabels.insert_or_assign(id, protStateLabels);

}

void TextGameWidget::updateHealthBar(int id, float value)
{
    auto pos = protsLabels.find(id);
    if(pos != protsLabels.end())
    {
         protsLabels[id]->healthBarLabel->setText("Prot "+QString::number(id)+" Health "+QString::number(value));

    }

}

void TextGameWidget::updateEnergyBar(int id, float value)
{

    auto pos = protsLabels.find(id);
    if(pos != protsLabels.end())
    {
         protsLabels[id]->energyBarLabel->setText("Prot "+QString::number(id)+" Energy "+QString::number(value));

    }


}

void TextGameWidget::zoomIn()
{

}

void TextGameWidget::zoomOut()
{

}

void TextGameWidget::removeHpView(int x, int y)
{

}

void TextGameWidget::showProtAttack(int x, int y)
{
    auto protItem = getProtView(x,y);
    if(protItem)
    {
       protItem.value()->attack();

    }

}

void TextGameWidget::showEnemyAttack(int x, int y)
{

}

void TextGameWidget::showProtDie(int x, int y)
{
    auto protItem = getProtView(x,y);
    if(protItem)
    {
       protItem.value()->die();

    }

}

void TextGameWidget::showProtUseHp(int x, int y)
{
    auto prot = getProtView(x,y);
    if(prot)
    {
       prot.value()->useHealthPack();

    }

}

void TextGameWidget::paintPoisonedTile(int x, int y, int poisonLevel)
{

    if(poisonLevel>0)
    {

        if(!isPoisonedTile(x,y))
        {
            poisonedTiles.push_back(std::make_shared<TextPoisonedTile>(x,y, poisonLevel));
            updateGameWidget();
        }
        else
        {
            getPoisonedTileView(x,y).value()->setPoisonLevel(poisonLevel);

        }

        updateGameWidget();

    }
    else
    {
        if(!isPoisonedTile(x,y))
        {
            return;
        }
        else
        {
            getPoisonedTileView(x,y).value()->setPoisonLevel(0);
            updateGameWidget();

        }
    }

}

void TextGameWidget::repaintGameWidget()
{

}

void TextGameWidget::showGameWin()
{
    textBrowser->setHtml("<h1>YOU WON!</h1>");
    gameStop = true;
    textBrowser->setDisabled(true);

}

void TextGameWidget::showGameLose()
{
    textBrowser->setHtml("<h1>YOU LOSE!</h1>");
    gameStop = true;
    textBrowser->setDisabled(true);

}

void TextGameWidget::changeAniSpeed(int times)
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

void TextGameWidget::addPlayer()
{
    int id = gameWorld->getProtagonistes().size()-1;

    std::shared_ptr<Protagonist> protModel = gameWorld->getProtagonistes().at(id);

    std::shared_ptr<TextProt> protView = std::make_shared<TextProt>(protModel->getXPos(), protModel->getYPos());

    connect(protModel.get(), &Protagonist::posChanged, protView.get(), &TextProt::move);

    prots.push_back(std::move(protView));

    addProtBars(id);
    connect(gameWorld->getProtagonistes().at(id).get(), &Protagonist::energyChanged, this, [=](int newValue){
        updateEnergyBar(id, newValue);
    });

    connect(gameWorld->getProtagonistes().at(id).get(), &Protagonist::healthChanged, this, [=](int newValue){
        updateHealthBar(id, newValue);
    });


    updateGameWidget();


    gameWorld->getProtagonistes().at(id)->setEnergy(100);
    gameWorld->getProtagonistes().at(id)->setHealth(100);

}

const std::vector<std::shared_ptr<TextPoisonedTile> > &TextGameWidget::getPoisonedTiles() const
{
    return poisonedTiles;
}

void TextGameWidget::setPoisonedTiles(const std::vector<std::shared_ptr<TextPoisonedTile> > &newPoisonedTiles)
{
    poisonedTiles = newPoisonedTiles;
}

void TextGameWidget::replaceTableCellContent(int x, int y, const QString &newContent)
{

      QTextDocument doc;
      doc.setHtml(worldContent);

        QList<QTextTable *> tables = doc.rootFrame()->findChildren<QTextTable *>();
        QTextTable *table = nullptr;
        if (!tables.isEmpty()) {
            table = tables.first();
            if (y < table->rows() && x < table->columns()) {
                QTextTableCell cell = table->cellAt(y, x);
                QTextCursor cursor = cell.firstCursorPosition();
                cursor.select(QTextCursor::BlockUnderCursor);
                cursor.removeSelectedText();
                cursor.insertHtml(newContent);
            }
        }

     worldContent = doc.toHtml();
     textBrowser->setHtml(worldContent);

}


