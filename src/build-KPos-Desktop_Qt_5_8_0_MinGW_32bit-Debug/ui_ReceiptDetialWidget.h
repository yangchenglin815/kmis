/********************************************************************************
** Form generated from reading UI file 'ReceiptDetialWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIPTDETIALWIDGET_H
#define UI_RECEIPTDETIALWIDGET_H

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
#include "receiptdetialinfowidget.h"
#include "receiptdetiallistview.h"
#include "receiptdetialtitlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiptDetialWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout_2;
    ReceiptDetialTitleWidget *titleWidget;
    ReceiptDetialListView *receiptListView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *groupWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *buttonWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *lastButton;
    QWidget *widget_6;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *pageLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *contrlWidget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *printButton;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_3;
    ReceiptDetialInfoWidget *receiptDetialWidget;

    void setupUi(QWidget *ReceiptDetialWidget)
    {
        if (ReceiptDetialWidget->objectName().isEmpty())
            ReceiptDetialWidget->setObjectName(QStringLiteral("ReceiptDetialWidget"));
        ReceiptDetialWidget->resize(766, 523);
        ReceiptDetialWidget->setSizeIncrement(QSize(76, 52));
        ReceiptDetialWidget->setBaseSize(QSize(766, 523));
        verticalLayout = new QVBoxLayout(ReceiptDetialWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainWidget = new QWidget(ReceiptDetialWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 15, 0, 0);
        leftWidget = new QWidget(mainWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        verticalLayout_2 = new QVBoxLayout(leftWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWidget = new ReceiptDetialTitleWidget(leftWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(titleWidget);

        receiptListView = new ReceiptDetialListView(leftWidget);
        receiptListView->setObjectName(QStringLiteral("receiptListView"));
        receiptListView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"}"));

        verticalLayout_2->addWidget(receiptListView);

        bottomWidget = new QWidget(leftWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 62));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"    background-color:#ffffff;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(bottomWidget);
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 16, 20);
        groupWidget = new QWidget(bottomWidget);
        groupWidget->setObjectName(QStringLiteral("groupWidget"));
        groupWidget->setMinimumSize(QSize(200, 0));
        horizontalLayout_4 = new QHBoxLayout(groupWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        buttonWidget = new QWidget(groupWidget);
        buttonWidget->setObjectName(QStringLiteral("buttonWidget"));
        horizontalLayout_3 = new QHBoxLayout(buttonWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lastButton = new QPushButton(buttonWidget);
        lastButton->setObjectName(QStringLiteral("lastButton"));
        lastButton->setMinimumSize(QSize(87, 37));
        lastButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"        border-image: url(:/saleImage/btn-up-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"        border-image: url(:/saleImage/btn-up-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"border-image: url(:/saleImage/btn-up-disable.png);\n"
"}"));

        horizontalLayout_3->addWidget(lastButton);

        widget_6 = new QWidget(buttonWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(1, 18));
        widget_6->setMaximumSize(QSize(1, 18));
        widget_6->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout_3->addWidget(widget_6);

        nextButton = new QPushButton(buttonWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setMinimumSize(QSize(87, 37));
        nextButton->setStyleSheet(QLatin1String("QPushButton{\n"
"        border-image: url(:/saleImage/btn-down-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"        border-image: url(:/saleImage/btn-down-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"        border-image: url(:/saleImage/btn-down-disabled.png);\n"
"}"));

        horizontalLayout_3->addWidget(nextButton);


        horizontalLayout_4->addWidget(buttonWidget);

        horizontalSpacer_3 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pageLabel = new QLabel(groupWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));

        horizontalLayout_4->addWidget(pageLabel);


        horizontalLayout_2->addWidget(groupWidget);

        horizontalSpacer = new QSpacerItem(86, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        contrlWidget = new QWidget(bottomWidget);
        contrlWidget->setObjectName(QStringLiteral("contrlWidget"));
        contrlWidget->setMinimumSize(QSize(300, 0));
        horizontalLayout_5 = new QHBoxLayout(contrlWidget);
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(210, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        printButton = new QPushButton(contrlWidget);
        printButton->setObjectName(QStringLiteral("printButton"));
        printButton->setMinimumSize(QSize(83, 42));
        printButton->setStyleSheet(QLatin1String("QPushButton{\n"
"        font-size:16px;\n"
"        color:#ffffff;\n"
"        border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"        border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"        border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_5->addWidget(printButton);


        horizontalLayout_2->addWidget(contrlWidget);


        verticalLayout_2->addWidget(bottomWidget);


        horizontalLayout->addWidget(leftWidget);

        rightWidget = new QWidget(mainWidget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        verticalLayout_3 = new QVBoxLayout(rightWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        receiptDetialWidget = new ReceiptDetialInfoWidget(rightWidget);
        receiptDetialWidget->setObjectName(QStringLiteral("receiptDetialWidget"));

        verticalLayout_3->addWidget(receiptDetialWidget);


        horizontalLayout->addWidget(rightWidget);

        horizontalLayout->setStretch(0, 466);
        horizontalLayout->setStretch(1, 300);

        verticalLayout->addWidget(mainWidget);


        retranslateUi(ReceiptDetialWidget);

        QMetaObject::connectSlotsByName(ReceiptDetialWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiptDetialWidget)
    {
        ReceiptDetialWidget->setWindowTitle(QApplication::translate("ReceiptDetialWidget", "Form", Q_NULLPTR));
        lastButton->setText(QString());
        nextButton->setText(QString());
        pageLabel->setText(QApplication::translate("ReceiptDetialWidget", "1/1\351\241\265", Q_NULLPTR));
        printButton->setText(QApplication::translate("ReceiptDetialWidget", "\346\211\223\345\215\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiptDetialWidget: public Ui_ReceiptDetialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIPTDETIALWIDGET_H
