#ifndef CONNECTION_H
#define CONNECTION_H


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if(!db.open())
    {
        qDebug() << "open db fail:" << db.lastError();
        return false;
    }
    QSqlQuery query;
    query.exec("CREATE TABLE student(id int primary key,"
               "name varchar, course int)");
    query.exec("INSERT INTO student values(1, '李强', 11)");
    query.exec("INSERT INTO student values(2, '马亮', 11)");
    query.exec("INSERT INTO student values(3, '孙红', 12)");

    return true;
}











#endif // CONNECTION_H
