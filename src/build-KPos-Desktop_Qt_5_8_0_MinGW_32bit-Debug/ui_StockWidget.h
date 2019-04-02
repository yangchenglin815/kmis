/********************************************************************************
** Form generated from reading UI file 'StockWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWIDGET_H
#define UI_STOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "StockOrderCheckWidget.h"
#include "StockOrderSearchWidget.h"
#include "StockOrderWidget.h"
#include "TitleWithReturnWidget.h"

QT_BEGIN_NAMESPACE

class Ui_StockWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    StockOrderWidget *stockOrderPage;
    StockOrderCheckWidget *stockOrderCheckPage;
    StockOrderSearchWidget *stockOrderSearchPage;

    void setupUi(QWidget *StockWidget)
    {
        if (StockWidget->objectName().isEmpty())
            StockWidget->setObjectName(QStringLiteral("StockWidget"));
        StockWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(StockWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(StockWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 52));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));
        titleWidget->setSizeIncrement(QSize(80, 5));
        titleWidget->setBaseSize(QSize(800, 52));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(StockWidget);
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
        stockOrderPage = new StockOrderWidget();
        stockOrderPage->setObjectName(QStringLiteral("stockOrderPage"));
        stackedWidget->addWidget(stockOrderPage);
        stockOrderCheckPage = new StockOrderCheckWidget();
        stockOrderCheckPage->setObjectName(QStringLiteral("stockOrderCheckPage"));
        stackedWidget->addWidget(stockOrderCheckPage);
        stockOrderSearchPage = new StockOrderSearchWidget();
        stockOrderSearchPage->setObjectName(QStringLiteral("stockOrderSearchPage"));
        stackedWidget->addWidget(stockOrderSearchPage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 52);
        verticalLayout->setStretch(1, 548);

        retranslateUi(StockWidget);

        QMetaObject::connectSlotsByName(StockWidget);
    } // setupUi

    void retranslateUi(QWidget *StockWidget)
    {
        StockWidget->setWindowTitle(QApplication::translate("StockWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StockWidget: public Ui_StockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWIDGET_H
