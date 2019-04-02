/********************************************************************************
** Form generated from reading UI file 'CreateDeliveryOrderDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDELIVERYORDERDLG_H
#define UI_CREATEDELIVERYORDERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ReceiveGoodsForCreateWidget.h"
#include "ReceiveProviderForCreateWidget.h"
#include "TitleBarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CreateDeliveryOrderDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *skinWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    ReceiveProviderForCreateWidget *providerPage;
    ReceiveGoodsForCreateWidget *goodsPage;

    void setupUi(QDialog *CreateDeliveryOrderDlg)
    {
        if (CreateDeliveryOrderDlg->objectName().isEmpty())
            CreateDeliveryOrderDlg->setObjectName(QStringLiteral("CreateDeliveryOrderDlg"));
        CreateDeliveryOrderDlg->resize(573, 563);
        verticalLayout = new QVBoxLayout(CreateDeliveryOrderDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(CreateDeliveryOrderDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 42));
        titleWidget->setMaximumSize(QSize(16777215, 42));

        verticalLayout->addWidget(titleWidget);

        skinWidget = new QWidget(CreateDeliveryOrderDlg);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        horizontalLayout = new QHBoxLayout(skinWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(22, 16, 22, 12);
        stackedWidget = new QStackedWidget(skinWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        providerPage = new ReceiveProviderForCreateWidget();
        providerPage->setObjectName(QStringLiteral("providerPage"));
        stackedWidget->addWidget(providerPage);
        goodsPage = new ReceiveGoodsForCreateWidget();
        goodsPage->setObjectName(QStringLiteral("goodsPage"));
        stackedWidget->addWidget(goodsPage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(CreateDeliveryOrderDlg);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CreateDeliveryOrderDlg);
    } // setupUi

    void retranslateUi(QDialog *CreateDeliveryOrderDlg)
    {
        CreateDeliveryOrderDlg->setWindowTitle(QApplication::translate("CreateDeliveryOrderDlg", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateDeliveryOrderDlg: public Ui_CreateDeliveryOrderDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDELIVERYORDERDLG_H
