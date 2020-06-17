#include "bouton.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include<QAbstractButton>
#include<QEvent>

bouton::bouton(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}

void bouton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void bouton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // change color to cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void bouton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // change color to dark cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}
