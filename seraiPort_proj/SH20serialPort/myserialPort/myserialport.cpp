#include "myserialport.h"
#include <QDebug>

MyserialPort::MyserialPort(QObject *parent) : QObject(parent)
{

}

MyserialPort::MyserialPort(
                               QString name,
                               QString stringBaudRate,
                               QString stringBits,
                               QString stringParity,
                               QString stringStopBits,
                               QString stringFlowControl
                               )
{
   //TODO:
   // Complete it !
   qDebug() << name << stringBaudRate << stringBits << stringParity << stringStopBits << stringFlowControl;

}
MyserialPort::MyserialPort(
               QString& name,
               qint32 baudRate,
               QSerialPort::DataBits dbits,
               QSerialPort::Parity parity,
               QSerialPort::StopBits sbits,
               QSerialPort::FlowControl flow)
{
    /*set serial message*/
    m_serial->setPortName(name);
    m_serial->setBaudRate(baudRate);
    m_serial->setDataBits(dbits);
    m_serial->setParity(parity);
    m_serial->setStopBits(sbits);
    m_serial->setFlowControl(flow);


    /*save serial message*/
    m_option->name = name;
    m_option->baudRate = baudRate;
    m_option->dataBits = dbits;
    m_option->parity = parity;
    m_option->stopBits = sbits;
    m_option->flowControl = flow;

    connect(m_serial, &QSerialPort::readyRead, this, &MyserialPort::readData);


}

MyserialPort::~MyserialPort()
{

    if(m_option)
    {
        delete m_option;
        m_option = nullptr;
    }
}

bool MyserialPort::open(){
    return m_serial->open(QIODevice::ReadWrite);
};
void MyserialPort::close(){
    if(m_serial->isOpen())
    {
        m_serial->close();
    }
};
void MyserialPort::readData(){

    QByteArray data = m_serial->readAll();
    qDebug() << "data:" << data;


};
void MyserialPort::writeData(const QByteArray &data){



};
void MyserialPort::handleError(QSerialPort::SerialPortError error){
    //TODO
};

