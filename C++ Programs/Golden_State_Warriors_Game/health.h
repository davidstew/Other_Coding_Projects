#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health(QGraphicsItem* parent = 0);
    void decrease();
    void decrease2();
    void decrease3();
    void increase();
    int getHealth();
private:
     void gameover();
    int health;
};
#endif // HEALTH_H
