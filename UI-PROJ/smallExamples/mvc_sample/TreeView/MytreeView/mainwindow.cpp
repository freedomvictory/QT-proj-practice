#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTreeView>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTreeView* treeView = new QTreeView(this);
    setCentralWidget(treeView);

    QStandardItemModel *standModel = new QStandardItemModel;

    QList<QStandardItem *> firstRow = prepareRow("first", "second", "third");
    QStandardItem* rootItem = standModel->invisibleRootItem();
    rootItem->appendRow(firstRow);

    QList<QStandardItem* > secondRow = prepareRow("111", "222", "333");
    firstRow.first()->appendRow(secondRow);

    treeView->setModel(standModel);
    treeView->expandAll();


}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<QStandardItem *> MainWindow::prepareRow(const QString &first, const QString &second, const QString &third)
{
    QList<QStandardItem *> rowItems;

    rowItems << new QStandardItem(first);
    rowItems << new QStandardItem(second);
    rowItems << new QStandardItem(third); \

    return rowItems;
}
