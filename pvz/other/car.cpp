#include "car.h"
#include"pause.h"
#include<QGraphicsScene>

car::car(QGraphicsPixmapItem *parent)
{
    setPixmap(QPixmap(":/other/images/LawnMower.png"));//图片
    startTimer(20);
}
void car::timerEvent(QTimerEvent *)
{
    if(!iscontinue)
        return;
    if(isstart==1)
    {
        setPos(pos().x()+5,pos().y());
    }
}
