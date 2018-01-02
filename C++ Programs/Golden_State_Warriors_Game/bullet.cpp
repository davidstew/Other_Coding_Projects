
#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "enemy2.h"
#include "enemy3.h"
#include "assistance.h"
#include "game.h"
#include <typeinfo>

extern Game * game; //there is an external global object called game


Bullet::Bullet(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/emoji.png"));

    //connect
    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

     timer->start(50);
}

void Bullet::move()
{
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items = collidingItems();
    //collidingItems() member function returns list of items that collide with bullet. colliding_items is intialized with that list

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // increase the score
            game->score->increase();
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
        if (typeid(*(colliding_items[i])) == typeid(Enemy2))
        {
            // increase the score
            game->score->increase2();
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
        if (typeid(*(colliding_items[i])) == typeid(Enemy3))
        {
            // increase the score
            game->score->increase2();
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
