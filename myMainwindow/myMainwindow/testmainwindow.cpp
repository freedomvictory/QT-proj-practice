#include "testmainwindow.h"
#include "ui_testmainwindow.h"
#include <QToolButton>
#include <QLabel>
#include <QTextEdit>
#include <QMdiSubWindow>


testMainWindow::testMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testMainWindow)
{
    ui->setupUi(this);

    //action_new send signal to funciton (action_new_show)
    connect(ui->action_New, &QAction::triggered, this, &this->action_new_triggered ) ;


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
void testMainWindow::action_new_triggered(bool arg)
{


    ui->showTextBrowser->setText("new file");


    //create new txetEdit control
    QTextEdit *edit = new QTextEdit(this);

    //create sub windows, and 'edit' is central control of thease sub window
    QMdiSubWindow *child = ui->myMdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("Multi documents editor sub window"));
    child->show();
}

void testMainWindow::m_action_handle(bool arg)
{
    ui->showTextBrowser->setText("this is toolBtn");

}

void testMainWindow::on_action_New_triggered()
{

}

void testMainWindow::on_actionshow_Docker_triggered()
{
    ui->mydockerWidget->show();
}
