#ifndef __MAINWIDGET_H
#define __MAINWIDGET_H


#include <QWidget> 

namespace Ui{
    class mainWidget;
}

class mainWidget: public QWidget
{
    Q_OBJECT
public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget(); 
private:
    Ui::mainWidget *ui; 
private slots:
    void on_sellTypeComboBox_currentIndexChanged(QString type);
    void on_sellCancelBtn_clicked();
    void on_sellBrandComboBox_currentIndexChanged(QString brand);
    void on_sellNumSpinBox_valueChanged(int value); 
};






#endif 