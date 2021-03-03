#include <QtTest/QtTest> 
#include <QXmlStreamWriter> 
#include <QDebug> 


class TestXML: public QObject 
{

Q_OBJECT

private slots:
    void writeFile(); 
};

void TestXML::writeFile() 
{
    QFile file("my2.xml");
    if(!file.open(QFile::WriteOnly | QFile::Text))
        qFatal("can't open file");
    
    QXmlStreamWriter stream(&file); 
    stream.setAutoFormatting(true); 
    stream.writeStartDocument();
    stream.writeStartElement("bookmark"); 
    stream.writeAttribute("href", "http://www.qt.io/");
    stream.writeTextElement("title", "Qt Home");
    stream.writeEndElement(); 
    stream.writeEndDocument(); 

    file.close(); 
}

QTEST_MAIN(TestXML)

#include "testXmlWriter.moc"