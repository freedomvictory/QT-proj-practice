#include <QStringList> 
#include <QDebug> 
#include <QObject> 
#include <QtTest/QtTest> 
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver> 
#include <QSqlRecord> 
#include <QSqlField> 
#include <QString> 
#include <QSqlError>



class TestSqlStatment :public QObject{
Q_OBJECT
private slots:
    void initTestCase();
    void testQueryNormal();
    void testQueryAbNormal();
    void testInsert();
    void cleanTestCase();

private:
    QSqlDatabase db;

};

void TestSqlStatment::initTestCase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
    if(!db.open())
    {
        qFatal("unable to establish a database connection");
    }
    QSqlQuery query(db);
    query.exec("DELETE FROM students");
    //create table and insert some data item 
    query.exec("create table students(id int primary key,"
                "name varchar(20)) if not exist");
    query.exec("INSERT INTO students (id, name) VALUES"
              "(0, 'LiMing'),"
              "(1, 'WangHua'),"
              "(2, 'XiaoHong'),"
              "(3, 'Gavin');");
}

void TestSqlStatment::testQueryNormal()
{
    
    QSqlQuery query(db);
    query.exec("SELECT *FROM students ");

    int numRows = 0; 
    if(db.driver()->hasFeature(QSqlDriver::QuerySize))
    {
        qDebug() << "has feature : query size";
        numRows = query.size();           
    }
    else 
    {
        qDebug() << "no feature: query size";
        query.last();
        numRows = query.at() + 1; 
    }
    //got the row number 
    qDebug() << "row number: " << numRows;     
    //modify the index to 1 is the second record 
    query.seek(1);
    qDebug() << "current index :" << query.at(); 
    //got current line record 
    QSqlRecord record = query.record(); 
    int id = record.value("id").toInt();
    QString name = record.value("name").toString();
    qDebug() << "current id, current name:" << id << "," << name; 
    //got index 1 record 
    QSqlField field = record.field(1);
    qDebug() << "second field :" << field.name() 
             << "field value:" << field.value().toString(); 
}

void TestSqlStatment::testInsert()
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO students(id, name) values(:id, :name)");
    //insert one line data 
    int idValue = 100;
    QString nameValue = "ChenYun";
    query.bindValue(":id", idValue);
    query.bindValue(":name", nameValue);
    query.exec();  

    //insert multiple lines 
    query.prepare("INSERT INTO students(id, name) values(?, ?)");
    QVariantList ids, names;
    ids << 20 << 21 << 22 << 23;
    names << "xiaozhu" << "yunfan" << "xiaohei" << "xiahou"; 
    query.addBindValue(ids);
    query.addBindValue(names);

    if(!query.execBatch())
        qDebug() << query.lastError();

    
}

// The result of select , find it or not find it 
void TestSqlStatment::testQueryAbNormal()
{
    //NORMAL
    QSqlQuery query(db);
    bool ok = query.exec("SELECT *FROM students WHERE id = 2");
    bool ok_first = query.first();
    qDebug() << "id = 2 select return value:" << ok;
    qDebug() << "id = 2 first() ret val: " << ok_first; //return true 
    QSqlRecord r = query.record();
    int id = r.value("id").toInt();
    QString name = r.value("name").toString();
    qDebug() << "record id: " << id << "name:" << name; 


    //ABNORMAL: Can't find id = 5
    ok = query.exec("SELECT *FROM students WHERE id = 5");
    qDebug() << "id = 5 select return value:" << ok;
    ok_first = query.first();
    qDebug() << "id = 5 first() ret val: " << ok_first; //return false 
    r = query.record();
    id = r.value("id").toInt();
    name = r.value("name").toString();
    qDebug() << "record id: " << id << "name:" << name; 

}

void TestSqlStatment::cleanTestCase()
{
    
}
QTEST_MAIN(TestSqlStatment)

#include "testSqlStatement.moc"
