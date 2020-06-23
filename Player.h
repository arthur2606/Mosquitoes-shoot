
#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // MYRECT_H
