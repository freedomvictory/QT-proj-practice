#include "myserialport.h"
#include <QDebug>
#include <QObject>
#include <QByteArray>
#include <QCoreApplication>


MyserialPort::MyserialPort(QObject *parent) : QObject(parent)
{

}

MyserialPort::MyserialPort(
        QString name,
        qint32 baudRate,
        QSerialPort::DataBits dbits,
        QSerialPort::Parity parity,
        QSerialPort::StopBits sbits,
        QSerialPort::FlowControl flow, QObject *parent) : QObject(parent)
{
    /*set serial message*/
    m_serial->setPortName(name);
    m_serial->setBaudRate(baudRate);
    m_serial->setDataBits(dbits);
    m_serial->setParity(parity);
    m_serial->setStopBits(sbits);
    m_serial->setFlowControl(flow);


    struct SerialOption so;
    m_option = &so;
    /*save serial message*/
    m_option->name = name;
    m_option->baudRate = baudRate;
    m_option->dataBits = dbits;
    m_option->parity = parity;
    m_option->stopBits = sbits;
    m_option->flowControl = flow;

    connect(m_serial, &QSerialPort::readyRead, this, &MyserialPort::readData);
    connect(m_serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error), this, &MyserialPort::handleError);


}

MyserialPort::~MyserialPort()
{

    /*relase m_serial*/
    if(m_serial)
    {
        close();
        delete m_serial;
        m_serial = nullptr;
    }
}

bool MyserialPort::open(){
    return m_serial->open(QIODevice::ReadOnly);
}
void MyserialPort::close(){
    if(m_serial->isOpen())
    {
        m_serial->close();
    }
}
void MyserialPort::readData(){

    qDebug() << "recv data\n";
    qDebug() << m_serial->readAll();






}




void MyserialPort::handleError(QSerialPort::SerialPortError error)
{
    qDebug() << "SerialPortError:" << error << m_serial->errorString() << "\n";
    if(error == QSerialPort::ReadError)
    {
        qDebug() << QObject::tr("An I/O error occured while reading the data from port %1, error: %2").arg(m_serial->portName()).arg(m_serial->errorString());
        QCoreApplication::exit(1);
    }
    //TODO
}

