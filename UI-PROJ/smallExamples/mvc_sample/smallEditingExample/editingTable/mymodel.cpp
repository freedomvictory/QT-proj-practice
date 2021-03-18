#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}


int MyModel::rowCount(const QModelIndex &parent) const
{
    return ROWS;
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return COLS;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if(role == Qt::DisplayRole)
    {
        return m_gridData[row][col];
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();
    int col = index.column();

    if(role == Qt::EditRole)
    {
        m_gridData[row][col] = value.toString();
        QModelIndex topLeft = createIndex(row, col);
        emit dataChanged(topLeft, topLeft);

        QString result;
        for(int i = 0; i < ROWS; i++)
            for(int j = 0; j < COLS; j++)
                result += m_gridData[i][j] + ' ';
        emit editCompleted(result);
    }
    return true;

}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
