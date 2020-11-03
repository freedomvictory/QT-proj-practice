#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QStandardItemModel>
#include <QDebug>



myMainWindow::myMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myMainWindow)
{
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel(7, 4, this);
    for(int row = 0; row < 7; ++row)
    {
        for(int column = 0; column < 4; ++column)
        {
            QStandardItem *item = new QStandardItem(QString("%1").arg(row * 4 + column) );
            model->setItem(row , column, item);
        }
    }
    tableView = new QTableView;
    tableView->setModel(model);
    setCentralWidget(tableView);

    QItemSelectionModel *selectionModel = tableView->selectionModel();

    QModelIndex topLeft, bottomRight;
    topLeft = model->index(1,1, QModelIndex());
    bottomRight = model->index(5, 2, QModelIndex());
    QItemSelection selection(topLeft, bottomRight);

    selectionModel->select(selection, QItemSelectionModel::Select);
}

myMainWindow::~myMainWindow()
{
    delete ui;
}
