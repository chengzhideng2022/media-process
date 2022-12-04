QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    worldcontroller.cpp

HEADERS += \
    ../world_v5/world.h \
    ../world_v5/world_global.h \
    mainwindow.h \
    world.h \
    worldcontroller.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../world_v5/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../world_v5/debug/ -lworld
else:unix: LIBS += -L$$PWD/../world_v5/ -lworld

INCLUDEPATH += $$PWD/../world_v5
DEPENDPATH += $$PWD/../world_v5

RESOURCES += \
    img.qrc
