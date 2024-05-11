#ifndef CARD_H
#define CARD_H
#include<QGraphicsItemGroup>
class card:public QGraphicsItemGroup
{
public:
    card(const QString &plantImagePath,const int price, QGraphicsItem *parent = nullptr,int x_value=0,int y_value=0,double Scale=0.5);
    int kind;//kind 表示植物种类，0-向日葵，1-豌豆射手，2-寒冰射手，3-双发射手，4-坚果，5-土豆地雷，6-樱桃炸弹
protected:
    int x,y;
    double scale;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override ;
    void setPlant(QPointF position);
private:
    int Price;
    QString PlantImagePath;
    QPointF OriginalPosition;
    card *tempCard= nullptr;
};

#endif // CARD_H
