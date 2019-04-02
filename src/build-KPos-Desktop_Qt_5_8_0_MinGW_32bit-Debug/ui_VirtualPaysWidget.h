/********************************************************************************
** Form generated from reading UI file 'VirtualPaysWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIRTUALPAYSWIDGET_H
#define UI_VIRTUALPAYSWIDGET_H

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

QT_BEGIN_NAMESPACE

class Ui_VirtualPaysWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *virtualWidget;
    QPushButton *virtualPay_01;
    QPushButton *virtualPay_02;
    QPushButton *virtualPay_03;
    QPushButton *virtualPay_04;
    QPushButton *virtualPay_05;
    QPushButton *virtualPay_06;
    QPushButton *virtualPay_09;
    QPushButton *virtualPay_08;
    QPushButton *virtualPay_07;
    QWidget *widget_2;
    QLabel *factAmtVirtualLabel;
    QPushButton *confirmButton;
    QLineEdit *factAmtVirtualEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *VirtualPaysWidget)
    {
        if (VirtualPaysWidget->objectName().isEmpty())
            VirtualPaysWidget->setObjectName(QStringLiteral("VirtualPaysWidget"));
        VirtualPaysWidget->resize(285, 235);
        verticalLayout = new QVBoxLayout(VirtualPaysWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        virtualWidget = new QWidget(VirtualPaysWidget);
        virtualWidget->setObjectName(QStringLiteral("virtualWidget"));
        virtualWidget->setMinimumSize(QSize(285, 144));
        virtualWidget->setMaximumSize(QSize(16777215, 16777215));
        virtualWidget->setStyleSheet(QLatin1String("QWidget#virtualWidget {\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        virtualPay_01 = new QPushButton(virtualWidget);
        virtualPay_01->setObjectName(QStringLiteral("virtualPay_01"));
        virtualPay_01->setGeometry(QRect(11, 9, 78, 38));
        virtualPay_01->setMinimumSize(QSize(78, 38));
        virtualPay_01->setFocusPolicy(Qt::NoFocus);
        virtualPay_02 = new QPushButton(virtualWidget);
        virtualPay_02->setObjectName(QStringLiteral("virtualPay_02"));
        virtualPay_02->setGeometry(QRect(102, 9, 78, 38));
        virtualPay_02->setMinimumSize(QSize(78, 38));
        virtualPay_02->setFocusPolicy(Qt::NoFocus);
        virtualPay_03 = new QPushButton(virtualWidget);
        virtualPay_03->setObjectName(QStringLiteral("virtualPay_03"));
        virtualPay_03->setGeometry(QRect(192, 9, 78, 38));
        virtualPay_03->setMinimumSize(QSize(78, 38));
        virtualPay_03->setFocusPolicy(Qt::NoFocus);
        virtualPay_04 = new QPushButton(virtualWidget);
        virtualPay_04->setObjectName(QStringLiteral("virtualPay_04"));
        virtualPay_04->setGeometry(QRect(11, 52, 78, 38));
        virtualPay_04->setMinimumSize(QSize(78, 38));
        virtualPay_04->setFocusPolicy(Qt::NoFocus);
        virtualPay_05 = new QPushButton(virtualWidget);
        virtualPay_05->setObjectName(QStringLiteral("virtualPay_05"));
        virtualPay_05->setGeometry(QRect(102, 52, 78, 38));
        virtualPay_05->setMinimumSize(QSize(78, 38));
        virtualPay_05->setFocusPolicy(Qt::NoFocus);
        virtualPay_06 = new QPushButton(virtualWidget);
        virtualPay_06->setObjectName(QStringLiteral("virtualPay_06"));
        virtualPay_06->setGeometry(QRect(192, 52, 78, 38));
        virtualPay_06->setMinimumSize(QSize(78, 38));
        virtualPay_06->setFocusPolicy(Qt::NoFocus);
        virtualPay_09 = new QPushButton(virtualWidget);
        virtualPay_09->setObjectName(QStringLiteral("virtualPay_09"));
        virtualPay_09->setGeometry(QRect(192, 95, 78, 38));
        virtualPay_09->setMinimumSize(QSize(78, 38));
        virtualPay_09->setFocusPolicy(Qt::NoFocus);
        virtualPay_08 = new QPushButton(virtualWidget);
        virtualPay_08->setObjectName(QStringLiteral("virtualPay_08"));
        virtualPay_08->setGeometry(QRect(102, 95, 78, 38));
        virtualPay_08->setMinimumSize(QSize(78, 38));
        virtualPay_08->setFocusPolicy(Qt::NoFocus);
        virtualPay_07 = new QPushButton(virtualWidget);
        virtualPay_07->setObjectName(QStringLiteral("virtualPay_07"));
        virtualPay_07->setGeometry(QRect(11, 95, 78, 38));
        virtualPay_07->setMinimumSize(QSize(78, 38));
        virtualPay_07->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(virtualWidget);

        widget_2 = new QWidget(VirtualPaysWidget);
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
        confirmButton = new QPushButton(widget_2);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(25, 40, 245, 42));
        confirmButton->setFont(font);
        confirmButton->setFocusPolicy(Qt::NoFocus);
        confirmButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
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

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(VirtualPaysWidget);

        QMetaObject::connectSlotsByName(VirtualPaysWidget);
    } // setupUi

    void retranslateUi(QWidget *VirtualPaysWidget)
    {
        VirtualPaysWidget->setWindowTitle(QApplication::translate("VirtualPaysWidget", "Form", Q_NULLPTR));
        virtualPay_01->setText(QApplication::translate("VirtualPaysWidget", "\345\256\236\344\275\223\345\215\241", Q_NULLPTR));
        virtualPay_02->setText(QApplication::translate("VirtualPaysWidget", "\351\223\266\350\201\224\345\215\241", Q_NULLPTR));
        virtualPay_03->setText(QApplication::translate("VirtualPaysWidget", "\346\236\234\351\272\246", Q_NULLPTR));
        virtualPay_04->setText(QApplication::translate("VirtualPaysWidget", "\346\224\257\347\245\250", Q_NULLPTR));
        virtualPay_05->setText(QApplication::translate("VirtualPaysWidget", "\346\254\240\345\215\225", Q_NULLPTR));
        virtualPay_06->setText(QApplication::translate("VirtualPaysWidget", "\345\270\202\346\260\221\345\215\241", Q_NULLPTR));
        virtualPay_09->setText(QString());
        virtualPay_08->setText(QString());
        virtualPay_07->setText(QApplication::translate("VirtualPaysWidget", "\345\205\266\344\273\226", Q_NULLPTR));
        factAmtVirtualLabel->setText(QApplication::translate("VirtualPaysWidget", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("VirtualPaysWidget", "\347\273\223\347\256\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VirtualPaysWidget: public Ui_VirtualPaysWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIRTUALPAYSWIDGET_H
