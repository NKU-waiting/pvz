#ifndef REPEATER_H
#define REPEATER_H
#include "plant.h"

class Repeater : public Plant
{
    Q_OBJECT
public:
    Repeater(QGraphicsPixmapItem *parent = nullptr);
    ~Repeater() override;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
private slots:
    void producePea();
};

#endif // REPEATER_H
