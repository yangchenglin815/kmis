/********************************************************************************
** Form generated from reading UI file 'GoodsSetPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSSETPAGE_H
#define UI_GOODSSETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "CategoryWidget.h"
#include "GoodsWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GoodsSetPage
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *skinWidget;
    CategoryWidget *categoryWidget;
    QLabel *categorySetLabel;
    QLabel *goodsSetLabel;
    GoodsWidget *goodsWidget;
    QPushButton *goodsNextButton;
    QPushButton *goodsFrontButton;
    QPushButton *categoryNextButton;
    QPushButton *categoryFrontButton;
    QPushButton *newCategoryButton;

    void setupUi(QWidget *GoodsSetPage)
    {
        if (GoodsSetPage->objectName().isEmpty())
            GoodsSetPage->setObjectName(QStringLiteral("GoodsSetPage"));
        GoodsSetPage->resize(562, 501);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GoodsSetPage->sizePolicy().hasHeightForWidth());
        GoodsSetPage->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(GoodsSetPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        skinWidget = new QWidget(GoodsSetPage);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        categoryWidget = new CategoryWidget(skinWidget);
        categoryWidget->setObjectName(QStringLiteral("categoryWidget"));
        categoryWidget->setGeometry(QRect(82, 11, 406, 111));
        categoryWidget->setMinimumSize(QSize(406, 111));
        categoryWidget->setMaximumSize(QSize(16777215, 16777215));
        categorySetLabel = new QLabel(skinWidget);
        categorySetLabel->setObjectName(QStringLiteral("categorySetLabel"));
        categorySetLabel->setGeometry(QRect(11, 11, 65, 19));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(categorySetLabel->sizePolicy().hasHeightForWidth());
        categorySetLabel->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        categorySetLabel->setFont(font);
        categorySetLabel->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        goodsSetLabel = new QLabel(skinWidget);
        goodsSetLabel->setObjectName(QStringLiteral("goodsSetLabel"));
        goodsSetLabel->setGeometry(QRect(11, 130, 65, 19));
        sizePolicy1.setHeightForWidth(goodsSetLabel->sizePolicy().hasHeightForWidth());
        goodsSetLabel->setSizePolicy(sizePolicy1);
        goodsSetLabel->setFont(font);
        goodsSetLabel->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        goodsWidget = new GoodsWidget(skinWidget);
        goodsWidget->setObjectName(QStringLiteral("goodsWidget"));
        goodsWidget->setGeometry(QRect(82, 130, 406, 360));
        goodsWidget->setMinimumSize(QSize(406, 360));
        goodsNextButton = new QPushButton(skinWidget);
        goodsNextButton->setObjectName(QStringLiteral("goodsNextButton"));
        goodsNextButton->setEnabled(true);
        goodsNextButton->setGeometry(QRect(500, 250, 55, 55));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(goodsNextButton->sizePolicy().hasHeightForWidth());
        goodsNextButton->setSizePolicy(sizePolicy2);
        goodsNextButton->setMinimumSize(QSize(55, 55));
        goodsNextButton->setMaximumSize(QSize(16777215, 16777215));
        goodsNextButton->setSizeIncrement(QSize(55, 55));
        goodsNextButton->setBaseSize(QSize(55, 55));
        goodsNextButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	font-size:12px;\n"
"	color:#ffffff;\n"
"	padding-top:20px;\n"
"	border-image: url(:/saleImage/goods_down.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/goods_down_press.png);\n"
"}"));
        goodsFrontButton = new QPushButton(skinWidget);
        goodsFrontButton->setObjectName(QStringLiteral("goodsFrontButton"));
        goodsFrontButton->setEnabled(true);
        goodsFrontButton->setGeometry(QRect(500, 189, 55, 55));
        sizePolicy2.setHeightForWidth(goodsFrontButton->sizePolicy().hasHeightForWidth());
        goodsFrontButton->setSizePolicy(sizePolicy2);
        goodsFrontButton->setMinimumSize(QSize(55, 55));
        goodsFrontButton->setMaximumSize(QSize(16777215, 16777215));
        goodsFrontButton->setSizeIncrement(QSize(55, 55));
        goodsFrontButton->setBaseSize(QSize(55, 55));
        goodsFrontButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/goods_up.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/goods_up_press.png);\n"
"}"));
        categoryNextButton = new QPushButton(skinWidget);
        categoryNextButton->setObjectName(QStringLiteral("categoryNextButton"));
        categoryNextButton->setEnabled(true);
        categoryNextButton->setGeometry(QRect(500, 128, 55, 55));
        sizePolicy2.setHeightForWidth(categoryNextButton->sizePolicy().hasHeightForWidth());
        categoryNextButton->setSizePolicy(sizePolicy2);
        categoryNextButton->setMinimumSize(QSize(55, 55));
        categoryNextButton->setMaximumSize(QSize(16777215, 16777215));
        categoryNextButton->setSizeIncrement(QSize(55, 55));
        categoryNextButton->setBaseSize(QSize(55, 55));
        categoryNextButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	font-size:12px;\n"
"	color:#ffffff;\n"
"	padding-top:20px;\n"
"	border-image: url(:/saleImage/category_down.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/saleImage/category_down_press.png);\n"
"}"));
        categoryFrontButton = new QPushButton(skinWidget);
        categoryFrontButton->setObjectName(QStringLiteral("categoryFrontButton"));
        categoryFrontButton->setEnabled(true);
        categoryFrontButton->setGeometry(QRect(500, 70, 55, 55));
        sizePolicy2.setHeightForWidth(categoryFrontButton->sizePolicy().hasHeightForWidth());
        categoryFrontButton->setSizePolicy(sizePolicy2);
        categoryFrontButton->setMinimumSize(QSize(55, 55));
        categoryFrontButton->setMaximumSize(QSize(16777215, 16777215));
        categoryFrontButton->setSizeIncrement(QSize(55, 55));
        categoryFrontButton->setBaseSize(QSize(55, 55));
        categoryFrontButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/category_up.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	border-image: url(:/saleImage/category_up_press.png);\n"
"}"));
        newCategoryButton = new QPushButton(skinWidget);
        newCategoryButton->setObjectName(QStringLiteral("newCategoryButton"));
        newCategoryButton->setEnabled(true);
        newCategoryButton->setGeometry(QRect(500, 10, 55, 55));
        sizePolicy2.setHeightForWidth(newCategoryButton->sizePolicy().hasHeightForWidth());
        newCategoryButton->setSizePolicy(sizePolicy2);
        newCategoryButton->setMinimumSize(QSize(55, 55));
        newCategoryButton->setMaximumSize(QSize(16777215, 16777215));
        newCategoryButton->setSizeIncrement(QSize(55, 55));
        newCategoryButton->setBaseSize(QSize(55, 55));
        QFont font1;
        font1.setPointSize(10);
        newCategoryButton->setFont(font1);
        newCategoryButton->setStyleSheet(QLatin1String("QPushButton#newCategoryButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/setImage/add_category_normal.png);\n"
"}\n"
"\n"
"QPushButton#newCategoryButton:pressed {\n"
"	border-image: url(:/setImage/add_category_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(skinWidget);


        retranslateUi(GoodsSetPage);

        QMetaObject::connectSlotsByName(GoodsSetPage);
    } // setupUi

    void retranslateUi(QWidget *GoodsSetPage)
    {
        GoodsSetPage->setWindowTitle(QApplication::translate("GoodsSetPage", "Form", Q_NULLPTR));
        categorySetLabel->setText(QApplication::translate("GoodsSetPage", "\345\210\206\347\261\273\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        goodsSetLabel->setText(QApplication::translate("GoodsSetPage", "\345\225\206\345\223\201\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        goodsNextButton->setText(QApplication::translate("GoodsSetPage", "1/12\351\241\265", Q_NULLPTR));
        goodsFrontButton->setText(QString());
        categoryNextButton->setText(QApplication::translate("GoodsSetPage", "1/12\351\241\265", Q_NULLPTR));
        categoryFrontButton->setText(QString());
        newCategoryButton->setText(QApplication::translate("GoodsSetPage", "\346\267\273\345\212\240\n"
"\345\210\206\347\261\273", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GoodsSetPage: public Ui_GoodsSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSSETPAGE_H
