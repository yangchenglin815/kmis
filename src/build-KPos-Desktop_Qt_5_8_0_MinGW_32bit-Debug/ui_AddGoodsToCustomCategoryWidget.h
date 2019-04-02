/********************************************************************************
** Form generated from reading UI file 'AddGoodsToCustomCategoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGOODSTOCUSTOMCATEGORYWIDGET_H
#define UI_ADDGOODSTOCUSTOMCATEGORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>
#include "CategoryChooseWidget.h"
#include "GoodsChooseWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AddGoodsToCustomCategoryWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    CategoryChooseWidget *categoryWidget;
    GoodsChooseWidget *goodsWidget;

    void setupUi(QWidget *AddGoodsToCustomCategoryWidget)
    {
        if (AddGoodsToCustomCategoryWidget->objectName().isEmpty())
            AddGoodsToCustomCategoryWidget->setObjectName(QStringLiteral("AddGoodsToCustomCategoryWidget"));
        AddGoodsToCustomCategoryWidget->resize(722, 417);
        verticalLayout = new QVBoxLayout(AddGoodsToCustomCategoryWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(AddGoodsToCustomCategoryWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 48));
        titleWidget->setMaximumSize(QSize(16777215, 48));
        titleWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(AddGoodsToCustomCategoryWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setSpacing(18);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(26, 0, 26, 0);
        categoryWidget = new CategoryChooseWidget(mainWidget);
        categoryWidget->setObjectName(QStringLiteral("categoryWidget"));
        categoryWidget->setMinimumSize(QSize(200, 320));
        categoryWidget->setMaximumSize(QSize(200, 320));

        horizontalLayout->addWidget(categoryWidget);

        goodsWidget = new GoodsChooseWidget(mainWidget);
        goodsWidget->setObjectName(QStringLiteral("goodsWidget"));
        goodsWidget->setMinimumSize(QSize(462, 320));
        goodsWidget->setMaximumSize(QSize(462, 320));

        horizontalLayout->addWidget(goodsWidget);


        verticalLayout->addWidget(mainWidget);


        retranslateUi(AddGoodsToCustomCategoryWidget);

        QMetaObject::connectSlotsByName(AddGoodsToCustomCategoryWidget);
    } // setupUi

    void retranslateUi(QWidget *AddGoodsToCustomCategoryWidget)
    {
        AddGoodsToCustomCategoryWidget->setWindowTitle(QApplication::translate("AddGoodsToCustomCategoryWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddGoodsToCustomCategoryWidget: public Ui_AddGoodsToCustomCategoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGOODSTOCUSTOMCATEGORYWIDGET_H
