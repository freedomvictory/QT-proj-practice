#include "keytest.h"
#include "ui_keytest.h"
#include <QDebug>

keyTest::keyTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keyTest)
{
    ui->setupUi(this);
}


void keyTest::keyPressEvent(QKeyEvent *event)
{
/* CTRL-M
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_M)
            setWindowState(Qt::WindowMaximized);
    }
    else QWidget::keyPressEvent(event);

    */

    if(event->key() == Qt::Key_Up)
    {
        qDebug() << "press:" << event->isAutoRepeat();
    }


}

void keyTest::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        qDebug() << "release:" << event->isAutoRepeat();
        qDebug() << "up";
    }

}

keyTest::~keyTest()
{
    delete ui;
}
