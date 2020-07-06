#ifndef QLOGGER_H
#define QLOGGER_H

#include <QFile>
class Qlogger
{
public:
    explicit Qlogger(QString path);
    ~Qlogger();
    bool Open();
    void Close();
    void WriteString(char* str);


private:

    QFile *m_file;
    QString *m_path;


};

#endif // QLOGGER_H
