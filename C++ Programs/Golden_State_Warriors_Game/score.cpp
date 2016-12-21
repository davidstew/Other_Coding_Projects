#include "score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;
    //draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",18));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::increase2()
{
    score += 2;
    setPlainText(QString("Score: ") + QString::number(score));

}

void Score::increase3()
{
    score += 3;
    setPlainText(QString("Score: ") + QString::number(score));

}

int Score::getScore()
{
    return score;
}
