/********************************************************************************
** Form generated from reading UI file 'GoodsSellListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSSELLLISTWIDGET_H
#define UI_GOODSSELLLISTWIDGET_H

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
#include "GoodsSellListTitleWidget.h"
#include "GoodsSellListView.h"

QT_BEGIN_NAMESPACE

class Ui_GoodsSellListWidget
{
public:
    QVBoxLayout *verticalLayout;
    GoodsSellListTitleWidget *titleWidget;
    GoodsSellListView *listView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *upPageButton;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *downPageButton;
    QSpacerItem *horizontalSpacer;
    QLabel *sellListPageLabel;

    void setupUi(QWidget *GoodsSellListWidget)
    {
        if (GoodsSellListWidget->objectName().isEmpty())
            GoodsSellListWidget->setObjectName(QStringLiteral("GoodsSellListWidget"));
        GoodsSellListWidget->resize(288, 313);
        GoodsSellListWidget->setMinimumSize(QSize(288, 313));
        verticalLayout = new QVBoxLayout(GoodsSellListWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new GoodsSellListTitleWidget(GoodsSellListWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 34));
        titleWidget->setMaximumSize(QSize(16777215, 34));

        verticalLayout->addWidget(titleWidget);

        listView = new GoodsSellListView(GoodsSellListWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setStyleSheet(QLatin1String("border:none;\n"
"background-color: rgb(250, 250, 250);"));
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(listView);

        widget = new QWidget(GoodsSellListWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 41));
        widget->setMaximumSize(QSize(16777215, 41));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        upPageButton = new QPushButton(widget);
        upPageButton->setObjectName(QStringLiteral("upPageButton"));
        upPageButton->setMinimumSize(QSize(87, 37));
        upPageButton->setMaximumSize(QSize(288, 37));
        upPageButton->setFocusPolicy(Qt::NoFocus);
        upPageButton->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout->addWidget(upPageButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(1, 22));
        frame->setMaximumSize(QSize(1, 22));
        frame->setStyleSheet(QLatin1String("/*background-color:rgb(167, 167, 167);*/\n"
"border:1px solid  rgb(237, 237, 237);"));
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        downPageButton = new QPushButton(widget);
        downPageButton->setObjectName(QStringLiteral("downPageButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(downPageButton->sizePolicy().hasHeightForWidth());
        downPageButton->setSizePolicy(sizePolicy);
        downPageButton->setMinimumSize(QSize(87, 37));
        downPageButton->setMaximumSize(QSize(87, 37));
        downPageButton->setFocusPolicy(Qt::NoFocus);
        downPageButton->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout->addWidget(downPageButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sellListPageLabel = new QLabel(widget);
        sellListPageLabel->setObjectName(QStringLiteral("sellListPageLabel"));

        horizontalLayout->addWidget(sellListPageLabel);


        verticalLayout->addWidget(widget);


        retranslateUi(GoodsSellListWidget);

        QMetaObject::connectSlotsByName(GoodsSellListWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodsSellListWidget)
    {
        GoodsSellListWidget->setWindowTitle(QApplication::translate("GoodsSellListWidget", "Form", Q_NULLPTR));
        upPageButton->setText(QString());
        downPageButton->setText(QString());
        sellListPageLabel->setText(QApplication::translate("GoodsSellListWidget", "1/1\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GoodsSellListWidget: public Ui_GoodsSellListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSSELLLISTWIDGET_H
