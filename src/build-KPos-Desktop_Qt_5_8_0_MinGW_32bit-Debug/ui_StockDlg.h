/********************************************************************************
** Form generated from reading UI file 'StockDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKDLG_H
#define UI_STOCKDLG_H

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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleBarWidget.h"
#include "WndDigitalKeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_StockDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *saveTopWidget;
    QLabel *goodsNameLabel;
    QLabel *goodsCodeLabel;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *saveMainWidget;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *addPage;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *realStockEdit;
    QLabel *shoudStockLabel;
    QWidget *modifyPage;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *addStockNumEdit;
    QLabel *lastRealStockLabel;
    QLabel *label;
    QLabel *shoudStock2Label;
    QLabel *label_6;
    QLineEdit *reduceStockNumEdit;
    QLabel *hintLabel;
    QPushButton *saveButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    WndDigitalKeyboard *keyboardWidget;

    void setupUi(QDialog *StockDlg)
    {
        if (StockDlg->objectName().isEmpty())
            StockDlg->setObjectName(QStringLiteral("StockDlg"));
        StockDlg->resize(660, 377);
        verticalLayout = new QVBoxLayout(StockDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(StockDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 46));
        titleWidget->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(StockDlg);
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
        goodsNameLabel = new QLabel(saveTopWidget);
        goodsNameLabel->setObjectName(QStringLiteral("goodsNameLabel"));
        goodsNameLabel->setGeometry(QRect(80, 10, 201, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        goodsNameLabel->setFont(font);
        goodsCodeLabel = new QLabel(saveTopWidget);
        goodsCodeLabel->setObjectName(QStringLiteral("goodsCodeLabel"));
        goodsCodeLabel->setGeometry(QRect(80, 30, 201, 20));
        goodsCodeLabel->setFont(font);
        label_7 = new QLabel(saveTopWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 71, 21));
        label_7->setFont(font);
        label_8 = new QLabel(saveTopWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 30, 71, 21));
        label_8->setFont(font);

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
        stackedWidget = new QStackedWidget(saveMainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 144));
        stackedWidget->setMaximumSize(QSize(16777215, 144));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 0);"));
        addPage = new QWidget();
        addPage->setObjectName(QStringLiteral("addPage"));
        horizontalLayout_2 = new QHBoxLayout(addPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 34, 0, 34);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(addPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(addPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        realStockEdit = new QLineEdit(addPage);
        realStockEdit->setObjectName(QStringLiteral("realStockEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(realStockEdit->sizePolicy().hasHeightForWidth());
        realStockEdit->setSizePolicy(sizePolicy);
        realStockEdit->setStyleSheet(QString::fromUtf8("background-color:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color: #666666;\n"
"padding-left:10px;"));

        gridLayout->addWidget(realStockEdit, 1, 1, 1, 1);

        shoudStockLabel = new QLabel(addPage);
        shoudStockLabel->setObjectName(QStringLiteral("shoudStockLabel"));
        shoudStockLabel->setStyleSheet(QString::fromUtf8("background-color:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color: #666666;\n"
"padding-left:10px;"));

        gridLayout->addWidget(shoudStockLabel, 0, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        stackedWidget->addWidget(addPage);
        modifyPage = new QWidget();
        modifyPage->setObjectName(QStringLiteral("modifyPage"));
        horizontalLayout_3 = new QHBoxLayout(modifyPage);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 14, 0, 14);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_5 = new QLabel(modifyPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_2 = new QLabel(modifyPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        addStockNumEdit = new QLineEdit(modifyPage);
        addStockNumEdit->setObjectName(QStringLiteral("addStockNumEdit"));
        sizePolicy.setHeightForWidth(addStockNumEdit->sizePolicy().hasHeightForWidth());
        addStockNumEdit->setSizePolicy(sizePolicy);
        addStockNumEdit->setStyleSheet(QString::fromUtf8("background-color:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color: #666666;\n"
"padding-left:10px;"));

        gridLayout_2->addWidget(addStockNumEdit, 2, 1, 1, 1);

        lastRealStockLabel = new QLabel(modifyPage);
        lastRealStockLabel->setObjectName(QStringLiteral("lastRealStockLabel"));
        lastRealStockLabel->setStyleSheet(QString::fromUtf8("background-color:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color: #666666;\n"
"padding-left:10px;"));

        gridLayout_2->addWidget(lastRealStockLabel, 1, 1, 1, 1);

        label = new QLabel(modifyPage);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        shoudStock2Label = new QLabel(modifyPage);
        shoudStock2Label->setObjectName(QStringLiteral("shoudStock2Label"));
        shoudStock2Label->setStyleSheet(QString::fromUtf8("background-color:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color: #666666;\n"
"padding-left:10px;"));

        gridLayout_2->addWidget(shoudStock2Label, 0, 1, 1, 1);

        label_6 = new QLabel(modifyPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        reduceStockNumEdit = new QLineEdit(modifyPage);
        reduceStockNumEdit->setObjectName(QStringLiteral("reduceStockNumEdit"));
        sizePolicy.setHeightForWidth(reduceStockNumEdit->sizePolicy().hasHeightForWidth());
        reduceStockNumEdit->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(reduceStockNumEdit, 3, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        stackedWidget->addWidget(modifyPage);

        verticalLayout_4->addWidget(stackedWidget);

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
        QFont font1;
        saveButton->setFont(font1);
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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


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


        retranslateUi(StockDlg);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(StockDlg);
    } // setupUi

    void retranslateUi(QDialog *StockDlg)
    {
        StockDlg->setWindowTitle(QApplication::translate("StockDlg", "Dialog", Q_NULLPTR));
        goodsNameLabel->setText(QString());
        goodsCodeLabel->setText(QString());
        label_7->setText(QApplication::translate("StockDlg", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("StockDlg", "\345\225\206\345\223\201\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("StockDlg", "\345\256\236\347\233\230\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("StockDlg", "\350\264\246\347\233\230\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        shoudStockLabel->setText(QString());
        label_5->setText(QApplication::translate("StockDlg", "\345\242\236\345\212\240\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("StockDlg", "\350\264\246\347\233\230\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        lastRealStockLabel->setText(QString());
        label->setText(QApplication::translate("StockDlg", "\344\270\212\346\254\241\345\256\236\347\233\230\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        shoudStock2Label->setText(QString());
        label_6->setText(QApplication::translate("StockDlg", "\345\207\217\345\260\221\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        hintLabel->setText(QString());
        saveButton->setText(QApplication::translate("StockDlg", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StockDlg: public Ui_StockDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKDLG_H
