#include <QApplication>
#include "MyRect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // creation de la scene
    QGraphicsScene * scene = new QGraphicsScene();

    // creation d'un objet a ajouter sur la scene
    MyRect * Mosquito = new MyRect();
    Mosquito->setRect(0,0,100,100); // modifie les dimensions de l'objet

    // ajouter un objet a la scene
    scene->addItem(Mosquito);

    // rendre l'objet focalisable
    Mosquito->setFlag(QGraphicsItem::ItemIsFocusable);
    Mosquito->setFocus();

    // creation d'une vue pour visualiser la scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Faire apparaitre la vue
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    Mosquito->setPos(view->width()/2,view->height() - Mosquito->rect().height());

    // Produire l'ennemi
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),Mosquito,SLOT(spawn()));
    timer->start(500);

    return a.exec();
}
