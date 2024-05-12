QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    other/car.cpp \
    other/card.cpp \
    other/cardbackground.cpp \
    other/pause.cpp \
    other/scene.cpp \
    other/shop.cpp \
    other/shovel.cpp \
    other/shovelbank.cpp \
    other/win.cpp \
    plant/cherrybomb.cpp \
    plant/pea.cpp \
    plant/peashooter.cpp \
    plant/peasnow.cpp \
    plant/plant.cpp \
    plant/potatomine.cpp \
    plant/repeater.cpp \
    plant/snowpea.cpp \
    plant/sun.cpp \
    plant/sunflower.cpp \
    plant/wallnut.cpp \
    zombie/basiczombie.cpp \
    zombie/bucketzombie.cpp \
    zombie/conezombie.cpp \
    zombie/footballzombie.cpp \
    zombie/zombie.cpp \
    zombie/zombiehead.cpp

HEADERS += \
    other/car.h \
    other/card.h \
    other/cardbackground.h \
    other/pause.h \
    other/scene.h \
    other/shop.h \
    other/shovel.h \
    other/shovelbank.h \
    other/win.h \
    plant/cherrybomb.h \
    plant/pea.h \
    plant/peashooter.h \
    plant/peasnow.h \
    plant/plant.h \
    plant/potatomine.h \
    plant/repeater.h \
    plant/snowpea.h \
    plant/sun.h \
    plant/sunflower.h \
    plant/wallnut.h \
    zombie/basiczombie.h \
    zombie/bucketzombie.h \
    zombie/conezombie.h \
    zombie/footballzombie.h \
    zombie/zombie.h \
    zombie/zombiehead.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    other/image.qrc
