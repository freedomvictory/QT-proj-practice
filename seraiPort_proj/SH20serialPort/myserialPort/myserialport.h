#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>


struct SerialOption;

class MyserialPort : public QObject
{
    Q_OBJECT
public:
    explicit MyserialPort(QObject *parent = nullptr);

public:

    MyserialPort(
                   QString name,
                   QString stringBaudRate = "9600",
                   QString stringBits = "8",
                   QString stringParity = "None",
                   QString stringStopBits = "1",
                   QString stringFlowControl = "None");
    MyserialPort(
                   QString& name,
                   qint32 baudRate = 9600,
                   QSerialPort::DataBits dbits = QSerialPort::Data8,
                   QSerialPort::Parity parity = QSerialPort::NoParity,
                   QSerialPort::StopBits sbits = QSerialPort::OneStop,
                   QSerialPort::FlowControl flow = QSerialPort::NoFlowControl);

    ~MyserialPort();

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


#endif // MYSERIALPORT_H
