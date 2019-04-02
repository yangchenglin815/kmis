/********************************************************************************
** Form generated from reading UI file 'GoodsSelectForCreateWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSSELECTFORCREATEWIDGET_H
#define UI_GOODSSELECTFORCREATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GoodsForCreateListView.h"

QT_BEGIN_NAMESPACE

class Ui_GoodsSelectForCreateWidget
{
public:
    QVBoxLayout *verticalLayout;
    GoodsForCreateListView *listView;
    QWidget *pageUpDownWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *lastPageButton;
    QWidget *widget_3;
    QPushButton *nextPageButton;
    QLabel *pageLabel;
    QWidget *confirmWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *lastStepButton;
    QPushButton *confirmButton;

    void setupUi(QWidget *GoodsSelectForCreateWidget)
    {
        if (GoodsSelectForCreateWidget->objectName().isEmpty())
            GoodsSelectForCreateWidget->setObjectName(QStringLiteral("GoodsSelectForCreateWidget"));
        GoodsSelectForCreateWidget->resize(290, 493);
        verticalLayout = new QVBoxLayout(GoodsSelectForCreateWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new GoodsForCreateListView(GoodsSelectForCreateWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        pageUpDownWidget = new QWidget(GoodsSelectForCreateWidget);
        pageUpDownWidget->setObjectName(QStringLiteral("pageUpDownWidget"));
        pageUpDownWidget->setMinimumSize(QSize(0, 40));
        pageUpDownWidget->setMaximumSize(QSize(16777215, 40));
        pageUpDownWidget->setStyleSheet(QLatin1String("QWidget#pageUpDownWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout = new QHBoxLayout(pageUpDownWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(16, 0, 12, 0);
        widget_4 = new QWidget(pageUpDownWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(17);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lastPageButton = new QPushButton(widget_4);
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

        horizontalLayout_3->addWidget(lastPageButton);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(1, 18));
        widget_3->setMaximumSize(QSize(1, 18));
        widget_3->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout_3->addWidget(widget_3);

        nextPageButton = new QPushButton(widget_4);
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

        horizontalLayout_3->addWidget(nextPageButton);


        horizontalLayout->addWidget(widget_4);

        pageLabel = new QLabel(pageUpDownWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setMinimumSize(QSize(60, 0));
        pageLabel->setMaximumSize(QSize(60, 16777215));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));
        pageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(pageLabel);


        verticalLayout->addWidget(pageUpDownWidget);

        confirmWidget = new QWidget(GoodsSelectForCreateWidget);
        confirmWidget->setObjectName(QStringLiteral("confirmWidget"));
        confirmWidget->setMinimumSize(QSize(0, 50));
        confirmWidget->setMaximumSize(QSize(16777215, 50));
        confirmWidget->setStyleSheet(QLatin1String("QWidget#confirmWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(confirmWidget);
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(12, 0, 12, 9);
        lastStepButton = new QPushButton(confirmWidget);
        lastStepButton->setObjectName(QStringLiteral("lastStepButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lastStepButton->sizePolicy().hasHeightForWidth());
        lastStepButton->setSizePolicy(sizePolicy);
        lastStepButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/orderGoodsImage/blueRect.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/orderGoodsImage/blueRect_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(lastStepButton);

        confirmButton = new QPushButton(confirmWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        sizePolicy.setHeightForWidth(confirmButton->sizePolicy().hasHeightForWidth());
        confirmButton->setSizePolicy(sizePolicy);
        confirmButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/orderGoodsImage/orangeRect.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/orderGoodsImage/orangeRect_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(confirmButton);


        verticalLayout->addWidget(confirmWidget);


        retranslateUi(GoodsSelectForCreateWidget);

        QMetaObject::connectSlotsByName(GoodsSelectForCreateWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodsSelectForCreateWidget)
    {
        GoodsSelectForCreateWidget->setWindowTitle(QApplication::translate("GoodsSelectForCreateWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("GoodsSelectForCreateWidget", "1/1\351\241\265", Q_NULLPTR));
        lastStepButton->setText(QApplication::translate("GoodsSelectForCreateWidget", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("GoodsSelectForCreateWidget", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GoodsSelectForCreateWidget: public Ui_GoodsSelectForCreateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSSELECTFORCREATEWIDGET_H
