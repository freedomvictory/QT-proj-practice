/********************************************************************************
** Form generated from reading UI file 'drawwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWWIDGET_H
#define UI_DRAWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drawWidget
{
public:

    void setupUi(QWidget *drawWidget)
    {
        if (drawWidget->objectName().isEmpty())
            drawWidget->setObjectName(QString::fromUtf8("drawWidget"));
        drawWidget->resize(400, 300);

        retranslateUi(drawWidget);

        QMetaObject::connectSlotsByName(drawWidget);
    } // setupUi

    void retranslateUi(QWidget *drawWidget)
    {
        drawWidget->setWindowTitle(QApplication::translate("drawWidget", "drawWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class drawWidget: public Ui_drawWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWWIDGET_H
