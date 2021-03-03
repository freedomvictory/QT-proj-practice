#include <QtTest/QTest> 
#include <QFile> 
#include <QXmlStreamReader> 
#include <QDebug> 




class TestXML : public QObject
{
    Q_OBJECT
private slots:
    void test__tokenType();
    void readSpecifyElement(); 
    void test__Method__ReadNextStartElement(); 

};

//测试tooken 
void TestXML::test__tokenType() 
{
    QFile file("c:\\Users\\dingguoliang\\Documents\\my.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text))
        qFatal("Error: cannot open file"); 

    QXmlStreamReader reader; 
    reader.setDevice(&file); 

    while(!reader.atEnd())
    {
        QXmlStreamReader::TokenType type = reader.readNext(); 

        switch (type)
        {
        case QXmlStreamReader::StartDocument:
            qDebug() << reader.documentEncoding() << reader.documentVersion(); 
            break;
        case QXmlStreamReader::StartElement:
            qDebug() << "<" << reader.name() << ">"; 
            if(reader.attributes().hasAttribute("id"))
                qDebug() << reader.attributes().value("id"); 
            break; 
        case QXmlStreamReader::EndElement:
            qDebug() << "</" << reader.name() << ">"; 
            break;
        case QXmlStreamReader::Characters:
            if(!reader.isWhitespace()) 
                qDebug() << reader.text(); 
            break; 
        default:
            break;
        }
    }
    qDebug() << "----------------------";
    file.close(); 
}

void TestXML::readSpecifyElement() 
{

    QFile file("c:\\Users\\dingguoliang\\Documents\\my.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text))
        qFatal("Error: cannot open file"); 

    QXmlStreamReader reader; 
    reader.setDevice(&file); 

    while(!reader.atEnd())
    {
        QXmlStreamReader::TokenType type = reader.readNext();
        if(type == QXmlStreamReader::StartElement 
        && reader.name() == "bookmark"
        && reader.attributes().hasAttribute("href")
        && reader.attributes().value("href") == "http://doc.qt.io/" )
        {
            reader.readNextStartElement();
            qDebug() << reader.readElementText();
        
            break; 
        }    
    }
    file.close();
}


/*探究 QXmlStreamReader::readNextStartElement 何时会失败
当 current element下，没有下一个元素可读时 
*/

void TestXML::test__Method__ReadNextStartElement()
{
    QFile file("c:\\Users\\dingguoliang\\Documents\\my.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text))
        qFatal("Error: cannot open file"); 

    QXmlStreamReader reader; 
    reader.setDevice(&file); 
    if(reader.readNextStartElement() && reader.name() == "xbel")
    {
        //current Element: xbel 
        if(reader.readNextStartElement() && reader.name() == "folder")
        {
            //current Element: folder 
            if(reader.readNextStartElement() && reader.name() == "title")
            {
                //current Element: title 
                QCOMPARE(reader.readNextStartElement() , false);
                //qDebug() << reader.errorString();
            }
            else 
                qFatal("Fail to read title");
        }
        else 
            qFatal("Fail to read folder");
    }
    else 
        qFatal("Fail to read xbel");

    file.close();
}

QTEST_MAIN(TestXML)

#include "testXmlReader.moc"







