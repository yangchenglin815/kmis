/********************************************************************************
** Form generated from reading UI file 'SummaryChartsLeftWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMMARYCHARTSLEFTWIDGET_H
#define UI_SUMMARYCHARTSLEFTWIDGET_H

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
#include "SummaryChartsLeftListView.h"
#include "SummaryChartsLeftTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SummaryChartsLeftWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
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
    SummaryChartsLeftTitleWidget *titleWidget;
    SummaryChartsLeftListView *listView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *saleSumMoneyLabel;
    QLabel *peopleSumNumberLabel;

    void setupUi(QWidget *SummaryChartsLeftWidget)
    {
        if (SummaryChartsLeftWidget->objectName().isEmpty())
            SummaryChartsLeftWidget->setObjectName(QStringLiteral("SummaryChartsLeftWidget"));
        SummaryChartsLeftWidget->resize(376, 495);
        verticalLayout = new QVBoxLayout(SummaryChartsLeftWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(SummaryChartsLeftWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 44));
        topWidget->setMaximumSize(QSize(16777215, 44));
        topWidget->setStyleSheet(QLatin1String("QWidget#topWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout = new QHBoxLayout(topWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 15, 0);
        label = new QLabel(topWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:16px;\n"
"color:#333333;"));

        horizontalLayout->addWidget(label);

        leftWidget = new QWidget(topWidget);
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


        verticalLayout->addWidget(topWidget);

        titleWidget = new SummaryChartsLeftTitleWidget(SummaryChartsLeftWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(titleWidget);

        listView = new SummaryChartsLeftListView(SummaryChartsLeftWidget);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        bottomWidget = new QWidget(SummaryChartsLeftWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 30));
        bottomWidget->setMaximumSize(QSize(16777215, 30));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(bottomWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(20, 0, 0, 0);
        label_2 = new QLabel(bottomWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;"));

        horizontalLayout_4->addWidget(label_2);

        saleSumMoneyLabel = new QLabel(bottomWidget);
        saleSumMoneyLabel->setObjectName(QStringLiteral("saleSumMoneyLabel"));
        saleSumMoneyLabel->setMinimumSize(QSize(113, 0));
        saleSumMoneyLabel->setMaximumSize(QSize(113, 16777215));
        saleSumMoneyLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#ea8852;"));
        saleSumMoneyLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(saleSumMoneyLabel);

        peopleSumNumberLabel = new QLabel(bottomWidget);
        peopleSumNumberLabel->setObjectName(QStringLiteral("peopleSumNumberLabel"));
        peopleSumNumberLabel->setMinimumSize(QSize(127, 0));
        peopleSumNumberLabel->setMaximumSize(QSize(127, 16777215));
        peopleSumNumberLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#ea8852;"));
        peopleSumNumberLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(peopleSumNumberLabel);


        verticalLayout->addWidget(bottomWidget);


        retranslateUi(SummaryChartsLeftWidget);

        QMetaObject::connectSlotsByName(SummaryChartsLeftWidget);
    } // setupUi

    void retranslateUi(QWidget *SummaryChartsLeftWidget)
    {
        SummaryChartsLeftWidget->setWindowTitle(QApplication::translate("SummaryChartsLeftWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SummaryChartsLeftWidget", "\345\256\236\346\227\266\351\224\200\345\224\256\346\261\207\346\200\273", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("SummaryChartsLeftWidget", "1/1\351\241\265", Q_NULLPTR));
        label_2->setText(QApplication::translate("SummaryChartsLeftWidget", "\345\220\210\350\256\241", Q_NULLPTR));
        saleSumMoneyLabel->setText(QApplication::translate("SummaryChartsLeftWidget", "10000000.11", Q_NULLPTR));
        peopleSumNumberLabel->setText(QApplication::translate("SummaryChartsLeftWidget", "10000", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SummaryChartsLeftWidget: public Ui_SummaryChartsLeftWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMMARYCHARTSLEFTWIDGET_H
