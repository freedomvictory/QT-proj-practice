#ifndef WINDOWMANGER_H
#define WINDOWMANGER_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>


class WindowManger : public QObject
{
    Q_OBJECT
public:
    explicit WindowManger(QObject *parent = nullptr);

private:

    QStackedWidget *myQStackW = new QStackedWidget();


public slots:

    void GO_A();
    void GO_B();
    void GO_C();
};

#endif // WINDOWMANGER_H
