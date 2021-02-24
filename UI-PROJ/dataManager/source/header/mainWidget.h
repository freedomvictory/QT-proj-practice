#ifndef __MAINWIDGET_H
#define __MAINWIDGET_H


#include <QWidget> 
#include <QtXml> 

namespace Ui{
    class mainWidget;
}

class mainWidget: public QWidget
{
    Q_OBJECT
public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget(); 

    enum DataTimeType{Time, Date, DateTime};
    QString getDateTime(DataTimeType type);

private:
    Ui::mainWidget *ui; 
    
    QDomDocument doc; 
    bool docRead();
    bool docWrite(); 
    void writeXml(); 
    void createNodes(QDomElement &date);
    void showDailyList(); 

private slots:
    //sell commodity 
    void on_sellTypeComboBox_currentIndexChanged(QString type);
    void on_sellCancelBtn_clicked();
    void on_sellBrandComboBox_currentIndexChanged(QString brand);
    void on_sellNumSpinBox_valueChanged(int value); 
    void on_sellOkBtn_clicked(); 
    //storage old commodity 
    /*
    void on_goodsTypeComboBox_currentIndexChange(QString type); 
    void on_goodsCancelBtn_clicked(); 
    */
};






#endif 