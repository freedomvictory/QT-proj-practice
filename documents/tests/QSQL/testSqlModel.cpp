#include <QWidget> 
#include <QtTest/QtTest> 
#include <QtSql> 
#include <QTableView> 
#include "connection.h"


class TestSqlModel : public QObject 
{
    Q_OBJECT
private slots:
    
    void testQueryModel(); 

};


void TestSqlModel::testQueryModel()
{

    createConnection(); 
    QSqlQueryModel *model = new QSqlQueryModel(this); 
    model->setQuery("select *from student");
    QTableView *view = new QTableView; 
    view->setModel(model);

    QTest::qWait(10 * 1000);

}

QTEST_MAIN(TestSqlModel)

#include "testSqlModel.moc"