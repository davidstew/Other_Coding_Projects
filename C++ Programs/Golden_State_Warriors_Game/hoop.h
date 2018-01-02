#ifndef HOOP_H
#define HOOP_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Hoop : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
     Hoop();
public slots: //receiving signal
    void move5();
};

#endif // HOOP_H
