#include <QtTest>
#include <QCoreApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"




// add necessary includes here

class mainwindowTEST : public QObject
{
    Q_OBJECT

public:
    mainwindowTEST();
    ~mainwindowTEST();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

private:
    MainWindow *w;
};

mainwindowTEST::mainwindowTEST()
    :w(new MainWindow)
{
    w->show();
}

mainwindowTEST::~mainwindowTEST()
{
    w->close();
    delete w;
}

void mainwindowTEST::initTestCase()
{

}

void mainwindowTEST::cleanupTestCase()
{

}

void mainwindowTEST::test_case1()
{
    auto btn = w->ui->pushButton;
    auto lineEdit = w->ui->lineEdit;

    QTest::mouseClick(btn, Qt::LeftButton);
    QCOMPARE(lineEdit->text(), QString("hello"));


}

QTEST_MAIN(mainwindowTEST)

#include "tst_mainwindowtest.moc"
