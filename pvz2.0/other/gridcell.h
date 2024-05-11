#ifndef GRIDCELL_H
#define GRIDCELL_H
#include<QGraphicsRectItem>
class GridCell:public QGraphicsRectItem
{
public:
    bool isOccupied;
    GridCell(int x, int y, int width, int height, QGraphicsItem *parent = nullptr);
    int row;
    int line;
};
extern GridCell *gridcell[5][9];
#endif // GRIDCELL_H
