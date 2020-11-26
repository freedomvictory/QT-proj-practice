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

private:
    Ui::BForm *ui;
};

#endif // BFORM_H
