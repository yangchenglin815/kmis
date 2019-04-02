/********************************************************************************
** Form generated from reading UI file 'ReceiveOrderGoodsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEORDERGOODSWIDGET_H
#define UI_RECEIVEORDERGOODSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ReceiveOrderGoodsListView.h"
#include "ReceiveOrderGoodsTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiveOrderGoodsWidget
{
public:
    QVBoxLayout *verticalLayout;
    ReceiveOrderGoodsTitleWidget *titleWidget;
    ReceiveOrderGoodsListView *listView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *leftWidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *lastPageButton;
    QWidget *widget_3;
    QPushButton *nextPageButton;
    QLabel *pageLabel;
    QWidget *rightWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *sumPriceLabel;
    QLabel *sumNumberLabel;
    QPushButton *confirmButton;

    void setupUi(QWidget *ReceiveOrderGoodsWidget)
    {
        if (ReceiveOrderGoodsWidget->objectName().isEmpty())
            ReceiveOrderGoodsWidget->setObjectName(QStringLiteral("ReceiveOrderGoodsWidget"));
        ReceiveOrderGoodsWidget->resize(760, 463);
        verticalLayout = new QVBoxLayout(ReceiveOrderGoodsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new ReceiveOrderGoodsTitleWidget(ReceiveOrderGoodsWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(titleWidget);

        listView = new ReceiveOrderGoodsListView(ReceiveOrderGoodsWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        bottomWidget = new QWidget(ReceiveOrderGoodsWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 74));
        bottomWidget->setMaximumSize(QSize(16777215, 74));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(bottomWidget);
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 12, 20);
        leftWidget = new QWidget(bottomWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(200, 0));
        leftWidget->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_2 = new QHBoxLayout(leftWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(leftWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lastPageButton = new QPushButton(widget_4);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(87, 37));
        lastPageButton->setMaximumSize(QSize(87, 37));
        lastPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/saleImage/btn-up-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/saleImage/btn-up-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"border-image: url(:/saleImage/btn-up-disable.png);\n"
"}"));

        horizontalLayout_3->addWidget(lastPageButton);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(1, 18));
        widget_3->setMaximumSize(QSize(1, 18));
        widget_3->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout_3->addWidget(widget_3);

        nextPageButton = new QPushButton(widget_4);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(87, 37));
        nextPageButton->setMaximumSize(QSize(87, 37));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/saleImage/btn-down-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/btn-down-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/saleImage/btn-down-disabled.png);\n"
"}"));

        horizontalLayout_3->addWidget(nextPageButton);


        horizontalLayout_2->addWidget(widget_4);

        pageLabel = new QLabel(leftWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));
        pageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(pageLabel);


        horizontalLayout_4->addWidget(leftWidget);

        rightWidget = new QWidget(bottomWidget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        horizontalLayout = new QHBoxLayout(rightWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(rightWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:#666666;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-bottom:6px;"));

        horizontalLayout->addWidget(label);

        sumPriceLabel = new QLabel(rightWidget);
        sumPriceLabel->setObjectName(QStringLiteral("sumPriceLabel"));
        sumPriceLabel->setStyleSheet(QString::fromUtf8("font-size:26px;\n"
"color:#f08e58;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-bottom:9px;"));

        horizontalLayout->addWidget(sumPriceLabel);

        sumNumberLabel = new QLabel(rightWidget);
        sumNumberLabel->setObjectName(QStringLiteral("sumNumberLabel"));
        sumNumberLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(sumNumberLabel);


        horizontalLayout_4->addWidget(rightWidget);

        confirmButton = new QPushButton(bottomWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setMinimumSize(QSize(144, 50));
        confirmButton->setMaximumSize(QSize(144, 50));
        confirmButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";	\n"
"	border-image: url(:/orderGoodsImage/orangeRect.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/orderGoodsImage/orangeRect_press.png);\n"
"}\n"
""));

        horizontalLayout_4->addWidget(confirmButton);


        verticalLayout->addWidget(bottomWidget);


        retranslateUi(ReceiveOrderGoodsWidget);

        QMetaObject::connectSlotsByName(ReceiveOrderGoodsWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiveOrderGoodsWidget)
    {
        ReceiveOrderGoodsWidget->setWindowTitle(QApplication::translate("ReceiveOrderGoodsWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("ReceiveOrderGoodsWidget", "1/1\351\241\265", Q_NULLPTR));
        label->setText(QApplication::translate("ReceiveOrderGoodsWidget", "\346\224\266\350\264\247\351\207\221\351\242\235:", Q_NULLPTR));
        sumPriceLabel->setText(QApplication::translate("ReceiveOrderGoodsWidget", "\357\277\2450.00", Q_NULLPTR));
        sumNumberLabel->setText(QString());
        confirmButton->setText(QApplication::translate("ReceiveOrderGoodsWidget", "\346\224\266\350\264\247\345\256\214\346\210\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiveOrderGoodsWidget: public Ui_ReceiveOrderGoodsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEORDERGOODSWIDGET_H
