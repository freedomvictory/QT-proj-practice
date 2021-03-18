#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_standardModel(new QStandardItemModel)
{
    ui->setupUi(this);
    setCentralWidget(ui->treeView);

    QStandardItem* rootNode = m_standardModel->invisibleRootItem();

    //defining a couple of items
    QStandardItem *americaItem = new QStandardItem("America");
    QStandardItem *mexicoItem =  new QStandardItem("Canada");
    QStandardItem *usaItem =     new QStandardItem("USA");
    QStandardItem *bostonItem =  new QStandardItem("Boston");
    QStandardItem *europeItem =  new QStandardItem("Europe");
    QStandardItem *italyItem =   new QStandardItem("Italy");
    QStandardItem *romeItem =    new QStandardItem("Rome");
    QStandardItem *veronaItem =  new QStandardItem("Verona");

    //first level
    rootNode->appendRow(americaItem);
    rootNode->appendRow(europeItem);
    //second level
    americaItem->appendRow(mexicoItem);
    americaItem->appendRow(usaItem);
    europeItem->appendRow(italyItem);\
    //third level
    usaItem->appendRow(bostonItem);
    italyItem->appendRow(romeItem);
    italyItem->appendRow(veronaItem);

    ui->treeView->setModel(m_standardModel);
    ui->treeView->expandAll();

    QItemSelectionModel* selectionModel = ui->treeView->selectionModel();
    connect(selectionModel, SIGNAL(selectionChanged(const QItemSelection &,const QItemSelection &)),
            this, SLOT(selectionChangeSlot(const QItemSelection &,const QItemSelection &)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectionChangeSlot(const QItemSelection &, const QItemSelection &)
{
    //got selected text
    const QModelIndex index = ui->treeView->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    //got current selected item hierarchy Level
    int hierarchyLevel = 1;
    QModelIndex seekRoot = index;
    while(seekRoot.parent() != QModelIndex())
    {
        seekRoot = seekRoot.parent();
        hierarchyLevel++;
    }

    QString showStr = QString("%1, level %2").arg(selectedText).arg(hierarchyLevel);
    setWindowTitle(showStr);
}
