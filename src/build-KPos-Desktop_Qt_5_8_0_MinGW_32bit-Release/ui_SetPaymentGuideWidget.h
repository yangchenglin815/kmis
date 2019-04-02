/********************************************************************************
** Form generated from reading UI file 'SetPaymentGuideWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPAYMENTGUIDEWIDGET_H
#define UI_SETPAYMENTGUIDEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetPaymentGuideWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *SetPaymentGuideWidget)
    {
        if (SetPaymentGuideWidget->objectName().isEmpty())
            SetPaymentGuideWidget->setObjectName(QStringLiteral("SetPaymentGuideWidget"));
        SetPaymentGuideWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(SetPaymentGuideWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetPaymentGuideWidget);
        widget->setObjectName(QStringLiteral("widget"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 110, 300, 150));
        pushButton->setFlat(true);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(19, 284, 153, 47));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font-size:15px;\n"
"border-top-left-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(widget);


        retranslateUi(SetPaymentGuideWidget);

        QMetaObject::connectSlotsByName(SetPaymentGuideWidget);
    } // setupUi

    void retranslateUi(QWidget *SetPaymentGuideWidget)
    {
        SetPaymentGuideWidget->setWindowTitle(QApplication::translate("SetPaymentGuideWidget", "Form", Q_NULLPTR));
        pushButton->setText(QString());
        label->setText(QApplication::translate("SetPaymentGuideWidget", "\346\224\257\344\273\230\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetPaymentGuideWidget: public Ui_SetPaymentGuideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPAYMENTGUIDEWIDGET_H
