QT += core gui 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = MDI 

TEMPLATE = app 

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
CONFIG += application
CONFIG += console 
INCLUDEPATH += ./header/


application {
    SOURCES += src/main.cpp \
               src/mainwindow.cpp \
               src/mdichild.cpp 

    HEADERS += header/mdichild.h \
               header/mainwindow.h
    FORMS += UI/mainwindow.ui
    RESOURCES += resource/myImage.qrc   
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
