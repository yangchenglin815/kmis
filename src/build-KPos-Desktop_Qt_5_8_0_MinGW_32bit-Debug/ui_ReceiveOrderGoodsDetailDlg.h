/********************************************************************************
** Form generated from reading UI file 'ReceiveOrderGoodsDetailDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEORDERGOODSDETAILDLG_H
#define UI_RECEIVEORDERGOODSDETAILDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleBarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiveOrderGoodsDetailDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *skinWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *introduceWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *goodsNameLabel;
    QLabel *goodsIntroductionLabel;
    QSpacerItem *verticalSpacer;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *needReceiveLabel;
    QSpacerItem *verticalSpacer_2;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *changeTabWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *stableButton;
    QPushButton *unStableButton;
    QPushButton *disperseButton;
    QWidget *bottomSkinWidget;
    QVBoxLayout *verticalLayout_7;
    QStackedWidget *stackedWidget;
    QWidget *standardGoodsPage;
    QFormLayout *formLayout_3;
    QLabel *label_13;
    QLineEdit *standardWeightLineEdit;
    QLabel *label_15;
    QLineEdit *receiveNumLineEdit;
    QLabel *label_12;
    QLineEdit *receiveSumValueLineEdit;
    QLabel *label_14;
    QLineEdit *receivePriceLineEdit;
    QWidget *noStandardGoodsPage;
    QFormLayout *formLayout;
    QLabel *label_5;
    QWidget *lineWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *allWeightlineEdit;
    QLabel *hintLabel;
    QLabel *label_6;
    QLineEdit *peelWeightlineEdit;
    QLabel *label_7;
    QLineEdit *receiveNum2LineEdit;
    QLabel *label_8;
    QLineEdit *receivePrice2LineEdit;
    QWidget *disperseGoodsPage;
    QFormLayout *formLayout_2;
    QLineEdit *receivePrice3LineEdit;
    QLabel *label_11;
    QLineEdit *receiveSumValue3LineEdit;
    QLabel *label_10;
    QPushButton *saveButton;

    void setupUi(QDialog *ReceiveOrderGoodsDetailDlg)
    {
        if (ReceiveOrderGoodsDetailDlg->objectName().isEmpty())
            ReceiveOrderGoodsDetailDlg->setObjectName(QStringLiteral("ReceiveOrderGoodsDetailDlg"));
        ReceiveOrderGoodsDetailDlg->resize(402, 455);
        verticalLayout = new QVBoxLayout(ReceiveOrderGoodsDetailDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(ReceiveOrderGoodsDetailDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 40));
        titleWidget->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(titleWidget);

        skinWidget = new QWidget(ReceiveOrderGoodsDetailDlg);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(skinWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(22, 0, 22, 18);
        introduceWidget = new QWidget(skinWidget);
        introduceWidget->setObjectName(QStringLiteral("introduceWidget"));
        introduceWidget->setMinimumSize(QSize(0, 80));
        introduceWidget->setMaximumSize(QSize(16777215, 80));
        horizontalLayout = new QHBoxLayout(introduceWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(introduceWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        verticalLayout_3 = new QVBoxLayout(widget_5);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 22, 0, 0);
        goodsNameLabel = new QLabel(widget_5);
        goodsNameLabel->setObjectName(QStringLiteral("goodsNameLabel"));
        goodsNameLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:16px;\n"
"color:#ffffff;"));

        verticalLayout_3->addWidget(goodsNameLabel);

        goodsIntroductionLabel = new QLabel(widget_5);
        goodsIntroductionLabel->setObjectName(QStringLiteral("goodsIntroductionLabel"));
        goodsIntroductionLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color:#999999;"));

        verticalLayout_3->addWidget(goodsIntroductionLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget_5);

        widget_6 = new QWidget(introduceWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(85, 0));
        widget_6->setMaximumSize(QSize(85, 16777215));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 22, 0, 0);
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color:#999999;"));

        verticalLayout_4->addWidget(label_3);

        needReceiveLabel = new QLabel(widget_6);
        needReceiveLabel->setObjectName(QStringLiteral("needReceiveLabel"));
        needReceiveLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:16px;\n"
"color:#ffffff;"));

        verticalLayout_4->addWidget(needReceiveLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widget_6);


        verticalLayout_2->addWidget(introduceWidget);

        mainWidget = new QWidget(skinWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(mainWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        changeTabWidget = new QWidget(mainWidget);
        changeTabWidget->setObjectName(QStringLiteral("changeTabWidget"));
        changeTabWidget->setMinimumSize(QSize(0, 36));
        changeTabWidget->setMaximumSize(QSize(16777215, 36));
        horizontalLayout_2 = new QHBoxLayout(changeTabWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        stableButton = new QPushButton(changeTabWidget);
        stableButton->setObjectName(QStringLiteral("stableButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stableButton->sizePolicy().hasHeightForWidth());
        stableButton->setSizePolicy(sizePolicy);
        stableButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:14px;\n"
"	color:#333333;\n"
"	border-image: url(:/receivingGoodsImage/bigTopTab_Press.png);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(stableButton);

        unStableButton = new QPushButton(changeTabWidget);
        unStableButton->setObjectName(QStringLiteral("unStableButton"));
        sizePolicy.setHeightForWidth(unStableButton->sizePolicy().hasHeightForWidth());
        unStableButton->setSizePolicy(sizePolicy);
        unStableButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:14px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/receivingGoodsImage/bigTopTab.png);\n"
"}"));

        horizontalLayout_2->addWidget(unStableButton);

        disperseButton = new QPushButton(changeTabWidget);
        disperseButton->setObjectName(QStringLiteral("disperseButton"));
        sizePolicy.setHeightForWidth(disperseButton->sizePolicy().hasHeightForWidth());
        disperseButton->setSizePolicy(sizePolicy);
        disperseButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:14px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/receivingGoodsImage/bigTopTab.png);\n"
"}"));

        horizontalLayout_2->addWidget(disperseButton);


        verticalLayout_5->addWidget(changeTabWidget);

        bottomSkinWidget = new QWidget(mainWidget);
        bottomSkinWidget->setObjectName(QStringLiteral("bottomSkinWidget"));
        bottomSkinWidget->setStyleSheet(QLatin1String("QWidget#bottomSkinWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(bottomSkinWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(22, 25, 22, 13);
        stackedWidget = new QStackedWidget(bottomSkinWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
"padding-left:10px;\n"
"border:1px solid #ea8852;\n"
"background-color:#fafafa;\n"
"}"));
        standardGoodsPage = new QWidget();
        standardGoodsPage->setObjectName(QStringLiteral("standardGoodsPage"));
        standardGoodsPage->setStyleSheet(QLatin1String("QWidget#standardGoodsPage{\n"
"	background-color:#ffffff;\n"
"}"));
        formLayout_3 = new QFormLayout(standardGoodsPage);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setHorizontalSpacing(0);
        formLayout_3->setVerticalSpacing(15);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(standardGoodsPage);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(0, 32));
        label_13->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_13);

        standardWeightLineEdit = new QLineEdit(standardGoodsPage);
        standardWeightLineEdit->setObjectName(QStringLiteral("standardWeightLineEdit"));
        standardWeightLineEdit->setMinimumSize(QSize(0, 32));
        standardWeightLineEdit->setStyleSheet(QStringLiteral(""));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, standardWeightLineEdit);

        label_15 = new QLabel(standardGoodsPage);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(0, 32));
        label_15->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_15);

        receiveNumLineEdit = new QLineEdit(standardGoodsPage);
        receiveNumLineEdit->setObjectName(QStringLiteral("receiveNumLineEdit"));
        receiveNumLineEdit->setMinimumSize(QSize(0, 32));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, receiveNumLineEdit);

        label_12 = new QLabel(standardGoodsPage);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 32));
        label_12->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_12);

        receiveSumValueLineEdit = new QLineEdit(standardGoodsPage);
        receiveSumValueLineEdit->setObjectName(QStringLiteral("receiveSumValueLineEdit"));
        receiveSumValueLineEdit->setMinimumSize(QSize(0, 32));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, receiveSumValueLineEdit);

        label_14 = new QLabel(standardGoodsPage);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(0, 32));
        label_14->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_14);

        receivePriceLineEdit = new QLineEdit(standardGoodsPage);
        receivePriceLineEdit->setObjectName(QStringLiteral("receivePriceLineEdit"));
        receivePriceLineEdit->setMinimumSize(QSize(0, 32));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, receivePriceLineEdit);

        stackedWidget->addWidget(standardGoodsPage);
        noStandardGoodsPage = new QWidget();
        noStandardGoodsPage->setObjectName(QStringLiteral("noStandardGoodsPage"));
        noStandardGoodsPage->setStyleSheet(QLatin1String("QWidget#noStandardGoodsPage{\n"
"	background-color:#ffffff;\n"
"}"));
        formLayout = new QFormLayout(noStandardGoodsPage);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(noStandardGoodsPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 32));
        label_5->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        lineWidget = new QWidget(noStandardGoodsPage);
        lineWidget->setObjectName(QStringLiteral("lineWidget"));
        lineWidget->setStyleSheet(QLatin1String("QWidget#lineWidget{\n"
"border:1px solid #ea8852;\n"
"background-color:#fafafa;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(lineWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(1, 1, 10, 1);
        allWeightlineEdit = new QLineEdit(lineWidget);
        allWeightlineEdit->setObjectName(QStringLiteral("allWeightlineEdit"));
        allWeightlineEdit->setMinimumSize(QSize(0, 30));
        allWeightlineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
"padding-left:10px;\n"
"border:none;\n"
"}"));

        horizontalLayout_3->addWidget(allWeightlineEdit);

        hintLabel = new QLabel(lineWidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color:#fa7a7a;\n"
"background-color:#fafafa;"));

        horizontalLayout_3->addWidget(hintLabel);


        formLayout->setWidget(0, QFormLayout::FieldRole, lineWidget);

        label_6 = new QLabel(noStandardGoodsPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 32));
        label_6->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        peelWeightlineEdit = new QLineEdit(noStandardGoodsPage);
        peelWeightlineEdit->setObjectName(QStringLiteral("peelWeightlineEdit"));
        peelWeightlineEdit->setMinimumSize(QSize(0, 32));

        formLayout->setWidget(1, QFormLayout::FieldRole, peelWeightlineEdit);

        label_7 = new QLabel(noStandardGoodsPage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 32));
        label_7->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        receiveNum2LineEdit = new QLineEdit(noStandardGoodsPage);
        receiveNum2LineEdit->setObjectName(QStringLiteral("receiveNum2LineEdit"));
        receiveNum2LineEdit->setMinimumSize(QSize(0, 32));

        formLayout->setWidget(2, QFormLayout::FieldRole, receiveNum2LineEdit);

        label_8 = new QLabel(noStandardGoodsPage);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(0, 32));
        label_8->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        receivePrice2LineEdit = new QLineEdit(noStandardGoodsPage);
        receivePrice2LineEdit->setObjectName(QStringLiteral("receivePrice2LineEdit"));
        receivePrice2LineEdit->setMinimumSize(QSize(0, 32));

        formLayout->setWidget(3, QFormLayout::FieldRole, receivePrice2LineEdit);

        stackedWidget->addWidget(noStandardGoodsPage);
        disperseGoodsPage = new QWidget();
        disperseGoodsPage->setObjectName(QStringLiteral("disperseGoodsPage"));
        disperseGoodsPage->setStyleSheet(QLatin1String("QWidget#disperseGoodsPage{\n"
"	background-color:#ffffff;\n"
"}"));
        formLayout_2 = new QFormLayout(disperseGoodsPage);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setHorizontalSpacing(0);
        formLayout_2->setVerticalSpacing(15);
        formLayout_2->setContentsMargins(0, 0, 0, -1);
        receivePrice3LineEdit = new QLineEdit(disperseGoodsPage);
        receivePrice3LineEdit->setObjectName(QStringLiteral("receivePrice3LineEdit"));
        receivePrice3LineEdit->setMinimumSize(QSize(0, 32));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, receivePrice3LineEdit);

        label_11 = new QLabel(disperseGoodsPage);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(0, 32));
        label_11->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_11);

        receiveSumValue3LineEdit = new QLineEdit(disperseGoodsPage);
        receiveSumValue3LineEdit->setObjectName(QStringLiteral("receiveSumValue3LineEdit"));
        receiveSumValue3LineEdit->setMinimumSize(QSize(0, 32));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, receiveSumValue3LineEdit);

        label_10 = new QLabel(disperseGoodsPage);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 32));
        label_10->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color:#333333;\n"
""));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        stackedWidget->addWidget(disperseGoodsPage);

        verticalLayout_7->addWidget(stackedWidget);

        saveButton = new QPushButton(bottomSkinWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(0, 44));
        saveButton->setMaximumSize(QSize(16777215, 44));
        saveButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:14px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
"\n"
"\n"
""));

        verticalLayout_7->addWidget(saveButton);


        verticalLayout_5->addWidget(bottomSkinWidget);


        verticalLayout_2->addWidget(mainWidget);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(ReceiveOrderGoodsDetailDlg);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ReceiveOrderGoodsDetailDlg);
    } // setupUi

    void retranslateUi(QDialog *ReceiveOrderGoodsDetailDlg)
    {
        ReceiveOrderGoodsDetailDlg->setWindowTitle(QApplication::translate("ReceiveOrderGoodsDetailDlg", "Dialog", Q_NULLPTR));
        goodsNameLabel->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\346\227\240\347\261\275\346\262\231\347\223\244\345\244\247\350\213\271\346\236\234", Q_NULLPTR));
        goodsIntroductionLabel->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\350\247\204\346\240\274\347\274\226\345\217\267\357\274\2322011555544(4\345\205\254\346\226\244/\347\256\261)", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\345\272\224\346\224\266\344\273\266\346\225\260/\346\225\260\351\207\217", Q_NULLPTR));
        needReceiveLabel->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "11/23", Q_NULLPTR));
        stableButton->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\350\256\241\344\273\266(\345\217\257\347\241\256\345\256\232)", Q_NULLPTR));
        unStableButton->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\350\256\241\344\273\266(\344\270\215\347\241\256\345\256\232)", Q_NULLPTR));
        disperseButton->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\346\225\243\346\226\244", Q_NULLPTR));
        label_13->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "      \350\247\204\346\240\274\357\274\232", Q_NULLPTR));
        standardWeightLineEdit->setText(QString());
        label_15->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\351\207\207\350\264\255\344\273\266\346\225\260\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\351\207\207\350\264\255\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "    \345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\345\215\225\344\273\266\346\257\233\351\207\215\357\274\232", Q_NULLPTR));
        hintLabel->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\346\232\202\344\274\260", Q_NULLPTR));
        label_6->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\345\215\225\344\273\266\347\232\256\351\207\215\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\351\207\207\350\264\255\344\273\266\346\225\260\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "    \345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\345\256\236\351\207\207\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "       \345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        saveButton->setText(QApplication::translate("ReceiveOrderGoodsDetailDlg", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiveOrderGoodsDetailDlg: public Ui_ReceiveOrderGoodsDetailDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEORDERGOODSDETAILDLG_H
