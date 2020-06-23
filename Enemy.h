#ifndef ENEMY_H
#define ENEMY_H
#include"game.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>

extern Game *game;

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY_H
