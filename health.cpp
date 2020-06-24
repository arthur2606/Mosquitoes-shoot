#include "health.h"
#include <QFont>
#include "game.h"
#include<QPushButton>
#include<QEvent>

extern Game *game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    // initialisation de la vie du joueur
    health = 10;

    // affichage de la vie du joueur(moustque)

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

//fonction nous servirant à reduire la vie du joueur dans le cas ou il a été touché

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    if(health<1){

      game->gameover();
    }
}

int Health::getHealth(){
    return health;
}
