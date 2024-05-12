#ifndef WALLNUT_H
#define WALLNUT_H

#include "plant.h"
class WallNut : public Plant
{
    Q_OBJECT
public:
    WallNut(QGraphicsPixmapItem *parent = nullptr);
    ~WallNut() override;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
};

#endif // WALLNUT_H
