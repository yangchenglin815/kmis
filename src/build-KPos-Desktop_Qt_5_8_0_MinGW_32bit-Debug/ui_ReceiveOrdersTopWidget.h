/********************************************************************************
** Form generated from reading UI file 'ReceiveOrdersTopWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEORDERSTOPWIDGET_H
#define UI_RECEIVEORDERSTOPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include "KPosComboBoxSimple.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiveOrdersTopWidget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget_2;
    QLineEdit *lineEdit_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    KPosComboBoxSimple *providerComboBox;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    KPosComboBoxSimple *receiptTypeComboBox;

    void setupUi(QWidget *ReceiveOrdersTopWidget)
    {
        if (ReceiveOrdersTopWidget->objectName().isEmpty())
            ReceiveOrdersTopWidget->setObjectName(QStringLiteral("ReceiveOrdersTopWidget"));
        ReceiveOrdersTopWidget->resize(760, 62);
        horizontalLayout_4 = new QHBoxLayout(ReceiveOrdersTopWidget);
        horizontalLayout_4->setSpacing(30);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(ReceiveOrdersTopWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font-size:14px;\n"
"color:#999999;"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QLatin1String("font-size:12px;\n"
"color:#999999;"));

        horizontalLayout->addWidget(lineEdit);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(16, 1));
        widget_2->setMaximumSize(QSize(16, 1));
        widget_2->setStyleSheet(QStringLiteral("border: 1px solid #6c6c6c;"));

        horizontalLayout->addWidget(widget_2);

        lineEdit_2 = new QLineEdit(widget_4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setStyleSheet(QLatin1String("font-size:12px;\n"
"color:#999999;"));

        horizontalLayout->addWidget(lineEdit_2);


        horizontalLayout_4->addWidget(widget_4);

        widget_5 = new QWidget(ReceiveOrdersTopWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font-size:14px;\n"
"color:#999999;"));

        horizontalLayout_2->addWidget(label_2);

        providerComboBox = new KPosComboBoxSimple(widget_5);
        providerComboBox->setObjectName(QStringLiteral("providerComboBox"));
        providerComboBox->setMinimumSize(QSize(170, 22));
        providerComboBox->setMaximumSize(QSize(170, 22));

        horizontalLayout_2->addWidget(providerComboBox);


        horizontalLayout_4->addWidget(widget_5);

        widget_6 = new QWidget(ReceiveOrdersTopWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("font-size:14px;\n"
"color:#999999;"));

        horizontalLayout_3->addWidget(label_3);

        receiptTypeComboBox = new KPosComboBoxSimple(widget_6);
        receiptTypeComboBox->setObjectName(QStringLiteral("receiptTypeComboBox"));
        receiptTypeComboBox->setMinimumSize(QSize(88, 22));
        receiptTypeComboBox->setMaximumSize(QSize(88, 22));

        horizontalLayout_3->addWidget(receiptTypeComboBox);


        horizontalLayout_4->addWidget(widget_6);


        retranslateUi(ReceiveOrdersTopWidget);

        QMetaObject::connectSlotsByName(ReceiveOrdersTopWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiveOrdersTopWidget)
    {
        ReceiveOrdersTopWidget->setWindowTitle(QApplication::translate("ReceiveOrdersTopWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ReceiveOrdersTopWidget", "\346\227\245\346\234\237\347\255\233\351\200\211\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReceiveOrdersTopWidget", "\344\276\233\345\272\224\345\225\206\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReceiveOrdersTopWidget", "\345\215\225\346\215\256\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiveOrdersTopWidget: public Ui_ReceiveOrdersTopWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEORDERSTOPWIDGET_H
