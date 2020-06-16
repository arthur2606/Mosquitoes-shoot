#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"

Game::Game(QWidget *parent){

    // creation de la scene

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); //  scene de taille 800x600

    // Annuler l'affichage de barre de defillage

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // annule l'affichage de la barre de defilement horizontal
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // annule l'affichage de la barre de defilement vertical
    setFixedSize(800,600);

    // creation du joueur

    player = new Player();
    player->setRect(0,0,100,100);
    player->setPos(400,500); // placer le joueur au milieu de la scene

    // Mettre notre joueur en vue principale

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // ajout du joueur à la scene de jeu

    scene->addItem(player);

    // creation du score et de la santé

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // creation des ennemies

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();
}
