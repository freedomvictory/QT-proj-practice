/********************************************************************************
** Form generated from reading UI file 'cform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFORM_H
#define UI_CFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CForm
{
public:
    QPushButton *pushButton_A;

    void setupUi(QWidget *CForm)
    {
        if (CForm->objectName().isEmpty())
            CForm->setObjectName(QStringLiteral("CForm"));
        CForm->resize(761, 603);
        pushButton_A = new QPushButton(CForm);
        pushButton_A->setObjectName(QStringLiteral("pushButton_A"));
        pushButton_A->setGeometry(QRect(370, 260, 93, 171));

        retranslateUi(CForm);

        QMetaObject::connectSlotsByName(CForm);
    } // setupUi

    void retranslateUi(QWidget *CForm)
    {
        CForm->setWindowTitle(QApplication::translate("CForm", "Form", Q_NULLPTR));
        pushButton_A->setText(QApplication::translate("CForm", "A", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CForm: public Ui_CForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFORM_H
