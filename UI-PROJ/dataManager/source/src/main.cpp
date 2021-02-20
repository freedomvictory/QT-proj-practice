#include "connection.h"
#include <QTextCodec>
#include <QApplication>
#include "mainWidget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    if(!createConnection())
        return 0;
    mainWidget w;
    w.show();
    return app.exec();

}