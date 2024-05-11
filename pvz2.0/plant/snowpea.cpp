#include "snowpea.h"
#include"peasnow.h"
#include"other/scene.h"
SnowPea::SnowPea(QGraphicsPixmapItem *parent)
    : Plant(":/plant/images/SnowPea.gif", parent)
{
    timerId = startTimer(1400);
}
SnowPea::~SnowPea()
{
}
void SnowPea::producePea()
{
    PeaSnow *pea=new PeaSnow;
    pea->setPos(pos().x()+50,pos().y()+5);
    scene()->addItem(pea);
}
void SnowPea::timerEvent(QTimerEvent *)
{
    if(isZombie[row]>0)
    {
        producePea();
    }
}
