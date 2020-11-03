/********************************************************************************
** Form generated from reading UI file 'keytest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYTEST_H
#define UI_KEYTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyTest
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *keyTest)
    {
        if (keyTest->objectName().isEmpty())
            keyTest->setObjectName(QString::fromUtf8("keyTest"));
        keyTest->resize(735, 483);
        textBrowser = new QTextBrowser(keyTest);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(290, 190, 256, 192));

        retranslateUi(keyTest);

        QMetaObject::connectSlotsByName(keyTest);
    } // setupUi

    void retranslateUi(QWidget *keyTest)
    {
        keyTest->setWindowTitle(QApplication::translate("keyTest", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class keyTest: public Ui_keyTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYTEST_H
