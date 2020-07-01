#include <QtTest/QTest>
#include "testserailport.h"
#include <QDebug>
#include <QThread>


class TESTtestserailport: public QObject
{
    Q_OBJECT

private slots:
    void open_read_serial();
};

void TESTtestserailport::open_read_serial()
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
}


//! [3]
QTEST_MAIN(TESTtestserailport)
#include "moc_predefs.h"
//! [3]
