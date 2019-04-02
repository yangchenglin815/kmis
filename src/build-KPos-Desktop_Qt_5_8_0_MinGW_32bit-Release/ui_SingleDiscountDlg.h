/********************************************************************************
** Form generated from reading UI file 'SingleDiscountDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEDISCOUNTDLG_H
#define UI_SINGLEDISCOUNTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>
#include <WndDigitalKeyboard.h>

QT_BEGIN_NAMESPACE

class Ui_SingleDiscountDlg
{
public:
    QGridLayout *gridLayout_3;
    TitleBarWidget *titleWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_1;
    QGridLayout *gridLayout;
    QWidget *discountInfoWidget;
    QFrame *line;
    QFrame *line_3;
    QLabel *goodsNameValueLabel;
    QLabel *goodsNameLabel;
    QLabel *barCodeLabel;
    QLabel *barCodeValueLabel;
    QLabel *originalAmtLabel;
    QLabel *originalAmtValueLabel;
    QLabel *discountValueLabel;
    QLabel *discountLabel;
    QWidget *widget_3;
    QLabel *rediscountLabel;
    QLabel *nowAmtLabel;
    QLineEdit *rediscountEdit;
    QLineEdit *nowAmtEdit;
    QLabel *transAmtLabel;
    QLabel *disAmtLabel;
    QLabel *transAmtValueLabel;
    QLabel *disAmtValueLabel;
    QPushButton *disCommitBtn;
    QFrame *line_4;
    QLabel *label;
    QFrame *line_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *twentyButton;
    QPushButton *fiftyButton;
    QPushButton *hundredButton;
    QPushButton *twoHundredButton;
    WndDigitalKeyboard *DigitalKeyWnd;

    void setupUi(QDialog *SingleDiscountDlg)
    {
        if (SingleDiscountDlg->objectName().isEmpty())
            SingleDiscountDlg->setObjectName(QStringLiteral("SingleDiscountDlg"));
        SingleDiscountDlg->resize(727, 482);
        SingleDiscountDlg->setMinimumSize(QSize(727, 482));
        SingleDiscountDlg->setStyleSheet(QStringLiteral(""));
        gridLayout_3 = new QGridLayout(SingleDiscountDlg);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(SingleDiscountDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(727, 40));
        titleWidget->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(titleWidget, 0, 0, 1, 1);

        widget = new QWidget(SingleDiscountDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_1 = new QWidget(widget);
        widget_1->setObjectName(QStringLiteral("widget_1"));
        widget_1->setMinimumSize(QSize(315, 430));
        widget_1->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(widget_1);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(15, 12, 15, 20);
        discountInfoWidget = new QWidget(widget_1);
        discountInfoWidget->setObjectName(QStringLiteral("discountInfoWidget"));
        discountInfoWidget->setMinimumSize(QSize(285, 126));
        discountInfoWidget->setStyleSheet(QStringLiteral("background-color: rgb(237, 237, 237);"));
        line = new QFrame(discountInfoWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 58, 285, 2));
        line->setMinimumSize(QSize(285, 2));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(discountInfoWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 157, 410, 2));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        goodsNameValueLabel = new QLabel(discountInfoWidget);
        goodsNameValueLabel->setObjectName(QStringLiteral("goodsNameValueLabel"));
        goodsNameValueLabel->setGeometry(QRect(80, 8, 150, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        goodsNameValueLabel->setFont(font);
        goodsNameValueLabel->setStyleSheet(QString::fromUtf8("font: 12px bold rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        goodsNameLabel = new QLabel(discountInfoWidget);
        goodsNameLabel->setObjectName(QStringLiteral("goodsNameLabel"));
        goodsNameLabel->setGeometry(QRect(11, 10, 65, 19));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        goodsNameLabel->setFont(font1);
        goodsNameLabel->setStyleSheet(QString::fromUtf8("font: 12px  rgb(51, 51, 51);\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        barCodeLabel = new QLabel(discountInfoWidget);
        barCodeLabel->setObjectName(QStringLiteral("barCodeLabel"));
        barCodeLabel->setGeometry(QRect(11, 30, 61, 19));
        barCodeLabel->setFont(font1);
        barCodeLabel->setStyleSheet(QString::fromUtf8("font: 12px bold rgb(51, 51, 51);\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        barCodeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        barCodeValueLabel = new QLabel(discountInfoWidget);
        barCodeValueLabel->setObjectName(QStringLiteral("barCodeValueLabel"));
        barCodeValueLabel->setGeometry(QRect(80, 30, 150, 21));
        barCodeValueLabel->setFont(font);
        barCodeValueLabel->setStyleSheet(QString::fromUtf8("font: 12px bold rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        originalAmtLabel = new QLabel(discountInfoWidget);
        originalAmtLabel->setObjectName(QStringLiteral("originalAmtLabel"));
        originalAmtLabel->setGeometry(QRect(10, 68, 52, 19));
        originalAmtLabel->setFont(font);
        originalAmtLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        originalAmtValueLabel = new QLabel(discountInfoWidget);
        originalAmtValueLabel->setObjectName(QStringLiteral("originalAmtValueLabel"));
        originalAmtValueLabel->setGeometry(QRect(125, 68, 140, 22));
        originalAmtValueLabel->setFont(font);
        originalAmtValueLabel->setStyleSheet(QString::fromUtf8("font: 22px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        originalAmtValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        discountValueLabel = new QLabel(discountInfoWidget);
        discountValueLabel->setObjectName(QStringLiteral("discountValueLabel"));
        discountValueLabel->setGeometry(QRect(125, 96, 140, 22));
        discountValueLabel->setFont(font);
        discountValueLabel->setStyleSheet(QString::fromUtf8("font: 22px;\n"
"color: rgb(234, 136, 82);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        discountValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        discountLabel = new QLabel(discountInfoWidget);
        discountLabel->setObjectName(QStringLiteral("discountLabel"));
        discountLabel->setGeometry(QRect(10, 96, 39, 19));
        discountLabel->setFont(font);
        discountLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(discountInfoWidget, 0, 0, 1, 1);

        widget_3 = new QWidget(widget_1);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(285, 285));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        rediscountLabel = new QLabel(widget_3);
        rediscountLabel->setObjectName(QStringLiteral("rediscountLabel"));
        rediscountLabel->setGeometry(QRect(20, 18, 61, 31));
        rediscountLabel->setFont(font);
        rediscountLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        nowAmtLabel = new QLabel(widget_3);
        nowAmtLabel->setObjectName(QStringLiteral("nowAmtLabel"));
        nowAmtLabel->setGeometry(QRect(20, 69, 61, 31));
        nowAmtLabel->setFont(font);
        nowAmtLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        rediscountEdit = new QLineEdit(widget_3);
        rediscountEdit->setObjectName(QStringLiteral("rediscountEdit"));
        rediscountEdit->setGeometry(QRect(80, 18, 185, 31));
        rediscountEdit->setFont(font);
        rediscountEdit->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        nowAmtEdit = new QLineEdit(widget_3);
        nowAmtEdit->setObjectName(QStringLiteral("nowAmtEdit"));
        nowAmtEdit->setGeometry(QRect(80, 69, 185, 31));
        nowAmtEdit->setFont(font);
        nowAmtEdit->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        transAmtLabel = new QLabel(widget_3);
        transAmtLabel->setObjectName(QStringLiteral("transAmtLabel"));
        transAmtLabel->setGeometry(QRect(26, 130, 81, 30));
        transAmtLabel->setMinimumSize(QSize(0, 30));
        transAmtLabel->setFont(font);
        transAmtLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        disAmtLabel = new QLabel(widget_3);
        disAmtLabel->setObjectName(QStringLiteral("disAmtLabel"));
        disAmtLabel->setGeometry(QRect(26, 160, 81, 30));
        disAmtLabel->setMinimumSize(QSize(0, 30));
        disAmtLabel->setFont(font);
        disAmtLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        transAmtValueLabel = new QLabel(widget_3);
        transAmtValueLabel->setObjectName(QStringLiteral("transAmtValueLabel"));
        transAmtValueLabel->setGeometry(QRect(125, 130, 140, 30));
        transAmtValueLabel->setMinimumSize(QSize(0, 30));
        transAmtValueLabel->setFont(font);
        transAmtValueLabel->setStyleSheet(QString::fromUtf8("font: 22px;\n"
"color: rgb(234, 136, 82);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        transAmtValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        disAmtValueLabel = new QLabel(widget_3);
        disAmtValueLabel->setObjectName(QStringLiteral("disAmtValueLabel"));
        disAmtValueLabel->setGeometry(QRect(125, 160, 140, 30));
        disAmtValueLabel->setMinimumSize(QSize(0, 30));
        disAmtValueLabel->setFont(font);
        disAmtValueLabel->setStyleSheet(QString::fromUtf8("font: 16px;\n"
"color: rgb(51\357\274\21451\357\274\21451);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        disAmtValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        disCommitBtn = new QPushButton(widget_3);
        disCommitBtn->setObjectName(QStringLiteral("disCommitBtn"));
        disCommitBtn->setGeometry(QRect(18, 220, 251, 51));
        disCommitBtn->setFocusPolicy(Qt::NoFocus);
        disCommitBtn->setStyleSheet(QString::fromUtf8("QPushButton#disCommitBtn {\n"
"	font:16px;\n"
"	color: rgb(255, 255, 255);\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#disCommitBtn:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));
        line_4 = new QFrame(widget_3);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 120, 281, 2));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 50, 185, 16));
        label->setStyleSheet(QStringLiteral("color: rgb(250, 122, 122);"));

        gridLayout->addWidget(widget_3, 1, 0, 1, 1);


        horizontalLayout_2->addWidget(widget_1);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(15, 10, 13, 130);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        twentyButton = new QPushButton(widget_2);
        twentyButton->setObjectName(QStringLiteral("twentyButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(twentyButton->sizePolicy().hasHeightForWidth());
        twentyButton->setSizePolicy(sizePolicy);
        twentyButton->setMinimumSize(QSize(76, 71));
        twentyButton->setFocusPolicy(Qt::NoFocus);
        twentyButton->setStyleSheet(QString::fromUtf8("QPushButton#factorBtn{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#factorBtn:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        verticalLayout->addWidget(twentyButton);

        fiftyButton = new QPushButton(widget_2);
        fiftyButton->setObjectName(QStringLiteral("fiftyButton"));
        sizePolicy.setHeightForWidth(fiftyButton->sizePolicy().hasHeightForWidth());
        fiftyButton->setSizePolicy(sizePolicy);
        fiftyButton->setMinimumSize(QSize(76, 71));
        fiftyButton->setFocusPolicy(Qt::NoFocus);
        fiftyButton->setStyleSheet(QString::fromUtf8("QPushButton#fiftyBtn{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#fiftyBtn:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        verticalLayout->addWidget(fiftyButton);

        hundredButton = new QPushButton(widget_2);
        hundredButton->setObjectName(QStringLiteral("hundredButton"));
        sizePolicy.setHeightForWidth(hundredButton->sizePolicy().hasHeightForWidth());
        hundredButton->setSizePolicy(sizePolicy);
        hundredButton->setMinimumSize(QSize(76, 71));
        hundredButton->setFocusPolicy(Qt::NoFocus);
        hundredButton->setStyleSheet(QString::fromUtf8("QPushButton#hundredBtn{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#hundredBtn:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        verticalLayout->addWidget(hundredButton);

        twoHundredButton = new QPushButton(widget_2);
        twoHundredButton->setObjectName(QStringLiteral("twoHundredButton"));
        sizePolicy.setHeightForWidth(twoHundredButton->sizePolicy().hasHeightForWidth());
        twoHundredButton->setSizePolicy(sizePolicy);
        twoHundredButton->setMinimumSize(QSize(76, 71));
        twoHundredButton->setFocusPolicy(Qt::NoFocus);
        twoHundredButton->setStyleSheet(QString::fromUtf8("QPushButton#twoHundredBtn{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"QPushButton#twoHundredBtn:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}"));

        verticalLayout->addWidget(twoHundredButton);


        horizontalLayout->addLayout(verticalLayout);

        DigitalKeyWnd = new WndDigitalKeyboard(widget_2);
        DigitalKeyWnd->setObjectName(QStringLiteral("DigitalKeyWnd"));
        DigitalKeyWnd->setMinimumSize(QSize(303, 303));

        horizontalLayout->addWidget(DigitalKeyWnd);

        horizontalLayout->setStretch(0, 1);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(widget_2);


        gridLayout_3->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(SingleDiscountDlg);

        QMetaObject::connectSlotsByName(SingleDiscountDlg);
    } // setupUi

    void retranslateUi(QDialog *SingleDiscountDlg)
    {
        SingleDiscountDlg->setWindowTitle(QApplication::translate("SingleDiscountDlg", "SingleDiscountDlg", Q_NULLPTR));
        goodsNameValueLabel->setText(QApplication::translate("SingleDiscountDlg", "\346\260\264\350\234\234\346\241\203", Q_NULLPTR));
        goodsNameLabel->setText(QApplication::translate("SingleDiscountDlg", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        barCodeLabel->setText(QApplication::translate("SingleDiscountDlg", "\346\235\241\347\240\201\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        barCodeValueLabel->setText(QApplication::translate("SingleDiscountDlg", "235254478", Q_NULLPTR));
        originalAmtLabel->setText(QApplication::translate("SingleDiscountDlg", "\345\216\237\345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        originalAmtValueLabel->setText(QApplication::translate("SingleDiscountDlg", "\357\277\24512.00", Q_NULLPTR));
        discountValueLabel->setText(QApplication::translate("SingleDiscountDlg", "9\346\212\230", Q_NULLPTR));
        discountLabel->setText(QApplication::translate("SingleDiscountDlg", "\346\212\230\346\211\243\357\274\232", Q_NULLPTR));
        rediscountLabel->setText(QApplication::translate("SingleDiscountDlg", "\347\216\260\346\212\230\346\211\243\357\274\232", Q_NULLPTR));
        nowAmtLabel->setText(QApplication::translate("SingleDiscountDlg", "\347\216\260\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        transAmtLabel->setText(QApplication::translate("SingleDiscountDlg", "\346\210\220\344\272\244\345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        disAmtLabel->setText(QApplication::translate("SingleDiscountDlg", "\344\274\230\346\203\240\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        transAmtValueLabel->setText(QApplication::translate("SingleDiscountDlg", "\357\277\24527.02", Q_NULLPTR));
        disAmtValueLabel->setText(QApplication::translate("SingleDiscountDlg", "\357\277\24527.02", Q_NULLPTR));
        disCommitBtn->setText(QApplication::translate("SingleDiscountDlg", "\346\217\220\344\272\244", Q_NULLPTR));
        label->setText(QString());
        twentyButton->setText(QApplication::translate("SingleDiscountDlg", "\357\277\24520", Q_NULLPTR));
        fiftyButton->setText(QApplication::translate("SingleDiscountDlg", "\357\277\24550", Q_NULLPTR));
        hundredButton->setText(QApplication::translate("SingleDiscountDlg", "\357\277\245100", Q_NULLPTR));
        twoHundredButton->setText(QApplication::translate("SingleDiscountDlg", "\357\277\245200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SingleDiscountDlg: public Ui_SingleDiscountDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEDISCOUNTDLG_H
