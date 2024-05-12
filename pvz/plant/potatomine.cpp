#include "potatomine.h"
#include"other/scene.h"
#include<QTimer>
PotatoMine::PotatoMine(QGraphicsPixmapItem *parent)
    : Plant(":/plant/images/PotatoMine1.gif", parent)
{
    setPixmap(QPixmap(":/plant/images/PotatoMine1.gif"));
    timer=new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,&QTimer::timeout,this,&PotatoMine::grow);
    timer->start(15000);
    movie->stop();
    timerId = startTimer(20);
    iskilltimerId=0;
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
        timer1=new QTimer(this);timer1->setSingleShot(true);
        connect(timer1,&QTimer::timeout,this,&PotatoMine::die);
        timer1->start(500);
    }
    isbreakout=1;
}
void PotatoMine::die()
{
    movie->stop();
    killTimer(timerId);
    isOccupied[row][line]=1;
    scene()->removeItem(this);
}
void PotatoMine::timerEvent(QTimerEvent *)
{
    if(!iscontinue)
    {
        timer->stop();
        return;
    }
    if(!timer->isActive())
        timer->start();
}
