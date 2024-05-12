#include "pause.h"
#include"scene.h"
bool iscontinue;
Pause::Pause(QGraphicsPixmapItem *)
{
    setPixmap(QPixmap(":/other/images/Button.png"));
    setScale(1.5);
    iscontinue=true;
}
void Pause::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(iscontinue)
    {
        textItem->setPlainText("Continue");
        iscontinue=!iscontinue;
        return;
    }
    if(!iscontinue)
    {
        textItem->setPlainText("Pause");
        iscontinue=!iscontinue;
        return;
    }
}
