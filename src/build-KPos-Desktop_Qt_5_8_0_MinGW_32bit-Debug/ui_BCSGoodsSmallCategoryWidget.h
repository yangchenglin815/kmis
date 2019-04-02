/********************************************************************************
** Form generated from reading UI file 'BCSGoodsSmallCategoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSGOODSSMALLCATEGORYWIDGET_H
#define UI_BCSGOODSSMALLCATEGORYWIDGET_H

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

class Ui_BCSGoodsSmallCategoryWidget
{
public:
    QVBoxLayout *verticalLayout;
    OrderCategorySmallListView *listView;
    QPushButton *lastPageButton;
    QPushButton *nextPageButton;

    void setupUi(QWidget *BCSGoodsSmallCategoryWidget)
    {
        if (BCSGoodsSmallCategoryWidget->objectName().isEmpty())
            BCSGoodsSmallCategoryWidget->setObjectName(QStringLiteral("BCSGoodsSmallCategoryWidget"));
        BCSGoodsSmallCategoryWidget->resize(102, 474);
        verticalLayout = new QVBoxLayout(BCSGoodsSmallCategoryWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new OrderCategorySmallListView(BCSGoodsSmallCategoryWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"background-color: rgb(81, 80, 80);\n"
"}"));

        verticalLayout->addWidget(listView);

        lastPageButton = new QPushButton(BCSGoodsSmallCategoryWidget);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(0, 36));
        lastPageButton->setMaximumSize(QSize(16777215, 36));
        lastPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/orderGoodsImage/changePageUp.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/orderGoodsImage/changePageUp_press.png);\n"
"}"));

        verticalLayout->addWidget(lastPageButton);

        nextPageButton = new QPushButton(BCSGoodsSmallCategoryWidget);
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


        retranslateUi(BCSGoodsSmallCategoryWidget);

        QMetaObject::connectSlotsByName(BCSGoodsSmallCategoryWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSGoodsSmallCategoryWidget)
    {
        BCSGoodsSmallCategoryWidget->setWindowTitle(QApplication::translate("BCSGoodsSmallCategoryWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BCSGoodsSmallCategoryWidget: public Ui_BCSGoodsSmallCategoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSGOODSSMALLCATEGORYWIDGET_H
