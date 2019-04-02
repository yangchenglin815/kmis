/********************************************************************************
** Form generated from reading UI file 'SetGoodsGuideWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETGOODSGUIDEWIDGET_H
#define UI_SETGOODSGUIDEWIDGET_H

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

class Ui_SetGoodsGuideWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *SetGoodsGuideWidget)
    {
        if (SetGoodsGuideWidget->objectName().isEmpty())
            SetGoodsGuideWidget->setObjectName(QStringLiteral("SetGoodsGuideWidget"));
        SetGoodsGuideWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(SetGoodsGuideWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetGoodsGuideWidget);
        widget->setObjectName(QStringLiteral("widget"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(211, 263, 300, 150));
        pushButton->setFlat(true);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(19, 176, 153, 47));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font-size:15px;\n"
"border-top-left-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(widget);


        retranslateUi(SetGoodsGuideWidget);

        QMetaObject::connectSlotsByName(SetGoodsGuideWidget);
    } // setupUi

    void retranslateUi(QWidget *SetGoodsGuideWidget)
    {
        SetGoodsGuideWidget->setWindowTitle(QApplication::translate("SetGoodsGuideWidget", "Form", Q_NULLPTR));
        pushButton->setText(QString());
        label->setText(QApplication::translate("SetGoodsGuideWidget", "\345\225\206\345\223\201\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetGoodsGuideWidget: public Ui_SetGoodsGuideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETGOODSGUIDEWIDGET_H
