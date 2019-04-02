/********************************************************************************
** Form generated from reading UI file 'KPosCalendarWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KPOSCALENDARWIDGET_H
#define UI_KPOSCALENDARWIDGET_H

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
#include "KPosCalendarListView.h"

QT_BEGIN_NAMESPACE

class Ui_KPosCalendarWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *yearLeftButton;
    QLabel *yearLabel;
    QPushButton *yearRightButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *monthLeftButton;
    QLabel *monthLabel;
    QPushButton *monthRightButton;
    KPosCalendarListView *listView;

    void setupUi(QWidget *KPosCalendarWidget)
    {
        if (KPosCalendarWidget->objectName().isEmpty())
            KPosCalendarWidget->setObjectName(QStringLiteral("KPosCalendarWidget"));
        KPosCalendarWidget->resize(204, 185);
        verticalLayout = new QVBoxLayout(KPosCalendarWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(KPosCalendarWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 34));
        topWidget->setMaximumSize(QSize(16777215, 34));
        topWidget->setStyleSheet(QLatin1String("QWidget#topWidget{\n"
"	background-color:#fafafa;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(topWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(11, 0, 11, 1);
        widget_2 = new QWidget(topWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        yearLeftButton = new QPushButton(widget_2);
        yearLeftButton->setObjectName(QStringLiteral("yearLeftButton"));
        yearLeftButton->setMinimumSize(QSize(14, 17));
        yearLeftButton->setMaximumSize(QSize(14, 17));
        yearLeftButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/orderGoodsImage/leftArrow.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/orderGoodsImage/leftArrow_press.png);\n"
"}"));

        horizontalLayout->addWidget(yearLeftButton);

        yearLabel = new QLabel(widget_2);
        yearLabel->setObjectName(QStringLiteral("yearLabel"));
        yearLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));

        horizontalLayout->addWidget(yearLabel);

        yearRightButton = new QPushButton(widget_2);
        yearRightButton->setObjectName(QStringLiteral("yearRightButton"));
        yearRightButton->setMinimumSize(QSize(14, 17));
        yearRightButton->setMaximumSize(QSize(14, 17));
        yearRightButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/orderGoodsImage/rightArrow.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/orderGoodsImage/rightArrow_press.png);\n"
"}"));

        horizontalLayout->addWidget(yearRightButton);


        horizontalLayout_3->addWidget(widget_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        widget_3 = new QWidget(topWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        monthLeftButton = new QPushButton(widget_3);
        monthLeftButton->setObjectName(QStringLiteral("monthLeftButton"));
        monthLeftButton->setMinimumSize(QSize(14, 17));
        monthLeftButton->setMaximumSize(QSize(14, 17));
        monthLeftButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/orderGoodsImage/leftArrow.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/orderGoodsImage/leftArrow_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(monthLeftButton);

        monthLabel = new QLabel(widget_3);
        monthLabel->setObjectName(QStringLiteral("monthLabel"));
        monthLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));

        horizontalLayout_2->addWidget(monthLabel);

        monthRightButton = new QPushButton(widget_3);
        monthRightButton->setObjectName(QStringLiteral("monthRightButton"));
        monthRightButton->setMinimumSize(QSize(14, 17));
        monthRightButton->setMaximumSize(QSize(14, 17));
        monthRightButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/orderGoodsImage/rightArrow.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/orderGoodsImage/rightArrow_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(monthRightButton);


        horizontalLayout_3->addWidget(widget_3);


        verticalLayout->addWidget(topWidget);

        listView = new KPosCalendarListView(KPosCalendarWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(listView);


        retranslateUi(KPosCalendarWidget);

        QMetaObject::connectSlotsByName(KPosCalendarWidget);
    } // setupUi

    void retranslateUi(QWidget *KPosCalendarWidget)
    {
        KPosCalendarWidget->setWindowTitle(QApplication::translate("KPosCalendarWidget", "Form", Q_NULLPTR));
        yearLeftButton->setText(QString());
        yearLabel->setText(QApplication::translate("KPosCalendarWidget", "2016", Q_NULLPTR));
        yearRightButton->setText(QString());
        monthLeftButton->setText(QString());
        monthLabel->setText(QApplication::translate("KPosCalendarWidget", "2\346\234\210", Q_NULLPTR));
        monthRightButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KPosCalendarWidget: public Ui_KPosCalendarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KPOSCALENDARWIDGET_H
