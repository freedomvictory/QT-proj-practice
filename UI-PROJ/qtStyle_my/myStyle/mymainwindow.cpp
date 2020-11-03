#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QStyleFactory>
#include <QPalette>

myMainWindow::myMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myMainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setStyle(QStyleFactory::create("windows"));
    QPalette palette1 = ui->pushButton->palette();

    palette1.setColor(QPalette::ButtonText, Qt::black);
    palette1.setColor(QPalette::Button, Qt::green);
    ui->pushButton->setPalette(palette1);

    ui->spinBox->setDisabled(true);
    QPalette palette2 = ui->spinBox->palette();

    palette2.setColor(QPalette::Disabled, QPalette::Base, Qt::blue);
    ui->spinBox->setPalette(palette2);

}

myMainWindow::~myMainWindow()
{
    delete ui;
}
