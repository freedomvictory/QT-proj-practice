#include "mycutsomplot.h"
#include <QDebug>

myCutsomPlot::myCutsomPlot(QWidget *parent):
    QCustomPlot(parent)
{
    connect(this, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress(QMouseEvent *)));
    connect(this, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));

    setAttribute( Qt::WA_AcceptTouchEvents );
    grabGesture( Qt::PinchGesture );

}


myCutsomPlot::~myCutsomPlot()
{


}



bool myCutsomPlot::event(QEvent *event)
{

    switch( event->type() ){
            case QEvent::Gesture: {
                QGestureEvent *gestureEve = static_cast<QGestureEvent*>(event);
                if( QGesture *pinch = gestureEve->gesture(Qt::PinchGesture) ){
                    QPinchGesture *pinchEve = static_cast<QPinchGesture *>(pinch);
                    qreal scaleFactor = pinchEve->totalScaleFactor( );
                    qDebug() << "[myCustomPlot:event] (log) QEvent:Gestrure: scaleFactor: " << scaleFactor;

                    if( scaleFactor > 1.0 ){
                        scaleFactor *= 10;
                    }else{
                        scaleFactor *= -10;
                    }
                    QWheelEvent *wheelEve = new QWheelEvent( currentTouchPointPos, scaleFactor, Qt::NoButton, Qt::NoModifier, Qt::Vertical );
                    this->wheelEvent( wheelEve );
                }
                return true;
            }
            case QEvent::TouchBegin:
            case QEvent::TouchUpdate:
            case QEvent::TouchEnd: {
                QTouchEvent *touchEvent = static_cast<QTouchEvent *>( event );
                QList<QTouchEvent::TouchPoint> touchPoints = touchEvent->touchPoints( );
                if( touchPoints.count( ) == 1 ){
                    const QTouchEvent::TouchPoint &touchPoint0 = touchPoints.first( );
                    currentTouchPointPos = touchPoint0.pos();
                    /*
                    QMouseEvent *mouseEve = new QMouseEvent(QEvent::MouseButtonPress,currentTouchPointPos,Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                    if( touchEvent->touchPointStates() ==  (Qt::TouchPointStates)Qt::TouchPointPressed ){
                        this->mousePressEvent( mouseEve );
                    }else if( touchEvent->touchPointStates() == (Qt::TouchPointStates)Qt::TouchPointMoved ){
                        this->mouseMoveEvent( mouseEve );
                    }else if( touchEvent->touchPointStates() == (Qt::TouchPointStates)Qt::TouchPointReleased ){
                        this->mouseReleaseEvent( mouseEve );
                    }
                    */
                }
                return true;
            }
            default: {
                break;
            }
        }



    return QWidget::event( event );


}

void myCutsomPlot::mousePress(QMouseEvent *)
{
    if (this->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
      this->axisRect()->setRangeDrag(this->xAxis->orientation());
    else if (this->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
      this->axisRect()->setRangeDrag(this->yAxis->orientation());
    else
      this->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);

}

void myCutsomPlot::mouseWheel()
{
    if (this->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
      this->axisRect()->setRangeZoom(this->xAxis->orientation());
    else if (this->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
      this->axisRect()->setRangeZoom(this->yAxis->orientation());
    else
      this->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);

}
