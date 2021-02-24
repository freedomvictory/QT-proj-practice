/********************************************************************************
** Form generated from reading UI file 'mainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *manageBtn;
    QPushButton *chartBtn;
    QPushButton *passwdBtn;
    QStackedWidget *stackedWidget;
    QWidget *managePage;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *page;
    QSpinBox *sellNumSpinBox;
    QPushButton *sellCancelBtn;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_20;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *sellSumLineEdit;
    QPushButton *sellOkBtn;
    QLabel *label_12;
    QComboBox *sellBrandComboBox;
    QLineEdit *sellPriceLineEdit;
    QLabel *label_19;
    QComboBox *sellTypeComboBox;
    QLabel *sellLastNumLabel;
    QWidget *page_4;
    QLabel *label_13;
    QLabel *label_21;
    QComboBox *goodsBrandComboBox;
    QComboBox *goodsTypeComboBox;
    QPushButton *goodsOkBtn;
    QLineEdit *goodsSumLineEdit;
    QLabel *label_3;
    QLineEdit *goodsPriceLineEdit;
    QLabel *label_14;
    QLabel *label_22;
    QLabel *label_15;
    QSpinBox *goodsNumSpinBox;
    QPushButton *goodsCancelBtn;
    QLabel *label_6;
    QWidget *page_3;
    QListWidget *daliyList;
    QWidget *page_2;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->resize(750, 500);
        horizontalLayoutWidget = new QWidget(mainWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 701, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        manageBtn = new QPushButton(horizontalLayoutWidget);
        manageBtn->setObjectName(QStringLiteral("manageBtn"));

        horizontalLayout->addWidget(manageBtn);

        chartBtn = new QPushButton(horizontalLayoutWidget);
        chartBtn->setObjectName(QStringLiteral("chartBtn"));

        horizontalLayout->addWidget(chartBtn);

        passwdBtn = new QPushButton(horizontalLayoutWidget);
        passwdBtn->setObjectName(QStringLiteral("passwdBtn"));

        horizontalLayout->addWidget(passwdBtn);

        stackedWidget = new QStackedWidget(mainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(25, 70, 700, 410));
        managePage = new QWidget();
        managePage->setObjectName(QStringLiteral("managePage"));
        label = new QLabel(managePage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 10, 501, 21));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignCenter);
        toolBox = new QToolBox(managePage);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(0, 40, 351, 331));
        toolBox->setFrameShape(QFrame::WinPanel);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 347, 237));
        sellNumSpinBox = new QSpinBox(page);
        sellNumSpinBox->setObjectName(QStringLiteral("sellNumSpinBox"));
        sellNumSpinBox->setGeometry(QRect(80, 120, 61, 20));
        sellCancelBtn = new QPushButton(page);
        sellCancelBtn->setObjectName(QStringLiteral("sellCancelBtn"));
        sellCancelBtn->setGeometry(QRect(167, 210, 75, 23));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(38, 10, 36, 16));
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(38, 47, 36, 16));
        label_20 = new QLabel(page);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(37, 160, 36, 16));
        label_10 = new QLabel(page);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(38, 80, 36, 16));
        label_11 = new QLabel(page);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(38, 120, 36, 16));
        sellSumLineEdit = new QLineEdit(page);
        sellSumLineEdit->setObjectName(QStringLiteral("sellSumLineEdit"));
        sellSumLineEdit->setGeometry(QRect(80, 160, 100, 20));
        sellOkBtn = new QPushButton(page);
        sellOkBtn->setObjectName(QStringLiteral("sellOkBtn"));
        sellOkBtn->setGeometry(QRect(47, 210, 75, 23));
        label_12 = new QLabel(page);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(197, 80, 54, 12));
        sellBrandComboBox = new QComboBox(page);
        sellBrandComboBox->setObjectName(QStringLiteral("sellBrandComboBox"));
        sellBrandComboBox->setGeometry(QRect(80, 47, 210, 20));
        sellPriceLineEdit = new QLineEdit(page);
        sellPriceLineEdit->setObjectName(QStringLiteral("sellPriceLineEdit"));
        sellPriceLineEdit->setGeometry(QRect(80, 80, 100, 20));
        label_19 = new QLabel(page);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(196, 160, 54, 12));
        sellTypeComboBox = new QComboBox(page);
        sellTypeComboBox->setObjectName(QStringLiteral("sellTypeComboBox"));
        sellTypeComboBox->setGeometry(QRect(80, 10, 151, 20));
        sellLastNumLabel = new QLabel(page);
        sellLastNumLabel->setObjectName(QStringLiteral("sellLastNumLabel"));
        sellLastNumLabel->setGeometry(QRect(150, 120, 111, 16));
        toolBox->addItem(page, QString::fromUtf8("\345\207\272\345\224\256\345\225\206\345\223\201"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 347, 237));
        label_13 = new QLabel(page_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 73, 36, 16));
        label_21 = new QLabel(page_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(39, 153, 36, 16));
        goodsBrandComboBox = new QComboBox(page_4);
        goodsBrandComboBox->setObjectName(QStringLiteral("goodsBrandComboBox"));
        goodsBrandComboBox->setGeometry(QRect(82, 40, 210, 20));
        goodsTypeComboBox = new QComboBox(page_4);
        goodsTypeComboBox->setObjectName(QStringLiteral("goodsTypeComboBox"));
        goodsTypeComboBox->setGeometry(QRect(82, 3, 151, 20));
        goodsOkBtn = new QPushButton(page_4);
        goodsOkBtn->setObjectName(QStringLiteral("goodsOkBtn"));
        goodsOkBtn->setGeometry(QRect(49, 203, 75, 23));
        goodsSumLineEdit = new QLineEdit(page_4);
        goodsSumLineEdit->setObjectName(QStringLiteral("goodsSumLineEdit"));
        goodsSumLineEdit->setGeometry(QRect(82, 153, 100, 20));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 3, 36, 16));
        goodsPriceLineEdit = new QLineEdit(page_4);
        goodsPriceLineEdit->setObjectName(QStringLiteral("goodsPriceLineEdit"));
        goodsPriceLineEdit->setGeometry(QRect(82, 73, 100, 20));
        label_14 = new QLabel(page_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 113, 36, 16));
        label_22 = new QLabel(page_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(198, 153, 54, 12));
        label_15 = new QLabel(page_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(199, 73, 54, 12));
        goodsNumSpinBox = new QSpinBox(page_4);
        goodsNumSpinBox->setObjectName(QStringLiteral("goodsNumSpinBox"));
        goodsNumSpinBox->setGeometry(QRect(82, 113, 61, 20));
        goodsCancelBtn = new QPushButton(page_4);
        goodsCancelBtn->setObjectName(QStringLiteral("goodsCancelBtn"));
        goodsCancelBtn->setGeometry(QRect(169, 203, 75, 23));
        label_6 = new QLabel(page_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 40, 36, 16));
        toolBox->addItem(page_4, QString::fromUtf8("\345\267\262\346\234\211\345\225\206\345\223\201\345\205\245\345\272\223"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 347, 237));
        toolBox->addItem(page_3, QString::fromUtf8("\346\226\260\345\225\206\345\223\201\345\205\245\345\272\223"));
        daliyList = new QListWidget(managePage);
        daliyList->setObjectName(QStringLiteral("daliyList"));
        daliyList->setGeometry(QRect(375, 41, 331, 321));
        stackedWidget->addWidget(managePage);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(mainWidget);

        stackedWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QApplication::translate("mainWidget", "\346\225\260\346\215\256\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        manageBtn->setText(QApplication::translate("mainWidget", "\345\225\206\345\223\201\347\256\241\347\220\206", Q_NULLPTR));
        chartBtn->setText(QApplication::translate("mainWidget", "\351\224\200\345\224\256\347\273\237\350\256\241", Q_NULLPTR));
        passwdBtn->setText(QApplication::translate("mainWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("mainWidget", "\345\225\206\345\223\201\347\256\241\347\220\206", Q_NULLPTR));
        sellCancelBtn->setText(QApplication::translate("mainWidget", "\345\217\226\346\266\210", Q_NULLPTR));
        label_2->setText(QApplication::translate("mainWidget", "\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("mainWidget", "\345\223\201\347\211\214\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("mainWidget", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("mainWidget", "\345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("mainWidget", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        sellOkBtn->setText(QApplication::translate("mainWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("mainWidget", "\345\205\203", Q_NULLPTR));
        label_19->setText(QApplication::translate("mainWidget", "\345\205\203", Q_NULLPTR));
        sellLastNumLabel->setText(QApplication::translate("mainWidget", "\345\211\251\344\275\231\346\225\260\351\207\217\357\274\232000", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("mainWidget", "\345\207\272\345\224\256\345\225\206\345\223\201", Q_NULLPTR));
        label_13->setText(QApplication::translate("mainWidget", "\345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        label_21->setText(QApplication::translate("mainWidget", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        goodsOkBtn->setText(QApplication::translate("mainWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("mainWidget", "\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("mainWidget", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("mainWidget", "\345\205\203", Q_NULLPTR));
        label_15->setText(QApplication::translate("mainWidget", "\345\205\203", Q_NULLPTR));
        goodsCancelBtn->setText(QApplication::translate("mainWidget", "\345\217\226\346\266\210", Q_NULLPTR));
        label_6->setText(QApplication::translate("mainWidget", "\345\223\201\347\211\214\357\274\232", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("mainWidget", "\345\267\262\346\234\211\345\225\206\345\223\201\345\205\245\345\272\223", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("mainWidget", "\346\226\260\345\225\206\345\223\201\345\205\245\345\272\223", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
