#include "mdichild.h"
#include <QMessageBox>
#include <QTextStream> 
#include <QFile> 
#include <QFileInfo> 
#include <QApplication> 
#include <QFileDialog>
#include <QPushButton>
#include <QMenu>

//TODO: CloseEvent and maybeSave() 

/*
construct function:
*/
MdiChild::MdiChild(QWidget *parent)
:QTextEdit(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true; 
}


void MdiChild::newFile()
{
    static int sequenceNumber = 1;
    //the new document havn't saved 
    isUntitled = true; 
    curFile = tr("unnamed document%1.txt").arg(sequenceNumber);
    setWindowTitle(curFile + "[*]" + tr(" - multiple documents editor"));

    connect(document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));
}

bool MdiChild::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("multiple documents editor"), tr("can't read file %1\n%2.")
                            .arg(fileName).arg(file.errorString()));
        return false; 
    }
    QTextStream in(&file); 
    QApplication::setOverrideCursor(Qt::WaitCursor);
    setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName); 
    connect(document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));

    return true; 
}

void MdiChild::setCurrentFile(const QString &fileName)
{
    //cut the symbolic link of path 
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false; 
    setWindowModified(false); // the widget don't show change status 
    setWindowTitle(userFriendlyCurrentFile() + "[*]"); // why not add `- multiple documents editor`
}

bool MdiChild::save()
{
    if(isUntitled)
        return saveAs();
    else 
        return saveFile(curFile);
}

bool MdiChild::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("SAVE AS"), curFile);
     if (fileName.isEmpty())
        return false;

    return saveFile(fileName); 
}

bool MdiChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("multiple documents editor"),
                                    tr("can't write file %1:\n%2.")
                                    .arg(fileName).arg(file.errorString()));
        return false; 
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText(); 
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);
    return true; 
}

QString MdiChild::userFriendlyCurrentFile()
{
    //got the file name from from the path 
    return QFileInfo(curFile).fileName(); 
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if(maybeSave()) 
        event->accept(); 
    else 
        event->ignore();
}

bool MdiChild::maybeSave()
{
    if(document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle(tr("multiple document editor"));
        box.setText(tr("Whether save the change of '%1' ?").arg(userFriendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);
        QPushButton *yesBtn = box.addButton(tr("YES(&N)"), QMessageBox::YesRole);
        box.addButton(tr("NO(&N)"), QMessageBox::NoRole);
        QPushButton *cancelBtn = box.addButton(tr("Cancle"), QMessageBox::RejectRole);

        box.exec();
        if ( box.clickedButton() == yesBtn)
            return save(); 
        else if(box.clickedButton() == cancelBtn)
            return false;
    }
    return true; 
}
void MdiChild::documentWasModified()
{
    //accroding whether the document is modified, and setting the window titile (changed and unsave)
    setWindowModified(document()->isModified());
}


void MdiChild::contextMenuEvent(QContextMenuEvent *e)
{
    //TODO: 
    QMenu *menu = new QMenu;
    QAction *undo = menu->addAction(tr("undo(&U)"), this, SLOT(undo()), QKeySequence::Undo);
    undo->setEnabled(document()->isUndoAvailable());

    QAction *redo = menu->addAction(tr("redo(&R)"),this,
                                    SLOT(redo()),QKeySequence::Redo);
    redo->setEnabled(document()->isRedoAvailable());
    menu->addSeparator();
    QAction *cut = menu->addAction(tr("cut(&T)"),this,
                                   SLOT(cut()),QKeySequence::Cut);
    cut->setEnabled(textCursor().hasSelection());
    QAction *copy = menu->addAction(tr("copy(&C)"),this,
                                    SLOT(copy()),QKeySequence::Copy);
    copy->setEnabled(textCursor().hasSelection());
    menu->addAction(tr("paste(&P)"),this,SLOT(paste()),QKeySequence::Paste);
    QAction *clear = menu->addAction(tr("clear"),this,SLOT(clear()));
    clear->setEnabled(!document()->isEmpty());
    menu->addSeparator();
    QAction *select = menu->addAction(tr("select all"),this,
                                SLOT(selectAll()),QKeySequence::SelectAll);
    select->setEnabled(!document()->isEmpty());


    menu->exec(e->globalPos());
    delete menu;



}





