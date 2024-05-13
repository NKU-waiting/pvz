#ifndef CART_H
#define CART_H
#include<QGraphicsPixmapItem>
class car:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    car(QGraphicsPixmapItem *parent=nullptr);
    int isstart=0;
    int row;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
};

#endif // CART_H
