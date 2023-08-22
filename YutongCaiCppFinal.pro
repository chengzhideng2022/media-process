QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    models/customizedenemy.cpp \
    models/gameworld.cpp \
    models/poisonedtile.cpp \
    models/positonsearchworld.cpp \
    pathplanner.cpp \
    views/choosemap.cpp \
    views/commandedit.cpp \
    views/dashboard.cpp \
    views/gamescreen.cpp \
    views/gameview.cpp \
    views/gamewidget.cpp \
    views/graphicactor.cpp \
    views/graphicenemy.cpp \
    views/graphicgamewidget.cpp \
    views/graphichp.cpp \
    views/graphicpenemy.cpp \
    views/graphicsprot.cpp \
    views/textenemy.cpp \
    views/textgamewidget.cpp \
    views/texthp.cpp \
    views/textpenemy.cpp \
    views/textpoisonedtile.cpp \
    views/textprot.cpp \
    worldfactory.cpp

HEADERS += \
    gametype.h \
    mainwindow.h \
    models/customizedenemy.h \
    models/gameworld.h \
    models/poisonedtile.h \
    models/positonsearchworld.h \
    pathplanner.h \
    views/choosemap.h \
    views/commandedit.h \
    views/dashboard.h \
    views/gamescreen.h \
    views/gameview.h \
    views/gamewidget.h \
    views/graphicactor.h \
    views/graphicenemy.h \
    views/graphicgamewidget.h \
    views/graphichp.h \
    views/graphicpenemy.h \
    views/graphicsprot.h \
    views/textenemy.h \
    views/textgamewidget.h \
    views/texthp.h \
    views/textpenemy.h \
    views/textpoisonedtile.h \
    views/textprot.h \
    worldfactory.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target





win32:CONFIG(release, debug|release): LIBS += -L$$PWD/world/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/world/debug/ -lworld
else:unix:!macx: LIBS += -L$$PWD/world/ -lworld

INCLUDEPATH += $$PWD/world
DEPENDPATH += $$PWD/world

RESOURCES += \
    image.qrc
