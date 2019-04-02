/********************************************************************************
** Form generated from reading UI file 'PaymentDetailDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTDETAILDLG_H
#define UI_PAYMENTDETAILDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>
#include "PaymentDetailWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PaymentDetailDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *backgroundWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *simpleAmtValueLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLabel *PaidAmtValueLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLabel *receivedAmtValueLabel;
    QPushButton *cashRefundBtn;
    PaymentDetailWidget *payDetailsWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QLabel *totalPayDetailsLabel;
    QLabel *label_7;

    void setupUi(QDialog *PaymentDetailDlg)
    {
        if (PaymentDetailDlg->objectName().isEmpty())
            PaymentDetailDlg->setObjectName(QStringLiteral("PaymentDetailDlg"));
        PaymentDetailDlg->resize(551, 324);
        PaymentDetailDlg->setMinimumSize(QSize(551, 324));
        verticalLayout = new QVBoxLayout(PaymentDetailDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(PaymentDetailDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 40));
        titleWidget->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(titleWidget);

        backgroundWidget = new QWidget(PaymentDetailDlg);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
        backgroundWidget->setMinimumSize(QSize(0, 284));
        backgroundWidget->setStyleSheet(QLatin1String("QWidget#backgroundWidget{\n"
"	border-image: url(:/paymentImage/payDetail_background.png);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(backgroundWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 0, 20, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(backgroundWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 48));
        label_3->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));

        horizontalLayout->addWidget(label_3);

        simpleAmtValueLabel = new QLabel(backgroundWidget);
        simpleAmtValueLabel->setObjectName(QStringLiteral("simpleAmtValueLabel"));
        simpleAmtValueLabel->setMinimumSize(QSize(0, 48));
        simpleAmtValueLabel->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"font-weight:bold;"));

        horizontalLayout->addWidget(simpleAmtValueLabel);

        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_4 = new QLabel(backgroundWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 48));
        label_4->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));

        horizontalLayout->addWidget(label_4);

        PaidAmtValueLabel = new QLabel(backgroundWidget);
        PaidAmtValueLabel->setObjectName(QStringLiteral("PaidAmtValueLabel"));
        PaidAmtValueLabel->setMinimumSize(QSize(0, 48));
        PaidAmtValueLabel->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"font-weight:bold;"));

        horizontalLayout->addWidget(PaidAmtValueLabel);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(backgroundWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 48));
        label_2->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));

        horizontalLayout->addWidget(label_2);

        receivedAmtValueLabel = new QLabel(backgroundWidget);
        receivedAmtValueLabel->setObjectName(QStringLiteral("receivedAmtValueLabel"));
        receivedAmtValueLabel->setMinimumSize(QSize(0, 48));
        receivedAmtValueLabel->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"font-weight:bold;"));

        horizontalLayout->addWidget(receivedAmtValueLabel);

        cashRefundBtn = new QPushButton(backgroundWidget);
        cashRefundBtn->setObjectName(QStringLiteral("cashRefundBtn"));
        cashRefundBtn->setMinimumSize(QSize(80, 30));
        cashRefundBtn->setStyleSheet(QLatin1String("QPushButton#cashRefundBtn {\n"
"	border-image: url(:/statementImage/cashRefund_nomal.png);\n"
"	color: rgb(255, 255, 255);\n"
"	border:none;\n"
"	font-size:14px;\n"
"}\n"
"\n"
"QPushButton#cashRefundBtn:pressed {\n"
"	border-image: url(:statementImage/cashRefund_press.png);\n"
"}"));

        horizontalLayout->addWidget(cashRefundBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        payDetailsWidget = new PaymentDetailWidget(backgroundWidget);
        payDetailsWidget->setObjectName(QStringLiteral("payDetailsWidget"));
        payDetailsWidget->setMinimumSize(QSize(512, 190));
        payDetailsWidget->setMaximumSize(QSize(512, 190));

        verticalLayout_2->addWidget(payDetailsWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_9 = new QLabel(backgroundWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(0, 40));
        label_9->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));

        horizontalLayout_2->addWidget(label_9);

        totalPayDetailsLabel = new QLabel(backgroundWidget);
        totalPayDetailsLabel->setObjectName(QStringLiteral("totalPayDetailsLabel"));
        totalPayDetailsLabel->setMinimumSize(QSize(0, 40));
        totalPayDetailsLabel->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:16px;\n"
"font-weight:bold;"));

        horizontalLayout_2->addWidget(totalPayDetailsLabel);

        label_7 = new QLabel(backgroundWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 40));
        label_7->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));

        horizontalLayout_2->addWidget(label_7);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(backgroundWidget);


        retranslateUi(PaymentDetailDlg);

        QMetaObject::connectSlotsByName(PaymentDetailDlg);
    } // setupUi

    void retranslateUi(QDialog *PaymentDetailDlg)
    {
        PaymentDetailDlg->setWindowTitle(QApplication::translate("PaymentDetailDlg", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("PaymentDetailDlg", "\346\225\264\345\215\225\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        simpleAmtValueLabel->setText(QApplication::translate("PaymentDetailDlg", "\357\277\2450.00", Q_NULLPTR));
        label_4->setText(QApplication::translate("PaymentDetailDlg", "\345\267\262\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        PaidAmtValueLabel->setText(QApplication::translate("PaymentDetailDlg", "\357\277\2450.00", Q_NULLPTR));
        label_2->setText(QApplication::translate("PaymentDetailDlg", "\345\276\205\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        receivedAmtValueLabel->setText(QApplication::translate("PaymentDetailDlg", "\357\277\2450.00", Q_NULLPTR));
        cashRefundBtn->setText(QApplication::translate("PaymentDetailDlg", "\347\216\260\351\207\221\351\200\200\346\254\276", Q_NULLPTR));
        label_9->setText(QApplication::translate("PaymentDetailDlg", "\345\205\261 ", Q_NULLPTR));
        totalPayDetailsLabel->setText(QApplication::translate("PaymentDetailDlg", "0", Q_NULLPTR));
        label_7->setText(QApplication::translate("PaymentDetailDlg", " \347\254\224", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PaymentDetailDlg: public Ui_PaymentDetailDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTDETAILDLG_H
