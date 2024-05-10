#ifndef FOOTBALLZOMBIE_H
#define FOOTBALLZOMBIE_H


#include "zombie.h"
class FootballZombie: public Zombie
{
    Q_OBJECT
public:
    FootballZombie(QGraphicsPixmapItem *parent = nullptr);
};
#endif // FOOTBALLZOMBIE_H
