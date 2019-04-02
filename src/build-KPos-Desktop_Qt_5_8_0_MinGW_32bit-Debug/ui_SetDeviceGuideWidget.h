/********************************************************************************
** Form generated from reading UI file 'SetDeviceGuideWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDEVICEGUIDEWIDGET_H
#define UI_SETDEVICEGUIDEWIDGET_H

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

class Ui_SetDeviceGuideWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *SetDeviceGuideWidget)
    {
        if (SetDeviceGuideWidget->objectName().isEmpty())
            SetDeviceGuideWidget->setObjectName(QStringLiteral("SetDeviceGuideWidget"));
        SetDeviceGuideWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(SetDeviceGuideWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetDeviceGuideWidget);
        widget->setObjectName(QStringLiteral("widget"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 318, 300, 150));
        pushButton->setFlat(true);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(19, 232, 153, 47));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font-size:15px;\n"
"border-top-left-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(widget);


        retranslateUi(SetDeviceGuideWidget);

        QMetaObject::connectSlotsByName(SetDeviceGuideWidget);
    } // setupUi

    void retranslateUi(QWidget *SetDeviceGuideWidget)
    {
        SetDeviceGuideWidget->setWindowTitle(QApplication::translate("SetDeviceGuideWidget", "Form", Q_NULLPTR));
        pushButton->setText(QString());
        label->setText(QApplication::translate("SetDeviceGuideWidget", "\350\256\276\345\244\207\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetDeviceGuideWidget: public Ui_SetDeviceGuideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDEVICEGUIDEWIDGET_H
