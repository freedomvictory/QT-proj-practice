#include <QtTest/QtTest> 
#include <QObject> 
#include <QString> 
#include <QDebug> 



class TestQString : public QObject 
{
    Q_OBJECT 
private slots:
    void initTestCase() {

    }

    void TestFloatToString();


};

void TestQString::TestFloatToString()
{

    float val = 0.25; 
    QString val_str; 
    val_str.sprintf("%%%.0f",(float)( val * 100));

    int val_int = (int)(val * 100);

    qDebug() << "val_str:" << val_str;
    qDebug() << "val_int:" << val_int; 

}





QTEST_MAIN(TestQString)
#include "testQstring.moc"

