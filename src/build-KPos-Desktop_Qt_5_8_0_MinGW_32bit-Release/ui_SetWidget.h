/********************************************************************************
** Form generated from reading UI file 'SetWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETWIDGET_H
#define UI_SETWIDGET_H

#include <DeviceSetPage.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GoodsSetPage.h"
#include "KeySetPage.h"
#include "ParamsSetPage.h"
#include "PayWaySetPage.h"
#include "PosInfoSetPage.h"
#include "ScreenSetPage.h"

QT_BEGIN_NAMESPACE

class Ui_SetWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *titleBarWidget;
    QLabel *logoLabel;
    QPushButton *backButton;
    QWidget *mainSkinWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *posInfoSetButton;
    QPushButton *keySetButton;
    QPushButton *goodsSetButton;
    QPushButton *deviceSetButton;
    QPushButton *screenSetButton;
    QPushButton *payWaySetButton;
    QPushButton *paramsSetButton;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    PosInfoSetPage *posInfoSetPage;
    KeySetPage *keySetPage;
    GoodsSetPage *goodSetPage;
    ScreenSetPage *screenSetPage;
    PayWaySetPage *payWaySetPage;
    ParamsSetPage *paramsSetPage;
    DeviceSetPage *deviceSetPage;

    void setupUi(QWidget *SetWidget)
    {
        if (SetWidget->objectName().isEmpty())
            SetWidget->setObjectName(QStringLiteral("SetWidget"));
        SetWidget->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(SetWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleBarWidget = new QWidget(SetWidget);
        titleBarWidget->setObjectName(QStringLiteral("titleBarWidget"));
        titleBarWidget->setMinimumSize(QSize(0, 50));
        titleBarWidget->setMaximumSize(QSize(16777215, 16777215));
        titleBarWidget->setStyleSheet(QLatin1String("QWidget#titleBarWidget {\n"
"	border-image: url(:/shareImages/dlg_titlebar.png);\n"
"}\n"
""));
        logoLabel = new QLabel(titleBarWidget);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        logoLabel->setGeometry(QRect(20, 15, 64, 19));
        logoLabel->setMinimumSize(QSize(0, 0));
        logoLabel->setMaximumSize(QSize(16777215, 16777215));
        logoLabel->setStyleSheet(QStringLiteral("border-image: url(:/saleImage/logo_sale.png);"));
        backButton = new QPushButton(titleBarWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(722, 5, 65, 39));
        backButton->setMinimumSize(QSize(0, 0));
        backButton->setMaximumSize(QSize(16777215, 16777215));
        backButton->setStyleSheet(QLatin1String("QPushButton#backButton {\n"
"	border-image: url(:/shareImages/btn_back_normal.png);\n"
"}\n"
"\n"
"QPushButton#backButton:press {\n"
"	border-image: url(:/shareImages/btn_back_press.png);\n"
"}"));

        verticalLayout_2->addWidget(titleBarWidget);

        mainSkinWidget = new QWidget(SetWidget);
        mainSkinWidget->setObjectName(QStringLiteral("mainSkinWidget"));
        mainSkinWidget->setStyleSheet(QLatin1String("QWidget#mainSkinWidget{\n"
"	background-color: rgb(81, 80, 80);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainSkinWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 16, 20, 20);
        widget_3 = new QWidget(mainSkinWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(75, 0));
        widget_3->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(7);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        posInfoSetButton = new QPushButton(widget_3);
        posInfoSetButton->setObjectName(QStringLiteral("posInfoSetButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(posInfoSetButton->sizePolicy().hasHeightForWidth());
        posInfoSetButton->setSizePolicy(sizePolicy);
        posInfoSetButton->setMinimumSize(QSize(148, 47));
        posInfoSetButton->setMaximumSize(QSize(250, 86));
        QFont font;
        posInfoSetButton->setFont(font);
        posInfoSetButton->setStyleSheet(QLatin1String("QPushButton{\n"
"font-size:15px; \n"
"color: #ffffff;\n"
"border-image: url(:/setImage/tab_button_normal.png);\n"
"}"));

        verticalLayout->addWidget(posInfoSetButton);

        keySetButton = new QPushButton(widget_3);
        keySetButton->setObjectName(QStringLiteral("keySetButton"));
        sizePolicy.setHeightForWidth(keySetButton->sizePolicy().hasHeightForWidth());
        keySetButton->setSizePolicy(sizePolicy);
        keySetButton->setMinimumSize(QSize(148, 47));
        keySetButton->setMaximumSize(QSize(250, 86));
        keySetButton->setFont(font);
        keySetButton->setStyleSheet(QLatin1String("QPushButton{\n"
"font-size:15px; \n"
"color: #ffffff;\n"
"border-image: url(:/setImage/tab_button_normal.png);\n"
"}"));

        verticalLayout->addWidget(keySetButton);

        goodsSetButton = new QPushButton(widget_3);
        goodsSetButton->setObjectName(QStringLiteral("goodsSetButton"));
        sizePolicy.setHeightForWidth(goodsSetButton->sizePolicy().hasHeightForWidth());
        goodsSetButton->setSizePolicy(sizePolicy);
        goodsSetButton->setMinimumSize(QSize(148, 47));
        goodsSetButton->setMaximumSize(QSize(250, 86));
        goodsSetButton->setFont(font);
        goodsSetButton->setStyleSheet(QLatin1String("QPushButton{\n"
"font-size:15px; \n"
"color: #ffffff;\n"
"border-image: url(:/setImage/tab_button_normal.png);\n"
"}"));

        verticalLayout->addWidget(goodsSetButton);

        deviceSetButton = new QPushButton(widget_3);
        deviceSetButton->setObjectName(QStringLiteral("deviceSetButton"));
        sizePolicy.setHeightForWidth(deviceSetButton->sizePolicy().hasHeightForWidth());
        deviceSetButton->setSizePolicy(sizePolicy);
        deviceSetButton->setMinimumSize(QSize(148, 47));
        deviceSetButton->setMaximumSize(QSize(250, 86));
        deviceSetButton->setFont(font);
        deviceSetButton->setStyleSheet(QLatin1String("QPushButton{\n"
"font-size:15px; \n"
"color: #ffffff;\n"
"border-image: url(:/setImage/tab_button_normal.png);\n"
"}"));

        verticalLayout->addWidget(deviceSetButton);

        screenSetButton = new QPushButton(widget_3);
        screenSetButton->setObjectName(QStringLiteral("screenSetButton"));
        sizePolicy.setHeightForWidth(screenSetButton->sizePolicy().hasHeightForWidth());
        screenSetButton->setSizePolicy(sizePolicy);
        screenSetButton->setMinimumSize(QSize(148, 47));
        screenSetButton->setMaximumSize(QSize(250, 86));
        screenSetButton->setFont(font);
        screenSetButton->setStyleSheet(QLatin1String("QPushButton{\n"
"font-size:15px; \n"
"color: #ffffff;\n"
"border-image: url(:/setImage/tab_button_normal.png);\n"
"}"));

        verticalLayout->addWidget(screenSetButton);

        payWaySetButton = new QPushButton(widget_3);
        payWaySetButton->setObjectName(QStringLiteral("payWaySetButton"));
        sizePolicy.setHeightForWidth(payWaySetButton->sizePolicy().hasHeightForWidth());
        payWaySetButton->setSizePolicy(sizePolicy);
        payWaySetButton->setMinimumSize(QSize(148, 47));
        payWaySetButton->setMaximumSize(QSize(250, 86));
        payWaySetButton->setFont(font);
        payWaySetButton->setStyleSheet(QLatin1String("QPushButton{\n"
"font-size:15px; \n"
"color: #ffffff;\n"
"border-image: url(:/setImage/tab_button_normal.png);\n"
"}"));

        verticalLayout->addWidget(payWaySetButton);

        paramsSetButton = new QPushButton(widget_3);
        paramsSetButton->setObjectName(QStringLiteral("paramsSetButton"));
        sizePolicy.setHeightForWidth(paramsSetButton->sizePolicy().hasHeightForWidth());
        paramsSetButton->setSizePolicy(sizePolicy);
        paramsSetButton->setMinimumSize(QSize(148, 47));
        paramsSetButton->setMaximumSize(QSize(250, 86));
        paramsSetButton->setFont(font);
        paramsSetButton->setStyleSheet(QLatin1String("QPushButton{\n"
"font-size:15px; \n"
"color: #ffffff;\n"
"border-image: url(:/setImage/tab_button_normal.png);\n"
"}"));

        verticalLayout->addWidget(paramsSetButton);

        verticalSpacer = new QSpacerItem(20, 199, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget_3);

        stackedWidget = new QStackedWidget(mainSkinWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(607, 0));
        stackedWidget->setMaximumSize(QSize(1677, 16777215));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        posInfoSetPage = new PosInfoSetPage();
        posInfoSetPage->setObjectName(QStringLiteral("posInfoSetPage"));
        posInfoSetPage->setStyleSheet(QStringLiteral(""));
        stackedWidget->addWidget(posInfoSetPage);
        keySetPage = new KeySetPage();
        keySetPage->setObjectName(QStringLiteral("keySetPage"));
        keySetPage->setStyleSheet(QStringLiteral(""));
        stackedWidget->addWidget(keySetPage);
        goodSetPage = new GoodsSetPage();
        goodSetPage->setObjectName(QStringLiteral("goodSetPage"));
        goodSetPage->setStyleSheet(QLatin1String("QWidget#goodSetPage{\n"
"	background-color:#ffffff;\n"
"}"));
        stackedWidget->addWidget(goodSetPage);
        screenSetPage = new ScreenSetPage();
        screenSetPage->setObjectName(QStringLiteral("screenSetPage"));
        screenSetPage->setStyleSheet(QLatin1String("QWidget#screenSetPage{\n"
"	background-color:#ffffff;\n"
"}"));
        stackedWidget->addWidget(screenSetPage);
        payWaySetPage = new PayWaySetPage();
        payWaySetPage->setObjectName(QStringLiteral("payWaySetPage"));
        payWaySetPage->setStyleSheet(QLatin1String("QWidget#payWaySetPage{\n"
"	background-color:#ffffff;\n"
"}"));
        stackedWidget->addWidget(payWaySetPage);
        paramsSetPage = new ParamsSetPage();
        paramsSetPage->setObjectName(QStringLiteral("paramsSetPage"));
        stackedWidget->addWidget(paramsSetPage);
        deviceSetPage = new DeviceSetPage();
        deviceSetPage->setObjectName(QStringLiteral("deviceSetPage"));
        stackedWidget->addWidget(deviceSetPage);

        horizontalLayout->addWidget(stackedWidget);

        horizontalLayout->setStretch(0, 153);
        horizontalLayout->setStretch(1, 607);

        verticalLayout_2->addWidget(mainSkinWidget);

        verticalLayout_2->setStretch(0, 50);
        verticalLayout_2->setStretch(1, 550);

        retranslateUi(SetWidget);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(SetWidget);
    } // setupUi

    void retranslateUi(QWidget *SetWidget)
    {
        SetWidget->setWindowTitle(QApplication::translate("SetWidget", "SetWidget", Q_NULLPTR));
        logoLabel->setText(QString());
        backButton->setText(QString());
        posInfoSetButton->setText(QApplication::translate("SetWidget", "\345\237\272\347\241\200\344\277\241\346\201\257", Q_NULLPTR));
        keySetButton->setText(QApplication::translate("SetWidget", "\346\214\211\351\224\256\350\256\276\347\275\256", Q_NULLPTR));
        goodsSetButton->setText(QApplication::translate("SetWidget", "\345\225\206\345\223\201\350\256\276\347\275\256", Q_NULLPTR));
        deviceSetButton->setText(QApplication::translate("SetWidget", "\350\256\276\345\244\207\350\256\276\347\275\256", Q_NULLPTR));
        screenSetButton->setText(QApplication::translate("SetWidget", "\345\244\226\346\230\276\345\271\277\345\221\212", Q_NULLPTR));
        payWaySetButton->setText(QApplication::translate("SetWidget", "\346\224\257\344\273\230\350\256\276\347\275\256", Q_NULLPTR));
        paramsSetButton->setText(QApplication::translate("SetWidget", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetWidget: public Ui_SetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETWIDGET_H
