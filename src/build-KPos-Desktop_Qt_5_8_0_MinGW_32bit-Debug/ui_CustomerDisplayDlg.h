/********************************************************************************
** Form generated from reading UI file 'CustomerDisplayDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERDISPLAYDLG_H
#define UI_CUSTOMERDISPLAYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include "SaleAdvertWidget.h"
#include "StandbyAdvertWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CustomerDisplayDlg
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    StandbyAdvertWidget *StandbyADPage;
    SaleAdvertWidget *SaleADPage;

    void setupUi(QDialog *CustomerDisplayDlg)
    {
        if (CustomerDisplayDlg->objectName().isEmpty())
            CustomerDisplayDlg->setObjectName(QStringLiteral("CustomerDisplayDlg"));
        CustomerDisplayDlg->resize(800, 600);
        CustomerDisplayDlg->setMinimumSize(QSize(800, 60));
        horizontalLayout = new QHBoxLayout(CustomerDisplayDlg);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(CustomerDisplayDlg);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        StandbyADPage = new StandbyAdvertWidget();
        StandbyADPage->setObjectName(QStringLiteral("StandbyADPage"));
        stackedWidget->addWidget(StandbyADPage);
        SaleADPage = new SaleAdvertWidget();
        SaleADPage->setObjectName(QStringLiteral("SaleADPage"));
        stackedWidget->addWidget(SaleADPage);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(CustomerDisplayDlg);

        QMetaObject::connectSlotsByName(CustomerDisplayDlg);
    } // setupUi

    void retranslateUi(QDialog *CustomerDisplayDlg)
    {
        CustomerDisplayDlg->setWindowTitle(QApplication::translate("CustomerDisplayDlg", "CustomerDisplayDlg", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CustomerDisplayDlg: public Ui_CustomerDisplayDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERDISPLAYDLG_H
