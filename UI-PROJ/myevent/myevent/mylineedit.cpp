#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit (parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    /*
    qDebug() << tr("myLineEdit  keyboard press Event!");
    QLineEdit::keyPressEvent(event);
    event->ignore();
    */
}

bool MyLineEdit::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
        qDebug() << tr("MyLineEdit's event() function called");

    return QLineEdit::event(event);
}
