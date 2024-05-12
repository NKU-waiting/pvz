#include "scene.h"
#include"shop.h"
#include "car.h"
#include"card.h"
#include"shovelbank.h"
#include"shovel.h"
#include"pause.h"
#include"zombie/basiczombie.h"
#include"zombie/bucketzombie.h"
#include"zombie/conezombie.h"
#include"zombie/footballzombie.h"

#include <QRandomGenerator>
#include<QGraphicsTextItem>
#include<QTimer>

QTimer *timer;
int number;
int isZombie[5];
QVector<int>Linenumbers;
QVector<int>Kindnumbers;
int isOccupied[5][9];
QGraphicsTextItem *showsunshine;
QGraphicsTextItem *textItem;
int dienumber=0;
Scene::Scene(QGraphicsScene *parent)
{
    setSceneRect(0,0,900,600);
    setBackgroundBrush(QImage(":/other/images/background.png"));
    //商店并显示阳光数量
    Shop *shop=new Shop;
    addItem(shop);
    QFont font; font.setPointSize(12);
    showsunshine=new QGraphicsTextItem;
    showsunshine->setPos(100,58);
    showsunshine->setFont(font);
    showsunshine->setPlainText(QString::number(sunshine));
    addItem(showsunshine);

    Pause *pause=new Pause;
    pause->setPos(630,15);
    addItem(pause);
    textItem=new QGraphicsTextItem;
    textItem->setScale(2);
    QFont font1; font1.setPointSize(40);
    textItem->setFont(font);
    textItem->setPos(645,20);
    textItem->setPlainText("Pause");
    addItem(textItem);

    //小推车
    car *car1=new car;car1->setPos(5,100);addItem(car1);
    car *car2=new car;car2->setPos(5,200);addItem(car2);
    car *car3=new car;car3->setPos(5,300);addItem(car3);
    car *car4=new car;car4->setPos(5,400);addItem(car4);
    car *car5=new car;car5->setPos(5,500);addItem(car5);
    //铲子
    ShovelBank *shovelBank=new ShovelBank;
    shovelBank->setPos(530,10);
    addItem(shovelBank);
    Shovel *shovel=new Shovel;
    addItem(shovel);

    //初始时每个格子是可被放置植物的
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<9;j++)
        {
            isOccupied[i][j]=1;
        }
        isZombie[i]=0;
    }

    card *sunflowercard=new card;//向日葵
    sunflowercard->PlantImagePath=(":/plant/images/SunFlower.png");sunflowercard->Price=50;
    sunflowercard->setPos(160,10);sunflowercard->kind=0;
    addItem(sunflowercard);

    card *Peashootercard=new card;//豌豆射手
    Peashootercard->PlantImagePath=(":/plant/images/Peashooter.png");Peashootercard->Price=100;
    Peashootercard->setPos(212,10);Peashootercard->kind=1;
    addItem(Peashootercard);

    card *SnowPeacard=new card;//寒冰射手
    SnowPeacard->PlantImagePath=(":/plant/images/SnowPea.png");SnowPeacard->Price=175;
    SnowPeacard->setPos(264,10);SnowPeacard->kind=2;
    addItem(SnowPeacard);

    card *Repeatercard=new card;//双发射手
    Repeatercard->PlantImagePath=(":/plant/images/Repeater.png");Repeatercard->Price=200;
    Repeatercard->setPos(316,10);Repeatercard->kind=3;
    addItem(Repeatercard);

    card *Wallnutcard=new card;//坚果
    Wallnutcard->PlantImagePath=(":/plant/images/WallNut.png");Wallnutcard->Price=50;
    Wallnutcard->setPos(368,10);Wallnutcard->kind=4;Wallnutcard->cardCD=30000;
    Wallnutcard->n=600;Wallnutcard->Originaln=600;
    addItem(Wallnutcard);

    card *PotatoMinecard=new card;//土豆地雷
    PotatoMinecard->PlantImagePath=(":/plant/images/PotatoMine.png");PotatoMinecard->Price=25;
    PotatoMinecard->setPos(420,10);PotatoMinecard->kind=5;PotatoMinecard->cardCD=30000;
    PotatoMinecard->n=600;PotatoMinecard->Originaln=600;
    addItem(PotatoMinecard);

    card *CherryBombcard=new card;//樱桃炸弹
    CherryBombcard->PlantImagePath=(":/plant/images/CherryBomb.png");CherryBombcard->Price=150;
    CherryBombcard->setPos(472,10);CherryBombcard->kind=6;CherryBombcard->cardCD=50000;
    CherryBombcard->n=1000;CherryBombcard->Originaln=1000;
    addItem(CherryBombcard);

    //自动生产僵尸
    timer = new QTimer(this);
    timer->setParent(this);
    connect(timer, &QTimer::timeout, this, &Scene::produceZombie);
    timer->start(7000);//每个僵尸出现间隔
    Linenumbers = generateRandomNumbers(15,0,4);
    Kindnumbers =generateRandomNumbers(15,0,10);
    number=0;
}
QVector<int> Scene:: generateRandomNumbers(int count, int min, int max) {
    QVector<int> randomNumbers(count);
    for (int i = 0; i < count; ++i) {
        randomNumbers[i] = QRandomGenerator::global()->bounded(max - min + 1) + min;
    }
    return randomNumbers;
}
void Scene::produceZombie()
{
    if(!iscontinue)
        return;
    switch (Kindnumbers[number])
    {
    case 0:case 1:case 2:case 3:case 4:
    {
        BasicZombie *zombie=new BasicZombie();
        zombie->setPos(750,38+Linenumbers[number]*100);
        isZombie[Linenumbers[number]]++;
        zombie->row=Linenumbers[number];
        addItem(zombie);
        break;
    }
    case 5:case 6:case 7:
    {
        ConeZombie *zombie=new ConeZombie();
        zombie->setPos(750,38+Linenumbers[number]*100);
        isZombie[Linenumbers[number]]++;
        zombie->row=Linenumbers[number];
        addItem(zombie);
        break;
    }
    case 8:
    {
        BucketZombie *zombie=new BucketZombie();
        zombie->setPos(750,38+Linenumbers[number]*100);
        isZombie[Linenumbers[number]]++;
        zombie->row=Linenumbers[number];
        addItem(zombie);
        break;
    }
    case 9:
    {
        FootballZombie *zombie=new FootballZombie();
        zombie->setPos(750,38+Linenumbers[number]*100);
        isZombie[Linenumbers[number]]++;
        zombie->row=Linenumbers[number];
        addItem(zombie);
        break;
    }
    default:
        break;
    }
    number++;
    if(number==10)
    {
        timer->stop();
    }
}
