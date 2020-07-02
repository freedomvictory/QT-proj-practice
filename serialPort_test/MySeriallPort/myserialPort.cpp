#include "myserialPort.h"
#include <QObject>
#include <QCoreApplication>



TestSerailPort::TestSerailPort(
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
TestSerailPort::TestSerailPort(
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

    connect(m_serial, &QSerialPort::readyRead, this, &TestSerailPort::readData);


}

TestSerailPort::~TestSerailPort()
{

    if(m_option)
    {
        delete m_option;
        m_option = nullptr;
    }
}

bool TestSerailPort::open(){
    return m_serial->open(QIODevice::ReadWrite);
};
void TestSerailPort::close(){
    if(m_serial->isOpen())
    {
        m_serial->close();
    }
};
void TestSerailPort::readData(){

    QByteArray data = m_serial->readAll();
    qDebug() << "data:" << data;


};
void TestSerailPort::writeData(const QByteArray &data){



};
void TestSerailPort::handleError(QSerialPort::SerialPortError error){
    //TODO
};
