#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H
#include "plant.h"
class CherryBomb : public Plant
{
    Q_OBJECT
public:
    CherryBomb(QGraphicsPixmapItem *parent = nullptr);
    ~CherryBomb() override;
    void bomb();
    void die();
    int isbomb=0;
};
#endif // CHERRYBOMB_H
