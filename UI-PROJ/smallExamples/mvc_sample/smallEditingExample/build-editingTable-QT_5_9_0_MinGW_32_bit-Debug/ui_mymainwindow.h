/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myMainWindow
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myMainWindow)
    {
        if (myMainWindow->objectName().isEmpty())
            myMainWindow->setObjectName(QStringLiteral("myMainWindow"));
        myMainWindow->resize(786, 579);
        centralWidget = new QWidget(myMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 50, 521, 371));
        myMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(myMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 786, 26));
        myMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(myMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        myMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(myMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        myMainWindow->setStatusBar(statusBar);

        retranslateUi(myMainWindow);

        QMetaObject::connectSlotsByName(myMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *myMainWindow)
    {
        myMainWindow->setWindowTitle(QApplication::translate("myMainWindow", "myMainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class myMainWindow: public Ui_myMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
