#include <QCoreApplication>
#include "myserialport.h"
#include <QDebug>
#include <QThread>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    MyserialPort *sh20_device = new MyserialPort("/dev/ttyUSB0");
    if(sh20_device->open())
    {
        qDebug() << "open success";

        qDebug() << "sleep call ,delay 30 seconds";
        QThread::sleep(30);
    }
    else
    {
       qDebug() << "open fail";
    }

    sh20_device->close();
    delete sh20_device;
    sh20_device = nullptr;


    return a.exec();
}
