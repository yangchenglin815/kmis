/********************************************************************************
** Form generated from reading UI file 'PayWaySetPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYWAYSETPAGE_H
#define UI_PAYWAYSETPAGE_H

#include <GridWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "KPosComboBox.h"
#include "SwitchButton.h"

QT_BEGIN_NAMESPACE

class Ui_PayWaySetPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *skinWidget;
    QLabel *label_25;
    QPushButton *nextPageButton;
    QLabel *label_28;
    GridWidget *firstGrideWidget;
    SwitchButton *memberStartButton;
    SwitchButton *alipayStartButton;
    SwitchButton *weChatMemberButton;
    SwitchButton *weChatStartButton;
    SwitchButton *alipayMemberButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    SwitchButton *virtualMemberButton;
    SwitchButton *virtualButton;
    QLabel *label_26;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *payImageLabel_0;
    QLabel *payMethodLabel_0;
    QLabel *payMethodLabel_1;
    QLabel *payImageLabel_1;
    QLabel *payMethodLabel_2;
    QLabel *payImageLabel_2;
    QLabel *payImageLabel_3;
    QLabel *payMethodLabel_3;
    QLabel *payMethodLabel_4;
    QLabel *payImageLabel_4;
    QWidget *page_2;
    QLabel *label_24;
    QLabel *label_35;
    QLabel *label_34;
    QLabel *label_23;
    KPosComboBox *cashComBox;

    void setupUi(QWidget *PayWaySetPage)
    {
        if (PayWaySetPage->objectName().isEmpty())
            PayWaySetPage->setObjectName(QStringLiteral("PayWaySetPage"));
        PayWaySetPage->resize(607, 513);
        verticalLayout = new QVBoxLayout(PayWaySetPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        skinWidget = new QWidget(PayWaySetPage);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color: #ffffff;\n"
"}"));
        label_25 = new QLabel(skinWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(0, 238, 124, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_25->setFont(font);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nextPageButton = new QPushButton(skinWidget);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setGeometry(QRect(590, 60, 15, 18));
        nextPageButton->setMinimumSize(QSize(15, 18));
        nextPageButton->setMaximumSize(QSize(15, 18));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/kPosSetImage/right.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/kPosSetImage/right_press.png);\n"
"}"));
        label_28 = new QLabel(skinWidget);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(0, 120, 124, 30));
        label_28->setFont(font);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        firstGrideWidget = new GridWidget(skinWidget);
        firstGrideWidget->setObjectName(QStringLiteral("firstGrideWidget"));
        firstGrideWidget->setGeometry(QRect(140, 110, 400, 81));
        memberStartButton = new SwitchButton(firstGrideWidget);
        memberStartButton->setObjectName(QStringLiteral("memberStartButton"));
        memberStartButton->setGeometry(QRect(92, 10, 54, 21));
        memberStartButton->setMinimumSize(QSize(0, 0));
        memberStartButton->setMaximumSize(QSize(16777215, 16777215));
        memberStartButton->setFont(font);
        memberStartButton->setStyleSheet(QStringLiteral(""));
        alipayStartButton = new SwitchButton(firstGrideWidget);
        alipayStartButton->setObjectName(QStringLiteral("alipayStartButton"));
        alipayStartButton->setGeometry(QRect(172, 10, 54, 21));
        alipayStartButton->setMinimumSize(QSize(0, 0));
        alipayStartButton->setMaximumSize(QSize(16777215, 16777215));
        alipayStartButton->setFont(font);
        alipayStartButton->setStyleSheet(QStringLiteral(""));
        weChatMemberButton = new SwitchButton(firstGrideWidget);
        weChatMemberButton->setObjectName(QStringLiteral("weChatMemberButton"));
        weChatMemberButton->setGeometry(QRect(252, 50, 54, 21));
        weChatMemberButton->setMinimumSize(QSize(0, 0));
        weChatMemberButton->setMaximumSize(QSize(16777215, 16777215));
        weChatMemberButton->setFont(font);
        weChatMemberButton->setStyleSheet(QStringLiteral(""));
        weChatStartButton = new SwitchButton(firstGrideWidget);
        weChatStartButton->setObjectName(QStringLiteral("weChatStartButton"));
        weChatStartButton->setGeometry(QRect(252, 10, 54, 21));
        weChatStartButton->setMinimumSize(QSize(0, 0));
        weChatStartButton->setMaximumSize(QSize(16777215, 16777215));
        weChatStartButton->setFont(font);
        weChatStartButton->setStyleSheet(QStringLiteral(""));
        alipayMemberButton = new SwitchButton(firstGrideWidget);
        alipayMemberButton->setObjectName(QStringLiteral("alipayMemberButton"));
        alipayMemberButton->setGeometry(QRect(172, 50, 54, 21));
        alipayMemberButton->setMinimumSize(QSize(0, 0));
        alipayMemberButton->setMaximumSize(QSize(16777215, 16777215));
        alipayMemberButton->setFont(font);
        alipayMemberButton->setStyleSheet(QStringLiteral(""));
        label = new QLabel(firstGrideWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 79, 40));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(firstGrideWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 40, 79, 40));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(firstGrideWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 40, 79, 40));
        label_3->setAlignment(Qt::AlignCenter);
        virtualMemberButton = new SwitchButton(firstGrideWidget);
        virtualMemberButton->setObjectName(QStringLiteral("virtualMemberButton"));
        virtualMemberButton->setGeometry(QRect(332, 50, 54, 21));
        virtualMemberButton->setMinimumSize(QSize(0, 0));
        virtualMemberButton->setMaximumSize(QSize(16777215, 16777215));
        virtualMemberButton->setFont(font);
        virtualMemberButton->setStyleSheet(QStringLiteral(""));
        virtualButton = new SwitchButton(firstGrideWidget);
        virtualButton->setObjectName(QStringLiteral("virtualButton"));
        virtualButton->setGeometry(QRect(332, 10, 54, 21));
        virtualButton->setMinimumSize(QSize(0, 0));
        virtualButton->setMaximumSize(QSize(16777215, 16777215));
        virtualButton->setFont(font);
        virtualButton->setStyleSheet(QStringLiteral(""));
        label_26 = new QLabel(skinWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(0, 160, 124, 30));
        label_26->setFont(font);
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stackedWidget = new QStackedWidget(skinWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(140, 40, 400, 71));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        payImageLabel_0 = new QLabel(page);
        payImageLabel_0->setObjectName(QStringLiteral("payImageLabel_0"));
        payImageLabel_0->setGeometry(QRect(28, 7, 29, 30));
        payImageLabel_0->setStyleSheet(QStringLiteral("border-image: url(:/kPosSetImage/money.png);"));
        payMethodLabel_0 = new QLabel(page);
        payMethodLabel_0->setObjectName(QStringLiteral("payMethodLabel_0"));
        payMethodLabel_0->setGeometry(QRect(0, 42, 79, 20));
        payMethodLabel_0->setFont(font);
        payMethodLabel_0->setAlignment(Qt::AlignCenter);
        payMethodLabel_1 = new QLabel(page);
        payMethodLabel_1->setObjectName(QStringLiteral("payMethodLabel_1"));
        payMethodLabel_1->setGeometry(QRect(80, 42, 79, 20));
        payMethodLabel_1->setFont(font);
        payMethodLabel_1->setAlignment(Qt::AlignCenter);
        payImageLabel_1 = new QLabel(page);
        payImageLabel_1->setObjectName(QStringLiteral("payImageLabel_1"));
        payImageLabel_1->setGeometry(QRect(104, 7, 29, 30));
        payImageLabel_1->setStyleSheet(QStringLiteral("border-image: url(:/kPosSetImage/huiyuanka.png);"));
        payMethodLabel_2 = new QLabel(page);
        payMethodLabel_2->setObjectName(QStringLiteral("payMethodLabel_2"));
        payMethodLabel_2->setGeometry(QRect(160, 42, 79, 20));
        payMethodLabel_2->setFont(font);
        payMethodLabel_2->setAlignment(Qt::AlignCenter);
        payImageLabel_2 = new QLabel(page);
        payImageLabel_2->setObjectName(QStringLiteral("payImageLabel_2"));
        payImageLabel_2->setGeometry(QRect(187, 7, 29, 30));
        payImageLabel_2->setStyleSheet(QStringLiteral("border-image: url(:/kPosSetImage/zhifubao.png);"));
        payImageLabel_3 = new QLabel(page);
        payImageLabel_3->setObjectName(QStringLiteral("payImageLabel_3"));
        payImageLabel_3->setGeometry(QRect(265, 7, 29, 30));
        payImageLabel_3->setStyleSheet(QStringLiteral("border-image: url(:/kPosSetImage/wxzhifu.png);"));
        payMethodLabel_3 = new QLabel(page);
        payMethodLabel_3->setObjectName(QStringLiteral("payMethodLabel_3"));
        payMethodLabel_3->setGeometry(QRect(240, 42, 79, 20));
        payMethodLabel_3->setFont(font);
        payMethodLabel_3->setAlignment(Qt::AlignCenter);
        payMethodLabel_4 = new QLabel(page);
        payMethodLabel_4->setObjectName(QStringLiteral("payMethodLabel_4"));
        payMethodLabel_4->setGeometry(QRect(320, 42, 79, 20));
        payMethodLabel_4->setFont(font);
        payMethodLabel_4->setAlignment(Qt::AlignCenter);
        payImageLabel_4 = new QLabel(page);
        payImageLabel_4->setObjectName(QStringLiteral("payImageLabel_4"));
        payImageLabel_4->setGeometry(QRect(340, 7, 29, 30));
        payImageLabel_4->setStyleSheet(QStringLiteral("border-image: url(:/kPosSetImage/xuni.png);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_24 = new QLabel(page_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(20, 41, 61, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label_24->setFont(font1);
        label_24->setAlignment(Qt::AlignCenter);
        label_35 = new QLabel(page_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(32, 1, 35, 35));
        label_35->setStyleSheet(QStringLiteral("border-image: url(:/kPosSetImage/jd_wallet.png);"));
        label_34 = new QLabel(page_2);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(103, 41, 32, 20));
        label_34->setFont(font1);
        label_34->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(page_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(103, 1, 32, 39));
        label_23->setStyleSheet(QStringLiteral("border-image: url(:/kPosSetImage/apple_pay.png);"));
        stackedWidget->addWidget(page_2);
        cashComBox = new KPosComboBox(skinWidget);
        cashComBox->setObjectName(QStringLiteral("cashComBox"));
        cashComBox->setGeometry(QRect(140, 236, 81, 30));
        cashComBox->setMinimumSize(QSize(0, 0));
        cashComBox->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(skinWidget);


        retranslateUi(PayWaySetPage);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PayWaySetPage);
    } // setupUi

    void retranslateUi(QWidget *PayWaySetPage)
    {
        PayWaySetPage->setWindowTitle(QApplication::translate("PayWaySetPage", "Form", Q_NULLPTR));
        label_25->setText(QApplication::translate("PayWaySetPage", "\345\210\206\347\232\204\345\205\203\346\225\264\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        nextPageButton->setText(QString());
        label_28->setText(QApplication::translate("PayWaySetPage", "\346\230\257\345\220\246\345\220\257\347\224\250\357\274\232", Q_NULLPTR));
        memberStartButton->setText(QString());
        alipayStartButton->setText(QString());
        weChatMemberButton->setText(QString());
        weChatStartButton->setText(QString());
        alipayMemberButton->setText(QString());
        label->setText(QApplication::translate("PayWaySetPage", "\346\230\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("PayWaySetPage", "\346\230\257", Q_NULLPTR));
        label_3->setText(QApplication::translate("PayWaySetPage", "\345\220\246", Q_NULLPTR));
        virtualMemberButton->setText(QString());
        virtualButton->setText(QString());
        label_26->setText(QApplication::translate("PayWaySetPage", "\346\230\257\345\220\246\347\224\250\344\272\216\344\274\232\345\221\230\346\224\257\344\273\230\357\274\232", Q_NULLPTR));
        payImageLabel_0->setText(QString());
        payMethodLabel_0->setText(QApplication::translate("PayWaySetPage", "\347\216\260\351\207\221", Q_NULLPTR));
        payMethodLabel_1->setText(QApplication::translate("PayWaySetPage", "\344\274\232\345\221\230\345\215\241", Q_NULLPTR));
        payImageLabel_1->setText(QString());
        payMethodLabel_2->setText(QApplication::translate("PayWaySetPage", "\346\224\257\344\273\230\345\256\235", Q_NULLPTR));
        payImageLabel_2->setText(QString());
        payImageLabel_3->setText(QString());
        payMethodLabel_3->setText(QApplication::translate("PayWaySetPage", "\345\276\256\344\277\241\346\224\257\344\273\230", Q_NULLPTR));
        payMethodLabel_4->setText(QApplication::translate("PayWaySetPage", "\350\231\232\346\213\237\346\224\257\344\273\230", Q_NULLPTR));
        payImageLabel_4->setText(QString());
        label_24->setText(QApplication::translate("PayWaySetPage", "\344\272\254\344\270\234\351\222\261\345\214\205", Q_NULLPTR));
        label_35->setText(QString());
        label_34->setText(QApplication::translate("PayWaySetPage", "pay", Q_NULLPTR));
        label_23->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PayWaySetPage: public Ui_PayWaySetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYWAYSETPAGE_H
