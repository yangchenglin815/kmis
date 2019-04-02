/********************************************************************************
** Form generated from reading UI file 'ReportLossWid.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTLOSSWID_H
#define UI_REPORTLOSSWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleWithReturnWidget.h"
#include "addreportlosswidget.h"
#include "checkdetialwidget.h"
#include "reportlosswidget.h"

QT_BEGIN_NAMESPACE

class Ui_ReportLossWid
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    ReportLossWidget *mainPage;
    AddReportLossWidget *editPage;
    CheckDetialWidget *inquirePage;

    void setupUi(QWidget *ReportLossWid)
    {
        if (ReportLossWid->objectName().isEmpty())
            ReportLossWid->setObjectName(QStringLiteral("ReportLossWid"));
        ReportLossWid->resize(800, 600);
        ReportLossWid->setSizeIncrement(QSize(40, 30));
        ReportLossWid->setBaseSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(ReportLossWid);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(ReportLossWid);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 52));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));
        titleWidget->setSizeIncrement(QSize(80, 5));
        titleWidget->setBaseSize(QSize(800, 52));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(ReportLossWid);
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
        mainPage = new ReportLossWidget();
        mainPage->setObjectName(QStringLiteral("mainPage"));
        stackedWidget->addWidget(mainPage);
        editPage = new AddReportLossWidget();
        editPage->setObjectName(QStringLiteral("editPage"));
        stackedWidget->addWidget(editPage);
        inquirePage = new CheckDetialWidget();
        inquirePage->setObjectName(QStringLiteral("inquirePage"));
        stackedWidget->addWidget(inquirePage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 52);
        verticalLayout->setStretch(1, 548);

        retranslateUi(ReportLossWid);

        QMetaObject::connectSlotsByName(ReportLossWid);
    } // setupUi

    void retranslateUi(QWidget *ReportLossWid)
    {
        ReportLossWid->setWindowTitle(QApplication::translate("ReportLossWid", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportLossWid: public Ui_ReportLossWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTLOSSWID_H
