#include "card.h"
#include"shop.h"
#include"scene.h"
#include <QGraphicsItemGroup>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include<QPointF>
#include"plant/sunflower.h"
#include"plant/cherrybomb.h"
#include"plant/peashooter.h"
#include"plant/wallnut.h"
#include"plant/snowpea.h"
#include"plant/repeater.h"
#include"plant/potatomine.h"

card::card(const QString &plantImagePath, const int price,QGraphicsItem *parent,int x_value,int y_value,double Scale)

    : QGraphicsItemGroup(parent),x(x_value),y(y_value),scale(Scale),Price(price),PlantImagePath(plantImagePath)
{
    //卡片背景
    QPixmap backgroundPixmap(":/other/images/Card.png");
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(backgroundPixmap);
    backgroundItem->setScale(0.5);
    addToGroup(backgroundItem);
    //植物
    QPixmap plantPixmap(plantImagePath);
    QGraphicsPixmapItem *plantItem = new QGraphicsPixmapItem(plantPixmap);
    plantItem->setScale(scale);
    plantItem->setPos(5+x, 15+y); // 设置植物图片在卡片上的位置
    addToGroup(plantItem);
    //植物价格
    QGraphicsTextItem *plantprice=new QGraphicsTextItem;
    plantprice->setPlainText(QString::number(price));
    plantprice->setPos(0,49);
    addToGroup(plantprice);
    setFlag(QGraphicsItem::ItemIsMovable, true);
}
void card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    OriginalPosition = pos();
    QGraphicsItemGroup::mousePressEvent(event);
}
void card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //setPos(event->scenePos());
    // 在原始位置显示临时卡片
    QPointF delta = event->lastPos() - event->pos(); // 计算鼠标移动的方向和距离
    setPos(delta+this->pos());
    if(tempCard==NULL)
    {
        tempCard = new card(PlantImagePath,Price,nullptr);
        tempCard->setPos(OriginalPosition);
        scene()->addItem(tempCard);}
    QGraphicsItemGroup::mouseMoveEvent(event);
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
    QGraphicsItemGroup::mouseReleaseEvent(event);
}
void card::setPlant(QPointF position)
{
    if(position.x()-75>=0&&position.y()-94>=0)
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
        }
    }
}
