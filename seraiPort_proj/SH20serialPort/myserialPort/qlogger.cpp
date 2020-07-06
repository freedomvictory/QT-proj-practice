#include "qlogger.h"
#include <QDebug>




Qlogger::Qlogger(QString path)
{
    m_file = new QFile(path);
    m_path = &path;
}
bool Qlogger::Open()
{
    if(!m_file->open(QIODevice::WriteOnly))
    {
        qDebug() << "Fail to open file:" << m_path;
        return false;
    }
    return true;
}
Qlogger::~Qlogger()
{
    delete m_file;
    m_file = nullptr;

    delete m_path;
    m_path = nullptr;

}

void Qlogger::WriteString(char *str)
{
   m_file->write(str);
   m_file->flush();
}


void Qlogger::Close()
{
    if(m_file->isOpen())
    {
        m_file->close();
    }
}

