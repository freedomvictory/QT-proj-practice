#include "mywidget.h"
#include "ui_mywidget.h"
#include "myclass.h"
#include <QDebug>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    myclass *my = new myclass(this);
    connect(my, &myclass::userNameChanged, this, &myWidget::userChanged);
    my->setUserName("yafei");
    qDebug() << "userName1:" << my->getUserName();
    my->setProperty("userName", "linux");
    qDebug() << "userName2:" << my->property("userName").toString();
}

myWidget::~myWidget()
{
    delete ui;
}
void myWidget::userChanged(QString userName)
{
    qDebug() << "userChanged" << userName;
}
