/********************************************************************************
** Form generated from reading UI file 'ReceiptTitleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIPTTITLEWIDGET_H
#define UI_RECEIPTTITLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReceiptTitleWidget
{
public:

    void setupUi(QWidget *ReceiptTitleWidget)
    {
        if (ReceiptTitleWidget->objectName().isEmpty())
            ReceiptTitleWidget->setObjectName(QStringLiteral("ReceiptTitleWidget"));
        ReceiptTitleWidget->resize(400, 300);

        retranslateUi(ReceiptTitleWidget);

        QMetaObject::connectSlotsByName(ReceiptTitleWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiptTitleWidget)
    {
        ReceiptTitleWidget->setWindowTitle(QApplication::translate("ReceiptTitleWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiptTitleWidget: public Ui_ReceiptTitleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIPTTITLEWIDGET_H
