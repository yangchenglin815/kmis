/********************************************************************************
** Form generated from reading UI file 'PendingListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENDINGLISTWIDGET_H
#define UI_PENDINGLISTWIDGET_H

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
#include "PendingListTitleWidget.h"
#include "PendingListView.h"

QT_BEGIN_NAMESPACE

class Ui_PendingListWidget
{
public:
    QVBoxLayout *verticalLayout;
    PendingListTitleWidget *titleWidget;
    PendingListView *listView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *upPageButton;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QPushButton *downPageButton;
    QLabel *pageNumLabel;

    void setupUi(QWidget *PendingListWidget)
    {
        if (PendingListWidget->objectName().isEmpty())
            PendingListWidget->setObjectName(QStringLiteral("PendingListWidget"));
        PendingListWidget->resize(291, 347);
        PendingListWidget->setMinimumSize(QSize(291, 347));
        verticalLayout = new QVBoxLayout(PendingListWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new PendingListTitleWidget(PendingListWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 36));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));
        titleWidget->setStyleSheet(QStringLiteral("border-bottom: 1px solid #ededed;"));

        verticalLayout->addWidget(titleWidget);

        listView = new PendingListView(PendingListWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(0, 268));
        listView->setMaximumSize(QSize(16777215, 348));
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setStyleSheet(QLatin1String("border:none;\n"
"background-color: rgb(250, 250, 250);"));
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(listView);

        widget = new QWidget(PendingListWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 40));
        widget->setMaximumSize(QSize(16777215, 40));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-top: 1px solid #ededed;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 20, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        upPageButton = new QPushButton(widget);
        upPageButton->setObjectName(QStringLiteral("upPageButton"));
        upPageButton->setMinimumSize(QSize(87, 37));
        upPageButton->setMaximumSize(QSize(87, 37));
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
        frame->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        downPageButton = new QPushButton(widget);
        downPageButton->setObjectName(QStringLiteral("downPageButton"));
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

        pageNumLabel = new QLabel(widget);
        pageNumLabel->setObjectName(QStringLiteral("pageNumLabel"));

        horizontalLayout->addWidget(pageNumLabel);


        verticalLayout->addWidget(widget);


        retranslateUi(PendingListWidget);

        QMetaObject::connectSlotsByName(PendingListWidget);
    } // setupUi

    void retranslateUi(QWidget *PendingListWidget)
    {
        PendingListWidget->setWindowTitle(QApplication::translate("PendingListWidget", "Form", Q_NULLPTR));
        upPageButton->setText(QString());
        downPageButton->setText(QString());
        pageNumLabel->setText(QApplication::translate("PendingListWidget", "1/1\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PendingListWidget: public Ui_PendingListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENDINGLISTWIDGET_H
