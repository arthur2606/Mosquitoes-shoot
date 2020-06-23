#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

    // intialisation du score
    score = 0;

    // gestion de l'affichage du score
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){

    return score;
}
