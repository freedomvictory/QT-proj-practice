#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::paintEvent(QPaintEvent *event)
{
    // test transformation
    /*
    QPainter painter(this);

    painter.fillRect(rect(), Qt::white);
    painter.setPen(QPen(Qt::red, 11));
    painter.drawLine(QPoint(5, 6), QPoint(100, 99));

    painter.translate(200, 150);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawLine(QPoint(5, 6), QPoint(100, 90));

    painter.save();
    painter.rotate(90);
    painter.setPen(Qt::cyan);

    painter.drawLine(QPoint(5, 6), QPoint(100, 99));
    painter.restore();

    painter.setBrush(Qt::darkGreen);
    painter.drawRect(-50, 50, 100, 50);
    painter.save();

    painter.scale(0.5, 0.4);
    painter.setBrush(Qt::yellow);
    painter.drawRect(-50, 50, 100, 50);
    painter.restore();

    painter.setPen(Qt::blue);
    painter.setBrush(Qt::darkYellow);
    painter.drawEllipse(QRect(60, -100, 50, 50));
    painter.shear(1.5, -0.7);
    painter.setBrush(Qt::darkGray);
    painter.drawEllipse(QRect(60, -100, 50, 50));
    */

    //test window convert to viewport
    QPainter painter(this);
    painter.setWindow(-50, -50, 100, 100);
    painter.setBrush(Qt::green);
    painter.drawRect(0, 0, 20, 20);




}

void myWidget::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);



}

