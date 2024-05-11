#include "peashooter.h"
#include<QTimer>
#include"pea.h"
#include"other/scene.h"
PeaShooter::PeaShooter(QGraphicsPixmapItem *parent)
    : Plant(":/plant/images/Peashooter.gif", parent)
{
    timerId = startTimer(1400);
}

PeaShooter::~PeaShooter()
{
}
void PeaShooter::producePea()
{
    Pea *pea=new Pea;
    pea->setPos(pos().x()+50,pos().y()+5);
    scene()->addItem(pea);
}
void PeaShooter::timerEvent(QTimerEvent *)
{
    if(isZombie[row]>0)
    {
        producePea();
    }
}
