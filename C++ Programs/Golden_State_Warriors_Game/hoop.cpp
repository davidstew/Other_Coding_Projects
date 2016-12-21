#include "hoop.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include "game.h"
#include <QTimer>

extern Game * game;

Hoop::Hoop() : QObject(), QGraphicsPixmapItem()
{
    QPen pen;
    //set random position
    int random_number = rand() % 700;

    setPos(random_number,0);

    //draw the rect
    //setBrush(QBrush(Qt::black));
   // setRect(QRect(10,10,10,10));
    setPixmap(QPixmap(":/images/hoop.jpg"));

    //connect
    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move5()));

     timer->start(50);
}

void Hoop::move5()
{
    //move enemy down
    setPos(x(),y()+5);

    if (pos().y() > 600)
    {
        QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/You Suck - Vanoss Sound Effects.mp3"));
        music->play();

        //decrease the health
       // game->health->decrease2();

        scene()->removeItem(this);
        delete this;

    }

}
