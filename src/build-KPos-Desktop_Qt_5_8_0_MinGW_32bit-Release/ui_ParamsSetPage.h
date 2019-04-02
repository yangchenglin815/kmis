/********************************************************************************
** Form generated from reading UI file 'ParamsSetPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMSSETPAGE_H
#define UI_PARAMSSETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ParamsShopSetWidget.h"
#include "SearchEdit.h"
#include "SwitchButton.h"

QT_BEGIN_NAMESPACE

class Ui_ParamsSetPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *systemWidget;
    QHBoxLayout *horizontalLayout_25;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QLabel *discountBaseMemberLabel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *priceSaleLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *priceSaleLimitLabel;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *discardZeroLabel;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QLabel *maxGoodsSaleNumberLabel;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_2;
    QLabel *maxSaveDaysLabel;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QLabel *fillReasonForRefundLabel;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_13;
    QWidget *widget_16;
    QLabel *label_72;
    QPushButton *updateOtherPosButton;
    ParamsShopSetWidget *shopParamsWidget;
    QLabel *label_18;
    QLabel *label_16;
    QLabel *label_10;
    QLabel *label_14;
    SwitchButton *chooseSalesmanButton;
    SwitchButton *sellZeroPriceGoodsButton;
    SwitchButton *openCashboxButton;
    QLabel *label_13;
    SwitchButton *createGoodsButton;
    SwitchButton *changePriceButton;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    SwitchButton *handinCashButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *pending0RButton;
    QRadioButton *pending1RButton;
    QRadioButton *pending2RButton;
    QRadioButton *pending3RButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *lock0RButton;
    QRadioButton *lock1RButton;
    QRadioButton *lock2RButton;
    QRadioButton *lock3RButton;
    QRadioButton *lock4RButton;
    QLabel *label_19;
    SearchEdit *nameWidget;

    void setupUi(QWidget *ParamsSetPage)
    {
        if (ParamsSetPage->objectName().isEmpty())
            ParamsSetPage->setObjectName(QStringLiteral("ParamsSetPage"));
        ParamsSetPage->resize(607, 513);
        verticalLayout = new QVBoxLayout(ParamsSetPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        systemWidget = new QWidget(ParamsSetPage);
        systemWidget->setObjectName(QStringLiteral("systemWidget"));
        systemWidget->setMinimumSize(QSize(0, 151));
        systemWidget->setMaximumSize(QSize(16777215, 151));
        systemWidget->setStyleSheet(QString::fromUtf8("QWidget#systemWidget {\n"
"	background-color: #fafafa;\n"
"}\n"
"\n"
"QLabel{\n"
"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	font-size:12px;\n"
"	color:#666666;\n"
"	font-weight:bold;\n"
"}"));
        horizontalLayout_25 = new QHBoxLayout(systemWidget);
        horizontalLayout_25->setSpacing(0);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(28, 20, 20, 20);
        widget = new QWidget(systemWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_1 = new QLabel(widget);
        label_1->setObjectName(QStringLiteral("label_1"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        label_1->setFont(font);
        label_1->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label_1);

        discountBaseMemberLabel = new QLabel(widget);
        discountBaseMemberLabel->setObjectName(QStringLiteral("discountBaseMemberLabel"));
        discountBaseMemberLabel->setFont(font);
        discountBaseMemberLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(discountBaseMemberLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        priceSaleLabel = new QLabel(widget);
        priceSaleLabel->setObjectName(QStringLiteral("priceSaleLabel"));
        priceSaleLabel->setFont(font);

        horizontalLayout_2->addWidget(priceSaleLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        priceSaleLimitLabel = new QLabel(widget);
        priceSaleLimitLabel->setObjectName(QStringLiteral("priceSaleLimitLabel"));
        priceSaleLimitLabel->setFont(font);

        horizontalLayout_3->addWidget(priceSaleLimitLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(label_5);

        discardZeroLabel = new QLabel(widget);
        discardZeroLabel->setObjectName(QStringLiteral("discardZeroLabel"));
        discardZeroLabel->setFont(font);
        discardZeroLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(discardZeroLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_25->addWidget(widget);

        widget_2 = new QWidget(systemWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(204, 0));
        widget_2->setMaximumSize(QSize(204, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral(""));

        horizontalLayout_10->addWidget(label_7);

        maxGoodsSaleNumberLabel = new QLabel(widget_2);
        maxGoodsSaleNumberLabel->setObjectName(QStringLiteral("maxGoodsSaleNumberLabel"));
        maxGoodsSaleNumberLabel->setFont(font);
        maxGoodsSaleNumberLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_10->addWidget(maxGoodsSaleNumberLabel);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_11->addWidget(label_2);

        maxSaveDaysLabel = new QLabel(widget_2);
        maxSaveDaysLabel->setObjectName(QStringLiteral("maxSaveDaysLabel"));
        maxSaveDaysLabel->setFont(font);
        maxSaveDaysLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_11->addWidget(maxSaveDaysLabel);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral(""));

        horizontalLayout_12->addWidget(label_8);

        fillReasonForRefundLabel = new QLabel(widget_2);
        fillReasonForRefundLabel->setObjectName(QStringLiteral("fillReasonForRefundLabel"));
        fillReasonForRefundLabel->setFont(font);
        fillReasonForRefundLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_12->addWidget(fillReasonForRefundLabel);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_13);


        verticalLayout_3->addLayout(horizontalLayout_13);


        horizontalLayout_25->addWidget(widget_2);


        verticalLayout->addWidget(systemWidget);

        widget_16 = new QWidget(ParamsSetPage);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setStyleSheet(QLatin1String("QWidget#widget_16 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        label_72 = new QLabel(widget_16);
        label_72->setObjectName(QStringLiteral("label_72"));
        label_72->setGeometry(QRect(12, 24, 100, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_72->setFont(font1);
        label_72->setStyleSheet(QStringLiteral(""));
        updateOtherPosButton = new QPushButton(widget_16);
        updateOtherPosButton->setObjectName(QStringLiteral("updateOtherPosButton"));
        updateOtherPosButton->setGeometry(QRect(470, 10, 121, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        updateOtherPosButton->setFont(font2);
        updateOtherPosButton->setStyleSheet(QLatin1String("QPushButton#updateOtherPosButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/setImage/sure_normal.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#updateOtherPosButton:pressed {\n"
"	border-image: url(:/setImage/sure_press.png);\n"
"}"));
        shopParamsWidget = new ParamsShopSetWidget(widget_16);
        shopParamsWidget->setObjectName(QStringLiteral("shopParamsWidget"));
        shopParamsWidget->setGeometry(QRect(10, 55, 580, 252));
        shopParamsWidget->setStyleSheet(QLatin1String("QWidget#shopParamsWidget{\n"
"#border-image: url(:/kPosSetImage/shopParamRect.png);\n"
"}"));
        label_18 = new QLabel(shopParamsWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 210, 91, 40));
        label_18->setFont(font2);
        label_16 = new QLabel(shopParamsWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 170, 91, 40));
        label_16->setFont(font2);
        label_10 = new QLabel(shopParamsWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(290, 49, 221, 30));
        label_10->setFont(font2);
        label_14 = new QLabel(shopParamsWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(290, 132, 171, 31));
        label_14->setFont(font2);
        chooseSalesmanButton = new SwitchButton(shopParamsWidget);
        chooseSalesmanButton->setObjectName(QStringLiteral("chooseSalesmanButton"));
        chooseSalesmanButton->setGeometry(QRect(510, 136, 58, 21));
        chooseSalesmanButton->setMinimumSize(QSize(58, 0));
        chooseSalesmanButton->setMaximumSize(QSize(58, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        chooseSalesmanButton->setFont(font3);
        chooseSalesmanButton->setStyleSheet(QStringLiteral(""));
        sellZeroPriceGoodsButton = new SwitchButton(shopParamsWidget);
        sellZeroPriceGoodsButton->setObjectName(QStringLiteral("sellZeroPriceGoodsButton"));
        sellZeroPriceGoodsButton->setGeometry(QRect(510, 55, 58, 21));
        sellZeroPriceGoodsButton->setFont(font3);
        sellZeroPriceGoodsButton->setStyleSheet(QStringLiteral(""));
        openCashboxButton = new SwitchButton(shopParamsWidget);
        openCashboxButton->setObjectName(QStringLiteral("openCashboxButton"));
        openCashboxButton->setGeometry(QRect(200, 138, 58, 21));
        openCashboxButton->setMinimumSize(QSize(58, 0));
        openCashboxButton->setMaximumSize(QSize(58, 16777215));
        openCashboxButton->setStyleSheet(QStringLiteral(""));
        label_13 = new QLabel(shopParamsWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 132, 171, 31));
        label_13->setFont(font2);
        createGoodsButton = new SwitchButton(shopParamsWidget);
        createGoodsButton->setObjectName(QStringLiteral("createGoodsButton"));
        createGoodsButton->setGeometry(QRect(200, 97, 58, 21));
        createGoodsButton->setMinimumSize(QSize(58, 0));
        createGoodsButton->setMaximumSize(QSize(58, 16777215));
        createGoodsButton->setStyleSheet(QStringLiteral(""));
        changePriceButton = new SwitchButton(shopParamsWidget);
        changePriceButton->setObjectName(QStringLiteral("changePriceButton"));
        changePriceButton->setGeometry(QRect(200, 55, 58, 21));
        changePriceButton->setMinimumSize(QSize(58, 0));
        changePriceButton->setMaximumSize(QSize(58, 16777215));
        changePriceButton->setStyleSheet(QStringLiteral(""));
        label_9 = new QLabel(shopParamsWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 49, 181, 31));
        label_9->setFont(font2);
        label_11 = new QLabel(shopParamsWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 91, 171, 31));
        label_11->setFont(font2);
        label_12 = new QLabel(shopParamsWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(290, 91, 171, 31));
        label_12->setFont(font2);
        handinCashButton = new SwitchButton(shopParamsWidget);
        handinCashButton->setObjectName(QStringLiteral("handinCashButton"));
        handinCashButton->setGeometry(QRect(510, 97, 58, 21));
        handinCashButton->setMinimumSize(QSize(58, 0));
        handinCashButton->setMaximumSize(QSize(58, 16777215));
        handinCashButton->setFont(font3);
        handinCashButton->setStyleSheet(QStringLiteral(""));
        groupBox = new QGroupBox(shopParamsWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(120, 170, 451, 40));
        groupBox->setStyleSheet(QStringLiteral("border:none;"));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 88, 0);
        pending0RButton = new QRadioButton(groupBox);
        pending0RButton->setObjectName(QStringLiteral("pending0RButton"));
        pending0RButton->setFont(font2);

        horizontalLayout_5->addWidget(pending0RButton);

        pending1RButton = new QRadioButton(groupBox);
        pending1RButton->setObjectName(QStringLiteral("pending1RButton"));
        pending1RButton->setFont(font2);

        horizontalLayout_5->addWidget(pending1RButton);

        pending2RButton = new QRadioButton(groupBox);
        pending2RButton->setObjectName(QStringLiteral("pending2RButton"));
        pending2RButton->setFont(font2);

        horizontalLayout_5->addWidget(pending2RButton);

        pending3RButton = new QRadioButton(groupBox);
        pending3RButton->setObjectName(QStringLiteral("pending3RButton"));
        pending3RButton->setFont(font2);

        horizontalLayout_5->addWidget(pending3RButton);

        groupBox_3 = new QGroupBox(shopParamsWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(120, 210, 451, 40));
        groupBox_3->setStyleSheet(QStringLiteral("border:none;"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        lock0RButton = new QRadioButton(groupBox_3);
        lock0RButton->setObjectName(QStringLiteral("lock0RButton"));
        lock0RButton->setFont(font2);

        horizontalLayout_7->addWidget(lock0RButton);

        lock1RButton = new QRadioButton(groupBox_3);
        lock1RButton->setObjectName(QStringLiteral("lock1RButton"));
        lock1RButton->setFont(font2);

        horizontalLayout_7->addWidget(lock1RButton);

        lock2RButton = new QRadioButton(groupBox_3);
        lock2RButton->setObjectName(QStringLiteral("lock2RButton"));
        lock2RButton->setFont(font2);

        horizontalLayout_7->addWidget(lock2RButton);

        lock3RButton = new QRadioButton(groupBox_3);
        lock3RButton->setObjectName(QStringLiteral("lock3RButton"));
        lock3RButton->setFont(font2);

        horizontalLayout_7->addWidget(lock3RButton);

        lock4RButton = new QRadioButton(groupBox_3);
        lock4RButton->setObjectName(QStringLiteral("lock4RButton"));
        lock4RButton->setFont(font2);

        horizontalLayout_7->addWidget(lock4RButton);

        label_19 = new QLabel(shopParamsWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(13, 2, 131, 40));
        label_19->setFont(font2);
        nameWidget = new SearchEdit(shopParamsWidget);
        nameWidget->setObjectName(QStringLiteral("nameWidget"));
        nameWidget->setGeometry(QRect(144, 6, 211, 32));
        nameWidget->setStyleSheet(QStringLiteral("border:1px solid #EA8852;"));

        verticalLayout->addWidget(widget_16);


        retranslateUi(ParamsSetPage);

        QMetaObject::connectSlotsByName(ParamsSetPage);
    } // setupUi

    void retranslateUi(QWidget *ParamsSetPage)
    {
        ParamsSetPage->setWindowTitle(QApplication::translate("ParamsSetPage", "Form", Q_NULLPTR));
        label_1->setText(QApplication::translate("ParamsSetPage", "\344\274\232\345\221\230\344\273\267\346\211\223\346\212\230\345\237\272\347\241\200\357\274\232", Q_NULLPTR));
        discountBaseMemberLabel->setText(QApplication::translate("ParamsSetPage", "\345\216\237\344\273\267", Q_NULLPTR));
        label->setStyleSheet(QString());
        label->setText(QApplication::translate("ParamsSetPage", "\346\230\257\345\220\246\350\276\223\345\205\245\344\273\267\346\240\274\351\224\200\345\224\256\357\274\232", Q_NULLPTR));
        priceSaleLabel->setStyleSheet(QString());
        priceSaleLabel->setText(QApplication::translate("ParamsSetPage", "\346\230\257", Q_NULLPTR));
        label_4->setStyleSheet(QString());
        label_4->setText(QApplication::translate("ParamsSetPage", "\344\273\267\346\240\274\344\270\215\350\203\275\345\244\247\344\272\216\357\274\232", Q_NULLPTR));
        priceSaleLimitLabel->setStyleSheet(QString());
        priceSaleLimitLabel->setText(QApplication::translate("ParamsSetPage", "200", Q_NULLPTR));
        label_5->setText(QApplication::translate("ParamsSetPage", "\346\230\257\345\220\246\345\217\257\344\273\245\346\212\271\351\233\266\357\274\232", Q_NULLPTR));
        discardZeroLabel->setText(QApplication::translate("ParamsSetPage", "\346\230\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("ParamsSetPage", "\351\224\200\345\224\256\346\227\266\345\215\225\345\223\201\346\234\200\345\244\247\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        maxGoodsSaleNumberLabel->setText(QApplication::translate("ParamsSetPage", "1000", Q_NULLPTR));
        label_2->setText(QApplication::translate("ParamsSetPage", "\351\224\200\345\224\256\346\225\260\346\215\256\346\234\200\345\244\247\344\277\235\345\255\230\345\244\251\346\225\260\357\274\232", Q_NULLPTR));
        maxSaveDaysLabel->setText(QApplication::translate("ParamsSetPage", "3\345\244\251", Q_NULLPTR));
        label_8->setText(QApplication::translate("ParamsSetPage", "\346\230\257\345\220\246\351\200\211\346\213\251\351\200\200\350\264\247\345\216\237\345\233\240\357\274\232", Q_NULLPTR));
        fillReasonForRefundLabel->setText(QApplication::translate("ParamsSetPage", "\345\220\246", Q_NULLPTR));
        label_72->setText(QApplication::translate("ParamsSetPage", "\351\227\250\345\272\227\347\272\247\345\217\202\346\225\260", Q_NULLPTR));
        updateOtherPosButton->setText(QApplication::translate("ParamsSetPage", "\345\220\214\346\255\245\345\210\260\345\205\266\344\273\226POS\346\234\272", Q_NULLPTR));
        label_18->setText(QApplication::translate("ParamsSetPage", "\351\224\201\345\261\217\347\255\211\345\276\205\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("ParamsSetPage", "\346\234\200\345\244\247\346\214\202\345\215\225\346\225\260\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("ParamsSetPage", "\345\211\215\345\217\260\346\230\257\345\220\246\345\205\201\350\256\270\351\224\200\345\224\256\345\224\256\344\273\267\344\270\272\351\233\266\347\232\204\345\225\206\345\223\201\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("ParamsSetPage", "\347\273\223\347\256\227\346\230\257\345\220\246\351\200\211\346\213\251\344\270\232\345\212\241\345\221\230\357\274\232", Q_NULLPTR));
        chooseSalesmanButton->setText(QString());
        sellZeroPriceGoodsButton->setText(QString());
        openCashboxButton->setText(QString());
        label_13->setText(QApplication::translate("ParamsSetPage", "\346\224\266\351\223\266\345\221\230\346\230\257\345\220\246\346\234\211\345\274\200\351\222\261\347\256\261\346\235\203\351\231\220\357\274\232", Q_NULLPTR));
        createGoodsButton->setText(QString());
        changePriceButton->setText(QString());
        label_9->setText(QApplication::translate("ParamsSetPage", "\346\224\266\351\223\266\345\221\230\346\230\257\345\220\246\346\234\211\346\211\223\346\212\230\346\224\271\344\273\267\346\235\203\351\231\220\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("ParamsSetPage", "\346\224\266\351\223\266\345\221\230\346\230\257\345\220\246\346\234\211\345\277\253\351\200\237\345\273\272\346\241\243\346\235\203\351\231\220\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("ParamsSetPage", "\346\230\257\345\220\246\344\272\244\346\254\276\357\274\232", Q_NULLPTR));
        handinCashButton->setText(QString());
        groupBox->setTitle(QString());
        pending0RButton->setText(QApplication::translate("ParamsSetPage", "\344\270\215\351\231\220\345\210\266", Q_NULLPTR));
        pending1RButton->setText(QApplication::translate("ParamsSetPage", "10", Q_NULLPTR));
        pending2RButton->setText(QApplication::translate("ParamsSetPage", "20", Q_NULLPTR));
        pending3RButton->setText(QApplication::translate("ParamsSetPage", "30", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        lock0RButton->setText(QApplication::translate("ParamsSetPage", "\344\270\215\351\224\201\345\261\217", Q_NULLPTR));
        lock1RButton->setText(QApplication::translate("ParamsSetPage", " 1\345\210\206\351\222\237", Q_NULLPTR));
        lock2RButton->setText(QApplication::translate("ParamsSetPage", "2\345\210\206\351\222\237", Q_NULLPTR));
        lock3RButton->setText(QApplication::translate("ParamsSetPage", "5\345\210\206\351\222\237", Q_NULLPTR));
        lock4RButton->setText(QApplication::translate("ParamsSetPage", "30\345\210\206\351\222\237", Q_NULLPTR));
        label_19->setText(QApplication::translate("ParamsSetPage", "\345\260\217\347\245\250\346\211\223\345\215\260\351\227\250\345\272\227\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ParamsSetPage: public Ui_ParamsSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMSSETPAGE_H
