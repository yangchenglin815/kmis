/********************************************************************************
** Form generated from reading UI file 'MemberDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBERDLG_H
#define UI_MEMBERDLG_H

#include <DateLineEdit.h>
#include <PayMethodButton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <ReplaceCardWidget.h>
#include <WndDigitalKeyboard.h>
#include "SearchEdit.h"
#include "TitleBarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MemberDlg
{
public:
    QGridLayout *gridLayout_3;
    TitleBarWidget *titleWidget;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *memRegisterButton;
    QPushButton *modifyPasswdButton;
    QPushButton *memQueryButton;
    QPushButton *memRechargeButton;
    QStackedWidget *stackedWidget;
    QWidget *memQueryWidget;
    QWidget *widget_4;
    QLabel *warningLabel;
    QLineEdit *cardIDQueryEdit;
    QWidget *widget_5;
    QLabel *birthdayQueryLabel;
    QLabel *sexQueryLabel;
    QLabel *birthdayValueQueryLabel;
    QLabel *nameQueryLabel;
    QLabel *sexValueQueryLabel;
    QLabel *nameValueQueryLabel;
    QLabel *cardIDQueryLabel;
    QLabel *cardIDValueQueryLabel;
    QLabel *iphoneValueQueryLabel;
    QLabel *phoneQueryLabel;
    QLabel *payPwdQueryLabel;
    QLabel *payPwdValueQueryLabel;
    QLabel *memGradeQueryLabel;
    QLabel *memGradeValueQueryLabel;
    QWidget *widget_6;
    QLabel *balanceQueryLabel;
    QLabel *integValueQueryLabel;
    QLabel *balanceValueQueryLabel;
    QLabel *integQueryLabel;
    QFrame *line_2;
    QWidget *widget_7;
    QPushButton *memConsumeQueryButton;
    QWidget *memRechargeWidget;
    QWidget *widget_9;
    QLabel *CardIDValueRecLabel;
    QLabel *phoneValueRecLabel;
    QLabel *memNameRecLabel;
    QLabel *phoneRecLabel;
    QLabel *memNameValueRecLabel;
    QLabel *CardIDRecLabel;
    QFrame *line_3;
    QWidget *widget_10;
    QLabel *balanceRecLabel;
    QLabel *balanceValueRecLabel;
    QLabel *integRecLabel;
    QLabel *integValueRecLabel;
    QWidget *widget_11;
    QLabel *amtChargeRecLabel;
    QLabel *payTypeRecLabel;
    PayMethodButton *payRecButton_02;
    PayMethodButton *payRecButton_05;
    PayMethodButton *payRecButton_06;
    PayMethodButton *payRecButton_04;
    QLineEdit *amtChargeRecEdit;
    PayMethodButton *payRecButton_03;
    QComboBox *operatorRecBox;
    QLineEdit *giftAmtRecEdit;
    PayMethodButton *payRecButton_01;
    QLabel *operatorRecLabel;
    QLabel *giftAmtRecLabel;
    QPushButton *rechargeConfireButton;
    QWidget *memRegisterWidget;
    QLabel *payPasswdRegLabel;
    QLabel *nameRegLabel;
    QComboBox *operatorRegBox;
    QLineEdit *phoneRegEdit;
    QPushButton *commitRegButton;
    QLabel *operatorRegLabel;
    QLabel *sexRegLabel;
    QLineEdit *payPasswdRegEdit;
    QLabel *phoneRegLabel;
    QLabel *memGradeRegLabel;
    QComboBox *memGradeRegBox;
    QPushButton *manBtn;
    QPushButton *womanBtn;
    QLabel *warningRegLabel;
    DateLineEdit *birthdayRegEdit;
    QLabel *birthdayRegLabel;
    SearchEdit *nameWidget;
    QWidget *modifyPasswdWidget;
    QWidget *widget_12;
    QLabel *newPasswdPwdLabel;
    QLabel *confirmNewPasswdPwdLabel;
    QLineEdit *newPasswdPwdEdit;
    QPushButton *commitPwdButton;
    QLabel *oldPasswdPwdLabel;
    QLabel *cardIDPwdLabel;
    QLineEdit *oldPasswdPwdEdit;
    QLineEdit *confirmNewpasswdPwdEdit;
    QLabel *pwdModifyWarningLabel;
    QLabel *cardIDValuePwdLabel;
    ReplaceCardWidget *replaceCardWidget;
    QFrame *line;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QPushButton *hundredButton;
    QPushButton *twoHundredButton;
    QPushButton *threeHundredButton;
    QPushButton *fiveHundredButton;
    WndDigitalKeyboard *DigitalKeyWnd;

    void setupUi(QDialog *MemberDlg)
    {
        if (MemberDlg->objectName().isEmpty())
            MemberDlg->setObjectName(QStringLiteral("MemberDlg"));
        MemberDlg->resize(726, 600);
        MemberDlg->setMinimumSize(QSize(726, 600));
        MemberDlg->setStyleSheet(QLatin1String("QDialog#MemberDlg {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        gridLayout_3 = new QGridLayout(MemberDlg);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(MemberDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 40));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(titleWidget, 0, 0, 1, 3);

        widget_2 = new QWidget(MemberDlg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(314, 560));
        widget_2->setMaximumSize(QSize(458, 16777215));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(15, 8, 15, 10);
        memRegisterButton = new QPushButton(widget_2);
        memRegisterButton->setObjectName(QStringLiteral("memRegisterButton"));
        memRegisterButton->setMinimumSize(QSize(71, 33));
        memRegisterButton->setMaximumSize(QSize(16777215, 50));
        memRegisterButton->setFocusPolicy(Qt::NoFocus);
        memRegisterButton->setStyleSheet(QStringLiteral("border-image: url(:/member/tab.png);"));

        gridLayout->addWidget(memRegisterButton, 0, 2, 1, 1);

        modifyPasswdButton = new QPushButton(widget_2);
        modifyPasswdButton->setObjectName(QStringLiteral("modifyPasswdButton"));
        modifyPasswdButton->setMinimumSize(QSize(71, 33));
        modifyPasswdButton->setMaximumSize(QSize(16777215, 50));
        modifyPasswdButton->setFocusPolicy(Qt::NoFocus);
        modifyPasswdButton->setStyleSheet(QStringLiteral("border-image: url(:/member/tab.png);"));

        gridLayout->addWidget(modifyPasswdButton, 0, 3, 1, 2);

        memQueryButton = new QPushButton(widget_2);
        memQueryButton->setObjectName(QStringLiteral("memQueryButton"));
        memQueryButton->setMinimumSize(QSize(71, 33));
        memQueryButton->setMaximumSize(QSize(16777215, 50));
        memQueryButton->setFocusPolicy(Qt::NoFocus);
        memQueryButton->setStyleSheet(QStringLiteral("border-image: url(:/member/tab.png);"));

        gridLayout->addWidget(memQueryButton, 0, 0, 1, 1);

        memRechargeButton = new QPushButton(widget_2);
        memRechargeButton->setObjectName(QStringLiteral("memRechargeButton"));
        memRechargeButton->setMinimumSize(QSize(71, 33));
        memRechargeButton->setMaximumSize(QSize(16777215, 50));
        memRechargeButton->setFocusPolicy(Qt::NoFocus);
        memRechargeButton->setStyleSheet(QStringLiteral("border-image: url(:/member/tab.png);"));

        gridLayout->addWidget(memRechargeButton, 0, 1, 1, 1);

        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(282, 506));
        stackedWidget->setStyleSheet(QLatin1String("QWidget#replaceCardWidget {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        memQueryWidget = new QWidget();
        memQueryWidget->setObjectName(QStringLiteral("memQueryWidget"));
        widget_4 = new QWidget(memQueryWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 0, 282, 94));
        widget_4->setMinimumSize(QSize(282, 94));
        widget_4->setStyleSheet(QLatin1String("QWidget#widget_4 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        warningLabel = new QLabel(widget_4);
        warningLabel->setObjectName(QStringLiteral("warningLabel"));
        warningLabel->setGeometry(QRect(16, 60, 250, 16));
        warningLabel->setMinimumSize(QSize(250, 14));
        warningLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(249, 79, 79);"));
        cardIDQueryEdit = new QLineEdit(widget_4);
        cardIDQueryEdit->setObjectName(QStringLiteral("cardIDQueryEdit"));
        cardIDQueryEdit->setGeometry(QRect(16, 30, 250, 33));
        cardIDQueryEdit->setMinimumSize(QSize(250, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        cardIDQueryEdit->setFont(font);
        cardIDQueryEdit->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-left:10px;\n"
""));
        cardIDQueryEdit->raise();
        warningLabel->raise();
        widget_5 = new QWidget(memQueryWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(0, 90, 282, 228));
        widget_5->setMinimumSize(QSize(282, 228));
        widget_5->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));
        birthdayQueryLabel = new QLabel(widget_5);
        birthdayQueryLabel->setObjectName(QStringLiteral("birthdayQueryLabel"));
        birthdayQueryLabel->setGeometry(QRect(3, 157, 80, 20));
        birthdayQueryLabel->setFont(font);
        birthdayQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        birthdayQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sexQueryLabel = new QLabel(widget_5);
        sexQueryLabel->setObjectName(QStringLiteral("sexQueryLabel"));
        sexQueryLabel->setGeometry(QRect(3, 74, 80, 20));
        sexQueryLabel->setFont(font);
        sexQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        sexQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        birthdayValueQueryLabel = new QLabel(widget_5);
        birthdayValueQueryLabel->setObjectName(QStringLiteral("birthdayValueQueryLabel"));
        birthdayValueQueryLabel->setGeometry(QRect(90, 157, 175, 20));
        birthdayValueQueryLabel->setFont(font);
        birthdayValueQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        nameQueryLabel = new QLabel(widget_5);
        nameQueryLabel->setObjectName(QStringLiteral("nameQueryLabel"));
        nameQueryLabel->setGeometry(QRect(3, 42, 80, 30));
        nameQueryLabel->setFont(font);
        nameQueryLabel->setContextMenuPolicy(Qt::DefaultContextMenu);
        nameQueryLabel->setLayoutDirection(Qt::LeftToRight);
        nameQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        nameQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sexValueQueryLabel = new QLabel(widget_5);
        sexValueQueryLabel->setObjectName(QStringLiteral("sexValueQueryLabel"));
        sexValueQueryLabel->setGeometry(QRect(90, 74, 175, 20));
        sexValueQueryLabel->setFont(font);
        sexValueQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        nameValueQueryLabel = new QLabel(widget_5);
        nameValueQueryLabel->setObjectName(QStringLiteral("nameValueQueryLabel"));
        nameValueQueryLabel->setGeometry(QRect(90, 42, 175, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        nameValueQueryLabel->setFont(font1);
        nameValueQueryLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        cardIDQueryLabel = new QLabel(widget_5);
        cardIDQueryLabel->setObjectName(QStringLiteral("cardIDQueryLabel"));
        cardIDQueryLabel->setGeometry(QRect(3, 20, 80, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cardIDQueryLabel->sizePolicy().hasHeightForWidth());
        cardIDQueryLabel->setSizePolicy(sizePolicy1);
        cardIDQueryLabel->setFont(font);
        cardIDQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        cardIDQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cardIDValueQueryLabel = new QLabel(widget_5);
        cardIDValueQueryLabel->setObjectName(QStringLiteral("cardIDValueQueryLabel"));
        cardIDValueQueryLabel->setGeometry(QRect(90, 20, 121, 20));
        cardIDValueQueryLabel->setFont(font);
        cardIDValueQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        iphoneValueQueryLabel = new QLabel(widget_5);
        iphoneValueQueryLabel->setObjectName(QStringLiteral("iphoneValueQueryLabel"));
        iphoneValueQueryLabel->setGeometry(QRect(90, 103, 175, 20));
        iphoneValueQueryLabel->setFont(font);
        iphoneValueQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        phoneQueryLabel = new QLabel(widget_5);
        phoneQueryLabel->setObjectName(QStringLiteral("phoneQueryLabel"));
        phoneQueryLabel->setGeometry(QRect(0, 103, 80, 20));
        phoneQueryLabel->setFont(font);
        phoneQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        phoneQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        payPwdQueryLabel = new QLabel(widget_5);
        payPwdQueryLabel->setObjectName(QStringLiteral("payPwdQueryLabel"));
        payPwdQueryLabel->setGeometry(QRect(3, 130, 80, 20));
        payPwdQueryLabel->setFont(font);
        payPwdQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        payPwdQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        payPwdValueQueryLabel = new QLabel(widget_5);
        payPwdValueQueryLabel->setObjectName(QStringLiteral("payPwdValueQueryLabel"));
        payPwdValueQueryLabel->setGeometry(QRect(90, 130, 175, 20));
        payPwdValueQueryLabel->setFont(font);
        payPwdValueQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memGradeQueryLabel = new QLabel(widget_5);
        memGradeQueryLabel->setObjectName(QStringLiteral("memGradeQueryLabel"));
        memGradeQueryLabel->setGeometry(QRect(3, 180, 80, 20));
        memGradeQueryLabel->setFont(font);
        memGradeQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memGradeQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        memGradeValueQueryLabel = new QLabel(widget_5);
        memGradeValueQueryLabel->setObjectName(QStringLiteral("memGradeValueQueryLabel"));
        memGradeValueQueryLabel->setGeometry(QRect(90, 180, 175, 20));
        memGradeValueQueryLabel->setFont(font1);
        memGradeValueQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        widget_6 = new QWidget(memQueryWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 318, 282, 84));
        widget_6->setMinimumSize(QSize(282, 84));
        widget_6->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));
        balanceQueryLabel = new QLabel(widget_6);
        balanceQueryLabel->setObjectName(QStringLiteral("balanceQueryLabel"));
        balanceQueryLabel->setGeometry(QRect(3, 10, 60, 30));
        balanceQueryLabel->setFont(font);
        balanceQueryLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        balanceQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        integValueQueryLabel = new QLabel(widget_6);
        integValueQueryLabel->setObjectName(QStringLiteral("integValueQueryLabel"));
        integValueQueryLabel->setGeometry(QRect(90, 43, 175, 30));
        integValueQueryLabel->setFont(font1);
        integValueQueryLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font:bold;\n"
"color: rgb(243, 133, 72);\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        integValueQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        balanceValueQueryLabel = new QLabel(widget_6);
        balanceValueQueryLabel->setObjectName(QStringLiteral("balanceValueQueryLabel"));
        balanceValueQueryLabel->setGeometry(QRect(90, 10, 175, 30));
        balanceValueQueryLabel->setFont(font1);
        balanceValueQueryLabel->setStyleSheet(QString::fromUtf8("font:18px;\n"
"font:bold;\n"
"color: rgb(243, 133, 72);\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        balanceValueQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        integQueryLabel = new QLabel(widget_6);
        integQueryLabel->setObjectName(QStringLiteral("integQueryLabel"));
        integQueryLabel->setGeometry(QRect(3, 43, 60, 30));
        integQueryLabel->setFont(font);
        integQueryLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        integQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_2 = new QFrame(memQueryWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 317, 282, 2));
        line_2->setMinimumSize(QSize(282, 2));
        line_2->setMaximumSize(QSize(16777215, 2));
        line_2->setStyleSheet(QLatin1String("Line#line_2 {\n"
"	border-color: rgb(237, 237, 237);\n"
"}"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget_7 = new QWidget(memQueryWidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(0, 400, 282, 101));
        widget_7->setMinimumSize(QSize(282, 68));
        widget_7->setStyleSheet(QLatin1String("QWidget#widget_7 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        memConsumeQueryButton = new QPushButton(widget_7);
        memConsumeQueryButton->setObjectName(QStringLiteral("memConsumeQueryButton"));
        memConsumeQueryButton->setGeometry(QRect(17, 38, 251, 43));
        memConsumeQueryButton->setMinimumSize(QSize(79, 43));
        memConsumeQueryButton->setFocusPolicy(Qt::NoFocus);
        memConsumeQueryButton->setStyleSheet(QString::fromUtf8("QPushButton#memConsumeQueryButton {\n"
"	font:16px;\n"
"	color: rgb(255, 255, 255);\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#memConsumeQueryButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));
        stackedWidget->addWidget(memQueryWidget);
        widget_5->raise();
        widget_4->raise();
        widget_6->raise();
        line_2->raise();
        widget_7->raise();
        memRechargeWidget = new QWidget();
        memRechargeWidget->setObjectName(QStringLiteral("memRechargeWidget"));
        widget_9 = new QWidget(memRechargeWidget);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setGeometry(QRect(0, 0, 284, 71));
        widget_9->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));
        CardIDValueRecLabel = new QLabel(widget_9);
        CardIDValueRecLabel->setObjectName(QStringLiteral("CardIDValueRecLabel"));
        CardIDValueRecLabel->setGeometry(QRect(70, 15, 91, 20));
        CardIDValueRecLabel->setFont(font);
        CardIDValueRecLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        phoneValueRecLabel = new QLabel(widget_9);
        phoneValueRecLabel->setObjectName(QStringLiteral("phoneValueRecLabel"));
        phoneValueRecLabel->setGeometry(QRect(70, 40, 101, 20));
        phoneValueRecLabel->setFont(font);
        phoneValueRecLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memNameRecLabel = new QLabel(widget_9);
        memNameRecLabel->setObjectName(QStringLiteral("memNameRecLabel"));
        memNameRecLabel->setGeometry(QRect(170, 15, 41, 20));
        memNameRecLabel->setFont(font);
        memNameRecLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memNameRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        phoneRecLabel = new QLabel(widget_9);
        phoneRecLabel->setObjectName(QStringLiteral("phoneRecLabel"));
        phoneRecLabel->setGeometry(QRect(10, 40, 50, 20));
        phoneRecLabel->setFont(font);
        phoneRecLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        phoneRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        memNameValueRecLabel = new QLabel(widget_9);
        memNameValueRecLabel->setObjectName(QStringLiteral("memNameValueRecLabel"));
        memNameValueRecLabel->setGeometry(QRect(210, 15, 61, 20));
        memNameValueRecLabel->setFont(font1);
        memNameValueRecLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memNameValueRecLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        CardIDRecLabel = new QLabel(widget_9);
        CardIDRecLabel->setObjectName(QStringLiteral("CardIDRecLabel"));
        CardIDRecLabel->setGeometry(QRect(10, 15, 50, 20));
        CardIDRecLabel->setFont(font);
        CardIDRecLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        CardIDRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_3 = new QFrame(memRechargeWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 70, 291, 2));
        line_3->setMinimumSize(QSize(0, 2));
        line_3->setMaximumSize(QSize(16777215, 2));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        widget_10 = new QWidget(memRechargeWidget);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setGeometry(QRect(0, 71, 284, 71));
        widget_10->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));
        balanceRecLabel = new QLabel(widget_10);
        balanceRecLabel->setObjectName(QStringLiteral("balanceRecLabel"));
        balanceRecLabel->setGeometry(QRect(10, 7, 50, 30));
        balanceRecLabel->setFont(font);
        balanceRecLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        balanceRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        balanceValueRecLabel = new QLabel(widget_10);
        balanceValueRecLabel->setObjectName(QStringLiteral("balanceValueRecLabel"));
        balanceValueRecLabel->setGeometry(QRect(140, 7, 128, 30));
        balanceValueRecLabel->setFont(font1);
        balanceValueRecLabel->setStyleSheet(QString::fromUtf8("font:18px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(238, 136, 82);"));
        balanceValueRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        integRecLabel = new QLabel(widget_10);
        integRecLabel->setObjectName(QStringLiteral("integRecLabel"));
        integRecLabel->setGeometry(QRect(10, 35, 50, 30));
        integRecLabel->setFont(font);
        integRecLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        integRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        integValueRecLabel = new QLabel(widget_10);
        integValueRecLabel->setObjectName(QStringLiteral("integValueRecLabel"));
        integValueRecLabel->setGeometry(QRect(140, 35, 128, 30));
        integValueRecLabel->setFont(font1);
        integValueRecLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(238, 136, 82);"));
        integValueRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        widget_11 = new QWidget(memRechargeWidget);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setGeometry(QRect(0, 140, 284, 331));
        widget_11->setStyleSheet(QLatin1String("QWidget#widget_11 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        amtChargeRecLabel = new QLabel(widget_11);
        amtChargeRecLabel->setObjectName(QStringLiteral("amtChargeRecLabel"));
        amtChargeRecLabel->setGeometry(QRect(-1, 12, 91, 31));
        amtChargeRecLabel->setMinimumSize(QSize(0, 31));
        amtChargeRecLabel->setFont(font);
        amtChargeRecLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        amtChargeRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        payTypeRecLabel = new QLabel(widget_11);
        payTypeRecLabel->setObjectName(QStringLiteral("payTypeRecLabel"));
        payTypeRecLabel->setGeometry(QRect(-1, 94, 91, 31));
        payTypeRecLabel->setMinimumSize(QSize(0, 31));
        payTypeRecLabel->setFont(font);
        payTypeRecLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        payTypeRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        payRecButton_02 = new PayMethodButton(widget_11);
        payRecButton_02->setObjectName(QStringLiteral("payRecButton_02"));
        payRecButton_02->setGeometry(QRect(185, 94, 80, 34));
        payRecButton_02->setMinimumSize(QSize(0, 34));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        payRecButton_02->setFont(font2);
        payRecButton_02->setFocusPolicy(Qt::NoFocus);
        payRecButton_02->setStyleSheet(QStringLiteral(""));
        payRecButton_05 = new PayMethodButton(widget_11);
        payRecButton_05->setObjectName(QStringLiteral("payRecButton_05"));
        payRecButton_05->setGeometry(QRect(96, 172, 80, 34));
        payRecButton_05->setMinimumSize(QSize(0, 34));
        payRecButton_05->setFont(font2);
        payRecButton_05->setFocusPolicy(Qt::NoFocus);
        payRecButton_05->setStyleSheet(QStringLiteral(""));
        payRecButton_06 = new PayMethodButton(widget_11);
        payRecButton_06->setObjectName(QStringLiteral("payRecButton_06"));
        payRecButton_06->setGeometry(QRect(185, 172, 80, 34));
        payRecButton_06->setMinimumSize(QSize(0, 34));
        payRecButton_06->setFont(font2);
        payRecButton_06->setFocusPolicy(Qt::NoFocus);
        payRecButton_06->setStyleSheet(QStringLiteral(""));
        payRecButton_04 = new PayMethodButton(widget_11);
        payRecButton_04->setObjectName(QStringLiteral("payRecButton_04"));
        payRecButton_04->setGeometry(QRect(185, 133, 80, 34));
        payRecButton_04->setMinimumSize(QSize(0, 34));
        payRecButton_04->setFont(font2);
        payRecButton_04->setFocusPolicy(Qt::NoFocus);
        payRecButton_04->setStyleSheet(QStringLiteral(""));
        amtChargeRecEdit = new QLineEdit(widget_11);
        amtChargeRecEdit->setObjectName(QStringLiteral("amtChargeRecEdit"));
        amtChargeRecEdit->setGeometry(QRect(95, 12, 168, 31));
        amtChargeRecEdit->setMinimumSize(QSize(168, 31));
        amtChargeRecEdit->setFont(font);
        amtChargeRecEdit->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"padding-left:10px;"));
        payRecButton_03 = new PayMethodButton(widget_11);
        payRecButton_03->setObjectName(QStringLiteral("payRecButton_03"));
        payRecButton_03->setGeometry(QRect(95, 133, 80, 34));
        payRecButton_03->setMinimumSize(QSize(0, 34));
        payRecButton_03->setFont(font2);
        payRecButton_03->setFocusPolicy(Qt::NoFocus);
        payRecButton_03->setStyleSheet(QStringLiteral(""));
        operatorRecBox = new QComboBox(widget_11);
        operatorRecBox->setObjectName(QStringLiteral("operatorRecBox"));
        operatorRecBox->setGeometry(QRect(96, 216, 168, 31));
        operatorRecBox->setMinimumSize(QSize(168, 31));
        operatorRecBox->setFont(font);
        operatorRecBox->setAcceptDrops(false);
        operatorRecBox->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        operatorRecBox->setEditable(true);
        operatorRecBox->setDuplicatesEnabled(false);
        giftAmtRecEdit = new QLineEdit(widget_11);
        giftAmtRecEdit->setObjectName(QStringLiteral("giftAmtRecEdit"));
        giftAmtRecEdit->setGeometry(QRect(95, 53, 168, 31));
        giftAmtRecEdit->setMinimumSize(QSize(168, 31));
        giftAmtRecEdit->setFont(font);
        giftAmtRecEdit->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"padding-left:10px;"));
        payRecButton_01 = new PayMethodButton(widget_11);
        payRecButton_01->setObjectName(QStringLiteral("payRecButton_01"));
        payRecButton_01->setGeometry(QRect(95, 94, 80, 34));
        payRecButton_01->setMinimumSize(QSize(0, 34));
        payRecButton_01->setFont(font2);
        payRecButton_01->setFocusPolicy(Qt::NoFocus);
        payRecButton_01->setStyleSheet(QStringLiteral(""));
        operatorRecLabel = new QLabel(widget_11);
        operatorRecLabel->setObjectName(QStringLiteral("operatorRecLabel"));
        operatorRecLabel->setGeometry(QRect(-1, 216, 91, 31));
        operatorRecLabel->setMinimumSize(QSize(0, 31));
        operatorRecLabel->setFont(font);
        operatorRecLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        operatorRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        giftAmtRecLabel = new QLabel(widget_11);
        giftAmtRecLabel->setObjectName(QStringLiteral("giftAmtRecLabel"));
        giftAmtRecLabel->setGeometry(QRect(-1, 53, 91, 31));
        giftAmtRecLabel->setMinimumSize(QSize(0, 31));
        giftAmtRecLabel->setFont(font);
        giftAmtRecLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        giftAmtRecLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rechargeConfireButton = new QPushButton(widget_11);
        rechargeConfireButton->setObjectName(QStringLiteral("rechargeConfireButton"));
        rechargeConfireButton->setGeometry(QRect(15, 263, 255, 44));
        rechargeConfireButton->setMinimumSize(QSize(255, 44));
        rechargeConfireButton->setFont(font2);
        rechargeConfireButton->setFocusPolicy(Qt::NoFocus);
        rechargeConfireButton->setStyleSheet(QLatin1String("QPushButton#rechargeConfireButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#rechargeConfireButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));
        stackedWidget->addWidget(memRechargeWidget);
        memRegisterWidget = new QWidget();
        memRegisterWidget->setObjectName(QStringLiteral("memRegisterWidget"));
        sizePolicy.setHeightForWidth(memRegisterWidget->sizePolicy().hasHeightForWidth());
        memRegisterWidget->setSizePolicy(sizePolicy);
        memRegisterWidget->setMinimumSize(QSize(0, 396));
        memRegisterWidget->setMaximumSize(QSize(16777215, 396));
        memRegisterWidget->setStyleSheet(QLatin1String("QWidget#memRegisterWidget {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        payPasswdRegLabel = new QLabel(memRegisterWidget);
        payPasswdRegLabel->setObjectName(QStringLiteral("payPasswdRegLabel"));
        payPasswdRegLabel->setGeometry(QRect(20, 170, 80, 30));
        payPasswdRegLabel->setMinimumSize(QSize(0, 30));
        payPasswdRegLabel->setFont(font);
        payPasswdRegLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        payPasswdRegLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nameRegLabel = new QLabel(memRegisterWidget);
        nameRegLabel->setObjectName(QStringLiteral("nameRegLabel"));
        nameRegLabel->setGeometry(QRect(20, 20, 80, 30));
        nameRegLabel->setMinimumSize(QSize(0, 30));
        nameRegLabel->setFont(font);
        nameRegLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        nameRegLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        operatorRegBox = new QComboBox(memRegisterWidget);
        operatorRegBox->setObjectName(QStringLiteral("operatorRegBox"));
        operatorRegBox->setGeometry(QRect(100, 250, 168, 30));
        operatorRegBox->setMinimumSize(QSize(0, 30));
        operatorRegBox->setFont(font);
        operatorRegBox->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        operatorRegBox->setEditable(true);
        phoneRegEdit = new QLineEdit(memRegisterWidget);
        phoneRegEdit->setObjectName(QStringLiteral("phoneRegEdit"));
        phoneRegEdit->setGeometry(QRect(100, 130, 168, 30));
        phoneRegEdit->setMinimumSize(QSize(0, 30));
        phoneRegEdit->setFont(font);
        phoneRegEdit->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"padding-left:10px;"));
        phoneRegEdit->setMaxLength(11);
        commitRegButton = new QPushButton(memRegisterWidget);
        commitRegButton->setObjectName(QStringLiteral("commitRegButton"));
        commitRegButton->setGeometry(QRect(13, 340, 255, 44));
        commitRegButton->setMinimumSize(QSize(255, 44));
        QFont font3;
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        commitRegButton->setFont(font3);
        commitRegButton->setFocusPolicy(Qt::NoFocus);
        commitRegButton->setStyleSheet(QLatin1String("QPushButton#commitRegButton {\n"
"	font:14px;\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#commitRegButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));
        operatorRegLabel = new QLabel(memRegisterWidget);
        operatorRegLabel->setObjectName(QStringLiteral("operatorRegLabel"));
        operatorRegLabel->setGeometry(QRect(20, 250, 80, 30));
        operatorRegLabel->setMinimumSize(QSize(0, 30));
        operatorRegLabel->setFont(font);
        operatorRegLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        operatorRegLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sexRegLabel = new QLabel(memRegisterWidget);
        sexRegLabel->setObjectName(QStringLiteral("sexRegLabel"));
        sexRegLabel->setGeometry(QRect(19, 54, 81, 30));
        sexRegLabel->setMinimumSize(QSize(0, 30));
        sexRegLabel->setFont(font);
        sexRegLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        sexRegLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        payPasswdRegEdit = new QLineEdit(memRegisterWidget);
        payPasswdRegEdit->setObjectName(QStringLiteral("payPasswdRegEdit"));
        payPasswdRegEdit->setGeometry(QRect(100, 170, 168, 30));
        payPasswdRegEdit->setMinimumSize(QSize(0, 30));
        payPasswdRegEdit->setFont(font);
        payPasswdRegEdit->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"padding-left:10px;"));
        payPasswdRegEdit->setMaxLength(6);
        payPasswdRegEdit->setEchoMode(QLineEdit::Password);
        phoneRegLabel = new QLabel(memRegisterWidget);
        phoneRegLabel->setObjectName(QStringLiteral("phoneRegLabel"));
        phoneRegLabel->setGeometry(QRect(20, 130, 80, 30));
        phoneRegLabel->setMinimumSize(QSize(0, 30));
        phoneRegLabel->setFont(font);
        phoneRegLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        phoneRegLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        memGradeRegLabel = new QLabel(memRegisterWidget);
        memGradeRegLabel->setObjectName(QStringLiteral("memGradeRegLabel"));
        memGradeRegLabel->setGeometry(QRect(0, 210, 100, 30));
        memGradeRegLabel->setMinimumSize(QSize(0, 30));
        memGradeRegLabel->setFont(font);
        memGradeRegLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memGradeRegLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        memGradeRegBox = new QComboBox(memRegisterWidget);
        memGradeRegBox->setObjectName(QStringLiteral("memGradeRegBox"));
        memGradeRegBox->setGeometry(QRect(100, 210, 168, 30));
        memGradeRegBox->setMinimumSize(QSize(0, 30));
        memGradeRegBox->setFont(font);
        memGradeRegBox->setFocusPolicy(Qt::NoFocus);
        memGradeRegBox->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memGradeRegBox->setEditable(true);
        manBtn = new QPushButton(memRegisterWidget);
        manBtn->setObjectName(QStringLiteral("manBtn"));
        manBtn->setGeometry(QRect(100, 57, 24, 24));
        manBtn->setFocusPolicy(Qt::NoFocus);
        manBtn->setStyleSheet(QStringLiteral("border-image: url(:/member/man_normal.png);"));
        womanBtn = new QPushButton(memRegisterWidget);
        womanBtn->setObjectName(QStringLiteral("womanBtn"));
        womanBtn->setGeometry(QRect(140, 57, 24, 24));
        womanBtn->setFocusPolicy(Qt::NoFocus);
        womanBtn->setStyleSheet(QStringLiteral("border-image: url(:/member/woman_normal.png);"));
        warningRegLabel = new QLabel(memRegisterWidget);
        warningRegLabel->setObjectName(QStringLiteral("warningRegLabel"));
        warningRegLabel->setGeometry(QRect(10, 320, 255, 20));
        warningRegLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(249, 79, 79);"));
        birthdayRegEdit = new DateLineEdit(memRegisterWidget);
        birthdayRegEdit->setObjectName(QStringLiteral("birthdayRegEdit"));
        birthdayRegEdit->setGeometry(QRect(100, 90, 168, 30));
        birthdayRegEdit->setMinimumSize(QSize(0, 30));
        birthdayRegEdit->setFont(font);
        birthdayRegEdit->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"padding-left:10px;"));
        birthdayRegLabel = new QLabel(memRegisterWidget);
        birthdayRegLabel->setObjectName(QStringLiteral("birthdayRegLabel"));
        birthdayRegLabel->setGeometry(QRect(9, 90, 91, 30));
        birthdayRegLabel->setMinimumSize(QSize(0, 30));
        birthdayRegLabel->setFont(font);
        birthdayRegLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        birthdayRegLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nameWidget = new SearchEdit(memRegisterWidget);
        nameWidget->setObjectName(QStringLiteral("nameWidget"));
        nameWidget->setGeometry(QRect(100, 20, 168, 30));
        nameWidget->setStyleSheet(QStringLiteral(""));
        stackedWidget->addWidget(memRegisterWidget);
        modifyPasswdWidget = new QWidget();
        modifyPasswdWidget->setObjectName(QStringLiteral("modifyPasswdWidget"));
        widget_12 = new QWidget(modifyPasswdWidget);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setGeometry(QRect(0, 0, 284, 290));
        widget_12->setStyleSheet(QLatin1String("QWidget#widget_12 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        newPasswdPwdLabel = new QLabel(widget_12);
        newPasswdPwdLabel->setObjectName(QStringLiteral("newPasswdPwdLabel"));
        newPasswdPwdLabel->setGeometry(QRect(10, 94, 80, 31));
        newPasswdPwdLabel->setMinimumSize(QSize(0, 31));
        newPasswdPwdLabel->setFont(font2);
        newPasswdPwdLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        confirmNewPasswdPwdLabel = new QLabel(widget_12);
        confirmNewPasswdPwdLabel->setObjectName(QStringLiteral("confirmNewPasswdPwdLabel"));
        confirmNewPasswdPwdLabel->setGeometry(QRect(10, 133, 80, 31));
        confirmNewPasswdPwdLabel->setMinimumSize(QSize(0, 31));
        confirmNewPasswdPwdLabel->setFont(font2);
        confirmNewPasswdPwdLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        newPasswdPwdEdit = new QLineEdit(widget_12);
        newPasswdPwdEdit->setObjectName(QStringLiteral("newPasswdPwdEdit"));
        newPasswdPwdEdit->setGeometry(QRect(95, 94, 168, 31));
        newPasswdPwdEdit->setMinimumSize(QSize(168, 31));
        newPasswdPwdEdit->setFont(font2);
        newPasswdPwdEdit->setStyleSheet(QStringLiteral("padding-left:10px;"));
        newPasswdPwdEdit->setMaxLength(6);
        newPasswdPwdEdit->setEchoMode(QLineEdit::Password);
        commitPwdButton = new QPushButton(widget_12);
        commitPwdButton->setObjectName(QStringLiteral("commitPwdButton"));
        commitPwdButton->setGeometry(QRect(12, 230, 255, 44));
        commitPwdButton->setMinimumSize(QSize(255, 44));
        commitPwdButton->setFont(font2);
        commitPwdButton->setFocusPolicy(Qt::NoFocus);
        commitPwdButton->setStyleSheet(QLatin1String("QPushButton#commitPwdButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#commitPwdButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));
        oldPasswdPwdLabel = new QLabel(widget_12);
        oldPasswdPwdLabel->setObjectName(QStringLiteral("oldPasswdPwdLabel"));
        oldPasswdPwdLabel->setGeometry(QRect(10, 55, 80, 31));
        oldPasswdPwdLabel->setMinimumSize(QSize(0, 31));
        oldPasswdPwdLabel->setFont(font2);
        oldPasswdPwdLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cardIDPwdLabel = new QLabel(widget_12);
        cardIDPwdLabel->setObjectName(QStringLiteral("cardIDPwdLabel"));
        cardIDPwdLabel->setGeometry(QRect(10, 16, 80, 31));
        cardIDPwdLabel->setMinimumSize(QSize(0, 31));
        cardIDPwdLabel->setFont(font2);
        cardIDPwdLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        oldPasswdPwdEdit = new QLineEdit(widget_12);
        oldPasswdPwdEdit->setObjectName(QStringLiteral("oldPasswdPwdEdit"));
        oldPasswdPwdEdit->setGeometry(QRect(95, 55, 168, 31));
        oldPasswdPwdEdit->setMinimumSize(QSize(168, 31));
        oldPasswdPwdEdit->setFont(font2);
        oldPasswdPwdEdit->setStyleSheet(QStringLiteral("padding-left:10px;"));
        oldPasswdPwdEdit->setMaxLength(6);
        oldPasswdPwdEdit->setEchoMode(QLineEdit::Password);
        confirmNewpasswdPwdEdit = new QLineEdit(widget_12);
        confirmNewpasswdPwdEdit->setObjectName(QStringLiteral("confirmNewpasswdPwdEdit"));
        confirmNewpasswdPwdEdit->setGeometry(QRect(95, 133, 168, 31));
        confirmNewpasswdPwdEdit->setMinimumSize(QSize(168, 31));
        confirmNewpasswdPwdEdit->setFont(font2);
        confirmNewpasswdPwdEdit->setStyleSheet(QStringLiteral("padding-left:10px;"));
        confirmNewpasswdPwdEdit->setMaxLength(6);
        confirmNewpasswdPwdEdit->setEchoMode(QLineEdit::Password);
        pwdModifyWarningLabel = new QLabel(widget_12);
        pwdModifyWarningLabel->setObjectName(QStringLiteral("pwdModifyWarningLabel"));
        pwdModifyWarningLabel->setGeometry(QRect(95, 164, 168, 31));
        pwdModifyWarningLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(249, 79, 79);"));
        cardIDValuePwdLabel = new QLabel(widget_12);
        cardIDValuePwdLabel->setObjectName(QStringLiteral("cardIDValuePwdLabel"));
        cardIDValuePwdLabel->setGeometry(QRect(95, 16, 168, 31));
        stackedWidget->addWidget(modifyPasswdWidget);
        replaceCardWidget = new ReplaceCardWidget();
        replaceCardWidget->setObjectName(QStringLiteral("replaceCardWidget"));
        stackedWidget->addWidget(replaceCardWidget);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 5);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        line = new QFrame(MemberDlg);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setMinimumSize(QSize(2, 0));
        line->setMaximumSize(QSize(2, 16777215));
        line->setSizeIncrement(QSize(0, 0));
        line->setStyleSheet(QStringLiteral("background-color: rgb(102, 102, 102);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 1, 1, 1);

        widget_3 = new QWidget(MemberDlg);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(412, 526));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(10, 44, 15, 193);
        hundredButton = new QPushButton(widget_3);
        hundredButton->setObjectName(QStringLiteral("hundredButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(hundredButton->sizePolicy().hasHeightForWidth());
        hundredButton->setSizePolicy(sizePolicy3);
        hundredButton->setMinimumSize(QSize(80, 68));
        hundredButton->setMaximumSize(QSize(80, 16777215));
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

        gridLayout_2->addWidget(hundredButton, 0, 0, 1, 1);

        twoHundredButton = new QPushButton(widget_3);
        twoHundredButton->setObjectName(QStringLiteral("twoHundredButton"));
        sizePolicy3.setHeightForWidth(twoHundredButton->sizePolicy().hasHeightForWidth());
        twoHundredButton->setSizePolicy(sizePolicy3);
        twoHundredButton->setMinimumSize(QSize(80, 68));
        twoHundredButton->setMaximumSize(QSize(80, 16777215));
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

        gridLayout_2->addWidget(twoHundredButton, 1, 0, 1, 1);

        threeHundredButton = new QPushButton(widget_3);
        threeHundredButton->setObjectName(QStringLiteral("threeHundredButton"));
        sizePolicy3.setHeightForWidth(threeHundredButton->sizePolicy().hasHeightForWidth());
        threeHundredButton->setSizePolicy(sizePolicy3);
        threeHundredButton->setMinimumSize(QSize(80, 68));
        threeHundredButton->setMaximumSize(QSize(80, 16777215));
        threeHundredButton->setFocusPolicy(Qt::NoFocus);
        threeHundredButton->setStyleSheet(QString::fromUtf8("QPushButton#threeHundredButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#threeHundredButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        gridLayout_2->addWidget(threeHundredButton, 2, 0, 1, 1);

        fiveHundredButton = new QPushButton(widget_3);
        fiveHundredButton->setObjectName(QStringLiteral("fiveHundredButton"));
        sizePolicy3.setHeightForWidth(fiveHundredButton->sizePolicy().hasHeightForWidth());
        fiveHundredButton->setSizePolicy(sizePolicy3);
        fiveHundredButton->setMinimumSize(QSize(80, 68));
        fiveHundredButton->setMaximumSize(QSize(80, 16777215));
        fiveHundredButton->setFocusPolicy(Qt::NoFocus);
        fiveHundredButton->setStyleSheet(QString::fromUtf8("QPushButton#fiveHundredButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#fiveHundredButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        gridLayout_2->addWidget(fiveHundredButton, 3, 0, 1, 1);

        DigitalKeyWnd = new WndDigitalKeyboard(widget_3);
        DigitalKeyWnd->setObjectName(QStringLiteral("DigitalKeyWnd"));
        DigitalKeyWnd->setMinimumSize(QSize(303, 303));

        gridLayout_2->addWidget(DigitalKeyWnd, 0, 1, 4, 1);


        gridLayout_3->addWidget(widget_3, 1, 2, 1, 1);

        QWidget::setTabOrder(cardIDQueryEdit, amtChargeRecEdit);
        QWidget::setTabOrder(amtChargeRecEdit, giftAmtRecEdit);
        QWidget::setTabOrder(giftAmtRecEdit, operatorRecBox);
        QWidget::setTabOrder(operatorRecBox, phoneRegEdit);
        QWidget::setTabOrder(phoneRegEdit, payPasswdRegEdit);
        QWidget::setTabOrder(payPasswdRegEdit, operatorRegBox);
        QWidget::setTabOrder(operatorRegBox, oldPasswdPwdEdit);
        QWidget::setTabOrder(oldPasswdPwdEdit, newPasswdPwdEdit);
        QWidget::setTabOrder(newPasswdPwdEdit, confirmNewpasswdPwdEdit);

        retranslateUi(MemberDlg);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MemberDlg);
    } // setupUi

    void retranslateUi(QDialog *MemberDlg)
    {
        MemberDlg->setWindowTitle(QApplication::translate("MemberDlg", "MemberDlg", Q_NULLPTR));
        memRegisterButton->setText(QApplication::translate("MemberDlg", "\344\274\232\345\221\230\346\263\250\345\206\214", Q_NULLPTR));
        modifyPasswdButton->setText(QApplication::translate("MemberDlg", "\345\257\206\347\240\201\344\277\256\346\224\271", Q_NULLPTR));
        memQueryButton->setText(QApplication::translate("MemberDlg", "\344\274\232\345\221\230\346\237\245\350\257\242", Q_NULLPTR));
        memRechargeButton->setText(QApplication::translate("MemberDlg", "\344\274\232\345\221\230\345\205\205\345\200\274", Q_NULLPTR));
        warningLabel->setText(QString());
        cardIDQueryEdit->setText(QString());
        cardIDQueryEdit->setPlaceholderText(QApplication::translate("MemberDlg", "\350\257\267\350\276\223\345\205\245\345\215\241\345\217\267\346\210\226\346\211\213\346\234\272\345\217\267", Q_NULLPTR));
        birthdayQueryLabel->setText(QApplication::translate("MemberDlg", "\347\224\237\346\227\245\357\274\232", Q_NULLPTR));
        sexQueryLabel->setText(QApplication::translate("MemberDlg", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        birthdayValueQueryLabel->setText(QString());
        nameQueryLabel->setText(QApplication::translate("MemberDlg", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        sexValueQueryLabel->setText(QString());
        nameValueQueryLabel->setText(QString());
        cardIDQueryLabel->setText(QApplication::translate("MemberDlg", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        cardIDValueQueryLabel->setText(QApplication::translate("MemberDlg", "2266654455", Q_NULLPTR));
        iphoneValueQueryLabel->setText(QString());
        phoneQueryLabel->setText(QApplication::translate("MemberDlg", "\346\211\213\346\234\272\345\217\267\357\274\232", Q_NULLPTR));
        payPwdQueryLabel->setText(QApplication::translate("MemberDlg", "\346\224\257\344\273\230\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        payPwdValueQueryLabel->setText(QString());
        memGradeQueryLabel->setText(QApplication::translate("MemberDlg", "\344\274\232\345\221\230\347\255\211\347\272\247\357\274\232", Q_NULLPTR));
        memGradeValueQueryLabel->setText(QString());
        balanceQueryLabel->setText(QApplication::translate("MemberDlg", "\344\275\231\351\242\235\357\274\232", Q_NULLPTR));
        integValueQueryLabel->setText(QString());
        balanceValueQueryLabel->setText(QString());
        integQueryLabel->setText(QApplication::translate("MemberDlg", "\347\247\257\345\210\206\357\274\232", Q_NULLPTR));
        memConsumeQueryButton->setText(QApplication::translate("MemberDlg", "\344\274\232\345\221\230\346\266\210\350\264\271", Q_NULLPTR));
        CardIDValueRecLabel->setText(QApplication::translate("MemberDlg", "13685695462", Q_NULLPTR));
        phoneValueRecLabel->setText(QApplication::translate("MemberDlg", "13685695462", Q_NULLPTR));
        memNameRecLabel->setText(QApplication::translate("MemberDlg", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        phoneRecLabel->setText(QApplication::translate("MemberDlg", "\347\224\265\350\257\235\357\274\232", Q_NULLPTR));
        memNameValueRecLabel->setText(QApplication::translate("MemberDlg", "\344\277\241\346\201\257\345\245\263\345\243\253", Q_NULLPTR));
        CardIDRecLabel->setText(QApplication::translate("MemberDlg", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        balanceRecLabel->setText(QApplication::translate("MemberDlg", "\344\275\231\351\242\235\357\274\232", Q_NULLPTR));
        balanceValueRecLabel->setText(QApplication::translate("MemberDlg", "\357\277\245150.00", Q_NULLPTR));
        integRecLabel->setText(QApplication::translate("MemberDlg", "\347\247\257\345\210\206\357\274\232", Q_NULLPTR));
        integValueRecLabel->setText(QApplication::translate("MemberDlg", "20", Q_NULLPTR));
        amtChargeRecLabel->setText(QApplication::translate("MemberDlg", "* \345\205\205\345\200\274\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        payTypeRecLabel->setText(QApplication::translate("MemberDlg", "\346\224\257\344\273\230\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        payRecButton_02->setText(QString());
        payRecButton_05->setText(QString());
        payRecButton_06->setText(QString());
        payRecButton_04->setText(QString());
        payRecButton_03->setText(QString());
        payRecButton_01->setText(QString());
        operatorRecLabel->setText(QApplication::translate("MemberDlg", "  \344\270\232\345\212\241\345\221\230\357\274\232", Q_NULLPTR));
        giftAmtRecLabel->setText(QApplication::translate("MemberDlg", "\350\265\240\351\200\201\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        rechargeConfireButton->setText(QApplication::translate("MemberDlg", "\347\241\256\350\256\244\345\205\205\345\200\274", Q_NULLPTR));
        payPasswdRegLabel->setText(QApplication::translate("MemberDlg", "\346\224\257\344\273\230\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        nameRegLabel->setText(QApplication::translate("MemberDlg", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        commitRegButton->setText(QApplication::translate("MemberDlg", "\346\217\220\344\272\244", Q_NULLPTR));
        operatorRegLabel->setText(QApplication::translate("MemberDlg", "\344\270\232\345\212\241\345\221\230\357\274\232", Q_NULLPTR));
        sexRegLabel->setText(QApplication::translate("MemberDlg", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        phoneRegLabel->setText(QApplication::translate("MemberDlg", "* \346\211\213\346\234\272\345\217\267\357\274\232", Q_NULLPTR));
        memGradeRegLabel->setText(QApplication::translate("MemberDlg", "* \344\274\232\345\221\230\347\255\211\347\272\247\357\274\232", Q_NULLPTR));
        memGradeRegBox->clear();
        memGradeRegBox->insertItems(0, QStringList()
         << QApplication::translate("MemberDlg", "\346\231\256\351\200\232\344\274\232\345\221\230", Q_NULLPTR)
         << QApplication::translate("MemberDlg", "\351\273\204\351\207\221\344\274\232\345\221\230", Q_NULLPTR)
         << QApplication::translate("MemberDlg", "\351\222\273\347\237\263\344\274\232\345\221\230", Q_NULLPTR)
        );
        manBtn->setText(QString());
        womanBtn->setText(QString());
        warningRegLabel->setText(QString());
        birthdayRegEdit->setText(QString());
        birthdayRegLabel->setText(QApplication::translate("MemberDlg", "\347\224\237\346\227\245\357\274\232", Q_NULLPTR));
        newPasswdPwdLabel->setText(QApplication::translate("MemberDlg", "\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        confirmNewPasswdPwdLabel->setText(QApplication::translate("MemberDlg", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        commitPwdButton->setText(QApplication::translate("MemberDlg", "\346\217\220\344\272\244", Q_NULLPTR));
        oldPasswdPwdLabel->setText(QApplication::translate("MemberDlg", "\345\216\237\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        cardIDPwdLabel->setText(QApplication::translate("MemberDlg", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        pwdModifyWarningLabel->setText(QString());
        cardIDValuePwdLabel->setText(QString());
        hundredButton->setText(QApplication::translate("MemberDlg", "\357\277\245100", Q_NULLPTR));
        twoHundredButton->setText(QApplication::translate("MemberDlg", "\357\277\245200", Q_NULLPTR));
        threeHundredButton->setText(QApplication::translate("MemberDlg", "\357\277\245300", Q_NULLPTR));
        fiveHundredButton->setText(QApplication::translate("MemberDlg", "\357\277\245500", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemberDlg: public Ui_MemberDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBERDLG_H
