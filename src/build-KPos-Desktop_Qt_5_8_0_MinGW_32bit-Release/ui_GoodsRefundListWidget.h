/********************************************************************************
** Form generated from reading UI file 'GoodsRefundListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSREFUNDLISTWIDGET_H
#define UI_GOODSREFUNDLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GoodsRefundListView.h"
#include "GoodsSellListTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GoodsRefundListWidget
{
public:
    QVBoxLayout *verticalLayout;
    GoodsSellListTitleWidget *titleWidget;
    GoodsRefundListView *listView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *lastPageButton;
    QFrame *frame;
    QPushButton *nextPageButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *pageLabel;

    void setupUi(QWidget *GoodsRefundListWidget)
    {
        if (GoodsRefundListWidget->objectName().isEmpty())
            GoodsRefundListWidget->setObjectName(QStringLiteral("GoodsRefundListWidget"));
        GoodsRefundListWidget->resize(305, 347);
        verticalLayout = new QVBoxLayout(GoodsRefundListWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new GoodsSellListTitleWidget(GoodsRefundListWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 34));
        titleWidget->setMaximumSize(QSize(16777215, 34));

        verticalLayout->addWidget(titleWidget);

        listView = new GoodsRefundListView(GoodsRefundListWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setStyleSheet(QLatin1String("border:none;\n"
"background-color: rgb(250, 250, 250);"));
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(listView);

        widget = new QWidget(GoodsRefundListWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 41));
        widget->setMaximumSize(QSize(16777215, 41));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 12, 0);
        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lastPageButton = new QPushButton(widget);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(87, 37));
        lastPageButton->setMaximumSize(QSize(87, 37));
        lastPageButton->setFocusPolicy(Qt::NoFocus);
        lastPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-image: url(:/saleImage/btn-up-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-image: url(:/saleImage/btn-up-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"background-image: url(:/saleImage/btn-up-disable.png);\n"
"}"));

        horizontalLayout->addWidget(lastPageButton);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(1, 22));
        frame->setMaximumSize(QSize(16777215, 22));
        frame->setStyleSheet(QLatin1String("/*background-color:rgb(167, 167, 167);*/\n"
"border:1px solid  rgb(237, 237, 237);"));
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        nextPageButton = new QPushButton(widget);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nextPageButton->sizePolicy().hasHeightForWidth());
        nextPageButton->setSizePolicy(sizePolicy);
        nextPageButton->setMinimumSize(QSize(87, 37));
        nextPageButton->setMaximumSize(QSize(87, 37));
        nextPageButton->setFocusPolicy(Qt::NoFocus);
        nextPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/btn-down-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/saleImage/btn-down-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	border-image: url(:/saleImage/btn-down-disabled.png);\n"
"}"));

        horizontalLayout->addWidget(nextPageButton);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pageLabel = new QLabel(widget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setMinimumSize(QSize(60, 0));
        pageLabel->setMaximumSize(QSize(16777215, 16777215));
        pageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(pageLabel);


        verticalLayout->addWidget(widget);


        retranslateUi(GoodsRefundListWidget);

        QMetaObject::connectSlotsByName(GoodsRefundListWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodsRefundListWidget)
    {
        GoodsRefundListWidget->setWindowTitle(QApplication::translate("GoodsRefundListWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("GoodsRefundListWidget", "1/1\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GoodsRefundListWidget: public Ui_GoodsRefundListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSREFUNDLISTWIDGET_H
