#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<QMovie>
#include<QTimerEvent>
class Zombie: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Zombie(const QString path,QGraphicsPixmapItem *parent=nullptr);
    ~Zombie();
    void death();
    void Burn();
    void GameLose();
    void GameWin();
    int ItemKind(QGraphicsItem *item);
    int row;
    QMovie *WalkMovie;
    QMovie *AttackMovie;
    QMovie *DieMovie;
    QMovie *BurnMovie;
    double walkspeed=1.5;
    int attack=2;
    int HP=270;
    int iswear=0;
    int ZombieKind;
    int isWalk=1;
    int isPlant=0;
    int isGamelose=0;
protected:
    virtual void timerEvent(QTimerEvent *event) override;
private slots:
    void updateWalk();
    void updateAttack();
    void updateDie();
    void updateBurn();
    void Walk();
    void Attack();
    void stopQMovie();
    void killSelf();
private:
    int timerId;
    int isdead=1;
};

#endif // ZOMBIE_H
