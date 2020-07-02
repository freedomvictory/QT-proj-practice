#ifndef TESTSERAILPORT_H
#define TESTSERAILPORT_H

#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QObject>
#include <QByteArray>
#include <QTimer>
#include <QTextStream>


struct SerialOption;
class TestSerailPort : public QObject
{
    Q_OBJECT

public:

    TestSerailPort(
                   QString name,
                   QString stringBaudRate = "9600",
                   QString stringBits = "8",
                   QString stringParity = "None",
                   QString stringStopBits = "1",
                   QString stringFlowControl = "None");
    TestSerailPort(
                   QString& name,
                   qint32 baudRate = 9600,
                   QSerialPort::DataBits dbits = QSerialPort::Data8,
                   QSerialPort::Parity parity = QSerialPort::NoParity,
                   QSerialPort::StopBits sbits = QSerialPort::OneStop,
                   QSerialPort::FlowControl flow = QSerialPort::NoFlowControl);

    ~TestSerailPort();

    /*basic user interface*/

    bool open();
    void close();

private slots:

    void readData();
    void writeData(const QByteArray &data);
    void handleError(QSerialPort::SerialPortError error);

private:

    /*serial port*/
    QSerialPort *m_serial;
    SerialOption *m_option;

};

/*Serial settings Option*/
struct SerialOption
{
    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
    bool localEchoEnabled;
};




#endif // TESTSERAILPORT_H
