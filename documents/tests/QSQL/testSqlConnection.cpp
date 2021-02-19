#include <QStringList> 
#include <QDebug> 
#include <QObject> 
#include <QtTest/QtTest> 
#include <QSqlDatabase>
#include <QSqlQuery>

class TestSqlConnection : public QObject {
Q_OBJECT
private slots:
    void testCreateAndOper();


};

void TestSqlConnection::testCreateAndOper()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if(!db.open())
    {
        qFatal("unable to establish a database connection");
    }
    QSqlQuery query(db);
    //create table and insert some data item 
    query.exec("create table students(id int primary key,"
                "name varchar(20))");
    query.exec("insert into students values(0, 'LiMing')");
    query.exec("insert into students values(1, 'LiuHao')");
    //query data 
    query.exec("select *from students");

    qDebug() << "query results:";
    while(query.next())
    {
        qDebug() << query.value(0).toInt() << ","  << query.value(1).toString(); 
    }
}

QTEST_MAIN(TestSqlConnection)

#include "testSqlConnection.moc"





