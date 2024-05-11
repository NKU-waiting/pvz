#include "zombiehead.h"
#include<QTimer>
#include <QGraphicsScene>
ZombieHead::ZombieHead(QGraphicsPixmapItem *parent)
:movie(new QMovie(this))
{
    movie->setFileName(":/zombie/images/ZombieHead.gif");
    movie->setSpeed(40); // 设置播放速度为正常速度的0.5倍
    movie->start();
    QTimer::singleShot(2000, this, &ZombieHead::killSelf);
    connect(movie, &QMovie::frameChanged,this, &ZombieHead::updateQPixmap);
    connect(movie, &QMovie::finished,this,&ZombieHead::stopQMovie);
}
void ZombieHead::updateQPixmap()
{
    setPixmap(movie->currentPixmap());
}
void ZombieHead::stopQMovie()
{
    movie->stop();
}
void ZombieHead::killSelf()
{
    scene()->removeItem(this);
    delete movie;
    delete this;
}
