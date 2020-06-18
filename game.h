#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "score.h"
#include "health.h"
#include <QObject>



class Game: public QGraphicsView{
public:
    Game(QWidget * parent=NULL);

    QGraphicsScene * scene;
    Score *score;
    Player *player;
    Health * health;
    void displayMainMenu();

   public slots:
       void start();

};

#endif // GAME_H
