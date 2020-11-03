#include "sortdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortDialog w;
    w.SetColumnRange('A', 'F');
    w.show();

    return a.exec();
}
