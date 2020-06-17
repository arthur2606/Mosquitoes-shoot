#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "bouton.h"
#include <QString>
#include<QGraphicsView>
#include<QEvent>

Game::Game(QWidget *parent){

    // creation de la scene

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); //  scene de taille 800x600

    // Annuler l'affichage de barre de defillage

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // annule l'affichage de la barre de defilement horizontal
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // annule l'affichage de la barre de defilement vertical
    setFixedSize(800,600);



}
void Game::displayMainMenu(){

    // creation du menu
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("MENU"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // bouton play
    bouton* playButton = new bouton(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // bouton pour sortir du jeu
    bouton* quitButton = new bouton(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}
void Game::start(){

      scene->clear();
    Score *score;
    Player *player;
    Health * health;

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
