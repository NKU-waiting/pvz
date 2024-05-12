#include "cardbackground.h"
#include <QGraphicsSceneMouseEvent>
#include<QPainter>
#include<QTimer>
CardBackground::CardBackground(QGraphicsItem *)
{
    setFlag(QGraphicsItemGroup::ItemIsMovable, true);
}
void CardBackground::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)  
    painter->drawPixmap(QRect(0,0, 50,70), QPixmap(":/other/images/Card.png"));
    painter->drawPixmap(QRect(10, 15, 30, 35), QPixmap(":/plant/images/SunFlower.png"));
    painter->drawText(5,65, QString::number(50));
    if (isblack)
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(0,0,50,70));
        isblack=0;
    }
}
void CardBackground::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}
void CardBackground::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    QPointF delta =  event->lastPos() - event->pos();
    setPos(pos() + delta);
    QGraphicsItem::mouseMoveEvent(event);
}
void CardBackground::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setPos(OriginalPosition);
    isblack=1;
}
