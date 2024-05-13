#include "peashooter.h"
#include<QTimer>
#include"pea.h"
#include"other/scene.h"
PeaShooter::PeaShooter(QGraphicsPixmapItem *parent)
    : Plant(":/fangzhou/images/keluosiAttack.gif", parent)
{
    setScale(0.15);
    timerId = startTimer(700);
}

PeaShooter::~PeaShooter()
{
}
void PeaShooter::producePea()
{
    Pea *pea=new Pea;
    pea->setPos(pos().x()+50,pos().y()+15);
    scene()->addItem(pea);
}
void PeaShooter::timerEvent(QTimerEvent *)
{
    if(!iscontinue)
        return;
    if(isZombie[row]>0)
    {
        producePea();
    }
}
