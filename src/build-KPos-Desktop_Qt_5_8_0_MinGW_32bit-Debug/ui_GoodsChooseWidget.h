/********************************************************************************
** Form generated from reading UI file 'GoodsChooseWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSCHOOSEWIDGET_H
#define UI_GOODSCHOOSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "GoodsChooseListView.h"
#include "KPosArrowButton.h"

QT_BEGIN_NAMESPACE

class Ui_GoodsChooseWidget
{
public:
    QPushButton *confirmButton;
    QLabel *goodsLabel;
    QLabel *selectAddLabel;
    QLabel *goodsContentLabel;
    QLabel *selectAddContentLabel;
    KPosUpArrowButton *upArrowButton;
    KPosDownArrowButton *downArrowButton;
    QWidget *widget_30;
    GoodsChooseListView *listView;

    void setupUi(QWidget *GoodsChooseWidget)
    {
        if (GoodsChooseWidget->objectName().isEmpty())
            GoodsChooseWidget->setObjectName(QStringLiteral("GoodsChooseWidget"));
        GoodsChooseWidget->resize(462, 320);
        GoodsChooseWidget->setStyleSheet(QStringLiteral(""));
        confirmButton = new QPushButton(GoodsChooseWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(3, 290, 85, 30));
        confirmButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/kPosSetImage/goodsChoose/confirmSave.png);\n"
"color:#ffffff;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/kPosSetImage/goodsChoose/confirmSavePress.png);\n"
"}"));
        goodsLabel = new QLabel(GoodsChooseWidget);
        goodsLabel->setObjectName(QStringLiteral("goodsLabel"));
        goodsLabel->setGeometry(QRect(113, 300, 13, 13));
        goodsLabel->setStyleSheet(QStringLiteral("background-color:#5181cd;"));
        selectAddLabel = new QLabel(GoodsChooseWidget);
        selectAddLabel->setObjectName(QStringLiteral("selectAddLabel"));
        selectAddLabel->setGeometry(QRect(173, 300, 13, 13));
        selectAddLabel->setStyleSheet(QStringLiteral("background-color:#d3865c;"));
        goodsContentLabel = new QLabel(GoodsChooseWidget);
        goodsContentLabel->setObjectName(QStringLiteral("goodsContentLabel"));
        goodsContentLabel->setGeometry(QRect(133, 300, 24, 12));
        selectAddContentLabel = new QLabel(GoodsChooseWidget);
        selectAddContentLabel->setObjectName(QStringLiteral("selectAddContentLabel"));
        selectAddContentLabel->setGeometry(QRect(193, 300, 72, 12));
        upArrowButton = new KPosUpArrowButton(GoodsChooseWidget);
        upArrowButton->setObjectName(QStringLiteral("upArrowButton"));
        upArrowButton->setGeometry(QRect(273, 283, 71, 31));
        downArrowButton = new KPosDownArrowButton(GoodsChooseWidget);
        downArrowButton->setObjectName(QStringLiteral("downArrowButton"));
        downArrowButton->setGeometry(QRect(360, 283, 101, 31));
        widget_30 = new QWidget(GoodsChooseWidget);
        widget_30->setObjectName(QStringLiteral("widget_30"));
        widget_30->setGeometry(QRect(351, 289, 1, 18));
        widget_30->setMinimumSize(QSize(1, 18));
        widget_30->setMaximumSize(QSize(1, 18));
        widget_30->setStyleSheet(QStringLiteral("border: 1px solid #6c6c6c;"));
        listView = new GoodsChooseListView(GoodsChooseWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 0, 450, 283));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"	background-color: rgb(81, 80, 80);\n"
"}"));

        retranslateUi(GoodsChooseWidget);

        QMetaObject::connectSlotsByName(GoodsChooseWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodsChooseWidget)
    {
        GoodsChooseWidget->setWindowTitle(QApplication::translate("GoodsChooseWidget", "Form", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("GoodsChooseWidget", "\344\277\235\345\255\230", Q_NULLPTR));
        goodsLabel->setText(QString());
        selectAddLabel->setText(QString());
        goodsContentLabel->setText(QApplication::translate("GoodsChooseWidget", "\345\225\206\345\223\201", Q_NULLPTR));
        selectAddContentLabel->setText(QApplication::translate("GoodsChooseWidget", "\351\200\211\346\213\251\346\267\273\345\212\240\345\225\206\345\223\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GoodsChooseWidget: public Ui_GoodsChooseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSCHOOSEWIDGET_H
