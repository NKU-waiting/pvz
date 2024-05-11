#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<QMovie>
#include<QTimerEvent>
#include"plant/plant.h"
class Zombie: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Zombie(const QString path,QGraphicsPixmapItem *parent=nullptr);
    ~Zombie();
    void death();
    int ItemKind(QGraphicsItem *item);
    int row;
    QMovie *WalkMovie;
    QMovie *AttackMovie;
    QMovie *DieMovie;
    int HP=270;
    int iswear=0;
    int ZombieKind;
    int isWalk=1;
    int isPlant=0;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
private slots:
    void updateWalk();
    void updateAttack();
    void updateDie();
    void Walk();
    void Attack();
    void stopQMovie();
    void killSelf();
private:
    int timerId;
    int isdead=1;
};

#endif // ZOMBIE_H
