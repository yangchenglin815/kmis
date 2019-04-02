/********************************************************************************
** Form generated from reading UI file 'RefundGoodsReasonDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFUNDGOODSREASONDLG_H
#define UI_REFUNDGOODSREASONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_RefundGoodsReasonDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *skinWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *reason1Edit;
    QLineEdit *reason2Edit;
    QLineEdit *reason3Edit;
    QLineEdit *reason4Edit;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *RefundGoodsReasonDlg)
    {
        if (RefundGoodsReasonDlg->objectName().isEmpty())
            RefundGoodsReasonDlg->setObjectName(QStringLiteral("RefundGoodsReasonDlg"));
        RefundGoodsReasonDlg->resize(370, 328);
        verticalLayout = new QVBoxLayout(RefundGoodsReasonDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(RefundGoodsReasonDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 46));
        titleWidget->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(titleWidget);

        skinWidget = new QWidget(RefundGoodsReasonDlg);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color:#505050;\n"
"}"));
        horizontalLayout = new QHBoxLayout(skinWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(17, 16, 17, 16);
        mainWidget = new QWidget(skinWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(mainWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 0, 20, 0);
        label = new QLabel(mainWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 42));
        label->setMaximumSize(QSize(16777215, 42));

        verticalLayout_3->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        reason1Edit = new QLineEdit(mainWidget);
        reason1Edit->setObjectName(QStringLiteral("reason1Edit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(reason1Edit->sizePolicy().hasHeightForWidth());
        reason1Edit->setSizePolicy(sizePolicy1);
        reason1Edit->setMinimumSize(QSize(0, 40));
        reason1Edit->setMaximumSize(QSize(16777215, 40));
        reason1Edit->setFocusPolicy(Qt::NoFocus);
        reason1Edit->setReadOnly(true);

        verticalLayout_2->addWidget(reason1Edit);

        reason2Edit = new QLineEdit(mainWidget);
        reason2Edit->setObjectName(QStringLiteral("reason2Edit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(reason2Edit->sizePolicy().hasHeightForWidth());
        reason2Edit->setSizePolicy(sizePolicy2);
        reason2Edit->setMinimumSize(QSize(0, 40));
        reason2Edit->setMaximumSize(QSize(16777215, 40));
        reason2Edit->setFocusPolicy(Qt::NoFocus);
        reason2Edit->setReadOnly(true);

        verticalLayout_2->addWidget(reason2Edit);

        reason3Edit = new QLineEdit(mainWidget);
        reason3Edit->setObjectName(QStringLiteral("reason3Edit"));
        sizePolicy2.setHeightForWidth(reason3Edit->sizePolicy().hasHeightForWidth());
        reason3Edit->setSizePolicy(sizePolicy2);
        reason3Edit->setMinimumSize(QSize(0, 40));
        reason3Edit->setMaximumSize(QSize(16777215, 40));
        reason3Edit->setFocusPolicy(Qt::NoFocus);
        reason3Edit->setReadOnly(true);

        verticalLayout_2->addWidget(reason3Edit);

        reason4Edit = new QLineEdit(mainWidget);
        reason4Edit->setObjectName(QStringLiteral("reason4Edit"));
        sizePolicy2.setHeightForWidth(reason4Edit->sizePolicy().hasHeightForWidth());
        reason4Edit->setSizePolicy(sizePolicy2);
        reason4Edit->setMinimumSize(QSize(0, 40));
        reason4Edit->setMaximumSize(QSize(16777215, 40));
        reason4Edit->setFocusPolicy(Qt::NoFocus);
        reason4Edit->setReadOnly(true);

        verticalLayout_2->addWidget(reason4Edit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addWidget(mainWidget);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(RefundGoodsReasonDlg);

        QMetaObject::connectSlotsByName(RefundGoodsReasonDlg);
    } // setupUi

    void retranslateUi(QDialog *RefundGoodsReasonDlg)
    {
        RefundGoodsReasonDlg->setWindowTitle(QApplication::translate("RefundGoodsReasonDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("RefundGoodsReasonDlg", "\350\257\267\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
        reason1Edit->setText(QApplication::translate("RefundGoodsReasonDlg", "\346\227\240\347\220\206\347\224\261\351\200\200\350\264\247", Q_NULLPTR));
        reason2Edit->setText(QApplication::translate("RefundGoodsReasonDlg", "\346\224\266\345\210\260\345\201\207\350\264\247", Q_NULLPTR));
        reason3Edit->setText(QApplication::translate("RefundGoodsReasonDlg", "\345\217\221\347\245\250\351\227\256\351\242\230", Q_NULLPTR));
        reason4Edit->setText(QApplication::translate("RefundGoodsReasonDlg", "\350\264\247\344\270\215\345\257\271\347\211\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RefundGoodsReasonDlg: public Ui_RefundGoodsReasonDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFUNDGOODSREASONDLG_H
