#include "drawwidget.h"
#include "ui_drawwidget.h"
#include <QPainter>

drawWidget::drawWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawWidget)
{
    ui->setupUi(this);
}

drawWidget::~drawWidget()
{
    delete ui;
}


void drawWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

    QPen pen(Qt::green, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);

    painter.setPen(pen);
    QRectF rectangle(70.0, 40.0, 80.0, 60.0);
    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
    //
    painter.drawArc(rectangle, startAngle, spanAngle);

}
