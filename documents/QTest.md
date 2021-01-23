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

## So import about event loop 

The QT event loop needs `QCoreApplication::exec()` support , but on `QTest`, There was no code called `QCoreApplication::exec()`. That means, If you want to test asynchronous calls like `m_socket->connectToHost()`. The Qtest function will can't receive any signal. and test will be fail. 

So , how did solve this problem.


>using QSignalSpy

Look at the following example 

```c++
void CommunicationProtocolTest::testConnectToCammera()
{
    //spy will drag the singal you want 
   QSignalSpy spy(communicationProtocol->m_socket, SIGNAL(connected()));
    communicationProtocol->connectToCamera();

    // wait returns true if 1 or more signals was emitted
    QCOMPARE(spy.wait(250), true);

    // You can be pedantic here and double check if you want
    QCOMPARE(spy.count(), 1);
}
```

Refer to [stackoverflow](https://stackoverflow.com/questions/21606125/qt-event-loop-and-unit-testing) and 
[qt.io](https://doc.qt.io/qt-5/qsignalspy.html)

## qt sleep function  


>`QTest::qSleep(int ms)`

Sleeps for *ms* milliseconds, blocking execution of the test. `qSleep()` will not do any event processing and leave your test unresponsive. Network communication might time out while sleeping. 


>`QTest::qWait()`

Waits for *ms* milliseconds, While waiting , events will be processed and your test will stay responsive to user interface events or network communication.

## QTEST SKIP function 

>`QSKIP()`

由测试函数调用。用来停止此测试函数的执行。也就是说可忽略此测试函数，执行下一个。 
