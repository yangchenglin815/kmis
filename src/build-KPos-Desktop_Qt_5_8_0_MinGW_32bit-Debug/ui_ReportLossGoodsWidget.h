/********************************************************************************
** Form generated from reading UI file 'ReportLossGoodsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTLOSSGOODSWIDGET_H
#define UI_REPORTLOSSGOODSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "reportlossgoodslistview.h"

QT_BEGIN_NAMESPACE

class Ui_ReportLossGoodsWidget
{
public:
    QHBoxLayout *horizontalLayout;
    ReportLossGoodsListView *listView;

    void setupUi(QWidget *ReportLossGoodsWidget)
    {
        if (ReportLossGoodsWidget->objectName().isEmpty())
            ReportLossGoodsWidget->setObjectName(QStringLiteral("ReportLossGoodsWidget"));
        ReportLossGoodsWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(ReportLossGoodsWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new ReportLossGoodsListView(ReportLossGoodsWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QString::fromUtf8("QListView{\n"
"background-color: rgba(255, 255, 255, 0);/*\350\203\214\346\231\257\351\200\217\346\230\216*/\n"
"border:0px;\n"
"}"));

        horizontalLayout->addWidget(listView);


        retranslateUi(ReportLossGoodsWidget);

        QMetaObject::connectSlotsByName(ReportLossGoodsWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportLossGoodsWidget)
    {
        ReportLossGoodsWidget->setWindowTitle(QApplication::translate("ReportLossGoodsWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportLossGoodsWidget: public Ui_ReportLossGoodsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTLOSSGOODSWIDGET_H
