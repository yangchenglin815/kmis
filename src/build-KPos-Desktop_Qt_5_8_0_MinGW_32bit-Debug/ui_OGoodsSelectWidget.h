/********************************************************************************
** Form generated from reading UI file 'OGoodsSelectWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OGOODSSELECTWIDGET_H
#define UI_OGOODSSELECTWIDGET_H

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
#include "../OutStock/OutStockGoodsSelectListView.h"
#include "../OutStock/OutStockGoodsSelectTitleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OGoodsSelectWidget
{
public:
    QVBoxLayout *verticalLayout;
    OutStockGoodsSelectTitleWidget *titleWidget;
    OutStockGoodsSelectListView *listView;
    QWidget *leftWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *lastPageButton;
    QPushButton *nextPageButton;
    QWidget *widget_6;
    QSpacerItem *horizontalSpacer;
    QLabel *pageLabel;
    QWidget *bottomWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *totalLabel;

    void setupUi(QWidget *OGoodsSelectWidget)
    {
        if (OGoodsSelectWidget->objectName().isEmpty())
            OGoodsSelectWidget->setObjectName(QStringLiteral("OGoodsSelectWidget"));
        OGoodsSelectWidget->resize(288, 470);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(250, 250, 250, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        OGoodsSelectWidget->setPalette(palette);
        verticalLayout = new QVBoxLayout(OGoodsSelectWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new OutStockGoodsSelectTitleWidget(OGoodsSelectWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 34));
        titleWidget->setMaximumSize(QSize(16777215, 34));

        verticalLayout->addWidget(titleWidget);

        listView = new OutStockGoodsSelectListView(OGoodsSelectWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("border:none;\n"
"background-color: rgb(250, 250, 250);"));
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(listView);

        leftWidget = new QWidget(OGoodsSelectWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(0, 41));
        leftWidget->setMaximumSize(QSize(16777215, 41));
        leftWidget->setStyleSheet(QLatin1String("QWidget#leftWidget{\n"
"        background-color:#fafafa;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(leftWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(14, 0, 14, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        widget_5 = new QWidget(leftWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        widget_5->setMinimumSize(QSize(170, 0));
        widget_5->setMaximumSize(QSize(170, 16777215));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        lastPageButton = new QPushButton(widget_5);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(87, 37));
        lastPageButton->setMaximumSize(QSize(87, 37));
        lastPageButton->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout_5->addWidget(lastPageButton);

        nextPageButton = new QPushButton(widget_5);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(87, 37));
        nextPageButton->setMaximumSize(QSize(87, 37));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_5->addWidget(nextPageButton);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(1, 18));
        widget_6->setMaximumSize(QSize(1, 18));
        widget_6->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout_5->addWidget(widget_6);


        horizontalLayout_4->addWidget(widget_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pageLabel = new QLabel(leftWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));

        horizontalLayout_4->addWidget(pageLabel);


        verticalLayout->addWidget(leftWidget);

        bottomWidget = new QWidget(OGoodsSelectWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 52));
        bottomWidget->setMaximumSize(QSize(16777215, 52));
        bottomWidget->setStyleSheet(QStringLiteral("background:#fafafa;"));
        horizontalLayoutWidget = new QWidget(bottomWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 291, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QPalette palette1;
        QBrush brush2(QColor(51, 51, 51, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label->setPalette(palette1);
        label->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
"color:#333333;\n"
"background:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:-6px;"));

        horizontalLayout_2->addWidget(label);

        totalLabel = new QLabel(horizontalLayoutWidget);
        totalLabel->setObjectName(QStringLiteral("totalLabel"));
        totalLabel->setStyleSheet(QString::fromUtf8("font-size:22px;\n"
"color:#ED9A6D;\n"
"background:#fafafa;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:-12px;"));

        horizontalLayout_2->addWidget(totalLabel);


        verticalLayout->addWidget(bottomWidget);


        retranslateUi(OGoodsSelectWidget);

        QMetaObject::connectSlotsByName(OGoodsSelectWidget);
    } // setupUi

    void retranslateUi(QWidget *OGoodsSelectWidget)
    {
        OGoodsSelectWidget->setWindowTitle(QApplication::translate("OGoodsSelectWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("OGoodsSelectWidget", "1/1\351\241\265", Q_NULLPTR));
        label->setText(QApplication::translate("OGoodsSelectWidget", "     \345\217\202\350\200\203\346\200\273\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        totalLabel->setText(QApplication::translate("OGoodsSelectWidget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OGoodsSelectWidget: public Ui_OGoodsSelectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OGOODSSELECTWIDGET_H
