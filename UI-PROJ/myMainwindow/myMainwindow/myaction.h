#ifndef MYACTION_H
#define MYACTION_H

#include <QWidgetAction>

class QLineEdit;

class Myaction : public QWidgetAction
{
    Q_OBJECT

public:
    explicit Myaction(QObject * parent = 0);
protected:
    QWidget *createWidget(QWidget *parent);

signals:
    /*the signal is used for sending line editor's content when push enter button*/
    void getText(const QString &string);

private slots:
    /*this is used for related to enter button singal */
    void sendText();

private:
    QLineEdit *myLineEdit;



};

#endif // MYACTION_H
