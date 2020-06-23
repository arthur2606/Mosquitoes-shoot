#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>

class Shoot: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Shoot();
public slots:
    void move();
};

#endif // BULLET_H
