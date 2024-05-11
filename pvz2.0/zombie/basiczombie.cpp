#include "basiczombie.h"

BasicZombie::BasicZombie(QGraphicsPixmapItem *parent)
    : Zombie(":/zombie/images/ZombieWalk1.gif", parent)
{
    AttackMovie->setFileName(":/zombie/images/ZombieAttack.gif");
    AttackMovie->setSpeed(60);
    DieMovie->setFileName(":/zombie/images/ZombieDie.gif");
    DieMovie->setSpeed(60);
}
BasicZombie::~BasicZombie()
{

}
