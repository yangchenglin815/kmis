/********************************************************************************
** Form generated from reading UI file 'CheckOrderGoodsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKORDERGOODSDLG_H
#define UI_CHECKORDERGOODSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CheckOrderGoodsWidget.h"
#include "TitleBarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CheckOrderGoodsDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    CheckOrderGoodsWidget *checkOrderGoodsWidget;

    void setupUi(QDialog *CheckOrderGoodsDlg)
    {
        if (CheckOrderGoodsDlg->objectName().isEmpty())
            CheckOrderGoodsDlg->setObjectName(QStringLiteral("CheckOrderGoodsDlg"));
        CheckOrderGoodsDlg->resize(702, 560);
        verticalLayout = new QVBoxLayout(CheckOrderGoodsDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(CheckOrderGoodsDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 42));
        titleWidget->setMaximumSize(QSize(16777215, 42));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(CheckOrderGoodsDlg);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 20, 24);
        checkOrderGoodsWidget = new CheckOrderGoodsWidget(mainWidget);
        checkOrderGoodsWidget->setObjectName(QStringLiteral("checkOrderGoodsWidget"));

        horizontalLayout->addWidget(checkOrderGoodsWidget);


        verticalLayout->addWidget(mainWidget);


        retranslateUi(CheckOrderGoodsDlg);

        QMetaObject::connectSlotsByName(CheckOrderGoodsDlg);
    } // setupUi

    void retranslateUi(QDialog *CheckOrderGoodsDlg)
    {
        CheckOrderGoodsDlg->setWindowTitle(QApplication::translate("CheckOrderGoodsDlg", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CheckOrderGoodsDlg: public Ui_CheckOrderGoodsDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKORDERGOODSDLG_H
