/********************************************************************************
** Form generated from reading UI file 'CategoryChooseWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORYCHOOSEWIDGET_H
#define UI_CATEGORYCHOOSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CategoryChooseListView.h"
#include "KPosArrowButton.h"

QT_BEGIN_NAMESPACE

class Ui_CategoryChooseWidget
{
public:
    QVBoxLayout *verticalLayout;
    CategoryChooseListView *listView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout;
    KPosUpArrowButton *upArrowButton;
    QWidget *widget_3;
    KPosDownArrowButton *downArrowButton;

    void setupUi(QWidget *CategoryChooseWidget)
    {
        if (CategoryChooseWidget->objectName().isEmpty())
            CategoryChooseWidget->setObjectName(QStringLiteral("CategoryChooseWidget"));
        CategoryChooseWidget->resize(200, 320);
        verticalLayout = new QVBoxLayout(CategoryChooseWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new CategoryChooseListView(CategoryChooseWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QStringLiteral("border:none;"));

        verticalLayout->addWidget(listView);

        bottomWidget = new QWidget(CategoryChooseWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 36));
        bottomWidget->setMaximumSize(QSize(16777215, 36));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout = new QHBoxLayout(bottomWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 13, 0);
        upArrowButton = new KPosUpArrowButton(bottomWidget);
        upArrowButton->setObjectName(QStringLiteral("upArrowButton"));

        horizontalLayout->addWidget(upArrowButton);

        widget_3 = new QWidget(bottomWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(1, 18));
        widget_3->setMaximumSize(QSize(1, 18));
        widget_3->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout->addWidget(widget_3);

        downArrowButton = new KPosDownArrowButton(bottomWidget);
        downArrowButton->setObjectName(QStringLiteral("downArrowButton"));

        horizontalLayout->addWidget(downArrowButton);


        verticalLayout->addWidget(bottomWidget);


        retranslateUi(CategoryChooseWidget);

        QMetaObject::connectSlotsByName(CategoryChooseWidget);
    } // setupUi

    void retranslateUi(QWidget *CategoryChooseWidget)
    {
        CategoryChooseWidget->setWindowTitle(QApplication::translate("CategoryChooseWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CategoryChooseWidget: public Ui_CategoryChooseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORYCHOOSEWIDGET_H
