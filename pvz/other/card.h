#ifndef CARD_H
#define CARD_H

#include<QGraphicsItem>
#include<QPainter>
#include<QTimer>
class card:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    card(QGraphicsItem *parent = nullptr);
    int kind;//kind 表示植物种类，0-向日葵，1-豌豆射手，2-寒冰射手，3-双发射手，4-坚果，5-土豆地雷，6-樱桃炸弹
    int cardCD=7500;
    int x,y;
    double scale;
    int Price;
    QString PlantImagePath;
    int isblack=0;
    QTimer *timer;
    int n=150;
    int Originaln=150;
protected:
    int isPlant=1;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void setPlant(QPointF position);
    void CardCD();
    void updatemap();
    QRectF boundingRect() const override {
        return QRectF(0, 0, 50,70);
    }
private:
    QPointF OriginalPosition;
    card *tempCard= nullptr;
};

#endif // CARD_H
