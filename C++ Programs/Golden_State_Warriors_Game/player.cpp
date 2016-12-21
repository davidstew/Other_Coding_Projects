
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "enemy2.h"
#include "enemy3.h"
#include "assistance.h"
#include "basketball.h"
#include "hoop.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/Star Wars Pad'me blaster pistol fire sound effect 2.mp3"));

    setPixmap(QPixmap(":/images/steph_curry.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
       {
        if (pos().x() > 0)
        setPos(x()-15,y());
        }
    else if (event->key() == Qt::Key_Right)
       {
        if (pos().x()+100 < 800)
        setPos(x()+15,y());
        }
    else if (event->key() == Qt::Key_Space)
    {
     //create a bullet
       Bullet * bullet = new Bullet();
       bullet->setPos(x()+20,y()-30);

       scene()->addItem(bullet);

     //play bulletsound
       if (bulletsound->state() == QMediaPlayer::PlayingState)
       {
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState)
       {
       bulletsound->play();
       }
    }

    else if (event->key() == Qt::Key_Up)
     {
        Basketball * ball = new Basketball();
        ball->setPos(x()+20,y()-30);

        scene()->addItem(ball);

      //play bulletsound
        if (bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState)
        {
        bulletsound->play();
        }
     }
}

void Player::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::spawn2()
{
    //create an enemy
    Enemy2 * enemy = new Enemy2();
    scene()->addItem(enemy);
}

void Player::spawn3()
{
    //create an enemy
    Enemy3 * enemy = new Enemy3();
    scene()->addItem(enemy);
}

void Player::spawn4()
{
    Assistance * assist = new Assistance();
    scene()->addItem(assist);
}

void Player::spawn5()
{
    Hoop * assist = new Hoop();
    scene()->addItem(assist);
}
