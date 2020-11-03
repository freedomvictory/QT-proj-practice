#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QPushButton>

class myButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myButton(QWidget *parent=nullptr);
    QString getName(){return "My button!";}


};

#endif // MYBUTTON_H
