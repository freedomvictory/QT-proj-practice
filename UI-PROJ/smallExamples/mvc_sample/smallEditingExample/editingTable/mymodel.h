#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QString>
#include <QAbstractTableModel>

const int ROWS = 2;
const int COLS = 3;

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel(QObject* parent);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QString m_gridData[ROWS][COLS];
signals:
    void editCompleted(const QString&);
};

#endif // MYMODEL_H
