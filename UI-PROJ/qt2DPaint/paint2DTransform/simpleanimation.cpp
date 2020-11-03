#include "simpleanimation.h"
#include <QTimer>
#include <QPainter>

simpleAnimation::simpleAnimation(QWidget *parent) : QWidget(parent)
{


    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}


void simpleAnimation::paintEvent(QPaintEvent *event)
{
    angle += 10;
    if(angle == 360)
    {
        angle = 0;
    }
    int side = qMin(width(), height());
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    QTransform tranform;
    tranform.translate(width()/2, height()/ 2);
    tranform.scale(side/300.0, side/300.0);
    tranform.rotate(angle);

    painter.setWorldTransform(tranform);
    painter.drawEllipse(-120, -120, 240, 240);
    painter.drawLine(0, 0, 100, 0);


}
