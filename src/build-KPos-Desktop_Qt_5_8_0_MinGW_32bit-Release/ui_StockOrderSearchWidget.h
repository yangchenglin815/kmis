/********************************************************************************
** Form generated from reading UI file 'StockOrderSearchWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKORDERSEARCHWIDGET_H
#define UI_STOCKORDERSEARCHWIDGET_H

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
#include "SearchEdit.h"
#include "StockOrderSearchListView.h"
#include "StockOrderSearchTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_StockOrderSearchWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    SearchEdit *searchWidget;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_2;
    StockOrderSearchTitleWidget *titleWidget;
    StockOrderSearchListView *listView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *leftWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *lastPageButton;
    QWidget *widget_6;
    QPushButton *nextPageButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *pageLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QLabel *totalDifferPriceLabel;

    void setupUi(QWidget *StockOrderSearchWidget)
    {
        if (StockOrderSearchWidget->objectName().isEmpty())
            StockOrderSearchWidget->setObjectName(QStringLiteral("StockOrderSearchWidget"));
        StockOrderSearchWidget->resize(766, 523);
        verticalLayout = new QVBoxLayout(StockOrderSearchWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(StockOrderSearchWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 62));
        topWidget->setMaximumSize(QSize(16777215, 62));
        horizontalLayout = new QHBoxLayout(topWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(215, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchWidget = new SearchEdit(topWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));
        searchWidget->setMinimumSize(QSize(262, 32));
        searchWidget->setMaximumSize(QSize(262, 32));

        horizontalLayout->addWidget(searchWidget);


        verticalLayout->addWidget(topWidget);

        mainWidget = new QWidget(StockOrderSearchWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        verticalLayout_2 = new QVBoxLayout(mainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWidget = new StockOrderSearchTitleWidget(mainWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(titleWidget);

        listView = new StockOrderSearchListView(mainWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"}"));

        verticalLayout_2->addWidget(listView);

        bottomWidget = new QWidget(mainWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 70));
        bottomWidget->setMaximumSize(QSize(16777215, 70));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(bottomWidget);
        horizontalLayout_3->setSpacing(16);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 25, 54, 20);
        leftWidget = new QWidget(bottomWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(200, 0));
        leftWidget->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_4 = new QHBoxLayout(leftWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        widget_5 = new QWidget(leftWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        lastPageButton = new QPushButton(widget_5);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(87, 31));
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

        horizontalLayout_5->addWidget(lastPageButton);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(1, 18));
        widget_6->setMaximumSize(QSize(1, 18));
        widget_6->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout_5->addWidget(widget_6);

        nextPageButton = new QPushButton(widget_5);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(87, 31));
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

        horizontalLayout_5->addWidget(nextPageButton);


        horizontalLayout_4->addWidget(widget_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pageLabel = new QLabel(leftWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));

        horizontalLayout_4->addWidget(pageLabel);


        horizontalLayout_3->addWidget(leftWidget);

        widget = new QWidget(bottomWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(282, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:16px;\n"
"color:#999999;"));

        horizontalLayout_2->addWidget(label);

        totalDifferPriceLabel = new QLabel(widget);
        totalDifferPriceLabel->setObjectName(QStringLiteral("totalDifferPriceLabel"));
        totalDifferPriceLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:20px;\n"
"font-weight:bold;\n"
"color:#ea8852;\n"
"\n"
""));

        horizontalLayout_2->addWidget(totalDifferPriceLabel);


        horizontalLayout_3->addWidget(widget);


        verticalLayout_2->addWidget(bottomWidget);


        verticalLayout->addWidget(mainWidget);


        retranslateUi(StockOrderSearchWidget);

        QMetaObject::connectSlotsByName(StockOrderSearchWidget);
    } // setupUi

    void retranslateUi(QWidget *StockOrderSearchWidget)
    {
        StockOrderSearchWidget->setWindowTitle(QApplication::translate("StockOrderSearchWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("StockOrderSearchWidget", "1/1\351\241\265", Q_NULLPTR));
        label->setText(QApplication::translate("StockOrderSearchWidget", "\346\200\273\350\277\233\344\273\267\345\267\256\345\274\202\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        totalDifferPriceLabel->setText(QApplication::translate("StockOrderSearchWidget", "\357\277\24510000.00", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StockOrderSearchWidget: public Ui_StockOrderSearchWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKORDERSEARCHWIDGET_H
