#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>


#include "testwidget_global.h"

class TESTWIDGETSHARED_EXPORT TestWidget :QWidget
{
    Q_OBJECT
public:
    TestWidget(QWidget *parent = 0);
    ~TestWidget();


};

#endif // TESTWIDGET_H
