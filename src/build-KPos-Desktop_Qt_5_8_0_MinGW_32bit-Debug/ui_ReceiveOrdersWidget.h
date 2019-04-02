/********************************************************************************
** Form generated from reading UI file 'ReceiveOrdersWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEORDERSWIDGET_H
#define UI_RECEIVEORDERSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ReceiveOrderCheckWidget.h"
#include "ReceiveOrdersMainWidget.h"
#include "ReceiveOrdersTopWidget.h"
#include "TitleWithReturnWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiveOrdersWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *receivePage;
    QVBoxLayout *verticalLayout_2;
    ReceiveOrdersTopWidget *receiveOrdersTopWidget;
    ReceiveOrdersMainWidget *receiveOrdersMainWidget;
    ReceiveOrderCheckWidget *checkPage;

    void setupUi(QWidget *ReceiveOrdersWidget)
    {
        if (ReceiveOrdersWidget->objectName().isEmpty())
            ReceiveOrdersWidget->setObjectName(QStringLiteral("ReceiveOrdersWidget"));
        ReceiveOrdersWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(ReceiveOrdersWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(ReceiveOrdersWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 52));
        titleWidget->setMaximumSize(QSize(16777215, 52));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(ReceiveOrdersWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 20, 25);
        stackedWidget = new QStackedWidget(mainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        receivePage = new QWidget();
        receivePage->setObjectName(QStringLiteral("receivePage"));
        verticalLayout_2 = new QVBoxLayout(receivePage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        receiveOrdersTopWidget = new ReceiveOrdersTopWidget(receivePage);
        receiveOrdersTopWidget->setObjectName(QStringLiteral("receiveOrdersTopWidget"));
        receiveOrdersTopWidget->setMinimumSize(QSize(0, 62));
        receiveOrdersTopWidget->setMaximumSize(QSize(16777215, 62));

        verticalLayout_2->addWidget(receiveOrdersTopWidget);

        receiveOrdersMainWidget = new ReceiveOrdersMainWidget(receivePage);
        receiveOrdersMainWidget->setObjectName(QStringLiteral("receiveOrdersMainWidget"));

        verticalLayout_2->addWidget(receiveOrdersMainWidget);

        stackedWidget->addWidget(receivePage);
        checkPage = new ReceiveOrderCheckWidget();
        checkPage->setObjectName(QStringLiteral("checkPage"));
        stackedWidget->addWidget(checkPage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(mainWidget);


        retranslateUi(ReceiveOrdersWidget);

        QMetaObject::connectSlotsByName(ReceiveOrdersWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiveOrdersWidget)
    {
        ReceiveOrdersWidget->setWindowTitle(QApplication::translate("ReceiveOrdersWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiveOrdersWidget: public Ui_ReceiveOrdersWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEORDERSWIDGET_H
