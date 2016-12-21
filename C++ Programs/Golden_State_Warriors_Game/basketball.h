#ifndef BASKETBALL_H
#define BASKETBALL_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Basketball : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Basketball(QGraphicsItem * parent = 0);
public slots: //receiving signal
    void move();
};

#endif // BASKETBALL_H
