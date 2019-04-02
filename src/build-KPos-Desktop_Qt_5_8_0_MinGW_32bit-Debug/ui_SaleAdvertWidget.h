/********************************************************************************
** Form generated from reading UI file 'SaleAdvertWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEADVERTWIDGET_H
#define UI_SALEADVERTWIDGET_H

#include <CustomerPlatformLabel.h>
#include <CustomerSaleWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "StandbyAdvertWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SaleAdvertWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QLabel *label;
    QLabel *goodsNameValueLabel;
    QWidget *widget_6;
    CustomerPlatformLabel *platformValueLabel;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QLabel *goodsPriceValueLabel;
    QLabel *label_10;
    QWidget *widget_7;
    QLabel *goodsNumValueLabel;
    QLabel *label_8;
    QWidget *widget_8;
    QLabel *goodsAmtValueLabel;
    QLabel *label_6;
    StandbyAdvertWidget *advertImageWidget;
    CustomerSaleWidget *CustomerSaleListWidget;

    void setupUi(QWidget *SaleAdvertWidget)
    {
        if (SaleAdvertWidget->objectName().isEmpty())
            SaleAdvertWidget->setObjectName(QStringLiteral("SaleAdvertWidget"));
        SaleAdvertWidget->resize(800, 600);
        horizontalLayout_3 = new QHBoxLayout(SaleAdvertWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SaleAdvertWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(508, 600));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QLatin1String("QWidget#widget_3 {\n"
"	border: 1px solid #ededed;\n"
"}"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 25, 61, 20));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102, 102, 102);\n"
""));
        goodsNameValueLabel = new QLabel(widget_3);
        goodsNameValueLabel->setObjectName(QStringLiteral("goodsNameValueLabel"));
        goodsNameValueLabel->setGeometry(QRect(40, 45, 221, 31));
        goodsNameValueLabel->setStyleSheet(QString::fromUtf8("font:18px rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));

        horizontalLayout_2->addWidget(widget_3);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setStyleSheet(QLatin1String("QWidget#widget_6 {\n"
"	border: 1px solid #ededed;\n"
"}"));
        platformValueLabel = new CustomerPlatformLabel(widget_6);
        platformValueLabel->setObjectName(QStringLiteral("platformValueLabel"));
        platformValueLabel->setGeometry(QRect(20, 37, 131, 34));
        platformValueLabel->setStyleSheet(QString::fromUtf8("/*font:18px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";*/\n"
