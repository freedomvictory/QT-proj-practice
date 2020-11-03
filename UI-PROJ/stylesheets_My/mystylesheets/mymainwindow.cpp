#include "mymainwindow.h"
#include "ui_mymainwindow.h"

myMainWindow::myMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myMainWindow)
{
    ui->setupUi(this);
    //ui->pushButton->setStyleSheet("background:yellow");
    //ui->horizontalSlider->setStyleSheet("background:blue");

    //setStyleSheet("QPushButton{background:yellow}QSlider{background:blue}");



}

myMainWindow::~myMainWindow()
{
    delete ui;
}
