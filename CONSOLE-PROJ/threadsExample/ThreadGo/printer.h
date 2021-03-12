#ifndef PRINTER_H
#define PRINTER_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QMutex>

class Printer {

public:
    void doWork(QVector<char> words);

private:
    int m_id;
    QMutex __mutex;
};

class Thread_a : public QThread {
    Q_OBJECT
public:
    Thread_a(Printer* p)
        : __printer(p) {}
protected:
    void run() override;
private:
    Printer* __printer;
};

class Thread_b : public QThread {
    Q_OBJECT
public:
    Thread_b(Printer* p)
        : __printer(p) {}
protected:
    void run() override;

private:
    Printer* __printer;

};



#endif // PRINTER_H
