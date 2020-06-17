#include "testmainwindow.h"
#include "ui_testmainwindow.h"
#include <QToolButton>
#include <QLabel>
#include <QTextEdit>
#include <QMdiSubWindow>
#include "myaction.h"
#include <QTextFrame>
#include <QDebug>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include "mysyntaxhighlighter.h"
#include <QMimeData>


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

    //AD OUR OWN ACTION
    //docuemnt()
    Myaction *action = new Myaction;
    ui->menuCUSTOM->addAction(action);

    connect(action, SIGNAL(getText(QString)), this, SLOT(setText(QString)));

    //full text doucument structure == <qt creator>
    QTextDocument *document = ui->myTextEdit->document(); //got `document` object
    QTextFrame *rootFrame = document->rootFrame();        //got root frame

    QTextFrameFormat format;                              //create frame format
    format.setBorderBrush(Qt::red);
    format.setBorder(3);
    rootFrame->setFrameFormat(format);                    //set frame format

    /******************************/
    //cursor
    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::lightGray);
    frameFormat.setMargin(10);
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);

    QTextCursor cursor = ui->myTextEdit->textCursor();
    cursor.insertFrame(frameFormat);

    //test textBlock ,add a action on toolBar
    QAction *action_textFrame = new QAction(tr("&Frame"), this);
    connect(action_textFrame, &QAction::triggered, this, &testMainWindow::showTextFrame);
    ui->mainToolBar->addAction(action_textFrame);

    // add an new action on mainToolBar
    QAction *action_textBlock = new QAction(tr("Block"), this);
    connect(action_textBlock, &QAction::triggered, this, &testMainWindow::showTextBlock);
    ui->mainToolBar->addAction(action_textBlock);

    //add an new acition on mainToolBar , it is used for set Text Font
    QAction *action_font = new QAction(tr("Font"), this);
    action_font->setCheckable(true);
    connect(action_font, &QAction::toggled, this, &testMainWindow::setTextFont);
    ui->mainToolBar->addAction(action_font);


    /**********************find dialog********************************************/

    //add a new action on menuBar
    QAction *action_textFind = new QAction(tr("FIND"), this);
    connect(action_textFind, &QAction::triggered, this, &testMainWindow::textFind);
    ui->mainToolBar->addAction(action_textFind);

    //create find dialog
    find_dialog = new QDialog(this);
    find_dialog_lineEdit = new QLineEdit(find_dialog);
    QPushButton *find_next_button = new QPushButton(find_dialog);
    find_next_button->setText(tr("find next"));
    connect(find_next_button, &QPushButton::clicked, this, &testMainWindow::findNext);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(find_dialog_lineEdit);
    layout->addWidget(find_next_button);
    find_dialog->setLayout(layout);

    // add highlighter
    highlighter = new MySyntaxHighlighter(ui->myTextEdit->document());
    ui->myTextEdit->append(tr("<h1><font color = red>USE HTML</font></h1 >"));

    /*got total window drop event*/
    setCentralWidget(ui->myTextEdit);
    ui->myTextEdit->setAcceptDrops(false);
    setAcceptDrops(true);

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

void testMainWindow::setText(const QString &string)
{
    ui->myTextEdit->setText(string); //set editor show string
}


\
void testMainWindow::showTextFrame()
{
    QTextDocument *document = ui->myTextEdit->document();
    QTextFrame *frame = document->rootFrame();

    QTextFrame::iterator it;
    for(it = frame->begin(); !(it.atEnd()); ++it)
    {
        QTextFrame *childFrame = it.currentFrame();
        QTextBlock childBlock = it.currentBlock();

        if(childFrame)
        {
            qDebug() << "frame";
        }
        if(childBlock.isValid())
        {
            qDebug() << "block:" << childBlock.text();
        }
    }
}

void testMainWindow::showTextBlock()
{
    QTextDocument *document = ui->myTextEdit->document();
    QTextBlock block = document->firstBlock();

    for(int i = 0; i < document->blockCount(); i++)\
    {
        qDebug() << tr("Text block : %1 , Text block first line number: %2, length: %3, content ")
                    .arg(i).arg(block.firstLineNumber()).arg(block.length())
                 << block.text();

        block = block.next();
    }


}

void testMainWindow::setTextFont(bool checked)
{

    if(checked)
    {
        QTextCursor cursor = ui->myTextEdit->textCursor();
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);

        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::lightGray);
        charFormat.setForeground(Qt::blue);
        charFormat.setFont(QFont(tr("宋体"), 12, QFont::Bold, true));
        charFormat.setFontUnderline(true);

        cursor.setCharFormat(charFormat);
        cursor.insertText(tr("测试字体"));
    }
    else
    {
        //TODO: resume default font format
    }
}


void testMainWindow::textFind()
{

    find_dialog->show();
}


void testMainWindow::findNext()
{

    QString string = find_dialog_lineEdit->text();

    bool isfind = ui->myTextEdit->find(string, QTextDocument::FindBackward);

    if(isfind)
    {
        qDebug() << tr("line : %1, column : %2")
                    .arg(ui->myTextEdit->textCursor().blockNumber())
                    .arg(ui->myTextEdit->textCursor().columnNumber());

    }


}

void testMainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "drogEnterEvent\n";
    if(event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
    else
    {
        event->ignore();
    }
}

void testMainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();
        QString fileName = urlList.at(0).toLocalFile();

        if(!fileName.isEmpty())
        {
            QFile file(fileName);
            if(!file.open(QIODevice::ReadOnly))
            {
                return;
            }
            QTextStream in(&file);
            qDebug() << "hello,world\n";
            ui->myTextEdit->setText(in.readAll());
        }

    }




}
