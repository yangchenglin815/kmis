/********************************************************************************
** Form generated from reading UI file 'ReceiptRefundDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIPTREFUNDDLG_H
#define UI_RECEIPTREFUNDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>
#include "RefundWithReceiptTitle.h"
#include "RefundWithReceiptView.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiptRefundDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *skinWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cashRefundButton;
    RefundWithReceiptTitle *widget_4;
    RefundWithReceiptView *listView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *pageLabel;
    QPushButton *lastPageButton;
    QFrame *frame;
    QPushButton *nextPageButton;
    QLabel *label_7;

    void setupUi(QDialog *ReceiptRefundDlg)
    {
        if (ReceiptRefundDlg->objectName().isEmpty())
            ReceiptRefundDlg->setObjectName(QStringLiteral("ReceiptRefundDlg"));
        ReceiptRefundDlg->resize(550, 322);
        verticalLayout = new QVBoxLayout(ReceiptRefundDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(ReceiptRefundDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 46));
        titleWidget->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(titleWidget);

        skinWidget = new QWidget(ReceiptRefundDlg);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color:#505050;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(skinWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(23, 0, 23, 0);
        widget_3 = new QWidget(skinWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 50));
        widget_3->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#ffffff;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#ffffff;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label_5);

        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#ffffff;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        cashRefundButton = new QPushButton(widget_3);
        cashRefundButton->setObjectName(QStringLiteral("cashRefundButton"));
        cashRefundButton->setMinimumSize(QSize(100, 32));
        cashRefundButton->setMaximumSize(QSize(100, 32));
        cashRefundButton->setFocusPolicy(Qt::NoFocus);
        cashRefundButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#ffffff;\n"
"font-size:12px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(cashRefundButton);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new RefundWithReceiptTitle(skinWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 38));

        verticalLayout_2->addWidget(widget_4);

        listView = new RefundWithReceiptView(skinWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(0, 0));
        listView->setMaximumSize(QSize(16777215, 16777215));
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"	background-color: #ffffff;\n"
"}\n"
""));
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_2->addWidget(listView);

        widget = new QWidget(skinWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 40));
        widget->setMaximumSize(QSize(16777215, 40));
        widget->setStyleSheet(QStringLiteral("background-color: #ffffff;;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pageLabel = new QLabel(widget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setMaximumSize(QSize(410, 16777215));

        horizontalLayout->addWidget(pageLabel);

        lastPageButton = new QPushButton(widget);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(87, 37));
        lastPageButton->setMaximumSize(QSize(87, 37));
        lastPageButton->setFocusPolicy(Qt::NoFocus);
        lastPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-image: url(:/saleImage/btn-up-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-image: url(:/saleImage/btn-up-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"background-image: url(:/saleImage/btn-up-disable.png);\n"
"}"));

        horizontalLayout->addWidget(lastPageButton);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 22));
        frame->setMaximumSize(QSize(16777215, 22));
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        nextPageButton = new QPushButton(widget);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(87, 37));
        nextPageButton->setMaximumSize(QSize(87, 37));
        nextPageButton->setFocusPolicy(Qt::NoFocus);
        nextPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-image: url(:/saleImage/btn-down-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-image: url(:/saleImage/btn-down-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"background-image: url(:/saleImage/btn-down-disabled.png);\n"
"}"));

        horizontalLayout->addWidget(nextPageButton);


        verticalLayout_2->addWidget(widget);

        label_7 = new QLabel(skinWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 34));
        label_7->setMaximumSize(QSize(16777215, 34));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_7);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(ReceiptRefundDlg);

        QMetaObject::connectSlotsByName(ReceiptRefundDlg);
    } // setupUi

    void retranslateUi(QDialog *ReceiptRefundDlg)
    {
        ReceiptRefundDlg->setWindowTitle(QApplication::translate("ReceiptRefundDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ReceiptRefundDlg", "\345\272\224\351\200\200\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReceiptRefundDlg", "\357\277\24564.00", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReceiptRefundDlg", "\345\267\262\351\200\200\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ReceiptRefundDlg", "\357\277\24532.00", Q_NULLPTR));
        label_5->setText(QApplication::translate("ReceiptRefundDlg", "\345\276\205\351\200\200\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("ReceiptRefundDlg", "\357\277\24532.00", Q_NULLPTR));
        cashRefundButton->setText(QApplication::translate("ReceiptRefundDlg", "\344\275\231\351\242\235\347\216\260\351\207\221\351\200\200\346\254\276", Q_NULLPTR));
        pageLabel->setText(QApplication::translate("ReceiptRefundDlg", "1/2\351\241\265", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        label_7->setText(QApplication::translate("ReceiptRefundDlg", "\345\205\261 2 \347\254\224", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiptRefundDlg: public Ui_ReceiptRefundDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIPTREFUNDDLG_H
