/********************************************************************************
** Form generated from reading UI file 'BarCodeScaleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCODESCALEWIDGET_H
#define UI_BARCODESCALEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCSGoodsSelectWidget.h"
#include "BCSWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BarCodeScaleWidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    BCSWidget *bcsPage;
    BCSGoodsSelectWidget *bcsGoodsSelectPage;

    void setupUi(QWidget *BarCodeScaleWidget)
    {
        if (BarCodeScaleWidget->objectName().isEmpty())
            BarCodeScaleWidget->setObjectName(QStringLiteral("BarCodeScaleWidget"));
        BarCodeScaleWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(BarCodeScaleWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(BarCodeScaleWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        bcsPage = new BCSWidget();
        bcsPage->setObjectName(QStringLiteral("bcsPage"));
        bcsPage->setLayoutDirection(Qt::LeftToRight);
        bcsPage->setStyleSheet(QLatin1String("QWidget#bcsPage{\n"
"	background-color: rgb(81, 80, 80);\n"
"}\n"
""));
        stackedWidget->addWidget(bcsPage);
        bcsGoodsSelectPage = new BCSGoodsSelectWidget();
        bcsGoodsSelectPage->setObjectName(QStringLiteral("bcsGoodsSelectPage"));
        bcsGoodsSelectPage->setStyleSheet(QLatin1String("QWidget#bcsGoodsSelectPage{\n"
"	background-color: rgb(81, 80, 80);\n"
"}"));
        stackedWidget->addWidget(bcsGoodsSelectPage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(BarCodeScaleWidget);

        QMetaObject::connectSlotsByName(BarCodeScaleWidget);
    } // setupUi

    void retranslateUi(QWidget *BarCodeScaleWidget)
    {
        BarCodeScaleWidget->setWindowTitle(QApplication::translate("BarCodeScaleWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BarCodeScaleWidget: public Ui_BarCodeScaleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCODESCALEWIDGET_H
