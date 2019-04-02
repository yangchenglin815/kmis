/********************************************************************************
** Form generated from reading UI file 'OrderAndCheckWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERANDCHECKWIDGET_H
#define UI_ORDERANDCHECKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "CheckOrderWidget.h"
#include "OrderGoodsWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OrderAndCheckWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    CheckOrderWidget *checkOrderPage;
    OrderGoodsWidget *orderGoodsPage;

    void setupUi(QWidget *OrderAndCheckWidget)
    {
        if (OrderAndCheckWidget->objectName().isEmpty())
            OrderAndCheckWidget->setObjectName(QStringLiteral("OrderAndCheckWidget"));
        OrderAndCheckWidget->resize(800, 600);
        horizontalLayout = new QHBoxLayout(OrderAndCheckWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(OrderAndCheckWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        checkOrderPage = new CheckOrderWidget();
        checkOrderPage->setObjectName(QStringLiteral("checkOrderPage"));
        stackedWidget->addWidget(checkOrderPage);
        orderGoodsPage = new OrderGoodsWidget();
        orderGoodsPage->setObjectName(QStringLiteral("orderGoodsPage"));
        stackedWidget->addWidget(orderGoodsPage);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(OrderAndCheckWidget);

        QMetaObject::connectSlotsByName(OrderAndCheckWidget);
    } // setupUi

    void retranslateUi(QWidget *OrderAndCheckWidget)
    {
        OrderAndCheckWidget->setWindowTitle(QApplication::translate("OrderAndCheckWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OrderAndCheckWidget: public Ui_OrderAndCheckWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERANDCHECKWIDGET_H
