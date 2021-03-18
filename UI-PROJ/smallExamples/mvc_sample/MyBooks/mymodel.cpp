#include "mymodel.h"
#include <QDebug>
#include <QBrush>
#include <QFont>
#include <QTime>
#include <QTimer>

MyModel::MyModel(QObject* parent)
    :QAbstractTableModel(parent)
{
    /*timer : every second send `dataChanged` signal*/
    auto timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerHint()));
    timer->start();

}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return 3;
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
#define TIMER


    int row = index.row();
    int col = index.column();
    //generate debug message
    qDebug() << QString("row %1, col%2, role %3")
               .arg(row).arg(col).arg(role);

    QVector<QString> books = {"Qt Creator 快速入门", "Qt on Android 核心编程", "C++ Primer"};
    QStringList authors;
    authors << QString("霍亚飞") << QString("安晓辉") << QString("Stanley B.Lippman 等");



    switch (role) {
    case Qt::DisplayRole:
#ifdef TIMER
        if(row == 0 && col == 0)
        {
            return QTime::currentTime().toString();
        }
#endif
        if(index.column() == 0)
            return books[row];
        else
            return authors.at(row);

        break;

    case Qt::BackgroundRole:
        if(col == 0)
            return QBrush(Qt::yellow);
        break;
    case Qt::FontRole:
        if(col == 0 && row == 1)
        {
            QFont boldFont;
            boldFont.setBold(true);
            return boldFont;
        }
        break;
    default:
        break;
    }

    return QVariant();
}

void MyModel::timerHint()
{
    QModelIndex topLeft = createIndex(0, 0);
    emit dataChanged(topLeft, topLeft);
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch (section) {
            case 0:
                return QString("first");
            case 1:
                return QString("second");
            default:
                break;
            }
        }
    }
    return QVariant();
}
