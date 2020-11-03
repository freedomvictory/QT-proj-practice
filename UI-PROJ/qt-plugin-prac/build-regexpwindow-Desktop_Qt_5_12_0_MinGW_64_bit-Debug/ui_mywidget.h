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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *labelNum;

    void setupUi(QWidget *myWidget)
    {
        if (myWidget->objectName().isEmpty())
            myWidget->setObjectName(QString::fromUtf8("myWidget"));
        myWidget->resize(400, 300);
        label = new QLabel(myWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 91, 16));
        label_2 = new QLabel(myWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 150, 141, 16));
        lineEdit = new QLineEdit(myWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 40, 113, 21));
        pushButton = new QPushButton(myWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 40, 93, 28));
        labelNum = new QLabel(myWidget);
        labelNum->setObjectName(QString::fromUtf8("labelNum"));
        labelNum->setGeometry(QRect(210, 150, 72, 15));

        retranslateUi(myWidget);

        QMetaObject::connectSlotsByName(myWidget);
    } // setupUi

    void retranslateUi(QWidget *myWidget)
    {
        myWidget->setWindowTitle(QApplication::translate("myWidget", "myWidget", nullptr));
        label->setText(QApplication::translate("myWidget", "\350\276\223\345\205\245\345\255\227\347\254\246\344\270\262\357\274\232", nullptr));
        label_2->setText(QApplication::translate("myWidget", "\345\207\272\347\216\260\347\232\204\347\254\254\344\270\200\344\270\252\346\225\260\345\255\227\344\270\272", nullptr));
        pushButton->setText(QApplication::translate("myWidget", "\350\277\207\346\273\244", nullptr));
        labelNum->setText(QApplication::translate("myWidget", "\346\227\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myWidget: public Ui_myWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
