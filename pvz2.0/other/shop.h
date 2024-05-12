#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include<QGraphicsPixmapItem>
class Shop:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Shop(QGraphicsPixmapItem *parent=nullptr);
};
extern int sunshine;//全局变量阳光
#endif // SHOP_H
