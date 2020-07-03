#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QTextCodec>
#include <QTimer>


struct SerialOption;

class MyserialPort : public QObject
{
    Q_OBJECT
public:
    explicit MyserialPort(QObject *parent = nullptr);

    MyserialPort(
                   QString name,
                   qint32 baudRate = 9600,
                   QSerialPort::DataBits dbits = QSerialPort::Data8,
                   QSerialPort::Parity parity = QSerialPort::NoParity,
                   QSerialPort::StopBits sbits = QSerialPort::OneStop,
                   QSerialPort::FlowControl flow = QSerialPort::NoFlowControl, QObject *parent = nullptr);

    ~MyserialPort();

    /*basic user interface*/

    bool open();
    void close();

private slots:

    void readData();
    void handleError(QSerialPort::SerialPortError error);

    void timerUpdate();

private:

    /*serial port*/
    QSerialPort *m_serial = new QSerialPort();
    SerialOption *m_option;
    QTimer *m_timer = new QTimer(this);
    QByteArray *m_readData = new QByteArray();


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
