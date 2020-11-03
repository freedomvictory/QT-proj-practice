#include "mymainwindow.h"
#include "ui_mymainwindow.h"


myMainWindow::myMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myMainWindow)
{

    ui->setupUi(this);
    QString str = ui->pushButton->getName();
    ui->pushButton->setText(str);
}

myMainWindow::~myMainWindow()
{
    delete ui;
}
