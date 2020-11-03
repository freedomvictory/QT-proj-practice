#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

#include "mylineedit.h"

namespace Ui {
class mywidget;
}
class MyLineEdit;

class mywidget : public QWidget
{
    Q_OBJECT

public:
    explicit mywidget(QWidget *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent *event);
    ~mywidget();

private:
    Ui::mywidget *ui;
    MyLineEdit *m_lineEdit;

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYWIDGET_H
