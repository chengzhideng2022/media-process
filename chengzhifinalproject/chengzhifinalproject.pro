QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chosemappage.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    myitem.cpp \
    myscene.cpp

HEADERS += \
    chosemappage.h \
    mainwindow.h \
    model.h \
    myitem.h \
    myscene.h \
    world.h \
    world_global.h

FORMS += \
    chosemappage.ui \
    mainwindow.ui

TRANSLATIONS += \
    chengzhifinalproject_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Desktop/world_v5/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Desktop/world_v5/debug/ -lworld
else:unix: LIBS += -L$$PWD/../Desktop/world_v5/ -lworld

INCLUDEPATH += $$PWD/../Desktop/world_v5
DEPENDPATH += $$PWD/../Desktop/world_v5
RESOURCES += \
    img.qrc


