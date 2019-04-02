/********************************************************************************
** Form generated from reading UI file 'CheckOrderWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKORDERWIDGET_H
#define UI_CHECKORDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CheckOrderCategoryDetailWidget.h"
#include "CheckOrderCategoryWidget.h"
#include "TitleWithReturnWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CheckOrderWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_2;
    CheckOrderCategoryWidget *categoryWidget;
    CheckOrderCategoryDetailWidget *categoryDetailWidget;

    void setupUi(QWidget *CheckOrderWidget)
    {
        if (CheckOrderWidget->objectName().isEmpty())
            CheckOrderWidget->setObjectName(QStringLiteral("CheckOrderWidget"));
        CheckOrderWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(CheckOrderWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(CheckOrderWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 50));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(CheckOrderWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(mainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(18, 0, 18, 26);
        categoryWidget = new CheckOrderCategoryWidget(mainWidget);
        categoryWidget->setObjectName(QStringLiteral("categoryWidget"));
        categoryWidget->setMinimumSize(QSize(0, 92));
        categoryWidget->setMaximumSize(QSize(16777215, 92));

        verticalLayout_2->addWidget(categoryWidget);

        categoryDetailWidget = new CheckOrderCategoryDetailWidget(mainWidget);
        categoryDetailWidget->setObjectName(QStringLiteral("categoryDetailWidget"));

        verticalLayout_2->addWidget(categoryDetailWidget);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 50);
        verticalLayout->setStretch(1, 550);

        retranslateUi(CheckOrderWidget);

        QMetaObject::connectSlotsByName(CheckOrderWidget);
    } // setupUi

    void retranslateUi(QWidget *CheckOrderWidget)
    {
        CheckOrderWidget->setWindowTitle(QApplication::translate("CheckOrderWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CheckOrderWidget: public Ui_CheckOrderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKORDERWIDGET_H
