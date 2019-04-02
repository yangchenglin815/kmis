/********************************************************************************
** Form generated from reading UI file 'SaleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEWIDGET_H
#define UI_SALEWIDGET_H

#include <CategoryWidget.h>
#include <OperateWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarLabel.h>
#include "GoodsRefundListWidget.h"
#include "GoodsSellListWidget.h"
#include "GoodsWidget.h"
#include "PlatformLabel.h"
#include "SearchEdit.h"

QT_BEGIN_NAMESPACE

class Ui_SaleWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    TitleBarLabel *titleLabel;
    QWidget *skinWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QWidget *saleInfoWidget;
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    SearchEdit *searchWidget;
    PlatformLabel *platFormLabel;
    QStackedWidget *sellStackedWidget;
    GoodsSellListWidget *goodsSellListWidget;
    GoodsRefundListWidget *goodsRefundListWidget;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_5;
    QWidget *consumInfoWidget;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QLabel *memberNumLabel;
    QLabel *lastChangeLabel;
    QLabel *memberNameLabel;
    QLabel *couponLabel;
    QLabel *lastDateLabel;
    QLabel *curDateLabel;
    QFrame *line;
    QWidget *sumPriceWidget;
    QHBoxLayout *horizontalLayout_9;
    QWidget *widget_3;
    QLabel *sumPriceValueLabel;
    QLabel *sumPriceLabel;
    QWidget *AllBtnWidget;
    QVBoxLayout *verticalLayout_3;
    CategoryWidget *categoryWidget;
    GoodsWidget *goodsWidget;
    QStackedWidget *operateStackedWidget;
    OperateWidget *operateWidget;
    QWidget *refundKeyPage;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *refund1Button;
    QPushButton *refund2Button;
    QPushButton *refund3Button;
    QPushButton *refund4Button;
    QPushButton *refund5Button;
    QWidget *PageWidget;
    QVBoxLayout *verticalLayout_8;
    QPushButton *categoryFrontButton;
    QPushButton *categoryNextButton;
    QPushButton *goodsFrontButton;
    QPushButton *goodsNextButton;
    QSpacerItem *verticalSpacer;
    QPushButton *statementButton;

    void setupUi(QDialog *SaleWidget)
    {
        if (SaleWidget->objectName().isEmpty())
            SaleWidget->setObjectName(QStringLiteral("SaleWidget"));
        SaleWidget->resize(800, 600);
        SaleWidget->setMinimumSize(QSize(800, 600));
        verticalLayout_2 = new QVBoxLayout(SaleWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleLabel = new TitleBarLabel(SaleWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setMinimumSize(QSize(800, 51));
        titleLabel->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(titleLabel);

        skinWidget = new QWidget(SaleWidget);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setMinimumSize(QSize(800, 549));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget\n"
"{\n"
"	background-color:#505050;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(skinWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(20, -1, 20, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        saleInfoWidget = new QWidget(skinWidget);
        saleInfoWidget->setObjectName(QStringLiteral("saleInfoWidget"));
        saleInfoWidget->setMinimumSize(QSize(290, 529));
        saleInfoWidget->setMaximumSize(QSize(590, 16777215));
        verticalLayout = new QVBoxLayout(saleInfoWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(saleInfoWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 44));
        topWidget->setMaximumSize(QSize(16777215, 73));
        topWidget->setStyleSheet(QLatin1String("QWidget#topWidget{\n"
"	background-color:#3e3d3d;\n"
"}"));
        horizontalLayout = new QHBoxLayout(topWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        searchWidget = new SearchEdit(topWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));

        horizontalLayout->addWidget(searchWidget);

        platFormLabel = new PlatformLabel(topWidget);
        platFormLabel->setObjectName(QStringLiteral("platFormLabel"));
        platFormLabel->setMinimumSize(QSize(81, 0));
        platFormLabel->setMaximumSize(QSize(112, 16777215));
        platFormLabel->setStyleSheet(QLatin1String("QLabel#platFormLabel {\n"
"	background-color:#74ac56;\n"
"}"));
        platFormLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(platFormLabel);

        horizontalLayout->setStretch(0, 192);
        horizontalLayout->setStretch(1, 81);

        verticalLayout->addWidget(topWidget);

        sellStackedWidget = new QStackedWidget(saleInfoWidget);
        sellStackedWidget->setObjectName(QStringLiteral("sellStackedWidget"));
        goodsSellListWidget = new GoodsSellListWidget();
        goodsSellListWidget->setObjectName(QStringLiteral("goodsSellListWidget"));
        sellStackedWidget->addWidget(goodsSellListWidget);
        goodsRefundListWidget = new GoodsRefundListWidget();
        goodsRefundListWidget->setObjectName(QStringLiteral("goodsRefundListWidget"));
        sellStackedWidget->addWidget(goodsRefundListWidget);

        verticalLayout->addWidget(sellStackedWidget);

        widget_9 = new QWidget(saleInfoWidget);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMinimumSize(QSize(0, 140));
        widget_9->setMaximumSize(QSize(16777215, 214));
        verticalLayout_5 = new QVBoxLayout(widget_9);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        consumInfoWidget = new QWidget(widget_9);
        consumInfoWidget->setObjectName(QStringLiteral("consumInfoWidget"));
        consumInfoWidget->setMinimumSize(QSize(0, 70));
        consumInfoWidget->setMaximumSize(QSize(16777215, 16777215));
        consumInfoWidget->setStyleSheet(QString::fromUtf8("QWidget#consumInfoWidget\n"
"{\n"
"	background-color:#ffffff;\n"
"}\n"
"\n"
"QLabel{\n"
"	font-size:12px;\n"
"	color:#999999;\n"
"    font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	background-color:#ffffff;\n"
"}\n"
"\n"
"QLabel#lastChangeLabel\n"
"{\n"
"	font-size:12px;\n"
"	color:#333333;\n"
"    font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(consumInfoWidget);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(consumInfoWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(288, 70));
        widget_2->setMaximumSize(QSize(288, 70));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        memberNumLabel = new QLabel(widget_2);
        memberNumLabel->setObjectName(QStringLiteral("memberNumLabel"));

        gridLayout_4->addWidget(memberNumLabel, 0, 0, 1, 1);

        lastChangeLabel = new QLabel(widget_2);
        lastChangeLabel->setObjectName(QStringLiteral("lastChangeLabel"));
        lastChangeLabel->setLayoutDirection(Qt::LeftToRight);
        lastChangeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(lastChangeLabel, 0, 1, 1, 1);

        memberNameLabel = new QLabel(widget_2);
        memberNameLabel->setObjectName(QStringLiteral("memberNameLabel"));

        gridLayout_4->addWidget(memberNameLabel, 1, 0, 1, 1);

        couponLabel = new QLabel(widget_2);
        couponLabel->setObjectName(QStringLiteral("couponLabel"));
        couponLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(couponLabel, 1, 1, 1, 1);

        lastDateLabel = new QLabel(widget_2);
        lastDateLabel->setObjectName(QStringLiteral("lastDateLabel"));

        gridLayout_4->addWidget(lastDateLabel, 2, 0, 1, 1);

        curDateLabel = new QLabel(widget_2);
        curDateLabel->setObjectName(QStringLiteral("curDateLabel"));
        curDateLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(curDateLabel, 2, 1, 1, 1);

        couponLabel->raise();
        lastDateLabel->raise();
        memberNameLabel->raise();
        curDateLabel->raise();
        lastChangeLabel->raise();
        memberNumLabel->raise();

        horizontalLayout_8->addWidget(widget_2);


        verticalLayout_5->addWidget(consumInfoWidget);

        line = new QFrame(widget_9);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(0, 1));
        line->setMaximumSize(QSize(16777215, 1));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        sumPriceWidget = new QWidget(widget_9);
        sumPriceWidget->setObjectName(QStringLiteral("sumPriceWidget"));
        sumPriceWidget->setMinimumSize(QSize(0, 0));
        sumPriceWidget->setMaximumSize(QSize(16777215, 16777215));
        sumPriceWidget->setStyleSheet(QStringLiteral("background-color:#ffffff;"));
        horizontalLayout_9 = new QHBoxLayout(sumPriceWidget);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(sumPriceWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(288, 69));
        widget_3->setMaximumSize(QSize(288, 69));
        widget_3->setStyleSheet(QLatin1String("QWidget#widget_3 {\n"
"	border-top: 1px solid  rgb(237, 237, 237);\n"
"}"));
        sumPriceValueLabel = new QLabel(widget_3);
        sumPriceValueLabel->setObjectName(QStringLiteral("sumPriceValueLabel"));
        sumPriceValueLabel->setGeometry(QRect(109, 20, 171, 32));
        QFont font;
        sumPriceValueLabel->setFont(font);
        sumPriceValueLabel->setStyleSheet(QLatin1String("font-size:34px;\n"
"color:#f38448;\n"
"background-color:#ffffff;"));
        sumPriceValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sumPriceLabel = new QLabel(widget_3);
        sumPriceLabel->setObjectName(QStringLiteral("sumPriceLabel"));
        sumPriceLabel->setGeometry(QRect(9, 20, 54, 31));
        sumPriceLabel->setStyleSheet(QLatin1String("font-size:16px;\n"
"color:#666666;\n"
"background-color:#ffffff;"));

        horizontalLayout_9->addWidget(widget_3);


        verticalLayout_5->addWidget(sumPriceWidget);


        verticalLayout->addWidget(widget_9);

        verticalLayout->setStretch(0, 44);
        verticalLayout->setStretch(1, 345);
        verticalLayout->setStretch(2, 140);

        horizontalLayout_2->addWidget(saleInfoWidget);

        AllBtnWidget = new QWidget(skinWidget);
        AllBtnWidget->setObjectName(QStringLiteral("AllBtnWidget"));
        verticalLayout_3 = new QVBoxLayout(AllBtnWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        categoryWidget = new CategoryWidget(AllBtnWidget);
        categoryWidget->setObjectName(QStringLiteral("categoryWidget"));
        categoryWidget->setMinimumSize(QSize(406, 111));
        categoryWidget->setMaximumSize(QSize(16777215, 155));

        verticalLayout_3->addWidget(categoryWidget);

        goodsWidget = new GoodsWidget(AllBtnWidget);
        goodsWidget->setObjectName(QStringLiteral("goodsWidget"));
        goodsWidget->setMinimumSize(QSize(406, 360));
        goodsWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(goodsWidget);

        operateStackedWidget = new QStackedWidget(AllBtnWidget);
        operateStackedWidget->setObjectName(QStringLiteral("operateStackedWidget"));
        operateStackedWidget->setMinimumSize(QSize(0, 60));
        operateStackedWidget->setMaximumSize(QSize(16777215, 93));
        operateWidget = new OperateWidget();
        operateWidget->setObjectName(QStringLiteral("operateWidget"));
        operateStackedWidget->addWidget(operateWidget);
        refundKeyPage = new QWidget();
        refundKeyPage->setObjectName(QStringLiteral("refundKeyPage"));
        horizontalLayout_3 = new QHBoxLayout(refundKeyPage);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 2, 0, 0);
        refund1Button = new QPushButton(refundKeyPage);
        refund1Button->setObjectName(QStringLiteral("refund1Button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(refund1Button->sizePolicy().hasHeightForWidth());
        refund1Button->setSizePolicy(sizePolicy);
        refund1Button->setMinimumSize(QSize(78, 0));
        refund1Button->setMaximumSize(QSize(16777215, 16777215));
        refund1Button->setFocusPolicy(Qt::NoFocus);
        refund1Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_3->addWidget(refund1Button);

        refund2Button = new QPushButton(refundKeyPage);
        refund2Button->setObjectName(QStringLiteral("refund2Button"));
        sizePolicy.setHeightForWidth(refund2Button->sizePolicy().hasHeightForWidth());
        refund2Button->setSizePolicy(sizePolicy);
        refund2Button->setMinimumSize(QSize(78, 0));
        refund2Button->setMaximumSize(QSize(16777215, 16777215));
        refund2Button->setFocusPolicy(Qt::NoFocus);
        refund2Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_3->addWidget(refund2Button);

        refund3Button = new QPushButton(refundKeyPage);
        refund3Button->setObjectName(QStringLiteral("refund3Button"));
        sizePolicy.setHeightForWidth(refund3Button->sizePolicy().hasHeightForWidth());
        refund3Button->setSizePolicy(sizePolicy);
        refund3Button->setMinimumSize(QSize(78, 0));
        refund3Button->setMaximumSize(QSize(16777215, 16777215));
        refund3Button->setFocusPolicy(Qt::NoFocus);
        refund3Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_3->addWidget(refund3Button);

        refund4Button = new QPushButton(refundKeyPage);
        refund4Button->setObjectName(QStringLiteral("refund4Button"));
        sizePolicy.setHeightForWidth(refund4Button->sizePolicy().hasHeightForWidth());
        refund4Button->setSizePolicy(sizePolicy);
        refund4Button->setMinimumSize(QSize(78, 0));
        refund4Button->setMaximumSize(QSize(16777215, 16777215));
        refund4Button->setFocusPolicy(Qt::NoFocus);
        refund4Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_3->addWidget(refund4Button);

        refund5Button = new QPushButton(refundKeyPage);
        refund5Button->setObjectName(QStringLiteral("refund5Button"));
        sizePolicy.setHeightForWidth(refund5Button->sizePolicy().hasHeightForWidth());
        refund5Button->setSizePolicy(sizePolicy);
        refund5Button->setMinimumSize(QSize(78, 0));
        refund5Button->setMaximumSize(QSize(16777215, 16777215));
        refund5Button->setFocusPolicy(Qt::NoFocus);
        refund5Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_3->addWidget(refund5Button);

        operateStackedWidget->addWidget(refundKeyPage);

        verticalLayout_3->addWidget(operateStackedWidget);

        verticalLayout_3->setStretch(0, 111);
        verticalLayout_3->setStretch(1, 360);
        verticalLayout_3->setStretch(2, 60);

        horizontalLayout_2->addWidget(AllBtnWidget);

        horizontalLayout_2->setStretch(0, 290);
        horizontalLayout_2->setStretch(1, 404);

        horizontalLayout_4->addLayout(horizontalLayout_2);

        PageWidget = new QWidget(skinWidget);
        PageWidget->setObjectName(QStringLiteral("PageWidget"));
        PageWidget->setMinimumSize(QSize(55, 529));
        PageWidget->setMaximumSize(QSize(135, 16777215));
        verticalLayout_8 = new QVBoxLayout(PageWidget);
        verticalLayout_8->setSpacing(4);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(4, 0, 0, 0);
        categoryFrontButton = new QPushButton(PageWidget);
        categoryFrontButton->setObjectName(QStringLiteral("categoryFrontButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(categoryFrontButton->sizePolicy().hasHeightForWidth());
        categoryFrontButton->setSizePolicy(sizePolicy1);
        categoryFrontButton->setMinimumSize(QSize(51, 51));
        categoryFrontButton->setMaximumSize(QSize(16777215, 71));
        categoryFrontButton->setFocusPolicy(Qt::NoFocus);
        categoryFrontButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/category_up.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	border-image: url(:/saleImage/category_up_press.png);\n"
"}"));

        verticalLayout_8->addWidget(categoryFrontButton);

        categoryNextButton = new QPushButton(PageWidget);
        categoryNextButton->setObjectName(QStringLiteral("categoryNextButton"));
        sizePolicy1.setHeightForWidth(categoryNextButton->sizePolicy().hasHeightForWidth());
        categoryNextButton->setSizePolicy(sizePolicy1);
        categoryNextButton->setMinimumSize(QSize(51, 51));
        categoryNextButton->setMaximumSize(QSize(16777215, 74));
        categoryNextButton->setFocusPolicy(Qt::NoFocus);
        categoryNextButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	font-size:12px;\n"
"	color:#ffffff;\n"
"	padding-top:20px;\n"
"	border-image: url(:/saleImage/category_down.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/category_down_press.png);\n"
"}"));

        verticalLayout_8->addWidget(categoryNextButton);

        goodsFrontButton = new QPushButton(PageWidget);
        goodsFrontButton->setObjectName(QStringLiteral("goodsFrontButton"));
        sizePolicy1.setHeightForWidth(goodsFrontButton->sizePolicy().hasHeightForWidth());
        goodsFrontButton->setSizePolicy(sizePolicy1);
        goodsFrontButton->setMinimumSize(QSize(51, 51));
        goodsFrontButton->setMaximumSize(QSize(16777215, 74));
        goodsFrontButton->setFocusPolicy(Qt::NoFocus);
        goodsFrontButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/goods_up.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/goods_up_press.png);\n"
"}"));

        verticalLayout_8->addWidget(goodsFrontButton);

        goodsNextButton = new QPushButton(PageWidget);
        goodsNextButton->setObjectName(QStringLiteral("goodsNextButton"));
        sizePolicy1.setHeightForWidth(goodsNextButton->sizePolicy().hasHeightForWidth());
        goodsNextButton->setSizePolicy(sizePolicy1);
        goodsNextButton->setMinimumSize(QSize(51, 51));
        goodsNextButton->setMaximumSize(QSize(16777215, 74));
        goodsNextButton->setFocusPolicy(Qt::NoFocus);
        goodsNextButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	font-size:12px;\n"
"	color:#ffffff;\n"
"	padding-top:20px;\n"
"	border-image: url(:/saleImage/goods_down.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/goods_down_press.png);\n"
"}"));

        verticalLayout_8->addWidget(goodsNextButton);

        verticalSpacer = new QSpacerItem(20, 173, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        statementButton = new QPushButton(PageWidget);
        statementButton->setObjectName(QStringLiteral("statementButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(statementButton->sizePolicy().hasHeightForWidth());
        statementButton->setSizePolicy(sizePolicy2);
        statementButton->setMinimumSize(QSize(52, 92));
        statementButton->setFocusPolicy(Qt::NoFocus);
        statementButton->setStyleSheet(QLatin1String("QPushButton#statementButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border:none;\n"
"	font-size:14px;\n"
"	border-image: url(:/saleImage/statement_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementButton:pressed {\n"
"	border-image: url(:/saleImage/statement_press.png);\n"
"}"));

        verticalLayout_8->addWidget(statementButton);

        verticalLayout_8->setStretch(0, 52);
        verticalLayout_8->setStretch(1, 52);
        verticalLayout_8->setStretch(2, 52);
        verticalLayout_8->setStretch(3, 52);
        verticalLayout_8->setStretch(4, 173);
        verticalLayout_8->setStretch(5, 92);

        horizontalLayout_4->addWidget(PageWidget);

        horizontalLayout_4->setStretch(0, 785);
        horizontalLayout_4->setStretch(1, 56);

        verticalLayout_2->addWidget(skinWidget);

        verticalLayout_2->setStretch(0, 51);
        verticalLayout_2->setStretch(1, 549);

        retranslateUi(SaleWidget);

        sellStackedWidget->setCurrentIndex(0);
        operateStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SaleWidget);
    } // setupUi

    void retranslateUi(QDialog *SaleWidget)
    {
        SaleWidget->setWindowTitle(QApplication::translate("SaleWidget", "SaleWidget", Q_NULLPTR));
        titleLabel->setText(QString());
        platFormLabel->setText(QString());
        memberNumLabel->setText(QApplication::translate("SaleWidget", "\344\274\232\345\221\230\350\264\246\345\217\267\357\274\23229189414", Q_NULLPTR));
        lastChangeLabel->setText(QApplication::translate("SaleWidget", "\344\270\212\347\254\224\346\211\276\351\233\266\357\274\232\357\277\24523.00", Q_NULLPTR));
        memberNameLabel->setText(QApplication::translate("SaleWidget", "\344\274\232\345\221\230\345\247\223\345\220\215\357\274\232\345\274\240XX\345\245\263\345\243\253", Q_NULLPTR));
        couponLabel->setText(QApplication::translate("SaleWidget", "\344\274\230\346\203\240\351\207\221\351\242\235\357\274\2325.20", Q_NULLPTR));
        lastDateLabel->setText(QApplication::translate("SaleWidget", "\344\270\212\346\254\241\350\264\255\347\211\251\346\227\266\351\227\264\357\274\2322016-06-21", Q_NULLPTR));
        curDateLabel->setText(QApplication::translate("SaleWidget", "\346\227\266\351\227\264\357\274\2322013-09-12", Q_NULLPTR));
        sumPriceValueLabel->setText(QApplication::translate("SaleWidget", "\357\277\24537.02", Q_NULLPTR));
        sumPriceLabel->setText(QApplication::translate("SaleWidget", "\345\220\210\350\256\241\357\274\232", Q_NULLPTR));
        refund1Button->setText(QString());
        refund2Button->setText(QString());
        refund3Button->setText(QApplication::translate("SaleWidget", "\351\200\200\350\264\247", Q_NULLPTR));
        refund4Button->setText(QApplication::translate("SaleWidget", "\346\225\264\345\215\225\351\200\200\350\264\247", Q_NULLPTR));
        refund5Button->setText(QApplication::translate("SaleWidget", "\344\277\256\346\224\271\346\225\260\351\207\217", Q_NULLPTR));
        categoryFrontButton->setText(QString());
        categoryNextButton->setText(QApplication::translate("SaleWidget", "1/12\351\241\265", Q_NULLPTR));
        goodsFrontButton->setText(QString());
        goodsNextButton->setText(QApplication::translate("SaleWidget", "1/12\351\241\265", Q_NULLPTR));
        statementButton->setText(QApplication::translate("SaleWidget", "\347\273\223\347\256\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SaleWidget: public Ui_SaleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEWIDGET_H
