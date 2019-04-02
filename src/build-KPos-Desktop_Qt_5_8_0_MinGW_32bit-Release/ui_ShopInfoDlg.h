/********************************************************************************
** Form generated from reading UI file 'ShopInfoDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPINFODLG_H
#define UI_SHOPINFODLG_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_ShopInfoDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    TitleBarWidget *titleWidget;
    QWidget *backgroundWidget;
    QVBoxLayout *verticalLayout;
    QWidget *contentWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *corpNameLabel;
    QLabel *label_2;
    QLabel *shopNameLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirmButton;
    QPushButton *cancellButton;

    void setupUi(QDialog *ShopInfoDlg)
    {
        if (ShopInfoDlg->objectName().isEmpty())
            ShopInfoDlg->setObjectName(QStringLiteral("ShopInfoDlg"));
        ShopInfoDlg->resize(370, 231);
        ShopInfoDlg->setMinimumSize(QSize(370, 231));
        verticalLayout_2 = new QVBoxLayout(ShopInfoDlg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(ShopInfoDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(370, 40));
        titleWidget->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(titleWidget);

        backgroundWidget = new QWidget(ShopInfoDlg);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
        backgroundWidget->setStyleSheet(QLatin1String("QWidget#backgroundWidget\n"
"{\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(backgroundWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 12, 20, 20);
        contentWidget = new QWidget(backgroundWidget);
        contentWidget->setObjectName(QStringLiteral("contentWidget"));
        contentWidget->setMinimumSize(QSize(329, 91));
        contentWidget->setMaximumSize(QSize(16777215, 16777215));
        contentWidget->setStyleSheet(QLatin1String("QWidget#contentWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        gridLayout = new QGridLayout(contentWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 7, 10, 20);
        label = new QLabel(contentWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(85, 45));
        label->setMaximumSize(QSize(85, 16777215));
        label->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(51, 51, 51);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        corpNameLabel = new QLabel(contentWidget);
        corpNameLabel->setObjectName(QStringLiteral("corpNameLabel"));
        corpNameLabel->setMinimumSize(QSize(0, 45));
        corpNameLabel->setStyleSheet(QString::fromUtf8("color:#ea8852;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;"));
        corpNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(corpNameLabel, 0, 1, 1, 1);

        label_2 = new QLabel(contentWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(85, 45));
        label_2->setMaximumSize(QSize(85, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(51, 51, 51);"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        shopNameLabel = new QLabel(contentWidget);
        shopNameLabel->setObjectName(QStringLiteral("shopNameLabel"));
        shopNameLabel->setMinimumSize(QSize(0, 45));
        shopNameLabel->setStyleSheet(QString::fromUtf8("color:#ea8852;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;"));
        shopNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(shopNameLabel, 1, 1, 1, 1);


        verticalLayout->addWidget(contentWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(18);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(-1, 14, -1, -1);
        confirmButton = new QPushButton(backgroundWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setMinimumSize(QSize(152, 42));
        confirmButton->setMaximumSize(QSize(197, 56));
        confirmButton->setFocusPolicy(Qt::NoFocus);
        confirmButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#ffffff;\n"
"	font-size:14px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));

        horizontalLayout->addWidget(confirmButton);

        cancellButton = new QPushButton(backgroundWidget);
        cancellButton->setObjectName(QStringLiteral("cancellButton"));
        cancellButton->setMinimumSize(QSize(152, 42));
        cancellButton->setMaximumSize(QSize(197, 56));
        cancellButton->setFocusPolicy(Qt::NoFocus);
        cancellButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#ffffff;\n"
"	font-size:14px;\n"
"	border-image: url(:/shareImages/cancel_normal.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/shareImages/cancel_press.png);\n"
"}\n"
""));

        horizontalLayout->addWidget(cancellButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(backgroundWidget);


        retranslateUi(ShopInfoDlg);

        QMetaObject::connectSlotsByName(ShopInfoDlg);
    } // setupUi

    void retranslateUi(QDialog *ShopInfoDlg)
    {
        ShopInfoDlg->setWindowTitle(QApplication::translate("ShopInfoDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ShopInfoDlg", "\347\273\204\347\273\207\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        corpNameLabel->setText(QApplication::translate("ShopInfoDlg", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("ShopInfoDlg", "\351\227\250\345\272\227\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        shopNameLabel->setText(QApplication::translate("ShopInfoDlg", "TextLabel", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("ShopInfoDlg", "\347\241\256\350\256\244\344\270\212\344\274\240", Q_NULLPTR));
        cancellButton->setText(QApplication::translate("ShopInfoDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShopInfoDlg: public Ui_ShopInfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPINFODLG_H
