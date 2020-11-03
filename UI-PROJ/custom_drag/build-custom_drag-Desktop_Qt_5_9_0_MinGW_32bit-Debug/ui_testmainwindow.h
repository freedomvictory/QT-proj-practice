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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testMainWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testMainWindow)
    {
        if (testMainWindow->objectName().isEmpty())
            testMainWindow->setObjectName(QStringLiteral("testMainWindow"));
        testMainWindow->resize(400, 300);
        menuBar = new QMenuBar(testMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        testMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testMainWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(testMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        testMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(testMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testMainWindow->setStatusBar(statusBar);

        retranslateUi(testMainWindow);

        QMetaObject::connectSlotsByName(testMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *testMainWindow)
    {
        testMainWindow->setWindowTitle(QApplication::translate("testMainWindow", "testMainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testMainWindow: public Ui_testMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAINWINDOW_H
