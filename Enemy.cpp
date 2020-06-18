#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"

#include <QDebug>
extern Game *game;
Enemy::Enemy(): QObject(), QGraphicsRectItem(){

    // Position aleatoire ennemi

    int random_number = rand() % 700;
    setPos(random_number,0);

    // dessiner ennemi
    setRect(0,0,70,70);

    // connecter le temps au mouvement de l'ennemi
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // deplacer l'ennemi vers le bas
    setPos(x(),y()+5);
    if (pos().y() + rect().height() < 0){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

}
