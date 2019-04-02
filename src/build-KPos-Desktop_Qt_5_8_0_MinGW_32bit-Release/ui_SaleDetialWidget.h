/********************************************************************************
** Form generated from reading UI file 'SaleDetialWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEDETIALWIDGET_H
#define UI_SALEDETIALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleWithReturnWidget.h"
#include "receiptdetialwidget.h"
#include "receiptlistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SaleDetialWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    ReceiptListWidget *receiptListPage;
    ReceiptDetialWidget *receiptDetialPage;

    void setupUi(QWidget *SaleDetialWidget)
    {
        if (SaleDetialWidget->objectName().isEmpty())
            SaleDetialWidget->setObjectName(QStringLiteral("SaleDetialWidget"));
        SaleDetialWidget->resize(800, 600);
        SaleDetialWidget->setSizeIncrement(QSize(40, 30));
        SaleDetialWidget->setBaseSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(SaleDetialWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(SaleDetialWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 52));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));
        titleWidget->setSizeIncrement(QSize(80, 5));
        titleWidget->setBaseSize(QSize(800, 52));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(SaleDetialWidget);
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
        receiptListPage = new ReceiptListWidget();
        receiptListPage->setObjectName(QStringLiteral("receiptListPage"));
        stackedWidget->addWidget(receiptListPage);
        receiptDetialPage = new ReceiptDetialWidget();
        receiptDetialPage->setObjectName(QStringLiteral("receiptDetialPage"));
        stackedWidget->addWidget(receiptDetialPage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 52);
        verticalLayout->setStretch(1, 548);

        retranslateUi(SaleDetialWidget);

        QMetaObject::connectSlotsByName(SaleDetialWidget);
    } // setupUi

    void retranslateUi(QWidget *SaleDetialWidget)
    {
        SaleDetialWidget->setWindowTitle(QApplication::translate("SaleDetialWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SaleDetialWidget: public Ui_SaleDetialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEDETIALWIDGET_H
