#include <QtTest/QtTest>
#include <QWeakPointer>
#include <QSharedPointer> 
#include <QDebug> 



class WeakPtr : public QObject
{
    Q_OBJECT

private slots:
    void TestUseIt();


};



void WeakPtr::TestUseIt() 
{

    QSharedPointer<int> __sharedPtr(new int(32));
    QWeakPointer<int> __weakPointer(__sharedPtr);
    {
        QSharedPointer<int> __another_sharePtr(__sharedPtr);
        __weakPointer = __another_sharePtr; 
    }
    if(!__weakPointer.isNull())
    {
        qDebug() << "__weakPointer is not empty";
        auto data = *__weakPointer.toStrongRef();
        qDebug() << data;
    }
}

QTEST_MAIN(WeakPtr)

#include "weakPointer.moc"