/********************************************************************************
** Form generated from reading UI file 'RankChartsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKCHARTSWIDGET_H
#define UI_RANKCHARTSWIDGET_H

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
#include "RankChartsLeftWidget.h"

QT_BEGIN_NAMESPACE

class Ui_RankChartsWidget
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
    RankChartsLeftWidget *rankChartsLeftWidget;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWebView *webView;

    void setupUi(QWidget *RankChartsWidget)
    {
        if (RankChartsWidget->objectName().isEmpty())
            RankChartsWidget->setObjectName(QStringLiteral("RankChartsWidget"));
        RankChartsWidget->resize(760, 536);
        verticalLayout = new QVBoxLayout(RankChartsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(RankChartsWidget);
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

        widget_2 = new QWidget(RankChartsWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rankChartsLeftWidget = new RankChartsLeftWidget(widget_2);
        rankChartsLeftWidget->setObjectName(QStringLiteral("rankChartsLeftWidget"));
        rankChartsLeftWidget->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(rankChartsLeftWidget);

        rightWidget = new QWidget(widget_2);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        rightWidget->setMinimumSize(QSize(376, 0));
        rightWidget->setMaximumSize(QSize(376, 16777215));
        rightWidget->setStyleSheet(QLatin1String("QWidget#rightWidget{\n"
"	background-color:#ffffff;\n"
"}\n"
""));
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


        retranslateUi(RankChartsWidget);

        QMetaObject::connectSlotsByName(RankChartsWidget);
    } // setupUi

    void retranslateUi(QWidget *RankChartsWidget)
    {
        RankChartsWidget->setWindowTitle(QApplication::translate("RankChartsWidget", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("RankChartsWidget", "\351\224\200\345\224\256\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("RankChartsWidget", "\345\210\206\347\261\273\351\224\200\345\224\256\345\215\240\346\257\224", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RankChartsWidget: public Ui_RankChartsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKCHARTSWIDGET_H
