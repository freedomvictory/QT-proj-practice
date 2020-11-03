#include "widget_split.h"
#include "ui_widget_split.h"

widget_split::widget_split(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_split)
{
    ui->setupUi(this);
}

widget_split::~widget_split()
{
    delete ui;
}
