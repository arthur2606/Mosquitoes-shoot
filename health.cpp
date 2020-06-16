#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    // initialisation de la vie du joueur
    health = 5;

    // affichage de la vie du joueur(moustque)

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

//fonction nous servirant à reduire la vie du joueur dans le cas ou il a été touché

void Health::decrease(){
    health=health+5;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}
