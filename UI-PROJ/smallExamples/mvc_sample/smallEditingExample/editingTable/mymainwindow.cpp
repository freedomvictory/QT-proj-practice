#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include "mymodel.h"

myMainWindow::myMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myMainWindow)
{
    ui->setupUi(this);
    MyModel *model = new MyModel(this);
    ui->tableView->setModel(model);
    connect(model, SIGNAL(editCompleted(QString)), this, SLOT(setMainWindowTitle(QString)));

}

myMainWindow::~myMainWindow()
{
    delete ui;
}

void myMainWindow::setMainWindowTitle(const QString &title)
{
    setWindowTitle(title);
}
