#ifndef BASICZOMBIE_H
#define BASICZOMBIE_H

#include "zombie.h"
class BasicZombie: public Zombie
{
    Q_OBJECT
public:
    BasicZombie(QGraphicsPixmapItem *parent = nullptr);
    ~BasicZombie() override;
};

#endif // BASICZOMBIE_H
