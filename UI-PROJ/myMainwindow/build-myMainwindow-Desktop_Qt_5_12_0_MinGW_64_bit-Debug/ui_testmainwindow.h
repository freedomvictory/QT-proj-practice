/********************************************************************************
** Form generated from reading UI file 'testmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMAINWINDOW_H
#define UI_TESTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testMainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Save_As;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Paster;
    QAction *action_Delete;
    QAction *action_Recalculate;
    QAction *action_Sort;
    QAction *action_Find;
    QAction *action_Row;
    QAction *action_Column;
    QAction *action_All;
    QAction *actionA_TOOL;
    QAction *actionshow_Docker;
    QWidget *centralWidget;
    QTextBrowser *showTextBrowser;
    QMdiArea *myMdiArea;
    QTextEdit *myTextEdit;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuEdit;
    QMenu *menu_Select;
    QMenu *menuTools;
    QMenu *menuCUSTOM;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QDockWidget *mydockerWidget;
    QWidget *dockWidgetContents_4;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *testMainWindow)
    {
        if (testMainWindow->objectName().isEmpty())
            testMainWindow->setObjectName(QString::fromUtf8("testMainWindow"));
        testMainWindow->resize(861, 561);
        action_New = new QAction(testMainWindow);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        action_Open = new QAction(testMainWindow);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        action_Save = new QAction(testMainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        action_Save_As = new QAction(testMainWindow);
        action_Save_As->setObjectName(QString::fromUtf8("action_Save_As"));
        action_Cut = new QAction(testMainWindow);
        action_Cut->setObjectName(QString::fromUtf8("action_Cut"));
        action_Copy = new QAction(testMainWindow);
        action_Copy->setObjectName(QString::fromUtf8("action_Copy"));
        action_Paster = new QAction(testMainWindow);
        action_Paster->setObjectName(QString::fromUtf8("action_Paster"));
        action_Delete = new QAction(testMainWindow);
        action_Delete->setObjectName(QString::fromUtf8("action_Delete"));
        action_Recalculate = new QAction(testMainWindow);
        action_Recalculate->setObjectName(QString::fromUtf8("action_Recalculate"));
        action_Sort = new QAction(testMainWindow);
        action_Sort->setObjectName(QString::fromUtf8("action_Sort"));
        action_Find = new QAction(testMainWindow);
        action_Find->setObjectName(QString::fromUtf8("action_Find"));
        action_Row = new QAction(testMainWindow);
        action_Row->setObjectName(QString::fromUtf8("action_Row"));
        action_Column = new QAction(testMainWindow);
        action_Column->setObjectName(QString::fromUtf8("action_Column"));
        action_All = new QAction(testMainWindow);
        action_All->setObjectName(QString::fromUtf8("action_All"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/images/127374.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_All->setIcon(icon);
        actionA_TOOL = new QAction(testMainWindow);
        actionA_TOOL->setObjectName(QString::fromUtf8("actionA_TOOL"));
        actionA_TOOL->setCheckable(true);
        actionA_TOOL->setIcon(icon);
        actionshow_Docker = new QAction(testMainWindow);
        actionshow_Docker->setObjectName(QString::fromUtf8("actionshow_Docker"));
        centralWidget = new QWidget(testMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        showTextBrowser = new QTextBrowser(centralWidget);
        showTextBrowser->setObjectName(QString::fromUtf8("showTextBrowser"));
        showTextBrowser->setGeometry(QRect(540, 0, 201, 221));
        myMdiArea = new QMdiArea(centralWidget);
        myMdiArea->setObjectName(QString::fromUtf8("myMdiArea"));
        myMdiArea->setGeometry(QRect(10, 10, 311, 491));
        myTextEdit = new QTextEdit(centralWidget);
        myTextEdit->setObjectName(QString::fromUtf8("myTextEdit"));
        myTextEdit->setGeometry(QRect(330, 240, 411, 211));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(560, 470, 131, 21));
        testMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 861, 26));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menu_Select = new QMenu(menuEdit);
        menu_Select->setObjectName(QString::fromUtf8("menu_Select"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuCUSTOM = new QMenu(menuBar);
        menuCUSTOM->setObjectName(QString::fromUtf8("menuCUSTOM"));
        testMainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(testMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        testMainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(testMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        testMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        mydockerWidget = new QDockWidget(testMainWindow);
        mydockerWidget->setObjectName(QString::fromUtf8("mydockerWidget"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        pushButton = new QPushButton(dockWidgetContents_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 250, 71, 28));
        toolButton = new QToolButton(dockWidgetContents_4);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(40, 220, 47, 21));
        textEdit = new QTextEdit(dockWidgetContents_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 290, 81, 87));
        mydockerWidget->setWidget(dockWidgetContents_4);
        testMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), mydockerWidget);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuCUSTOM->menuAction());
        menu_File->addSeparator();
        menu_File->addAction(action_New);
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addAction(action_Save_As);
        menu_File->addAction(actionshow_Docker);
        menuEdit->addAction(action_Cut);
        menuEdit->addAction(action_Copy);
        menuEdit->addAction(action_Paster);
        menuEdit->addAction(action_Delete);
        menuEdit->addAction(menu_Select->menuAction());
        menuEdit->addAction(action_Find);
        menu_Select->addAction(action_Row);
        menu_Select->addAction(action_Column);
        menu_Select->addAction(action_All);
        menuTools->addSeparator();
        menuTools->addAction(action_Recalculate);
        menuTools->addAction(action_Sort);
        mainToolBar->addSeparator();

        retranslateUi(testMainWindow);

        QMetaObject::connectSlotsByName(testMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *testMainWindow)
    {
        testMainWindow->setWindowTitle(QApplication::translate("testMainWindow", "testMainWindow", nullptr));
        action_New->setText(QApplication::translate("testMainWindow", "  &New", nullptr));
        action_Open->setText(QApplication::translate("testMainWindow", "  &Open", nullptr));
        action_Save->setText(QApplication::translate("testMainWindow", "  &Save", nullptr));
        action_Save_As->setText(QApplication::translate("testMainWindow", "  Save &As...", nullptr));
        action_Cut->setText(QApplication::translate("testMainWindow", "  Cu&t", nullptr));
        action_Copy->setText(QApplication::translate("testMainWindow", "  &Copy", nullptr));
        action_Paster->setText(QApplication::translate("testMainWindow", "  &Paster", nullptr));
        action_Delete->setText(QApplication::translate("testMainWindow", "  &Delete", nullptr));
        action_Recalculate->setText(QApplication::translate("testMainWindow", "  &Recalculate", nullptr));
        action_Sort->setText(QApplication::translate("testMainWindow", "  &Sort", nullptr));
        action_Find->setText(QApplication::translate("testMainWindow", "  &Find", nullptr));
        action_Row->setText(QApplication::translate("testMainWindow", "  &Row", nullptr));
        action_Column->setText(QApplication::translate("testMainWindow", "  &Column", nullptr));
        action_All->setText(QApplication::translate("testMainWindow", "  &All", nullptr));
        actionA_TOOL->setText(QApplication::translate("testMainWindow", "A_TOOL", nullptr));
#ifndef QT_NO_TOOLTIP
        actionA_TOOL->setToolTip(QApplication::translate("testMainWindow", "\346\265\213\350\257\225", nullptr));
#endif // QT_NO_TOOLTIP
        actionshow_Docker->setText(QApplication::translate("testMainWindow", "  &show Docker", nullptr));
        menu_File->setTitle(QApplication::translate("testMainWindow", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("testMainWindow", "Edit", nullptr));
        menu_Select->setTitle(QApplication::translate("testMainWindow", "  &Select", nullptr));
        menuTools->setTitle(QApplication::translate("testMainWindow", "Tools", nullptr));
        menuCUSTOM->setTitle(QApplication::translate("testMainWindow", "CUSTOM", nullptr));
        mainToolBar->setWindowTitle(QApplication::translate("testMainWindow", "toolBar", nullptr));
        mydockerWidget->setWindowTitle(QApplication::translate("testMainWindow", "Tool Box", nullptr));
        pushButton->setText(QApplication::translate("testMainWindow", "PushButton", nullptr));
        toolButton->setText(QApplication::translate("testMainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testMainWindow: public Ui_testMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAINWINDOW_H
