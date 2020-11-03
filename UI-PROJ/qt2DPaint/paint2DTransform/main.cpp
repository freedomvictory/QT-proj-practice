#include "mywidget.h"
#include <QApplication>
#include "simpleanimation.h"
#include "drawpathwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //myWidget w;
    //simpleAnimation w;
    drawPathWidget w;
    w.show();

    return a.exec();
}
