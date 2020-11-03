/***************************************************************************
**                                                                        **
**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
**  Copyright (C) 2011-2018 Emanuel Eichhammer                            **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: http://www.qcustomplot.com/                          **
**             Date: 25.06.18                                             **
**          Version: 2.0.1                                                **
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  mPlot(0),
  mTag1(0),
  mTag2(0)
{
  ui->setupUi(this);
  // add two lines , enable touch event and gesture
  //setAttribute(Qt::WA_AcceptTouchEvents);
  grabGesture(Qt::PinchGesture);


  QFile *data = new QFile("混合溶剂1000ppm.txt");
  if(! data->open(QIODevice::ReadOnly | QIODevice::Text))
  {

  }
  else
  {

      m_textStream = new QTextStream(data);
      m_textStream->readLine();
        //QTextStream in(&data);





  }


  mPlot = new QCustomPlot(this);
  setCentralWidget(mPlot);

  mPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

  connect(mPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
  connect(mPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));
  
  // configure plot to have two right axes:
  mPlot->yAxis->setTickLabels(false);
  connect(mPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), mPlot->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
  mPlot->yAxis2->setVisible(true);
  mPlot->axisRect()->addAxis(QCPAxis::atRight);
  mPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30); // add some padding to have space for tags
  mPlot->axisRect()->axis(QCPAxis::atRight, 1)->setPadding(30); // add some padding to have space for tags
  
  // create graphs:
  mGraph1 = mPlot->addGraph(mPlot->xAxis, mPlot->axisRect()->axis(QCPAxis::atRight, 0));
  mGraph2 = mPlot->addGraph(mPlot->xAxis, mPlot->axisRect()->axis(QCPAxis::atRight, 1));
  mGraph1->setPen(QPen(QColor(250, 120, 0)));
  mGraph2->setPen(QPen(QColor(0, 180, 60)));
  
  // create tags with newly introduced AxisTag class (see axistag.h/.cpp):
  mTag1 = new AxisTag(mGraph1->valueAxis());
  mTag1->setPen(mGraph1->pen());
  mTag2 = new AxisTag(mGraph2->valueAxis());
  mTag2->setPen(mGraph2->pen());

  double time_f = 0, current_f = 0;


// all data load in graph once

  /***********************************start***************************/
  QVector<double> times;
  QVector<double> currents;

  while(! m_textStream->atEnd())
  {
      QString line = m_textStream->readLine();

      auto data_line = line.split("\t");
      QString time = data_line.at(0);
      QString current = data_line.at(1);


      qDebug() << " time:" << time;
      qDebug() << " current :" << current;

      bool ok;
      time_f = time.toDouble(&ok);
      times.append(time_f);
      if(ok)
      {
          qDebug() << "time_f:" << time_f;
      }
      current_f = current.toDouble(&ok);
      if(ok)
      {
          qDebug() << "current_f" << current_f;
      }
      currents.append(current_f);

  }

  // add all data to graph
  mGraph1->addData(times, currents);

  mPlot->xAxis->rescale();
  mGraph1->rescaleValueAxis(false, true);
  mPlot->xAxis->setRange(time_f, 0, Qt::AlignRight);
  mPlot->replot();

  /***********************end*********************************/

  /*stop the timer */
  //connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
  //mDataTimer.start(1);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::timerSlot()
{
    double time_f = 0, current_f = 0;


    if(! m_textStream->atEnd())
    {
        QString line = m_textStream->readLine();

        auto data_line = line.split("\t");
        QString time = data_line.at(0);
        QString current = data_line.at(1);


        qDebug() << " time:" << time;
        qDebug() << " current :" << current;

        bool ok;
        time_f = time.toDouble(&ok);
        if(ok)
        {
            qDebug() << "time_f:" << time_f;
        }
        current_f = current.toDouble(&ok);
        if(ok)
        {
            qDebug() << "current_f" << current_f;
        }
    }
    else
    {

    }
    mGraph1->addData(time_f, current_f);



  // calculate and add a new data point to each graph:
  //mGraph1->addData(mGraph1->dataCount(), qSin(mGraph1->dataCount()/50.0)+qSin(mGraph1->dataCount()/50.0/0.3843)*0.25);
  //mGraph2->addData(mGraph2->dataCount(), qCos(mGraph2->dataCount()/50.0)+qSin(mGraph2->dataCount()/50.0/0.4364)*0.15);



  // make key axis range scroll with the data:
  mPlot->xAxis->rescale();
  mGraph1->rescaleValueAxis(false, true);
  mGraph2->rescaleValueAxis(false, true);
  mPlot->xAxis->setRange(time_f, 0, Qt::AlignRight);
  
  // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
  double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
  double graph2Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
  mTag1->updatePosition(graph1Value);
  mTag2->updatePosition(graph2Value);
  mTag1->setText(QString::number(graph1Value, 'f', 2));
  mTag2->setText(QString::number(graph2Value, 'f', 2));
  
  mPlot->replot();
}

void MainWindow::mousePress()
{
    if (mPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
      mPlot->axisRect()->setRangeDrag(mPlot->xAxis->orientation());
    else if (mPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
      mPlot->axisRect()->setRangeDrag(mPlot->yAxis->orientation());
    else
      mPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);

}

void MainWindow::mouseWheel()
{
    if (mPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
      mPlot->axisRect()->setRangeZoom(mPlot->xAxis->orientation());
    else if (mPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
      mPlot->axisRect()->setRangeZoom(mPlot->yAxis->orientation());
    else
      mPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);

}

bool MainWindow::event(QEvent *event)
{

    switch( event->type() ){
            case QEvent::Gesture: {
                QGestureEvent *gestureEve = static_cast<QGestureEvent*>(event);
                if( QGesture *pinch = gestureEve->gesture(Qt::PinchGesture) ){
                    QPinchGesture *pinchEve = static_cast<QPinchGesture *>(pinch);
                    qreal scaleFactor = pinchEve->totalScaleFactor( );
                    qDebug() << "[MainWindow:event] (log) QEvent:Gestrure: scaleFactor: " << scaleFactor;

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
                    QMouseEvent *mouseEve = new QMouseEvent(QEvent::MouseButtonPress,currentTouchPointPos,Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                    if( touchEvent->touchPointStates() ==  (Qt::TouchPointStates)Qt::TouchPointPressed ){
                        this->mousePressEvent( mouseEve );
                    }else if( touchEvent->touchPointStates() == (Qt::TouchPointStates)Qt::TouchPointMoved ){
                        this->mouseMoveEvent( mouseEve );
                    }else if( touchEvent->touchPointStates() == (Qt::TouchPointStates)Qt::TouchPointReleased ){
                        this->mouseReleaseEvent( mouseEve );
                    }
                }
                return true;
            }
            default: {
                break;
            }
        }



    return QMainWindow::event( event );
}





