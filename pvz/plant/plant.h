#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<QMovie>
#include"other/pause.h"
class Plant : public QObject,public QGraphicsPixmapItem
{
public:
    int line,row=0;
    Plant(const QString &PlantImagePath,QGraphicsPixmapItem *parent=nullptr);
    ~Plant();
    void update();
    void setGifPath(const QString &path);
    int HP=300;
    int timerId;
    int iskilltimerId=1;
    QMovie *movie;
};

#endif // PLANT_H
