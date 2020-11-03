/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myMainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myMainWindow)
    {
        if (myMainWindow->objectName().isEmpty())
            myMainWindow->setObjectName(QString::fromUtf8("myMainWindow"));
        myMainWindow->resize(723, 354);
        myMainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"/*****\350\203\214\346\231\257\345\233\276\347\211\207******/\n"
"        background-image: url(:/image/beijing01.png);\n"
"}\n"
"\n"
"/*********************\346\214\211\351\222\256\351\203\250\344\273\266*******************/\n"
"QPushButton{\n"
"/*\350\203\214\346\231\257\350\211\262*/\n"
"        background-color: rgba(100, 225, 100, 30);\n"
"/*\350\276\271\346\241\206\346\240\267\345\274\217*/\n"
"        border-style: outset;\n"
"/*\350\276\271\346\241\206\345\256\275\345\272\246\344\270\2724\345\203\217\347\264\240*/\n"
"        border-width: 4px;\n"
"/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204*/\n"
"        border-radius: 10px;\n"
"/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"        border-color: rgba(255,225,255,30);\n"
"/*\345\255\227\344\275\223*/\n"
"        font:bold 14px;\n"
"/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"        color: rgba(0,0,0,100);\n"
"/*\345\241\253\350\241\254*/\n"
"        padding: 6px;\n"
"}\n"
"\n"
"/*"
                        "*************\351\274\240\346\240\207\346\202\254\345\201\234\345\234\250\346\214\211\351\222\256\344\270\212\346\227\266***************/\n"
"QPushButton:hover{\n"
"        background-color: rgba(100, 255, 100, 100);\n"
"	border-color: rgba(255, 255, 255, 200);\n"
"	color: rgba(0, 0, 0, 100);\n"
"}\n"
"\n"
"/****************\346\214\211\351\222\256\350\242\253\346\214\211\344\270\213\346\227\266***************/\n"
"QPushButton:pressed{\n"
"        background-color: rgba(100, 255, 100, 200);\n"
"	border-color: rgba(255, 255, 255, 30);\n"
"	border-style: inset;\n"
"	color: rgba(0, 0, 0, 100);\n"
"}\n"
"\n"
"/****************\346\273\221\345\235\227\351\203\250\344\273\266***************/\n"
"/*\346\260\264\345\271\263\346\273\221\345\235\227\347\232\204\346\211\213\346\237\204*/\n"
"QSlider::handle:horizontal{\n"
"        image: url(:/image/sliderHandle.png);\n"
"}\n"
"QSlider::sub-page:horizontal{\n"
"/*\350\276\271\346\241\206\345\233\276\347\211\207*/\n"
"        border-image: url(:/image/slider.png);\n"
"}\n"
""));
        centralWidget = new QWidget(myMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 37, 131, 61));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(360, 181, 111, 20));
        horizontalSlider->setMinimumSize(QSize(0, 0));
        horizontalSlider->setSizeIncrement(QSize(0, 0));
        horizontalSlider->setOrientation(Qt::Horizontal);
        myMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(myMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 723, 26));
        myMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(myMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        myMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(myMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        myMainWindow->setStatusBar(statusBar);

        retranslateUi(myMainWindow);

        QMetaObject::connectSlotsByName(myMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *myMainWindow)
    {
        myMainWindow->setWindowTitle(QApplication::translate("myMainWindow", "myMainWindow", nullptr));
        pushButton->setText(QApplication::translate("myMainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myMainWindow: public Ui_myMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
