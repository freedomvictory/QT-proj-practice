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
    ui->toolBox->setCurrentIndex(0);
    //set `sellTypeComboBox` content
    QSqlQueryModel *typeModel = new QSqlQueryModel(this);
    typeModel->setQuery("select name from type");
    ui->sellTypeComboBox->setModel(typeModel);
    //update `goodsTypeComboBox` content
    //ui->goodsTypeComboBox->setModel(typeModel);

    //use `QSplitter` layout the toolbox and listWidget 
    QSplitter *splitter = new QSplitter(ui->managePage);
    splitter->resize(700, 360);
    splitter->move(0, 50);
    splitter->addWidget(ui->toolBox);
    splitter->addWidget(ui->daliyList);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 1);
    //reset the component status 
    on_sellCancelBtn_clicked();

    showDailyList(); 

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

void mainWidget::on_sellOkBtn_clicked() 
{
    QString type = ui->sellTypeComboBox->currentText(); 
    QString name = ui->sellBrandComboBox->currentText(); 

    int value = ui->sellNumSpinBox->value(); 
    int last = ui->sellNumSpinBox->maximum() - value; 

    QSqlQuery query;
    query.exec(QString("select sell from brand where name = '%1' and type = '%2'").arg(name).arg(type)); 
    query.next(); 
    int sell = query.value(0).toInt() + value;

    QSqlDatabase::database().transaction(); 
    bool ok = query.exec(
        QString("UPDATE brand SET sell = %1, last = %2 WHERE name = '%3' AND type = '%4'")
        .arg(sell).arg(last).arg(name).arg(type)
    );
    if(ok)
    {
        QSqlDatabase::database().commit(); 
        QMessageBox::information(this, tr("prompt"), tr("purchase successfuly"), QMessageBox::Ok); 
        writeXml(); 
        showDailyList(); 
        on_sellCancelBtn_clicked();
    }
    else 
    {
        QSqlDatabase::database().rollback();
        QMessageBox::information(this, tr("prompt"), tr("purchase failed :%1 ").arg(query.lastError().text()), QMessageBox::Ok);
    }
}

QString mainWidget::getDateTime(DataTimeType type)
{
    QDateTime datetime = QDateTime::currentDateTime();
    if (type == Date)
        return datetime.toString("yyyy-MM-dd");
    else if(type == Time)
        return datetime.toString("hh:mm");
    else 
        return datetime.toString("yyyy-MM-dd dddd hh:mm");       
}

bool mainWidget::docRead() 
{
    QFile file("data.xml"); 
    if(!file.open(QIODevice::ReadOnly))
        return false; 
    if(!doc.setContent(&file))
    {
        file.close(); 
        return false; 
    }
    file.close(); 
    return true; 
}

bool mainWidget::docWrite() 
{
    QFile file("data.xml"); 
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return false; 
    QTextStream out(&file); 
    doc.save(out, 4); 
    file.close(); 
    return true; 
}

void mainWidget::writeXml()
{
    if(docRead())
    {
        QString currentDate = getDateTime(Date); 
        QDomElement root = doc.documentElement(); 
        if(!root.hasChildNodes())
        {
            QDomElement date = doc.createElement(QString("日期")); 
            QDomAttr curDate = doc.createAttribute("date");
            curDate.setValue(currentDate);
            date.setAttributeNode(curDate); 
            root.appendChild(date); 
            createNodes(date); 
        }
        else 
        {
            QDomElement date = root.lastChild().toElement(); 
            if(date.attribute("date") == currentDate)
                createNodes(date); 
            else 
            {
                QDomElement date = doc.createElement(QString("日期")); 
                QDomAttr curDate = doc.createAttribute("date");
                curDate.setValue(currentDate);
                date.setAttributeNode(curDate); 
                root.appendChild(date); 
                createNodes(date);      
            }
        }
        docWrite(); 
    }

}

void mainWidget::createNodes(QDomElement &date) 
{
    QDomElement time = doc.createElement(QString("时间"));
    QDomAttr curTime = doc.createAttribute("time");
    curTime.setValue(getDateTime(Time)); 
    time.setAttributeNode(curTime); 
    date.appendChild(time); 

    QDomElement type = doc.createElement(QString("类型"));
    QDomElement brand = doc.createElement(QString("品牌"));
    QDomElement price = doc.createElement(QString("单价"));
    QDomElement num = doc.createElement(QString("数量"));
    QDomElement sum = doc.createElement(QString("金额"));

    QDomText text;
    text = doc.createTextNode(QString("%1").arg(ui->sellTypeComboBox->currentText()));
    type.appendChild(text); 
    text = doc.createTextNode(QString("%1").arg(ui->sellBrandComboBox->currentText()));
    brand.appendChild(text);
    text = doc.createTextNode(QString("%1").arg(ui->sellPriceLineEdit->text()));
    price.appendChild(text);
    text = doc.createTextNode(QString("%1").arg(ui->sellNumSpinBox->value()));
    num.appendChild(text);
    text = doc.createTextNode(QString("%1").arg(ui->sellSumLineEdit->text()));
    sum.appendChild(text);

    time.appendChild(type);
    time.appendChild(brand);
    time.appendChild(price);
    time.appendChild(num);
    time.appendChild(sum); 

}
//Display a list of daily sales 
void mainWidget::showDailyList()
{
    ui->daliyList->clear(); 
    if(docRead())
    {
        QDomElement root = doc.documentElement(); 
        QString title = root.tagName(); 
        QListWidgetItem *titleItem = new QListWidgetItem; 
        titleItem->setText(QString("-----%1-----").arg(title));
        titleItem->setTextAlignment(Qt::AlignCenter);
        ui->daliyList->addItem(titleItem);
        if(root.hasChildNodes())
        {
            QString currentDate = getDateTime(Date);
            QDomElement dateElement = root.lastChild().toElement();
            QString date = dateElement.attribute("date"); 
            if(date == currentDate)
            {
                ui->daliyList->addItem("");
                ui->daliyList->addItem(QString("日期：%1").arg(date)); 
                ui->daliyList->addItem("");
                //add time nodes 
                QDomNodeList children =  dateElement.childNodes();
                for(int i = 0; i < children.count(); i++)
                {
                    QDomNode node = children.at(i); 
                    QString time = node.toElement().attribute("time"); 
                    QDomNodeList list = node.childNodes(); 
                    QString type = list.at(0).toElement().text(); 
                    QString brand = list.at(1).toElement().text(); 
                    QString price = list.at(2).toElement().text(); 
                    QString num = list.at(3).toElement().text(); 
                    QString sum = list.at(4).toElement().text(); 
                    QString str = time + " 出售" + brand + type + " "
                                 + num + "台，" + "单价：" + price + "元，共"
                                 + sum + "元";
                    QListWidgetItem *tempItem = new QListWidgetItem;
                    tempItem->setText("*****************************************");
                    tempItem->setTextAlignment(Qt::AlignCenter); 
                    ui->daliyList->addItem(tempItem); 
                    ui->daliyList->addItem(str); 
                }
            }
        }
    }

} 