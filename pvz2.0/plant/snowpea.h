#ifndef SNOWPEA_H
#define SNOWPEA_H

#include "plant.h"
class SnowPea : public Plant
{
    Q_OBJECT
public:
    SnowPea(QGraphicsPixmapItem *parent = nullptr);
    ~SnowPea() override;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
private slots:
    void producePea();
};
#endif // SNOWPEA_H
