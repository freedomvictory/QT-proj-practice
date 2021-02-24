#ifndef __CONNECTION_H 
#define __CONNECTION_H 

#include <QtSql> 
#include <QDebug> 
#include <QtXml> 

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("windowspc");
    db.setDatabaseName("data.db");
    db.setUserName("dingguoliang");
    db.setPassword("123456");

    if(! db.open())
        return false; 
    
    QSqlQuery query; 
    //create classfication table 
    query.exec("create table type(id varchar primary key, name varchar)");
    query.exec(QString("insert into type values('0', '请选择类型')"));
    query.exec(QString("insert into type values('01', '电视')"));
    query.exec(QString("insert into type values('02', '空调')"));
    query.exec(QString("insert into type values('03', '冰箱')"));

    //create brand table 
    query.exec("create table brand(id varchar primary key, name varchar, "
               "type varchar, price int, sum int, sell int, last int)");
    query.exec(QString("insert into brand values('01', '海信', '电视', 3699, 50, 10, 40)"));
    query.exec(QString("insert into brand values('02', '创维', '电视', 3499, 20, 5, 15)"));
    query.exec(QString("insert into brand values('03', '海尔', '电视', 4199, 80, 40, 40)"));
    query.exec(QString("insert into brand values('04', '王牌', '电视', 3999, 40, 10, 30)"));
    query.exec(QString("insert into brand values('05', '海尔', '空调', 2899, 60, 10, 50)"));
    query.exec(QString("insert into brand values('06', '格力', '空调', 2799, 70, 20, 50)"));
    query.exec(QString("insert into brand values('07', '美的', '冰箱', 2999, 100, 15, 85)"));
    query.exec(QString("insert into brand values('08', '海尔', '冰箱', 3499, 70, 10, 60)"));
    //create password table 
    query.exec("create table password(pwd varchar primary key)");
    query.exec("insert into password values('123456')");

    return true; 
}
//create xml file 
static bool createXml() 
{
    QFile file("data.xml");
    if(file.exists())
        return true; 
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return false;
    //construct QDomDocument  
    QDomDocument doc; 
    QDomProcessingInstruction instruction; 
    instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement(QString("日销售清单"));
    doc.appendChild(root); 
    //save QDomDocument to file 
    QTextStream out(&file); 
    doc.save(out, 4);
    file.close(); 

    return true; 
}













#endif 