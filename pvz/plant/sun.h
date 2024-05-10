#ifndef SUN_H
#define SUN_H

#include "plant.h"
class Sun: public Plant
{
    Q_OBJECT
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    Sun(QGraphicsPixmapItem *parent=nullptr);
    ~Sun() override;
};

#endif // SUN_H
