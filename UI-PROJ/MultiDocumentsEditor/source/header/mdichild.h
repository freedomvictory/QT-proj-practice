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
    void newFile();
    bool loadFile(const QString &fileName);
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    QString userFriendlyCurrentFile(); 
    QString currentFile() {return curFile;};
    


protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentWasModified(); 

private:

    void setCurrentFile(const QString &fileName);

    QString curFile; 
    bool isUntitled;
    


};







#endif 