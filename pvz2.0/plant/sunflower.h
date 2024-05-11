#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "plant.h"
class SunFlower : public Plant
{
    Q_OBJECT
public:
    SunFlower(QGraphicsPixmapItem *parent = nullptr);
    ~SunFlower() override;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
private slots:
    void produceSunshine();
private:
    int n=0;
    QTimer *timer;
};

#endif // SUNFLOWER_H
