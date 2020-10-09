#include "myaction.h"
#include <QLineEdit>
#include <QSplitter>
#include <QLabel>


Myaction::Myaction(QObject * parent) :
    QWidgetAction(parent)
{
    //create a line editor
    myLineEdit = new QLineEdit;
    //line editor's enter button connect the sendText slot
    connect(myLineEdit, &QLineEdit::returnPressed, this, &Myaction::sendText);
}

QWidget *Myaction::createWidget(QWidget *parent)
{
    /*judge parent control is/(is not) menu or toolBar
    if is  : create sub control, and return it.
    if not : return NULL*/
    if(parent->inherits("QMenu") || parent->inherits("QToolBar"))
    {
        QSplitter * splitter = new QSplitter(parent);
        QLabel * qlabel = new QLabel;
        qlabel->setText(tr("insert text"));
        splitter->addWidget(qlabel);
        splitter->addWidget(myLineEdit);
        return splitter;
    }

    return Q_NULLPTR;
}

void Myaction::sendText()
{
    emit getText(myLineEdit->text());
    myLineEdit->clear();
}
