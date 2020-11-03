#include "mywidget.h"
#include <QApplication>
#include "keytest.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // mywidget w;

    keyTest w;
    w.show();

    return a.exec();
}
