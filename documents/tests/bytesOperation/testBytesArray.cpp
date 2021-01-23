#include <QtTest/QtTest> 
#include <QVector>
#include <QObject> 
#include <QDebug> 
#include <QByteArray> 
#include <QDataStream> 






class TestBytes: public QObject{

Q_OBJECT

public:
    static void VectorOperation(QVector<int> &q);

private slots:
    void InitTestCase(){

    }
    void TestQVector();
    void TestQByteArray(); 
    void TestQDataStream();
    
};

void VectorOperation(QVector<int> &q)
{
    q.append(1);
    q.append(2);
    q.append(3);
    q.append(4);

}

void TestBytes::TestQVector()
{
    QVector<int> v; 
    VectorOperation(v);
    qDebug() << "v:" << v; 
    v.clear(); 
    qDebug() << "after cleared v:" << v; 
    v.append(1); 
    qDebug() << "after append v:" << v; 
}

void TestBytes::TestQByteArray()
{
    QByteArray bytes_x; 
    QDataStream d(&bytes_x, QIODevice::WriteOnly);
    d << quint16(23);
    d << quint8(5);

    //append operation 
    QByteArray bytes_y("hello", 5);
    bytes_x.append(bytes_y);
    qDebug() << "bytes_x" << bytes_x.toHex();

    //append single byte 
    QByteArray bytes_z("iamverygood", 11);
    for(auto i = bytes_x.begin() ; i != bytes_x.end(); i++)
    {
        bytes_z.append(*i);
    }
    for(quint8 c = 0x00; c <= 0xfe; c++)
    {
        bytes_z.append(c);
    }
    quint8 byte = 0x00;
    bytes_z.append(byte);
    bytes_z.append(byte);
    bytes_z.append(byte);
    for(int j = 0; j < bytes_x.count() ; j++ )
    {
        bytes_z.append(bytes_x[j]);
    }
    //qDebug() << "byte_z" << bytes_z.toHex(); 

    //using QDataStream 
    QDataStream stream(&bytes_x, QIODevice::WriteOnly);
    stream.device()->seek(bytes_x.count());
    stream << quint8(0xff);
    stream << quint8(0x00);
    stream << quint8(0x01);
    stream << quint8(0x02);
	//got length 
    qDebug() << "new bytes_x:" << bytes_x.toHex(); 
    qDebug() << "count: " << bytes_x.count(); 
    qDebug() << "len: " << bytes_x.length(); 
    //make empty 
    bytes_x.resize(0);
    qDebug() << "empty bytes_x:" << bytes_x.toHex();
  

}

void TestBytes::TestQDataStream()
{
    char bytes[] = {0x00, 0x00, 0x20, 0x40};
    QByteArray bytes_array;
    bytes_array.setRawData(bytes, 4);

    qDebug() << "bytes_array:" << bytes_array.toHex();

    QDataStream stream(&bytes_array, QIODevice::ReadOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    //NOTE NEED SET 
    stream.setFloatingPointPrecision(QDataStream::SinglePrecision);
    //stream.device()->seek(0);

    float data = 0; 
    stream >> data; 
    qDebug() << "data:" <<  data ;



}

QTEST_MAIN(TestBytes)

