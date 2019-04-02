/********************************************************************************
** Form generated from reading UI file 'BCSAddGoodsGroupDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSADDGOODSGROUPDLG_H
#define UI_BCSADDGOODSGROUPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "SearchEdit.h"
#include "TitleBarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCSAddGoodsGroupDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *skinWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *mainWidget;
    QLabel *label;
    QPushButton *confirmButton;
    QLabel *hintLabel;
    SearchEdit *nameWidget;

    void setupUi(QDialog *BCSAddGoodsGroupDlg)
    {
        if (BCSAddGoodsGroupDlg->objectName().isEmpty())
            BCSAddGoodsGroupDlg->setObjectName(QStringLiteral("BCSAddGoodsGroupDlg"));
        BCSAddGoodsGroupDlg->resize(370, 266);
        verticalLayout = new QVBoxLayout(BCSAddGoodsGroupDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(BCSAddGoodsGroupDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 46));
        titleWidget->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(titleWidget);

        skinWidget = new QWidget(BCSAddGoodsGroupDlg);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"background-color: #505050;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(skinWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        mainWidget = new QWidget(skinWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setMinimumSize(QSize(0, 0));
        mainWidget->setMaximumSize(QSize(16777215, 16777215));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        label = new QLabel(mainWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(28, 52, 71, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        confirmButton = new QPushButton(mainWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(24, 119, 291, 44));
        confirmButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#ffffff;\n"
"font-size:16px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));
        hintLabel = new QLabel(mainWidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setGeometry(QRect(30, 90, 271, 20));
        nameWidget = new SearchEdit(mainWidget);
        nameWidget->setObjectName(QStringLiteral("nameWidget"));
        nameWidget->setGeometry(QRect(100, 50, 211, 32));
        nameWidget->setStyleSheet(QStringLiteral("border:1px solid red;"));

        verticalLayout_2->addWidget(mainWidget);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(BCSAddGoodsGroupDlg);

        QMetaObject::connectSlotsByName(BCSAddGoodsGroupDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSAddGoodsGroupDlg)
    {
        BCSAddGoodsGroupDlg->setWindowTitle(QApplication::translate("BCSAddGoodsGroupDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSAddGoodsGroupDlg", "\345\225\206\345\223\201\347\273\204\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("BCSAddGoodsGroupDlg", "\347\241\256\350\256\244", Q_NULLPTR));
        hintLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BCSAddGoodsGroupDlg: public Ui_BCSAddGoodsGroupDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSADDGOODSGROUPDLG_H
