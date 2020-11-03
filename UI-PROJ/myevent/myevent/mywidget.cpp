#include "mywidget.h"
#include "ui_mywidget.h"

#include <QKeyEvent>
#include <QDebug>

mywidget::mywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mywidget)
{
    ui->setupUi(this);
    m_lineEdit = new MyLineEdit(this);
    m_lineEdit->move(100, 100);
    m_lineEdit->installEventFilter(this);
}

void mywidget::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << tr("Mywidget key press event!");
}

bool mywidget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == m_lineEdit)
    {
        if(event->type() == QEvent::KeyPress)
            qDebug() << tr("mywidget's event filter");
    }
    return QWidget::eventFilter(obj, event);


}

mywidget::~mywidget()
{
    delete ui;
}

