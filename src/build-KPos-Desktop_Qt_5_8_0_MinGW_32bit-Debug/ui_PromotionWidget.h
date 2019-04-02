/********************************************************************************
** Form generated from reading UI file 'PromotionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMOTIONWIDGET_H
#define UI_PROMOTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_PromotionWidget
{
public:
    QGridLayout *gridLayout;
    TitleBarWidget *titleWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *shoppingCartLabel_01;
    QLabel *goodsNameLabel_01;
    QLabel *shoppingCartLabel_02;
    QLabel *goodsNameLabel_02;
    QLabel *shoppingCartLabel_03;
    QLabel *goodsNameLabel_03;
    QLabel *shoppingCartLabel_04;
    QLabel *goodsNameLabel_04;
    QLabel *shoppingCartLabel_05;
    QLabel *goodsNameLabel_05;
    QLabel *shoppingCartLabel_06;
    QLabel *goodsNameLabel_06;
    QLabel *promotionStatusLabel_01;
    QLabel *promotionStatusLabel_02;
    QLabel *promotionStatusLabel_03;
    QLabel *promotionStatusLabel_04;
    QLabel *promotionStatusLabel_05;
    QLabel *promotionStatusLabel_06;

    void setupUi(QWidget *PromotionWidget)
    {
        if (PromotionWidget->objectName().isEmpty())
            PromotionWidget->setObjectName(QStringLiteral("PromotionWidget"));
        PromotionWidget->resize(370, 370);
        PromotionWidget->setMinimumSize(QSize(370, 370));
        gridLayout = new QGridLayout(PromotionWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(PromotionWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(370, 40));

        gridLayout->addWidget(titleWidget, 0, 0, 1, 1);

        widget_2 = new QWidget(PromotionWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(370, 330));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2 {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 22, 20, 26);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(330, 282));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 22, 13, 14));
        label->setMinimumSize(QSize(13, 14));
        label->setStyleSheet(QStringLiteral("border-image: url(:/saleImage/cu.png);"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 20, 91, 16));
        label_2->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 121, 121);\n"
"font:bold;"));
        shoppingCartLabel_01 = new QLabel(widget_3);
        shoppingCartLabel_01->setObjectName(QStringLiteral("shoppingCartLabel_01"));
        shoppingCartLabel_01->setGeometry(QRect(40, 46, 80, 16));
        shoppingCartLabel_01->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(153, 153, 153);\n"
""));
        goodsNameLabel_01 = new QLabel(widget_3);
        goodsNameLabel_01->setObjectName(QStringLiteral("goodsNameLabel_01"));
        goodsNameLabel_01->setGeometry(QRect(130, 46, 100, 16));
        goodsNameLabel_01->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
""));
        shoppingCartLabel_02 = new QLabel(widget_3);
        shoppingCartLabel_02->setObjectName(QStringLiteral("shoppingCartLabel_02"));
        shoppingCartLabel_02->setGeometry(QRect(40, 72, 80, 16));
        shoppingCartLabel_02->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(153, 153, 153);\n"
""));
        goodsNameLabel_02 = new QLabel(widget_3);
        goodsNameLabel_02->setObjectName(QStringLiteral("goodsNameLabel_02"));
        goodsNameLabel_02->setGeometry(QRect(130, 72, 100, 16));
        goodsNameLabel_02->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        shoppingCartLabel_03 = new QLabel(widget_3);
        shoppingCartLabel_03->setObjectName(QStringLiteral("shoppingCartLabel_03"));
        shoppingCartLabel_03->setGeometry(QRect(40, 98, 80, 16));
        shoppingCartLabel_03->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(153, 153, 153);\n"
""));
        goodsNameLabel_03 = new QLabel(widget_3);
        goodsNameLabel_03->setObjectName(QStringLiteral("goodsNameLabel_03"));
        goodsNameLabel_03->setGeometry(QRect(130, 98, 100, 16));
        goodsNameLabel_03->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        shoppingCartLabel_04 = new QLabel(widget_3);
        shoppingCartLabel_04->setObjectName(QStringLiteral("shoppingCartLabel_04"));
        shoppingCartLabel_04->setGeometry(QRect(40, 124, 80, 16));
        shoppingCartLabel_04->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(153, 153, 153);\n"
""));
        goodsNameLabel_04 = new QLabel(widget_3);
        goodsNameLabel_04->setObjectName(QStringLiteral("goodsNameLabel_04"));
        goodsNameLabel_04->setGeometry(QRect(130, 124, 100, 16));
        goodsNameLabel_04->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        shoppingCartLabel_05 = new QLabel(widget_3);
        shoppingCartLabel_05->setObjectName(QStringLiteral("shoppingCartLabel_05"));
        shoppingCartLabel_05->setGeometry(QRect(40, 150, 80, 16));
        shoppingCartLabel_05->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(153, 153, 153);\n"
""));
        goodsNameLabel_05 = new QLabel(widget_3);
        goodsNameLabel_05->setObjectName(QStringLiteral("goodsNameLabel_05"));
        goodsNameLabel_05->setGeometry(QRect(130, 150, 101, 16));
        goodsNameLabel_05->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        shoppingCartLabel_06 = new QLabel(widget_3);
        shoppingCartLabel_06->setObjectName(QStringLiteral("shoppingCartLabel_06"));
        shoppingCartLabel_06->setGeometry(QRect(40, 170, 80, 16));
        shoppingCartLabel_06->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(153, 153, 153);\n"
""));
        goodsNameLabel_06 = new QLabel(widget_3);
        goodsNameLabel_06->setObjectName(QStringLiteral("goodsNameLabel_06"));
        goodsNameLabel_06->setGeometry(QRect(130, 170, 100, 16));
        goodsNameLabel_06->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        promotionStatusLabel_01 = new QLabel(widget_3);
        promotionStatusLabel_01->setObjectName(QStringLiteral("promotionStatusLabel_01"));
        promotionStatusLabel_01->setGeometry(QRect(230, 46, 60, 16));
        promotionStatusLabel_01->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(117, 170, 86);"));
        promotionStatusLabel_02 = new QLabel(widget_3);
        promotionStatusLabel_02->setObjectName(QStringLiteral("promotionStatusLabel_02"));
        promotionStatusLabel_02->setGeometry(QRect(230, 72, 60, 16));
        promotionStatusLabel_02->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(117, 170, 86);"));
        promotionStatusLabel_03 = new QLabel(widget_3);
        promotionStatusLabel_03->setObjectName(QStringLiteral("promotionStatusLabel_03"));
        promotionStatusLabel_03->setGeometry(QRect(230, 98, 60, 16));
        promotionStatusLabel_03->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(117, 170, 86);"));
        promotionStatusLabel_04 = new QLabel(widget_3);
        promotionStatusLabel_04->setObjectName(QStringLiteral("promotionStatusLabel_04"));
        promotionStatusLabel_04->setGeometry(QRect(230, 124, 60, 16));
        promotionStatusLabel_04->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(117, 170, 86);"));
        promotionStatusLabel_05 = new QLabel(widget_3);
        promotionStatusLabel_05->setObjectName(QStringLiteral("promotionStatusLabel_05"));
        promotionStatusLabel_05->setGeometry(QRect(230, 150, 60, 16));
        promotionStatusLabel_05->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(117, 170, 86);"));
        promotionStatusLabel_06 = new QLabel(widget_3);
        promotionStatusLabel_06->setObjectName(QStringLiteral("promotionStatusLabel_06"));
        promotionStatusLabel_06->setGeometry(QRect(230, 170, 60, 16));
        promotionStatusLabel_06->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(117, 170, 86);"));

        horizontalLayout->addWidget(widget_3);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(PromotionWidget);

        QMetaObject::connectSlotsByName(PromotionWidget);
    } // setupUi

    void retranslateUi(QWidget *PromotionWidget)
    {
        PromotionWidget->setWindowTitle(QApplication::translate("PromotionWidget", "PromotionWidget", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("PromotionWidget", "\346\273\241100\345\207\21710", Q_NULLPTR));
        shoppingCartLabel_01->setText(QApplication::translate("PromotionWidget", "\345\272\217\345\217\267\357\274\232", Q_NULLPTR));
        goodsNameLabel_01->setText(QString());
        shoppingCartLabel_02->setText(QApplication::translate("PromotionWidget", "\345\272\217\345\217\267\357\274\232", Q_NULLPTR));
        goodsNameLabel_02->setText(QString());
        shoppingCartLabel_03->setText(QApplication::translate("PromotionWidget", "\345\272\217\345\217\267\357\274\232", Q_NULLPTR));
        goodsNameLabel_03->setText(QString());
        shoppingCartLabel_04->setText(QApplication::translate("PromotionWidget", "\345\272\217\345\217\267\357\274\232", Q_NULLPTR));
        goodsNameLabel_04->setText(QString());
        shoppingCartLabel_05->setText(QApplication::translate("PromotionWidget", "\345\272\217\345\217\267\357\274\232", Q_NULLPTR));
        goodsNameLabel_05->setText(QString());
        shoppingCartLabel_06->setText(QApplication::translate("PromotionWidget", "\345\272\217\345\217\267\357\274\232", Q_NULLPTR));
        goodsNameLabel_06->setText(QString());
        promotionStatusLabel_01->setText(QString());
        promotionStatusLabel_02->setText(QString());
        promotionStatusLabel_03->setText(QString());
        promotionStatusLabel_04->setText(QString());
        promotionStatusLabel_05->setText(QString());
        promotionStatusLabel_06->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PromotionWidget: public Ui_PromotionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMOTIONWIDGET_H
