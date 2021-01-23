#ifndef BFORM_H
#define BFORM_H

#include <QWidget>

namespace Ui {
class BForm;
}

class BForm : public QWidget
{
    Q_OBJECT

public:
    explicit BForm(QWidget *parent = 0);
    ~BForm();

signals:

    void go_cForm();




private:
    Ui::BForm *ui;

public slots:

    void on_pushButton_C_clicked();
};

#endif // BFORM_H
