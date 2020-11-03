# QCustomPlot 


## Introduction 


It's a `QT c++ widget` for plotting and data visualization. It has no further dependencies and is well documented. This `plotting library` focuses on making good looking, publication quality 2D plots, graphs and charts, as well as offering high performance for realtime visualization applications.

## Start up : How to use this library  

Please refer this 
[Tutorials/settingup](https://www.qcustomplot.com/index.php/tutorials/settingup)



## A `hello-world` code example 

```c++ 
//MainWindow class header file 
class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  


private:
  Ui::MainWindow *ui;

  //Focus on these members 
  QCustomPlot *mPlot;
  QPointer<QCPGraph> mGraph1;
  QPointer<QCPGraph> mGraph2;
  AxisTag *mTag1;
  AxisTag *mTag2;

  QTextStream *m_textStream;


protected:
  bool event(QEvent *event) override;

  //void QWindow::touchEvent(QTouchEvent *ev) override;



};

// source File  : cpp 

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  mPlot(0),
  mTag1(0),
  mTag2(0)
{
  ui->setupUi(this);

  QFile *data = new QFile("混合溶剂1000ppm.txt");
  if(! data->open(QIODevice::ReadOnly | QIODevice::Text))
  {
  }
  else
  {
      m_textStream = new QTextStream(data);
      m_textStream->readLine();

  }

  mPlot = new QCustomPlot(this);
  setCentralWidget(mPlot);

 
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
}

MainWindow::~MainWindow()
{
  delete ui;
}
```

