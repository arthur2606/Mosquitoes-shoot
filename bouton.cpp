#include "bouton.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include<QAbstractButton>
#include<QEvent>

bouton::bouton(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){

    // representation d'un bouton
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);

    // presenter le texte
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // reponse lorsque le curseur passe sur un bouton

    setAcceptHoverEvents(true);
}

void bouton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void bouton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // change la couleur en rouge
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void bouton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // change la couleur en green aprés etre placé au dessu d'un bouton
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}
