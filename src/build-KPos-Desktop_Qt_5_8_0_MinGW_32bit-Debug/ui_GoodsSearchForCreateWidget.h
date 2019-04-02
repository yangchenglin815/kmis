/********************************************************************************
** Form generated from reading UI file 'GoodsSearchForCreateWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSSEARCHFORCREATEWIDGET_H
#define UI_GOODSSEARCHFORCREATEWIDGET_H

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
#include "SearchEdit.h"

QT_BEGIN_NAMESPACE

class Ui_GoodsSearchForCreateWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout_2;
    SearchEdit *searchEdit;
    GoodsForCreateListView *listView;
    QWidget *pageUpDownWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *lastPageButton;
    QWidget *widget_3;
    QPushButton *nextPageButton;
    QLabel *pageLabel;

    void setupUi(QWidget *GoodsSearchForCreateWidget)
    {
        if (GoodsSearchForCreateWidget->objectName().isEmpty())
            GoodsSearchForCreateWidget->setObjectName(QStringLiteral("GoodsSearchForCreateWidget"));
        GoodsSearchForCreateWidget->resize(216, 493);
        verticalLayout = new QVBoxLayout(GoodsSearchForCreateWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(GoodsSearchForCreateWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 48));
        topWidget->setMaximumSize(QSize(16777215, 48));
        topWidget->setStyleSheet(QLatin1String("QWidget#topWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(topWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        searchEdit = new SearchEdit(topWidget);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));
        searchEdit->setStyleSheet(QStringLiteral("border: 1px solid #ea8852;"));

        horizontalLayout_2->addWidget(searchEdit);


        verticalLayout->addWidget(topWidget);

        listView = new GoodsForCreateListView(GoodsSearchForCreateWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(listView);

        pageUpDownWidget = new QWidget(GoodsSearchForCreateWidget);
        pageUpDownWidget->setObjectName(QStringLiteral("pageUpDownWidget"));
        pageUpDownWidget->setMinimumSize(QSize(0, 42));
        pageUpDownWidget->setMaximumSize(QSize(16777215, 42));
        pageUpDownWidget->setStyleSheet(QLatin1String("QWidget#pageUpDownWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout = new QHBoxLayout(pageUpDownWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(pageUpDownWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
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
        pageLabel->setMinimumSize(QSize(50, 0));
        pageLabel->setMaximumSize(QSize(50, 16777215));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));
        pageLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(pageLabel);


        verticalLayout->addWidget(pageUpDownWidget);


        retranslateUi(GoodsSearchForCreateWidget);

        QMetaObject::connectSlotsByName(GoodsSearchForCreateWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodsSearchForCreateWidget)
    {
        GoodsSearchForCreateWidget->setWindowTitle(QApplication::translate("GoodsSearchForCreateWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("GoodsSearchForCreateWidget", "1/1\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GoodsSearchForCreateWidget: public Ui_GoodsSearchForCreateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSSEARCHFORCREATEWIDGET_H
