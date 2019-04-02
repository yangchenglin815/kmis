/********************************************************************************
** Form generated from reading UI file 'SetParamGuideWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPARAMGUIDEWIDGET_H
#define UI_SETPARAMGUIDEWIDGET_H

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

class Ui_SetParamGuideWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *SetParamGuideWidget)
    {
        if (SetParamGuideWidget->objectName().isEmpty())
            SetParamGuideWidget->setObjectName(QStringLiteral("SetParamGuideWidget"));
        SetParamGuideWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(SetParamGuideWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetParamGuideWidget);
        widget->setObjectName(QStringLiteral("widget"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 156, 300, 150));
        pushButton->setFlat(true);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(19, 342, 153, 47));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font-size:15px;\n"
"border-top-left-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(widget);


        retranslateUi(SetParamGuideWidget);

        QMetaObject::connectSlotsByName(SetParamGuideWidget);
    } // setupUi

    void retranslateUi(QWidget *SetParamGuideWidget)
    {
        SetParamGuideWidget->setWindowTitle(QApplication::translate("SetParamGuideWidget", "Form", Q_NULLPTR));
        pushButton->setText(QString());
        label->setText(QApplication::translate("SetParamGuideWidget", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetParamGuideWidget: public Ui_SetParamGuideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPARAMGUIDEWIDGET_H
