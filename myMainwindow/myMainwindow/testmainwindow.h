#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class testMainWindow;
}

class testMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit testMainWindow(QWidget *parent = 0);
    ~testMainWindow();

private:
    Ui::testMainWindow *ui;


private slots:

   void action_new_show(bool);
   void m_action_handle(bool);

};

#endif // TESTMAINWINDOW_H
