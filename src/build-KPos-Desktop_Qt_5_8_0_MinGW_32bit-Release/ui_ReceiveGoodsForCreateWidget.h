/********************************************************************************
** Form generated from reading UI file 'ReceiveGoodsForCreateWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEGOODSFORCREATEWIDGET_H
#define UI_RECEIVEGOODSFORCREATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "GoodsSearchForCreateWidget.h"
#include "GoodsSelectForCreateWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiveGoodsForCreateWidget
{
public:
    QHBoxLayout *horizontalLayout;
    GoodsSelectForCreateWidget *goodsSelectForCreateWidget;
    QSpacerItem *horizontalSpacer;
    GoodsSearchForCreateWidget *goodsSearchForCreateWidget;

    void setupUi(QWidget *ReceiveGoodsForCreateWidget)
    {
        if (ReceiveGoodsForCreateWidget->objectName().isEmpty())
            ReceiveGoodsForCreateWidget->setObjectName(QStringLiteral("ReceiveGoodsForCreateWidget"));
        ReceiveGoodsForCreateWidget->resize(529, 493);
        horizontalLayout = new QHBoxLayout(ReceiveGoodsForCreateWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        goodsSelectForCreateWidget = new GoodsSelectForCreateWidget(ReceiveGoodsForCreateWidget);
        goodsSelectForCreateWidget->setObjectName(QStringLiteral("goodsSelectForCreateWidget"));
        goodsSelectForCreateWidget->setMinimumSize(QSize(290, 0));
        goodsSelectForCreateWidget->setMaximumSize(QSize(290, 16777215));

        horizontalLayout->addWidget(goodsSelectForCreateWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        goodsSearchForCreateWidget = new GoodsSearchForCreateWidget(ReceiveGoodsForCreateWidget);
        goodsSearchForCreateWidget->setObjectName(QStringLiteral("goodsSearchForCreateWidget"));
        goodsSearchForCreateWidget->setMinimumSize(QSize(216, 0));
        goodsSearchForCreateWidget->setMaximumSize(QSize(216, 16777215));

        horizontalLayout->addWidget(goodsSearchForCreateWidget);


        retranslateUi(ReceiveGoodsForCreateWidget);

        QMetaObject::connectSlotsByName(ReceiveGoodsForCreateWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiveGoodsForCreateWidget)
    {
        ReceiveGoodsForCreateWidget->setWindowTitle(QApplication::translate("ReceiveGoodsForCreateWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiveGoodsForCreateWidget: public Ui_ReceiveGoodsForCreateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEGOODSFORCREATEWIDGET_H
