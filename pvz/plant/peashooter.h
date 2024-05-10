#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "plant.h"
class PeaShooter : public Plant
{
    Q_OBJECT
public:
    PeaShooter(QGraphicsPixmapItem *parent = nullptr);
    ~PeaShooter() override;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
private slots:
    void producePea();
};


#endif // PEASHOOTER_H
