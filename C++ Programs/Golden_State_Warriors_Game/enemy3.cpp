#include "enemy3.h"
#include <QGraphicsEllipseItem>
#include "game.h"
#include <QTimer>
#include <qDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QMediaPlayer>

extern Game * game;

Enemy3::Enemy3() : QObject(), QGraphicsPixmapItem()
{
    QPen pen;
    //set random position
    int random_number = rand() % 700;

    setPos(random_number,0);

    //draw the rect
    //setBrush(QBrush(Qt::black));
   // setRect(QRect(10,10,10,10));
    setPixmap(QPixmap(":/images/lebron.jpg"));
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/Lebron James Kid (mp3cut.net).mp3"));
    music->play();


    //connect
    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move3()));

     timer->start(50);
}

void Enemy3::move3()
{
    //move enemy down
    setPos(x(),y()+20);

    if (pos().y() > 600)
    {
        QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/You Suck - Vanoss Sound Effects.mp3"));
        music->setVolume(1000);
        music->play();

        //decrease the health
        game->health->decrease3();

        scene()->removeItem(this);
        delete this;

    }

}
