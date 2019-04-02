/********************************************************************************
** Form generated from reading UI file 'AlipayRechargeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALIPAYRECHARGEDLG_H
#define UI_ALIPAYRECHARGEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_AlipayRechargeDlg
{
public:
    QGridLayout *gridLayout_2;
    TitleBarWidget *titleWnd;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *refreshButton;
    QPushButton *cancelButton;
    QWidget *widget_3;
    QLabel *rechargeLabel;
    QLabel *statusLabel;
    QLabel *rechargeAmtLabel;
    QLabel *statusValueLabel;

    void setupUi(QDialog *AlipayRechargeDlg)
    {
        if (AlipayRechargeDlg->objectName().isEmpty())
            AlipayRechargeDlg->setObjectName(QStringLiteral("AlipayRechargeDlg"));
        AlipayRechargeDlg->resize(370, 231);
        AlipayRechargeDlg->setMinimumSize(QSize(370, 231));
        AlipayRechargeDlg->setFocusPolicy(Qt::StrongFocus);
        gridLayout_2 = new QGridLayout(AlipayRechargeDlg);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWnd = new TitleBarWidget(AlipayRechargeDlg);
        titleWnd->setObjectName(QStringLiteral("titleWnd"));
        titleWnd->setMinimumSize(QSize(0, 40));
        titleWnd->setMaximumSize(QSize(16777215, 60));

        gridLayout_2->addWidget(titleWnd, 0, 0, 1, 1);

        widget_2 = new QWidget(AlipayRechargeDlg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2 {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(17);
        gridLayout->setContentsMargins(20, 14, 20, 25);
        refreshButton = new QPushButton(widget_2);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(refreshButton->sizePolicy().hasHeightForWidth());
        refreshButton->setSizePolicy(sizePolicy);
        refreshButton->setMinimumSize(QSize(152, 42));
        refreshButton->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        refreshButton->setFont(font);
        refreshButton->setFocusPolicy(Qt::NoFocus);
        refreshButton->setStyleSheet(QLatin1String("QPushButton#refreshButton{\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"                        \n"
"QPushButton#refreshButton:pressed{\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));

        gridLayout->addWidget(refreshButton, 1, 0, 1, 1);

        cancelButton = new QPushButton(widget_2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(66);
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);
        cancelButton->setMinimumSize(QSize(152, 42));
        cancelButton->setMaximumSize(QSize(16777215, 16777215));
        cancelButton->setFont(font);
        cancelButton->setFocusPolicy(Qt::NoFocus);
        cancelButton->setStyleSheet(QLatin1String("QPushButton#cancelButton{\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/cancel_normal.png);\n"
"}\n"
"                        \n"
"QPushButton#cancelButton:pressed{\n"
"	border-image: url(:/shareImages/cancel_press.png);\n"
"}"));

        gridLayout->addWidget(cancelButton, 1, 1, 1, 1);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(328, 93));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        rechargeLabel = new QLabel(widget_3);
        rechargeLabel->setObjectName(QStringLiteral("rechargeLabel"));
        rechargeLabel->setGeometry(QRect(10, 21, 71, 16));
        rechargeLabel->setFont(font);
        rechargeLabel->setStyleSheet(QStringLiteral("font-size:14px;"));
        statusLabel = new QLabel(widget_3);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(10, 56, 71, 16));
        statusLabel->setFont(font);
        statusLabel->setStyleSheet(QStringLiteral("font-size:14px;"));
        rechargeAmtLabel = new QLabel(widget_3);
        rechargeAmtLabel->setObjectName(QStringLiteral("rechargeAmtLabel"));
        rechargeAmtLabel->setGeometry(QRect(216, 21, 101, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        rechargeAmtLabel->setFont(font1);
        rechargeAmtLabel->setStyleSheet(QString::fromUtf8("font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:18px;\n"
"color: rgb(51, 51, 51);"));
        rechargeAmtLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statusValueLabel = new QLabel(widget_3);
        statusValueLabel->setObjectName(QStringLiteral("statusValueLabel"));
        statusValueLabel->setGeometry(QRect(246, 56, 71, 16));
        statusValueLabel->setFont(font);
        statusValueLabel->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(117, 171, 87);"));
        statusValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(widget_3, 0, 0, 1, 2);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(AlipayRechargeDlg);

        QMetaObject::connectSlotsByName(AlipayRechargeDlg);
    } // setupUi

    void retranslateUi(QDialog *AlipayRechargeDlg)
    {
        AlipayRechargeDlg->setWindowTitle(QApplication::translate("AlipayRechargeDlg", "AlipayRechargeDlg", Q_NULLPTR));
        refreshButton->setText(QApplication::translate("AlipayRechargeDlg", "\345\210\267\346\226\260", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("AlipayRechargeDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        rechargeLabel->setText(QApplication::translate("AlipayRechargeDlg", "\345\205\205\345\200\274\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("AlipayRechargeDlg", "\346\224\257\344\273\230\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        rechargeAmtLabel->setText(QApplication::translate("AlipayRechargeDlg", "\357\277\24537.02", Q_NULLPTR));
        statusValueLabel->setText(QApplication::translate("AlipayRechargeDlg", "\346\210\220\345\212\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AlipayRechargeDlg: public Ui_AlipayRechargeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALIPAYRECHARGEDLG_H
