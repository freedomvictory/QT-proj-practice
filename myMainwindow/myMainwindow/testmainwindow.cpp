#include "testmainwindow.h"
#include "ui_testmainwindow.h"
#include <QToolButton>
#include <QLabel>


testMainWindow::testMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testMainWindow)
{
    ui->setupUi(this);

    //action_new send signal to funciton (action_new_show)
    connect(ui->action_New, &QAction::triggered, this, &this->action_new_show ) ;


    //add an action to toolbar, and this action send singnal to a handler (an action just like a button in toolBar)
    QAction *mQAction = ui->mainToolBar->addAction(tr("hello"));
    connect(mQAction, &QAction::triggered, this, &this->m_action_handle);

    /*status bar show some message(only 2 seconds) and add a label to status bar*/
    ui->statusBar->showMessage(tr("this is status bar"));

    QLabel *permanet = new QLabel(this);
    permanet->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanet->setText("www.qter.org");
    ui->statusBar->addPermanentWidget(permanet);

}

testMainWindow::~testMainWindow()
{
    delete ui;
}
void testMainWindow::action_new_show(bool arg)
{

    if(arg == true)
    {
        ui->showTextBrowser->setText("true");
    }
    else
    {
        ui->showTextBrowser->setText("false");
    }



}

void testMainWindow::m_action_handle(bool arg)
{
    ui->showTextBrowser->setText("this is toolBtn");

}
