#include "cform.h"
#include "ui_cform.h"

CForm::CForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm)
{
    ui->setupUi(this);
}

CForm::~CForm()
{
    delete ui;
}

void CForm::on_pushButton_A_clicked()
{
    emit go_aForm();
}
