# QTest 


## introduction 

`Qt Test` is a framework for unit testing Qt based applications and libraries. `Qt Test` provides all the functionality commonly found in unit testing framework as well as extensions for testing graphical user interfaces 



## unit testing  

To create a test , subclass `QObject` and add one or more private slots to it . Each private slot is test function in your test. But there are four private slots are not trated as test functions. They will be used to initlize and clean up resources 

- `initTestCase()` will be called before the first test function is executed.
- `cleanupTestCase()` will be called after the last test function was executed.
- `init()` will be called before each test function is executed.
- `cleanup()` will be called after every test function.

## a helloWorld example 

```
//pro file 
QT += widgets testlib

SOURCES = testqstring.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target 
```

```cpp
// cpp file
#include <QtTest/QtTest>

class TestQString: public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
};

void TestQString::toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN(TestQString)
#include "testqstring.moc"
```


## more 

`https://doc-snapshots.qt.io/qt5-5.9/qtest-overview.html`