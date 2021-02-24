#include "mywidget.h"
#include "ui_mywidget.h"

#include <QtSql>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    model(new QSqlTableModel(this))
{
    ui->setupUi(this);

    model->setTable("student");
    model->select();
    // set edit stragety
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

}

Widget::~Widget()
{
    delete ui;
}
//展示整张表
void Widget::on_pushButton_displayTotTab_clicked()
{
    model->setTable("student");
    model->select();
}
//根据名称查询
void Widget::on_pushButton_query_clicked()
{
    QString name = ui->lineEdit->text();
    model->setFilter(QString("name='%1'").arg(name));
    model->select();
}
//添加记录
void Widget::on_pushButton_addRecord_clicked()
{
    int rowNum = model->rowCount();
    int id = 10;
    model->insertRow(rowNum);
    model->setData(model->index(rowNum, 0), id);
}
//提交修改
void Widget::on_pushButton_commit_clicked()
{
    model->database().transaction();
    if(model->submitAll())
    {
        if(model->database().commit())
            QMessageBox::information(this, tr("tableModel"), tr("data changed sucessfuly!"));
    }
    else
    {
        model->database().rollback();
        QMessageBox::warning(this, tr("table model"), tr("database error:%1").arg(model->lastError().text()), QMessageBox::Ok);
    }
}
//撤销修改：针对未提交的数据库操作
void Widget::on_pushButton_revert_clicked()
{
    model->revertAll();
}
//删除选中行
void Widget::on_pushButton_delete_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this, tr("delete current line!"), tr("Did you true delete it?"),
                                  QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
        model->revertAll();
    else
        model->submitAll();

}
//升序排序
void Widget::on_pushButton_Asce_clicked()
{
    model->setSort(0, Qt::AscendingOrder);
    model->select();
}
//降序排序
void Widget::on_pushButton_Desc_clicked()
{
    model->setSort(0, Qt::DescendingOrder);
    model->select();
}
