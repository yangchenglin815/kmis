/********************************************************************************
** Form generated from reading UI file 'QuickAddDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUICKADDDLG_H
#define UI_QUICKADDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <WndDigitalKeyboard.h>
#include "SearchEdit.h"

QT_BEGIN_NAMESPACE

class Ui_QuickAddDlg
{
public:
    QWidget *widget;
    QFrame *frame_2;
    QWidget *widget_12;
    QLabel *pluLabel;
    QLineEdit *barCodelEdit;
    QLabel *factAmtCouponLabel_3;
    QPushButton *submitBtn;
    QLabel *productNumLb;
    QLabel *factAmtCouponLabel_4;
    QLabel *factAmtCouponLabel_5;
    QLabel *factAmtCouponLabel_2;
    QLabel *factAmtCouponLabel_6;
    QComboBox *bKindcBox;
    QComboBox *mKindcBox;
    QComboBox *sKindcBox;
    QLabel *factAmtCouponLabel_7;
    QComboBox *weighTypeCBox;
    QComboBox *basicUnitCBox;
    QLabel *factAmtCouponLabel_8;
    QLabel *factAmtCouponLabel_9;
    QLineEdit *getGoodslEdit;
    QLabel *factAmtCouponLabel_10;
    QComboBox *wUnitCBox;
    QLabel *factAmtCouponLabel_11;
    QLineEdit *referPricelEdit;
    QLabel *factAmtCouponLabel_12;
    QLabel *factAmtCouponLabel_13;
    QLabel *wUnitlabel;
    SearchEdit *goodsNameWidget;
    QWidget *widget_8;
    QGridLayout *gridLayout;
    QPushButton *factorButton;
    QPushButton *fiftyButton;
    QPushButton *hundredButton;
    QPushButton *twoHundredButton;
    WndDigitalKeyboard *DigitalKeyWnd;
    QFrame *line;
    QLineEdit *pricelEdit;
    QLineEdit *memPricelEdit;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *QuickAddDlg)
    {
        if (QuickAddDlg->objectName().isEmpty())
            QuickAddDlg->setObjectName(QStringLiteral("QuickAddDlg"));
        QuickAddDlg->resize(728, 544);
        QuickAddDlg->setMinimumSize(QSize(727, 543));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        QuickAddDlg->setFont(font);
        QuickAddDlg->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(QuickAddDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 40, 728, 504));
        widget->setMinimumSize(QSize(0, 504));
        widget->setMaximumSize(QSize(16777215, 504));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"        border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        frame_2 = new QFrame(widget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 314, 504));
        frame_2->setMinimumSize(QSize(314, 504));
        frame_2->setMaximumSize(QSize(314, 16777215));
        frame_2->setFrameShape(QFrame::Panel);
        widget_12 = new QWidget(frame_2);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setGeometry(QRect(10, 10, 301, 491));
        widget_12->setMinimumSize(QSize(285, 129));
        widget_12->setStyleSheet(QLatin1String("QWidget#widget_12 {\n"
"        background-color: rgb(255, 255, 255);\n"
"}"));
        pluLabel = new QLabel(widget_12);
        pluLabel->setObjectName(QStringLiteral("pluLabel"));
        pluLabel->setGeometry(QRect(10, 240, 71, 31));
        QFont font1;
        pluLabel->setFont(font1);
        pluLabel->setStyleSheet(QLatin1String("\n"
"        font-size:14px;\n"
"        color: rgb(51, 51, 51);\n"
""));
        pluLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        barCodelEdit = new QLineEdit(widget_12);
        barCodelEdit->setObjectName(QStringLiteral("barCodelEdit"));
        barCodelEdit->setGeometry(QRect(90, 240, 181, 31));
        barCodelEdit->setFont(font1);
        barCodelEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        barCodelEdit->setMaxLength(20);
        factAmtCouponLabel_3 = new QLabel(widget_12);
        factAmtCouponLabel_3->setObjectName(QStringLiteral("factAmtCouponLabel_3"));
        factAmtCouponLabel_3->setGeometry(QRect(100, 95, 161, 16));
        factAmtCouponLabel_3->setStyleSheet(QStringLiteral("color:red"));
        submitBtn = new QPushButton(widget_12);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));
        submitBtn->setGeometry(QRect(20, 440, 245, 42));
        submitBtn->setMinimumSize(QSize(245, 42));
        submitBtn->setFont(font1);
        submitBtn->setFocusPolicy(Qt::NoFocus);
        submitBtn->setStyleSheet(QLatin1String("QPushButton#submitBtn {\n"
"        color: rgb(255, 255, 255);\n"
"        font-size:16px;\n"
"        border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#submitBtn:pressed {\n"
"        border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        productNumLb = new QLabel(widget_12);
        productNumLb->setObjectName(QStringLiteral("productNumLb"));
        productNumLb->setGeometry(QRect(0, 0, 301, 31));
        productNumLb->setFont(font1);
        productNumLb->setStyleSheet(QLatin1String("font-size:14px;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        factAmtCouponLabel_4 = new QLabel(widget_12);
        factAmtCouponLabel_4->setObjectName(QStringLiteral("factAmtCouponLabel_4"));
        factAmtCouponLabel_4->setGeometry(QRect(10, 80, 72, 31));
        factAmtCouponLabel_4->setFont(font1);
        factAmtCouponLabel_4->setStyleSheet(QLatin1String("\n"
"        font-size:14px;\n"
"        color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        factAmtCouponLabel_5 = new QLabel(widget_12);
        factAmtCouponLabel_5->setObjectName(QStringLiteral("factAmtCouponLabel_5"));
        factAmtCouponLabel_5->setGeometry(QRect(10, 40, 72, 31));
        factAmtCouponLabel_5->setFont(font1);
        factAmtCouponLabel_5->setStyleSheet(QLatin1String("\n"
"        font-size:14px;\n"
"        color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        factAmtCouponLabel_2 = new QLabel(widget_12);
        factAmtCouponLabel_2->setObjectName(QStringLiteral("factAmtCouponLabel_2"));
        factAmtCouponLabel_2->setGeometry(QRect(10, 120, 72, 31));
        factAmtCouponLabel_2->setFont(font1);
        factAmtCouponLabel_2->setStyleSheet(QLatin1String("font-size:14px;\n"
"        color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        factAmtCouponLabel_6 = new QLabel(widget_12);
        factAmtCouponLabel_6->setObjectName(QStringLiteral("factAmtCouponLabel_6"));
        factAmtCouponLabel_6->setGeometry(QRect(10, 160, 72, 31));
        factAmtCouponLabel_6->setFont(font1);
        factAmtCouponLabel_6->setStyleSheet(QLatin1String("\n"
"        font-size:14px;\n"
"        color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bKindcBox = new QComboBox(widget_12);
        bKindcBox->setObjectName(QStringLiteral("bKindcBox"));
        bKindcBox->setGeometry(QRect(90, 40, 181, 31));
        bKindcBox->setFont(font1);
        bKindcBox->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        mKindcBox = new QComboBox(widget_12);
        mKindcBox->setObjectName(QStringLiteral("mKindcBox"));
        mKindcBox->setGeometry(QRect(90, 80, 181, 31));
        mKindcBox->setFont(font1);
        mKindcBox->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        sKindcBox = new QComboBox(widget_12);
        sKindcBox->setObjectName(QStringLiteral("sKindcBox"));
        sKindcBox->setGeometry(QRect(90, 120, 181, 31));
        sKindcBox->setFont(font1);
        sKindcBox->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        factAmtCouponLabel_7 = new QLabel(widget_12);
        factAmtCouponLabel_7->setObjectName(QStringLiteral("factAmtCouponLabel_7"));
        factAmtCouponLabel_7->setGeometry(QRect(10, 200, 72, 31));
        factAmtCouponLabel_7->setFont(font1);
        factAmtCouponLabel_7->setStyleSheet(QLatin1String("\n"
"        font-size:14px;\n"
"        color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        weighTypeCBox = new QComboBox(widget_12);
        weighTypeCBox->setObjectName(QStringLiteral("weighTypeCBox"));
        weighTypeCBox->setGeometry(QRect(90, 200, 181, 31));
        weighTypeCBox->setFont(font1);
        weighTypeCBox->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        basicUnitCBox = new QComboBox(widget_12);
        basicUnitCBox->setObjectName(QStringLiteral("basicUnitCBox"));
        basicUnitCBox->setGeometry(QRect(90, 280, 181, 31));
        basicUnitCBox->setFont(font1);
        basicUnitCBox->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        factAmtCouponLabel_8 = new QLabel(widget_12);
        factAmtCouponLabel_8->setObjectName(QStringLiteral("factAmtCouponLabel_8"));
        factAmtCouponLabel_8->setGeometry(QRect(10, 280, 72, 31));
        factAmtCouponLabel_8->setFont(font1);
        factAmtCouponLabel_8->setStyleSheet(QLatin1String("\n"
"        font-size:14px;\n"
"        color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        factAmtCouponLabel_9 = new QLabel(widget_12);
        factAmtCouponLabel_9->setObjectName(QStringLiteral("factAmtCouponLabel_9"));
        factAmtCouponLabel_9->setGeometry(QRect(10, 320, 72, 31));
        factAmtCouponLabel_9->setFont(font1);
        factAmtCouponLabel_9->setStyleSheet(QLatin1String("\n"
"        font-size:14px;\n"
"        color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        getGoodslEdit = new QLineEdit(widget_12);
        getGoodslEdit->setObjectName(QStringLiteral("getGoodslEdit"));
        getGoodslEdit->setGeometry(QRect(90, 320, 61, 31));
        getGoodslEdit->setFont(font1);
        getGoodslEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        getGoodslEdit->setMaxLength(6);
        factAmtCouponLabel_10 = new QLabel(widget_12);
        factAmtCouponLabel_10->setObjectName(QStringLiteral("factAmtCouponLabel_10"));
        factAmtCouponLabel_10->setGeometry(QRect(180, 320, 16, 31));
        factAmtCouponLabel_10->setFont(font1);
        factAmtCouponLabel_10->setStyleSheet(QLatin1String("font-size:18px;\n"
"color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        wUnitCBox = new QComboBox(widget_12);
        wUnitCBox->setObjectName(QStringLiteral("wUnitCBox"));
        wUnitCBox->setGeometry(QRect(200, 320, 71, 31));
        wUnitCBox->setFont(font1);
        wUnitCBox->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        factAmtCouponLabel_11 = new QLabel(widget_12);
        factAmtCouponLabel_11->setObjectName(QStringLiteral("factAmtCouponLabel_11"));
        factAmtCouponLabel_11->setGeometry(QRect(10, 360, 72, 31));
        factAmtCouponLabel_11->setFont(font1);
        factAmtCouponLabel_11->setStyleSheet(QLatin1String("\n"
"        font-size:14px;\n"
"        color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        referPricelEdit = new QLineEdit(widget_12);
        referPricelEdit->setObjectName(QStringLiteral("referPricelEdit"));
        referPricelEdit->setGeometry(QRect(90, 360, 181, 31));
        referPricelEdit->setFont(font1);
        referPricelEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        referPricelEdit->setMaxLength(6);
        factAmtCouponLabel_12 = new QLabel(widget_12);
        factAmtCouponLabel_12->setObjectName(QStringLiteral("factAmtCouponLabel_12"));
        factAmtCouponLabel_12->setGeometry(QRect(10, 400, 41, 31));
        factAmtCouponLabel_12->setFont(font1);
        factAmtCouponLabel_12->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        factAmtCouponLabel_13 = new QLabel(widget_12);
        factAmtCouponLabel_13->setObjectName(QStringLiteral("factAmtCouponLabel_13"));
        factAmtCouponLabel_13->setGeometry(QRect(130, 400, 61, 31));
        factAmtCouponLabel_13->setFont(font1);
        factAmtCouponLabel_13->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(51, 51, 51);\n"
""));
        factAmtCouponLabel_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        wUnitlabel = new QLabel(widget_12);
        wUnitlabel->setObjectName(QStringLiteral("wUnitlabel"));
        wUnitlabel->setGeometry(QRect(150, 320, 31, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        wUnitlabel->setFont(font2);
        wUnitlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        goodsNameWidget = new SearchEdit(widget_12);
        goodsNameWidget->setObjectName(QStringLiteral("goodsNameWidget"));
        goodsNameWidget->setGeometry(QRect(90, 160, 181, 31));
        goodsNameWidget->setStyleSheet(QStringLiteral(""));
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
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        factorButton->setFont(font3);
        factorButton->setFocusPolicy(Qt::NoFocus);
        factorButton->setStyleSheet(QString::fromUtf8("QPushButton#factorButton{\n"
"        font:20px;\n"
"        font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"        color: rgb(255,255,255);\n"
"        border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#factorButton:pressed{\n"
"        border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        gridLayout->addWidget(factorButton, 0, 0, 1, 1);

        fiftyButton = new QPushButton(widget_8);
        fiftyButton->setObjectName(QStringLiteral("fiftyButton"));
        sizePolicy.setHeightForWidth(fiftyButton->sizePolicy().hasHeightForWidth());
        fiftyButton->setSizePolicy(sizePolicy);
        fiftyButton->setMinimumSize(QSize(76, 72));
        fiftyButton->setMaximumSize(QSize(16777215, 16777215));
        fiftyButton->setFont(font3);
        fiftyButton->setFocusPolicy(Qt::NoFocus);
        fiftyButton->setStyleSheet(QString::fromUtf8("QPushButton#fiftyButton{\n"
"        font:20px;\n"
"        font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"        color: rgb(255,255,255);\n"
"        border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#fiftyButton:pressed{\n"
"        border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        gridLayout->addWidget(fiftyButton, 1, 0, 1, 1);

        hundredButton = new QPushButton(widget_8);
        hundredButton->setObjectName(QStringLiteral("hundredButton"));
        sizePolicy.setHeightForWidth(hundredButton->sizePolicy().hasHeightForWidth());
        hundredButton->setSizePolicy(sizePolicy);
        hundredButton->setMinimumSize(QSize(76, 72));
        hundredButton->setMaximumSize(QSize(16777215, 16777215));
        hundredButton->setFont(font3);
        hundredButton->setFocusPolicy(Qt::NoFocus);
        hundredButton->setStyleSheet(QString::fromUtf8("QPushButton#hundredButton{\n"
"        font:20px;\n"
"        font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"        color: rgb(255,255,255);\n"
"        border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#hundredButton:pressed{\n"
"        border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        gridLayout->addWidget(hundredButton, 2, 0, 1, 1);

        twoHundredButton = new QPushButton(widget_8);
        twoHundredButton->setObjectName(QStringLiteral("twoHundredButton"));
        sizePolicy.setHeightForWidth(twoHundredButton->sizePolicy().hasHeightForWidth());
        twoHundredButton->setSizePolicy(sizePolicy);
        twoHundredButton->setMinimumSize(QSize(76, 72));
        twoHundredButton->setMaximumSize(QSize(16777215, 16777215));
        twoHundredButton->setFont(font3);
        twoHundredButton->setFocusPolicy(Qt::NoFocus);
        twoHundredButton->setStyleSheet(QString::fromUtf8("QPushButton#twoHundredButton{\n"
"        font:20px;\n"
"        font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"        color: rgb(255,255,255);\n"
"        border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#twoHundredButton:pressed{\n"
"        border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
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
        pricelEdit = new QLineEdit(QuickAddDlg);
        pricelEdit->setObjectName(QStringLiteral("pricelEdit"));
        pricelEdit->setGeometry(QRect(70, 450, 61, 31));
        pricelEdit->setFont(font1);
        pricelEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        pricelEdit->setMaxLength(6);
        memPricelEdit = new QLineEdit(QuickAddDlg);
        memPricelEdit->setObjectName(QStringLiteral("memPricelEdit"));
        memPricelEdit->setGeometry(QRect(200, 450, 81, 31));
        memPricelEdit->setFont(font1);
        memPricelEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        memPricelEdit->setMaxLength(6);
        titleWidget = new QWidget(QuickAddDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setGeometry(QRect(0, 0, 728, 40));
        titleWidget->setStyleSheet(QLatin1String("QWidget#titleWidget{\n"
"	border-image: url(:/shareImages/title_bar.png);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(titleWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(30, 4, 13, 5);
        titleLabel = new QLabel(titleWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel#titleLabel {\n"
"	font-size: 16px;\n"
"	color: rgb(255, 255, 255);\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        horizontalLayout_2->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(912, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        closeButton = new QPushButton(titleWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(31, 31));
        closeButton->setMaximumSize(QSize(31, 31));
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/shareImages/close.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	border-image: url(:/shareImages/close_press.png);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(closeButton);


        retranslateUi(QuickAddDlg);

        QMetaObject::connectSlotsByName(QuickAddDlg);
    } // setupUi

    void retranslateUi(QDialog *QuickAddDlg)
    {
        QuickAddDlg->setWindowTitle(QApplication::translate("QuickAddDlg", "StatementDlg", Q_NULLPTR));
        pluLabel->setText(QApplication::translate("QuickAddDlg", "\346\235\241\347\240\201\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_3->setText(QString());
        submitBtn->setText(QApplication::translate("QuickAddDlg", "\346\217\220\344\272\244", Q_NULLPTR));
        productNumLb->setText(QApplication::translate("QuickAddDlg", "  \345\225\206\345\223\201\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_4->setText(QApplication::translate("QuickAddDlg", "\344\270\255\347\261\273\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_5->setText(QApplication::translate("QuickAddDlg", "\345\244\247\347\261\273\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_2->setText(QApplication::translate("QuickAddDlg", "\345\260\217\347\261\273\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_6->setText(QApplication::translate("QuickAddDlg", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_7->setText(QApplication::translate("QuickAddDlg", "\347\247\260\351\207\215\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        weighTypeCBox->clear();
        weighTypeCBox->insertItems(0, QStringList()
         << QApplication::translate("QuickAddDlg", "\346\240\207\345\223\201", Q_NULLPTR)
         << QApplication::translate("QuickAddDlg", "\350\256\241\351\207\215", Q_NULLPTR)
         << QApplication::translate("QuickAddDlg", "\350\256\241\346\225\260", Q_NULLPTR)
        );
        factAmtCouponLabel_8->setText(QApplication::translate("QuickAddDlg", "\346\234\200\345\260\217\350\247\204\346\240\274\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_9->setText(QApplication::translate("QuickAddDlg", "\350\246\201\350\264\247\350\247\204\346\240\274\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_10->setText(QApplication::translate("QuickAddDlg", "/", Q_NULLPTR));
        factAmtCouponLabel_11->setText(QApplication::translate("QuickAddDlg", "\345\217\202\350\200\203\350\277\233\344\273\267\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_12->setText(QApplication::translate("QuickAddDlg", "\345\224\256\344\273\267\357\274\232", Q_NULLPTR));
        factAmtCouponLabel_13->setText(QApplication::translate("QuickAddDlg", "\344\274\232\345\221\230\344\273\267\357\274\232", Q_NULLPTR));
        wUnitlabel->setText(QApplication::translate("QuickAddDlg", "\345\205\254\346\226\244", Q_NULLPTR));
        factorButton->setText(QString());
        fiftyButton->setText(QString());
        hundredButton->setText(QString());
        twoHundredButton->setText(QString());
        titleLabel->setText(QApplication::translate("QuickAddDlg", "TextLabel", Q_NULLPTR));
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QuickAddDlg: public Ui_QuickAddDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICKADDDLG_H
