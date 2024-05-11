#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H
#include "plant.h"
class CherryBomb : public Plant
{
    Q_OBJECT
public:
    CherryBomb(QGraphicsPixmapItem *parent = nullptr);
    ~CherryBomb() override;
};
#endif // CHERRYBOMB_H
