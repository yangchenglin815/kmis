/********************************************************************************
** Form generated from reading UI file 'BankCardRechargeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKCARDRECHARGEDLG_H
#define UI_BANKCARDRECHARGEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_BankCardRechargeDlg
{
public:
    QGridLayout *gridLayout_2;
    TitleBarWidget *widget;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QLabel *bankCardIDLabel;
    QLabel *bankCardLabel;
    QLabel *payPasswdLabel;
    QLabel *payPasswdValueLabel;
    QFrame *splitLine;
    QWidget *widget_4;
    QLabel *statusValueLabel;
    QLabel *rechargeAmtLabel;
    QLabel *statusLabel;
    QLabel *rechargeLabel;

    void setupUi(QDialog *BankCardRechargeDlg)
    {
        if (BankCardRechargeDlg->objectName().isEmpty())
            BankCardRechargeDlg->setObjectName(QStringLiteral("BankCardRechargeDlg"));
        BankCardRechargeDlg->resize(498, 319);
        gridLayout_2 = new QGridLayout(BankCardRechargeDlg);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new TitleBarWidget(BankCardRechargeDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 60));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(BankCardRechargeDlg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(30, 20, 30, 30);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        bankCardIDLabel = new QLabel(widget_3);
        bankCardIDLabel->setObjectName(QStringLiteral("bankCardIDLabel"));
        bankCardIDLabel->setGeometry(QRect(109, 25, 291, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        bankCardIDLabel->setFont(font);
        bankCardIDLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bankCardLabel = new QLabel(widget_3);
        bankCardLabel->setObjectName(QStringLiteral("bankCardLabel"));
        bankCardLabel->setGeometry(QRect(25, 25, 100, 20));
        bankCardLabel->setFont(font);
        payPasswdLabel = new QLabel(widget_3);
        payPasswdLabel->setObjectName(QStringLiteral("payPasswdLabel"));
        payPasswdLabel->setGeometry(QRect(25, 60, 100, 20));
        payPasswdLabel->setFont(font);
        payPasswdValueLabel = new QLabel(widget_3);
        payPasswdValueLabel->setObjectName(QStringLiteral("payPasswdValueLabel"));
        payPasswdValueLabel->setGeometry(QRect(99, 60, 301, 20));
        payPasswdValueLabel->setFont(font);
        payPasswdValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(widget_3, 0, 0, 1, 1);

        splitLine = new QFrame(widget_2);
        splitLine->setObjectName(QStringLiteral("splitLine"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitLine->sizePolicy().hasHeightForWidth());
        splitLine->setSizePolicy(sizePolicy);
        splitLine->setMinimumSize(QSize(0, 2));
        splitLine->setMaximumSize(QSize(16777215, 2));
        splitLine->setFrameShape(QFrame::HLine);
        splitLine->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(splitLine, 1, 0, 1, 1);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        statusValueLabel = new QLabel(widget_4);
        statusValueLabel->setObjectName(QStringLiteral("statusValueLabel"));
        statusValueLabel->setGeometry(QRect(250, 63, 150, 20));
        statusValueLabel->setFont(font);
        statusValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rechargeAmtLabel = new QLabel(widget_4);
        rechargeAmtLabel->setObjectName(QStringLiteral("rechargeAmtLabel"));
        rechargeAmtLabel->setGeometry(QRect(250, 17, 150, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        rechargeAmtLabel->setFont(font1);
        rechargeAmtLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statusLabel = new QLabel(widget_4);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(20, 63, 100, 20));
        statusLabel->setFont(font);
        rechargeLabel = new QLabel(widget_4);
        rechargeLabel->setObjectName(QStringLiteral("rechargeLabel"));
        rechargeLabel->setGeometry(QRect(20, 22, 100, 20));
        rechargeLabel->setFont(font);

        gridLayout->addWidget(widget_4, 2, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(BankCardRechargeDlg);

        QMetaObject::connectSlotsByName(BankCardRechargeDlg);
    } // setupUi

    void retranslateUi(QDialog *BankCardRechargeDlg)
    {
        BankCardRechargeDlg->setWindowTitle(QApplication::translate("BankCardRechargeDlg", "BankCardRechargeDlg", Q_NULLPTR));
        bankCardIDLabel->setText(QString());
        bankCardLabel->setText(QApplication::translate("BankCardRechargeDlg", "\351\223\266\350\241\214\345\215\241\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        payPasswdLabel->setText(QApplication::translate("BankCardRechargeDlg", "\346\224\257\344\273\230\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        payPasswdValueLabel->setText(QString());
        statusValueLabel->setText(QString());
        rechargeAmtLabel->setText(QString());
        statusLabel->setText(QApplication::translate("BankCardRechargeDlg", "\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        rechargeLabel->setText(QApplication::translate("BankCardRechargeDlg", "\345\205\205\345\200\274\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BankCardRechargeDlg: public Ui_BankCardRechargeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKCARDRECHARGEDLG_H
