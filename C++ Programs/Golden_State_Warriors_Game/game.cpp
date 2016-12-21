
#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include "health.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include "enemy2.h"
#include <QBrush>
#include <QImage>
#include <QMessageBox>
#include <QApplication>


Game::Game(QWidget *parent)
{
//connect health to ending of game
//connect(health,SIGNAL(dead()),this,SLOT(end()));


//create a scene
scene = new QGraphicsScene();
scene->setSceneRect(0,0,800,600);
setBackgroundBrush(QBrush(QImage(":/images/Warriors.png")));

setScene(scene);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(800,600);


//create a player to put in the scene

player = new Player();
//player->setRect(0,0,100,100);
//player->setBrush(QBrush(Qt::green));
player->setPos(400,500);

//make player focusable
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();

scene->addItem(player);

//create score
score = new Score();
scene->addItem(score);

//create health
health = new Health();
health->setPos(health->x(),health->y()+25);
scene->addItem(health);

//spawn enemies
QTimer * timer = new QTimer();

QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
timer->start(2000);

QTimer * timer1 = new QTimer();
QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn2()));
timer1->start(6000);

QTimer * timer2 = new QTimer();
QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn3()));
timer2->start(10000);

QTimer * timer3 = new QTimer();
QObject::connect(timer3,SIGNAL(timeout()),player,SLOT(spawn4()));
timer3->start(20000);

QTimer * timer4 = new QTimer();
QObject::connect(timer4,SIGNAL(timeout()),player,SLOT(spawn5()));
timer4->start(5000);


//play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/E-40 - Choices (Yup) --WARRIORS VERSION--.mp3"));
    music->setVolume(30);
    music->play();

    if (music->state() == QMediaPlayer::StoppedState)
    {
        music->play();
    }


show();
}

