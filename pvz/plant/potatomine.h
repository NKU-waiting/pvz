#ifndef POTATOMINE_H
#define POTATOMINE_H

#include "plant.h"
class PotatoMine : public Plant
{
    Q_OBJECT
public:
    PotatoMine(QGraphicsPixmapItem *parent = nullptr);
    ~PotatoMine() override;
    void grow();
    void bomb();
    void die();
    int isgrow=0;
    int isbreakout=0;
    QTimer *timer;
    QTimer *timer1;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
};

#endif // POTATOMINE_H
