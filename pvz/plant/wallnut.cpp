#include "wallnut.h"

WallNut::WallNut(QGraphicsPixmapItem *parent)
    : Plant(":/plant/images/WallNut.gif", parent)
{
    HP=4000;
    timerId = startTimer(100);
}
WallNut::~WallNut()
{

}
void WallNut::timerEvent(QTimerEvent *)
{
}
