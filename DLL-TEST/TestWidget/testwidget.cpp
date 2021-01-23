#include "testwidget.h"
#include <stdio.h>
#include <QPushButton>

TestWidget::TestWidget(QWidget *parent):
    QWidget(parent)
{
    QPushButton *button_ok = new QPushButton();
    button_ok->setText("ok");





}

TestWidget::~TestWidget()
{
}

extern "C" double multiply(int a, int b)
{
    return a * b;
}

TestWidget *win;
extern "C" void showDialog()
{
    win = new TestWidget();
    win->show();
}

extern "C" void closeDialog()
{
    win->close();

}

