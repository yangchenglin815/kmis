/********************************************************************************
** Form generated from reading UI file 'BCSGroupManageLeftWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSGROUPMANAGELEFTWIDGET_H
#define UI_BCSGROUPMANAGELEFTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCSGroupManageLeftListView.h"
#include "BCSGroupManageLeftTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCSGroupManageLeftWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    BCSGroupManageLeftTitleWidget *titleWidget;
    BCSGroupManageLeftListView *listView;
    QWidget *turnPageWidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *lastPageButton;
    QWidget *widget_6;
    QPushButton *nextPageButton;
    QSpacerItem *horizontalSpacer;
    QLabel *pageLabel;

    void setupUi(QWidget *BCSGroupManageLeftWidget)
    {
        if (BCSGroupManageLeftWidget->objectName().isEmpty())
            BCSGroupManageLeftWidget->setObjectName(QStringLiteral("BCSGroupManageLeftWidget"));
        BCSGroupManageLeftWidget->resize(240, 396);
        BCSGroupManageLeftWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(BCSGroupManageLeftWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWidget = new BCSGroupManageLeftTitleWidget(BCSGroupManageLeftWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(titleWidget);

        listView = new BCSGroupManageLeftListView(BCSGroupManageLeftWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"}"));

        verticalLayout_2->addWidget(listView);

        turnPageWidget = new QWidget(BCSGroupManageLeftWidget);
        turnPageWidget->setObjectName(QStringLiteral("turnPageWidget"));
        turnPageWidget->setMinimumSize(QSize(0, 0));
        turnPageWidget->setMaximumSize(QSize(16777215, 16777215));
        turnPageWidget->setStyleSheet(QLatin1String("QWidget#turnPageWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(turnPageWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(turnPageWidget);
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

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        horizontalLayout_4->addWidget(widget_5);

        pageLabel = new QLabel(turnPageWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));

        horizontalLayout_4->addWidget(pageLabel);


        verticalLayout_2->addWidget(turnPageWidget);


        retranslateUi(BCSGroupManageLeftWidget);

        QMetaObject::connectSlotsByName(BCSGroupManageLeftWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSGroupManageLeftWidget)
    {
        BCSGroupManageLeftWidget->setWindowTitle(QApplication::translate("BCSGroupManageLeftWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("BCSGroupManageLeftWidget", "1/1\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSGroupManageLeftWidget: public Ui_BCSGroupManageLeftWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSGROUPMANAGELEFTWIDGET_H
