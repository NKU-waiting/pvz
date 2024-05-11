#ifndef CONEZOMBIE_H
#define CONEZOMBIE_H


#include "zombie.h"
class ConeZombie: public Zombie
{
    Q_OBJECT
public:
    ConeZombie(QGraphicsPixmapItem *parent = nullptr);
};

#endif // CONEZOMBIE_H
