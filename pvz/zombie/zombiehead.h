#ifndef ZOMBIEHEAD_H
#define ZOMBIEHEAD_H

#include <QGraphicsPixmapItem>
#include<QMovie>
class ZombieHead: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ZombieHead(QGraphicsPixmapItem *parent=nullptr);
private slots:
    void updateQPixmap();
    void stopQMovie();
    void killSelf();
private:
    QMovie *movie;
};

#endif // ZOMBIEHEAD_H
