/********************************************************************************
** Form generated from reading UI file 'HomePageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGEWIDGET_H
#define UI_HOMEPAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePageWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *minimizeButton;
    QPushButton *closeButton;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *saleButton;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *adjustPriceButton;
    QPushButton *saleDetialButton;
    QVBoxLayout *verticalLayout;
    QPushButton *accountManageButton;
    QPushButton *modifyPasswdButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *reportButton;
    QPushButton *orderGoodsButton;
    QPushButton *stockingButton;
    QPushButton *reportLossButton;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *inStockButton;
    QPushButton *outStockButton;
    QPushButton *goodsManageButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *barCodeScaleButton;
    QPushButton *setButton;

    void setupUi(QWidget *HomePageWidget)
    {
        if (HomePageWidget->objectName().isEmpty())
            HomePageWidget->setObjectName(QStringLiteral("HomePageWidget"));
        HomePageWidget->resize(800, 600);
        HomePageWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(HomePageWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(HomePageWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 48));
        titleWidget->setMaximumSize(QSize(16777215, 48));
        titleWidget->setStyleSheet(QLatin1String("QWidget#titleWidget{\n"
"	background-color: rgb(81, 80, 80);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(titleWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(1101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        minimizeButton = new QPushButton(titleWidget);
        minimizeButton->setObjectName(QStringLiteral("minimizeButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minimizeButton->sizePolicy().hasHeightForWidth());
        minimizeButton->setSizePolicy(sizePolicy);
        minimizeButton->setMinimumSize(QSize(34, 34));
        minimizeButton->setMaximumSize(QSize(42, 42));
        minimizeButton->setFocusPolicy(Qt::NoFocus);
        minimizeButton->setStyleSheet(QLatin1String("QPushButton#minimizeButton {\n"
"	border-image: url(:/shareImages/minimize.png);\n"
"}\n"
"\n"
"QPushButton#minimizeButton:pressed {\n"
"	border-image: url(:/shareImages/minimize_press.png);\n"
"}\n"
""));

        horizontalLayout_3->addWidget(minimizeButton);

        closeButton = new QPushButton(titleWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(67, 34));
        closeButton->setMaximumSize(QSize(42, 42));
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton#closeButton {\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border-radius:8px;\n"
"	background:qlineargradient(spread:pad, x1:0.54, y1:1, x2:0.506, y2:0, stop:0 rgba(28, 28, 28, 255), stop:1 rgba(84, 84, 84, 255));\n"
"	color:rgb(255, 255, 255);\n"
"	border:1px solid black;\n"
"}\n"
"\n"
"QPushButton#closeButton:pressed {\n"
"	background:qlineargradient(spread:pad, x1:0.54, y1:1, 	x2:0.506, y2:0, stop:0 rgba(84, 84, 84,  255), stop:1 rgba(28, 28, 28,255));\n"
"}\n"
"\n"
""));

        horizontalLayout_3->addWidget(closeButton);


        verticalLayout_4->addWidget(titleWidget);

        mainWidget = new QWidget(HomePageWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"	background-color: rgb(81, 80, 80);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(mainWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        saleButton = new QPushButton(mainWidget);
        saleButton->setObjectName(QStringLiteral("saleButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(saleButton->sizePolicy().hasHeightForWidth());
        saleButton->setSizePolicy(sizePolicy1);
        saleButton->setMinimumSize(QSize(0, 0));
        saleButton->setMaximumSize(QSize(16777215, 16777215));
        saleButton->setFocusPolicy(Qt::NoFocus);
        saleButton->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border-image: url(:/homeWidgetImage/sale.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(:/homeWidgetImage/sale_press.png);\n"
"}"));

        horizontalLayout_7->addWidget(saleButton);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        adjustPriceButton = new QPushButton(mainWidget);
        adjustPriceButton->setObjectName(QStringLiteral("adjustPriceButton"));
        sizePolicy1.setHeightForWidth(adjustPriceButton->sizePolicy().hasHeightForWidth());
        adjustPriceButton->setSizePolicy(sizePolicy1);
        adjustPriceButton->setMinimumSize(QSize(0, 0));
        adjustPriceButton->setMaximumSize(QSize(16777215, 16777215));
        adjustPriceButton->setFocusPolicy(Qt::NoFocus);
        adjustPriceButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	border-image: url(:/homeWidgetImage/adjustPrice.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(:/homeWidgetImage/adjust_press.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/adjust_disable.png);\n"
"}"));

        verticalLayout_2->addWidget(adjustPriceButton);

        saleDetialButton = new QPushButton(mainWidget);
        saleDetialButton->setObjectName(QStringLiteral("saleDetialButton"));
        saleDetialButton->setMinimumSize(QSize(0, 115));
        saleDetialButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	border-image: url(:/homeWidgetImage/xsmx_h.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(:/homeWidgetImage/xsmx_p.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/xsmx_n.png);\n"
"}"));

        verticalLayout_2->addWidget(saleDetialButton);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        accountManageButton = new QPushButton(mainWidget);
        accountManageButton->setObjectName(QStringLiteral("accountManageButton"));
        sizePolicy1.setHeightForWidth(accountManageButton->sizePolicy().hasHeightForWidth());
        accountManageButton->setSizePolicy(sizePolicy1);
        accountManageButton->setFocusPolicy(Qt::NoFocus);
        accountManageButton->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border-image: url(:/homeWidgetImage/accountManage.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(:/homeWidgetImage/accountManage_press.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/accountManage_disable.png);\n"
"}"));

        verticalLayout->addWidget(accountManageButton);

        modifyPasswdButton = new QPushButton(mainWidget);
        modifyPasswdButton->setObjectName(QStringLiteral("modifyPasswdButton"));
        sizePolicy1.setHeightForWidth(modifyPasswdButton->sizePolicy().hasHeightForWidth());
        modifyPasswdButton->setSizePolicy(sizePolicy1);
        modifyPasswdButton->setFocusPolicy(Qt::NoFocus);
        modifyPasswdButton->setStyleSheet(QLatin1String("QPushButton {			\n"
"	border-image: url(:/homeWidgetImage/modifyPassword.png);\n"
"}\n"
"\n"
"QPushButton:pressed {	\n"
"	border-image: url(:/homeWidgetImage/modifyPassword_press.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/modifyPassword_disable.png);\n"
"}"));

        verticalLayout->addWidget(modifyPasswdButton);


        horizontalLayout_4->addLayout(verticalLayout);


        horizontalLayout_7->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        reportButton = new QPushButton(mainWidget);
        reportButton->setObjectName(QStringLiteral("reportButton"));
        sizePolicy1.setHeightForWidth(reportButton->sizePolicy().hasHeightForWidth());
        reportButton->setSizePolicy(sizePolicy1);
        reportButton->setMinimumSize(QSize(0, 0));
        reportButton->setMaximumSize(QSize(16777215, 16777215));
        reportButton->setFocusPolicy(Qt::NoFocus);
        reportButton->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border-image: url(:/homeWidgetImage/reportForms.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(:/homeWidgetImage/reportForms_press.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/reportForms_disable.png);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(reportButton);

        orderGoodsButton = new QPushButton(mainWidget);
        orderGoodsButton->setObjectName(QStringLiteral("orderGoodsButton"));
        sizePolicy1.setHeightForWidth(orderGoodsButton->sizePolicy().hasHeightForWidth());
        orderGoodsButton->setSizePolicy(sizePolicy1);
        orderGoodsButton->setFocusPolicy(Qt::NoFocus);
        orderGoodsButton->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border-image: url(:/homeWidgetImage/orderGoods.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(:/homeWidgetImage/orderGoods_press.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/orderGoods_disable.png);\n"
"}"));

        horizontalLayout_2->addWidget(orderGoodsButton);

        stockingButton = new QPushButton(mainWidget);
        stockingButton->setObjectName(QStringLiteral("stockingButton"));
        sizePolicy1.setHeightForWidth(stockingButton->sizePolicy().hasHeightForWidth());
        stockingButton->setSizePolicy(sizePolicy1);
        stockingButton->setFocusPolicy(Qt::NoFocus);
        stockingButton->setStyleSheet(QLatin1String("QPushButton {			\n"
"	border-image: url(:/homeWidgetImage/stocking.png);\n"
"}\n"
"\n"
"QPushButton:pressed {	\n"
"	border-image: url(:/homeWidgetImage/stocking_press.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/stocking_disable.png);\n"
"}"));

        horizontalLayout_2->addWidget(stockingButton);

        reportLossButton = new QPushButton(mainWidget);
        reportLossButton->setObjectName(QStringLiteral("reportLossButton"));
        reportLossButton->setMinimumSize(QSize(0, 139));
        reportLossButton->setStyleSheet(QLatin1String("QPushButton {			\n"
"	border-image: url(:/homeWidgetImage/bs_h.png);\n"
"}\n"
"\n"
"QPushButton:pressed {	\n"
"	border-image: url(:/homeWidgetImage/bs_p.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/bs_n.png);\n"
"}"));

        horizontalLayout_2->addWidget(reportLossButton);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        inStockButton = new QPushButton(mainWidget);
        inStockButton->setObjectName(QStringLiteral("inStockButton"));
        sizePolicy1.setHeightForWidth(inStockButton->sizePolicy().hasHeightForWidth());
        inStockButton->setSizePolicy(sizePolicy1);
        inStockButton->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border-image: url(:/homeWidgetImage/rk-h.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(:/homeWidgetImage/rk-p.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/rk-n.png);\n"
"}"));

        horizontalLayout_5->addWidget(inStockButton);

        outStockButton = new QPushButton(mainWidget);
        outStockButton->setObjectName(QStringLiteral("outStockButton"));
        sizePolicy1.setHeightForWidth(outStockButton->sizePolicy().hasHeightForWidth());
        outStockButton->setSizePolicy(sizePolicy1);
        outStockButton->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border-image: url(:/homeWidgetImage/ck-h.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(:/homeWidgetImage/ck-p.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/ck-n.png);\n"
"}"));

        horizontalLayout_5->addWidget(outStockButton);

        goodsManageButton = new QPushButton(mainWidget);
        goodsManageButton->setObjectName(QStringLiteral("goodsManageButton"));
        goodsManageButton->setMinimumSize(QSize(0, 136));
        goodsManageButton->setStyleSheet(QLatin1String("QPushButton {			\n"
"	border-image: url(:/homeWidgetImage/spgl_h.png);\n"
"}\n"
"\n"
"QPushButton:pressed {	\n"
"	border-image: url(:/homeWidgetImage/spgl_p.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/spgl_n.png);\n"
"}"));

        horizontalLayout_5->addWidget(goodsManageButton);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        barCodeScaleButton = new QPushButton(mainWidget);
        barCodeScaleButton->setObjectName(QStringLiteral("barCodeScaleButton"));
        sizePolicy1.setHeightForWidth(barCodeScaleButton->sizePolicy().hasHeightForWidth());
        barCodeScaleButton->setSizePolicy(sizePolicy1);
        barCodeScaleButton->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border-image: url(:/homeWidgetImage/tmcgl_h.png);\n"
"}\n"
"\n"
"QPushButton:pressed {	\n"
"	border-image: url(:/homeWidgetImage/tmcgl_p.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/tmcgl_n.png);\n"
"}"));

        horizontalLayout->addWidget(barCodeScaleButton);

        setButton = new QPushButton(mainWidget);
        setButton->setObjectName(QStringLiteral("setButton"));
        sizePolicy1.setHeightForWidth(setButton->sizePolicy().hasHeightForWidth());
        setButton->setSizePolicy(sizePolicy1);
        setButton->setFocusPolicy(Qt::NoFocus);
        setButton->setStyleSheet(QLatin1String("QPushButton {		\n"
"	border-image: url(:/homeWidgetImage/set.png);\n"
"}\n"
"\n"
"QPushButton:pressed {	\n"
"	border-image: url(:/homeWidgetImage/set_press.png);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	border-image: url(:/homeWidgetImage/set_disable.png);\n"
"}"));

        horizontalLayout->addWidget(setButton);


        horizontalLayout_6->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalLayout_3->setStretch(0, 244);
        verticalLayout_3->setStretch(1, 142);
        verticalLayout_3->setStretch(2, 142);

        verticalLayout_4->addWidget(mainWidget);


        retranslateUi(HomePageWidget);

        QMetaObject::connectSlotsByName(HomePageWidget);
    } // setupUi

    void retranslateUi(QWidget *HomePageWidget)
    {
        HomePageWidget->setWindowTitle(QApplication::translate("HomePageWidget", "HomePageWidget", Q_NULLPTR));
        minimizeButton->setText(QString());
        closeButton->setText(QApplication::translate("HomePageWidget", "\346\263\250\351\224\200", Q_NULLPTR));
        saleButton->setText(QString());
        adjustPriceButton->setText(QString());
        saleDetialButton->setText(QString());
        accountManageButton->setText(QString());
        modifyPasswdButton->setText(QString());
        reportButton->setText(QString());
        orderGoodsButton->setText(QString());
        stockingButton->setText(QString());
        reportLossButton->setText(QString());
        inStockButton->setText(QString());
        outStockButton->setText(QString());
        goodsManageButton->setText(QString());
        barCodeScaleButton->setText(QString());
        setButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomePageWidget: public Ui_HomePageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGEWIDGET_H
