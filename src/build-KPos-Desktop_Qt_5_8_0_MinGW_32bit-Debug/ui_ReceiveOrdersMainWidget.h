/********************************************************************************
** Form generated from reading UI file 'ReceiveOrdersMainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEORDERSMAINWIDGET_H
#define UI_RECEIVEORDERSMAINWIDGET_H

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
#include "ReceiveOrdersListView.h"
#include "ReceiveOrdersTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiveOrdersMainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *allRecieveButton;
    QPushButton *noFinishReciveButton;
    QPushButton *finishedRecieveButton;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    QPushButton *createDeliveryOrderButton;
    QSpacerItem *verticalSpacer;
    ReceiveOrdersTitleWidget *titleWidget;
    ReceiveOrdersListView *listView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout;
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
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ReceiveOrdersMainWidget)
    {
        if (ReceiveOrdersMainWidget->objectName().isEmpty())
            ReceiveOrdersMainWidget->setObjectName(QStringLiteral("ReceiveOrdersMainWidget"));
        ReceiveOrdersMainWidget->resize(760, 461);
        verticalLayout = new QVBoxLayout(ReceiveOrdersMainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(ReceiveOrdersMainWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 40));
        topWidget->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_4 = new QHBoxLayout(topWidget);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(topWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(215, 0));
        widget_5->setMaximumSize(QSize(215, 16777215));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        allRecieveButton = new QPushButton(widget_5);
        allRecieveButton->setObjectName(QStringLiteral("allRecieveButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(allRecieveButton->sizePolicy().hasHeightForWidth());
        allRecieveButton->setSizePolicy(sizePolicy);
        allRecieveButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:14px;\n"
"	color:#333333;\n"
"	border-image: url(:/receivingGoodsImage/topTab_Press.png);\n"
"}"));

        horizontalLayout_5->addWidget(allRecieveButton);

        noFinishReciveButton = new QPushButton(widget_5);
        noFinishReciveButton->setObjectName(QStringLiteral("noFinishReciveButton"));
        sizePolicy.setHeightForWidth(noFinishReciveButton->sizePolicy().hasHeightForWidth());
        noFinishReciveButton->setSizePolicy(sizePolicy);
        noFinishReciveButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:14px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/receivingGoodsImage/topTab.png);\n"
"}"));

        horizontalLayout_5->addWidget(noFinishReciveButton);

        finishedRecieveButton = new QPushButton(widget_5);
        finishedRecieveButton->setObjectName(QStringLiteral("finishedRecieveButton"));
        sizePolicy.setHeightForWidth(finishedRecieveButton->sizePolicy().hasHeightForWidth());
        finishedRecieveButton->setSizePolicy(sizePolicy);
        finishedRecieveButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:14px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/receivingGoodsImage/topTab.png);\n"
"}"));

        horizontalLayout_5->addWidget(finishedRecieveButton);


        horizontalLayout_4->addWidget(widget_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        widget_6 = new QWidget(topWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        createDeliveryOrderButton = new QPushButton(widget_6);
        createDeliveryOrderButton->setObjectName(QStringLiteral("createDeliveryOrderButton"));
        createDeliveryOrderButton->setMinimumSize(QSize(150, 32));
        createDeliveryOrderButton->setMaximumSize(QSize(150, 32));
        createDeliveryOrderButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/receivingGoodsImage/createDeliveryOrder.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/receivingGoodsImage/createDeliveryOrder_press.png);\n"
"}"));

        verticalLayout_2->addWidget(createDeliveryOrderButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(widget_6);


        verticalLayout->addWidget(topWidget);

        titleWidget = new ReceiveOrdersTitleWidget(ReceiveOrdersMainWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(titleWidget);

        listView = new ReceiveOrdersListView(ReceiveOrdersMainWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        bottomWidget = new QWidget(ReceiveOrdersMainWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 74));
        bottomWidget->setMaximumSize(QSize(16777215, 74));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout = new QHBoxLayout(bottomWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
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


        horizontalLayout->addWidget(leftWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(bottomWidget);


        retranslateUi(ReceiveOrdersMainWidget);

        QMetaObject::connectSlotsByName(ReceiveOrdersMainWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiveOrdersMainWidget)
    {
        ReceiveOrdersMainWidget->setWindowTitle(QApplication::translate("ReceiveOrdersMainWidget", "Form", Q_NULLPTR));
        allRecieveButton->setText(QApplication::translate("ReceiveOrdersMainWidget", "\345\205\250\351\203\250", Q_NULLPTR));
        noFinishReciveButton->setText(QApplication::translate("ReceiveOrdersMainWidget", "\346\234\252\345\256\214\346\210\220", Q_NULLPTR));
        finishedRecieveButton->setText(QApplication::translate("ReceiveOrdersMainWidget", "\345\267\262\345\256\214\346\210\220", Q_NULLPTR));
        createDeliveryOrderButton->setText(QString());
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("ReceiveOrdersMainWidget", "1/1\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiveOrdersMainWidget: public Ui_ReceiveOrdersMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEORDERSMAINWIDGET_H
