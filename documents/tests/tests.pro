QT += core testlib sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test 

TEMPLATE = app 

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
CONFIG += word

testQString {
    SOURCES += QString/testQstring.cpp 
    HEADERS += 
}

testJSON {
    SOURCES += JSON/testjson.cpp 
    HEADERS += 
}

testSQL {
    SOURCES += QSQL/testSqlStatement.cpp 
    HEADERS += 
}

word {
    QT += axcontainer 
    SOURCES += Word/main.cpp \
               Word/wordengine.cpp 
    HEADERS += Word/wordengine.h 
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
