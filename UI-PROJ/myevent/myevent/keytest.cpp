#include "keytest.h"
#include "ui_keytest.h"

keyTest::keyTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keyTest)
{
    ui->setupUi(this);
}

keyTest::~keyTest()
{
    delete ui;
}
