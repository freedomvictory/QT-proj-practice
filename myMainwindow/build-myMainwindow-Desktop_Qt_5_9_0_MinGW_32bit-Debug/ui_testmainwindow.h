/********************************************************************************
** Form generated from reading UI file 'testmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMAINWINDOW_H
#define UI_TESTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
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
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuEdit;
    QMenu *menu_Select;
    QMenu *menuTools;
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
            testMainWindow->setObjectName(QStringLiteral("testMainWindow"));
        testMainWindow->resize(861, 561);
        action_New = new QAction(testMainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        action_Open = new QAction(testMainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        action_Save = new QAction(testMainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        action_Save_As = new QAction(testMainWindow);
        action_Save_As->setObjectName(QStringLiteral("action_Save_As"));
        action_Cut = new QAction(testMainWindow);
        action_Cut->setObjectName(QStringLiteral("action_Cut"));
        action_Copy = new QAction(testMainWindow);
        action_Copy->setObjectName(QStringLiteral("action_Copy"));
        action_Paster = new QAction(testMainWindow);
        action_Paster->setObjectName(QStringLiteral("action_Paster"));
        action_Delete = new QAction(testMainWindow);
        action_Delete->setObjectName(QStringLiteral("action_Delete"));
        action_Recalculate = new QAction(testMainWindow);
        action_Recalculate->setObjectName(QStringLiteral("action_Recalculate"));
        action_Sort = new QAction(testMainWindow);
        action_Sort->setObjectName(QStringLiteral("action_Sort"));
        action_Find = new QAction(testMainWindow);
        action_Find->setObjectName(QStringLiteral("action_Find"));
        action_Row = new QAction(testMainWindow);
        action_Row->setObjectName(QStringLiteral("action_Row"));
        action_Column = new QAction(testMainWindow);
        action_Column->setObjectName(QStringLiteral("action_Column"));
        action_All = new QAction(testMainWindow);
        action_All->setObjectName(QStringLiteral("action_All"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/images/127374.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_All->setIcon(icon);
        actionA_TOOL = new QAction(testMainWindow);
        actionA_TOOL->setObjectName(QStringLiteral("actionA_TOOL"));
        actionA_TOOL->setCheckable(true);
        actionA_TOOL->setIcon(icon);
        actionshow_Docker = new QAction(testMainWindow);
        actionshow_Docker->setObjectName(QStringLiteral("actionshow_Docker"));
        centralWidget = new QWidget(testMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        showTextBrowser = new QTextBrowser(centralWidget);
        showTextBrowser->setObjectName(QStringLiteral("showTextBrowser"));
        showTextBrowser->setGeometry(QRect(540, 0, 81, 221));
        myMdiArea = new QMdiArea(centralWidget);
        myMdiArea->setObjectName(QStringLiteral("myMdiArea"));
        myMdiArea->setGeometry(QRect(10, 10, 511, 491));
        testMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 861, 26));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menu_Select = new QMenu(menuEdit);
        menu_Select->setObjectName(QStringLiteral("menu_Select"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        testMainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(testMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testMainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(testMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        mydockerWidget = new QDockWidget(testMainWindow);
        mydockerWidget->setObjectName(QStringLiteral("mydockerWidget"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        pushButton = new QPushButton(dockWidgetContents_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 250, 71, 28));
        toolButton = new QToolButton(dockWidgetContents_4);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(40, 220, 47, 21));
        textEdit = new QTextEdit(dockWidgetContents_4);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 290, 81, 87));
        mydockerWidget->setWidget(dockWidgetContents_4);
        testMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), mydockerWidget);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
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
        testMainWindow->setWindowTitle(QApplication::translate("testMainWindow", "testMainWindow", Q_NULLPTR));
        action_New->setText(QApplication::translate("testMainWindow", "  &New", Q_NULLPTR));
        action_Open->setText(QApplication::translate("testMainWindow", "  &Open", Q_NULLPTR));
        action_Save->setText(QApplication::translate("testMainWindow", "  &Save", Q_NULLPTR));
        action_Save_As->setText(QApplication::translate("testMainWindow", "  Save &As...", Q_NULLPTR));
        action_Cut->setText(QApplication::translate("testMainWindow", "  Cu&t", Q_NULLPTR));
        action_Copy->setText(QApplication::translate("testMainWindow", "  &Copy", Q_NULLPTR));
        action_Paster->setText(QApplication::translate("testMainWindow", "  &Paster", Q_NULLPTR));
        action_Delete->setText(QApplication::translate("testMainWindow", "  &Delete", Q_NULLPTR));
        action_Recalculate->setText(QApplication::translate("testMainWindow", "  &Recalculate", Q_NULLPTR));
        action_Sort->setText(QApplication::translate("testMainWindow", "  &Sort", Q_NULLPTR));
        action_Find->setText(QApplication::translate("testMainWindow", "  &Find", Q_NULLPTR));
        action_Row->setText(QApplication::translate("testMainWindow", "  &Row", Q_NULLPTR));
        action_Column->setText(QApplication::translate("testMainWindow", "  &Column", Q_NULLPTR));
        action_All->setText(QApplication::translate("testMainWindow", "  &All", Q_NULLPTR));
        actionA_TOOL->setText(QApplication::translate("testMainWindow", "A_TOOL", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionA_TOOL->setToolTip(QApplication::translate("testMainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionshow_Docker->setText(QApplication::translate("testMainWindow", "  &show Docker", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("testMainWindow", "&File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("testMainWindow", "Edit", Q_NULLPTR));
        menu_Select->setTitle(QApplication::translate("testMainWindow", "  &Select", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("testMainWindow", "Tools", Q_NULLPTR));
        mainToolBar->setWindowTitle(QApplication::translate("testMainWindow", "toolBar", Q_NULLPTR));
        mydockerWidget->setWindowTitle(QApplication::translate("testMainWindow", "Tool Box", Q_NULLPTR));
        pushButton->setText(QApplication::translate("testMainWindow", "PushButton", Q_NULLPTR));
        toolButton->setText(QApplication::translate("testMainWindow", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testMainWindow: public Ui_testMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAINWINDOW_H
