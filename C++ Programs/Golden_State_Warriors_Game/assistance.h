#ifndef ASSISTANCE_H
#define ASSISTANCE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Assistance : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
     Assistance();
public slots: //receiving signal
    void move4();
};

#endif // ASSISTANCE_H
