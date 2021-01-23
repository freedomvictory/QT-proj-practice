#include "bform.h"
#include "ui_bform.h"

BForm::BForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BForm)
{
    ui->setupUi(this);
}

BForm::~BForm()
{
    delete ui;
}

void BForm::on_pushButton_C_clicked()
{
    emit go_cForm();
}
