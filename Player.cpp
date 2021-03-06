#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Shoot.h"
#include "Enemy.h"
#include <QGraphicsPixmapItem>
#include <QDebug>

Player::Player(QGraphicsPixmapItem *parent1): QGraphicsPixmapItem(parent1){

shootsound = new QMediaPlayer();
shootsound->setMedia(QUrl("qrc:/sounds/shoot.mp3"));

}

void Player::keyPressEvent(QKeyEvent *event){
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

      //   Son de la balle
        if(shootsound->state() == QMediaPlayer::PlayingState){
           shootsound->setPosition(0);
         }
        else if (shootsound->state() == QMediaPlayer::StoppedState){
           shootsound->play();
        }
    }

}

void Player::spawn(){
    // creation de l'ennemi
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
