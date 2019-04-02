/********************************************************************************
** Form generated from reading UI file 'KPosUpdateProgressWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KPOSUPDATEPROGRESSWIDGET_H
#define UI_KPOSUPDATEPROGRESSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ProgressWidget.h"

QT_BEGIN_NAMESPACE

class Ui_KPosUpdateProgressWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *skinWidget;
    QLabel *label_2;
    QLabel *hintLabel;
    ProgressWidget *progressWidget;

    void setupUi(QWidget *KPosUpdateProgressWidget)
    {
        if (KPosUpdateProgressWidget->objectName().isEmpty())
            KPosUpdateProgressWidget->setObjectName(QStringLiteral("KPosUpdateProgressWidget"));
        KPosUpdateProgressWidget->resize(708, 311);
        KPosUpdateProgressWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(KPosUpdateProgressWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        skinWidget = new QWidget(KPosUpdateProgressWidget);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	border-image: url(:/progressImage/rect.png);\n"
"}\n"
""));
        label_2 = new QLabel(skinWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(271, 30, 80, 80));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/progressImage/logo.png);"));
        hintLabel = new QLabel(skinWidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setGeometry(QRect(239, 151, 161, 16));
        progressWidget = new ProgressWidget(skinWidget);
        progressWidget->setObjectName(QStringLiteral("progressWidget"));
        progressWidget->setGeometry(QRect(40, 190, 610, 41));

        verticalLayout->addWidget(skinWidget);


        retranslateUi(KPosUpdateProgressWidget);

        QMetaObject::connectSlotsByName(KPosUpdateProgressWidget);
    } // setupUi

    void retranslateUi(QWidget *KPosUpdateProgressWidget)
    {
        KPosUpdateProgressWidget->setWindowTitle(QApplication::translate("KPosUpdateProgressWidget", "Form", Q_NULLPTR));
        label_2->setText(QString());
        hintLabel->setText(QApplication::translate("KPosUpdateProgressWidget", "\346\255\243\345\234\250\344\270\213\350\275\275\345\256\211\350\243\205\345\214\205\357\274\214\350\257\267\347\250\215\347\255\211...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KPosUpdateProgressWidget: public Ui_KPosUpdateProgressWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KPOSUPDATEPROGRESSWIDGET_H
