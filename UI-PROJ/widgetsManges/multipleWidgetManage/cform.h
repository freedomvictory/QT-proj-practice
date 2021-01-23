#ifndef CFORM_H
#define CFORM_H

#include <QWidget>

namespace Ui {
class CForm;
}

class CForm : public QWidget
{
    Q_OBJECT

public:
    explicit CForm(QWidget *parent = 0);
    ~CForm();


signals:

    void go_aForm();

private:
    Ui::CForm *ui;

public slots:
    void on_pushButton_A_clicked();
};

#endif // CFORM_H
