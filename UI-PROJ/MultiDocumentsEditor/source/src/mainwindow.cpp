#include "mainWindow.h"
#include "mdichild.h"
#include "ui_mainwindow.h"

#include <QMdiSubWindow>
#include <QFileDialog>
#include <QSignalMapper>
#include <QMessageBox>
#include <QSettings>
#include <QCloseEvent>
#include <QLabel>
#include <QDebug> 

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator = new QAction(this);
    actionSeparator->setEnabled(true);
    //update menu
    updateMenus();
    //update menu when there are active window 
    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow *)), this, SLOT(updateMenus()));
    //create signal mapper 
    windowMapper = new QSignalMapper(this); 
    //bundles the signal of mapper to `SLOT -> set active sub-window`
    connect(windowMapper, SIGNAL(mapped(QWidget*)), this, SLOT(setActiveSubWindow(QWidget *)));
    //update window menu and set update window menu when the window menu will be displayed 
    updateWindowMenu();
    connect(ui->menuW, SIGNAL(aboutToShow()), this, SLOT(updateWindowMenu()));
    readSettings(); //read window setting message and init it 
    
    initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    MdiChild *child = createMdiChild();
    //add subwindow for multiple documents area 
    child->newFile();
    child->show();
}

void MainWindow::updateMenus()
{

    bool hasMdiChild = (activeMdiChild() != 0);
    qDebug() << "[updateMenus] (log) hasMdiChild:" << hasMdiChild;
    ui->actionSave->setEnabled(hasMdiChild);
    ui->actionSaveAs->setEnabled(hasMdiChild);
    ui->actionPaste_P->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);

    actionSeparator->setVisible(hasMdiChild);
    //Cut and Copy is enable when there are active window and selected text 
    bool hasSelection = (activeMdiChild() && activeMdiChild()->textCursor().hasSelection());
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);
    
    ui->actionUndo->setEnabled(activeMdiChild() && activeMdiChild()->document()->isUndoAvailable());
    ui->actionRedo->setEnabled(activeMdiChild() && activeMdiChild()->document()->isRedoAvailable());



}

/*
Got current active subwindow
*/
MdiChild* MainWindow::activeMdiChild()
{
    if(QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0;
}

MdiChild* MainWindow::createMdiChild()
{
    MdiChild *child = new MdiChild;
    //add subwindow on multiple document area, and `child` is central component 
    ui->mdiArea->addSubWindow(child);
    //bind the copy signal of the sub-window to the cut and copy actions of the menu bar 
    connect(child, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(child, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    //bind the undo and redo signal of the `QTextDocument` to the undo and redo actions 
    //of the menu bar 
    connect(child->document(), SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(child->document(), SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    //update line and row when cursor changed the position 
    connect(child, SIGNAL(cursorPositionChanged()), this, SLOT(showTextRowAndCol()));
    return child; 
}

void MainWindow::on_actionOpen_triggered() 
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        QMdiSubWindow *existing = findMdiChild(fileName);
        if(existing)
        {
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }
        //if file is not opened, then create the sub-window    
        MdiChild *child = createMdiChild();
        if(child->loadFile(fileName))
        {
            ui->statusbar->showMessage(tr("Open file success"), 2000);
            child->show();
        } 
        else
            child->close();
    }
}

QMdiSubWindow* MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();
    //traverse sub-window list , find the sub-window that opened `fileName`
    foreach(QMdiSubWindow *window, ui->mdiArea->subWindowList())
    {
        MdiChild *mdichild = qobject_cast<MdiChild*>(window->widget());
        if(mdichild->currentFile() == canonicalFilePath)
            return window; 
    }
    return 0;
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if(!window)
        return; 
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(window));    
}

void MainWindow::updateWindowMenu()
{
    ui->menuW->clear();
    ui->menuW->addAction(ui->actionClose);
    ui->menuW->addAction(ui->actionCloseAll);
    ui->menuW->addSeparator();
    ui->menuW->addAction(ui->actionTile);
    ui->menuW->addAction(ui->actionCascade);
    ui->menuW->addSeparator();
    ui->menuW->addAction(ui->actionNext);
    ui->menuW->addAction(ui->actionPrevious);
    ui->menuW->addAction(actionSeparator);

    QList<QMdiSubWindow*> windows = ui->mdiArea->subWindowList();
    actionSeparator->setVisible(! windows.isEmpty());

    for(int i = 0; i < windows.size(); ++i)
    {
        MdiChild *child = qobject_cast<MdiChild*>(windows.at(i)->widget());
        QString text;
        if(i < 9)
            text = tr("&%1 %2").arg(i + 1).arg(child->userFriendlyCurrentFile());
        else 
            text = tr("%1 %2").arg(i + 1).arg(child->userFriendlyCurrentFile());

        //add action to menu 
        QAction *action = ui->menuW->addAction(text);  
        action->setCheckable(true);     
        //set current active window is checked status 
        action->setChecked(child == activeMdiChild());
        //when action triggered , windowMapper will emit map signal with current widget argument 
        connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
        windowMapper->setMapping(action, windows.at(i));
    }
}


void MainWindow::on_actionSave_triggered()
{
    if(activeMdiChild() && activeMdiChild()->save())
        ui->statusbar->showMessage(tr("file saved sucess"), 2000);      
}
void MainWindow::on_actionSaveAs_triggered()
{
    if(activeMdiChild() && activeMdiChild()->saveAs())
        ui->statusbar->showMessage(tr("file saved sucess"), 2000);      
}
void MainWindow::on_actionUndo_triggered()
{
    if(activeMdiChild()) 
        activeMdiChild()->undo();
}
void MainWindow::on_actionRedo_triggered()
{
    if(activeMdiChild())
        activeMdiChild()->redo();
}
void MainWindow::on_actionCut_triggered()
{
    if(activeMdiChild())
        activeMdiChild()->cut();
}
void MainWindow::on_actionCopy_triggered()
{
    if(activeMdiChild())
        activeMdiChild()->copy();
}

void MainWindow::on_actionPaste_P_triggered()
{
    if(activeMdiChild())
        activeMdiChild()->paste();
}

void MainWindow::on_actionClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow();
}
void MainWindow::on_actionCloseAll_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}
void MainWindow::on_actionTile_triggered()
{
    ui->mdiArea->tileSubWindows();
}
void MainWindow::on_actionCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}
void MainWindow::on_actionNext_triggered()
{
    ui->mdiArea->activateNextSubWindow();
}
void MainWindow::on_actionPrevious_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("about this software"), tr("author:yafei"));
}
void MainWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //close all sub-window 
    ui->mdiArea->closeAllSubWindows();
    //if there are window has not closed : ignore the event 
    if(ui->mdiArea->currentSubWindow())
        event->ignore();
    else
    {
        writeSettings();
        event->accept();
    } 
}

