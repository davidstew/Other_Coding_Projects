#ifndef ENEMY3_H
#define ENEMY3_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy3 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
     Enemy3();
public slots: //receiving signal
    void move3();
};

#endif // ENEMY3_H
