/********************************************************************************
** Form generated from reading UI file 'BCSWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSWIDGET_H
#define UI_BCSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCSGroupManageWidget.h"
#include "BCSManageWidget.h"
#include "TitleWithReturnWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCSWidget
{
public:
    QVBoxLayout *verticalLayout;
    TitleWithReturnWidget *titleWidget;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QPushButton *bcsManageButton;
    QPushButton *bcsGoodsGroupButton;
    QPushButton *bcsSendDownButton;
    QStackedWidget *stackedWidget;
    BCSManageWidget *bcsManagePage;
    BCSGroupManageWidget *bcsGroupManagePage;

    void setupUi(QWidget *BCSWidget)
    {
        if (BCSWidget->objectName().isEmpty())
            BCSWidget->setObjectName(QStringLiteral("BCSWidget"));
        BCSWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(BCSWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleWithReturnWidget(BCSWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 50));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(BCSWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(mainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 0, 20, 10);
        widget = new QWidget(mainWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 60));
        bcsManageButton = new QPushButton(widget);
        bcsManageButton->setObjectName(QStringLiteral("bcsManageButton"));
        bcsManageButton->setGeometry(QRect(-1, 24, 100, 38));
        bcsManageButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 14px;\n"
"	color: #333333;\n"
"	background: #FFFFFF;\n"
"\n"
"	border: 1px solid #363636;\n"
"	border-bottom:0px solid #363636;\n"
"	border-top-left-radius:8px;\n"
"	border-top-right-radius:8px;\n"
"	border-bottom-right-radius:0px;\n"
"	border-bottom-left-radius:0px;\n"
"}\n"
""));
        bcsGoodsGroupButton = new QPushButton(widget);
        bcsGoodsGroupButton->setObjectName(QStringLiteral("bcsGoodsGroupButton"));
        bcsGoodsGroupButton->setGeometry(QRect(103, 24, 100, 38));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        bcsGoodsGroupButton->setFont(font);
        bcsGoodsGroupButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 14px;\n"
"	color: #FFFFFF;\n"
"	background-color:qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 #5D5D5D, stop:1 #595959);\n"
"	border: 1px solid #363636;\n"
"	border-bottom:0px solid #363636;\n"
"	border-top-left-radius:8px;\n"
"	border-top-right-radius:8px;\n"
"	border-bottom-right-radius:0px;\n"
"	border-bottom-left-radius:0px;\n"
"}"));
        bcsSendDownButton = new QPushButton(widget);
        bcsSendDownButton->setObjectName(QStringLiteral("bcsSendDownButton"));
        bcsSendDownButton->setGeometry(QRect(635, 14, 125, 32));
        bcsSendDownButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 14px;\n"
"	color: #FFFFFF;\n"
"	background-color:qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 #E89161, stop:1 #CD7646);\n"
"	border: 1px solid #363636;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color:qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 #CD7646, stop:1 #E89161);\n"
"}\n"
"\n"
""));

        verticalLayout_2->addWidget(widget);

        stackedWidget = new QStackedWidget(mainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        bcsManagePage = new BCSManageWidget();
        bcsManagePage->setObjectName(QStringLiteral("bcsManagePage"));
        stackedWidget->addWidget(bcsManagePage);
        bcsGroupManagePage = new BCSGroupManageWidget();
        bcsGroupManagePage->setObjectName(QStringLiteral("bcsGroupManagePage"));
        stackedWidget->addWidget(bcsGroupManagePage);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(mainWidget);

        verticalLayout->setStretch(0, 50);
        verticalLayout->setStretch(1, 550);

        retranslateUi(BCSWidget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BCSWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSWidget)
    {
        BCSWidget->setWindowTitle(QApplication::translate("BCSWidget", "Form", Q_NULLPTR));
        bcsManageButton->setText(QApplication::translate("BCSWidget", "\346\235\241\347\240\201\347\247\244\347\256\241\347\220\206", Q_NULLPTR));
        bcsGoodsGroupButton->setText(QApplication::translate("BCSWidget", "\345\225\206\345\223\201\347\273\204\347\256\241\347\220\206", Q_NULLPTR));
        bcsSendDownButton->setText(QApplication::translate("BCSWidget", "\344\270\213\345\217\221\346\235\241\347\240\201\347\247\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSWidget: public Ui_BCSWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSWIDGET_H
