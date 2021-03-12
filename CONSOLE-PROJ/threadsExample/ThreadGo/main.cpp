#include <QCoreApplication>
#include "printer.h"

/*
    author : gavin
    QMutex 的使用
    模拟打印机程序。线程A和线程B 各用打印机打印一段文字，打印机就是它们的临界资源

*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Printer p;
    Thread_a worker_a(&p);
    Thread_b worker_b(&p);

    worker_a.start();
    worker_b.start();

    return a.exec();
}
