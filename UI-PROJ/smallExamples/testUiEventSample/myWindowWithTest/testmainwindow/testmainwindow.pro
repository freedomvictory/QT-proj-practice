QT += testlib
QT += gui widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app
INCLUDEPATH += ../myWindow
SOURCES +=  tst_mainwindowtest.cpp \
            ../myWindow/mainwindow.cpp
HEADERS +=  \
        ../myWindow/mainwindow.h

FORMS += \
        ../myWindow/mainwindow.ui
