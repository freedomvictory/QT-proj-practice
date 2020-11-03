#ifndef DRAWPATHWIDGET_H
#define DRAWPATHWIDGET_H

#include <QWidget>

class drawPathWidget : public QWidget
{
    Q_OBJECT
public:
    explicit drawPathWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
};

#endif // DRAWPATHWIDGET_H
