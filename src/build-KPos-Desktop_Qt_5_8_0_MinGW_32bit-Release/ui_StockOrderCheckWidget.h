/********************************************************************************
** Form generated from reading UI file 'StockOrderCheckWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKORDERCHECKWIDGET_H
#define UI_STOCKORDERCHECKWIDGET_H

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
#include "AdjustPriceGoodsWidget.h"
#include "SearchEdit.h"
#include "StockGoodsSelectWidget.h"

QT_BEGIN_NAMESPACE

class Ui_StockOrderCheckWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout_4;
    SearchEdit *searchWidget;
    StockGoodsSelectWidget *goodsSelectWidget;
    QSpacerItem *horizontalSpacer;
    QWidget *middleWidget;
    QVBoxLayout *verticalLayout_6;
    AdjustPriceCategoryWidget *categoryWidget;
    AdjustPriceGoodsWidget *goodsWidget;
    QWidget *operateWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *deleteButton;
    QPushButton *modifyNumButton;
    QPushButton *printAllButton;
    QPushButton *printAddedButton;
    QPushButton *saveButton;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_9;
    QPushButton *categoryFrontButton;
    QPushButton *categoryNextButton;
    QPushButton *goodsFrontButton;
    QPushButton *goodsNextButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *StockOrderCheckWidget)
    {
        if (StockOrderCheckWidget->objectName().isEmpty())
            StockOrderCheckWidget->setObjectName(QStringLiteral("StockOrderCheckWidget"));
        StockOrderCheckWidget->resize(766, 523);
        horizontalLayout = new QHBoxLayout(StockOrderCheckWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, 0);
        leftWidget = new QWidget(StockOrderCheckWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(288, 0));
        leftWidget->setMaximumSize(QSize(288, 16777215));
        verticalLayout_5 = new QVBoxLayout(leftWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(leftWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 44));
        topWidget->setMaximumSize(QSize(16777215, 44));
        topWidget->setStyleSheet(QLatin1String("QWidget#topWidget{\n"
"	background-color:#3e3d3d;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(topWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(6, 6, 6, 6);
        searchWidget = new SearchEdit(topWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));

        horizontalLayout_4->addWidget(searchWidget);


        verticalLayout_5->addWidget(topWidget);

        goodsSelectWidget = new StockGoodsSelectWidget(leftWidget);
        goodsSelectWidget->setObjectName(QStringLiteral("goodsSelectWidget"));
        goodsSelectWidget->setMinimumSize(QSize(0, 0));
        goodsSelectWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_5->addWidget(goodsSelectWidget);


        horizontalLayout->addWidget(leftWidget);

        horizontalSpacer = new QSpacerItem(8, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        middleWidget = new QWidget(StockOrderCheckWidget);
        middleWidget->setObjectName(QStringLiteral("middleWidget"));
        verticalLayout_6 = new QVBoxLayout(middleWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        categoryWidget = new AdjustPriceCategoryWidget(middleWidget);
        categoryWidget->setObjectName(QStringLiteral("categoryWidget"));
        categoryWidget->setMinimumSize(QSize(412, 111));
        categoryWidget->setMaximumSize(QSize(16777215, 111));

        verticalLayout_6->addWidget(categoryWidget);

        goodsWidget = new AdjustPriceGoodsWidget(middleWidget);
        goodsWidget->setObjectName(QStringLiteral("goodsWidget"));
        goodsWidget->setMinimumSize(QSize(412, 0));

        verticalLayout_6->addWidget(goodsWidget);

        operateWidget = new QWidget(middleWidget);
        operateWidget->setObjectName(QStringLiteral("operateWidget"));
        operateWidget->setMinimumSize(QSize(412, 53));
        operateWidget->setMaximumSize(QSize(16777215, 53));
        horizontalLayout_5 = new QHBoxLayout(operateWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 6, 0, 0);
        deleteButton = new QPushButton(operateWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
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

        horizontalLayout_5->addWidget(deleteButton);

        modifyNumButton = new QPushButton(operateWidget);
        modifyNumButton->setObjectName(QStringLiteral("modifyNumButton"));
        sizePolicy.setHeightForWidth(modifyNumButton->sizePolicy().hasHeightForWidth());
        modifyNumButton->setSizePolicy(sizePolicy);
        modifyNumButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_5->addWidget(modifyNumButton);

        printAllButton = new QPushButton(operateWidget);
        printAllButton->setObjectName(QStringLiteral("printAllButton"));
        sizePolicy.setHeightForWidth(printAllButton->sizePolicy().hasHeightForWidth());
        printAllButton->setSizePolicy(sizePolicy);
        printAllButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_5->addWidget(printAllButton);

        printAddedButton = new QPushButton(operateWidget);
        printAddedButton->setObjectName(QStringLiteral("printAddedButton"));
        sizePolicy.setHeightForWidth(printAddedButton->sizePolicy().hasHeightForWidth());
        printAddedButton->setSizePolicy(sizePolicy);
        printAddedButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_5->addWidget(printAddedButton);

        saveButton = new QPushButton(operateWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
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

        horizontalLayout_5->addWidget(saveButton);


        verticalLayout_6->addWidget(operateWidget);


        horizontalLayout->addWidget(middleWidget);

        rightWidget = new QWidget(StockOrderCheckWidget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        rightWidget->setMinimumSize(QSize(55, 0));
        rightWidget->setMaximumSize(QSize(55, 16777215));
        verticalLayout_9 = new QVBoxLayout(rightWidget);
        verticalLayout_9->setSpacing(4);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(4, 0, 0, 0);
        categoryFrontButton = new QPushButton(rightWidget);
        categoryFrontButton->setObjectName(QStringLiteral("categoryFrontButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(categoryFrontButton->sizePolicy().hasHeightForWidth());
        categoryFrontButton->setSizePolicy(sizePolicy1);
        categoryFrontButton->setMinimumSize(QSize(51, 52));
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

        verticalLayout_9->addWidget(categoryFrontButton);

        categoryNextButton = new QPushButton(rightWidget);
        categoryNextButton->setObjectName(QStringLiteral("categoryNextButton"));
        sizePolicy1.setHeightForWidth(categoryNextButton->sizePolicy().hasHeightForWidth());
        categoryNextButton->setSizePolicy(sizePolicy1);
        categoryNextButton->setMinimumSize(QSize(51, 52));
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

        verticalLayout_9->addWidget(categoryNextButton);

        goodsFrontButton = new QPushButton(rightWidget);
        goodsFrontButton->setObjectName(QStringLiteral("goodsFrontButton"));
        sizePolicy1.setHeightForWidth(goodsFrontButton->sizePolicy().hasHeightForWidth());
        goodsFrontButton->setSizePolicy(sizePolicy1);
        goodsFrontButton->setMinimumSize(QSize(51, 52));
        goodsFrontButton->setMaximumSize(QSize(16777215, 16777215));
        goodsFrontButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/goods_up.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/goods_up_press.png);\n"
"}"));

        verticalLayout_9->addWidget(goodsFrontButton);

        goodsNextButton = new QPushButton(rightWidget);
        goodsNextButton->setObjectName(QStringLiteral("goodsNextButton"));
        sizePolicy1.setHeightForWidth(goodsNextButton->sizePolicy().hasHeightForWidth());
        goodsNextButton->setSizePolicy(sizePolicy1);
        goodsNextButton->setMinimumSize(QSize(51, 52));
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

        verticalLayout_9->addWidget(goodsNextButton);

        verticalSpacer = new QSpacerItem(20, 173, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);


        horizontalLayout->addWidget(rightWidget);


        retranslateUi(StockOrderCheckWidget);

        QMetaObject::connectSlotsByName(StockOrderCheckWidget);
    } // setupUi

    void retranslateUi(QWidget *StockOrderCheckWidget)
    {
        StockOrderCheckWidget->setWindowTitle(QApplication::translate("StockOrderCheckWidget", "Form", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("StockOrderCheckWidget", "\345\210\240\351\231\244", Q_NULLPTR));
        modifyNumButton->setText(QApplication::translate("StockOrderCheckWidget", "\344\277\256\346\224\271\346\225\260\351\207\217", Q_NULLPTR));
        printAllButton->setText(QApplication::translate("StockOrderCheckWidget", "\346\211\223\345\215\260\345\205\250\351\203\250", Q_NULLPTR));
        printAddedButton->setText(QApplication::translate("StockOrderCheckWidget", "\346\211\223\345\215\260\346\226\260\345\242\236", Q_NULLPTR));
        saveButton->setText(QApplication::translate("StockOrderCheckWidget", "\344\277\235\345\255\230", Q_NULLPTR));
        categoryFrontButton->setText(QString());
        categoryNextButton->setText(QApplication::translate("StockOrderCheckWidget", "1/12\351\241\265", Q_NULLPTR));
        goodsFrontButton->setText(QString());
        goodsNextButton->setText(QApplication::translate("StockOrderCheckWidget", "1/12\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StockOrderCheckWidget: public Ui_StockOrderCheckWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKORDERCHECKWIDGET_H
