/********************************************************************************
** Form generated from reading UI file 'OrderCategorySmallWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERCATEGORYSMALLWIDGET_H
#define UI_ORDERCATEGORYSMALLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "OrderCategorySmallListView.h"

QT_BEGIN_NAMESPACE

class Ui_OrderCategorySmallWidget
{
public:
    QVBoxLayout *verticalLayout;
    OrderCategorySmallListView *listView;
    QPushButton *nextPageButton;

    void setupUi(QWidget *OrderCategorySmallWidget)
    {
        if (OrderCategorySmallWidget->objectName().isEmpty())
            OrderCategorySmallWidget->setObjectName(QStringLiteral("OrderCategorySmallWidget"));
        OrderCategorySmallWidget->resize(102, 474);
        verticalLayout = new QVBoxLayout(OrderCategorySmallWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new OrderCategorySmallListView(OrderCategorySmallWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"background-color: rgb(81, 80, 80);\n"
"}"));

        verticalLayout->addWidget(listView);

        nextPageButton = new QPushButton(OrderCategorySmallWidget);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(0, 36));
        nextPageButton->setMaximumSize(QSize(16777215, 36));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/orderGoodsImage/changePage.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/orderGoodsImage/changePage_press.png);\n"
"}"));

        verticalLayout->addWidget(nextPageButton);


        retranslateUi(OrderCategorySmallWidget);

        QMetaObject::connectSlotsByName(OrderCategorySmallWidget);
    } // setupUi

    void retranslateUi(QWidget *OrderCategorySmallWidget)
    {
        OrderCategorySmallWidget->setWindowTitle(QApplication::translate("OrderCategorySmallWidget", "Form", Q_NULLPTR));
        nextPageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OrderCategorySmallWidget: public Ui_OrderCategorySmallWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERCATEGORYSMALLWIDGET_H
