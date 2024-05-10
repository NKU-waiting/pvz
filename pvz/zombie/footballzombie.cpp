#include "footballzombie.h"

FootballZombie::FootballZombie(QGraphicsPixmapItem *parent)
    : Zombie(":/zombie/images/FootballZombieWalk.gif", parent)
{
    setScale(0.8);
    HP+=1400;iswear=1;ZombieKind=3;
    AttackMovie->setFileName(":/zombie/images/FootballZombieAttack.gif");
    AttackMovie->setSpeed(60);
    DieMovie->setFileName(":/zombie/images/FootballZombieDie.gif");
    DieMovie->setSpeed(60);
}

