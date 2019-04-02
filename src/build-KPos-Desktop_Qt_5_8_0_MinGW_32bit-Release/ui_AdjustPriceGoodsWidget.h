/********************************************************************************
** Form generated from reading UI file 'AdjustPriceGoodsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTPRICEGOODSWIDGET_H
#define UI_ADJUSTPRICEGOODSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "AdjustPriceGoodsListView.h"

QT_BEGIN_NAMESPACE

class Ui_AdjustPriceGoodsWidget
{
public:
    QHBoxLayout *horizontalLayout;
    AdjustPriceGoodsListView *listView;

    void setupUi(QWidget *AdjustPriceGoodsWidget)
    {
        if (AdjustPriceGoodsWidget->objectName().isEmpty())
            AdjustPriceGoodsWidget->setObjectName(QStringLiteral("AdjustPriceGoodsWidget"));
        AdjustPriceGoodsWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(AdjustPriceGoodsWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new AdjustPriceGoodsListView(AdjustPriceGoodsWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QString::fromUtf8("QListView{\n"
"background-color: rgba(255, 255, 255, 0);/*\350\203\214\346\231\257\351\200\217\346\230\216*/\n"
"border:0px;\n"
"}"));

        horizontalLayout->addWidget(listView);


        retranslateUi(AdjustPriceGoodsWidget);

        QMetaObject::connectSlotsByName(AdjustPriceGoodsWidget);
    } // setupUi

    void retranslateUi(QWidget *AdjustPriceGoodsWidget)
    {
        AdjustPriceGoodsWidget->setWindowTitle(QApplication::translate("AdjustPriceGoodsWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdjustPriceGoodsWidget: public Ui_AdjustPriceGoodsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTPRICEGOODSWIDGET_H
