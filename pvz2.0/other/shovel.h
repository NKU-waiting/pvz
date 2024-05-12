#ifndef SHOVEL_H
#define SHOVEL_H

#include <QObject>
#include<QGraphicsPixmapItem>
class Shovel:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Shovel(QGraphicsPixmapItem *parent=nullptr);
    QPointF OriginalPosition;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override ;
};

#endif // SHOVEL_H
