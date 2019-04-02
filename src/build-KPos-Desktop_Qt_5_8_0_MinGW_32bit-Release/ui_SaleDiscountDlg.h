/********************************************************************************
** Form generated from reading UI file 'SaleDiscountDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEDISCOUNTDLG_H
#define UI_SALEDISCOUNTDLG_H

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

class Ui_SaleDiscountDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    TitleBarWidget *titleWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_1;
    QGridLayout *gridLayout;
    QWidget *discountInfoWidget;
    QFrame *line_3;
    QLabel *originalAmtLabel;
    QLabel *originalAmtValueLabel;
    QLabel *discountValueLabel;
    QLabel *discountLabel;
    QWidget *widget_3;
    QLabel *rediscountLabel;
    QLineEdit *rediscountEdit;
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

    void setupUi(QDialog *SaleDiscountDlg)
    {
        if (SaleDiscountDlg->objectName().isEmpty())
            SaleDiscountDlg->setObjectName(QStringLiteral("SaleDiscountDlg"));
        SaleDiscountDlg->resize(735, 495);
        verticalLayout_2 = new QVBoxLayout(SaleDiscountDlg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(SaleDiscountDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(727, 40));
        titleWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(titleWidget);

        widget = new QWidget(SaleDiscountDlg);
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
        discountInfoWidget->setMinimumSize(QSize(285, 86));
        discountInfoWidget->setStyleSheet(QStringLiteral("background-color: rgb(237, 237, 237);"));
        line_3 = new QFrame(discountInfoWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 157, 410, 2));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        originalAmtLabel = new QLabel(discountInfoWidget);
        originalAmtLabel->setObjectName(QStringLiteral("originalAmtLabel"));
        originalAmtLabel->setGeometry(QRect(10, 14, 52, 19));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        originalAmtLabel->setFont(font);
        originalAmtLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        originalAmtValueLabel = new QLabel(discountInfoWidget);
        originalAmtValueLabel->setObjectName(QStringLiteral("originalAmtValueLabel"));
        originalAmtValueLabel->setGeometry(QRect(175, 14, 91, 22));
        originalAmtValueLabel->setFont(font);
        originalAmtValueLabel->setStyleSheet(QString::fromUtf8("font: 22px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        originalAmtValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        discountValueLabel = new QLabel(discountInfoWidget);
        discountValueLabel->setObjectName(QStringLiteral("discountValueLabel"));
        discountValueLabel->setGeometry(QRect(174, 50, 91, 22));
        discountValueLabel->setFont(font);
        discountValueLabel->setStyleSheet(QString::fromUtf8("font: 22px;\n"
"color: rgb(234, 136, 82);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        discountValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        discountLabel = new QLabel(discountInfoWidget);
        discountLabel->setObjectName(QStringLiteral("discountLabel"));
        discountLabel->setGeometry(QRect(10, 50, 39, 19));
        discountLabel->setFont(font);
        discountLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(discountInfoWidget, 0, 0, 1, 1);

        widget_3 = new QWidget(widget_1);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(285, 323));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        rediscountLabel = new QLabel(widget_3);
        rediscountLabel->setObjectName(QStringLiteral("rediscountLabel"));
        rediscountLabel->setGeometry(QRect(20, 25, 61, 31));
        rediscountLabel->setFont(font);
        rediscountLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        rediscountEdit = new QLineEdit(widget_3);
        rediscountEdit->setObjectName(QStringLiteral("rediscountEdit"));
        rediscountEdit->setGeometry(QRect(80, 25, 185, 31));
        rediscountEdit->setFont(font);
        rediscountEdit->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        transAmtLabel = new QLabel(widget_3);
        transAmtLabel->setObjectName(QStringLiteral("transAmtLabel"));
        transAmtLabel->setGeometry(QRect(20, 90, 81, 30));
        transAmtLabel->setMinimumSize(QSize(0, 30));
        transAmtLabel->setFont(font);
        transAmtLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        disAmtLabel = new QLabel(widget_3);
        disAmtLabel->setObjectName(QStringLiteral("disAmtLabel"));
        disAmtLabel->setGeometry(QRect(20, 120, 81, 30));
        disAmtLabel->setMinimumSize(QSize(0, 30));
        disAmtLabel->setFont(font);
        disAmtLabel->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: rgb(51, 51, 51);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        transAmtValueLabel = new QLabel(widget_3);
        transAmtValueLabel->setObjectName(QStringLiteral("transAmtValueLabel"));
        transAmtValueLabel->setGeometry(QRect(144, 90, 121, 30));
        transAmtValueLabel->setMinimumSize(QSize(0, 30));
        transAmtValueLabel->setFont(font);
        transAmtValueLabel->setStyleSheet(QString::fromUtf8("font: 22px;\n"
"color: rgb(234, 136, 82);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        transAmtValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        disAmtValueLabel = new QLabel(widget_3);
        disAmtValueLabel->setObjectName(QStringLiteral("disAmtValueLabel"));
        disAmtValueLabel->setGeometry(QRect(144, 120, 121, 30));
        disAmtValueLabel->setMinimumSize(QSize(0, 30));
        disAmtValueLabel->setFont(font);
        disAmtValueLabel->setStyleSheet(QString::fromUtf8("font: 16px;\n"
"color: rgb(51\357\274\21451\357\274\21451);\n"
"font: bold;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        disAmtValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        disCommitBtn = new QPushButton(widget_3);
        disCommitBtn->setObjectName(QStringLiteral("disCommitBtn"));
        disCommitBtn->setGeometry(QRect(18, 250, 251, 51));
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
        line_4->setGeometry(QRect(0, 80, 285, 2));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 60, 185, 16));
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
        twentyButton->setStyleSheet(QString::fromUtf8("QPushButton#twentyButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"/*QPushButton#twentyButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}*/"));

        verticalLayout->addWidget(twentyButton);

        fiftyButton = new QPushButton(widget_2);
        fiftyButton->setObjectName(QStringLiteral("fiftyButton"));
        sizePolicy.setHeightForWidth(fiftyButton->sizePolicy().hasHeightForWidth());
        fiftyButton->setSizePolicy(sizePolicy);
        fiftyButton->setMinimumSize(QSize(76, 71));
        fiftyButton->setFocusPolicy(Qt::NoFocus);
        fiftyButton->setStyleSheet(QString::fromUtf8("QPushButton#fiftyButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"/*QPushButton#fiftyButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}*/"));

        verticalLayout->addWidget(fiftyButton);

        hundredButton = new QPushButton(widget_2);
        hundredButton->setObjectName(QStringLiteral("hundredButton"));
        sizePolicy.setHeightForWidth(hundredButton->sizePolicy().hasHeightForWidth());
        hundredButton->setSizePolicy(sizePolicy);
        hundredButton->setMinimumSize(QSize(76, 71));
        hundredButton->setFocusPolicy(Qt::NoFocus);
        hundredButton->setStyleSheet(QString::fromUtf8("QPushButton#hundredButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"/*QPushButton#hundredButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}*/"));

        verticalLayout->addWidget(hundredButton);

        twoHundredButton = new QPushButton(widget_2);
        twoHundredButton->setObjectName(QStringLiteral("twoHundredButton"));
        sizePolicy.setHeightForWidth(twoHundredButton->sizePolicy().hasHeightForWidth());
        twoHundredButton->setSizePolicy(sizePolicy);
        twoHundredButton->setMinimumSize(QSize(76, 71));
        twoHundredButton->setFocusPolicy(Qt::NoFocus);
        twoHundredButton->setStyleSheet(QString::fromUtf8("QPushButton#twoHundredButton{\n"
"	font:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255,255,255);\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_normal.png);\n"
"}\n"
"\n"
"/*QPushButton#twoHundredButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/foreign_key_press.png);\n"
"}*/"));

        verticalLayout->addWidget(twoHundredButton);


        horizontalLayout->addLayout(verticalLayout);

        DigitalKeyWnd = new WndDigitalKeyboard(widget_2);
        DigitalKeyWnd->setObjectName(QStringLiteral("DigitalKeyWnd"));
        DigitalKeyWnd->setMinimumSize(QSize(303, 303));

        horizontalLayout->addWidget(DigitalKeyWnd);

        horizontalLayout->setStretch(0, 1);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(widget_2);


        verticalLayout_2->addWidget(widget);


        retranslateUi(SaleDiscountDlg);

        QMetaObject::connectSlotsByName(SaleDiscountDlg);
    } // setupUi

    void retranslateUi(QDialog *SaleDiscountDlg)
    {
        SaleDiscountDlg->setWindowTitle(QApplication::translate("SaleDiscountDlg", "SaleDiscountDlg", Q_NULLPTR));
        originalAmtLabel->setText(QApplication::translate("SaleDiscountDlg", "\345\216\237\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        originalAmtValueLabel->setText(QApplication::translate("SaleDiscountDlg", "\357\277\24512.00", Q_NULLPTR));
        discountValueLabel->setText(QApplication::translate("SaleDiscountDlg", "9\346\212\230", Q_NULLPTR));
        discountLabel->setText(QApplication::translate("SaleDiscountDlg", "\346\212\230\346\211\243\357\274\232", Q_NULLPTR));
        rediscountLabel->setText(QApplication::translate("SaleDiscountDlg", "\347\216\260\346\212\230\346\211\243\357\274\232", Q_NULLPTR));
        transAmtLabel->setText(QApplication::translate("SaleDiscountDlg", "\346\210\220\344\272\244\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        disAmtLabel->setText(QApplication::translate("SaleDiscountDlg", "\344\274\230\346\203\240\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        transAmtValueLabel->setText(QApplication::translate("SaleDiscountDlg", "\357\277\24527.02", Q_NULLPTR));
        disAmtValueLabel->setText(QApplication::translate("SaleDiscountDlg", "\357\277\24527.02", Q_NULLPTR));
        disCommitBtn->setText(QApplication::translate("SaleDiscountDlg", "\346\217\220\344\272\244", Q_NULLPTR));
        label->setText(QString());
        twentyButton->setText(QString());
        fiftyButton->setText(QString());
        hundredButton->setText(QString());
        twoHundredButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SaleDiscountDlg: public Ui_SaleDiscountDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEDISCOUNTDLG_H
