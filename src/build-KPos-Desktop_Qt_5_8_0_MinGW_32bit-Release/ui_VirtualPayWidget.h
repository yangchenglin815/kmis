/********************************************************************************
** Form generated from reading UI file 'VirtualPayWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIRTUALPAYWIDGET_H
#define UI_VIRTUALPAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <VirtualPayButton.h>

QT_BEGIN_NAMESPACE

class Ui_VirtualPayWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *virtualWidget;
    VirtualPayButton *virtualPay_01;
    VirtualPayButton *virtualPay_02;
    VirtualPayButton *virtualPay_03;
    VirtualPayButton *virtualPay_04;
    VirtualPayButton *virtualPay_05;
    VirtualPayButton *virtualPay_06;
    VirtualPayButton *virtualPay_09;
    VirtualPayButton *virtualPay_08;
    VirtualPayButton *virtualPay_07;
    QWidget *widget_2;
    QLabel *factAmtVirtualLabel;
    QPushButton *statementVirtualButton;
    QLineEdit *factAmtVirtualEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *VirtualPayWidget)
    {
        if (VirtualPayWidget->objectName().isEmpty())
            VirtualPayWidget->setObjectName(QStringLiteral("VirtualPayWidget"));
        VirtualPayWidget->resize(285, 235);
        verticalLayout = new QVBoxLayout(VirtualPayWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        virtualWidget = new QWidget(VirtualPayWidget);
        virtualWidget->setObjectName(QStringLiteral("virtualWidget"));
        virtualWidget->setMinimumSize(QSize(285, 144));
        virtualWidget->setMaximumSize(QSize(16777215, 16777215));
        virtualWidget->setStyleSheet(QLatin1String("QWidget#virtualWidget {\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        virtualPay_01 = new VirtualPayButton(virtualWidget);
        virtualPay_01->setObjectName(QStringLiteral("virtualPay_01"));
        virtualPay_01->setGeometry(QRect(11, 9, 78, 38));
        virtualPay_01->setMinimumSize(QSize(78, 38));
        virtualPay_01->setFocusPolicy(Qt::NoFocus);
        virtualPay_02 = new VirtualPayButton(virtualWidget);
        virtualPay_02->setObjectName(QStringLiteral("virtualPay_02"));
        virtualPay_02->setGeometry(QRect(102, 9, 78, 38));
        virtualPay_02->setMinimumSize(QSize(78, 38));
        virtualPay_02->setFocusPolicy(Qt::NoFocus);
        virtualPay_03 = new VirtualPayButton(virtualWidget);
        virtualPay_03->setObjectName(QStringLiteral("virtualPay_03"));
        virtualPay_03->setGeometry(QRect(192, 9, 78, 38));
        virtualPay_03->setMinimumSize(QSize(78, 38));
        virtualPay_03->setFocusPolicy(Qt::NoFocus);
        virtualPay_04 = new VirtualPayButton(virtualWidget);
        virtualPay_04->setObjectName(QStringLiteral("virtualPay_04"));
        virtualPay_04->setGeometry(QRect(11, 52, 78, 38));
        virtualPay_04->setMinimumSize(QSize(78, 38));
        virtualPay_04->setFocusPolicy(Qt::NoFocus);
        virtualPay_05 = new VirtualPayButton(virtualWidget);
        virtualPay_05->setObjectName(QStringLiteral("virtualPay_05"));
        virtualPay_05->setGeometry(QRect(102, 52, 78, 38));
        virtualPay_05->setMinimumSize(QSize(78, 38));
        virtualPay_05->setFocusPolicy(Qt::NoFocus);
        virtualPay_06 = new VirtualPayButton(virtualWidget);
        virtualPay_06->setObjectName(QStringLiteral("virtualPay_06"));
        virtualPay_06->setGeometry(QRect(192, 52, 78, 38));
        virtualPay_06->setMinimumSize(QSize(78, 38));
        virtualPay_06->setFocusPolicy(Qt::NoFocus);
        virtualPay_09 = new VirtualPayButton(virtualWidget);
        virtualPay_09->setObjectName(QStringLiteral("virtualPay_09"));
        virtualPay_09->setGeometry(QRect(192, 95, 78, 38));
        virtualPay_09->setMinimumSize(QSize(78, 38));
        virtualPay_09->setFocusPolicy(Qt::NoFocus);
        virtualPay_08 = new VirtualPayButton(virtualWidget);
        virtualPay_08->setObjectName(QStringLiteral("virtualPay_08"));
        virtualPay_08->setGeometry(QRect(102, 95, 78, 38));
        virtualPay_08->setMinimumSize(QSize(78, 38));
        virtualPay_08->setFocusPolicy(Qt::NoFocus);
        virtualPay_07 = new VirtualPayButton(virtualWidget);
        virtualPay_07->setObjectName(QStringLiteral("virtualPay_07"));
        virtualPay_07->setGeometry(QRect(11, 95, 78, 38));
        virtualPay_07->setMinimumSize(QSize(78, 38));
        virtualPay_07->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(virtualWidget);

        widget_2 = new QWidget(VirtualPayWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(285, 91));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2 { \n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        factAmtVirtualLabel = new QLabel(widget_2);
        factAmtVirtualLabel->setObjectName(QStringLiteral("factAmtVirtualLabel"));
        factAmtVirtualLabel->setGeometry(QRect(25, 5, 72, 31));
        QFont font;
        factAmtVirtualLabel->setFont(font);
        factAmtVirtualLabel->setStyleSheet(QLatin1String("QLabel#factAmtJdLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        statementVirtualButton = new QPushButton(widget_2);
        statementVirtualButton->setObjectName(QStringLiteral("statementVirtualButton"));
        statementVirtualButton->setGeometry(QRect(25, 40, 245, 42));
        statementVirtualButton->setFont(font);
        statementVirtualButton->setFocusPolicy(Qt::NoFocus);
        statementVirtualButton->setStyleSheet(QLatin1String("QPushButton#statementVirtualButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#statementVirtualButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}\n"
""));
        factAmtVirtualEdit = new QLineEdit(widget_2);
        factAmtVirtualEdit->setObjectName(QStringLiteral("factAmtVirtualEdit"));
        factAmtVirtualEdit->setGeometry(QRect(100, 5, 168, 31));
        factAmtVirtualEdit->setFont(font);
        factAmtVirtualEdit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        verticalLayout->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(VirtualPayWidget);

        QMetaObject::connectSlotsByName(VirtualPayWidget);
    } // setupUi

    void retranslateUi(QWidget *VirtualPayWidget)
    {
        VirtualPayWidget->setWindowTitle(QApplication::translate("VirtualPayWidget", "VirtualPayWidget", Q_NULLPTR));
        virtualPay_01->setText(QApplication::translate("VirtualPayWidget", "\345\256\236\344\275\223\345\215\241", Q_NULLPTR));
        virtualPay_02->setText(QApplication::translate("VirtualPayWidget", "\351\223\266\350\201\224\345\215\241", Q_NULLPTR));
        virtualPay_03->setText(QApplication::translate("VirtualPayWidget", "\346\236\234\351\272\246", Q_NULLPTR));
        virtualPay_04->setText(QApplication::translate("VirtualPayWidget", "\346\224\257\347\245\250", Q_NULLPTR));
        virtualPay_05->setText(QApplication::translate("VirtualPayWidget", "\346\254\240\345\215\225", Q_NULLPTR));
        virtualPay_06->setText(QApplication::translate("VirtualPayWidget", "\345\270\202\346\260\221\345\215\241", Q_NULLPTR));
        virtualPay_09->setText(QString());
        virtualPay_08->setText(QString());
        virtualPay_07->setText(QApplication::translate("VirtualPayWidget", "\345\205\266\344\273\226", Q_NULLPTR));
        factAmtVirtualLabel->setText(QApplication::translate("VirtualPayWidget", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        statementVirtualButton->setText(QApplication::translate("VirtualPayWidget", "\347\273\223\347\256\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VirtualPayWidget: public Ui_VirtualPayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIRTUALPAYWIDGET_H
