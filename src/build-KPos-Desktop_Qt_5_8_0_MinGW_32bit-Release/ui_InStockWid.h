/********************************************************************************
** Form generated from reading UI file 'InStockWid.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTOCKWID_H
#define UI_INSTOCKWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../InStock/EditView.h"
#include "../InStock/Inquire.h"
#include "../InStock/MainView.h"
#include "TitleWithReturnWidget.h"

QT_BEGIN_NAMESPACE

class Ui_InStockWid
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    MainView *mainPage;
    EditView *editPage;
    Inquire *inquirePage;

    void setupUi(QWidget *InStockWid)
    {
        if (InStockWid->objectName().isEmpty())
            InStockWid->setObjectName(QStringLiteral("InStockWid"));
        InStockWid->resize(800, 600);
        InStockWid->setSizeIncrement(QSize(40, 30));
        InStockWid->setBaseSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(InStockWid);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(InStockWid);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 52));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));
        titleWidget->setSizeIncrement(QSize(80, 5));
        titleWidget->setBaseSize(QSize(800, 52));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(InStockWid);
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
        mainPage = new MainView();
        mainPage->setObjectName(QStringLiteral("mainPage"));
        stackedWidget->addWidget(mainPage);
        editPage = new EditView();
        editPage->setObjectName(QStringLiteral("editPage"));
        stackedWidget->addWidget(editPage);
        inquirePage = new Inquire();
        inquirePage->setObjectName(QStringLiteral("inquirePage"));
        stackedWidget->addWidget(inquirePage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 52);
        verticalLayout->setStretch(1, 548);

        retranslateUi(InStockWid);

        QMetaObject::connectSlotsByName(InStockWid);
    } // setupUi

    void retranslateUi(QWidget *InStockWid)
    {
        InStockWid->setWindowTitle(QApplication::translate("InStockWid", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InStockWid: public Ui_InStockWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTOCKWID_H
