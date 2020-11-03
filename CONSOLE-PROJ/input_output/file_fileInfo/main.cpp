#include <QCoreApplication>
#include <QFileInfo>
#include <QStringList>
#include <QDateTime>
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //write file contents
    QFile my_file("myfile.txt");
    if(!my_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << my_file.errorString();
    }

    my_file.write("hello QT! \nyafeilinux");
    my_file.close();

    //got file info
    QFileInfo my_file_info(my_file);
    qDebug() << QObject::tr("absolute path:") << my_file_info.absolutePath() << endl;
    qDebug() << QObject::tr("file name:") << my_file_info.fileName() << endl;
    qDebug() << QObject::tr("base name:") << my_file_info.baseName() << endl;
    qDebug() << QObject::tr("fiel create time:") << my_file_info.created() << endl;


    return a.exec();
}
