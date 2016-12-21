#include "enemy2.h"
#include <QGraphicsEllipseItem>
#include "game.h"
#include <QTimer>
#include <qDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QMediaPlayer>

extern Game * game;

Enemy2::Enemy2() : QObject(), QGraphicsPixmapItem()
{
    QPen pen;
    //set random position
    int random_number = rand() % 700;

    setPos(random_number,0);

    //draw the rect
    //setBrush(QBrush(Qt::black));
   // setRect(QRect(10,10,10,10));
    setPixmap(QPixmap(":/images/kevindurant.jpg"));

    //connect
    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move2()));

     timer->start(50);
}

void Enemy2::move2()
{
    //move enemy down
    setPos(x(),y()+10);

    if (pos().y() > 600)
    {
        QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/You Suck - Vanoss Sound Effects.mp3"));
        music->setVolume(1000);
        music->play();

        //decrease the health
        game->health->decrease2();

        scene()->removeItem(this);
        delete this;

    }

}

