#include "Shoot.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"

#include <QDebug>
Shoot::Shoot(): QObject(), QGraphicsRectItem(){
    // dessiner la balle
    setRect(50,0,5,15);

    // connecter le temps pour un mouvement continue de la balle
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Shoot::move(){
    // Si la balle recontre un ennemi, les deux se detruisent
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // retirer les deux de la scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // supprimer les deux de la mémoire
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // mouvement de la balle vers le haut
    setPos(x(),y()-10);
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

