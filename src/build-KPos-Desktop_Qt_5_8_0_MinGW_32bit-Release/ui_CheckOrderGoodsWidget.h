/********************************************************************************
** Form generated from reading UI file 'CheckOrderGoodsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKORDERGOODSWIDGET_H
#define UI_CHECKORDERGOODSWIDGET_H

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
#include "CheckOrderGoodsListView.h"
#include "CheckOrderGoodsSortWidget.h"
#include "CheckOrderGoodsTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CheckOrderGoodsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *sortWidget;
    QHBoxLayout *horizontalLayout;
    CheckOrderGoodsSortWidget *sortByPriceWidget;
    CheckOrderGoodsSortWidget *sortByNumWidget;
    QSpacerItem *horizontalSpacer;
    CheckOrderGoodsTitleWidget *titleWidget;
    CheckOrderGoodsListView *listView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *leftWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *lastPageButton;
    QWidget *widget_3;
    QPushButton *nextPageButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *pageLabel;
    QWidget *rightWidget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QLabel *sumPriceLabel;
    QLabel *sumNumberLabel;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *confirmButton;

    void setupUi(QWidget *CheckOrderGoodsWidget)
    {
        if (CheckOrderGoodsWidget->objectName().isEmpty())
            CheckOrderGoodsWidget->setObjectName(QStringLiteral("CheckOrderGoodsWidget"));
        CheckOrderGoodsWidget->resize(662, 494);
        verticalLayout = new QVBoxLayout(CheckOrderGoodsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sortWidget = new QWidget(CheckOrderGoodsWidget);
        sortWidget->setObjectName(QStringLiteral("sortWidget"));
        sortWidget->setMinimumSize(QSize(0, 38));
        sortWidget->setMaximumSize(QSize(16777215, 38));
        horizontalLayout = new QHBoxLayout(sortWidget);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(11, 0, 0, 0);
        sortByPriceWidget = new CheckOrderGoodsSortWidget(sortWidget);
        sortByPriceWidget->setObjectName(QStringLiteral("sortByPriceWidget"));
        sortByPriceWidget->setMinimumSize(QSize(60, 0));
        sortByPriceWidget->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(sortByPriceWidget);

        sortByNumWidget = new CheckOrderGoodsSortWidget(sortWidget);
        sortByNumWidget->setObjectName(QStringLiteral("sortByNumWidget"));
        sortByNumWidget->setMinimumSize(QSize(60, 0));
        sortByNumWidget->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(sortByNumWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(sortWidget);

        titleWidget = new CheckOrderGoodsTitleWidget(CheckOrderGoodsWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 28));
        titleWidget->setMaximumSize(QSize(16777215, 28));

        verticalLayout->addWidget(titleWidget);

        listView = new CheckOrderGoodsListView(CheckOrderGoodsWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        bottomWidget = new QWidget(CheckOrderGoodsWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 74));
        bottomWidget->setMaximumSize(QSize(16777215, 74));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(bottomWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 12, 0);
        leftWidget = new QWidget(bottomWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(200, 0));
        leftWidget->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_2 = new QHBoxLayout(leftWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

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

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pageLabel = new QLabel(leftWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));

        horizontalLayout_2->addWidget(pageLabel);


        horizontalLayout_4->addWidget(leftWidget);

        rightWidget = new QWidget(bottomWidget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        horizontalLayout_5 = new QHBoxLayout(rightWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        label = new QLabel(rightWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:#666666;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-bottom:6px;"));

        horizontalLayout_5->addWidget(label);

        sumPriceLabel = new QLabel(rightWidget);
        sumPriceLabel->setObjectName(QStringLiteral("sumPriceLabel"));
        sumPriceLabel->setStyleSheet(QString::fromUtf8("font-size:26px;\n"
"color:#f08e58;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-bottom:9px;"));

        horizontalLayout_5->addWidget(sumPriceLabel);

        sumNumberLabel = new QLabel(rightWidget);
        sumNumberLabel->setObjectName(QStringLiteral("sumNumberLabel"));
        sumNumberLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_5->addWidget(sumNumberLabel);


        horizontalLayout_4->addWidget(rightWidget);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

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


        retranslateUi(CheckOrderGoodsWidget);

        QMetaObject::connectSlotsByName(CheckOrderGoodsWidget);
    } // setupUi

    void retranslateUi(QWidget *CheckOrderGoodsWidget)
    {
        CheckOrderGoodsWidget->setWindowTitle(QApplication::translate("CheckOrderGoodsWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("CheckOrderGoodsWidget", "1/1\351\241\265", Q_NULLPTR));
        label->setText(QApplication::translate("CheckOrderGoodsWidget", "\346\200\273\350\256\241\357\274\232", Q_NULLPTR));
        sumPriceLabel->setText(QApplication::translate("CheckOrderGoodsWidget", "\357\277\2450.00", Q_NULLPTR));
        sumNumberLabel->setText(QApplication::translate("CheckOrderGoodsWidget", "\357\274\210\345\205\2610\344\273\266\357\274\211", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("CheckOrderGoodsWidget", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CheckOrderGoodsWidget: public Ui_CheckOrderGoodsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKORDERGOODSWIDGET_H
