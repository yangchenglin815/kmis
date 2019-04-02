/********************************************************************************
** Form generated from reading UI file 'AdjustPriceDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTPRICEDLG_H
#define UI_ADJUSTPRICEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleBarWidget.h"
#include "WndDigitalKeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_AdjustPriceDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *saveTopWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *goodsNameLabel;
    QLabel *goodsCodeLabel;
    QWidget *saveMainWidget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *nowPriceEdit;
    QLineEdit *nowMemberPriceEdit;
    QLabel *oldPriceLabel;
    QLabel *oldMemberPriceLabel;
    QLabel *hintLabel;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer;
    WndDigitalKeyboard *keyboardWidget;

    void setupUi(QDialog *AdjustPriceDlg)
    {
        if (AdjustPriceDlg->objectName().isEmpty())
            AdjustPriceDlg->setObjectName(QStringLiteral("AdjustPriceDlg"));
        AdjustPriceDlg->resize(660, 377);
        verticalLayout = new QVBoxLayout(AdjustPriceDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(AdjustPriceDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 46));
        titleWidget->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(AdjustPriceDlg);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"	background-color:#505050;\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 12, 20, 24);
        widget_2 = new QWidget(mainWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(284, 0));
        widget_2->setMaximumSize(QSize(284, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        saveTopWidget = new QWidget(widget_2);
        saveTopWidget->setObjectName(QStringLiteral("saveTopWidget"));
        saveTopWidget->setMinimumSize(QSize(0, 64));
        saveTopWidget->setMaximumSize(QSize(16777215, 64));
        saveTopWidget->setStyleSheet(QLatin1String("QWidget#saveTopWidget{\n"
"	background-color:#fafafa;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(saveTopWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(18, 15, 0, 15);
        goodsNameLabel = new QLabel(saveTopWidget);
        goodsNameLabel->setObjectName(QStringLiteral("goodsNameLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        goodsNameLabel->setFont(font);

        verticalLayout_3->addWidget(goodsNameLabel);

        goodsCodeLabel = new QLabel(saveTopWidget);
        goodsCodeLabel->setObjectName(QStringLiteral("goodsCodeLabel"));
        goodsCodeLabel->setFont(font);

        verticalLayout_3->addWidget(goodsCodeLabel);


        verticalLayout_2->addWidget(saveTopWidget);

        saveMainWidget = new QWidget(widget_2);
        saveMainWidget->setObjectName(QStringLiteral("saveMainWidget"));
        saveMainWidget->setStyleSheet(QLatin1String("QWidget#saveMainWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(saveMainWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(20, 15, 20, 12);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(saveMainWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(saveMainWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_5 = new QLabel(saveMainWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(saveMainWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        nowPriceEdit = new QLineEdit(saveMainWidget);
        nowPriceEdit->setObjectName(QStringLiteral("nowPriceEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nowPriceEdit->sizePolicy().hasHeightForWidth());
        nowPriceEdit->setSizePolicy(sizePolicy);
        nowPriceEdit->setStyleSheet(QString::fromUtf8("background-color:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color: #666666;\n"
"padding-left:10px;"));

        gridLayout->addWidget(nowPriceEdit, 1, 1, 1, 1);

        nowMemberPriceEdit = new QLineEdit(saveMainWidget);
        nowMemberPriceEdit->setObjectName(QStringLiteral("nowMemberPriceEdit"));
        sizePolicy.setHeightForWidth(nowMemberPriceEdit->sizePolicy().hasHeightForWidth());
        nowMemberPriceEdit->setSizePolicy(sizePolicy);
        nowMemberPriceEdit->setStyleSheet(QString::fromUtf8("background-color:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color: #666666;\n"
"padding-left:10px;"));

        gridLayout->addWidget(nowMemberPriceEdit, 3, 1, 1, 1);

        oldPriceLabel = new QLabel(saveMainWidget);
        oldPriceLabel->setObjectName(QStringLiteral("oldPriceLabel"));
        oldPriceLabel->setStyleSheet(QString::fromUtf8("background-color:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color: #666666;\n"
"padding-left:10px;"));

        gridLayout->addWidget(oldPriceLabel, 0, 1, 1, 1);

        oldMemberPriceLabel = new QLabel(saveMainWidget);
        oldMemberPriceLabel->setObjectName(QStringLiteral("oldMemberPriceLabel"));
        oldMemberPriceLabel->setStyleSheet(QString::fromUtf8("background-color:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color: #666666;\n"
"padding-left:10px;"));

        gridLayout->addWidget(oldMemberPriceLabel, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        hintLabel = new QLabel(saveMainWidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setMinimumSize(QSize(0, 18));
        hintLabel->setMaximumSize(QSize(16777215, 18));
        hintLabel->setStyleSheet(QStringLiteral("color:red;"));

        verticalLayout_4->addWidget(hintLabel);

        saveButton = new QPushButton(saveMainWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(0, 42));
        saveButton->setMaximumSize(QSize(16777215, 42));
        saveButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#ffffff;\n"
"font-size:16px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));

        verticalLayout_4->addWidget(saveButton);


        verticalLayout_2->addWidget(saveMainWidget);


        horizontalLayout->addWidget(widget_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        keyboardWidget = new WndDigitalKeyboard(mainWidget);
        keyboardWidget->setObjectName(QStringLiteral("keyboardWidget"));
        keyboardWidget->setMinimumSize(QSize(304, 0));
        keyboardWidget->setMaximumSize(QSize(304, 16777215));

        horizontalLayout->addWidget(keyboardWidget);


        verticalLayout->addWidget(mainWidget);


        retranslateUi(AdjustPriceDlg);

        QMetaObject::connectSlotsByName(AdjustPriceDlg);
    } // setupUi

    void retranslateUi(QDialog *AdjustPriceDlg)
    {
        AdjustPriceDlg->setWindowTitle(QApplication::translate("AdjustPriceDlg", "Dialog", Q_NULLPTR));
        goodsNameLabel->setText(QApplication::translate("AdjustPriceDlg", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        goodsCodeLabel->setText(QApplication::translate("AdjustPriceDlg", "\345\225\206\345\223\201\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("AdjustPriceDlg", "\347\216\260\345\224\256\344\273\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("AdjustPriceDlg", "\345\216\237\345\224\256\344\273\267\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("AdjustPriceDlg", "\345\216\237\344\274\232\345\221\230\344\273\267\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("AdjustPriceDlg", "\347\216\260\344\274\232\345\221\230\344\273\267\357\274\232", Q_NULLPTR));
        oldPriceLabel->setText(QString());
        oldMemberPriceLabel->setText(QString());
        hintLabel->setText(QString());
        saveButton->setText(QApplication::translate("AdjustPriceDlg", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdjustPriceDlg: public Ui_AdjustPriceDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTPRICEDLG_H
