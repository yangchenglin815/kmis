/********************************************************************************
** Form generated from reading UI file 'BCSGoodsSelectWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSGOODSSELECTWIDGET_H
#define UI_BCSGOODSSELECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCSGoodsBigCategoryWidget.h"
#include "BCSGoodsSmallCategoryWidget.h"
#include "BCSGoodsWidget.h"
#include "SearchEdit.h"
#include "TitleWithReturnWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCSGoodsSelectWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    SearchEdit *searchWidget;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_2;
    BCSGoodsBigCategoryWidget *categoryBigWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    BCSGoodsSmallCategoryWidget *categorySmallWidget;
    BCSGoodsWidget *goodsWidget;

    void setupUi(QWidget *BCSGoodsSelectWidget)
    {
        if (BCSGoodsSelectWidget->objectName().isEmpty())
            BCSGoodsSelectWidget->setObjectName(QStringLiteral("BCSGoodsSelectWidget"));
        BCSGoodsSelectWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(BCSGoodsSelectWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(BCSGoodsSelectWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 50));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));
        searchWidget = new SearchEdit(titleWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));
        searchWidget->setGeometry(QRect(434, 9, 262, 32));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(BCSGoodsSelectWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(mainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(18, 0, 18, 26);
        categoryBigWidget = new BCSGoodsBigCategoryWidget(mainWidget);
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
        categorySmallWidget = new BCSGoodsSmallCategoryWidget(widget_2);
        categorySmallWidget->setObjectName(QStringLiteral("categorySmallWidget"));

        horizontalLayout->addWidget(categorySmallWidget);

        goodsWidget = new BCSGoodsWidget(widget_2);
        goodsWidget->setObjectName(QStringLiteral("goodsWidget"));
        goodsWidget->setMinimumSize(QSize(662, 0));
        goodsWidget->setMaximumSize(QSize(662, 16777215));

        horizontalLayout->addWidget(goodsWidget);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 50);
        verticalLayout->setStretch(1, 550);

        retranslateUi(BCSGoodsSelectWidget);

        QMetaObject::connectSlotsByName(BCSGoodsSelectWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSGoodsSelectWidget)
    {
        BCSGoodsSelectWidget->setWindowTitle(QApplication::translate("BCSGoodsSelectWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSGoodsSelectWidget: public Ui_BCSGoodsSelectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSGOODSSELECTWIDGET_H
