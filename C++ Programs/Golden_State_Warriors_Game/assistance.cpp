#include "assistance.h"

#include "enemy3.h"
#include <QGraphicsEllipseItem>
#include "game.h"
#include <QTimer>
#include <qDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QMediaPlayer>

extern Game * game;

Assistance::Assistance() : QObject(), QGraphicsPixmapItem()
{
    QPen pen;
    //set random position
    int random_number = rand() % 700;

    setPos(random_number,0);

    //draw the rect
    //setBrush(QBrush(Qt::black));
   // setRect(QRect(10,10,10,10));
    setPixmap(QPixmap(":/images/klay.jpg"));

    //connect
    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move4()));

     timer->start(50);
}

void Assistance::move4()
{
    //move enemy down
    setPos(x(),y()+15);

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
