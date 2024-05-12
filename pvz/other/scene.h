#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QVector>
#include<plant/plant.h>
class Scene:public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QGraphicsScene *parent = nullptr);
    QVector<int> generateRandomNumbers(int count, int min, int max);
private slots:
    void produceZombie();
};
extern QVector<int> Linenumbers;
extern QVector<int> Kindnumbers;
extern QGraphicsTextItem *showsunshine;
extern QGraphicsTextItem *textItem;
extern int isOccupied[5][9];
extern int isZombie[5];
extern int number;
extern int dienumber;
#endif // SCENE_H
