#include "testmainwindow.h"
#include <QApplication>

//created by gavin, time: 2020/06/19
//reference book <qt crateor> p108


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testMainWindow w;
    w.show();

    return a.exec();
}
