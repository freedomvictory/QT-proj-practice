#include <QCoreApplication>
#include "myserialport.h"
#include <QDebug>
#include <QFile>
#include "qlogger.h"

/*used for debug, print log to file*/
extern Qlogger myQlogger;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*debug*/
    //myQlogger.Open();

    MyserialPort *sh20_device = new MyserialPort("/dev/ttyUSB0");
    if(sh20_device->open())
    {
        qDebug() << "open success";
    }
    else
    {
       qDebug() << "open fail";
    }


    return a.exec();
}
