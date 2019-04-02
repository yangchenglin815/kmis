/********************************************************************************
** Form generated from reading UI file 'CustomerSaleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERSALEWIDGET_H
#define UI_CUSTOMERSALEWIDGET_H

#include <GoodsSellListView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GoodsSellListTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CustomerSaleWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    GoodsSellListTitleWidget *widget;
    GoodsSellListView *listView;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *totalValueLabel;

    void setupUi(QWidget *CustomerSaleWidget)
    {
        if (CustomerSaleWidget->objectName().isEmpty())
            CustomerSaleWidget->setObjectName(QStringLiteral("CustomerSaleWidget"));
        CustomerSaleWidget->resize(292, 600);
        CustomerSaleWidget->setMinimumSize(QSize(292, 600));
        CustomerSaleWidget->setStyleSheet(QLatin1String("QWidget#CustomerSaleWidget {\n"
"	\n"
"}\n"
"background-color: rgb(250, 250, 250);"));
        verticalLayout = new QVBoxLayout(CustomerSaleWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(CustomerSaleWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(292, 42));
        label->setStyleSheet(QString::fromUtf8("QLabel#label {\n"
"	font: 16px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        widget = new GoodsSellListTitleWidget(CustomerSaleWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(292, 38));

        verticalLayout->addWidget(widget);

        listView = new GoodsSellListView(CustomerSaleWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(292, 443));
        listView->setStyleSheet(QLatin1String("QListView#listView {\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        widget_2 = new QWidget(CustomerSaleWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(291, 77));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 14, 0);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 77));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2 {\n"
"	font:14px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        horizontalLayout->addWidget(label_2);

        totalValueLabel = new QLabel(widget_2);
        totalValueLabel->setObjectName(QStringLiteral("totalValueLabel"));
        totalValueLabel->setMinimumSize(QSize(0, 77));
        totalValueLabel->setStyleSheet(QString::fromUtf8("QLabel#totalValueLabel {\n"
"	font:30px;\n"
"	font:bold;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(251, 153, 110);\n"
"}"));
        totalValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(totalValueLabel);


        verticalLayout->addWidget(widget_2);


        retranslateUi(CustomerSaleWidget);

        QMetaObject::connectSlotsByName(CustomerSaleWidget);
    } // setupUi

    void retranslateUi(QWidget *CustomerSaleWidget)
    {
        CustomerSaleWidget->setWindowTitle(QApplication::translate("CustomerSaleWidget", "CustomerSaleWidget", Q_NULLPTR));
        label->setText(QApplication::translate("CustomerSaleWidget", "\345\225\206\345\223\201\345\210\227\350\241\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("CustomerSaleWidget", "\345\220\210\350\256\241\357\274\232", Q_NULLPTR));
        totalValueLabel->setText(QApplication::translate("CustomerSaleWidget", "\357\277\245499990.00", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CustomerSaleWidget: public Ui_CustomerSaleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERSALEWIDGET_H
