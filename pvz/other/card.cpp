#include "card.h"
#include"shop.h"
#include"scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include<QPointF>
#include<QGraphicsRectItem>
#include"plant/sunflower.h"
#include"plant/cherrybomb.h"
#include"plant/peashooter.h"
#include"plant/wallnut.h"
#include"plant/snowpea.h"
#include"plant/repeater.h"
#include"plant/potatomine.h"
card::card(QGraphicsItem *)
    :timer(new QTimer(this))
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    connect(timer,&QTimer::timeout,this,&card::updatemap);
}
void card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(0,0, 50,70), QPixmap(":/other/images/Card.png"));
    painter->drawPixmap(QRect(10, 15, 30, 35), QPixmap(PlantImagePath));
    painter->drawText(5,65, QString::number(Price));
    if (isblack)
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(0,0,50,70*qreal(n)/Originaln));
        isblack=0;
    }
}
void card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    OriginalPosition = pos();
    QGraphicsItem::mousePressEvent(event);
}
void card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //setPos(event->scenePos());
    // 在原始位置显示临时卡片
    QPointF delta = event->lastPos() - event->pos(); // 计算鼠标移动的方向和距离
    setPos(delta+this->pos());
    if(tempCard==NULL)
    {
        tempCard = new card;
        tempCard->PlantImagePath=this->PlantImagePath;
        tempCard->Price=this->Price;
        tempCard->setPos(OriginalPosition);
        scene()->addItem(tempCard);}
    QGraphicsItem::mouseMoveEvent(event);
}
void card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(tempCard!=NULL)
    {
        scene()->removeItem(tempCard);
        delete tempCard;
        tempCard = nullptr;}
    setPos(OriginalPosition);
    setPlant(event->scenePos());
    QGraphicsItem::mouseReleaseEvent(event);
}
void card::setPlant(QPointF position)
{
    if(isPlant&&position.x()-75>=0&&position.y()-94>=0)
    {
        int line=(position.x()-94)/82,row=(position.y()-75)/100;
        if(0<=row&&row<5&&0<=line&&line<9&&isOccupied[row][line]==1&&sunshine>=Price)
        {
            switch (this->kind)
            {
            case 0:
            {
                SunFlower *plant=new SunFlower;
                plant->setPos(94+line*82,90+row*98);
                plant->line=line;plant->row=row;
                scene()->addItem(plant);
                break;}
            case 1:
            {
                PeaShooter *plant=new PeaShooter;
                plant->setPos(94+line*82,90+row*98);
                plant->line=line;plant->row=row;
                scene()->addItem(plant);
                break;}
            case 2:
            {
                SnowPea *plant=new SnowPea;
                plant->setPos(94+line*82,90+row*98);
                plant->line=line;plant->row=row;
                scene()->addItem(plant);
                break;}
            case 3:
            {
                Repeater *plant=new Repeater;
                plant->setPos(94+line*82,90+row*98);
                plant->line=line;plant->row=row;
                scene()->addItem(plant);
                break;}
            case 4:
            {   WallNut *plant=new WallNut;
                plant->setPos(94+line*82,90+row*98);
                plant->line=line;plant->row=row;
                scene()->addItem(plant);
                break;}
            case 5:
            {   PotatoMine *plant=new PotatoMine;
                plant->setPos(94+line*82,90+row*98);
                plant->line=line;plant->row=row;
                scene()->addItem(plant);
                break;}
            case 6:
            {   CherryBomb *plant=new CherryBomb;
                plant->setPos(94+line*82,90+row*98);
                plant->line=line;plant->row=row;
                scene()->addItem(plant);
                break;}
            default:
                break;
            }
            isOccupied[row][line]=0;
            sunshine-=Price;
            showsunshine->setPlainText(QString::number(sunshine));
            isPlant--;
            CardCD();
        }
    }
}
void card::CardCD()
{
    setFlag(QGraphicsItem::ItemIsMovable, false);
    timer->start(50);
    isblack=1;
}
void card::updatemap()
{
    if(!iscontinue)
        return;
    isblack=1;
    update();
    n--;
    if(n==0)
    {
        isPlant=1;
        isblack=0;
        timer->stop();
        setFlag(QGraphicsItem::ItemIsMovable, true);
        n=Originaln;
    }
}

