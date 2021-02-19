#include <QStringList> 
#include <QDebug> 
#include <QObject> 
#include <QtTest/QtTest> 
#include <QSqlDatabase>

class TestSqlDriver : public QObject{

Q_OBJECT
private slots:
    void showSupportDrvNames();

};

void TestSqlDriver::showSupportDrvNames()
{
    QStringList drivers = QSqlDatabase::drivers();
    for(auto drv : drivers)
    {
        qDebug() << drv; 
    }
}




QTEST_MAIN(TestSqlDriver)

#include "testSqlDriver.moc"



