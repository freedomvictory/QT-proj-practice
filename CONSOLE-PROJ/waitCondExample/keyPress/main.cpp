#include <QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

QMutex mutex;
QWaitCondition keyPressed;
int count = 0;




class ReadKeyPressThread : public QThread
{
protected:
    void run() override
    {
        forever
        {
           char c = getchar();
           qDebug() << "ReadKeyPressThread: read char --> " << c;
           mutex.lock();
           while(count > 0)
           {
               mutex.unlock();
               sleep(1);
               mutex.lock();
           }
           keyPressed.wakeAll();
           qDebug() << "ReadKeyPressThread: wake all";
           mutex.unlock();
        }
    }
};

class HandleThingThread : public QThread
{
protected:
    void run() override
    {
        forever
        {
            mutex.lock();
            qDebug() << QThread::currentThreadId() << " waiting :" ;
            keyPressed.wait(&mutex);
            ++count;
            mutex.unlock();
            /*do something*/
            qDebug() << QThread::currentThreadId()  << " running :"
                     << "do something";

            mutex.lock();
            --count;
            mutex.unlock();
        }
    }
};









int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ReadKeyPressThread* rp_thread = new ReadKeyPressThread;
    HandleThingThread* ht_threads = new HandleThingThread[3];
    for(int i = 0; i < 3; i++)
        ht_threads[i].start();
    QThread::sleep(1);
    rp_thread->start();

    return a.exec();
}
