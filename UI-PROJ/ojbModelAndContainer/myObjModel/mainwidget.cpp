#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "mydialog.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    myDialog *dlg = new myDialog(this);

    connect(dlg, SIGNAL(dlgReturn(int)), this, SLOT(showValue(int)));
    dlg->show();
}

mainWidget::~mainWidget()
{
    delete ui;
}

void mainWidget::showValue(int value)
{
    ui->label->setText(tr("获取的值是：%1").arg(value));
}
