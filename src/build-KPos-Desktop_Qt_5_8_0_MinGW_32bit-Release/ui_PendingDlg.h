/********************************************************************************
** Form generated from reading UI file 'PendingDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENDINGDLG_H
#define UI_PENDINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>
#include "GoodsSellListWidget.h"
#include "PendingListWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PendingDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *mainBackgroundWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_6;
    QLabel *label_2;
    QPushButton *clearButton;
    PendingListWidget *pendingListWidget;
    QWidget *widget_5;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *arrowLabel;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    GoodsSellListWidget *goodsSellListWidget;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PendingDlg)
    {
        if (PendingDlg->objectName().isEmpty())
            PendingDlg->setObjectName(QStringLiteral("PendingDlg"));
        PendingDlg->resize(661, 464);
        PendingDlg->setMinimumSize(QSize(661, 464));
        verticalLayout = new QVBoxLayout(PendingDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(PendingDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 40));
        titleWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(titleWidget);

        mainBackgroundWidget = new QWidget(PendingDlg);
        mainBackgroundWidget->setObjectName(QStringLiteral("mainBackgroundWidget"));
        mainBackgroundWidget->setStyleSheet(QLatin1String("QWidget#mainBackgroundWidget{\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainBackgroundWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_3 = new QWidget(mainBackgroundWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(291, 383));
        widget_3->setMaximumSize(QSize(291, 383));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(191, 37));
        widget_6->setMaximumSize(QSize(291, 37));
        widget_6->setStyleSheet(QLatin1String("background-color:#e5e4e4;\n"
""));
        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 291, 37));
        label_2->setMinimumSize(QSize(0, 37));
        label_2->setMaximumSize(QSize(16777215, 37));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size:14px;\n"
"	color:#333333;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
""));
        label_2->setAlignment(Qt::AlignCenter);
        clearButton = new QPushButton(widget_6);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(200, 3, 90, 40));
        clearButton->setMinimumSize(QSize(90, 40));
        clearButton->setMaximumSize(QSize(90, 40));
        clearButton->setFocusPolicy(Qt::NoFocus);
        clearButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:#ffffff;\n"
"	font-size: 14px;\n"
"    font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	padding-top:-10px;\n"
"	padding-left:-6px;\n"
"	border:none;\n"
"	background-image: url(:/pendingImage/deleteAllOrder.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	background-image: url(:/pendingImage/deleteAllOrder_pressed.png);\n"
"}\n"
"\n"
""));

        verticalLayout_2->addWidget(widget_6);

        pendingListWidget = new PendingListWidget(widget_3);
        pendingListWidget->setObjectName(QStringLiteral("pendingListWidget"));

        verticalLayout_2->addWidget(pendingListWidget);


        horizontalLayout->addWidget(widget_3);

        widget_5 = new QWidget(mainBackgroundWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(50, 476));
        widget_5->setMaximumSize(QSize(50, 476));
        gridLayout = new QGridLayout(widget_5);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        arrowLabel = new QLabel(widget_5);
        arrowLabel->setObjectName(QStringLiteral("arrowLabel"));
        arrowLabel->setMinimumSize(QSize(25, 25));
        arrowLabel->setMaximumSize(QSize(25, 25));
        arrowLabel->setStyleSheet(QStringLiteral("background-image: url(:/pendingImage/arrow.png);"));

        gridLayout->addWidget(arrowLabel, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);


        horizontalLayout->addWidget(widget_5);

        widget_4 = new QWidget(mainBackgroundWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(291, 383));
        widget_4->setMaximumSize(QSize(291, 383));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(291, 37));
        label_3->setMaximumSize(QSize(16777215, 37));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size:14px;\n"
"	color:#333333;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	background-color:#e5e4e4;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        goodsSellListWidget = new GoodsSellListWidget(widget_4);
        goodsSellListWidget->setObjectName(QStringLiteral("goodsSellListWidget"));

        verticalLayout_3->addWidget(goodsSellListWidget);


        horizontalLayout->addWidget(widget_4);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(mainBackgroundWidget);


        retranslateUi(PendingDlg);

        QMetaObject::connectSlotsByName(PendingDlg);
    } // setupUi

    void retranslateUi(QDialog *PendingDlg)
    {
        PendingDlg->setWindowTitle(QApplication::translate("PendingDlg", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("PendingDlg", "\350\256\242\345\215\225", Q_NULLPTR));
        clearButton->setText(QApplication::translate("PendingDlg", "\345\205\250\351\203\250\345\210\240\351\231\244", Q_NULLPTR));
        arrowLabel->setText(QString());
        label_3->setText(QApplication::translate("PendingDlg", "\345\225\206\345\223\201\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PendingDlg: public Ui_PendingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENDINGDLG_H
