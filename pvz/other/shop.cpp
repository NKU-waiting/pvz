#include "shop.h"
int sunshine;
Shop::Shop(QGraphicsPixmapItem *parent)
{
    sunshine=1000;//设置阳光数量
    setPixmap(QPixmap(":/other/images/Shop.png"));//图片
    setPos(85,0);//位置
}
