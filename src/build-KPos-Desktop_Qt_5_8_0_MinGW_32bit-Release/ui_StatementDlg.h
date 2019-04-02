/********************************************************************************
** Form generated from reading UI file 'StatementDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATEMENTDLG_H
#define UI_STATEMENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <VirtualPayWidget.h>
#include <WndDigitalKeyboard.h>
#include "StatementMethodButton.h"
#include "TitleBarWidget.h"
#include "VirtualPaysWidget.h"

QT_BEGIN_NAMESPACE

class Ui_StatementDlg
{
public:
    QWidget *widget;
    QWidget *widget_2;
    StatementMethodButton *payMethodBtn_1;
    StatementMethodButton *payMethodBtn_4;
    StatementMethodButton *payMethodBtn_5;
    StatementMethodButton *payMethodBtn_3;
    StatementMethodButton *payMethodBtn_2;
    QWidget *widget_4;
    QFrame *id_line_2;
    QLabel *discountLabel;
    QLabel *simpleAmtLabel;
    QPushButton *samllChangeButton;
    QLabel *simpleAmtValueLabel;
    QLabel *amtPaidValueLabel;
    QLabel *discountValueLabel;
    QFrame *id_line_1;
    QLabel *disAmtLabel;
    QLabel *disAmtValueLabel;
    QPushButton *paymentDetailButton;
    QLabel *amtPaidLabel;
    QLabel *receivedValueLabel;
    QLabel *amtReceivedLabel;
    QFrame *id_line_3;
    QStackedWidget *stackedWidget;
    QWidget *cashWidget;
    QWidget *widget_3;
    QPushButton *statementButton;
    QLabel *factAmtCashLabel;
    QLineEdit *factAmtCashEdit;
    QWidget *memCardWidget;
    QWidget *widget_5;
    QFrame *line_2;
    QLabel *id_lab_integ_value;
    QLabel *id_lab_integ;
    QLabel *id_lab_can_arrived_value;
    QLabel *id_lab_mem_card;
    QLabel *id_lab_mem_card_value;
    QLabel *id_lab_can_arrived;
    QWidget *widget_6;
    QLabel *arrivedMemLabel;
    QLabel *balanceMemLabel;
    QPushButton *statementMemButton;
    QLabel *arrivedValueLabel;
    QLabel *integUseMemLabel;
    QLineEdit *balanceMemEdit;
    QLineEdit *integUseMemEdit;
    QLabel *memWarningLabel;
    QWidget *storeCardWidget;
    QLabel *warningStoreLabel;
    QPushButton *statementStoreButton;
    QLabel *cardIDStoreLabel;
    QLineEdit *useAmtStoreEdit;
    QLineEdit *cardIDStoreEdit;
    QLabel *useAmtStoreLabel;
    QLabel *currentAmtStoreLabel;
    QLineEdit *currentAmtStoreEdit;
    QWidget *alipayWidget;
    QWidget *widget_7;
    QPushButton *statementAlipayButton;
    QLabel *factAmtAlipayLabel;
    QLineEdit *factAmtAlipayEdit;
    QWidget *wechartPayWidget;
    QWidget *widget_9;
    QPushButton *statementWeButton;
    QLabel *factAmtWeLabel;
    QLineEdit *factAmtWeEdit;
    QWidget *applePayWidget;
    QWidget *widget_10;
    QPushButton *statementAppleButton;
    QLabel *factAmtAppleLabel;
    QLineEdit *factAmtAppleEdit;
    QWidget *jdWalletWidget;
    QWidget *widget_11;
    QPushButton *statementJdButton;
    QLabel *factAmtJdLabel;
    QLineEdit *factAmtJdEdit;
    QWidget *CouponWidget;
    QWidget *widget_12;
    QPushButton *statementCouponButton;
    QLabel *factAmtCouponLabel_1;
    QLineEdit *factAmtCouponEdit_1;
    QLineEdit *factAmtCouponEdit_2;
    QLabel *factAmtCouponLabel_2;
    QLabel *factAmtCouponLabel_3;
    QWidget *unionPayWidget;
    QWidget *widget_13;
    QLineEdit *factAmtUnionEdit;
    QPushButton *statementUnionButton;
    QLabel *factAmtUnionLabel;
    VirtualPayWidget *virtualPayWidget;
    VirtualPaysWidget *virtualPaysPage;
    QFrame *line_3;
    QWidget *widget_8;
    QGridLayout *gridLayout;
    QPushButton *factorButton;
    QPushButton *fiftyButton;
    QPushButton *hundredButton;
    QPushButton *twoHundredButton;
    WndDigitalKeyboard *DigitalKeyWnd;
    QFrame *line;
    TitleBarWidget *titleWidget;

    void setupUi(QDialog *StatementDlg)
    {
        if (StatementDlg->objectName().isEmpty())
            StatementDlg->setObjectName(QStringLiteral("StatementDlg"));
        StatementDlg->resize(728, 544);
        StatementDlg->setMinimumSize(QSize(727, 543));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        StatementDlg->setFont(font);
        StatementDlg->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(StatementDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 40, 728, 504));
        widget->setMinimumSize(QSize(0, 504));
        widget->setMaximumSize(QSize(16777215, 504));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 314, 504));
        widget_2->setMinimumSize(QSize(314, 504));
        widget_2->setMaximumSize(QSize(314, 16777215));
        payMethodBtn_1 = new StatementMethodButton(widget_2);
        payMethodBtn_1->setObjectName(QStringLiteral("payMethodBtn_1"));
        payMethodBtn_1->setGeometry(QRect(14, 14, 55, 35));
        payMethodBtn_1->setMinimumSize(QSize(55, 35));
        payMethodBtn_1->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        payMethodBtn_1->setFont(font1);
        payMethodBtn_1->setFocusPolicy(Qt::NoFocus);
        payMethodBtn_1->setStyleSheet(QStringLiteral(""));
        payMethodBtn_4 = new StatementMethodButton(widget_2);
        payMethodBtn_4->setObjectName(QStringLiteral("payMethodBtn_4"));
        payMethodBtn_4->setGeometry(QRect(185, 14, 55, 35));
        payMethodBtn_4->setMinimumSize(QSize(55, 35));
        payMethodBtn_4->setMaximumSize(QSize(16777215, 16777215));
        payMethodBtn_4->setFont(font1);
        payMethodBtn_4->setFocusPolicy(Qt::NoFocus);
        payMethodBtn_4->setStyleSheet(QStringLiteral(""));
        payMethodBtn_5 = new StatementMethodButton(widget_2);
        payMethodBtn_5->setObjectName(QStringLiteral("payMethodBtn_5"));
        payMethodBtn_5->setGeometry(QRect(242, 14, 55, 35));
        payMethodBtn_5->setMinimumSize(QSize(55, 35));
        payMethodBtn_5->setMaximumSize(QSize(16777215, 16777215));
        payMethodBtn_5->setFont(font);
        payMethodBtn_5->setFocusPolicy(Qt::NoFocus);
        payMethodBtn_5->setStyleSheet(QStringLiteral(""));
        payMethodBtn_3 = new StatementMethodButton(widget_2);
        payMethodBtn_3->setObjectName(QStringLiteral("payMethodBtn_3"));
        payMethodBtn_3->setGeometry(QRect(128, 14, 55, 35));
        payMethodBtn_3->setMinimumSize(QSize(55, 35));
        payMethodBtn_3->setMaximumSize(QSize(16777215, 16777215));
        payMethodBtn_3->setFont(font1);
        payMethodBtn_3->setFocusPolicy(Qt::NoFocus);
        payMethodBtn_3->setStyleSheet(QStringLiteral(""));
        payMethodBtn_2 = new StatementMethodButton(widget_2);
        payMethodBtn_2->setObjectName(QStringLiteral("payMethodBtn_2"));
        payMethodBtn_2->setGeometry(QRect(71, 14, 55, 35));
        payMethodBtn_2->setMinimumSize(QSize(55, 35));
        payMethodBtn_2->setMaximumSize(QSize(16777215, 16777215));
        payMethodBtn_2->setFont(font1);
        payMethodBtn_2->setFocusPolicy(Qt::NoFocus);
        payMethodBtn_2->setStyleSheet(QStringLiteral(""));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(14, 47, 285, 212));
        widget_4->setMinimumSize(QSize(285, 212));
        widget_4->setMaximumSize(QSize(16777215, 16777215));
        widget_4->setFont(font);
        widget_4->setStyleSheet(QLatin1String("QWidget#widget_4 {\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        id_line_2 = new QFrame(widget_4);
        id_line_2->setObjectName(QStringLiteral("id_line_2"));
        id_line_2->setGeometry(QRect(0, 83, 285, 2));
        id_line_2->setMinimumSize(QSize(285, 2));
        id_line_2->setMaximumSize(QSize(16777215, 2));
        id_line_2->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));
        id_line_2->setFrameShape(QFrame::HLine);
        id_line_2->setFrameShadow(QFrame::Sunken);
        discountLabel = new QLabel(widget_4);
        discountLabel->setObjectName(QStringLiteral("discountLabel"));
        discountLabel->setGeometry(QRect(20, 50, 41, 30));
        discountLabel->setFont(font);
        discountLabel->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        simpleAmtLabel = new QLabel(widget_4);
        simpleAmtLabel->setObjectName(QStringLiteral("simpleAmtLabel"));
        simpleAmtLabel->setGeometry(QRect(20, 86, 100, 40));
        simpleAmtLabel->setFont(font);
        simpleAmtLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"font-size:14px;"));
        samllChangeButton = new QPushButton(widget_4);
        samllChangeButton->setObjectName(QStringLiteral("samllChangeButton"));
        samllChangeButton->setGeometry(QRect(18, 10, 115, 25));
        samllChangeButton->setMinimumSize(QSize(115, 25));
        QFont font2;
        samllChangeButton->setFont(font2);
        samllChangeButton->setFocusPolicy(Qt::NoFocus);
        samllChangeButton->setStyleSheet(QLatin1String("QPushButton#samllChangeButton {\n"
"	font-size:12px;\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/statementImage/samll_change_normal.png);\n"
"}\n"
"\n"
"QPushButton#samllChangeButton:pressed {\n"
"	border-image: url(:/statementImage/samll_change_press.png);\n"
"}"));
        simpleAmtValueLabel = new QLabel(widget_4);
        simpleAmtValueLabel->setObjectName(QStringLiteral("simpleAmtValueLabel"));
        simpleAmtValueLabel->setGeometry(QRect(129, 86, 137, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        simpleAmtValueLabel->setFont(font3);
        simpleAmtValueLabel->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-size:18px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        simpleAmtValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        amtPaidValueLabel = new QLabel(widget_4);
        amtPaidValueLabel->setObjectName(QStringLiteral("amtPaidValueLabel"));
        amtPaidValueLabel->setGeometry(QRect(129, 120, 137, 40));
        amtPaidValueLabel->setFont(font3);
        amtPaidValueLabel->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font-size:18px;\n"
"font: bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        amtPaidValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        discountValueLabel = new QLabel(widget_4);
        discountValueLabel->setObjectName(QStringLiteral("discountValueLabel"));
        discountValueLabel->setGeometry(QRect(60, 50, 41, 30));
        discountValueLabel->setFont(font3);
        discountValueLabel->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font-size:12px;\n"
"font: bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        id_line_1 = new QFrame(widget_4);
        id_line_1->setObjectName(QStringLiteral("id_line_1"));
        id_line_1->setGeometry(QRect(0, 45, 285, 2));
        id_line_1->setMinimumSize(QSize(285, 2));
        id_line_1->setMaximumSize(QSize(16777215, 2));
        id_line_1->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));
        id_line_1->setFrameShape(QFrame::HLine);
        id_line_1->setFrameShadow(QFrame::Sunken);
        disAmtLabel = new QLabel(widget_4);
        disAmtLabel->setObjectName(QStringLiteral("disAmtLabel"));
        disAmtLabel->setGeometry(QRect(110, 50, 71, 30));
        disAmtLabel->setFont(font);
        disAmtLabel->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        disAmtValueLabel = new QLabel(widget_4);
        disAmtValueLabel->setObjectName(QStringLiteral("disAmtValueLabel"));
        disAmtValueLabel->setGeometry(QRect(170, 50, 54, 30));
        disAmtValueLabel->setFont(font3);
        disAmtValueLabel->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font-size:12px;\n"
"font: bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        paymentDetailButton = new QPushButton(widget_4);
        paymentDetailButton->setObjectName(QStringLiteral("paymentDetailButton"));
        paymentDetailButton->setGeometry(QRect(148, 10, 115, 25));
        paymentDetailButton->setMinimumSize(QSize(115, 25));
        paymentDetailButton->setFont(font2);
        paymentDetailButton->setFocusPolicy(Qt::NoFocus);
        paymentDetailButton->setStyleSheet(QLatin1String("QPushButton#paymentDetailButton {\n"
"	font-size:12px;\n"
"	color: rgb(153, 153, 153);\n"
"	border-image: url(:/statementImage/pay_details_normal.png);\n"
"}\n"
"\n"
"QPushButton#paymentDetailButton:pressed {\n"
"	border-image: url(:/statementImage/pay_details_press.png);\n"
"}"));
        amtPaidLabel = new QLabel(widget_4);
        amtPaidLabel->setObjectName(QStringLiteral("amtPaidLabel"));
        amtPaidLabel->setGeometry(QRect(20, 120, 100, 40));
        amtPaidLabel->setFont(font);
        amtPaidLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"font-size:14px;"));
        receivedValueLabel = new QLabel(widget_4);
        receivedValueLabel->setObjectName(QStringLiteral("receivedValueLabel"));
        receivedValueLabel->setGeometry(QRect(130, 166, 137, 40));
        receivedValueLabel->setFont(font3);
        receivedValueLabel->setStyleSheet(QString::fromUtf8("color: rgb(234, 136, 82);\n"
"font-size:22px;\n"
"font: bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        receivedValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        amtReceivedLabel = new QLabel(widget_4);
        amtReceivedLabel->setObjectName(QStringLiteral("amtReceivedLabel"));
        amtReceivedLabel->setGeometry(QRect(20, 166, 100, 40));
        amtReceivedLabel->setFont(font);
        amtReceivedLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"font-size:14px;"));
        id_line_3 = new QFrame(widget_4);
        id_line_3->setObjectName(QStringLiteral("id_line_3"));
        id_line_3->setGeometry(QRect(0, 160, 285, 2));
        id_line_3->setMinimumSize(QSize(0, 2));
        id_line_3->setMaximumSize(QSize(16777215, 2));
        id_line_3->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));
        id_line_3->setFrameShape(QFrame::HLine);
        id_line_3->setFrameShadow(QFrame::Sunken);
        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(14, 261, 285, 230));
        stackedWidget->setMinimumSize(QSize(285, 129));
        stackedWidget->setStyleSheet(QLatin1String("QWidget#storeCardWidget {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        cashWidget = new QWidget();
        cashWidget->setObjectName(QStringLiteral("cashWidget"));
        widget_3 = new QWidget(cashWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 285, 129));
        widget_3->setMinimumSize(QSize(285, 129));
        widget_3->setFont(font);
        widget_3->setStyleSheet(QLatin1String("QWidget#widget_3 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        statementButton = new QPushButton(widget_3);
        statementButton->setObjectName(QStringLiteral("statementButton"));
        statementButton->setGeometry(QRect(18, 73, 245, 42));
        statementButton->setFont(font2);
        statementButton->setFocusPolicy(Qt::NoFocus);
        statementButton->setStyleSheet(QLatin1String("QPushButton#statementButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        factAmtCashLabel = new QLabel(widget_3);
        factAmtCashLabel->setObjectName(QStringLiteral("factAmtCashLabel"));
        factAmtCashLabel->setGeometry(QRect(18, 21, 72, 31));
        factAmtCashLabel->setFont(font);
        factAmtCashLabel->setStyleSheet(QString::fromUtf8("QLabel#factAmtCashLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        factAmtCashEdit = new QLineEdit(widget_3);
        factAmtCashEdit->setObjectName(QStringLiteral("factAmtCashEdit"));
        factAmtCashEdit->setGeometry(QRect(93, 21, 168, 31));
        factAmtCashEdit->setFont(font2);
        factAmtCashEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        stackedWidget->addWidget(cashWidget);
        memCardWidget = new QWidget();
        memCardWidget->setObjectName(QStringLiteral("memCardWidget"));
        widget_5 = new QWidget(memCardWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 285, 71));
        widget_5->setMinimumSize(QSize(285, 0));
        widget_5->setStyleSheet(QLatin1String("background-color: rgb(250, 250, 250)\n"
""));
        line_2 = new QFrame(widget_5);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 36, 285, 2));
        line_2->setMinimumSize(QSize(0, 2));
        line_2->setMaximumSize(QSize(16777215, 2));
        line_2->setStyleSheet(QLatin1String("Line#line_2 {\n"
"	border-color: rgb(237, 237, 237);\n"
"}"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        id_lab_integ_value = new QLabel(widget_5);
        id_lab_integ_value->setObjectName(QStringLiteral("id_lab_integ_value"));
        id_lab_integ_value->setGeometry(QRect(60, 37, 31, 33));
        id_lab_integ_value->setFont(font2);
        id_lab_integ_value->setStyleSheet(QLatin1String("font-size:12px;\n"
"color:rgb(51, 51, 51)"));
        id_lab_integ = new QLabel(widget_5);
        id_lab_integ->setObjectName(QStringLiteral("id_lab_integ"));
        id_lab_integ->setGeometry(QRect(20, 37, 31, 33));
        id_lab_integ->setFont(font2);
        id_lab_integ->setStyleSheet(QLatin1String("QLabel#id_lab_integ {\n"
"	font-size:12px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        id_lab_can_arrived_value = new QLabel(widget_5);
        id_lab_can_arrived_value->setObjectName(QStringLiteral("id_lab_can_arrived_value"));
        id_lab_can_arrived_value->setGeometry(QRect(200, 37, 61, 33));
        id_lab_can_arrived_value->setFont(font2);
        id_lab_can_arrived_value->setStyleSheet(QLatin1String("QLabel#id_lab_can_arrived_value {\n"
"	font-size:12px;\n"
"	color: rgb(244, 132, 69);\n"
"}"));
        id_lab_can_arrived_value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        id_lab_mem_card = new QLabel(widget_5);
        id_lab_mem_card->setObjectName(QStringLiteral("id_lab_mem_card"));
        id_lab_mem_card->setGeometry(QRect(20, 0, 91, 35));
        id_lab_mem_card->setFont(font2);
        id_lab_mem_card->setStyleSheet(QLatin1String("QLabel#id_lab_mem_card {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        id_lab_mem_card_value = new QLabel(widget_5);
        id_lab_mem_card_value->setObjectName(QStringLiteral("id_lab_mem_card_value"));
        id_lab_mem_card_value->setGeometry(QRect(160, 0, 101, 35));
        id_lab_mem_card_value->setFont(font2);
        id_lab_mem_card_value->setStyleSheet(QLatin1String("QLabel#id_lab_mem_card_value {\n"
"	font-size:18px;\n"
"	color: rgb(244, 132, 69);\n"
"}"));
        id_lab_mem_card_value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        id_lab_can_arrived = new QLabel(widget_5);
        id_lab_can_arrived->setObjectName(QStringLiteral("id_lab_can_arrived"));
        id_lab_can_arrived->setGeometry(QRect(130, 37, 71, 33));
        id_lab_can_arrived->setFont(font2);
        id_lab_can_arrived->setStyleSheet(QLatin1String("font-size:12px;\n"
"color: rgb(51, 51, 51);"));
        id_lab_can_arrived->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        widget_6 = new QWidget(memCardWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 71, 285, 161));
        widget_6->setMinimumSize(QSize(285, 0));
        widget_6->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        arrivedMemLabel = new QLabel(widget_6);
        arrivedMemLabel->setObjectName(QStringLiteral("arrivedMemLabel"));
        arrivedMemLabel->setGeometry(QRect(170, 56, 41, 31));
        arrivedMemLabel->setFont(font2);
        arrivedMemLabel->setStyleSheet(QLatin1String("QLabel#arrivedMemLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        balanceMemLabel = new QLabel(widget_6);
        balanceMemLabel->setObjectName(QStringLiteral("balanceMemLabel"));
        balanceMemLabel->setGeometry(QRect(20, 15, 71, 31));
        balanceMemLabel->setFont(font2);
        balanceMemLabel->setStyleSheet(QLatin1String("QLabel#balanceMemLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        statementMemButton = new QPushButton(widget_6);
        statementMemButton->setObjectName(QStringLiteral("statementMemButton"));
        statementMemButton->setGeometry(QRect(23, 100, 245, 42));
        statementMemButton->setMinimumSize(QSize(245, 42));
        statementMemButton->setFont(font2);
        statementMemButton->setFocusPolicy(Qt::NoFocus);
        statementMemButton->setStyleSheet(QLatin1String("QPushButton#statementMemButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementMemButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        arrivedValueLabel = new QLabel(widget_6);
        arrivedValueLabel->setObjectName(QStringLiteral("arrivedValueLabel"));
        arrivedValueLabel->setGeometry(QRect(215, 56, 50, 31));
        arrivedValueLabel->setFont(font2);
        arrivedValueLabel->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);"));
        integUseMemLabel = new QLabel(widget_6);
        integUseMemLabel->setObjectName(QStringLiteral("integUseMemLabel"));
        integUseMemLabel->setGeometry(QRect(20, 56, 71, 31));
        integUseMemLabel->setFont(font2);
        integUseMemLabel->setStyleSheet(QLatin1String("QLabel#integUseMemLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        balanceMemEdit = new QLineEdit(widget_6);
        balanceMemEdit->setObjectName(QStringLiteral("balanceMemEdit"));
        balanceMemEdit->setGeometry(QRect(90, 15, 178, 31));
        balanceMemEdit->setFont(font2);
        balanceMemEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        integUseMemEdit = new QLineEdit(widget_6);
        integUseMemEdit->setObjectName(QStringLiteral("integUseMemEdit"));
        integUseMemEdit->setGeometry(QRect(90, 56, 61, 31));
        integUseMemEdit->setFont(font2);
        integUseMemEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        memWarningLabel = new QLabel(widget_6);
        memWarningLabel->setObjectName(QStringLiteral("memWarningLabel"));
        memWarningLabel->setGeometry(QRect(23, 90, 245, 16));
        memWarningLabel->setStyleSheet(QStringLiteral("color: rgb(250, 122, 122);"));
        stackedWidget->addWidget(memCardWidget);
        storeCardWidget = new QWidget();
        storeCardWidget->setObjectName(QStringLiteral("storeCardWidget"));
        warningStoreLabel = new QLabel(storeCardWidget);
        warningStoreLabel->setObjectName(QStringLiteral("warningStoreLabel"));
        warningStoreLabel->setGeometry(QRect(100, 0, 161, 12));
        warningStoreLabel->setMinimumSize(QSize(0, 12));
        warningStoreLabel->setFont(font);
        warningStoreLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:10px;\n"
"color: rgb(250, 122, 122);"));
        statementStoreButton = new QPushButton(storeCardWidget);
        statementStoreButton->setObjectName(QStringLiteral("statementStoreButton"));
        statementStoreButton->setGeometry(QRect(10, 175, 261, 42));
        statementStoreButton->setMinimumSize(QSize(118, 42));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        statementStoreButton->setFont(font4);
        statementStoreButton->setFocusPolicy(Qt::NoFocus);
        statementStoreButton->setStyleSheet(QLatin1String("QPushButton#statementStoreButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementStoreButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        cardIDStoreLabel = new QLabel(storeCardWidget);
        cardIDStoreLabel->setObjectName(QStringLiteral("cardIDStoreLabel"));
        cardIDStoreLabel->setGeometry(QRect(10, 30, 81, 31));
        cardIDStoreLabel->setFont(font);
        cardIDStoreLabel->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color: rgb(51, 51, 51);\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        cardIDStoreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        useAmtStoreEdit = new QLineEdit(storeCardWidget);
        useAmtStoreEdit->setObjectName(QStringLiteral("useAmtStoreEdit"));
        useAmtStoreEdit->setGeometry(QRect(100, 137, 168, 31));
        useAmtStoreEdit->setMinimumSize(QSize(168, 31));
        useAmtStoreEdit->setFont(font);
        useAmtStoreEdit->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        cardIDStoreEdit = new QLineEdit(storeCardWidget);
        cardIDStoreEdit->setObjectName(QStringLiteral("cardIDStoreEdit"));
        cardIDStoreEdit->setGeometry(QRect(100, 30, 168, 31));
        cardIDStoreEdit->setMinimumSize(QSize(168, 31));
        cardIDStoreEdit->setFont(font);
        cardIDStoreEdit->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        useAmtStoreLabel = new QLabel(storeCardWidget);
        useAmtStoreLabel->setObjectName(QStringLiteral("useAmtStoreLabel"));
        useAmtStoreLabel->setGeometry(QRect(10, 137, 81, 31));
        useAmtStoreLabel->setFont(font);
        useAmtStoreLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(51, 51, 51);"));
        useAmtStoreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        currentAmtStoreLabel = new QLabel(storeCardWidget);
        currentAmtStoreLabel->setObjectName(QStringLiteral("currentAmtStoreLabel"));
        currentAmtStoreLabel->setGeometry(QRect(10, 80, 81, 31));
        currentAmtStoreLabel->setFont(font);
        currentAmtStoreLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(51, 51, 51);"));
        currentAmtStoreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        currentAmtStoreEdit = new QLineEdit(storeCardWidget);
        currentAmtStoreEdit->setObjectName(QStringLiteral("currentAmtStoreEdit"));
        currentAmtStoreEdit->setGeometry(QRect(100, 80, 168, 31));
        currentAmtStoreEdit->setMinimumSize(QSize(168, 31));
        currentAmtStoreEdit->setFont(font);
        currentAmtStoreEdit->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        currentAmtStoreEdit->setReadOnly(true);
        stackedWidget->addWidget(storeCardWidget);
        alipayWidget = new QWidget();
        alipayWidget->setObjectName(QStringLiteral("alipayWidget"));
        widget_7 = new QWidget(alipayWidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(0, 0, 285, 129));
        widget_7->setMinimumSize(QSize(285, 129));
        widget_7->setStyleSheet(QLatin1String("QWidget#widget_7 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        statementAlipayButton = new QPushButton(widget_7);
        statementAlipayButton->setObjectName(QStringLiteral("statementAlipayButton"));
        statementAlipayButton->setGeometry(QRect(18, 73, 245, 42));
        statementAlipayButton->setFont(font2);
        statementAlipayButton->setFocusPolicy(Qt::NoFocus);
        statementAlipayButton->setStyleSheet(QLatin1String("QPushButton#statementAlipayButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementAlipayButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        factAmtAlipayLabel = new QLabel(widget_7);
        factAmtAlipayLabel->setObjectName(QStringLiteral("factAmtAlipayLabel"));
        factAmtAlipayLabel->setGeometry(QRect(18, 21, 72, 31));
        factAmtAlipayLabel->setFont(font);
        factAmtAlipayLabel->setStyleSheet(QString::fromUtf8("QLabel#factAmtAlipayLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        factAmtAlipayEdit = new QLineEdit(widget_7);
        factAmtAlipayEdit->setObjectName(QStringLiteral("factAmtAlipayEdit"));
        factAmtAlipayEdit->setGeometry(QRect(93, 21, 168, 31));
        factAmtAlipayEdit->setFont(font2);
        factAmtAlipayEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        stackedWidget->addWidget(alipayWidget);
        wechartPayWidget = new QWidget();
        wechartPayWidget->setObjectName(QStringLiteral("wechartPayWidget"));
        widget_9 = new QWidget(wechartPayWidget);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setGeometry(QRect(0, 0, 285, 129));
        widget_9->setMinimumSize(QSize(285, 129));
        widget_9->setStyleSheet(QLatin1String("QWidget#widget_9 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        statementWeButton = new QPushButton(widget_9);
        statementWeButton->setObjectName(QStringLiteral("statementWeButton"));
        statementWeButton->setGeometry(QRect(18, 73, 245, 42));
        statementWeButton->setMinimumSize(QSize(245, 42));
        statementWeButton->setFont(font2);
        statementWeButton->setFocusPolicy(Qt::NoFocus);
        statementWeButton->setStyleSheet(QLatin1String("QPushButton#statementWeButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementWeButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        factAmtWeLabel = new QLabel(widget_9);
        factAmtWeLabel->setObjectName(QStringLiteral("factAmtWeLabel"));
        factAmtWeLabel->setGeometry(QRect(18, 21, 72, 31));
        factAmtWeLabel->setMinimumSize(QSize(0, 31));
        factAmtWeLabel->setFont(font);
        factAmtWeLabel->setStyleSheet(QString::fromUtf8("QLabel#factAmtWeLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        factAmtWeEdit = new QLineEdit(widget_9);
        factAmtWeEdit->setObjectName(QStringLiteral("factAmtWeEdit"));
        factAmtWeEdit->setGeometry(QRect(93, 21, 168, 31));
        factAmtWeEdit->setMinimumSize(QSize(168, 31));
        factAmtWeEdit->setFont(font2);
        factAmtWeEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        stackedWidget->addWidget(wechartPayWidget);
        applePayWidget = new QWidget();
        applePayWidget->setObjectName(QStringLiteral("applePayWidget"));
        widget_10 = new QWidget(applePayWidget);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setGeometry(QRect(0, 0, 285, 129));
        widget_10->setMinimumSize(QSize(285, 129));
        widget_10->setStyleSheet(QLatin1String("QWidget#widget_10 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        statementAppleButton = new QPushButton(widget_10);
        statementAppleButton->setObjectName(QStringLiteral("statementAppleButton"));
        statementAppleButton->setGeometry(QRect(18, 73, 245, 42));
        statementAppleButton->setFont(font2);
        statementAppleButton->setFocusPolicy(Qt::NoFocus);
        statementAppleButton->setStyleSheet(QLatin1String("QPushButton#statementAppleButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementAppleButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        factAmtAppleLabel = new QLabel(widget_10);
        factAmtAppleLabel->setObjectName(QStringLiteral("factAmtAppleLabel"));
        factAmtAppleLabel->setGeometry(QRect(18, 21, 71, 31));
        factAmtAppleLabel->setFont(font2);
        factAmtAppleLabel->setStyleSheet(QLatin1String("QLabel#factAmtAppleLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        factAmtAppleEdit = new QLineEdit(widget_10);
        factAmtAppleEdit->setObjectName(QStringLiteral("factAmtAppleEdit"));
        factAmtAppleEdit->setGeometry(QRect(93, 21, 168, 31));
        factAmtAppleEdit->setFont(font2);
        factAmtAppleEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color:rgb(102, 102, 102);\n"
"padding-left:10px;"));
        stackedWidget->addWidget(applePayWidget);
        jdWalletWidget = new QWidget();
        jdWalletWidget->setObjectName(QStringLiteral("jdWalletWidget"));
        widget_11 = new QWidget(jdWalletWidget);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setGeometry(QRect(0, 0, 285, 129));
        widget_11->setMinimumSize(QSize(285, 129));
        widget_11->setStyleSheet(QLatin1String("QWidget#widget_11 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        statementJdButton = new QPushButton(widget_11);
        statementJdButton->setObjectName(QStringLiteral("statementJdButton"));
        statementJdButton->setGeometry(QRect(18, 73, 245, 42));
        statementJdButton->setFont(font2);
        statementJdButton->setFocusPolicy(Qt::NoFocus);
        statementJdButton->setStyleSheet(QLatin1String("QPushButton#statementJdButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementJdButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        factAmtJdLabel = new QLabel(widget_11);
        factAmtJdLabel->setObjectName(QStringLiteral("factAmtJdLabel"));
        factAmtJdLabel->setGeometry(QRect(18, 21, 72, 31));
        factAmtJdLabel->setFont(font2);
        factAmtJdLabel->setStyleSheet(QLatin1String("QLabel#factAmtJdLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        factAmtJdEdit = new QLineEdit(widget_11);
        factAmtJdEdit->setObjectName(QStringLiteral("factAmtJdEdit"));
        factAmtJdEdit->setGeometry(QRect(93, 21, 168, 31));
        factAmtJdEdit->setFont(font2);
        factAmtJdEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        stackedWidget->addWidget(jdWalletWidget);
        CouponWidget = new QWidget();
        CouponWidget->setObjectName(QStringLiteral("CouponWidget"));
        widget_12 = new QWidget(CouponWidget);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setGeometry(QRect(0, 0, 285, 171));
        widget_12->setMinimumSize(QSize(285, 129));
        widget_12->setStyleSheet(QLatin1String("QWidget#widget_12 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        statementCouponButton = new QPushButton(widget_12);
        statementCouponButton->setObjectName(QStringLiteral("statementCouponButton"));
        statementCouponButton->setGeometry(QRect(18, 110, 245, 42));
        statementCouponButton->setFont(font2);
        statementCouponButton->setFocusPolicy(Qt::NoFocus);
        statementCouponButton->setStyleSheet(QLatin1String("QPushButton#statementCouponButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementCouponButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        factAmtCouponLabel_1 = new QLabel(widget_12);
        factAmtCouponLabel_1->setObjectName(QStringLiteral("factAmtCouponLabel_1"));
        factAmtCouponLabel_1->setGeometry(QRect(18, 21, 72, 31));
        factAmtCouponLabel_1->setFont(font2);
        factAmtCouponLabel_1->setStyleSheet(QLatin1String("QLabel#factAmtCouponLabel_1 {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        factAmtCouponLabel_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        factAmtCouponEdit_1 = new QLineEdit(widget_12);
        factAmtCouponEdit_1->setObjectName(QStringLiteral("factAmtCouponEdit_1"));
        factAmtCouponEdit_1->setGeometry(QRect(93, 21, 168, 31));
        factAmtCouponEdit_1->setFont(font2);
        factAmtCouponEdit_1->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        factAmtCouponEdit_2 = new QLineEdit(widget_12);
        factAmtCouponEdit_2->setObjectName(QStringLiteral("factAmtCouponEdit_2"));
        factAmtCouponEdit_2->setGeometry(QRect(95, 60, 168, 31));
        factAmtCouponEdit_2->setFont(font2);
        factAmtCouponEdit_2->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        factAmtCouponEdit_2->setDragEnabled(true);
        factAmtCouponLabel_2 = new QLabel(widget_12);
        factAmtCouponLabel_2->setObjectName(QStringLiteral("factAmtCouponLabel_2"));
        factAmtCouponLabel_2->setGeometry(QRect(20, 60, 72, 31));
        factAmtCouponLabel_2->setFont(font2);
        factAmtCouponLabel_2->setStyleSheet(QLatin1String("QLabel#factAmtCouponLabel_2 {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        factAmtCouponLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        factAmtCouponLabel_3 = new QLabel(widget_12);
        factAmtCouponLabel_3->setObjectName(QStringLiteral("factAmtCouponLabel_3"));
        factAmtCouponLabel_3->setGeometry(QRect(100, 95, 161, 16));
        factAmtCouponLabel_3->setStyleSheet(QStringLiteral("color:red"));
        stackedWidget->addWidget(CouponWidget);
        unionPayWidget = new QWidget();
        unionPayWidget->setObjectName(QStringLiteral("unionPayWidget"));
        unionPayWidget->setStyleSheet(QLatin1String("QWidget#widget_13 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        widget_13 = new QWidget(unionPayWidget);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        widget_13->setGeometry(QRect(0, 0, 285, 129));
        widget_13->setStyleSheet(QLatin1String("QWidget#widget_12 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        factAmtUnionEdit = new QLineEdit(widget_13);
        factAmtUnionEdit->setObjectName(QStringLiteral("factAmtUnionEdit"));
        factAmtUnionEdit->setGeometry(QRect(93, 21, 168, 31));
        factAmtUnionEdit->setFont(font2);
        factAmtUnionEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        statementUnionButton = new QPushButton(widget_13);
        statementUnionButton->setObjectName(QStringLiteral("statementUnionButton"));
        statementUnionButton->setGeometry(QRect(18, 73, 245, 42));
        statementUnionButton->setFont(font2);
        statementUnionButton->setFocusPolicy(Qt::NoFocus);
        statementUnionButton->setStyleSheet(QLatin1String("QPushButton#statementUnionButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementUnionButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        factAmtUnionLabel = new QLabel(widget_13);
        factAmtUnionLabel->setObjectName(QStringLiteral("factAmtUnionLabel"));
        factAmtUnionLabel->setGeometry(QRect(18, 21, 72, 31));
        factAmtUnionLabel->setFont(font2);
        factAmtUnionLabel->setStyleSheet(QLatin1String("QLabel#factAmtJdLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        stackedWidget->addWidget(unionPayWidget);
        virtualPayWidget = new VirtualPayWidget();
        virtualPayWidget->setObjectName(QStringLiteral("virtualPayWidget"));
        stackedWidget->addWidget(virtualPayWidget);
        virtualPaysPage = new VirtualPaysWidget();
        virtualPaysPage->setObjectName(QStringLiteral("virtualPaysPage"));
        stackedWidget->addWidget(virtualPaysPage);
        line_3 = new QFrame(widget_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(14, 259, 285, 2));
        line_3->setMinimumSize(QSize(285, 2));
        line_3->setStyleSheet(QLatin1String("Line#line_3 {\n"
"	border: 1px solid #ededed;\n"
"}"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        widget_8 = new QWidget(widget);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(314, 0, 413, 504));
        widget_8->setMinimumSize(QSize(413, 504));
        gridLayout = new QGridLayout(widget_8);
        gridLayout->setSpacing(7);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(15, 12, 15, 190);
        factorButton = new QPushButton(widget_8);
        factorButton->setObjectName(QStringLiteral("factorButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(factorButton->sizePolicy().hasHeightForWidth());
        factorButton->setSizePolicy(sizePolicy);
        factorButton->setMinimumSize(QSize(76, 72));
        factorButton->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        factorButton->setFont(font5);
        factorButton->setFocusPolicy(Qt::NoFocus);
        factorButton->setStyleSheet(QString::fromUtf8("QPushButton#factorButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#factorButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        gridLayout->addWidget(factorButton, 0, 0, 1, 1);

        fiftyButton = new QPushButton(widget_8);
        fiftyButton->setObjectName(QStringLiteral("fiftyButton"));
        sizePolicy.setHeightForWidth(fiftyButton->sizePolicy().hasHeightForWidth());
        fiftyButton->setSizePolicy(sizePolicy);
        fiftyButton->setMinimumSize(QSize(76, 72));
        fiftyButton->setMaximumSize(QSize(16777215, 16777215));
        fiftyButton->setFont(font5);
        fiftyButton->setFocusPolicy(Qt::NoFocus);
        fiftyButton->setStyleSheet(QString::fromUtf8("QPushButton#fiftyButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#fiftyButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        gridLayout->addWidget(fiftyButton, 1, 0, 1, 1);

        hundredButton = new QPushButton(widget_8);
        hundredButton->setObjectName(QStringLiteral("hundredButton"));
        sizePolicy.setHeightForWidth(hundredButton->sizePolicy().hasHeightForWidth());
        hundredButton->setSizePolicy(sizePolicy);
        hundredButton->setMinimumSize(QSize(76, 72));
        hundredButton->setMaximumSize(QSize(16777215, 16777215));
        hundredButton->setFont(font5);
        hundredButton->setFocusPolicy(Qt::NoFocus);
        hundredButton->setStyleSheet(QString::fromUtf8("QPushButton#hundredButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#hundredButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        gridLayout->addWidget(hundredButton, 2, 0, 1, 1);

        twoHundredButton = new QPushButton(widget_8);
        twoHundredButton->setObjectName(QStringLiteral("twoHundredButton"));
        sizePolicy.setHeightForWidth(twoHundredButton->sizePolicy().hasHeightForWidth());
        twoHundredButton->setSizePolicy(sizePolicy);
        twoHundredButton->setMinimumSize(QSize(76, 72));
        twoHundredButton->setMaximumSize(QSize(16777215, 16777215));
        twoHundredButton->setFont(font5);
        twoHundredButton->setFocusPolicy(Qt::NoFocus);
        twoHundredButton->setStyleSheet(QString::fromUtf8("QPushButton#twoHundredButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#twoHundredButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        gridLayout->addWidget(twoHundredButton, 3, 0, 1, 1);

        DigitalKeyWnd = new WndDigitalKeyboard(widget_8);
        DigitalKeyWnd->setObjectName(QStringLiteral("DigitalKeyWnd"));
        DigitalKeyWnd->setMinimumSize(QSize(303, 303));

        gridLayout->addWidget(DigitalKeyWnd, 0, 1, 4, 1);

        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(314, 0, 2, 504));
        line->setMinimumSize(QSize(2, 504));
        line->setMaximumSize(QSize(2, 16777215));
        line->setStyleSheet(QStringLiteral("background-color: rgb(102, 102, 102);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        titleWidget = new TitleBarWidget(StatementDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setGeometry(QRect(0, 0, 728, 40));
        titleWidget->setMinimumSize(QSize(728, 40));
        titleWidget->setMaximumSize(QSize(16777215, 40));
        titleWidget->setStyleSheet(QStringLiteral(""));

        retranslateUi(StatementDlg);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(StatementDlg);
    } // setupUi

    void retranslateUi(QDialog *StatementDlg)
    {
        StatementDlg->setWindowTitle(QApplication::translate("StatementDlg", "StatementDlg", Q_NULLPTR));
        payMethodBtn_1->setText(QApplication::translate("StatementDlg", "\347\216\260\351\207\221", Q_NULLPTR));
        payMethodBtn_4->setText(QApplication::translate("StatementDlg", "\346\224\257\344\273\230\345\256\235", Q_NULLPTR));
        payMethodBtn_5->setText(QString());
        payMethodBtn_3->setText(QApplication::translate("StatementDlg", "\345\202\250\345\200\274\345\215\241", Q_NULLPTR));
        payMethodBtn_2->setText(QApplication::translate("StatementDlg", "\344\274\232\345\221\230\345\215\241", Q_NULLPTR));
        discountLabel->setText(QApplication::translate("StatementDlg", "\346\212\230\346\211\243\357\274\232", Q_NULLPTR));
        simpleAmtLabel->setText(QApplication::translate("StatementDlg", "\346\225\264\345\215\225\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        samllChangeButton->setText(QApplication::translate("StatementDlg", "\346\212\271\351\233\266", Q_NULLPTR));
        simpleAmtValueLabel->setText(QApplication::translate("StatementDlg", "\357\277\24537.02", Q_NULLPTR));
        amtPaidValueLabel->setText(QApplication::translate("StatementDlg", "\357\277\24510.00", Q_NULLPTR));
        discountValueLabel->setText(QApplication::translate("StatementDlg", "9\346\212\230", Q_NULLPTR));
        disAmtLabel->setText(QApplication::translate("StatementDlg", "\344\274\230\346\203\240\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        disAmtValueLabel->setText(QApplication::translate("StatementDlg", "\357\277\2453.70", Q_NULLPTR));
        paymentDetailButton->setText(QApplication::translate("StatementDlg", "\346\224\257\344\273\230\350\257\246\346\203\205(0/0)", Q_NULLPTR));
        amtPaidLabel->setText(QApplication::translate("StatementDlg", "\345\267\262\344\273\230\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        receivedValueLabel->setText(QApplication::translate("StatementDlg", "\357\277\24527.02", Q_NULLPTR));
        amtReceivedLabel->setText(QApplication::translate("StatementDlg", "\345\276\205\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        statementButton->setText(QApplication::translate("StatementDlg", "\347\273\223\347\256\227", Q_NULLPTR));
        factAmtCashLabel->setText(QApplication::translate("StatementDlg", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        id_lab_integ_value->setText(QApplication::translate("StatementDlg", "20", Q_NULLPTR));
        id_lab_integ->setText(QApplication::translate("StatementDlg", "\347\247\257\345\210\206\357\274\232", Q_NULLPTR));
        id_lab_can_arrived_value->setText(QApplication::translate("StatementDlg", "\357\277\2450.20", Q_NULLPTR));
        id_lab_mem_card->setText(QApplication::translate("StatementDlg", "\344\274\232\345\221\230\345\215\241\344\275\231\351\242\235:", Q_NULLPTR));
        id_lab_mem_card_value->setText(QApplication::translate("StatementDlg", "\357\277\24550.00", Q_NULLPTR));
        id_lab_can_arrived->setText(QApplication::translate("StatementDlg", "\345\217\257\346\212\265\347\216\260\357\274\232", Q_NULLPTR));
        arrivedMemLabel->setText(QApplication::translate("StatementDlg", "\346\212\265\347\216\260\357\274\232", Q_NULLPTR));
        balanceMemLabel->setText(QApplication::translate("StatementDlg", "\344\275\231\351\242\235\344\275\277\347\224\250\357\274\232", Q_NULLPTR));
        statementMemButton->setText(QApplication::translate("StatementDlg", "\347\273\223\347\256\227", Q_NULLPTR));
        arrivedValueLabel->setText(QString());
        integUseMemLabel->setText(QApplication::translate("StatementDlg", "\347\247\257\345\210\206\344\275\277\347\224\250\357\274\232", Q_NULLPTR));
        memWarningLabel->setText(QString());
        warningStoreLabel->setText(QString());
        statementStoreButton->setText(QApplication::translate("StatementDlg", "\347\273\223\347\256\227", Q_NULLPTR));
        cardIDStoreLabel->setText(QApplication::translate("StatementDlg", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        cardIDStoreEdit->setPlaceholderText(QApplication::translate("StatementDlg", "\350\257\267\346\211\253\347\240\201", Q_NULLPTR));
        useAmtStoreLabel->setText(QApplication::translate("StatementDlg", "\344\275\277\347\224\250\357\274\232", Q_NULLPTR));
        currentAmtStoreLabel->setText(QApplication::translate("StatementDlg", "\344\275\231\351\242\235\357\274\232", Q_NULLPTR));
        statementAlipayButton->setText(QApplication::translate("StatementDlg", "\347\273\223\347\256\227", Q_NULLPTR));
        factAmtAlipayLabel->setText(QApplication::translate("StatementDlg", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        statementWeButton->setText(QApplication::translate("StatementDlg", "\347\273\223\347\256\227", Q_NULLPTR));
        factAmtWeLabel->setText(QApplication::translate("StatementDlg", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        statementAppleButton->setText(QApplication::translate("StatementDlg", "\347\273\223\347\256\227", Q_NULLPTR));
        factAmtAppleLabel->setText(QApplication::translate("StatementDlg", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        statementJdButton->setText(QApplication::translate("StatementDlg", "\347\273\223\347\256\227", Q_NULLPTR));
        factAmtJdLabel->setText(QApplication::translate("StatementDlg", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        statementCouponButton->setText(QApplication::translate("StatementDlg", "\347\273\223\347\256\227", Q_NULLPTR));
        factAmtCouponLabel_1->setText(QApplication::translate("StatementDlg", "\345\210\270\345\217\267\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_2->setText(QApplication::translate("StatementDlg", "\344\274\230\346\203\240\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_3->setText(QString());
        statementUnionButton->setText(QApplication::translate("StatementDlg", "\347\273\223\347\256\227", Q_NULLPTR));
        factAmtUnionLabel->setText(QApplication::translate("StatementDlg", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        factorButton->setText(QApplication::translate("StatementDlg", "\345\256\236\351\231\205", Q_NULLPTR));
        fiftyButton->setText(QApplication::translate("StatementDlg", "\357\277\24550", Q_NULLPTR));
        hundredButton->setText(QApplication::translate("StatementDlg", "\357\277\245100", Q_NULLPTR));
        twoHundredButton->setText(QApplication::translate("StatementDlg", "\357\277\245200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StatementDlg: public Ui_StatementDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEMENTDLG_H
