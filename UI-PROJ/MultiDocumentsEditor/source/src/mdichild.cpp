#include "mdichild.h"
#include <QMessageBox>
#include <QTextStream> 
#include <QFile> 
#include <QFileInfo> 
#include <QApplication> 
#include <QFileDialog>


//TODO: CloseEvent and maybeSave() 


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
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
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

}

void MdiChild::documentWasModified()
{
    //accroding whether the document is modified, and setting the window titile (changed and unsave)
    setWindowModified(document()->isModified());
}






