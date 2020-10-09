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
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QFontComboBox *fontComboBox;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nLabel;
    QLineEdit *nLineEdit;
    QLabel *sLabel;
    QLineEdit *sLineEdit;
    QLabel *aLabel;
    QLineEdit *aLineEdit;
    QLabel *mLabel;
    QLineEdit *mLineEdit;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(736, 286);
        fontComboBox = new QFontComboBox(MyWidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(30, 170, 112, 21));
        textEdit = new QTextEdit(MyWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(40, 210, 256, 61));
        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 160, 93, 28));
        formLayoutWidget = new QWidget(MyWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 671, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nLabel = new QLabel(formLayoutWidget);
        nLabel->setObjectName(QString::fromUtf8("nLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nLabel);

        nLineEdit = new QLineEdit(formLayoutWidget);
        nLineEdit->setObjectName(QString::fromUtf8("nLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nLineEdit);

        sLabel = new QLabel(formLayoutWidget);
        sLabel->setObjectName(QString::fromUtf8("sLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, sLabel);

        sLineEdit = new QLineEdit(formLayoutWidget);
        sLineEdit->setObjectName(QString::fromUtf8("sLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, sLineEdit);

        aLabel = new QLabel(formLayoutWidget);
        aLabel->setObjectName(QString::fromUtf8("aLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, aLabel);

        aLineEdit = new QLineEdit(formLayoutWidget);
        aLineEdit->setObjectName(QString::fromUtf8("aLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, aLineEdit);

        mLabel = new QLabel(formLayoutWidget);
        mLabel->setObjectName(QString::fromUtf8("mLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, mLabel);

        mLineEdit = new QLineEdit(formLayoutWidget);
        mLineEdit->setObjectName(QString::fromUtf8("mLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, mLineEdit);

#ifndef QT_NO_SHORTCUT
        nLabel->setBuddy(nLineEdit);
        sLabel->setBuddy(sLineEdit);
        mLabel->setBuddy(mLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", nullptr));
        pushButton->setText(QApplication::translate("MyWidget", "PushButton", nullptr));
        nLabel->setText(QApplication::translate("MyWidget", "\345\247\223\345\220\215(&N)", nullptr));
        sLabel->setText(QApplication::translate("MyWidget", "\346\200\247\345\210\253(&S)", nullptr));
        aLabel->setText(QApplication::translate("MyWidget", "\345\271\264\351\276\204(A)", nullptr));
        mLabel->setText(QApplication::translate("MyWidget", "\351\202\256\347\256\261(&M)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
