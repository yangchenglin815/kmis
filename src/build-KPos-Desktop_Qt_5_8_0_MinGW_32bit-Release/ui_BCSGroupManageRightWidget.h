/********************************************************************************
** Form generated from reading UI file 'BCSGroupManageRightWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSGROUPMANAGERIGHTWIDGET_H
#define UI_BCSGROUPMANAGERIGHTWIDGET_H

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
#include "BCSGroupManageRightListView.h"
#include "BCSGroupManageRightTitleWiget.h"

QT_BEGIN_NAMESPACE

class Ui_BCSGroupManageRightWidget
{
public:
    QVBoxLayout *verticalLayout;
    BCSGroupManageRightTitleWiget *titleWidget;
    BCSGroupManageRightListView *listView;
    QWidget *turnPageWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *lastPageButton;
    QWidget *widget_6;
    QPushButton *nextPageButton;
    QLabel *pageLabel;

    void setupUi(QWidget *BCSGroupManageRightWidget)
    {
        if (BCSGroupManageRightWidget->objectName().isEmpty())
            BCSGroupManageRightWidget->setObjectName(QStringLiteral("BCSGroupManageRightWidget"));
        BCSGroupManageRightWidget->resize(518, 396);
        verticalLayout = new QVBoxLayout(BCSGroupManageRightWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new BCSGroupManageRightTitleWiget(BCSGroupManageRightWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(titleWidget);

        listView = new BCSGroupManageRightListView(BCSGroupManageRightWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        turnPageWidget = new QWidget(BCSGroupManageRightWidget);
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
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

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


        horizontalLayout_4->addWidget(widget_5);

        pageLabel = new QLabel(turnPageWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));

        horizontalLayout_4->addWidget(pageLabel);


        verticalLayout->addWidget(turnPageWidget);


        retranslateUi(BCSGroupManageRightWidget);

        QMetaObject::connectSlotsByName(BCSGroupManageRightWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSGroupManageRightWidget)
    {
        BCSGroupManageRightWidget->setWindowTitle(QApplication::translate("BCSGroupManageRightWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("BCSGroupManageRightWidget", "1/1\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSGroupManageRightWidget: public Ui_BCSGroupManageRightWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSGROUPMANAGERIGHTWIDGET_H
