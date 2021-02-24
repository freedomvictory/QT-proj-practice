#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
class QSqlTableModel;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:


    void on_pushButton_displayTotTab_clicked();
    void on_pushButton_query_clicked();
    void on_pushButton_addRecord_clicked();
    void on_pushButton_commit_clicked();

    void on_pushButton_revert_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_Asce_clicked();

    void on_pushButton_Desc_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;

};

#endif // MYWIDGET_H
