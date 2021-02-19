#ifndef __MDICHILD_H
#define __MDICHILD_H

#include <QTextEdit>
#include <QCloseEvent>
#include <QString> 
#include <QObject> 

class MdiChild : public QTextEdit
{
    Q_OBJECT
public:
    explicit MdiChild(QWidget *parent = 0);
    void newFile();                         // new file operation 
    bool loadFile(const QString &fileName); // load file operation 
    bool save();                            // save file operation 
    bool saveAs();                          // save as operation 
    bool saveFile(const QString &fileName);
    QString userFriendlyCurrentFile(); 
    QString currentFile() const {return curFile;};
    


protected:
    void closeEvent(QCloseEvent *event);
    void contextMenuEvent(QContextMenuEvent* e);

private slots:
    void documentWasModified();             // show change status flag when the document was modified 

private:

    bool maybeSave();   //whether the document need to save
    void setCurrentFile(const QString &fileName);
    /*current file path*/
    QString curFile; 
    /*whether file is already saved on the disk*/
    bool isUntitled;
    


};







#endif 