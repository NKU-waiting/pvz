#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<QMovie>
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
    QMovie *movie;
};

#endif // PLANT_H
