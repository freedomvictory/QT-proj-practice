QT += core testlib sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test 

TEMPLATE = app 

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
CONFIG += testSmartPointer 

testQString {
    SOURCES += QString/testQstring.cpp 
    HEADERS += 
}

testJSON {
    SOURCES += JSON/testjson.cpp 
    HEADERS += 
}

testSQL {
    SOURCES += QSQL/testSqlModel.cpp 
    HEADERS += QSQL 
}

word {
    QT += axcontainer 
    SOURCES += Word/main.cpp \
               Word/wordengine.cpp 
    HEADERS += Word/wordengine.h 
}

testThread {
    SOURCES += QThread/subClassThread.cpp 
    HEADERS += 
}
testXML {
    SOURCES += xml/testXmlWriter.cpp 
    HEADERS += 
}
testSmartPointer {
    SOURCES += smartPointer/weakPointer.cpp 
    HEADERS += 
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
