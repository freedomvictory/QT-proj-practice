#ifndef MYCUTSOMPLOT_H
#define MYCUTSOMPLOT_H

#include "qcustomplot.h"


class myCutsomPlot : public QCustomPlot
{
     Q_OBJECT
public:
      explicit myCutsomPlot(QWidget *parent = nullptr);
      ~myCutsomPlot();

private:
    QPointF currentTouchPointPos;




protected:
    bool event(QEvent *event) override;

private slots:
    void mousePress(QMouseEvent *);
    void mouseWheel();

};

#endif // MYCUTSOMPLOT_H
