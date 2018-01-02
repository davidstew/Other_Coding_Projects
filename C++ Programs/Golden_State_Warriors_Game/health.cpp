
#include "health.h"
#include "game.h"
#include <QFont>
#include <QApplication>
#include <QMessageBox>
#include <QTImer>
#include <QMediaPlayer>


extern Game * game;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    health = 5;
    //draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",18));
}

void Health::increase()
{
    health += 3;
    setPlainText(QString("Health: ") + QString::number(health));

}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));

    if (health <= 0)
    {
        gameover();
    }
}

void Health::decrease2()
{
    health += -2;
    setPlainText(QString("Health: ") + QString::number(health));

    if (health <= 0)
    {
        gameover();
    }

}

void Health::decrease3()
{
    health += -3;
    setPlainText(QString("Health: ") + QString::number(health));


    if (health <= 0)
    {
        gameover();
    }
}


void Health::gameover()
{
    /*
        QMessageBox Msgbox;
        Msgbox.setText("GAME OVER!");
        Msgbox.exec();

   QMediaPlayer * music = new QMediaPlayer();
   music->setMedia(QUrl("qrc:/sounds/Game Over Yeah (HD).mp3"));
   music->setVolume(30);
   music->play();

 QApplication::quit();
*/
}

int Health::getHealth()
{
    return health;
}
