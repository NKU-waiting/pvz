#include "potatomine.h"
#include"other/scene.h"
#include<QTimer>
PotatoMine::PotatoMine(QGraphicsPixmapItem *parent)
    : Plant(":/plant/images/PotatoMine1.gif", parent)
{
    setPixmap(QPixmap(":/plant/images/PotatoMine1.gif"));
    QTimer *timer=new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,&QTimer::timeout,this,&PotatoMine::grow);
    timer->start(15000);
    movie->stop();
    timerId = startTimer(20);
}
PotatoMine::~PotatoMine()
{
}
void PotatoMine::grow()
{
    movie->setFileName(":/plant/images/PotatoMine.gif");
    movie->start();
    isgrow=1;
}
void PotatoMine::bomb()
{
    if(isbreakout==0){
        movie->stop();movie->setFileName(":/plant/images/PotatoMineBomb.gif");
        movie->start();
        QTimer *timer=new QTimer(this);
        connect(timer,&QTimer::timeout,this,&PotatoMine::die);
        timer->start(500);
    }
    isbreakout=1;
}
void PotatoMine::die()
{
    HP=0;
}
void PotatoMine::timerEvent(QTimerEvent *)
{
    if(HP<=0)
    {
        isOccupied[row][line]=1;
        killTimer(timerId);
        scene()->removeItem(this);
    }
}
