#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "axistag.h"
#include "qcustomplot.h"

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

private:
    Ui::myWidget *ui;

    QPointer<QCPGraph> mGraph1;
    QPointer<QCPGraph> mGraph2;
    AxisTag *mTag1;
    AxisTag *mTag2;
};

#endif // MYWIDGET_H
