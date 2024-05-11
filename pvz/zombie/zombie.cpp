#include "zombie.h"
#include<QTimer>
#include"other/scene.h"
#include"zombiehead.h"
#include <QGraphicsPixmapItem>
#include"plant/pea.h"
#include"plant/peasnow.h"
#include"plant/peashooter.h"
#include"plant/repeater.h"
#include"plant/snowpea.h"
#include"plant/sunflower.h"
#include"plant/wallnut.h"
#include"plant/potatomine.h"
#include"plant/cherrybomb.h"
#include<QObject>
Zombie::Zombie(const QString path,QGraphicsPixmapItem *parent)
    : QGraphicsPixmapItem(parent), WalkMovie(new QMovie(this)),AttackMovie(new QMovie(this)),DieMovie(new QMovie(this)),BurnMovie(new QMovie(this))
{
    connect(WalkMovie, &QMovie::frameChanged, this, &Zombie::updateWalk);
    connect(AttackMovie, &QMovie::frameChanged, this, &Zombie::updateAttack);
    connect(DieMovie, &QMovie::frameChanged, this, &Zombie::updateDie);
    connect(BurnMovie, &QMovie::frameChanged, this, &Zombie::updateBurn);
    BurnMovie->setFileName(":/zombie/images/Burn.gif");
    WalkMovie->setFileName(path);
    WalkMovie->setSpeed(150); // 设置播放速度为正常速度的1.5倍
    WalkMovie->start();
    timerId = startTimer(20);
}
Zombie::~Zombie()
{
}
void Zombie::Walk()
{
    isWalk=1;
    AttackMovie->stop();
    WalkMovie->start();
}
void Zombie::Attack()
{
    isWalk=0;
    WalkMovie->stop();
    AttackMovie->start();
}
void Zombie::updateWalk()
{
    setPos(pos().x()-1.5,pos().y());
    setPixmap(WalkMovie->currentPixmap());
}
void Zombie::updateAttack()
{
    setPixmap(AttackMovie->currentPixmap());
}
void Zombie::updateDie()
{
    setPixmap(DieMovie->currentPixmap());
}
void Zombie::updateBurn()
{
    setPixmap(BurnMovie->currentPixmap());
}
void Zombie::stopQMovie()
{
    WalkMovie->stop();
}
void Zombie::timerEvent(QTimerEvent *)
{
    QList<QGraphicsItem *> items=collidingItems();
    for(auto item:items)
    {
        int kind=ItemKind(item);
        switch (kind) {
        case 0:
            break;
        case 1:
        {
            scene()->removeItem(item);
            delete item;
            HP-=20;
            if(isdead==1&&HP<90)
            {
                isdead=0;
                isZombie[row]--;
                death();
                killTimer(timerId);
                return;
            }
            break;
        }
        case 2:
        {
            Plant* plant = static_cast<Plant*>(item);
            if(plant->row==this->row)
            {
                Attack();
                plant->HP-=2;
                isPlant=1;
            }
            break;
        }
        case 3:
        {
            PotatoMine* potatoMine = static_cast<PotatoMine*>(item);
            if(potatoMine->row==this->row)
            {
                if(potatoMine->isgrow==1){
                    potatoMine->bomb();
                    connect(BurnMovie, &QMovie::finished,this,&Zombie::killSelf);
                    Burn();
                }else{
                    Attack();
                    potatoMine->HP-=2;
                    isPlant=1;
                }
            }
            break;
        }
        case 4:
        {
            CherryBomb *cherryBomb=static_cast<CherryBomb*>(item);
            if(cherryBomb->isbomb==1)
            {
                connect(BurnMovie, &QMovie::finished,this,&Zombie::killSelf);
                Burn();
            }
        }
        default:
            break;
        }
    }
    if(isWalk==0 && isPlant==0)
    {
        Walk();
    }
    isPlant=0;
    if(iswear&&HP<=270)
    {
        WalkMovie->setFileName(":/zombie/images/ZombieWalk1.gif");
        AttackMovie->setFileName(":/zombie/images/ZombieAttack.gif");
        DieMovie->setFileName(":/zombie/images/ZombieDie.gif");
        if (WalkMovie->state() == QMovie::Running) {
            WalkMovie->stop();
            WalkMovie->start();
        }
        if (AttackMovie->state() == QMovie::Running) {
            AttackMovie->stop();
            AttackMovie->start();
        }
        iswear=0;
    }
}
int Zombie::ItemKind(QGraphicsItem *item)
{
    if(typeid(*item)==typeid(Pea)||typeid(*item)==typeid(PeaSnow))
        return 1;
    if(typeid(*item)==typeid(SunFlower)||typeid(*item)==typeid(SnowPea)||typeid(*item)==typeid(PeaShooter))
        return 2;
    if(typeid(*item)==typeid(WallNut)||typeid(*item)==typeid(Repeater))
        return 2;
    if(typeid(*item)==typeid(PotatoMine))
        return 3;
    if(typeid(*item)==typeid(CherryBomb))
        return 4;
    return 0;
}
void Zombie::death()
{
    WalkMovie->stop();
    AttackMovie->stop();
    connect(DieMovie, &QMovie::finished,this,&Zombie::stopQMovie);
    DieMovie->start();
    setPos(pos().x()-30,pos().y());
    //僵尸头
    ZombieHead *Head =new ZombieHead;
    Head->setPos(pos().x()+60,pos().y());
    scene()->addItem(Head);
    QTimer::singleShot(2000, this, &Zombie::killSelf);
}
void Zombie::Burn()
{
    WalkMovie->stop();
    AttackMovie->stop();
    DieMovie->stop();
    BurnMovie->start();
}
void Zombie::killSelf()
{
    scene()->removeItem(this);
    delete WalkMovie;
    delete AttackMovie;
    delete DieMovie;
    delete BurnMovie;
    delete this;
}
