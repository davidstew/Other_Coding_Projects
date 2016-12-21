#include "basketball.h"
#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "enemy2.h"
#include "assistance.h"
#include "game.h"
#include "hoop.h"
#include <typeinfo>

extern Game * game; //there is an external global object called game

Basketball::Basketball(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/basketball.png"));

    //connect
    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

     timer->start(50);
}

void Basketball::move()
{
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items = collidingItems();
    //collidingItems() member function returns list of items that collide with bullet. colliding_items is intialized with that list

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Assistance))
        {
            //increase the score
            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/sounds/klayaudio1.mp3"));
            music->setVolume(15000000);
            music->play();
            game->score->increase2();
            game->health->increase();
           //remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

           // delete them both
            delete colliding_items[i];
            delete this;
            return;
         }
     }

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Hoop))
        {
            //increase the score
            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/sounds/Stephen Curry Game-Winner - Warriors vs Thunder - February 27, 2016 - NBA 2015-16 Season (mp3cut.net).mp3"));
           // music->setVolume(15000000);
            music->play();
            game->score->increase();
            //game->health->increase();
            //remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

           // delete them both
            delete colliding_items[i];
            delete this;
            return;
         }
     }

     //move bullet up
    setPos(x(),y()-10);

    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }

}
