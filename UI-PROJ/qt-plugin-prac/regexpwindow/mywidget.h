#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "regexpinterface.h"

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = nullptr);
    ~myWidget();

private:
    Ui::myWidget *ui;
    RegExpInterface *regexpInterface;
    bool loadPlugin();

private slots:
    void on_pushButton_clicked();

};

#endif // MYWIDGET_H
