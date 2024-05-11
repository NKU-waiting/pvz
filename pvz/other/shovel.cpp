#include "shovel.h"
#include"scene.h"
#include"plant/peashooter.h"
#include"plant/sunflower.h"
#include"plant/repeater.h"
#include"plant/wallnut.h"
#include"plant/potatomine.h"
#include"plant/snowpea.h"
#include <QGraphicsSceneMouseEvent>
Shovel::Shovel(QGraphicsPixmapItem *)
{
    setScale(0.7);
    setPixmap(QPixmap(":/other/images/Shovel.png"));//图片
    setPos(530,10);
    OriginalPosition = pos();
    setFlag(QGraphicsItem::ItemIsMovable, true);
}
void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mousePressEvent(event);
}
void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF delta = event->lastPos() - event->pos(); // 计算鼠标移动的方向和距离
    setPos(this->pos()-0.7*delta);
}
void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem *> items=collidingItems();
    for(auto item:items)
    {
        if(typeid(*item)==typeid(SunFlower)||typeid(*item)==typeid(SnowPea)||typeid(*item)==typeid(PeaShooter)||typeid(*item)==typeid(WallNut)||typeid(*item)==typeid(Repeater)||typeid(*item)==typeid(PotatoMine))
        {
            Plant* plant = static_cast<Plant*>(item);
            isOccupied[plant->row][plant->line]=1;
            plant->HP=0;
        }
    }
    setPos(OriginalPosition);
    QGraphicsPixmapItem::mouseReleaseEvent(event);
}
