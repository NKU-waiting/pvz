#ifndef POTATOMINE_H
#define POTATOMINE_H

#include "plant.h"
class PotatoMine : public Plant
{
    Q_OBJECT
public:
    PotatoMine(QGraphicsPixmapItem *parent = nullptr);
    ~PotatoMine() override;
};

#endif // POTATOMINE_H
