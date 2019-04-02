/********************************************************************************
** Form generated from reading UI file 'GoodsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSWIDGET_H
#define UI_GOODSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "GoodsCellButton.h"

QT_BEGIN_NAMESPACE

class Ui_GoodsWidget
{
public:
    QGridLayout *gridLayout;
    GoodsCellButton *cellButton_01;
    GoodsCellButton *cellButton_02;
    GoodsCellButton *cellButton_03;
    GoodsCellButton *cellButton_04;
    GoodsCellButton *cellButton_05;
    GoodsCellButton *cellButton_06;
    GoodsCellButton *cellButton_07;
    GoodsCellButton *cellButton_08;
    GoodsCellButton *cellButton_09;
    GoodsCellButton *cellButton_10;
    GoodsCellButton *cellButton_11;
    GoodsCellButton *cellButton_12;
    GoodsCellButton *cellButton_13;
    GoodsCellButton *cellButton_14;
    GoodsCellButton *cellButton_15;
    GoodsCellButton *cellButton_16;
    GoodsCellButton *cellButton_17;
    GoodsCellButton *cellButton_18;
    GoodsCellButton *cellButton_19;
    GoodsCellButton *cellButton_20;
    GoodsCellButton *cellButton_21;
    GoodsCellButton *cellButton_22;
    GoodsCellButton *cellButton_23;
    GoodsCellButton *cellButton_24;
    GoodsCellButton *cellButton_25;
    GoodsCellButton *cellButton_26;
    GoodsCellButton *cellButton_27;
    GoodsCellButton *cellButton_28;
    GoodsCellButton *cellButton_29;
    GoodsCellButton *cellButton_30;

    void setupUi(QWidget *GoodsWidget)
    {
        if (GoodsWidget->objectName().isEmpty())
            GoodsWidget->setObjectName(QStringLiteral("GoodsWidget"));
        GoodsWidget->resize(801, 464);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(1);
        GoodsWidget->setFont(font);
        GoodsWidget->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/saleImage/goods_btn_normal.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/goods_btn_press.png);\n"
"}"));
        gridLayout = new QGridLayout(GoodsWidget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cellButton_01 = new GoodsCellButton(GoodsWidget);
        cellButton_01->setObjectName(QStringLiteral("cellButton_01"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cellButton_01->sizePolicy().hasHeightForWidth());
        cellButton_01->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        cellButton_01->setFont(font1);
        cellButton_01->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_01, 0, 0, 1, 1);

        cellButton_02 = new GoodsCellButton(GoodsWidget);
        cellButton_02->setObjectName(QStringLiteral("cellButton_02"));
        sizePolicy.setHeightForWidth(cellButton_02->sizePolicy().hasHeightForWidth());
        cellButton_02->setSizePolicy(sizePolicy);
        cellButton_02->setFont(font1);
        cellButton_02->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_02, 0, 1, 1, 1);

        cellButton_03 = new GoodsCellButton(GoodsWidget);
        cellButton_03->setObjectName(QStringLiteral("cellButton_03"));
        sizePolicy.setHeightForWidth(cellButton_03->sizePolicy().hasHeightForWidth());
        cellButton_03->setSizePolicy(sizePolicy);
        cellButton_03->setFont(font1);
        cellButton_03->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_03, 0, 2, 1, 1);

        cellButton_04 = new GoodsCellButton(GoodsWidget);
        cellButton_04->setObjectName(QStringLiteral("cellButton_04"));
        sizePolicy.setHeightForWidth(cellButton_04->sizePolicy().hasHeightForWidth());
        cellButton_04->setSizePolicy(sizePolicy);
        cellButton_04->setFont(font1);
        cellButton_04->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_04, 0, 3, 1, 1);

        cellButton_05 = new GoodsCellButton(GoodsWidget);
        cellButton_05->setObjectName(QStringLiteral("cellButton_05"));
        sizePolicy.setHeightForWidth(cellButton_05->sizePolicy().hasHeightForWidth());
        cellButton_05->setSizePolicy(sizePolicy);
        cellButton_05->setFont(font1);
        cellButton_05->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_05, 0, 4, 1, 1);

        cellButton_06 = new GoodsCellButton(GoodsWidget);
        cellButton_06->setObjectName(QStringLiteral("cellButton_06"));
        sizePolicy.setHeightForWidth(cellButton_06->sizePolicy().hasHeightForWidth());
        cellButton_06->setSizePolicy(sizePolicy);
        cellButton_06->setFont(font1);
        cellButton_06->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_06, 0, 5, 1, 1);

        cellButton_07 = new GoodsCellButton(GoodsWidget);
        cellButton_07->setObjectName(QStringLiteral("cellButton_07"));
        sizePolicy.setHeightForWidth(cellButton_07->sizePolicy().hasHeightForWidth());
        cellButton_07->setSizePolicy(sizePolicy);
        cellButton_07->setFont(font1);
        cellButton_07->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_07, 1, 0, 1, 1);

        cellButton_08 = new GoodsCellButton(GoodsWidget);
        cellButton_08->setObjectName(QStringLiteral("cellButton_08"));
        sizePolicy.setHeightForWidth(cellButton_08->sizePolicy().hasHeightForWidth());
        cellButton_08->setSizePolicy(sizePolicy);
        cellButton_08->setFont(font1);
        cellButton_08->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_08, 1, 1, 1, 1);

        cellButton_09 = new GoodsCellButton(GoodsWidget);
        cellButton_09->setObjectName(QStringLiteral("cellButton_09"));
        sizePolicy.setHeightForWidth(cellButton_09->sizePolicy().hasHeightForWidth());
        cellButton_09->setSizePolicy(sizePolicy);
        cellButton_09->setFont(font1);
        cellButton_09->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_09, 1, 2, 1, 1);

        cellButton_10 = new GoodsCellButton(GoodsWidget);
        cellButton_10->setObjectName(QStringLiteral("cellButton_10"));
        sizePolicy.setHeightForWidth(cellButton_10->sizePolicy().hasHeightForWidth());
        cellButton_10->setSizePolicy(sizePolicy);
        cellButton_10->setFont(font1);
        cellButton_10->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_10, 1, 3, 1, 1);

        cellButton_11 = new GoodsCellButton(GoodsWidget);
        cellButton_11->setObjectName(QStringLiteral("cellButton_11"));
        sizePolicy.setHeightForWidth(cellButton_11->sizePolicy().hasHeightForWidth());
        cellButton_11->setSizePolicy(sizePolicy);
        cellButton_11->setFont(font1);
        cellButton_11->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_11, 1, 4, 1, 1);

        cellButton_12 = new GoodsCellButton(GoodsWidget);
        cellButton_12->setObjectName(QStringLiteral("cellButton_12"));
        sizePolicy.setHeightForWidth(cellButton_12->sizePolicy().hasHeightForWidth());
        cellButton_12->setSizePolicy(sizePolicy);
        cellButton_12->setFont(font1);
        cellButton_12->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_12, 1, 5, 1, 1);

        cellButton_13 = new GoodsCellButton(GoodsWidget);
        cellButton_13->setObjectName(QStringLiteral("cellButton_13"));
        sizePolicy.setHeightForWidth(cellButton_13->sizePolicy().hasHeightForWidth());
        cellButton_13->setSizePolicy(sizePolicy);
        cellButton_13->setFont(font1);
        cellButton_13->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_13, 2, 0, 1, 1);

        cellButton_14 = new GoodsCellButton(GoodsWidget);
        cellButton_14->setObjectName(QStringLiteral("cellButton_14"));
        sizePolicy.setHeightForWidth(cellButton_14->sizePolicy().hasHeightForWidth());
        cellButton_14->setSizePolicy(sizePolicy);
        cellButton_14->setFont(font1);
        cellButton_14->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_14, 2, 1, 1, 1);

        cellButton_15 = new GoodsCellButton(GoodsWidget);
        cellButton_15->setObjectName(QStringLiteral("cellButton_15"));
        sizePolicy.setHeightForWidth(cellButton_15->sizePolicy().hasHeightForWidth());
        cellButton_15->setSizePolicy(sizePolicy);
        cellButton_15->setFont(font1);
        cellButton_15->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_15, 2, 2, 1, 1);

        cellButton_16 = new GoodsCellButton(GoodsWidget);
        cellButton_16->setObjectName(QStringLiteral("cellButton_16"));
        sizePolicy.setHeightForWidth(cellButton_16->sizePolicy().hasHeightForWidth());
        cellButton_16->setSizePolicy(sizePolicy);
        cellButton_16->setFont(font1);
        cellButton_16->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_16, 2, 3, 1, 1);

        cellButton_17 = new GoodsCellButton(GoodsWidget);
        cellButton_17->setObjectName(QStringLiteral("cellButton_17"));
        sizePolicy.setHeightForWidth(cellButton_17->sizePolicy().hasHeightForWidth());
        cellButton_17->setSizePolicy(sizePolicy);
        cellButton_17->setFont(font1);
        cellButton_17->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_17, 2, 4, 1, 1);

        cellButton_18 = new GoodsCellButton(GoodsWidget);
        cellButton_18->setObjectName(QStringLiteral("cellButton_18"));
        sizePolicy.setHeightForWidth(cellButton_18->sizePolicy().hasHeightForWidth());
        cellButton_18->setSizePolicy(sizePolicy);
        cellButton_18->setFont(font1);
        cellButton_18->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_18, 2, 5, 1, 1);

        cellButton_19 = new GoodsCellButton(GoodsWidget);
        cellButton_19->setObjectName(QStringLiteral("cellButton_19"));
        sizePolicy.setHeightForWidth(cellButton_19->sizePolicy().hasHeightForWidth());
        cellButton_19->setSizePolicy(sizePolicy);
        cellButton_19->setFont(font1);
        cellButton_19->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_19, 3, 0, 1, 1);

        cellButton_20 = new GoodsCellButton(GoodsWidget);
        cellButton_20->setObjectName(QStringLiteral("cellButton_20"));
        sizePolicy.setHeightForWidth(cellButton_20->sizePolicy().hasHeightForWidth());
        cellButton_20->setSizePolicy(sizePolicy);
        cellButton_20->setFont(font1);
        cellButton_20->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_20, 3, 1, 1, 1);

        cellButton_21 = new GoodsCellButton(GoodsWidget);
        cellButton_21->setObjectName(QStringLiteral("cellButton_21"));
        sizePolicy.setHeightForWidth(cellButton_21->sizePolicy().hasHeightForWidth());
        cellButton_21->setSizePolicy(sizePolicy);
        cellButton_21->setFont(font1);
        cellButton_21->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_21, 3, 2, 1, 1);

        cellButton_22 = new GoodsCellButton(GoodsWidget);
        cellButton_22->setObjectName(QStringLiteral("cellButton_22"));
        sizePolicy.setHeightForWidth(cellButton_22->sizePolicy().hasHeightForWidth());
        cellButton_22->setSizePolicy(sizePolicy);
        cellButton_22->setFont(font1);
        cellButton_22->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_22, 3, 3, 1, 1);

        cellButton_23 = new GoodsCellButton(GoodsWidget);
        cellButton_23->setObjectName(QStringLiteral("cellButton_23"));
        sizePolicy.setHeightForWidth(cellButton_23->sizePolicy().hasHeightForWidth());
        cellButton_23->setSizePolicy(sizePolicy);
        cellButton_23->setFont(font1);
        cellButton_23->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_23, 3, 4, 1, 1);

        cellButton_24 = new GoodsCellButton(GoodsWidget);
        cellButton_24->setObjectName(QStringLiteral("cellButton_24"));
        sizePolicy.setHeightForWidth(cellButton_24->sizePolicy().hasHeightForWidth());
        cellButton_24->setSizePolicy(sizePolicy);
        cellButton_24->setFont(font1);
        cellButton_24->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_24, 3, 5, 1, 1);

        cellButton_25 = new GoodsCellButton(GoodsWidget);
        cellButton_25->setObjectName(QStringLiteral("cellButton_25"));
        sizePolicy.setHeightForWidth(cellButton_25->sizePolicy().hasHeightForWidth());
        cellButton_25->setSizePolicy(sizePolicy);
        cellButton_25->setFont(font1);
        cellButton_25->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_25, 4, 0, 1, 1);

        cellButton_26 = new GoodsCellButton(GoodsWidget);
        cellButton_26->setObjectName(QStringLiteral("cellButton_26"));
        sizePolicy.setHeightForWidth(cellButton_26->sizePolicy().hasHeightForWidth());
        cellButton_26->setSizePolicy(sizePolicy);
        cellButton_26->setFont(font1);
        cellButton_26->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_26, 4, 1, 1, 1);

        cellButton_27 = new GoodsCellButton(GoodsWidget);
        cellButton_27->setObjectName(QStringLiteral("cellButton_27"));
        sizePolicy.setHeightForWidth(cellButton_27->sizePolicy().hasHeightForWidth());
        cellButton_27->setSizePolicy(sizePolicy);
        cellButton_27->setFont(font1);
        cellButton_27->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_27, 4, 2, 1, 1);

        cellButton_28 = new GoodsCellButton(GoodsWidget);
        cellButton_28->setObjectName(QStringLiteral("cellButton_28"));
        sizePolicy.setHeightForWidth(cellButton_28->sizePolicy().hasHeightForWidth());
        cellButton_28->setSizePolicy(sizePolicy);
        cellButton_28->setFont(font1);
        cellButton_28->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_28, 4, 3, 1, 1);

        cellButton_29 = new GoodsCellButton(GoodsWidget);
        cellButton_29->setObjectName(QStringLiteral("cellButton_29"));
        sizePolicy.setHeightForWidth(cellButton_29->sizePolicy().hasHeightForWidth());
        cellButton_29->setSizePolicy(sizePolicy);
        cellButton_29->setFont(font1);
        cellButton_29->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_29, 4, 4, 1, 1);

        cellButton_30 = new GoodsCellButton(GoodsWidget);
        cellButton_30->setObjectName(QStringLiteral("cellButton_30"));
        sizePolicy.setHeightForWidth(cellButton_30->sizePolicy().hasHeightForWidth());
        cellButton_30->setSizePolicy(sizePolicy);
        cellButton_30->setFont(font1);
        cellButton_30->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(cellButton_30, 4, 5, 1, 1);


        retranslateUi(GoodsWidget);

        QMetaObject::connectSlotsByName(GoodsWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodsWidget)
    {
        GoodsWidget->setWindowTitle(QApplication::translate("GoodsWidget", "GoodsWidget", Q_NULLPTR));
        cellButton_01->setText(QString());
        cellButton_02->setText(QString());
        cellButton_03->setText(QString());
        cellButton_04->setText(QString());
        cellButton_05->setText(QString());
        cellButton_06->setText(QString());
        cellButton_07->setText(QString());
        cellButton_08->setText(QString());
        cellButton_09->setText(QString());
        cellButton_10->setText(QString());
        cellButton_11->setText(QString());
        cellButton_12->setText(QString());
        cellButton_13->setText(QString());
        cellButton_14->setText(QString());
        cellButton_15->setText(QString());
        cellButton_16->setText(QString());
        cellButton_17->setText(QString());
        cellButton_18->setText(QString());
        cellButton_19->setText(QString());
        cellButton_20->setText(QString());
        cellButton_21->setText(QString());
        cellButton_22->setText(QString());
        cellButton_23->setText(QString());
        cellButton_24->setText(QString());
        cellButton_25->setText(QString());
        cellButton_26->setText(QString());
        cellButton_27->setText(QString());
        cellButton_28->setText(QString());
        cellButton_29->setText(QString());
        cellButton_30->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GoodsWidget: public Ui_GoodsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSWIDGET_H
