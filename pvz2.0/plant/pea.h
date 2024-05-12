#ifndef PEA_H
#define PEA_H

#include <QObject>
#include <QGraphicsPixmapItem>
class Pea: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pea(QGraphicsPixmapItem *parent=nullptr);
protected:
    virtual void timerEvent(QTimerEvent *event) override;
};

#endif // PEA_H
