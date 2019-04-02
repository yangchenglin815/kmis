/********************************************************************************
** Form generated from reading UI file 'ReceiveOrderCheckWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEORDERCHECKWIDGET_H
#define UI_RECEIVEORDERCHECKWIDGET_H

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
#include "ReceiveOrderGoodsWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiveOrderCheckWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *backButton;
    QLabel *label;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *orderIdValueLabel;
    QFrame *frame;
    QLabel *label_4;
    QLabel *providerNameLabel;
    QWidget *widget_5;
    QLabel *orderTimeLabel;
    ReceiveOrderGoodsWidget *receiveOrderGoodsWidget;

    void setupUi(QWidget *ReceiveOrderCheckWidget)
    {
        if (ReceiveOrderCheckWidget->objectName().isEmpty())
            ReceiveOrderCheckWidget->setObjectName(QStringLiteral("ReceiveOrderCheckWidget"));
        ReceiveOrderCheckWidget->resize(760, 523);
        verticalLayout = new QVBoxLayout(ReceiveOrderCheckWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ReceiveOrderCheckWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 60));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(150, 0));
        widget_3->setMaximumSize(QSize(150, 16777215));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(12);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        backButton = new QPushButton(widget_3);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setMinimumSize(QSize(15, 18));
        backButton->setMaximumSize(QSize(15, 18));
        backButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/orderGoodsImage/leftArrow.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/orderGoodsImage/leftArrow_press.png);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(backButton);

        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:16px;\n"
"color:#ffffff;"));

        horizontalLayout_2->addWidget(label);


        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 20, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color:#999999;"));

        horizontalLayout_3->addWidget(label_2);

        orderIdValueLabel = new QLabel(widget_4);
        orderIdValueLabel->setObjectName(QStringLiteral("orderIdValueLabel"));
        orderIdValueLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color:#999999;"));

        horizontalLayout_3->addWidget(orderIdValueLabel);

        frame = new QFrame(widget_4);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(1, 12));
        frame->setMaximumSize(QSize(1, 12));
        frame->setStyleSheet(QStringLiteral("border: 1px solid #6c6c6c;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(frame);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color:#999999;"));

        horizontalLayout_3->addWidget(label_4);

        providerNameLabel = new QLabel(widget_4);
        providerNameLabel->setObjectName(QStringLiteral("providerNameLabel"));
        providerNameLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color:#999999;"));

        horizontalLayout_3->addWidget(providerNameLabel);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(1, 12));
        widget_5->setMaximumSize(QSize(1, 12));
        widget_5->setStyleSheet(QStringLiteral("border: 1px solid #6c6c6c;"));

        horizontalLayout_3->addWidget(widget_5);

        orderTimeLabel = new QLabel(widget_4);
        orderTimeLabel->setObjectName(QStringLiteral("orderTimeLabel"));
        orderTimeLabel->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:12px;\n"
"color:#999999;"));

        horizontalLayout_3->addWidget(orderTimeLabel);


        horizontalLayout->addWidget(widget_4);


        verticalLayout->addWidget(widget);

        receiveOrderGoodsWidget = new ReceiveOrderGoodsWidget(ReceiveOrderCheckWidget);
        receiveOrderGoodsWidget->setObjectName(QStringLiteral("receiveOrderGoodsWidget"));

        verticalLayout->addWidget(receiveOrderGoodsWidget);


        retranslateUi(ReceiveOrderCheckWidget);

        QMetaObject::connectSlotsByName(ReceiveOrderCheckWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiveOrderCheckWidget)
    {
        ReceiveOrderCheckWidget->setWindowTitle(QApplication::translate("ReceiveOrderCheckWidget", "Form", Q_NULLPTR));
        backButton->setText(QString());
        label->setText(QApplication::translate("ReceiveOrderCheckWidget", "\350\277\224\345\233\236\351\200\201\345\233\236\345\215\225\345\210\227\350\241\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReceiveOrderCheckWidget", "\351\200\201\350\264\247\345\215\225\345\217\267\357\274\232", Q_NULLPTR));
        orderIdValueLabel->setText(QApplication::translate("ReceiveOrderCheckWidget", "21555558888", Q_NULLPTR));
        label_4->setText(QApplication::translate("ReceiveOrderCheckWidget", "\344\276\233\345\272\224\345\225\206\357\274\232", Q_NULLPTR));
        providerNameLabel->setText(QApplication::translate("ReceiveOrderCheckWidget", "\345\205\204\345\274\237\346\260\264\346\236\234\344\276\233\345\272\224\345\225\206", Q_NULLPTR));
        orderTimeLabel->setText(QApplication::translate("ReceiveOrderCheckWidget", "2016.02.12 12:20", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiveOrderCheckWidget: public Ui_ReceiveOrderCheckWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEORDERCHECKWIDGET_H
