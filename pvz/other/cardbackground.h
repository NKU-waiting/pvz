#ifndef CARDBACKGROUND_H
#define CARDBACKGROUND_H

#include <QGraphicsItem>

class CardBackground :public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    CardBackground(QGraphicsItem *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void updatepaint();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QRectF boundingRect() const override {
        return QRectF(0, 0, 100,140);
    }
    QPointF OriginalPosition;
    int isblack=0;
};

#endif // CARDBACKGROUND_H
