#include "ui_mainWidget.h"
#include "mainWidget.h"
#include <QtSql>
#include <QSplitter>
#include <QMessageBox> 

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    setFixedSize(750, 500);
    ui->stackedWidget->setCurrentIndex(0);
    //set `sellTypeComboBox` content
    QSqlQueryModel *typeModel = new QSqlQueryModel(this);
    typeModel->setQuery("select name from type");
    ui->sellTypeComboBox->setModel(typeModel);
    //use `QSplitter` layout the toolbox and listWidget 
    QSplitter *splitter = new QSplitter(ui->managePage);
    splitter->resize(700, 360);
    splitter->move(0, 50);
    splitter->addWidget(ui->toolBox);
    splitter->addWidget(ui->daliyList);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 1);


}

mainWidget::~mainWidget()
{
    delete ui;
}

void mainWidget::on_sellTypeComboBox_currentIndexChanged(QString type)
{
    if(type == "请选择类型")
    {
        //clear other component content 
        on_sellCancelBtn_clicked();
    }
    else 
    {
        ui->sellBrandComboBox->setEnabled(true);
        QSqlQueryModel *model = new QSqlQueryModel(this);
        model->setQuery(QString("select name from brand where type = '%1'").arg(type)); 
        ui->sellBrandComboBox->setModel(model);
        ui->sellCancelBtn->setEnabled(true);
    }
}
void mainWidget::on_sellCancelBtn_clicked()
{
    ui->sellTypeComboBox->setCurrentIndex(0);
    ui->sellBrandComboBox->clear();
    ui->sellBrandComboBox->setEnabled(false);
    ui->sellPriceLineEdit->clear();
    ui->sellPriceLineEdit->setEnabled(false);
    ui->sellNumSpinBox->setValue(0);
    ui->sellNumSpinBox->setEnabled(false);
    ui->sellSumLineEdit->clear();
    ui->sellSumLineEdit->setEnabled(false);
    ui->sellOkBtn->setEnabled(false);
    ui->sellCancelBtn->setEnabled(false);
    ui->sellLastNumLabel->setVisible(false);
}


void mainWidget::on_sellBrandComboBox_currentIndexChanged(QString brand)
{
    //clear sell number control and sell sum price control ,disable them.  
    ui->sellNumSpinBox->setValue(0);
    ui->sellNumSpinBox->setEnabled(false);
    ui->sellSumLineEdit->clear();
    ui->sellSumLineEdit->setEnabled(false);
    ui->sellOkBtn->setEnabled(false); //disable ok button 
    //query unit price , update `sellPriceLineEdit`
    QSqlQuery query; 
    query.exec(QString("select price from brand where name ='%1' and type = '%2'").arg(brand)
    .arg(ui->sellTypeComboBox->currentText()));
    query.next();
    ui->sellPriceLineEdit->setEnabled(true);
    ui->sellPriceLineEdit->setReadOnly(true);
    ui->sellPriceLineEdit->setText(query.value(0).toString());
    //query last number of commodity, update `sellNumSpinBox` and `sellLastNumLabel`
    query.exec(QString("select last from brand where name = '%1' and type = '%2'").arg(brand)
    .arg(ui->sellTypeComboBox->currentText()));
    query.next();
    int num = query.value(0).toInt(); 
    if(num == 0)
        QMessageBox::information(this, tr("prompt"), tr("This commodity has sold out!"), QMessageBox::Ok);
    else 
    {
        ui->sellNumSpinBox->setEnabled(true);
        ui->sellNumSpinBox->setMaximum(num); 
        ui->sellLastNumLabel->setText(QString("剩余数量:%1").arg(num));
        ui->sellLastNumLabel->setVisible(true); 
    }
}
void mainWidget::on_sellNumSpinBox_valueChanged(int value)
{
    if(value == 0)
    {
        ui->sellSumLineEdit->clear(); 
        ui->sellSumLineEdit->setEnabled(false); 
        ui->sellOkBtn->setEnabled(false);
    }
    else 
    {
        ui->sellSumLineEdit->setEnabled(true); 
        qreal sum = value * ui->sellPriceLineEdit->text().toInt(); 
        ui->sellSumLineEdit->setText(QString::number(sum));
        ui->sellOkBtn->setEnabled(true);
    }
    
}