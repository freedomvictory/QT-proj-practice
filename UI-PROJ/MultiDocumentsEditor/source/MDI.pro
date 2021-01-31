QT += core testlib 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = MDI 

TEMPLATE = app 

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
CONFIG += application


application {
    SOURCES += 
    HEADERS += 
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
