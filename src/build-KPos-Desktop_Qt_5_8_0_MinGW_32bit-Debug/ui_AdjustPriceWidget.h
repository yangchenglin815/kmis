/********************************************************************************
** Form generated from reading UI file 'AdjustPriceWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTPRICEWIDGET_H
#define UI_ADJUSTPRICEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AdjustPriceOrderCheckWidget.h"
#include "AdjustPriceOrderSearchWidget.h"
#include "AdjustPriceOrderWidget.h"
#include "TitleWithReturnWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AdjustPriceWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    AdjustPriceOrderWidget *adjustPriceOrderPage;
    AdjustPriceOrderSearchWidget *adjustPriceOrderSearchPage;
    AdjustPriceOrderCheckWidget *adjustPriceOrderCheckPage;

    void setupUi(QWidget *AdjustPriceWidget)
    {
        if (AdjustPriceWidget->objectName().isEmpty())
            AdjustPriceWidget->setObjectName(QStringLiteral("AdjustPriceWidget"));
        AdjustPriceWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(AdjustPriceWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(AdjustPriceWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 52));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(AdjustPriceWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 20, 10);
        stackedWidget = new QStackedWidget(mainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        adjustPriceOrderPage = new AdjustPriceOrderWidget();
        adjustPriceOrderPage->setObjectName(QStringLiteral("adjustPriceOrderPage"));
        stackedWidget->addWidget(adjustPriceOrderPage);
        adjustPriceOrderSearchPage = new AdjustPriceOrderSearchWidget();
        adjustPriceOrderSearchPage->setObjectName(QStringLiteral("adjustPriceOrderSearchPage"));
        stackedWidget->addWidget(adjustPriceOrderSearchPage);
        adjustPriceOrderCheckPage = new AdjustPriceOrderCheckWidget();
        adjustPriceOrderCheckPage->setObjectName(QStringLiteral("adjustPriceOrderCheckPage"));
        stackedWidget->addWidget(adjustPriceOrderCheckPage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 52);
        verticalLayout->setStretch(1, 548);

        retranslateUi(AdjustPriceWidget);

        QMetaObject::connectSlotsByName(AdjustPriceWidget);
    } // setupUi

    void retranslateUi(QWidget *AdjustPriceWidget)
    {
        AdjustPriceWidget->setWindowTitle(QApplication::translate("AdjustPriceWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdjustPriceWidget: public Ui_AdjustPriceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTPRICEWIDGET_H
