//! [0]
#include <QtTest/QTest>
#include "myserialPort.h"
#include <QDebug>
#include <QThread>



class TestMyserialPort: public QObject
{
    Q_OBJECT
private slots:
    void open_read_serial();
};
//! [0]

//! [1]
void TestMyserialPort::open_read_serial()
{
    TestSerailPort *myserial = new TestSerailPort("COM8");


    if(myserial->open())
    {
        QThread::msleep(10 * 1000);
    }
    else
    {
        qDebug() << "Fail to open serial";
    }
    QCOMPARE("HELLO", "hello");
}
//! [1]


//! [2]
QTEST_MAIN(TestMyserialPort)
#include "testmyserialport.moc"
//! [2]
