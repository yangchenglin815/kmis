/********************************************************************************
** Form generated from reading UI file 'SetButtonGuideWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETBUTTONGUIDEWIDGET_H
#define UI_SETBUTTONGUIDEWIDGET_H

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

class Ui_SetButtonGuideWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *SetButtonGuideWidget)
    {
        if (SetButtonGuideWidget->objectName().isEmpty())
            SetButtonGuideWidget->setObjectName(QStringLiteral("SetButtonGuideWidget"));
        SetButtonGuideWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(SetButtonGuideWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetButtonGuideWidget);
        widget->setObjectName(QStringLiteral("widget"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(217, 206, 300, 150));
        pushButton->setFlat(true);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(19, 122, 153, 47));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font-size:15px;\n"
"border-top-left-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(widget);


        retranslateUi(SetButtonGuideWidget);

        QMetaObject::connectSlotsByName(SetButtonGuideWidget);
    } // setupUi

    void retranslateUi(QWidget *SetButtonGuideWidget)
    {
        SetButtonGuideWidget->setWindowTitle(QApplication::translate("SetButtonGuideWidget", "Form", Q_NULLPTR));
        pushButton->setText(QString());
        label->setText(QApplication::translate("SetButtonGuideWidget", "\346\214\211\351\224\256\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetButtonGuideWidget: public Ui_SetButtonGuideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETBUTTONGUIDEWIDGET_H
