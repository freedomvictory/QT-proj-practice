/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mywidget
{
public:
    QLineEdit *lineEdit;
    QFrame *line;
    QFrame *line_2;
    QPushButton *pushButton;

    void setupUi(QWidget *mywidget)
    {
        if (mywidget->objectName().isEmpty())
            mywidget->setObjectName(QString::fromUtf8("mywidget"));
        mywidget->resize(400, 300);
        lineEdit = new QLineEdit(mywidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(260, 160, 113, 21));
        line = new QFrame(mywidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(50, 100, 118, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(mywidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(100, 20, 3, 61));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(mywidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 120, 93, 28));

        retranslateUi(mywidget);

        QMetaObject::connectSlotsByName(mywidget);
    } // setupUi

    void retranslateUi(QWidget *mywidget)
    {
        mywidget->setWindowTitle(QApplication::translate("mywidget", "mywidget", nullptr));
        pushButton->setText(QApplication::translate("mywidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mywidget: public Ui_mywidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
