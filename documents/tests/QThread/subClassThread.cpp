#include <QtTest/QtTest>
#include <QThread> 

//From this example 
//we got : 子类化QThread , 在里边定义槽。槽执行的时候对应的线程，不是新线程，而是实例化Thread 的线程。 
//If we define SLOT On you own subclass Thread.  When the slot is executed , the corresponding thread is not new thread but the old thread 
class Caller : public QObject 
{
    Q_OBJECT
signals:
    void operate();
public:
    void startOper(){
        emit operate();
    }
    
};

class Mythread: public QThread
{
    Q_OBJECT
public:
    explicit Mythread(Caller *sender){
        connect(sender, &Caller::operate, this, &Mythread::doSomeWork);
    }
    ~Mythread(){
        quit();
        wait(); 
        qDebug() << "Mythread delete"; 
    }
protected:
    void run() override{
        qDebug() << "thread id:" << QThread::currentThreadId();
        exec(); 
    } 
public slots: 
    void doSomeWork(){
        qDebug() << "slots -> thread id:" << QThread::currentThreadId();
    }

};

class TestThread : public QObject
{
    Q_OBJECT
private slots:
    void run(){
        Caller c; 
        Mythread _thread(&c); 
        _thread.start(); 
        QTest::qWait(5 * 100);
        c.startOper();
        QTest::qWait(5 * 1000);     
    }
};

QTEST_MAIN(TestThread)

#include "subClassThread.moc"




