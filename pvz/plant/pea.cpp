#include "pea.h"
#include"other/pause.h"
#include<QGraphicsScene>
Pea::Pea(QGraphicsPixmapItem *parent)
{
    setPixmap(QPixmap(":/plant/images/Pea.png"));
    startTimer(10);
}
void Pea::timerEvent(QTimerEvent *)
{
    if(!iscontinue)
        return;
    setPos(pos().x()+2,pos().y());
    if(pos().x()>897)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}
