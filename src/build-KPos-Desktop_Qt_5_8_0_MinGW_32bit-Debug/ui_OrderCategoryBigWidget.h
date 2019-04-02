/********************************************************************************
** Form generated from reading UI file 'OrderCategoryBigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERCATEGORYBIGWIDGET_H
#define UI_ORDERCATEGORYBIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "OrderCategoryBigListView.h"

QT_BEGIN_NAMESPACE

class Ui_OrderCategoryBigWidget
{
public:
    QHBoxLayout *horizontalLayout;
    OrderCategoryBigListView *listView;
    QPushButton *nextPageButton;

    void setupUi(QWidget *OrderCategoryBigWidget)
    {
        if (OrderCategoryBigWidget->objectName().isEmpty())
            OrderCategoryBigWidget->setObjectName(QStringLiteral("OrderCategoryBigWidget"));
        OrderCategoryBigWidget->resize(605, 69);
        horizontalLayout = new QHBoxLayout(OrderCategoryBigWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new OrderCategoryBigListView(OrderCategoryBigWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(0, 0));
        listView->setMaximumSize(QSize(16777215, 16777215));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"background-color: rgb(81, 80, 80);\n"
"}"));

        horizontalLayout->addWidget(listView);

        nextPageButton = new QPushButton(OrderCategoryBigWidget);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(15, 18));
        nextPageButton->setMaximumSize(QSize(15, 18));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/setImage/right.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/setImage/right_press.png);\n"
"}\n"
""));

        horizontalLayout->addWidget(nextPageButton);


        retranslateUi(OrderCategoryBigWidget);

        QMetaObject::connectSlotsByName(OrderCategoryBigWidget);
    } // setupUi

    void retranslateUi(QWidget *OrderCategoryBigWidget)
    {
        OrderCategoryBigWidget->setWindowTitle(QApplication::translate("OrderCategoryBigWidget", "Form", Q_NULLPTR));
        nextPageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OrderCategoryBigWidget: public Ui_OrderCategoryBigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERCATEGORYBIGWIDGET_H
