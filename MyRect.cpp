#include "MyRect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Shoot.h"
#include "Enemy.h"

#include <QDebug>
void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-60,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+60,y());
    }
    else if (event->key() == Qt::Key_Space){
        // creation de la balle
        Shoot * shoot = new Shoot();
        shoot->setPos(x(),y());
        scene()->addItem(shoot);

          }
}

void MyRect::spawn(){
    // creation de l'ennemi
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
