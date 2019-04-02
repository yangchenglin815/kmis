/********************************************************************************
** Form generated from reading UI file 'ReceiveProviderForCreateWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEPROVIDERFORCREATEWIDGET_H
#define UI_RECEIVEPROVIDERFORCREATEWIDGET_H

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
#include "ReceiveProviderListView.h"
#include "SearchEdit.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiveProviderForCreateWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    SearchEdit *searchEdit;
    ReceiveProviderListView *listView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *lastPageButton;
    QWidget *widget_3;
    QPushButton *nextPageButton;
    QLabel *pageLabel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ReceiveProviderForCreateWidget)
    {
        if (ReceiveProviderForCreateWidget->objectName().isEmpty())
            ReceiveProviderForCreateWidget->setObjectName(QStringLiteral("ReceiveProviderForCreateWidget"));
        ReceiveProviderForCreateWidget->resize(529, 493);
        verticalLayout = new QVBoxLayout(ReceiveProviderForCreateWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(ReceiveProviderForCreateWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 80));
        topWidget->setMaximumSize(QSize(16777215, 80));
        topWidget->setStyleSheet(QStringLiteral("background-color:#ffffff;"));
        horizontalLayout_2 = new QHBoxLayout(topWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(31, 24, 31, 24);
        label = new QLabel(topWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(58, 0));
        label->setMaximumSize(QSize(58, 16777215));
        label->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:#333333;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label);

        searchEdit = new SearchEdit(topWidget);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));
        searchEdit->setStyleSheet(QStringLiteral("border: 1px solid #ea8852;"));

        horizontalLayout_2->addWidget(searchEdit);


        verticalLayout->addWidget(topWidget);

        listView = new ReceiveProviderListView(ReceiveProviderForCreateWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        bottomWidget = new QWidget(ReceiveProviderForCreateWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 58));
        bottomWidget->setMaximumSize(QSize(16777215, 58));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(bottomWidget);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, 0, 14, 0);
        widget_4 = new QWidget(bottomWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(24);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
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

        horizontalLayout_4->addWidget(lastPageButton);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(1, 18));
        widget_3->setMaximumSize(QSize(1, 18));
        widget_3->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout_4->addWidget(widget_3);

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

        horizontalLayout_4->addWidget(nextPageButton);


        horizontalLayout_3->addWidget(widget_4);

        pageLabel = new QLabel(bottomWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));

        horizontalLayout_3->addWidget(pageLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(bottomWidget);


        retranslateUi(ReceiveProviderForCreateWidget);

        QMetaObject::connectSlotsByName(ReceiveProviderForCreateWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiveProviderForCreateWidget)
    {
        ReceiveProviderForCreateWidget->setWindowTitle(QApplication::translate("ReceiveProviderForCreateWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ReceiveProviderForCreateWidget", "\344\276\233\345\272\224\345\225\206", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("ReceiveProviderForCreateWidget", "1/1\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiveProviderForCreateWidget: public Ui_ReceiveProviderForCreateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEPROVIDERFORCREATEWIDGET_H
