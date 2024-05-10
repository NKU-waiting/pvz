#include "bucketzombie.h"

BucketZombie::BucketZombie(QGraphicsPixmapItem *parent)
    : Zombie(":/zombie/images/BucketZombieWalk.gif", parent)
{
    HP+=1100;iswear=1;ZombieKind=2;
    AttackMovie->setFileName(":/zombie/images/BucketZombieAttack.gif");
    AttackMovie->setSpeed(60);
    DieMovie->setFileName(":/zombie/images/ZombieDie.gif");
    DieMovie->setSpeed(60);
}

