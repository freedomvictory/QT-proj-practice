#include <QCoreApplication>
#include "myserialport.h"
#include <QDebug>
#include <QFile>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream qtin(stdin);


    MyserialPort *sh20_device = new MyserialPort("/dev/ttyUSB0");
    if(sh20_device->open())
    {
        qDebug() << "open success";



    }
    else
    {
       qDebug() << "open fail";
    }

    QString line = qtin.readLine();
    /*
    sh20_device->close();
    delete sh20_device;
    sh20_device = nullptr;
    */

    return a.exec();
}
