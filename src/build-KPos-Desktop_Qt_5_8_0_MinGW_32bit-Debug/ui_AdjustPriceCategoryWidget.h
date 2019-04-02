/********************************************************************************
** Form generated from reading UI file 'AdjustPriceCategoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTPRICECATEGORYWIDGET_H
#define UI_ADJUSTPRICECATEGORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "AdjustPriceCategoryListView.h"

QT_BEGIN_NAMESPACE

class Ui_AdjustPriceCategoryWidget
{
public:
    QHBoxLayout *horizontalLayout;
    AdjustPriceCategoryListView *listView;

    void setupUi(QWidget *AdjustPriceCategoryWidget)
    {
        if (AdjustPriceCategoryWidget->objectName().isEmpty())
            AdjustPriceCategoryWidget->setObjectName(QStringLiteral("AdjustPriceCategoryWidget"));
        AdjustPriceCategoryWidget->resize(406, 111);
        AdjustPriceCategoryWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(AdjustPriceCategoryWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new AdjustPriceCategoryListView(AdjustPriceCategoryWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QString::fromUtf8("QListView{\n"
"background-color: rgba(255, 255, 255, 0);/*\350\203\214\346\231\257\351\200\217\346\230\216*/\n"
"border:0px;\n"
"}\n"
""));

        horizontalLayout->addWidget(listView);


        retranslateUi(AdjustPriceCategoryWidget);

        QMetaObject::connectSlotsByName(AdjustPriceCategoryWidget);
    } // setupUi

    void retranslateUi(QWidget *AdjustPriceCategoryWidget)
    {
        AdjustPriceCategoryWidget->setWindowTitle(QApplication::translate("AdjustPriceCategoryWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdjustPriceCategoryWidget: public Ui_AdjustPriceCategoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTPRICECATEGORYWIDGET_H
