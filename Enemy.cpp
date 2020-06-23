#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"

#include <QDebug>
extern Game *game;
Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){

    // Position aleatoire ennemi

    int random_number = rand() % 700;
    setPos(random_number,0);

    // dessiner ennemi
    QPixmap  En(":/images2/moustique_ennemies_2.jpg");
       setPixmap(En.scaled(100,100,Qt::KeepAspectRatio));

    // connecter le temps au mouvement de l'ennemi
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // deplacer l'ennemi vers le bas
    setPos(x(),y()+5);
    if (pos().y()>600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

}
