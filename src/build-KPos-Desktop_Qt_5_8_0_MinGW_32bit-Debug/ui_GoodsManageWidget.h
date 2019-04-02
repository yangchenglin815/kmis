/********************************************************************************
** Form generated from reading UI file 'GoodsManageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSMANAGEWIDGET_H
#define UI_GOODSMANAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "SearchEdit.h"
#include "TitleWithReturnWidget.h"
#include "categorybigwidget.h"
#include "categorygoodswidget.h"
#include "categorysmallwidget.h"

QT_BEGIN_NAMESPACE

class Ui_GoodsManageWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    SearchEdit *searchWidget;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_2;
    CategoryBigWidget *categoryBigWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    CategorySmallWidget *categorySmallWidget;
    CategoryGoodsWidget *orderGoodsWidget;

    void setupUi(QWidget *GoodsManageWidget)
    {
        if (GoodsManageWidget->objectName().isEmpty())
            GoodsManageWidget->setObjectName(QStringLiteral("GoodsManageWidget"));
        GoodsManageWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(GoodsManageWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(GoodsManageWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 50));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));
        searchWidget = new SearchEdit(titleWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));
        searchWidget->setGeometry(QRect(434, 9, 262, 32));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(GoodsManageWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(mainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(18, 0, 18, 26);
        categoryBigWidget = new CategoryBigWidget(mainWidget);
        categoryBigWidget->setObjectName(QStringLiteral("categoryBigWidget"));
        categoryBigWidget->setMinimumSize(QSize(0, 50));
        categoryBigWidget->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(categoryBigWidget);

        widget_2 = new QWidget(mainWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        categorySmallWidget = new CategorySmallWidget(widget_2);
        categorySmallWidget->setObjectName(QStringLiteral("categorySmallWidget"));
        categorySmallWidget->setMinimumSize(QSize(102, 0));
        categorySmallWidget->setMaximumSize(QSize(102, 16777215));

        horizontalLayout->addWidget(categorySmallWidget);

        orderGoodsWidget = new CategoryGoodsWidget(widget_2);
        orderGoodsWidget->setObjectName(QStringLiteral("orderGoodsWidget"));
        orderGoodsWidget->setMinimumSize(QSize(0, 0));
        orderGoodsWidget->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(orderGoodsWidget);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 50);
        verticalLayout->setStretch(1, 550);

        retranslateUi(GoodsManageWidget);

        QMetaObject::connectSlotsByName(GoodsManageWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodsManageWidget)
    {
        GoodsManageWidget->setWindowTitle(QApplication::translate("GoodsManageWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GoodsManageWidget: public Ui_GoodsManageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSMANAGEWIDGET_H
