/********************************************************************************
** Form generated from reading UI file 'OutStockWid.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTSTOCKWID_H
#define UI_OUTSTOCKWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../OutStock/OEditView.h"
#include "../OutStock/OInquire.h"
#include "../OutStock/OMainView.h"
#include "TitleWithReturnWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OutStockWid
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    OMainView *mainPage;
    OEditView *editPage;
    OInquire *inquirePage;

    void setupUi(QWidget *OutStockWid)
    {
        if (OutStockWid->objectName().isEmpty())
            OutStockWid->setObjectName(QStringLiteral("OutStockWid"));
        OutStockWid->resize(800, 600);
        verticalLayout = new QVBoxLayout(OutStockWid);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(OutStockWid);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 52));
        titleWidget->setMaximumSize(QSize(16777215, 52));
        titleWidget->setSizeIncrement(QSize(80, 5));
        titleWidget->setBaseSize(QSize(800, 52));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(OutStockWid);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 20, 10);
        stackedWidget = new QStackedWidget(mainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        mainPage = new OMainView();
        mainPage->setObjectName(QStringLiteral("mainPage"));
        stackedWidget->addWidget(mainPage);
        editPage = new OEditView();
        editPage->setObjectName(QStringLiteral("editPage"));
        stackedWidget->addWidget(editPage);
        inquirePage = new OInquire();
        inquirePage->setObjectName(QStringLiteral("inquirePage"));
        stackedWidget->addWidget(inquirePage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 52);
        verticalLayout->setStretch(1, 548);

        retranslateUi(OutStockWid);

        QMetaObject::connectSlotsByName(OutStockWid);
    } // setupUi

    void retranslateUi(QWidget *OutStockWid)
    {
        OutStockWid->setWindowTitle(QApplication::translate("OutStockWid", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OutStockWid: public Ui_OutStockWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTSTOCKWID_H
