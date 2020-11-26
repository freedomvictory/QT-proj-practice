# QT Debug message 


# redirect `qDebug,qWarning,qCritical` output 


You can install a message handler using [`qInstallMsgHandler`](https://doc.qt.io/qt-5/qtglobal.html#qInstallMessageHandler) function 
 

Look at the fllowing example 

```c++ 
#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>

void myMessageHandler(QtMsgType type, const QMessageLogContext &, const QString & msg)
{
    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
    break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
    break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
    break;
    }
    QFile outFile("log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}

int main( int argc, char * argv[] )
{
    QApplication app( argc, argv );
    qInstallMessageHandler(myMessageHandler);   
    ...
    return app.exec();
}
```

