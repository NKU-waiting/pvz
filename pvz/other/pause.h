#ifndef PAUSE_H
#define PAUSE_H
#include<QGraphicsPixmapItem>
#include <QObject>

class Pause:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pause(QGraphicsPixmapItem *parent=nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};
extern bool iscontinue;
#endif // PAUSE_H
