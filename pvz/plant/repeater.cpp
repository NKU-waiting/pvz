#include "repeater.h"
#include"other/pause.h"
#include"pea.h"
#include"other/scene.h"
Repeater::Repeater(QGraphicsPixmapItem *parent)
    : Plant(":/fangzhou/images/nengtianshiAttack.gif", parent)
{
    setScale(0.35);
    timerId = startTimer(700);
}
Repeater::~Repeater()
{

}
void Repeater::producePea()
{
    Pea *pea1=new Pea;Pea *pea2=new Pea;
    pea1->setPos(pos().x()+50,pos().y()+15);pea2->setPos(pos().x()+80,pos().y()+15);
    scene()->addItem(pea1);scene()->addItem(pea2);
}
void Repeater::timerEvent(QTimerEvent *)
{
    if(!iscontinue)
        return;
    if(isZombie[row]>0)
    {
        producePea();
    }
}