"\n"
"color: rgb(116,163,93);\n"
""));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 18, 54, 12));
        label_4->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102, 102, 102);"));

        horizontalLayout_2->addWidget(widget_6);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QLatin1String("QWidget#widget_4 {\n"
"	border: 1px solid #ededed;\n"
"}"));
        goodsPriceValueLabel = new QLabel(widget_4);
        goodsPriceValueLabel->setObjectName(QStringLiteral("goodsPriceValueLabel"));
        goodsPriceValueLabel->setGeometry(QRect(40, 38, 111, 31));
        goodsPriceValueLabel->setStyleSheet(QString::fromUtf8("font: 30px rgb(51, 51, 51);\n"
"font:  bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_10 = new QLabel(widget_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 15, 54, 16));
        label_10->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102, 102, 102);"));

        horizontalLayout->addWidget(widget_4);

        widget_7 = new QWidget(widget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setStyleSheet(QLatin1String("QWidget#widget_7 {\n"
"	border: 1px solid #ededed;\n"
"}"));
        goodsNumValueLabel = new QLabel(widget_7);
        goodsNumValueLabel->setObjectName(QStringLiteral("goodsNumValueLabel"));
        goodsNumValueLabel->setGeometry(QRect(40, 38, 111, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        goodsNumValueLabel->setFont(font);
        goodsNumValueLabel->setStyleSheet(QString::fromUtf8("font:30px rgb(51, 51, 51);\n"
"font:  bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 15, 54, 16));
        label_8->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102, 102, 102);"));

        horizontalLayout->addWidget(widget_7);

        widget_8 = new QWidget(widget);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setStyleSheet(QLatin1String("QWidget#widget_8 {\n"
"	border: 1px solid #ededed;\n"
"}"));
        goodsAmtValueLabel = new QLabel(widget_8);
        goodsAmtValueLabel->setObjectName(QStringLiteral("goodsAmtValueLabel"));
        goodsAmtValueLabel->setGeometry(QRect(20, 38, 147, 31));
        goodsAmtValueLabel->setFont(font);
        goodsAmtValueLabel->setStyleSheet(QString::fromUtf8("font:30px;\n"
"font: bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(255,129,56);\n"
""));
        label_6 = new QLabel(widget_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 15, 54, 16));
        label_6->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102, 102, 102);"));

        horizontalLayout->addWidget(widget_8);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        advertImageWidget = new StandbyAdvertWidget(widget);
        advertImageWidget->setObjectName(QStringLiteral("advertImageWidget"));
        advertImageWidget->setMinimumSize(QSize(0, 399));

        verticalLayout->addWidget(advertImageWidget);

        verticalLayout->setStretch(0, 98);
        verticalLayout->setStretch(1, 97);
        verticalLayout->setStretch(2, 399);

        horizontalLayout_4->addLayout(verticalLayout);


        horizontalLayout_3->addWidget(widget);

        CustomerSaleListWidget = new CustomerSaleWidget(SaleAdvertWidget);
        CustomerSaleListWidget->setObjectName(QStringLiteral("CustomerSaleListWidget"));
        CustomerSaleListWidget->setMinimumSize(QSize(292, 600));
        CustomerSaleListWidget->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));

        horizontalLayout_3->addWidget(CustomerSaleListWidget);

        horizontalLayout_3->setStretch(0, 508);
        horizontalLayout_3->setStretch(1, 292);
        widget->raise();
        CustomerSaleListWidget->raise();

        retranslateUi(SaleAdvertWidget);

        QMetaObject::connectSlotsByName(SaleAdvertWidget);
    } // setupUi

    void retranslateUi(QWidget *SaleAdvertWidget)
    {
        SaleAdvertWidget->setWindowTitle(QApplication::translate("SaleAdvertWidget", "SaleAdvertWidget", Q_NULLPTR));
        label->setText(QApplication::translate("SaleAdvertWidget", "\345\225\206\345\223\201\345\220\215\347\247\260", Q_NULLPTR));
        goodsNameValueLabel->setText(QApplication::translate("SaleAdvertWidget", "\350\266\205\347\272\247\346\227\240\346\225\214\345\260\212\350\264\265\346\260\264\346\236\234\345\244\247\346\213\274\347\233\230", Q_NULLPTR));
        platformValueLabel->setText(QApplication::translate("SaleAdvertWidget", "-11.922", Q_NULLPTR));
        label_4->setText(QApplication::translate("SaleAdvertWidget", "\345\217\260\347\247\244", Q_NULLPTR));
        goodsPriceValueLabel->setText(QApplication::translate("SaleAdvertWidget", "\357\277\2455.00", Q_NULLPTR));
        label_10->setText(QApplication::translate("SaleAdvertWidget", "\345\215\225\344\273\267", Q_NULLPTR));
        goodsNumValueLabel->setText(QApplication::translate("SaleAdvertWidget", "1.126", Q_NULLPTR));
        label_8->setText(QApplication::translate("SaleAdvertWidget", "\346\225\260\351\207\217", Q_NULLPTR));
        goodsAmtValueLabel->setText(QApplication::translate("SaleAdvertWidget", "\357\277\24599.999", Q_NULLPTR));
        label_6->setText(QApplication::translate("SaleAdvertWidget", "\351\207\221\351\242\235", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SaleAdvertWidget: public Ui_SaleAdvertWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEADVERTWIDGET_H
