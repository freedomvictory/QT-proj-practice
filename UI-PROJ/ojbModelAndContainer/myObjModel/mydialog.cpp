#include "mydialog.h"
#include "ui_mydialog.h"

#include <QPushButton>

myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
    //connect(ui->pushButton, &QPushButton::clicked, this, SLOT(on_pushButton_clicked()));
}

myDialog::~myDialog()
{
    delete ui;
}

void myDialog::on_pushButton_clicked()
{
    int value = ui->spinBox->value();
    emit dlgReturn(value);
    close();
}

