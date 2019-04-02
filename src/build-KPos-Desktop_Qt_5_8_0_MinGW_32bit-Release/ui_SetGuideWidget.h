/********************************************************************************
** Form generated from reading UI file 'SetGuideWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETGUIDEWIDGET_H
#define UI_SETGUIDEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "setbaseguidewidget.h"
#include "setbuttonguidewidget.h"
#include "setdeviceguidewidget.h"
#include "setgoodsguidewidget.h"
#include "sethomeguidepage.h"
#include "setparamguidewidget.h"
#include "setpaymentguidewidget.h"

QT_BEGIN_NAMESPACE

class Ui_SetGuideWidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    SetHomeGuidePage *setHomeGuidePage;
    SetBaseGuideWidget *setBaseGuidePage;
    SetButtonGuideWidget *setButtonGuidePage;
    SetGoodsGuideWidget *setGoodsGuidePage;
    SetDeviceGuideWidget *setDeviceGuidePage;
    SetPaymentGuideWidget *setPaymentGuidePage;
    SetParamGuideWidget *setParamGuidePage;

    void setupUi(QWidget *SetGuideWidget)
    {
        if (SetGuideWidget->objectName().isEmpty())
            SetGuideWidget->setObjectName(QStringLiteral("SetGuideWidget"));
        SetGuideWidget->resize(800, 600);
        SetGuideWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(SetGuideWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(SetGuideWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        setHomeGuidePage = new SetHomeGuidePage();
        setHomeGuidePage->setObjectName(QStringLiteral("setHomeGuidePage"));
        stackedWidget->addWidget(setHomeGuidePage);
        setBaseGuidePage = new SetBaseGuideWidget();
        setBaseGuidePage->setObjectName(QStringLiteral("setBaseGuidePage"));
        stackedWidget->addWidget(setBaseGuidePage);
        setButtonGuidePage = new SetButtonGuideWidget();
        setButtonGuidePage->setObjectName(QStringLiteral("setButtonGuidePage"));
        stackedWidget->addWidget(setButtonGuidePage);
        setGoodsGuidePage = new SetGoodsGuideWidget();
        setGoodsGuidePage->setObjectName(QStringLiteral("setGoodsGuidePage"));
        stackedWidget->addWidget(setGoodsGuidePage);
        setDeviceGuidePage = new SetDeviceGuideWidget();
        setDeviceGuidePage->setObjectName(QStringLiteral("setDeviceGuidePage"));
        stackedWidget->addWidget(setDeviceGuidePage);
        setPaymentGuidePage = new SetPaymentGuideWidget();
        setPaymentGuidePage->setObjectName(QStringLiteral("setPaymentGuidePage"));
        stackedWidget->addWidget(setPaymentGuidePage);
        setParamGuidePage = new SetParamGuideWidget();
        setParamGuidePage->setObjectName(QStringLiteral("setParamGuidePage"));
        stackedWidget->addWidget(setParamGuidePage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(SetGuideWidget);

        QMetaObject::connectSlotsByName(SetGuideWidget);
    } // setupUi

    void retranslateUi(QWidget *SetGuideWidget)
    {
        SetGuideWidget->setWindowTitle(QApplication::translate("SetGuideWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetGuideWidget: public Ui_SetGuideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETGUIDEWIDGET_H
