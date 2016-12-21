
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <qDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QMediaPlayer>

extern Game * game;

Enemy::Enemy() : QObject(), QGraphicsPixmapItem()
{
    //set random position
    int random_number = rand() % 700;

    setPos(random_number,0);

    //draw the rect
   // setBrush(QBrush(Qt::yellow));
   // setRect(0,0,10,10);
    setPixmap(QPixmap(":/images/westbrook.png"));

    //connect
    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

     timer->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(),y()+5);

    if (pos().y() > 600)
    {
        QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/You Suck - Vanoss Sound Effects.mp3"));
        music->setVolume(1000);
        music->play();

        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;

    }

}
