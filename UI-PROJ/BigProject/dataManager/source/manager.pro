QT += core gui sql xml 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = manager

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
CONFIG += application
CONFIG += console
INCLUDEPATH += ./header/


application {
    SOURCES += src/main.cpp \
               src/mainWidget.cpp 
    HEADERS += header/connection.h \
               header/mainWidget.h  
    FORMS += ui/mainWidget.ui 
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target