#ifndef ITEM_H
#define ITEM_H
#include <QGraphicsPixmapItem>
#include "worldcontroller.h"
#include <QProcess>

class Item : public QGraphicsPixmapItem
{
public:
    Item();
   // set_sizes setup(int wanted_width_in_tiles, int wanted_height_int_tiles,
                   // int max_width, int max_height, shared_ptr<WorldController> worldcontroller, QString map) override;
    //void resetVC() override;
  //  virtual QWidget * getViewer() override;

    void fillworld() ;
    void fillrow(vector<float> values, int row);

    int getTilesize() const;
    void setTilesize(int newTilesize);

    int testHeight(int height_in_tiles, int max_height, int world_height) ;
    int testWidth(int width_in_tiles, int max_width, int world_width) ;

    void drawProt(int x, int y, char id);
    void update() ;
    void moveprot(int x, int y, char id) ;

    void placeenemy(int x, int y, shared_ptr<Tile> realEnemy, int numba) ;
    void placeHP(int x, int y, int numba);

    void paintPoisonTiles() ;
    void colortile(int x, int y, int R, int G, int B, bool repaint=true) ;
    void dimtile(int x, int y);

    void nextFrame() ;
    void animateDeath(char id) ;
    void getPoisoned(char id) ;
    void heal(char id) ;
    void win() ;

    float getZoom() const;
    bool setZoom(float newZoom) ;
private:
   // GraphicsViewer * gv;
    shared_ptr<WorldController> worldcontroller;
   // vector<GraphicsProt *> prota;
    QGraphicsScene * scene;
    QGraphicsPixmapItem pixmapman;
    QImage world;
    QPixmap pm;
   // QProgressBar * healthBar;
   // QProgressBar * energyBar;
   // QLabel * healthLabel;
  //  QLabel * energyLabel;

  //  vector<GraphicsEnemy *> enemies;
   // vector<GraphicsHP *> hps;
    vector<wrapperHP> whps;
    vector<point> poisoned;
    QGraphicsPixmapItem * go = nullptr;

    int permatilesize = 30;
    int tilesize = 30;
    float zoom = 1.0;
    float oldzoom = 1.0;
    int intzoom = 4;
    char protsActive = 1;
    QString pathmap;
    std::array<int, 8> tsizes =  {1,     3,   6,   10,  15,  30, 45,  60};
    std::array<float, 8> zooms = {0.1/3, 0.1, 0.2 ,0.3, 0.5, 1,  1.5, 2};
};

#endif // ITEM_H
