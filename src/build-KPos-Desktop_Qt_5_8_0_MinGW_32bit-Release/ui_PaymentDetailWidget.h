/********************************************************************************
** Form generated from reading UI file 'PaymentDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTDETAILWIDGET_H
#define UI_PAYMENTDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "PaymentDetailTitle.h"
#include "PaymentDetailView.h"

QT_BEGIN_NAMESPACE

class Ui_PaymentDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    PaymentDetailTitle *titleWidget;
    PaymentDetailView *PayDetailsView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *pageLabel;
    QPushButton *upPageButton;
    QFrame *frame;
    QPushButton *downPageButton;

    void setupUi(QWidget *PaymentDetailWidget)
    {
        if (PaymentDetailWidget->objectName().isEmpty())
            PaymentDetailWidget->setObjectName(QStringLiteral("PaymentDetailWidget"));
        PaymentDetailWidget->resize(506, 190);
        PaymentDetailWidget->setMinimumSize(QSize(506, 190));
        verticalLayout = new QVBoxLayout(PaymentDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new PaymentDetailTitle(PaymentDetailWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 37));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(titleWidget);

        PayDetailsView = new PaymentDetailView(PaymentDetailWidget);
        PayDetailsView->setObjectName(QStringLiteral("PayDetailsView"));
        PayDetailsView->setFocusPolicy(Qt::NoFocus);
        PayDetailsView->setStyleSheet(QLatin1String("border:none;\n"
"background-color: rgb(250, 250, 250);"));
        PayDetailsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        PayDetailsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(PayDetailsView);

        widget = new QWidget(PaymentDetailWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 40));
        widget->setMaximumSize(QSize(16777215, 40));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pageLabel = new QLabel(widget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(pageLabel);

        upPageButton = new QPushButton(widget);
        upPageButton->setObjectName(QStringLiteral("upPageButton"));
        upPageButton->setMinimumSize(QSize(26, 18));
        upPageButton->setMaximumSize(QSize(87, 37));
        upPageButton->setFocusPolicy(Qt::NoFocus);
        upPageButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        upPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border:none;\n"
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
"	border-image: url(:/saleImage/btn-up-disable.png);\n"
"}"));

        horizontalLayout->addWidget(upPageButton);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(1, 22));
        frame->setMaximumSize(QSize(1, 22));
        frame->setStyleSheet(QLatin1String("QFrame#frame {\n"
"	border:1px solid  rgb(237, 237, 237);\n"
"}"));
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        downPageButton = new QPushButton(widget);
        downPageButton->setObjectName(QStringLiteral("downPageButton"));
        downPageButton->setMinimumSize(QSize(26, 18));
        downPageButton->setMaximumSize(QSize(87, 37));
        downPageButton->setFocusPolicy(Qt::NoFocus);
        downPageButton->setContextMenuPolicy(Qt::NoContextMenu);
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


        verticalLayout->addWidget(widget);


        retranslateUi(PaymentDetailWidget);

        QMetaObject::connectSlotsByName(PaymentDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *PaymentDetailWidget)
    {
        PaymentDetailWidget->setWindowTitle(QApplication::translate("PaymentDetailWidget", "Form", Q_NULLPTR));
        pageLabel->setText(QApplication::translate("PaymentDetailWidget", "1/1\351\241\265", Q_NULLPTR));
        upPageButton->setText(QString());
        downPageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PaymentDetailWidget: public Ui_PaymentDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTDETAILWIDGET_H
