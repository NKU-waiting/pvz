#ifndef BUCKETZOMBIE_H
#define BUCKETZOMBIE_H


#include "zombie.h"
class BucketZombie: public Zombie
{
    Q_OBJECT
public:
    BucketZombie(QGraphicsPixmapItem *parent = nullptr);
};

#endif // BUCKETZOMBIE_H
