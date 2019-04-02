/********************************************************************************
** Form generated from reading UI file 'SummaryChartsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMMARYCHARTSWIDGET_H
#define UI_SUMMARYCHARTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "SummaryChartsLeftWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SummaryChartsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    SummaryChartsLeftWidget *summaryChartsLeftWidget;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWebView *webView;

    void setupUi(QWidget *SummaryChartsWidget)
    {
        if (SummaryChartsWidget->objectName().isEmpty())
            SummaryChartsWidget->setObjectName(QStringLiteral("SummaryChartsWidget"));
        SummaryChartsWidget->resize(760, 536);
        verticalLayout = new QVBoxLayout(SummaryChartsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SummaryChartsWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 41));
        widget->setMaximumSize(QSize(16777215, 41));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#999999;"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(122, 0));
        lineEdit->setMaximumSize(QSize(122, 16777215));
        lineEdit->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color:#999999;"));

        horizontalLayout_3->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(SummaryChartsWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        summaryChartsLeftWidget = new SummaryChartsLeftWidget(widget_2);
        summaryChartsLeftWidget->setObjectName(QStringLiteral("summaryChartsLeftWidget"));

        horizontalLayout->addWidget(summaryChartsLeftWidget);

        rightWidget = new QWidget(widget_2);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        rightWidget->setMinimumSize(QSize(376, 0));
        rightWidget->setMaximumSize(QSize(376, 16777215));
        rightWidget->setStyleSheet(QLatin1String("QWidget#rightWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(rightWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(rightWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 44));
        widget_5->setMaximumSize(QSize(16777215, 44));
        widget_5->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 0, 0);
        label = new QLabel(widget_5);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:16px;\n"
"color:#333333;"));

        horizontalLayout_2->addWidget(label);


        verticalLayout_2->addWidget(widget_5);

        webView = new QWebView(rightWidget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        verticalLayout_2->addWidget(webView);


        horizontalLayout->addWidget(rightWidget);


        verticalLayout->addWidget(widget_2);


        retranslateUi(SummaryChartsWidget);

        QMetaObject::connectSlotsByName(SummaryChartsWidget);
    } // setupUi

    void retranslateUi(QWidget *SummaryChartsWidget)
    {
        SummaryChartsWidget->setWindowTitle(QApplication::translate("SummaryChartsWidget", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("SummaryChartsWidget", "\351\224\200\345\224\256\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("SummaryChartsWidget", "\351\224\200\345\224\256\351\242\235", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SummaryChartsWidget: public Ui_SummaryChartsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMMARYCHARTSWIDGET_H
