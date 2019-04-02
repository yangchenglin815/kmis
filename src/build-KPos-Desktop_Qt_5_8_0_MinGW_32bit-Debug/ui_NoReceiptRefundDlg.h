/********************************************************************************
** Form generated from reading UI file 'NoReceiptRefundDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORECEIPTREFUNDDLG_H
#define UI_NORECEIPTREFUNDDLG_H

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

QT_BEGIN_NAMESPACE

class Ui_NoReceiptRefundDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *skinWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *refundCashLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *integralLabel;
    QLabel *integralMoneyLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *confirmButton;

    void setupUi(QDialog *NoReceiptRefundDlg)
    {
        if (NoReceiptRefundDlg->objectName().isEmpty())
            NoReceiptRefundDlg->setObjectName(QStringLiteral("NoReceiptRefundDlg"));
        NoReceiptRefundDlg->resize(374, 280);
        verticalLayout = new QVBoxLayout(NoReceiptRefundDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(NoReceiptRefundDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 46));
        titleWidget->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(titleWidget);

        skinWidget = new QWidget(NoReceiptRefundDlg);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color:#505050;\n"
"}"));
        horizontalLayout = new QHBoxLayout(skinWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(24, 24, 24, 24);
        mainWidget = new QWidget(skinWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(mainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(16, -1, 16, -1);
        label = new QLabel(mainWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 30));
        label->setMaximumSize(QSize(70, 30));
        label->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:#333333;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label);

        refundCashLabel = new QLabel(mainWidget);
        refundCashLabel->setObjectName(QStringLiteral("refundCashLabel"));
        refundCashLabel->setMinimumSize(QSize(0, 30));
        refundCashLabel->setMaximumSize(QSize(16777215, 30));
        refundCashLabel->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:#f38448;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        refundCashLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(refundCashLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(16, -1, 16, -1);
        label_4 = new QLabel(mainWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(70, 30));
        label_4->setMaximumSize(QSize(70, 30));
        label_4->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:#333333;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label_4);

        label_2 = new QLabel(mainWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setMaximumSize(QSize(16777215, 30));
        label_2->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:#333333;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(16, -1, 16, -1);
        integralLabel = new QLabel(mainWidget);
        integralLabel->setObjectName(QStringLiteral("integralLabel"));
        integralLabel->setMinimumSize(QSize(0, 30));
        integralLabel->setMaximumSize(QSize(16777215, 30));
        integralLabel->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:#333333;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_4->addWidget(integralLabel);

        integralMoneyLabel = new QLabel(mainWidget);
        integralMoneyLabel->setObjectName(QStringLiteral("integralMoneyLabel"));
        integralMoneyLabel->setMinimumSize(QSize(0, 30));
        integralMoneyLabel->setMaximumSize(QSize(16777215, 30));
        integralMoneyLabel->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:#f38448;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        integralMoneyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(integralMoneyLabel);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        confirmButton = new QPushButton(mainWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setMinimumSize(QSize(0, 50));
        confirmButton->setMaximumSize(QSize(16777215, 50));
        confirmButton->setFocusPolicy(Qt::NoFocus);
        confirmButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#ffffff;\n"
"font-size:16px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));

        verticalLayout_2->addWidget(confirmButton);


        horizontalLayout->addWidget(mainWidget);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(NoReceiptRefundDlg);

        QMetaObject::connectSlotsByName(NoReceiptRefundDlg);
    } // setupUi

    void retranslateUi(QDialog *NoReceiptRefundDlg)
    {
        NoReceiptRefundDlg->setWindowTitle(QApplication::translate("NoReceiptRefundDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("NoReceiptRefundDlg", "\351\200\200\346\254\276\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        refundCashLabel->setText(QApplication::translate("NoReceiptRefundDlg", "\357\277\24527.02", Q_NULLPTR));
        label_4->setText(QApplication::translate("NoReceiptRefundDlg", "\351\200\200\346\254\276\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("NoReceiptRefundDlg", "\347\216\260\351\207\221", Q_NULLPTR));
        integralLabel->setText(QApplication::translate("NoReceiptRefundDlg", "\347\247\257\345\210\206\346\212\265\347\216\260\357\274\232", Q_NULLPTR));
        integralMoneyLabel->setText(QApplication::translate("NoReceiptRefundDlg", "\357\277\2451.00", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("NoReceiptRefundDlg", "\346\217\220\344\272\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NoReceiptRefundDlg: public Ui_NoReceiptRefundDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORECEIPTREFUNDDLG_H
