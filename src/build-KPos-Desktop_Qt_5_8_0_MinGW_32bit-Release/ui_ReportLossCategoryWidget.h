/********************************************************************************
** Form generated from reading UI file 'ReportLossCategoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTLOSSCATEGORYWIDGET_H
#define UI_REPORTLOSSCATEGORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "reportlosscategorylistview.h"

QT_BEGIN_NAMESPACE

class Ui_ReportLossCategoryWidget
{
public:
    QHBoxLayout *horizontalLayout;
    ReportLossCategoryListView *listView;

    void setupUi(QWidget *ReportLossCategoryWidget)
    {
        if (ReportLossCategoryWidget->objectName().isEmpty())
            ReportLossCategoryWidget->setObjectName(QStringLiteral("ReportLossCategoryWidget"));
        ReportLossCategoryWidget->resize(412, 111);
        horizontalLayout = new QHBoxLayout(ReportLossCategoryWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new ReportLossCategoryListView(ReportLossCategoryWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QString::fromUtf8("QListView{\n"
"background-color: rgba(255, 255, 255, 0);/*\350\203\214\346\231\257\351\200\217\346\230\216*/\n"
"border:0px;\n"
"}\n"
""));

        horizontalLayout->addWidget(listView);


        retranslateUi(ReportLossCategoryWidget);

        QMetaObject::connectSlotsByName(ReportLossCategoryWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportLossCategoryWidget)
    {
        ReportLossCategoryWidget->setWindowTitle(QApplication::translate("ReportLossCategoryWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportLossCategoryWidget: public Ui_ReportLossCategoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTLOSSCATEGORYWIDGET_H
