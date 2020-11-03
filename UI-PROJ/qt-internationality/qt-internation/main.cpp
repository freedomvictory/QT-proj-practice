#include "mymainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("../qt-internation/myI18n_zh_CN.qm");
    a.installTranslator(&translator);
    myMainWindow w;
    w.show();

    return a.exec();
}
