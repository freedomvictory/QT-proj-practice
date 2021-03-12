#include <QPointer>
#include <QtTest/QtTest>
#include <QDebug> 


class Status 
{
public:
    Status() {qDebug() << "Status()"; }
    ~Status(){qDebug() << "~Status()";}

    void printStatus(const QString& status)
    {
        qDebug() << status; 
    }
};

class Module 
{
public:
    Module(const char *name): m_name(name){}
    ~Module() {m_status->printStatus(QString("%1 exit").arg(m_name));} 

    void setStatus(QSharedPointer<Status> &status)
    {
        m_status = status; 
    }



private:
    QString m_name; 
    QSharedPointer<Status> m_status; 

};


class MySharedPtr : public QObject 
{
    Q_OBJECT

private slots:
    void TestInitIt(); 


};

void MySharedPtr::TestInitIt() 
{
    Module *module1 = new Module("module one");
    {
        QSharedPointer<Status> status(new Status); 
        {
            QSharedPointer<Status> copyStatus(status);
        }
        module1->setStatus(status);
        {
            Module module2("module two");
            module2.setStatus(status); 
        }
    }
    delete module1; 

}

QTEST_MAIN(MySharedPtr)

#include "sharedPointer.moc"