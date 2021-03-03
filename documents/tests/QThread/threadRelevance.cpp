#include <QThread> 
#include <QtTest/QtTest> 
#include <QTimer> 
#include <QDebug> 


class MyThread: public QThread 
{
public:
    explicit MyThread();
protected:
    void run() override;
private:
    QTimer m_timer; 
};

MyThread::MyThread()
{
    //m_timer need to move to this thread!!!
    //Otherwise it will report an error 
    m_timer.moveToThread(this); 
    connect(&m_timer, &QTimer::timeout, [](){
        qDebug() << "timer timeout!";
    });
}

void MyThread::run()
{
    m_timer.start(1000);
    QThread::run(); 
}

class TestThread: public QObject 
{
    Q_OBJECT
private slots:
    void runThread(); 
};

void TestThread::runThread()
{
    MyThread a; 
    a.start(); 
    QTest::qWait(3000);
}

QTEST_MAIN(TestThread)
#include "threadRelevance.moc"