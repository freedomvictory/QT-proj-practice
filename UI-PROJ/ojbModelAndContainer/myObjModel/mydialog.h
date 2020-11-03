#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = nullptr);
    ~myDialog();

private:
    Ui::myDialog *ui;

signals:
    void dlgReturn(int); //customize signals

private slots:
    void on_pushButton_clicked();
};

#endif // MYDIALOG_H
