/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SortDialog
{
public:
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;
    QPushButton *moreButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *secondaryGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *secondaryColumnLabel;
    QLabel *secondaryOrderLabel;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *secondaryCoumnCombo;
    QComboBox *secondaryOrderCombo;
    QGroupBox *tertiaryGroupBox;
    QGridLayout *gridLayout_4;
    QLabel *teritiaryColumnLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *tertiaryOrderLabel;
    QComboBox *teritiaryColumnCombo;
    QComboBox *tertiaryOrderOrder;
    QGroupBox *primarykeyGroupBox;
    QGridLayout *gridLayout;
    QLabel *columnLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *orderLabel;
    QComboBox *primaryColumnCombo;
    QComboBox *primaryCorderCombo;

    void setupUi(QDialog *SortDialog)
    {
        if (SortDialog->objectName().isEmpty())
            SortDialog->setObjectName(QStringLiteral("SortDialog"));
        SortDialog->resize(456, 367);
        gridLayout_6 = new QGridLayout(SortDialog);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        okButton = new QPushButton(SortDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(SortDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        verticalSpacer = new QSpacerItem(108, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moreButton = new QPushButton(SortDialog);
        moreButton->setObjectName(QStringLiteral("moreButton"));
        moreButton->setCheckable(true);

        verticalLayout->addWidget(moreButton);


        gridLayout_6->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 51, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 1, 0, 1, 1);

        secondaryGroupBox = new QGroupBox(SortDialog);
        secondaryGroupBox->setObjectName(QStringLiteral("secondaryGroupBox"));
        gridLayout_3 = new QGridLayout(secondaryGroupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        secondaryColumnLabel = new QLabel(secondaryGroupBox);
        secondaryColumnLabel->setObjectName(QStringLiteral("secondaryColumnLabel"));

        gridLayout_3->addWidget(secondaryColumnLabel, 0, 0, 1, 1);

        secondaryOrderLabel = new QLabel(secondaryGroupBox);
        secondaryOrderLabel->setObjectName(QStringLiteral("secondaryOrderLabel"));

        gridLayout_3->addWidget(secondaryOrderLabel, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(176, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        secondaryCoumnCombo = new QComboBox(secondaryGroupBox);
        secondaryCoumnCombo->setObjectName(QStringLiteral("secondaryCoumnCombo"));

        gridLayout_3->addWidget(secondaryCoumnCombo, 0, 1, 1, 1);

        secondaryOrderCombo = new QComboBox(secondaryGroupBox);
        secondaryOrderCombo->setObjectName(QStringLiteral("secondaryOrderCombo"));

        gridLayout_3->addWidget(secondaryOrderCombo, 1, 1, 1, 2);


        gridLayout_6->addWidget(secondaryGroupBox, 2, 0, 1, 1);

        tertiaryGroupBox = new QGroupBox(SortDialog);
        tertiaryGroupBox->setObjectName(QStringLiteral("tertiaryGroupBox"));
        gridLayout_4 = new QGridLayout(tertiaryGroupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        teritiaryColumnLabel = new QLabel(tertiaryGroupBox);
        teritiaryColumnLabel->setObjectName(QStringLiteral("teritiaryColumnLabel"));

        gridLayout_4->addWidget(teritiaryColumnLabel, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(176, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        tertiaryOrderLabel = new QLabel(tertiaryGroupBox);
        tertiaryOrderLabel->setObjectName(QStringLiteral("tertiaryOrderLabel"));

        gridLayout_4->addWidget(tertiaryOrderLabel, 1, 0, 1, 1);

        teritiaryColumnCombo = new QComboBox(tertiaryGroupBox);
        teritiaryColumnCombo->setObjectName(QStringLiteral("teritiaryColumnCombo"));

        gridLayout_4->addWidget(teritiaryColumnCombo, 0, 1, 1, 1);

        tertiaryOrderOrder = new QComboBox(tertiaryGroupBox);
        tertiaryOrderOrder->setObjectName(QStringLiteral("tertiaryOrderOrder"));

        gridLayout_4->addWidget(tertiaryOrderOrder, 1, 1, 1, 2);

        teritiaryColumnLabel->raise();
        tertiaryOrderLabel->raise();
        teritiaryColumnCombo->raise();
        tertiaryOrderOrder->raise();

        gridLayout_6->addWidget(tertiaryGroupBox, 3, 0, 1, 1);

        primarykeyGroupBox = new QGroupBox(SortDialog);
        primarykeyGroupBox->setObjectName(QStringLiteral("primarykeyGroupBox"));
        gridLayout = new QGridLayout(primarykeyGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        columnLabel = new QLabel(primarykeyGroupBox);
        columnLabel->setObjectName(QStringLiteral("columnLabel"));

        gridLayout->addWidget(columnLabel, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(176, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        orderLabel = new QLabel(primarykeyGroupBox);
        orderLabel->setObjectName(QStringLiteral("orderLabel"));

        gridLayout->addWidget(orderLabel, 1, 0, 1, 1);

        primaryColumnCombo = new QComboBox(primarykeyGroupBox);
        primaryColumnCombo->setObjectName(QStringLiteral("primaryColumnCombo"));

        gridLayout->addWidget(primaryColumnCombo, 0, 1, 1, 1);

        primaryCorderCombo = new QComboBox(primarykeyGroupBox);
        primaryCorderCombo->setObjectName(QStringLiteral("primaryCorderCombo"));

        gridLayout->addWidget(primaryCorderCombo, 1, 1, 1, 2);


        gridLayout_6->addWidget(primarykeyGroupBox, 0, 0, 1, 1);

        tertiaryGroupBox->raise();
        secondaryGroupBox->raise();
        primarykeyGroupBox->raise();
        QWidget::setTabOrder(primaryColumnCombo, primaryCorderCombo);
        QWidget::setTabOrder(primaryCorderCombo, secondaryCoumnCombo);
        QWidget::setTabOrder(secondaryCoumnCombo, secondaryOrderCombo);
        QWidget::setTabOrder(secondaryOrderCombo, teritiaryColumnCombo);
        QWidget::setTabOrder(teritiaryColumnCombo, tertiaryOrderOrder);
        QWidget::setTabOrder(tertiaryOrderOrder, okButton);
        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, moreButton);

        retranslateUi(SortDialog);
        QObject::connect(okButton, SIGNAL(clicked()), SortDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SortDialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), secondaryGroupBox, SLOT(setVisible(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), tertiaryGroupBox, SLOT(setVisible(bool)));

        okButton->setDefault(true);
        cancelButton->setDefault(true);
        moreButton->setDefault(true);


        QMetaObject::connectSlotsByName(SortDialog);
    } // setupUi

    void retranslateUi(QDialog *SortDialog)
    {
        SortDialog->setWindowTitle(QApplication::translate("SortDialog", "Sort", Q_NULLPTR));
        okButton->setText(QApplication::translate("SortDialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SortDialog", "Cancel", Q_NULLPTR));
        moreButton->setText(QApplication::translate("SortDialog", "&More", Q_NULLPTR));
        secondaryGroupBox->setTitle(QApplication::translate("SortDialog", "&Secondary Key", Q_NULLPTR));
        secondaryColumnLabel->setText(QApplication::translate("SortDialog", "Column:", Q_NULLPTR));
        secondaryOrderLabel->setText(QApplication::translate("SortDialog", "Order:", Q_NULLPTR));
        secondaryCoumnCombo->clear();
        secondaryCoumnCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", Q_NULLPTR)
        );
        secondaryOrderCombo->clear();
        secondaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", Q_NULLPTR)
         << QApplication::translate("SortDialog", "Descending", Q_NULLPTR)
        );
        tertiaryGroupBox->setTitle(QApplication::translate("SortDialog", "&Tertiary Key", Q_NULLPTR));
        teritiaryColumnLabel->setText(QApplication::translate("SortDialog", "Column:", Q_NULLPTR));
        tertiaryOrderLabel->setText(QApplication::translate("SortDialog", "Order:", Q_NULLPTR));
        teritiaryColumnCombo->clear();
        teritiaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", Q_NULLPTR)
        );
        tertiaryOrderOrder->clear();
        tertiaryOrderOrder->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", Q_NULLPTR)
         << QApplication::translate("SortDialog", "Descending", Q_NULLPTR)
        );
        primarykeyGroupBox->setTitle(QApplication::translate("SortDialog", "&Primary Key", Q_NULLPTR));
        columnLabel->setText(QApplication::translate("SortDialog", "Column:", Q_NULLPTR));
        orderLabel->setText(QApplication::translate("SortDialog", "Order:", Q_NULLPTR));
        primaryColumnCombo->clear();
        primaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", Q_NULLPTR)
        );
        primaryCorderCombo->clear();
        primaryCorderCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", Q_NULLPTR)
         << QApplication::translate("SortDialog", "Descending", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class SortDialog: public Ui_SortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
