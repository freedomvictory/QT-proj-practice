#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

namespace Ui {
class drawWidget;
}

class drawWidget : public QWidget
{
    Q_OBJECT

public:
    explicit drawWidget(QWidget *parent = nullptr);
    ~drawWidget();

private:
    Ui::drawWidget *ui;
};

#endif // DRAWWIDGET_H