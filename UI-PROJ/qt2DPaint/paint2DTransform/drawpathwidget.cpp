#include <QPainter>
#include "drawpathwidget.h"

drawPathWidget::drawPathWidget(QWidget *parent) : QWidget(parent)
{

}

void drawPathWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPainterPath path;

    path.moveTo(50, 250);
    path.lineTo(51, 255);
    path.lineTo(52, 260);
    path.lineTo(60, 300);

    path.lineTo(60, 500);
    path.lineTo(200, 300);
    path.lineTo(500, 400);


    painter.setPen(Qt::darkBlue);
    painter.drawPath(path);





}
