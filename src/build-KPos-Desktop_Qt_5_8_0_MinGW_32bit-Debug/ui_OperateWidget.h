/********************************************************************************
** Form generated from reading UI file 'OperateWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATEWIDGET_H
#define UI_OPERATEWIDGET_H

#include <OperatorButton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperateWidget
{
public:
    QHBoxLayout *horizontalLayout;
    OperatorButton *operator_01;
    OperatorButton *operator_02;
    OperatorButton *operator_03;
    OperatorButton *operator_04;
    OperatorButton *operator_05;
    OperatorButton *operator_06;

    void setupUi(QWidget *OperateWidget)
    {
        if (OperateWidget->objectName().isEmpty())
            OperateWidget->setObjectName(QStringLiteral("OperateWidget"));
        OperateWidget->resize(498, 53);
        OperateWidget->setStyleSheet(QStringLiteral("font-size:14px;"));
        horizontalLayout = new QHBoxLayout(OperateWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        operator_01 = new OperatorButton(OperateWidget);
        operator_01->setObjectName(QStringLiteral("operator_01"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(operator_01->sizePolicy().hasHeightForWidth());
        operator_01->setSizePolicy(sizePolicy);
        operator_01->setMinimumSize(QSize(78, 53));
        operator_01->setMaximumSize(QSize(225, 90));
        QFont font;
        operator_01->setFont(font);
        operator_01->setFocusPolicy(Qt::NoFocus);
        operator_01->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(operator_01);

        operator_02 = new OperatorButton(OperateWidget);
        operator_02->setObjectName(QStringLiteral("operator_02"));
        sizePolicy.setHeightForWidth(operator_02->sizePolicy().hasHeightForWidth());
        operator_02->setSizePolicy(sizePolicy);
        operator_02->setMinimumSize(QSize(78, 53));
        operator_02->setMaximumSize(QSize(225, 90));
        operator_02->setFont(font);
        operator_02->setFocusPolicy(Qt::NoFocus);
        operator_02->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(operator_02);

        operator_03 = new OperatorButton(OperateWidget);
        operator_03->setObjectName(QStringLiteral("operator_03"));
        sizePolicy.setHeightForWidth(operator_03->sizePolicy().hasHeightForWidth());
        operator_03->setSizePolicy(sizePolicy);
        operator_03->setMinimumSize(QSize(78, 53));
        operator_03->setMaximumSize(QSize(225, 90));
        operator_03->setFont(font);
        operator_03->setFocusPolicy(Qt::NoFocus);
        operator_03->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(operator_03);

        operator_04 = new OperatorButton(OperateWidget);
        operator_04->setObjectName(QStringLiteral("operator_04"));
        sizePolicy.setHeightForWidth(operator_04->sizePolicy().hasHeightForWidth());
        operator_04->setSizePolicy(sizePolicy);
        operator_04->setMinimumSize(QSize(78, 53));
        operator_04->setMaximumSize(QSize(225, 90));
        operator_04->setFont(font);
        operator_04->setFocusPolicy(Qt::NoFocus);
        operator_04->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(operator_04);

        operator_05 = new OperatorButton(OperateWidget);
        operator_05->setObjectName(QStringLiteral("operator_05"));
        sizePolicy.setHeightForWidth(operator_05->sizePolicy().hasHeightForWidth());
        operator_05->setSizePolicy(sizePolicy);
        operator_05->setMinimumSize(QSize(78, 53));
        operator_05->setMaximumSize(QSize(225, 90));
        operator_05->setFont(font);
        operator_05->setFocusPolicy(Qt::NoFocus);
        operator_05->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(operator_05);

        operator_06 = new OperatorButton(OperateWidget);
        operator_06->setObjectName(QStringLiteral("operator_06"));
        sizePolicy.setHeightForWidth(operator_06->sizePolicy().hasHeightForWidth());
        operator_06->setSizePolicy(sizePolicy);
        operator_06->setMinimumSize(QSize(78, 53));
        operator_06->setMaximumSize(QSize(225, 90));
        operator_06->setFont(font);
        operator_06->setFocusPolicy(Qt::NoFocus);
        operator_06->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(operator_06);


        retranslateUi(OperateWidget);

        QMetaObject::connectSlotsByName(OperateWidget);
    } // setupUi

    void retranslateUi(QWidget *OperateWidget)
    {
        OperateWidget->setWindowTitle(QApplication::translate("OperateWidget", "OperateWidget", Q_NULLPTR));
        operator_01->setText(QString());
        operator_02->setText(QString());
        operator_03->setText(QString());
        operator_04->setText(QString());
        operator_05->setText(QString());
        operator_06->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OperateWidget: public Ui_OperateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATEWIDGET_H
