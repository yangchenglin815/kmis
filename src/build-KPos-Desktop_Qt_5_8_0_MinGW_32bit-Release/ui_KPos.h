/********************************************************************************
** Form generated from reading UI file 'KPos.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KPOS_H
#define UI_KPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../InStock/InStockWid.h"
#include "../OutStock/OutStockWid.h"
#include "AdjustPriceWidget.h"
#include "BarCodeScaleWidget.h"
#include "HomePageWidget.h"
#include "OrderAndCheckWidget.h"
#include "ReceiveOrdersWidget.h"
#include "ReportChartsWidget.h"
#include "SaleWidget.h"
#include "SetWidget.h"
#include "StockWidget.h"
#include "goodsmanagewidget.h"
#include "passwdconfigwidget.h"
#include "reportlosswid.h"
#include "resetkeywgt.h"
#include "saledetialwidget.h"

QT_BEGIN_NAMESPACE

class Ui_KPos
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    HomePageWidget *HomePage;
    OutStockWid *outStockPage;
    InStockWid *inStockPage;
    SaleWidget *SalePage;
    SaleDetialWidget *saleDetialPage;
    ReportLossWid *reportLossPage;
    GoodsManageWidget *goodsManagePage;
    QWidget *ReportPage;
    SetWidget *SetPage;
    ReceiveOrdersWidget *receiveOrdersPage;
    StockWidget *stockPage;
    ReportChartsWidget *reportChartsPage;
    AdjustPriceWidget *adjustPricePage;
    BarCodeScaleWidget *barCodeScalePage;
    OrderAndCheckWidget *orderAndCheckPage;
    ResetKeyWgt *resetKeyPage;
    PasswdConfigWidget *accountManagePage;

    void setupUi(QMainWindow *KPos)
    {
        if (KPos->objectName().isEmpty())
            KPos->setObjectName(QStringLiteral("KPos"));
        KPos->resize(800, 600);
        centralWidget = new QWidget(KPos);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        HomePage = new HomePageWidget();
        HomePage->setObjectName(QStringLiteral("HomePage"));
        HomePage->setStyleSheet(QStringLiteral(""));
        stackedWidget->addWidget(HomePage);
        outStockPage = new OutStockWid();
        outStockPage->setObjectName(QStringLiteral("outStockPage"));
        stackedWidget->addWidget(outStockPage);
        inStockPage = new InStockWid();
        inStockPage->setObjectName(QStringLiteral("inStockPage"));
        stackedWidget->addWidget(inStockPage);
        SalePage = new SaleWidget();
        SalePage->setObjectName(QStringLiteral("SalePage"));
        stackedWidget->addWidget(SalePage);
        saleDetialPage = new SaleDetialWidget();
        saleDetialPage->setObjectName(QStringLiteral("saleDetialPage"));
        stackedWidget->addWidget(saleDetialPage);
        reportLossPage = new ReportLossWid();
        reportLossPage->setObjectName(QStringLiteral("reportLossPage"));
        stackedWidget->addWidget(reportLossPage);
        goodsManagePage = new GoodsManageWidget();
        goodsManagePage->setObjectName(QStringLiteral("goodsManagePage"));
        stackedWidget->addWidget(goodsManagePage);
        ReportPage = new QWidget();
        ReportPage->setObjectName(QStringLiteral("ReportPage"));
        stackedWidget->addWidget(ReportPage);
        SetPage = new SetWidget();
        SetPage->setObjectName(QStringLiteral("SetPage"));
        SetPage->setStyleSheet(QStringLiteral(""));
        stackedWidget->addWidget(SetPage);
        receiveOrdersPage = new ReceiveOrdersWidget();
        receiveOrdersPage->setObjectName(QStringLiteral("receiveOrdersPage"));
        stackedWidget->addWidget(receiveOrdersPage);
        stockPage = new StockWidget();
        stockPage->setObjectName(QStringLiteral("stockPage"));
        stackedWidget->addWidget(stockPage);
        reportChartsPage = new ReportChartsWidget();
        reportChartsPage->setObjectName(QStringLiteral("reportChartsPage"));
        stackedWidget->addWidget(reportChartsPage);
        adjustPricePage = new AdjustPriceWidget();
        adjustPricePage->setObjectName(QStringLiteral("adjustPricePage"));
        stackedWidget->addWidget(adjustPricePage);
        barCodeScalePage = new BarCodeScaleWidget();
        barCodeScalePage->setObjectName(QStringLiteral("barCodeScalePage"));
        stackedWidget->addWidget(barCodeScalePage);
        orderAndCheckPage = new OrderAndCheckWidget();
        orderAndCheckPage->setObjectName(QStringLiteral("orderAndCheckPage"));
        stackedWidget->addWidget(orderAndCheckPage);
        resetKeyPage = new ResetKeyWgt();
        resetKeyPage->setObjectName(QStringLiteral("resetKeyPage"));
        stackedWidget->addWidget(resetKeyPage);
        accountManagePage = new PasswdConfigWidget();
        accountManagePage->setObjectName(QStringLiteral("accountManagePage"));
        stackedWidget->addWidget(accountManagePage);

        verticalLayout_3->addWidget(stackedWidget);

        KPos->setCentralWidget(centralWidget);

        retranslateUi(KPos);

        stackedWidget->setCurrentIndex(10);


        QMetaObject::connectSlotsByName(KPos);
    } // setupUi

    void retranslateUi(QMainWindow *KPos)
    {
        KPos->setWindowTitle(QApplication::translate("KPos", "KPos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KPos: public Ui_KPos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KPOS_H
