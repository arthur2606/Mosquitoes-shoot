#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "score.h"
#include "health.h"
#include <QObject>
#include "game.h"



class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget *parent=0);

    QGraphicsScene * scene;
    Score *score;
    Player *player;
    Health * health;
    void displayMainMenu();
    void gameover();

   public slots:
       void start();

};

#endif // GAME_H
