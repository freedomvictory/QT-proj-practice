#include "mywidget.h"
#include "ui_mywidget.h"

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    //open the file , and read the first line

    QTextStream* m_textStream = nullptr;
    QFile *data = new QFile("E:\\Documents\\code\\c++\\QT-proj-practice\\UI-PROJ\\myCustomPlotWidget\\build-qtWidgetCutstomPlot-Desktop_Qt_5_9_0_MinGW_32bit-Debug\\debug\\混合溶剂1000ppm.txt");
    if(! data->open(QIODevice::ReadOnly | QIODevice::Text))
    {
    }
    else
    {
        m_textStream = new QTextStream(data);
        m_textStream->readLine();
          //QTextStream in(&data);
    }

    ui->mPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    // configure plot to have two right axes:
    ui->mPlot->yAxis->setTickLabels(false);
    connect(ui->mPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), ui->mPlot->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    ui->mPlot->yAxis2->setVisible(true);
    ui->mPlot->axisRect()->addAxis(QCPAxis::atRight);
    ui->mPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30); // add some padding to have space for tags
    ui->mPlot->axisRect()->axis(QCPAxis::atRight, 1)->setPadding(30); // add some padding to have space for tags

    // create graphs:
    mGraph1 = ui->mPlot->addGraph(ui->mPlot->xAxis, ui->mPlot->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph2 = ui->mPlot->addGraph(ui->mPlot->xAxis, ui->mPlot->axisRect()->axis(QCPAxis::atRight, 1));
    mGraph1->setPen(QPen(QColor(250, 120, 0)));
    mGraph2->setPen(QPen(QColor(0, 180, 60)));

    // create tags with newly introduced AxisTag class (see axistag.h/.cpp):
    mTag1 = new AxisTag(mGraph1->valueAxis());
    mTag1->setPen(mGraph1->pen());
    mTag2 = new AxisTag(mGraph2->valueAxis());
    mTag2->setPen(mGraph2->pen());


    // all data load in graph once

    /***********************************start***************************/
    double time_f = 0, current_f = 0;
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

    ui->mPlot->xAxis->rescale();
    mGraph1->rescaleValueAxis(false, true);
    ui->mPlot->xAxis->setRange(time_f, 0, Qt::AlignRight);
    ui->mPlot->replot();

    /***********************end*********************************/





}

myWidget::~myWidget()
{
    delete ui;
}
