#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Shoot: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Shoot();
public slots:
    void move();
};

#endif // BULLET_H
