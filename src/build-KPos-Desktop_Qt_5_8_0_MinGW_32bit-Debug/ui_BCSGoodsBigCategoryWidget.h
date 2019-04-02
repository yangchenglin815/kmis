/********************************************************************************
** Form generated from reading UI file 'BCSGoodsBigCategoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSGOODSBIGCATEGORYWIDGET_H
#define UI_BCSGOODSBIGCATEGORYWIDGET_H

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

class Ui_BCSGoodsBigCategoryWidget
{
public:
    QHBoxLayout *horizontalLayout;
    OrderCategoryBigListView *listView;
    QWidget *widget_2;
    QPushButton *lastPageButton;
    QWidget *widget;
    QPushButton *nextPageButton;

    void setupUi(QWidget *BCSGoodsBigCategoryWidget)
    {
        if (BCSGoodsBigCategoryWidget->objectName().isEmpty())
            BCSGoodsBigCategoryWidget->setObjectName(QStringLiteral("BCSGoodsBigCategoryWidget"));
        BCSGoodsBigCategoryWidget->resize(764, 50);
        horizontalLayout = new QHBoxLayout(BCSGoodsBigCategoryWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new OrderCategoryBigListView(BCSGoodsBigCategoryWidget);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);
        listView->setMinimumSize(QSize(0, 0));
        listView->setMaximumSize(QSize(16777215, 16777215));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"	background-color: rgb(81, 80, 80);\n"
"}"));

        horizontalLayout->addWidget(listView);

        widget_2 = new QWidget(BCSGoodsBigCategoryWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(77, 0));
        widget_2->setMaximumSize(QSize(77, 16777215));
        lastPageButton = new QPushButton(widget_2);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setGeometry(QRect(9, 16, 15, 18));
        lastPageButton->setMinimumSize(QSize(15, 18));
        lastPageButton->setMaximumSize(QSize(15, 18));
        lastPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/setImage/left.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/setImage/left_press.png);\n"
"}"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(38, 16, 1, 18));
        widget->setMinimumSize(QSize(1, 18));
        widget->setMaximumSize(QSize(1, 18));
        widget->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));
        nextPageButton = new QPushButton(widget_2);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setGeometry(QRect(52, 16, 15, 18));
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

        horizontalLayout->addWidget(widget_2);


        retranslateUi(BCSGoodsBigCategoryWidget);

        QMetaObject::connectSlotsByName(BCSGoodsBigCategoryWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSGoodsBigCategoryWidget)
    {
        BCSGoodsBigCategoryWidget->setWindowTitle(QApplication::translate("BCSGoodsBigCategoryWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BCSGoodsBigCategoryWidget: public Ui_BCSGoodsBigCategoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSGOODSBIGCATEGORYWIDGET_H
