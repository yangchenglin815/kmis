/********************************************************************************
** Form generated from reading UI file 'AdjustPriceOrderCheckWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTPRICEORDERCHECKWIDGET_H
#define UI_ADJUSTPRICEORDERCHECKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AdjustPriceCategoryWidget.h"
#include "AdjustPriceGoodsSelectWidget.h"
#include "AdjustPriceGoodsWidget.h"
#include "SearchEdit.h"

QT_BEGIN_NAMESPACE

class Ui_AdjustPriceOrderCheckWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout_3;
    SearchEdit *searchWidget;
    AdjustPriceGoodsSelectWidget *goodsSelectWidget;
    QSpacerItem *horizontalSpacer_3;
    QWidget *middleWidget;
    QVBoxLayout *verticalLayout_3;
    AdjustPriceCategoryWidget *categoryWidget;
    AdjustPriceGoodsWidget *goodsWidget;
    QWidget *operateWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *deleteButton;
    QPushButton *modifyPriceButton;
    QPushButton *printButton;
    QPushButton *saveButton;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_8;
    QPushButton *categoryFrontButton;
    QPushButton *categoryNextButton;
    QPushButton *goodsFrontButton;
    QPushButton *goodsNextButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AdjustPriceOrderCheckWidget)
    {
        if (AdjustPriceOrderCheckWidget->objectName().isEmpty())
            AdjustPriceOrderCheckWidget->setObjectName(QStringLiteral("AdjustPriceOrderCheckWidget"));
        AdjustPriceOrderCheckWidget->resize(755, 523);
        horizontalLayout = new QHBoxLayout(AdjustPriceOrderCheckWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 9, 0, 0);
        leftWidget = new QWidget(AdjustPriceOrderCheckWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(288, 0));
        leftWidget->setMaximumSize(QSize(590, 16777215));
        verticalLayout_4 = new QVBoxLayout(leftWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(leftWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topWidget->sizePolicy().hasHeightForWidth());
        topWidget->setSizePolicy(sizePolicy);
        topWidget->setMinimumSize(QSize(0, 44));
        topWidget->setMaximumSize(QSize(16777215, 44));
        topWidget->setStyleSheet(QLatin1String("QWidget#topWidget{\n"
"	background-color:#3e3d3d;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(topWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, 6, 6, 6);
        searchWidget = new SearchEdit(topWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));

        horizontalLayout_3->addWidget(searchWidget);


        verticalLayout_4->addWidget(topWidget);

        goodsSelectWidget = new AdjustPriceGoodsSelectWidget(leftWidget);
        goodsSelectWidget->setObjectName(QStringLiteral("goodsSelectWidget"));
        sizePolicy.setHeightForWidth(goodsSelectWidget->sizePolicy().hasHeightForWidth());
        goodsSelectWidget->setSizePolicy(sizePolicy);
        goodsSelectWidget->setMinimumSize(QSize(0, 0));
        goodsSelectWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_4->addWidget(goodsSelectWidget);


        horizontalLayout->addWidget(leftWidget);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        middleWidget = new QWidget(AdjustPriceOrderCheckWidget);
        middleWidget->setObjectName(QStringLiteral("middleWidget"));
        verticalLayout_3 = new QVBoxLayout(middleWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        categoryWidget = new AdjustPriceCategoryWidget(middleWidget);
        categoryWidget->setObjectName(QStringLiteral("categoryWidget"));
        categoryWidget->setMinimumSize(QSize(412, 111));
        categoryWidget->setMaximumSize(QSize(16777215, 150));

        verticalLayout_3->addWidget(categoryWidget);

        goodsWidget = new AdjustPriceGoodsWidget(middleWidget);
        goodsWidget->setObjectName(QStringLiteral("goodsWidget"));
        goodsWidget->setMinimumSize(QSize(412, 0));

        verticalLayout_3->addWidget(goodsWidget);

        operateWidget = new QWidget(middleWidget);
        operateWidget->setObjectName(QStringLiteral("operateWidget"));
        operateWidget->setMinimumSize(QSize(412, 53));
        operateWidget->setMaximumSize(QSize(16777215, 95));
        horizontalLayout_2 = new QHBoxLayout(operateWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 6, 0, 0);
        deleteButton = new QPushButton(operateWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);
        deleteButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_2->addWidget(deleteButton);

        modifyPriceButton = new QPushButton(operateWidget);
        modifyPriceButton->setObjectName(QStringLiteral("modifyPriceButton"));
        sizePolicy1.setHeightForWidth(modifyPriceButton->sizePolicy().hasHeightForWidth());
        modifyPriceButton->setSizePolicy(sizePolicy1);
        modifyPriceButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_2->addWidget(modifyPriceButton);

        printButton = new QPushButton(operateWidget);
        printButton->setObjectName(QStringLiteral("printButton"));
        sizePolicy1.setHeightForWidth(printButton->sizePolicy().hasHeightForWidth());
        printButton->setSizePolicy(sizePolicy1);
        printButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_2->addWidget(printButton);

        saveButton = new QPushButton(operateWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        sizePolicy1.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy1);
        saveButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/orangeButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/OrangeButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_2->addWidget(saveButton);


        verticalLayout_3->addWidget(operateWidget);

        verticalLayout_3->setStretch(0, 110);
        verticalLayout_3->setStretch(1, 350);
        verticalLayout_3->setStretch(2, 53);

        horizontalLayout->addWidget(middleWidget);

        rightWidget = new QWidget(AdjustPriceOrderCheckWidget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        rightWidget->setMinimumSize(QSize(55, 0));
        rightWidget->setMaximumSize(QSize(130, 16777215));
        verticalLayout_8 = new QVBoxLayout(rightWidget);
        verticalLayout_8->setSpacing(4);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(4, 0, 0, 0);
        categoryFrontButton = new QPushButton(rightWidget);
        categoryFrontButton->setObjectName(QStringLiteral("categoryFrontButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(categoryFrontButton->sizePolicy().hasHeightForWidth());
        categoryFrontButton->setSizePolicy(sizePolicy2);
        categoryFrontButton->setMinimumSize(QSize(52, 52));
        categoryFrontButton->setMaximumSize(QSize(16777215, 16777215));
        categoryFrontButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/category_up.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	border-image: url(:/saleImage/category_up_press.png);\n"
"}"));

        verticalLayout_8->addWidget(categoryFrontButton);

        categoryNextButton = new QPushButton(rightWidget);
        categoryNextButton->setObjectName(QStringLiteral("categoryNextButton"));
        sizePolicy2.setHeightForWidth(categoryNextButton->sizePolicy().hasHeightForWidth());
        categoryNextButton->setSizePolicy(sizePolicy2);
        categoryNextButton->setMinimumSize(QSize(52, 52));
        categoryNextButton->setMaximumSize(QSize(16777215, 16777215));
        categoryNextButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	font-size:12px;\n"
"	color:#ffffff;\n"
"	padding-top:20px;\n"
"	border-image: url(:/saleImage/category_down.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/category_down_press.png);\n"
"}"));

        verticalLayout_8->addWidget(categoryNextButton);

        goodsFrontButton = new QPushButton(rightWidget);
        goodsFrontButton->setObjectName(QStringLiteral("goodsFrontButton"));
        sizePolicy2.setHeightForWidth(goodsFrontButton->sizePolicy().hasHeightForWidth());
        goodsFrontButton->setSizePolicy(sizePolicy2);
        goodsFrontButton->setMinimumSize(QSize(52, 52));
        goodsFrontButton->setMaximumSize(QSize(16777215, 16777215));
        goodsFrontButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/goods_up.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/goods_up_press.png);\n"
"}"));

        verticalLayout_8->addWidget(goodsFrontButton);

        goodsNextButton = new QPushButton(rightWidget);
        goodsNextButton->setObjectName(QStringLiteral("goodsNextButton"));
        sizePolicy2.setHeightForWidth(goodsNextButton->sizePolicy().hasHeightForWidth());
        goodsNextButton->setSizePolicy(sizePolicy2);
        goodsNextButton->setMinimumSize(QSize(52, 52));
        goodsNextButton->setMaximumSize(QSize(16777215, 16777215));
        goodsNextButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	font-size:12px;\n"
"	color:#ffffff;\n"
"	padding-top:20px;\n"
"	border-image: url(:/saleImage/goods_down.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/goods_down_press.png);\n"
"}"));

        verticalLayout_8->addWidget(goodsNextButton);

        verticalSpacer = new QSpacerItem(20, 173, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);


        horizontalLayout->addWidget(rightWidget);

        horizontalLayout->setStretch(0, 288);
        horizontalLayout->setStretch(1, 8);
        horizontalLayout->setStretch(2, 412);
        horizontalLayout->setStretch(3, 55);

        retranslateUi(AdjustPriceOrderCheckWidget);

        QMetaObject::connectSlotsByName(AdjustPriceOrderCheckWidget);
    } // setupUi

    void retranslateUi(QWidget *AdjustPriceOrderCheckWidget)
    {
        AdjustPriceOrderCheckWidget->setWindowTitle(QApplication::translate("AdjustPriceOrderCheckWidget", "Form", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("AdjustPriceOrderCheckWidget", "\345\210\240\351\231\244", Q_NULLPTR));
        modifyPriceButton->setText(QApplication::translate("AdjustPriceOrderCheckWidget", "\344\277\256\346\224\271\344\273\267\346\240\274", Q_NULLPTR));
        printButton->setText(QApplication::translate("AdjustPriceOrderCheckWidget", "\346\211\223\345\215\260", Q_NULLPTR));
        saveButton->setText(QApplication::translate("AdjustPriceOrderCheckWidget", "\344\277\235\345\255\230", Q_NULLPTR));
        categoryFrontButton->setText(QString());
        categoryNextButton->setText(QApplication::translate("AdjustPriceOrderCheckWidget", "1/12\351\241\265", Q_NULLPTR));
        goodsFrontButton->setText(QString());
        goodsNextButton->setText(QApplication::translate("AdjustPriceOrderCheckWidget", "1/12\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdjustPriceOrderCheckWidget: public Ui_AdjustPriceOrderCheckWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTPRICEORDERCHECKWIDGET_H
