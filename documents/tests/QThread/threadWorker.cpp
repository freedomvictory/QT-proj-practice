#include <QThread> 
#include <QtTest/QtTest> 
#include <QDebug> 


class Worker : public QObject 
{
    Q_OBJECT
public:
    ~Worker(){qDebug() << "Worker::~Worker()";}
public slots:
    void doWork(const QString &parameter){
        /*do some work*/
        qDebug() << "Worker::doWork start";
        resultReady(parameter + ",world");
        qDebug() << "Worker::doWork over";
    }
signals:
    void resultReady(const QString &result);
};

class Controller : public QObject 
{
    Q_OBJECT 
    QThread workerThread;
public:
    Controller(){
        Worker *worker = new Worker; 
        worker->moveToThread(&workerThread);
        connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater); 
        connect(this, &Controller::operate, worker, &Worker::doWork); 
        connect(worker, &Worker::resultReady, this, &Controller::handleResult);
        workerThread.start(); 
    }
    ~Controller(){
        qDebug() << "~Controller()"; 
        workerThread.quit(); 
        workerThread.wait(); 

    }
    void startWork(){
        emit operate("hello");
    }
public slots:
    void handleResult(const QString &res){
        qDebug() << "Controller::handlerResult->" << res;  
    }
signals:
    void operate(const QString &); 
};


class TestUseWorkerThread : public QObject 
{
    Q_OBJECT 
private slots:
    void run(); 
};

//测试线程结束时，信后和槽执行顺序 
void TestUseWorkerThread::run() 
{
    Controller __controller; 
    QTest::qWait(200); 
    __controller.startWork(); 
    QTest::qWait(5 * 1000); 
    
}

QTEST_MAIN(TestUseWorkerThread)

#include "threadWorker.moc"


