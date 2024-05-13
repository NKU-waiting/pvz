#include "snowpea.h"
#include"peasnow.h"
#include"other/scene.h"
SnowPea::SnowPea(QGraphicsPixmapItem *parent)
    : Plant(":/fangzhou/images/hanmangAttack.gif", parent)
{
    setScale(0.35);
    timerId = startTimer(700);
}
SnowPea::~SnowPea()
{
}
void SnowPea::producePea()
{
    PeaSnow *pea=new PeaSnow;
    pea->setPos(pos().x()+50,pos().y()+15);
    scene()->addItem(pea);
}
void SnowPea::timerEvent(QTimerEvent *)
{
    if(!iscontinue)
        return;
    if(isZombie[row]>0)
    {
        producePea();
    }
}
