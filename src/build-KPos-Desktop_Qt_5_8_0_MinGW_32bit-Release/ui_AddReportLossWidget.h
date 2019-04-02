/********************************************************************************
** Form generated from reading UI file 'AddReportLossWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDREPORTLOSSWIDGET_H
#define UI_ADDREPORTLOSSWIDGET_H

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
#include "SearchEdit.h"
#include "addreportlossselectwidget.h"
#include "reportlosscategorywidget.h"
#include "reportlossgoodswidget.h"

QT_BEGIN_NAMESPACE

class Ui_AddReportLossWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout_4;
    SearchEdit *searchWidget;
    AddReportLossSelectWidget *listWidget;
    QWidget *AllBtnWidget;
    QVBoxLayout *verticalLayout_2;
    ReportLossCategoryWidget *categoryWidget;
    ReportLossGoodsWidget *goodsWidget;
    QWidget *buttonWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *deleteButton;
    QPushButton *modeifyNoButton;
    QPushButton *printButton;
    QPushButton *saveButton;
    QWidget *pageWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *categoryFrontButton;
    QPushButton *categoryNextButton;
    QPushButton *goodsFrontButton;
    QPushButton *goodsNextButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AddReportLossWidget)
    {
        if (AddReportLossWidget->objectName().isEmpty())
            AddReportLossWidget->setObjectName(QStringLiteral("AddReportLossWidget"));
        AddReportLossWidget->resize(755, 539);
        AddReportLossWidget->setStyleSheet(QLatin1String("QWidget#AddReportLossWidget\n"
"{\n"
"	background-color:#505050;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(AddReportLossWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 9, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(AddReportLossWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(widget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setStyleSheet(QLatin1String("QWidget#topWidget{\n"
"	background-color:#3e3d3d;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(topWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(6, 6, 6, 6);
        searchWidget = new SearchEdit(topWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));

        horizontalLayout_4->addWidget(searchWidget);


        verticalLayout_3->addWidget(topWidget);

        listWidget = new AddReportLossSelectWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral("background-color:#fafafa;"));

        verticalLayout_3->addWidget(listWidget);

        verticalLayout_3->setStretch(0, 44);
        verticalLayout_3->setStretch(1, 485);

        horizontalLayout->addWidget(widget);

        AllBtnWidget = new QWidget(AddReportLossWidget);
        AllBtnWidget->setObjectName(QStringLiteral("AllBtnWidget"));
        verticalLayout_2 = new QVBoxLayout(AllBtnWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        categoryWidget = new ReportLossCategoryWidget(AllBtnWidget);
        categoryWidget->setObjectName(QStringLiteral("categoryWidget"));
        categoryWidget->setMinimumSize(QSize(412, 111));

        verticalLayout_2->addWidget(categoryWidget);

        goodsWidget = new ReportLossGoodsWidget(AllBtnWidget);
        goodsWidget->setObjectName(QStringLiteral("goodsWidget"));
        goodsWidget->setMinimumSize(QSize(412, 0));

        verticalLayout_2->addWidget(goodsWidget);

        buttonWidget = new QWidget(AllBtnWidget);
        buttonWidget->setObjectName(QStringLiteral("buttonWidget"));
        buttonWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(buttonWidget);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 2, 0, 0);
        deleteButton = new QPushButton(buttonWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setMinimumSize(QSize(91, 60));
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

        horizontalLayout_3->addWidget(deleteButton);

        modeifyNoButton = new QPushButton(buttonWidget);
        modeifyNoButton->setObjectName(QStringLiteral("modeifyNoButton"));
        modeifyNoButton->setMinimumSize(QSize(91, 60));
        modeifyNoButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_3->addWidget(modeifyNoButton);

        printButton = new QPushButton(buttonWidget);
        printButton->setObjectName(QStringLiteral("printButton"));
        printButton->setMinimumSize(QSize(91, 60));
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

        horizontalLayout_3->addWidget(printButton);

        saveButton = new QPushButton(buttonWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(91, 60));
        saveButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/orangeButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/orangeButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_3->addWidget(saveButton);


        verticalLayout_2->addWidget(buttonWidget);

        verticalLayout_2->setStretch(0, 111);
        verticalLayout_2->setStretch(1, 350);
        verticalLayout_2->setStretch(2, 53);

        horizontalLayout->addWidget(AllBtnWidget);

        horizontalLayout->setStretch(0, 290);
        horizontalLayout->setStretch(1, 404);

        horizontalLayout_2->addLayout(horizontalLayout);

        pageWidget = new QWidget(AddReportLossWidget);
        pageWidget->setObjectName(QStringLiteral("pageWidget"));
        pageWidget->setMinimumSize(QSize(55, 529));
        pageWidget->setMaximumSize(QSize(135, 16777215));
        verticalLayout = new QVBoxLayout(pageWidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 0, 0, 0);
        categoryFrontButton = new QPushButton(pageWidget);
        categoryFrontButton->setObjectName(QStringLiteral("categoryFrontButton"));
        categoryFrontButton->setMinimumSize(QSize(51, 51));
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

        verticalLayout->addWidget(categoryFrontButton);

        categoryNextButton = new QPushButton(pageWidget);
        categoryNextButton->setObjectName(QStringLiteral("categoryNextButton"));
        categoryNextButton->setMinimumSize(QSize(51, 51));
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

        verticalLayout->addWidget(categoryNextButton);

        goodsFrontButton = new QPushButton(pageWidget);
        goodsFrontButton->setObjectName(QStringLiteral("goodsFrontButton"));
        goodsFrontButton->setMinimumSize(QSize(51, 51));
        goodsFrontButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/goods_up.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/goods_up_press.png);\n"
"}"));

        verticalLayout->addWidget(goodsFrontButton);

        goodsNextButton = new QPushButton(pageWidget);
        goodsNextButton->setObjectName(QStringLiteral("goodsNextButton"));
        goodsNextButton->setMinimumSize(QSize(51, 51));
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

        verticalLayout->addWidget(goodsNextButton);

        verticalSpacer = new QSpacerItem(20, 316, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 52);
        verticalLayout->setStretch(1, 52);
        verticalLayout->setStretch(2, 52);
        verticalLayout->setStretch(3, 52);
        verticalLayout->setStretch(4, 265);

        horizontalLayout_2->addWidget(pageWidget);

        horizontalLayout_2->setStretch(0, 785);
        horizontalLayout_2->setStretch(1, 56);

        retranslateUi(AddReportLossWidget);

        QMetaObject::connectSlotsByName(AddReportLossWidget);
    } // setupUi

    void retranslateUi(QWidget *AddReportLossWidget)
    {
        AddReportLossWidget->setWindowTitle(QApplication::translate("AddReportLossWidget", "Form", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("AddReportLossWidget", "\345\210\240\351\231\244", Q_NULLPTR));
        modeifyNoButton->setText(QApplication::translate("AddReportLossWidget", "\344\277\256\346\224\271\346\225\260\351\207\217", Q_NULLPTR));
        printButton->setText(QApplication::translate("AddReportLossWidget", "\346\211\223\345\215\260", Q_NULLPTR));
        saveButton->setText(QApplication::translate("AddReportLossWidget", "\344\277\235\345\255\230", Q_NULLPTR));
        categoryFrontButton->setText(QString());
        categoryNextButton->setText(QString());
        goodsFrontButton->setText(QString());
        goodsNextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddReportLossWidget: public Ui_AddReportLossWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDREPORTLOSSWIDGET_H
