#include "repeater.h"
#include"pea.h"
#include"other/scene.h"
Repeater::Repeater(QGraphicsPixmapItem *parent)
    : Plant(":/plant/images/Repeater.gif", parent)
{
    timerId = startTimer(1400);
}
Repeater::~Repeater()
{

}
void Repeater::producePea()
{
    Pea *pea1=new Pea;Pea *pea2=new Pea;
    pea1->setPos(pos().x()+50,pos().y()+5);pea2->setPos(pos().x()+80,pos().y()+5);
    scene()->addItem(pea1);scene()->addItem(pea2);
}
void Repeater::timerEvent(QTimerEvent *)
{
    if(isZombie[row]>0)
    {
        producePea();
    }
}
