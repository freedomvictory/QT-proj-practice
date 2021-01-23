QT += core testlib 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = TESTS 

TEMPLATE = app 

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
CONFIG += testJSON

testQString {
    SOURCES += QString/testQstring.cpp 
    HEADERS += 
}

testJSON {
    SOURCES += JSON/testjson.cpp 
    HEADERS += 
}



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
