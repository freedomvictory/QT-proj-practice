#include "windowmanger.h"
#include "bform.h"
#include "cform.h"
#include "mainwidget.h"



WindowManger::WindowManger(QObject *parent) : QObject(parent)
{

    mainWidget *a = new mainWidget();
    BForm *b = new BForm();
    CForm *c = new CForm();

    connect(a, &mainWidget::GO_B, this, &WindowManger::GO_B);
    connect(b, &BForm::go_cForm, this, &WindowManger::GO_C);
    connect(c, &CForm::go_aForm, this, &WindowManger::GO_A);

    this->myQStackW->addWidget(a);
    this->myQStackW->addWidget(b);
    this->myQStackW->addWidget(c);

    this->myQStackW->setCurrentIndex(0);

}

void WindowManger::GO_A()
{
    this->myQStackW->setCurrentIndex(0);
}

void WindowManger::GO_B()
{
    this->myQStackW->setCurrentIndex(1);
}

void WindowManger::GO_C()
{
    this->myQStackW->setCurrentIndex(2);
}