void MainWindow::writeSettings()
{
    QSettings settings("laoyinghaina", "MDI");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void MainWindow::readSettings()
{
    QSettings settings("laoyinghaina", "MDI");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    move(pos);
    resize(size);
}

void MainWindow::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void MainWindow::showTextRowAndCol()
{
    if(auto child = activeMdiChild())
    {
        int rowNum = child->textCursor().blockNumber() + 1;
        int colNum = child->textCursor().columnNumber() + 1; 
        ui->statusbar->showMessage(tr("%1 row %2 column").arg(rowNum).arg(colNum), 2000);     
    }
}

void MainWindow::initWindow()
{
    setWindowTitle(tr("multiple document editor"));
    ui->toolBar->setWindowTitle(tr("Tool Bar"));

    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    ui->statusbar->showMessage(tr("welecome use multiple documents editor"));
    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Box | QFrame::Sunken); 
    label->setText(tr("<a href=\"http://www.yafeilinux.com\">yafeilinux.com</a>"));
    label->setTextFormat(Qt::RichText);
    label->setOpenExternalLinks(true);

    ui->statusbar->addPermanentWidget(label);
    ui->actionNew->setStatusTip(tr("create a file"));
    ui->actionOpen->setStatusTip(tr("open a file"));
    ui->actionSave->setStatusTip(tr("save file to disk"));
    ui->actionSaveAs->setStatusTip(tr("save as document"));
    ui->actionExit->setStatusTip(tr("exit application"));
    ui->actionUndo->setStatusTip(tr("undo the operation"));
    ui->actionRedo->setStatusTip(tr("redo the operation"));
    ui->actionCut->setStatusTip(tr("cut the selected text"));
    ui->actionCopy->setStatusTip(tr("copy to selected text to clipboard"));
    ui->actionPaste_P->setStatusTip(tr("paste of the content of clipboard to current cursor position"));
    ui->actionClose->setStatusTip(tr("close active window"));
    ui->actionCloseAll->setStatusTip(tr("close all window"));
    ui->actionTile->setStatusTip(tr("平铺所有窗口"));
    ui->actionCascade->setStatusTip(tr("层叠所有窗口"));
    ui->actionNext->setStatusTip(tr("将焦点移动到下一个窗口"));
    ui->actionPrevious->setStatusTip(tr("将焦点移动到前一个窗口"));
    ui->actionAbout->setStatusTip(tr("显示本软件的介绍"));
    ui->actionAboutQt->setStatusTip(tr("显示Qt的介绍"));



}