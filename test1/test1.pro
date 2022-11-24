TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Library/release/ -lEmergencyCenter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Library/debug/ -lEmergencyCenter
else:unix: LIBS += -L$$PWD/../Library/ -lEmergencyCenter

INCLUDEPATH += $$PWD/../Library
DEPENDPATH += $$PWD/../Library
