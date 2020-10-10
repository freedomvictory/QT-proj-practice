#ifndef WIDGET_SPLIT_H
#define WIDGET_SPLIT_H

#include <QWidget>

namespace Ui {
class widget_split;
}

class widget_split : public QWidget
{
    Q_OBJECT

public:
    explicit widget_split(QWidget *parent = nullptr);
    ~widget_split();

private:
    Ui::widget_split *ui;
};

#endif // WIDGET_SPLIT_H
