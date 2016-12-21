#ifndef ENEMY2_H
#define ENEMY2_H


#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy2 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
     Enemy2();
public slots: //receiving signal
    void move2();
};

#endif // ENEMY2_H
