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

   void action_new_triggered(bool);
   void m_action_handle(bool);

   void on_action_New_triggered();

   /*menu item : file-> show docker */
   void on_actionshow_Docker_triggered();

   /*custom menu*/
   void setText(const QString &string);
};

#endif // TESTMAINWINDOW_H
