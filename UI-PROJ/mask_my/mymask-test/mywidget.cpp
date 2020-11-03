#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    QPixmap pixmap(":/image/gouzi.jpg");
    ui->label->setPixmap(pixmap);
    ui->label->setMask(pixmap.mask());
}

myWidget::~myWidget()
{
    delete ui;
}
