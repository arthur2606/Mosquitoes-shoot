#ifndef BOUTON_H
#define BOUTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class bouton:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:

    bouton(QString name, QGraphicsItem* parent=NULL);


    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
 signals:

    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif // BOUTON_H
