/********************************************************************************
** Form generated from reading UI file 'BCSGoodsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSGOODSWIDGET_H
#define UI_BCSGOODSWIDGET_H

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
#include "BCSGoodsListView.h"
#include "BCSGoodsTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCSGoodsWidget
{
public:
    QVBoxLayout *verticalLayout;
    BCSGoodsTitleWidget *titleWidget;
    BCSGoodsListView *listView;
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
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *countLabel;
    QLabel *sumNumberLabel;
    QPushButton *saveButton;

    void setupUi(QWidget *BCSGoodsWidget)
    {
        if (BCSGoodsWidget->objectName().isEmpty())
            BCSGoodsWidget->setObjectName(QStringLiteral("BCSGoodsWidget"));
        BCSGoodsWidget->resize(662, 474);
        verticalLayout = new QVBoxLayout(BCSGoodsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new BCSGoodsTitleWidget(BCSGoodsWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(titleWidget);

        listView = new BCSGoodsListView(BCSGoodsWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        bottomWidget = new QWidget(BCSGoodsWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 84));
        bottomWidget->setMaximumSize(QSize(16777215, 84));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(bottomWidget);
        horizontalLayout_4->setSpacing(20);
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
"padding-bottom:3px;"));

        horizontalLayout->addWidget(label);

        countLabel = new QLabel(rightWidget);
        countLabel->setObjectName(QStringLiteral("countLabel"));
        countLabel->setStyleSheet(QString::fromUtf8("font-size:26px;\n"
"color:#f08e58;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-bottom:9px;\n"
""));

        horizontalLayout->addWidget(countLabel);

        sumNumberLabel = new QLabel(rightWidget);
        sumNumberLabel->setObjectName(QStringLiteral("sumNumberLabel"));
        sumNumberLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(sumNumberLabel);


        horizontalLayout_4->addWidget(rightWidget);

        saveButton = new QPushButton(bottomWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(144, 50));
        saveButton->setMaximumSize(QSize(144, 50));
        saveButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        horizontalLayout_4->addWidget(saveButton);


        verticalLayout->addWidget(bottomWidget);


        retranslateUi(BCSGoodsWidget);

        QMetaObject::connectSlotsByName(BCSGoodsWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSGoodsWidget)
    {
        BCSGoodsWidget->setWindowTitle(QApplication::translate("BCSGoodsWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("BCSGoodsWidget", "1/1\351\241\265", Q_NULLPTR));
        label->setText(QApplication::translate("BCSGoodsWidget", "\346\200\273\350\256\241\357\274\232", Q_NULLPTR));
        countLabel->setText(QApplication::translate("BCSGoodsWidget", "0", Q_NULLPTR));
        sumNumberLabel->setText(QApplication::translate("BCSGoodsWidget", "\357\274\210\344\270\252\357\274\211", Q_NULLPTR));
        saveButton->setText(QApplication::translate("BCSGoodsWidget", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSGoodsWidget: public Ui_BCSGoodsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSGOODSWIDGET_H
