#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    GameView(int width, int height, QWidget *parent = nullptr);



    int getWidth() const;
    void setWidth(int newWidth);

    int getHeight() const;
    void setHeight(int newHeight);



private:
    int width;
    int height;


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void tellClickedPos(QPointF point);
};

#endif // GAMEVIEW_H
