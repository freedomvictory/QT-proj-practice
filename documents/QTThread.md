# QTThread 



```c++
//cpp file 
#include "centercontroller.h"
#include <QDebug>
#include <QThread>

CoreDPworkerThread::CoreDPworkerThread(QObject *parent)
    : QThread(parent)
{
    m_stopped = false;
}

void CoreDPworkerThread::run()
{
    QString result;

    //TODO STH
    int i = 0;
    while(!m_stopped)
    {
        i ++;
        qDebug() << "CoreDPworkerThead running " << i << " times";
        msleep(1000);
    }
    result = "over";

    emit resultReady(result);
}


void CoreDPworkerThread::stop()
{
    m_stopped = true;
}


CoreController::CoreController(QObject *parent):
    QObject (parent)
{
    CoreDPworkerThread *worker_thread = new CoreDPworkerThread(this);
    connect(worker_thread, &CoreDPworkerThread::resultReady, this, &CoreController::handleResults);
    connect(worker_thread, &CoreDPworkerThread::finished, worker_thread, &QObject::deleteLater);
    worker_thread->start();

}
void CoreController::handleResults(const QString& result)
{
    qDebug() << "CoreController::handleResults:" << result;
}

//header file 

#ifndef CENTERCONTROLLER_H
#define CENTERCONTROLLER_H

#include <QObject>
#include <QThread>


class CoreDPworkerThread: public QThread
{
    Q_OBJECT

public:
    explicit CoreDPworkerThread(QObject *parent = nullptr);
    void run() override;

    void stop();

signals:
    void resultReady(const QString &s);

private:
    volatile bool m_stopped;
};


class CoreController : public QObject
{
    Q_OBJECT
public:
    explicit CoreController(QObject *parent = nullptr);

private slots:
    void handleResults(const QString&);

};



#endif // CENTERCONTROLLER_H

```