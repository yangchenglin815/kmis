/********************************************************************************
** Form generated from reading UI file 'AdjustPriceOrderWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTPRICEORDERWIDGET_H
#define UI_ADJUSTPRICEORDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AdjustPriceOrderListView.h"
#include "AdjustPriceOrderTitleWidget.h"
#include "SearchEdit.h"

QT_BEGIN_NAMESPACE

class Ui_AdjustPriceOrderWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *startDateEdit;
    QWidget *widget_2;
    QLineEdit *endDateEdit;
    QSpacerItem *horizontalSpacer;
    SearchEdit *searchWidget;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_2;
    AdjustPriceOrderTitleWidget *titleWidget;
    AdjustPriceOrderListView *listView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *leftWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *lastPageButton;
    QWidget *widget_6;
    QPushButton *nextPageButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *pageLabel;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *deleteButton;
    QPushButton *checkButton;
    QPushButton *printButton;
    QPushButton *searchButton;
    QPushButton *editButton;
    QPushButton *addButton;

    void setupUi(QWidget *AdjustPriceOrderWidget)
    {
        if (AdjustPriceOrderWidget->objectName().isEmpty())
            AdjustPriceOrderWidget->setObjectName(QStringLiteral("AdjustPriceOrderWidget"));
        AdjustPriceOrderWidget->resize(766, 523);
        verticalLayout = new QVBoxLayout(AdjustPriceOrderWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(AdjustPriceOrderWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 62));
        topWidget->setMaximumSize(QSize(16777215, 62));
        horizontalLayout = new QHBoxLayout(topWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(topWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(280, 0));
        widget->setMaximumSize(QSize(280, 16777215));
        widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font-size:14px;\n"
"color:#999999;"));

        horizontalLayout_2->addWidget(label);

        startDateEdit = new QLineEdit(widget);
        startDateEdit->setObjectName(QStringLiteral("startDateEdit"));
        startDateEdit->setStyleSheet(QLatin1String("font-size:12px;\n"
"color:#999999;"));
        startDateEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(startDateEdit);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(16, 1));
        widget_2->setMaximumSize(QSize(16, 1));
        widget_2->setStyleSheet(QStringLiteral("border: 1px solid #6c6c6c;"));

        horizontalLayout_2->addWidget(widget_2);

        endDateEdit = new QLineEdit(widget);
        endDateEdit->setObjectName(QStringLiteral("endDateEdit"));
        endDateEdit->setStyleSheet(QLatin1String("font-size:12px;\n"
"color:#999999;"));
        endDateEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(endDateEdit);


        horizontalLayout->addWidget(widget);

        horizontalSpacer = new QSpacerItem(215, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchWidget = new SearchEdit(topWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));
        searchWidget->setMinimumSize(QSize(262, 32));
        searchWidget->setMaximumSize(QSize(262, 32));

        horizontalLayout->addWidget(searchWidget);


        verticalLayout->addWidget(topWidget);

        mainWidget = new QWidget(AdjustPriceOrderWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        verticalLayout_2 = new QVBoxLayout(mainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWidget = new AdjustPriceOrderTitleWidget(mainWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(titleWidget);

        listView = new AdjustPriceOrderListView(mainWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"}"));

        verticalLayout_2->addWidget(listView);

        bottomWidget = new QWidget(mainWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 62));
        bottomWidget->setMaximumSize(QSize(16777215, 62));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(bottomWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 16, 20);
        leftWidget = new QWidget(bottomWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(200, 0));
        leftWidget->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_4 = new QHBoxLayout(leftWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        widget_5 = new QWidget(leftWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        lastPageButton = new QPushButton(widget_5);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(87, 37));
        lastPageButton->setMaximumSize(QSize(87, 37));
        lastPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/saleImage/btn-up-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/saleImage/btn-up-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"border-image: url(:/saleImage/btn-up-disable.png);\n"
"}"));

        horizontalLayout_5->addWidget(lastPageButton);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(1, 18));
        widget_6->setMaximumSize(QSize(1, 18));
        widget_6->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout_5->addWidget(widget_6);

        nextPageButton = new QPushButton(widget_5);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(87, 37));
        nextPageButton->setMaximumSize(QSize(87, 37));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/saleImage/btn-down-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/btn-down-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/saleImage/btn-down-disabled.png);\n"
"}"));

        horizontalLayout_5->addWidget(nextPageButton);


        horizontalLayout_4->addWidget(widget_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pageLabel = new QLabel(leftWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));

        horizontalLayout_4->addWidget(pageLabel);


        horizontalLayout_3->addWidget(leftWidget);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        widget_3 = new QWidget(bottomWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setMinimumSize(QSize(518, 0));
        widget_3->setMaximumSize(QSize(518, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget_3);
        horizontalLayout_6->setSpacing(4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        deleteButton = new QPushButton(widget_3);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);
        deleteButton->setMinimumSize(QSize(0, 0));
        deleteButton->setMaximumSize(QSize(16777215, 16777215));
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

        horizontalLayout_6->addWidget(deleteButton);

        checkButton = new QPushButton(widget_3);
        checkButton->setObjectName(QStringLiteral("checkButton"));
        sizePolicy1.setHeightForWidth(checkButton->sizePolicy().hasHeightForWidth());
        checkButton->setSizePolicy(sizePolicy1);
        checkButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_6->addWidget(checkButton);

        printButton = new QPushButton(widget_3);
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

        horizontalLayout_6->addWidget(printButton);

        searchButton = new QPushButton(widget_3);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        sizePolicy1.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy1);
        searchButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_6->addWidget(searchButton);

        editButton = new QPushButton(widget_3);
        editButton->setObjectName(QStringLiteral("editButton"));
        sizePolicy1.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy1);
        editButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_6->addWidget(editButton);

        addButton = new QPushButton(widget_3);
        addButton->setObjectName(QStringLiteral("addButton"));
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(0, 0));
        addButton->setMaximumSize(QSize(16777215, 16777215));
        addButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_6->addWidget(addButton);


        horizontalLayout_3->addWidget(widget_3);


        verticalLayout_2->addWidget(bottomWidget);


        verticalLayout->addWidget(mainWidget);


        retranslateUi(AdjustPriceOrderWidget);

        QMetaObject::connectSlotsByName(AdjustPriceOrderWidget);
    } // setupUi

    void retranslateUi(QWidget *AdjustPriceOrderWidget)
    {
        AdjustPriceOrderWidget->setWindowTitle(QApplication::translate("AdjustPriceOrderWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("AdjustPriceOrderWidget", "\346\227\245\346\234\237\347\255\233\351\200\211\357\274\232", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("AdjustPriceOrderWidget", "1/1\351\241\265", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("AdjustPriceOrderWidget", "\345\210\240\351\231\244", Q_NULLPTR));
        checkButton->setText(QApplication::translate("AdjustPriceOrderWidget", "\345\256\241\346\240\270", Q_NULLPTR));
        printButton->setText(QApplication::translate("AdjustPriceOrderWidget", "\346\211\223\345\215\260", Q_NULLPTR));
        searchButton->setText(QApplication::translate("AdjustPriceOrderWidget", "\346\237\245\347\234\213", Q_NULLPTR));
        editButton->setText(QApplication::translate("AdjustPriceOrderWidget", "\347\274\226\350\276\221", Q_NULLPTR));
        addButton->setText(QApplication::translate("AdjustPriceOrderWidget", "\346\226\260\345\242\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdjustPriceOrderWidget: public Ui_AdjustPriceOrderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTPRICEORDERWIDGET_H
