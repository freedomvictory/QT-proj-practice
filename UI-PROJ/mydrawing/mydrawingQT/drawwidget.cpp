#include "drawwidget.h"
#include "ui_drawwidget.h"

drawWidget::drawWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawWidget)
{
    ui->setupUi(this);
}

drawWidget::~drawWidget()
{
    delete ui;
}
