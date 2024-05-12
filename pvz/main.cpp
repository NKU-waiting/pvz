#include <QGraphicsView>
#include "other/scene.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon icon(":/other/images/PVZ.ico");
    a.setWindowIcon(icon);

    Scene *scene=new Scene;
    QGraphicsView view(scene);

    view.setFixedSize(900,600);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();

    return a.exec();
}
