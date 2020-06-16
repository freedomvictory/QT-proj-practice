#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QDialog;


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




    QLineEdit * find_dialog_lineEdit;
    QDialog * find_dialog;

private slots:

   void action_new_triggered(bool);
   void m_action_handle(bool);

   void on_action_New_triggered();

   /*menu item : file-> show docker */
   void on_actionshow_Docker_triggered();

   /*custom menu*/
   void setText(const QString &string);

   /*text block function test -- a menu action handler when trigger */
   void showTextFrame();

    /*show text block*/
   void showTextBlock();

   /*set font and text show format*/
   void setTextFont(bool checked);

   /*find dialog slots*/
   void textFind();
   void findNext();




};

#endif // TESTMAINWINDOW_H
