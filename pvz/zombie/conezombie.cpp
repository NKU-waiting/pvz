#include "conezombie.h"

ConeZombie::ConeZombie(QGraphicsPixmapItem *parent)
    : Zombie(":/zombie/images/ConeZombieWalk.gif", parent)
{
    setScale(0.9);
    HP+=370;iswear=1;ZombieKind=1;
    AttackMovie->setFileName(":/zombie/images/ConeZombieAttack.gif");
    AttackMovie->setSpeed(60);
    DieMovie->setFileName(":/zombie/images/ZombieDie.gif");
    DieMovie->setSpeed(60);
}

