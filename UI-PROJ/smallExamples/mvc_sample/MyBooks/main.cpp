#include "mywidget.h"
#include <QApplication>
#include <QTableView>
#include <mymodel.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableView;
    MyModel model(0);
    tableView.setModel(&model);
    tableView.show();

    return a.exec();
}
