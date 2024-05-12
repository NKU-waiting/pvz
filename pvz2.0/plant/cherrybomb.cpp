#include "cherrybomb.h"
#include<QTimer>
CherryBomb::CherryBomb(QGraphicsPixmapItem *parent)
    : Plant(":/plant/images/CherryBomb.gif", parent)
{
    QTimer *timer=new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,&QTimer::timeout,this,&CherryBomb::bomb);
    timer->start(500);
    timerId = startTimer(1400);
}
CherryBomb::~CherryBomb()
{
}
void CherryBomb::bomb()
{
    isbomb=1;
    movie->stop();
    setPos(pos().x()-100,pos().y()-60);
    setScale(1.2);
    movie->setFileName(":/plant/images/Boom.gif");
    movie->start();
    QTimer *timer=new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,&QTimer::timeout,this,&CherryBomb::die);
    timer->start(500);
}
void CherryBomb::die()
{
    HP=0;
}
