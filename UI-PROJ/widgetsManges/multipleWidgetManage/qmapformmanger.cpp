#include "qmapformmanger.h"
#include "mainwidget.h"
#include "bform.h"
#include "cform.h"

QMapFormManger::QMapFormManger(QObject *parent) : QObject(parent)
{

    auto mw = new mainWidget();
    auto bw = new BForm();
    auto cw = new CForm();

    mywidgets["A"] = mw;
    mywidgets["B"] = bw;
    mywidgets["C"] = cw;

    QObject::connect(mw, &mainWidget::GO_B, this, &GO_B);
    QObject::connect(bw, &BForm::go_cForm, this, &GO_C);
    QObject::connect(cw, &CForm::go_aForm, this, &GO_A);


    mywidgets["A"]->show();


}


void QMapFormManger::GO_A()
{
    mywidgets["A"]->show();
    mywidgets["C"]->close();

}

void QMapFormManger::GO_B()
{

    mywidgets["B"]->show();
    mywidgets["A"]->close();

}

void QMapFormManger::GO_C()
{
    mywidgets["C"]->show();
    mywidgets["B"]->close();

}
