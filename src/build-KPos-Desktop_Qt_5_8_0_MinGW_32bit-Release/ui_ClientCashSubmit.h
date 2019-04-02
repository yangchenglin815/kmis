/********************************************************************************
** Form generated from reading UI file 'ClientCashSubmit.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTCASHSUBMIT_H
#define UI_CLIENTCASHSUBMIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "WndDigitalKeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_ClientCashSubmit
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titleLabel;
    QPushButton *deleteBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *shop_code;
    QLabel *pos_type;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *user_name;
    QLabel *shop_name;
    QLabel *label;
    QLabel *last_submit_at;
    QLabel *label_11;
    QLabel *pos_code;
    QLabel *operate_at;
    QLabel *label_15;
    QLabel *label_5;
    QLabel *user_code;
    QFrame *frame;
    QLabel *label_20;
    QLineEdit *bills_10;
    QLabel *label_21;
    QLineEdit *bills_0_5;
    QLabel *label_24;
    QLineEdit *bills_0_1;
    QLabel *label_22;
    QLineEdit *bills_1;
    QLabel *label_23;
    QLineEdit *bills_5;
    QLabel *label_25;
    QLabel *cashSum;
    QLabel *label_17;
    QLineEdit *bills_100;
    QLabel *label_18;
    QLineEdit *bills_50;
    QLabel *label_19;
    QLineEdit *bills_20;
    QPushButton *pushFrom;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *factorButton;
    QPushButton *fiftyButton;
    QPushButton *twoHundredButton;
    QPushButton *hundredButton;
    WndDigitalKeyboard *DigitalKeyWnd;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ClientCashSubmit)
    {
        if (ClientCashSubmit->objectName().isEmpty())
            ClientCashSubmit->setObjectName(QStringLiteral("ClientCashSubmit"));
        ClientCashSubmit->resize(726, 480);
        ClientCashSubmit->setMinimumSize(QSize(726, 480));
        ClientCashSubmit->setStyleSheet(QStringLiteral("QDialog#ClientCashSubmit{\\n	border-image: url(:/shareImages/dlg_background.png);\\n}"));
        verticalLayout = new QVBoxLayout(ClientCashSubmit);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(ClientCashSubmit);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 42));
        titleWidget->setMaximumSize(QSize(16777215, 42));
        titleWidget->setCursor(QCursor(Qt::ArrowCursor));
        titleWidget->setStyleSheet(QLatin1String("QWidget#titleWidget {\n"
"	border-image: url(:/shareImages/title_bar.png);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(titleWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 5, -1, -1);
        titleLabel = new QLabel(titleWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel#titleLabel {\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:16px;\n"
"	color: rgb(255, 255, 255);\n"
"	border-width: 0px;\n"
"}"));

        horizontalLayout_2->addWidget(titleLabel);

        deleteBtn = new QPushButton(titleWidget);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setMinimumSize(QSize(33, 33));
        deleteBtn->setMaximumSize(QSize(33, 33));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        deleteBtn->setFont(font1);
        deleteBtn->setFocusPolicy(Qt::NoFocus);
        deleteBtn->setStyleSheet(QLatin1String("QPushButton#deleteBtn {\n"
"	border-image: url(:/shareImages/close.png);\n"
"}\n"
"\n"
"QPushButton#deleteBtn:pressed {\n"
"	border-image: url(:/shareImages/close_press.png);\n"
"}"));
        deleteBtn->setAutoDefault(false);

        horizontalLayout_2->addWidget(deleteBtn);


        verticalLayout->addWidget(titleWidget);

        widget = new QWidget(ClientCashSubmit);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, 11, 15, -1);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(283, 416));
        widget_2->setMaximumSize(QSize(283, 416));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(283, 140));
        widget_5->setMaximumSize(QSize(283, 140));
        widget_5->setStyleSheet(QLatin1String("background-color: rgb(250, 250, 250);\n"
""));
        label_9 = new QLabel(widget_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(9, 73, 60, 16));
        label_9->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        label_13 = new QLabel(widget_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(9, 94, 54, 16));
        label_13->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        shop_code = new QLabel(widget_5);
        shop_code->setObjectName(QStringLiteral("shop_code"));
        shop_code->setGeometry(QRect(70, 9, 81, 16));
        shop_code->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        pos_type = new QLabel(widget_5);
        pos_type->setObjectName(QStringLiteral("pos_type"));
        pos_type->setGeometry(QRect(231, 73, 41, 20));
        pos_type->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(9, 30, 54, 16));
        label_3->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(160, 52, 66, 16));
        label_7->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        user_name = new QLabel(widget_5);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setGeometry(QRect(233, 52, 41, 20));
        user_name->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        shop_name = new QLabel(widget_5);
        shop_name->setObjectName(QStringLiteral("shop_name"));
        shop_name->setGeometry(QRect(70, 30, 201, 16));
        shop_name->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        label = new QLabel(widget_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 54, 16));
        label->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        last_submit_at = new QLabel(widget_5);
        last_submit_at->setObjectName(QStringLiteral("last_submit_at"));
        last_submit_at->setGeometry(QRect(90, 116, 96, 16));
        last_submit_at->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        label_11 = new QLabel(widget_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(166, 73, 60, 16));
        label_11->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        pos_code = new QLabel(widget_5);
        pos_code->setObjectName(QStringLiteral("pos_code"));
        pos_code->setGeometry(QRect(70, 73, 81, 16));
        pos_code->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        operate_at = new QLabel(widget_5);
        operate_at->setObjectName(QStringLiteral("operate_at"));
        operate_at->setGeometry(QRect(69, 94, 96, 16));
        operate_at->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        label_15 = new QLabel(widget_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(9, 116, 78, 16));
        label_15->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(9, 52, 66, 16));
        label_5->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));
        user_code = new QLabel(widget_5);
        user_code->setObjectName(QStringLiteral("user_code"));
        user_code->setGeometry(QRect(80, 52, 71, 16));
        user_code->setStyleSheet(QStringLiteral("color: rgb(153, 153, 153);"));

        verticalLayout_3->addWidget(widget_5);

        frame = new QFrame(widget_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(283, 276));
        frame->setMaximumSize(QSize(283, 276));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(frame);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(151, 54, 52, 30));
        label_20->setMaximumSize(QSize(62, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_20->setFont(font2);
        label_20->setStyleSheet(QStringLiteral(""));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bills_10 = new QLineEdit(frame);
        bills_10->setObjectName(QStringLiteral("bills_10"));
        bills_10->setGeometry(QRect(200, 54, 70, 30));
        bills_10->setMinimumSize(QSize(70, 30));
        bills_10->setMaximumSize(QSize(70, 30));
        bills_10->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: #ed9a6e;\n"
"border-style:solid;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        label_21 = new QLabel(frame);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(30, 92, 42, 30));
        label_21->setMaximumSize(QSize(62, 16777215));
        label_21->setFont(font2);
        label_21->setStyleSheet(QStringLiteral(""));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bills_0_5 = new QLineEdit(frame);
        bills_0_5->setObjectName(QStringLiteral("bills_0_5"));
        bills_0_5->setGeometry(QRect(72, 130, 70, 30));
        bills_0_5->setMinimumSize(QSize(70, 30));
        bills_0_5->setMaximumSize(QSize(70, 30));
        bills_0_5->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: #ed9a6e;\n"
"border-style:solid;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(145, 130, 57, 30));
        label_24->setMaximumSize(QSize(62, 16777215));
        label_24->setFont(font2);
        label_24->setStyleSheet(QStringLiteral(""));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bills_0_1 = new QLineEdit(frame);
        bills_0_1->setObjectName(QStringLiteral("bills_0_1"));
        bills_0_1->setGeometry(QRect(200, 130, 70, 30));
        bills_0_1->setMinimumSize(QSize(70, 30));
        bills_0_1->setMaximumSize(QSize(70, 30));
        bills_0_1->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: #ed9a6e;\n"
"border-style:solid;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        label_22 = new QLabel(frame);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(160, 92, 42, 30));
        label_22->setMaximumSize(QSize(62, 16777215));
        label_22->setFont(font2);
        label_22->setLayoutDirection(Qt::LeftToRight);
        label_22->setStyleSheet(QStringLiteral(""));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bills_1 = new QLineEdit(frame);
        bills_1->setObjectName(QStringLiteral("bills_1"));
        bills_1->setGeometry(QRect(200, 92, 70, 30));
        bills_1->setMinimumSize(QSize(70, 30));
        bills_1->setMaximumSize(QSize(70, 30));
        bills_1->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: #ed9a6e;\n"
"border-style:solid;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        label_23 = new QLabel(frame);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(14, 130, 57, 30));
        label_23->setMaximumSize(QSize(62, 16777215));
        label_23->setFont(font2);
        label_23->setStyleSheet(QStringLiteral(""));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bills_5 = new QLineEdit(frame);
        bills_5->setObjectName(QStringLiteral("bills_5"));
        bills_5->setGeometry(QRect(72, 92, 70, 30));
        bills_5->setMinimumSize(QSize(70, 30));
        bills_5->setMaximumSize(QSize(70, 30));
        bills_5->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: #ed9a6e;\n"
"border-style:solid;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        label_25 = new QLabel(frame);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(19, 168, 91, 31));
        label_25->setMaximumSize(QSize(16777215, 45));
        label_25->setFont(font2);
        cashSum = new QLabel(frame);
        cashSum->setObjectName(QStringLiteral("cashSum"));
        cashSum->setGeometry(QRect(115, 168, 141, 28));
        cashSum->setMaximumSize(QSize(16777215, 45));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        cashSum->setFont(font3);
        cashSum->setStyleSheet(QStringLiteral("color:#ef9b6d"));
        cashSum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 16, 62, 30));
        label_17->setMaximumSize(QSize(62, 16777215));
        label_17->setFont(font2);
        label_17->setStyleSheet(QStringLiteral(""));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bills_100 = new QLineEdit(frame);
        bills_100->setObjectName(QStringLiteral("bills_100"));
        bills_100->setGeometry(QRect(72, 16, 70, 30));
        bills_100->setMinimumSize(QSize(70, 30));
        bills_100->setMaximumSize(QSize(70, 30));
        bills_100->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: #ed9a6e;\n"
"border-style:solid;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(151, 16, 52, 30));
        label_18->setMaximumSize(QSize(62, 16777215));
        label_18->setFont(font2);
        label_18->setStyleSheet(QStringLiteral(""));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bills_50 = new QLineEdit(frame);
        bills_50->setObjectName(QStringLiteral("bills_50"));
        bills_50->setGeometry(QRect(200, 16, 70, 30));
        bills_50->setMinimumSize(QSize(70, 30));
        bills_50->setMaximumSize(QSize(70, 30));
        bills_50->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: #ed9a6e;\n"
"border-style:solid;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 54, 52, 30));
        label_19->setMaximumSize(QSize(62, 16777215));
        label_19->setFont(font2);
        label_19->setStyleSheet(QStringLiteral(""));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bills_20 = new QLineEdit(frame);
        bills_20->setObjectName(QStringLiteral("bills_20"));
        bills_20->setGeometry(QRect(72, 54, 70, 30));
        bills_20->setMinimumSize(QSize(70, 30));
        bills_20->setMaximumSize(QSize(70, 30));
        bills_20->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: #ed9a6e;\n"
"border-style:solid;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        pushFrom = new QPushButton(frame);
        pushFrom->setObjectName(QStringLiteral("pushFrom"));
        pushFrom->setGeometry(QRect(19, 221, 243, 42));
        pushFrom->setMinimumSize(QSize(243, 42));
        pushFrom->setMaximumSize(QSize(243, 42));
        QFont font4;
        pushFrom->setFont(font4);
        pushFrom->setFocusPolicy(Qt::NoFocus);
        pushFrom->setStyleSheet(QLatin1String("QPushButton#pushFrom{\n"
" 	color:#FFFFFF;\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"QPushButton#pushFrom:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));

        verticalLayout_3->addWidget(frame);


        horizontalLayout->addWidget(widget_2);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 300));
        widget_3->setMaximumSize(QSize(16777215, 300));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        factorButton = new QPushButton(widget_3);
        factorButton->setObjectName(QStringLiteral("factorButton"));
        factorButton->setMinimumSize(QSize(74, 67));
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

        verticalLayout_4->addWidget(factorButton);

        fiftyButton = new QPushButton(widget_3);
        fiftyButton->setObjectName(QStringLiteral("fiftyButton"));
        fiftyButton->setMinimumSize(QSize(74, 67));
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

        verticalLayout_4->addWidget(fiftyButton);

        twoHundredButton = new QPushButton(widget_3);
        twoHundredButton->setObjectName(QStringLiteral("twoHundredButton"));
        twoHundredButton->setMinimumSize(QSize(74, 67));
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

        verticalLayout_4->addWidget(twoHundredButton);

        hundredButton = new QPushButton(widget_3);
        hundredButton->setObjectName(QStringLiteral("hundredButton"));
        hundredButton->setMinimumSize(QSize(74, 67));
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

        verticalLayout_4->addWidget(hundredButton);


        horizontalLayout_3->addLayout(verticalLayout_4);

        DigitalKeyWnd = new WndDigitalKeyboard(widget_3);
        DigitalKeyWnd->setObjectName(QStringLiteral("DigitalKeyWnd"));
        DigitalKeyWnd->setMinimumSize(QSize(303, 303));

        horizontalLayout_3->addWidget(DigitalKeyWnd);


        verticalLayout_2->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget_4);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(bills_100, bills_50);
        QWidget::setTabOrder(bills_50, bills_20);
        QWidget::setTabOrder(bills_20, bills_10);
        QWidget::setTabOrder(bills_10, bills_5);
        QWidget::setTabOrder(bills_5, bills_1);
        QWidget::setTabOrder(bills_1, bills_0_5);
        QWidget::setTabOrder(bills_0_5, bills_0_1);

        retranslateUi(ClientCashSubmit);

        QMetaObject::connectSlotsByName(ClientCashSubmit);
    } // setupUi

    void retranslateUi(QDialog *ClientCashSubmit)
    {
        ClientCashSubmit->setWindowTitle(QApplication::translate("ClientCashSubmit", "Dialog", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("ClientCashSubmit", "\344\272\244\346\254\276", Q_NULLPTR));
        deleteBtn->setText(QString());
        label_9->setText(QApplication::translate("ClientCashSubmit", "POS\346\234\272\347\274\226\345\217\267:", Q_NULLPTR));
        label_13->setText(QApplication::translate("ClientCashSubmit", "\344\270\212\346\234\272\346\227\266\351\227\264:", Q_NULLPTR));
        shop_code->setText(QApplication::translate("ClientCashSubmit", "1212255554", Q_NULLPTR));
        pos_type->setText(QApplication::translate("ClientCashSubmit", "KPOS", Q_NULLPTR));
        label_3->setText(QApplication::translate("ClientCashSubmit", "\351\227\250\345\272\227\345\220\215\347\247\260:", Q_NULLPTR));
        label_7->setText(QApplication::translate("ClientCashSubmit", "\346\224\266\351\223\266\345\221\230\345\247\223\345\220\215:", Q_NULLPTR));
        user_name->setText(QApplication::translate("ClientCashSubmit", "\345\274\240\345\260\217\345\247\220", Q_NULLPTR));
        shop_name->setText(QApplication::translate("ClientCashSubmit", "xxx\345\272\204\345\233\255\345\272\227\351\223\272", Q_NULLPTR));
        label->setText(QApplication::translate("ClientCashSubmit", "\351\227\250\345\272\227\347\274\226\345\217\267:", Q_NULLPTR));
        last_submit_at->setText(QApplication::translate("ClientCashSubmit", "2016.06.17 12:20", Q_NULLPTR));
        label_11->setText(QApplication::translate("ClientCashSubmit", "POS\346\234\272\345\236\213\345\217\267:", Q_NULLPTR));
        pos_code->setText(QApplication::translate("ClientCashSubmit", "122325", Q_NULLPTR));
        operate_at->setText(QApplication::translate("ClientCashSubmit", "2016.06.17 12:20", Q_NULLPTR));
        label_15->setText(QApplication::translate("ClientCashSubmit", "\344\270\212\346\254\241\344\272\244\346\254\276\346\227\266\351\227\264:", Q_NULLPTR));
        label_5->setText(QApplication::translate("ClientCashSubmit", "\346\224\266\351\223\266\345\221\230\347\274\226\345\217\267:", Q_NULLPTR));
        user_code->setText(QApplication::translate("ClientCashSubmit", "122325", Q_NULLPTR));
        label_20->setText(QApplication::translate("ClientCashSubmit", "\357\277\24510\357\274\232", Q_NULLPTR));
        label_21->setText(QApplication::translate("ClientCashSubmit", "\357\277\2455\357\274\232", Q_NULLPTR));
        label_24->setText(QApplication::translate("ClientCashSubmit", "\357\277\2450.1\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("ClientCashSubmit", "\357\277\2451\357\274\232", Q_NULLPTR));
        label_23->setText(QApplication::translate("ClientCashSubmit", "\357\277\2450.5\357\274\232", Q_NULLPTR));
        label_25->setText(QApplication::translate("ClientCashSubmit", "\344\270\212\344\272\244\347\216\260\351\207\221\357\274\232", Q_NULLPTR));
        cashSum->setText(QApplication::translate("ClientCashSubmit", "\357\277\2450.00", Q_NULLPTR));
        label_17->setText(QApplication::translate("ClientCashSubmit", "\357\277\245100\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("ClientCashSubmit", "\357\277\24550\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("ClientCashSubmit", "\357\277\24520\357\274\232", Q_NULLPTR));
        pushFrom->setText(QApplication::translate("ClientCashSubmit", "\346\217\220\344\272\244", Q_NULLPTR));
        factorButton->setText(QString());
        fiftyButton->setText(QString());
        twoHundredButton->setText(QString());
        hundredButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClientCashSubmit: public Ui_ClientCashSubmit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTCASHSUBMIT_H
