/********************************************************************************
** Form generated from reading UI file 'SetBaseGuideWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETBASEGUIDEWIDGET_H
#define UI_SETBASEGUIDEWIDGET_H

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

class Ui_SetBaseGuideWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *SetBaseGuideWidget)
    {
        if (SetBaseGuideWidget->objectName().isEmpty())
            SetBaseGuideWidget->setObjectName(QStringLiteral("SetBaseGuideWidget"));
        SetBaseGuideWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(SetBaseGuideWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetBaseGuideWidget);
        widget->setObjectName(QStringLiteral("widget"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(217, 152, 300, 150));
        pushButton->setFlat(true);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(19, 67, 153, 47));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font-size:15px;\n"
"border-top-left-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(widget);


        retranslateUi(SetBaseGuideWidget);

        QMetaObject::connectSlotsByName(SetBaseGuideWidget);
    } // setupUi

    void retranslateUi(QWidget *SetBaseGuideWidget)
    {
        SetBaseGuideWidget->setWindowTitle(QApplication::translate("SetBaseGuideWidget", "Form", Q_NULLPTR));
        pushButton->setText(QString());
        label->setText(QApplication::translate("SetBaseGuideWidget", "\345\237\272\346\234\254\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetBaseGuideWidget: public Ui_SetBaseGuideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETBASEGUIDEWIDGET_H
