#include "gridcell.h"

GridCell::GridCell(int x, int y, int width, int height, QGraphicsItem *parent)
: QGraphicsRectItem(QRectF(x, y, width, height), parent)
{
    setVisible(false);//设置为不可见
    isOccupied=false;
}
