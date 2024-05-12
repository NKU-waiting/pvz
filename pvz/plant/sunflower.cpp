#include "sunflower.h"
#include"sun.h"
#include<QTimer>
SunFlower::SunFlower(QGraphicsPixmapItem *parent)
    : Plant(":/plant/images/SunFlower.gif", parent)
{
    timerId = startTimer(6000);
}
SunFlower::~SunFlower()
{
    delete timer;
}
void SunFlower::produceSunshine()
{
    Sun *sun=new Sun;
    sun->setPos(pos().x()-50,pos().y()-30);
    scene()->addItem(sun);
}
void SunFlower::timerEvent(QTimerEvent *)
{
    if(!iscontinue)
        return;
    if(n%4==0)
        produceSunshine();
    n++;
}
