/********************************************************************************
** Form generated from reading UI file 'bform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BFORM_H
#define UI_BFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BForm
{
public:
    QPushButton *pushButton_C;

    void setupUi(QWidget *BForm)
    {
        if (BForm->objectName().isEmpty())
            BForm->setObjectName(QStringLiteral("BForm"));
        BForm->resize(800, 537);
        pushButton_C = new QPushButton(BForm);
        pushButton_C->setObjectName(QStringLiteral("pushButton_C"));
        pushButton_C->setGeometry(QRect(350, 240, 93, 131));

        retranslateUi(BForm);

        QMetaObject::connectSlotsByName(BForm);
    } // setupUi

    void retranslateUi(QWidget *BForm)
    {
        BForm->setWindowTitle(QApplication::translate("BForm", "Form", Q_NULLPTR));
        pushButton_C->setText(QApplication::translate("BForm", "C", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BForm: public Ui_BForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BFORM_H
