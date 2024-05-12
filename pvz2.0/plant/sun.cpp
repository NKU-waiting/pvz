#include "sun.h"
#include "other/shop.h"
#include"other/scene.h"
Sun::Sun(QGraphicsPixmapItem *parent)
: Plant(":/plant/images/Sun.gif", parent)
{

}
void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    sunshine+=25;
    showsunshine->setPlainText(QString::number(sunshine));
    scene()->removeItem(this);
}
Sun::~Sun()
{
}
