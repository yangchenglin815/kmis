/********************************************************************************
** Form generated from reading UI file 'ReportChartsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTCHARTSWIDGET_H
#define UI_REPORTCHARTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "RankChartsWidget.h"
#include "SummaryChartsWidget.h"
#include "TitleWithReturnWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ReportChartsWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *chartsHomePage;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *summaryChartsButton;
    QPushButton *rankChartsButton;
    QSpacerItem *verticalSpacer;
    RankChartsWidget *rankChartsPage;
    SummaryChartsWidget *summaryChartsPage;

    void setupUi(QWidget *ReportChartsWidget)
    {
        if (ReportChartsWidget->objectName().isEmpty())
            ReportChartsWidget->setObjectName(QStringLiteral("ReportChartsWidget"));
        ReportChartsWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(ReportChartsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(ReportChartsWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 52));
        titleWidget->setMaximumSize(QSize(16777215, 52));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(ReportChartsWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 20, 12);
        stackedWidget = new QStackedWidget(mainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        chartsHomePage = new QWidget();
        chartsHomePage->setObjectName(QStringLiteral("chartsHomePage"));
        chartsHomePage->setStyleSheet(QLatin1String("QWidget#chartsHomePage{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(chartsHomePage);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(29, -1, 29, -1);
        widget = new QWidget(chartsHomePage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 207));
        widget->setMaximumSize(QSize(16777215, 207));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        summaryChartsButton = new QPushButton(widget);
        summaryChartsButton->setObjectName(QStringLiteral("summaryChartsButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(summaryChartsButton->sizePolicy().hasHeightForWidth());
        summaryChartsButton->setSizePolicy(sizePolicy);
        summaryChartsButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/reportChartsImage/summayCharts.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/reportChartsImage/summayCharts_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(summaryChartsButton);

        rankChartsButton = new QPushButton(widget);
        rankChartsButton->setObjectName(QStringLiteral("rankChartsButton"));
        sizePolicy.setHeightForWidth(rankChartsButton->sizePolicy().hasHeightForWidth());
        rankChartsButton->setSizePolicy(sizePolicy);
        rankChartsButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/reportChartsImage/rankCharts.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/reportChartsImage/rankCharts_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(rankChartsButton);


        verticalLayout_2->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 302, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        stackedWidget->addWidget(chartsHomePage);
        rankChartsPage = new RankChartsWidget();
        rankChartsPage->setObjectName(QStringLiteral("rankChartsPage"));
        stackedWidget->addWidget(rankChartsPage);
        summaryChartsPage = new SummaryChartsWidget();
        summaryChartsPage->setObjectName(QStringLiteral("summaryChartsPage"));
        stackedWidget->addWidget(summaryChartsPage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 52);
        verticalLayout->setStretch(1, 548);

        retranslateUi(ReportChartsWidget);

        QMetaObject::connectSlotsByName(ReportChartsWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportChartsWidget)
    {
        ReportChartsWidget->setWindowTitle(QApplication::translate("ReportChartsWidget", "Form", Q_NULLPTR));
        summaryChartsButton->setText(QString());
        rankChartsButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReportChartsWidget: public Ui_ReportChartsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTCHARTSWIDGET_H
