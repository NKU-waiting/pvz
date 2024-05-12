#include "plant.h"
#include"other/scene.h"
Plant::Plant(const QString &PlantImagePath,QGraphicsPixmapItem *parent)
: QGraphicsPixmapItem(parent), movie(new QMovie(this))
{
    setGifPath(PlantImagePath);
    connect(movie, &QMovie::frameChanged, this, &Plant::update);
}
Plant::~Plant()
{
    delete movie;
}
void Plant::update()
{
    setPixmap(movie->currentPixmap());
    if(HP<=0)
    {
        movie->stop();
        isOccupied[row][line]=1;
        killTimer(timerId);
        scene()->removeItem(this);
    }
}
void Plant::setGifPath(const QString &path)
{
    // 设置 GIF 文件的路径并启动动画
    movie->setFileName(path);
    movie->setSpeed(100); // 设置播放速度为正常速度的1.5倍
    movie->start();
}
