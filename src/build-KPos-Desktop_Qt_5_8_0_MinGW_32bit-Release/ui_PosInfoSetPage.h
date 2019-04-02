/********************************************************************************
** Form generated from reading UI file 'PosInfoSetPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSINFOSETPAGE_H
#define UI_POSINFOSETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "KPosComboBox.h"
#include "SKinSetCellButton.h"

QT_BEGIN_NAMESPACE

class Ui_PosInfoSetPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *skinWidget;
    QLabel *smartLabel;
    QLabel *skinSetLabel;
    QLabel *flatSkinLabel;
    QLabel *balckSkinLabel;
    SKinSetCellButton *balckSkinButton;
    SKinSetCellButton *flatSkinButton;
    SKinSetCellButton *smartButton;
    QLabel *posModelLabel;
    QLabel *posCodeLabel;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *shopNameLabel;
    QLabel *shopCodeLabel;
    QLabel *label_4;
    QLabel *curVersionLabel;
    QLabel *label_2;
    QPushButton *posTestButton;
    KPosComboBox *posModelComBox;

    void setupUi(QWidget *PosInfoSetPage)
    {
        if (PosInfoSetPage->objectName().isEmpty())
            PosInfoSetPage->setObjectName(QStringLiteral("PosInfoSetPage"));
        PosInfoSetPage->resize(607, 513);
        PosInfoSetPage->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(PosInfoSetPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        skinWidget = new QWidget(PosInfoSetPage);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        smartLabel = new QLabel(skinWidget);
        smartLabel->setObjectName(QStringLiteral("smartLabel"));
        smartLabel->setGeometry(QRect(360, 290, 94, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        smartLabel->setFont(font);
        smartLabel->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        smartLabel->setAlignment(Qt::AlignCenter);
        skinSetLabel = new QLabel(skinWidget);
        skinSetLabel->setObjectName(QStringLiteral("skinSetLabel"));
        skinSetLabel->setGeometry(QRect(0, 234, 102, 20));
        skinSetLabel->setMinimumSize(QSize(102, 20));
        skinSetLabel->setMaximumSize(QSize(102, 20));
        skinSetLabel->setFont(font);
        skinSetLabel->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        skinSetLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        flatSkinLabel = new QLabel(skinWidget);
        flatSkinLabel->setObjectName(QStringLiteral("flatSkinLabel"));
        flatSkinLabel->setGeometry(QRect(240, 290, 94, 20));
        flatSkinLabel->setFont(font);
        flatSkinLabel->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        flatSkinLabel->setAlignment(Qt::AlignCenter);
        balckSkinLabel = new QLabel(skinWidget);
        balckSkinLabel->setObjectName(QStringLiteral("balckSkinLabel"));
        balckSkinLabel->setGeometry(QRect(120, 290, 94, 20));
        balckSkinLabel->setFont(font);
        balckSkinLabel->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        balckSkinLabel->setAlignment(Qt::AlignCenter);
        balckSkinButton = new SKinSetCellButton(skinWidget);
        balckSkinButton->setObjectName(QStringLiteral("balckSkinButton"));
        balckSkinButton->setGeometry(QRect(120, 230, 94, 54));
        flatSkinButton = new SKinSetCellButton(skinWidget);
        flatSkinButton->setObjectName(QStringLiteral("flatSkinButton"));
        flatSkinButton->setGeometry(QRect(240, 230, 94, 54));
        smartButton = new SKinSetCellButton(skinWidget);
        smartButton->setObjectName(QStringLiteral("smartButton"));
        smartButton->setGeometry(QRect(360, 230, 94, 54));
        posModelLabel = new QLabel(skinWidget);
        posModelLabel->setObjectName(QStringLiteral("posModelLabel"));
        posModelLabel->setGeometry(QRect(0, 194, 102, 20));
        posModelLabel->setMinimumSize(QSize(102, 20));
        posModelLabel->setMaximumSize(QSize(102, 20));
        posModelLabel->setFont(font);
        posModelLabel->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        posModelLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        posCodeLabel = new QLabel(skinWidget);
        posCodeLabel->setObjectName(QStringLiteral("posCodeLabel"));
        posCodeLabel->setGeometry(QRect(120, 154, 300, 20));
        posCodeLabel->setFont(font);
        posCodeLabel->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        label_6 = new QLabel(skinWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 154, 102, 20));
        label_6->setMinimumSize(QSize(102, 20));
        label_6->setMaximumSize(QSize(102, 20));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(skinWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 114, 102, 20));
        label_5->setMinimumSize(QSize(102, 20));
        label_5->setMaximumSize(QSize(102, 20));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        shopNameLabel = new QLabel(skinWidget);
        shopNameLabel->setObjectName(QStringLiteral("shopNameLabel"));
        shopNameLabel->setGeometry(QRect(120, 114, 300, 20));
        shopNameLabel->setFont(font);
        shopNameLabel->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        shopCodeLabel = new QLabel(skinWidget);
        shopCodeLabel->setObjectName(QStringLiteral("shopCodeLabel"));
        shopCodeLabel->setGeometry(QRect(120, 74, 300, 20));
        shopCodeLabel->setFont(font);
        shopCodeLabel->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        label_4 = new QLabel(skinWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 74, 102, 20));
        label_4->setMinimumSize(QSize(102, 20));
        label_4->setMaximumSize(QSize(102, 20));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        curVersionLabel = new QLabel(skinWidget);
        curVersionLabel->setObjectName(QStringLiteral("curVersionLabel"));
        curVersionLabel->setGeometry(QRect(120, 34, 300, 20));
        curVersionLabel->setFont(font);
        curVersionLabel->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        label_2 = new QLabel(skinWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 34, 102, 20));
        label_2->setMinimumSize(QSize(102, 20));
        label_2->setMaximumSize(QSize(102, 20));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        posTestButton = new QPushButton(skinWidget);
        posTestButton->setObjectName(QStringLiteral("posTestButton"));
        posTestButton->setGeometry(QRect(310, 190, 90, 30));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(posTestButton->sizePolicy().hasHeightForWidth());
        posTestButton->setSizePolicy(sizePolicy);
        posTestButton->setFont(font);
        posTestButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/kPosSetImage/buttonNormal.png);\n"
"color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/kPosSetImage/buttonPressed.png);\n"
"}"));
        posModelComBox = new KPosComboBox(skinWidget);
        posModelComBox->setObjectName(QStringLiteral("posModelComBox"));
        posModelComBox->setGeometry(QRect(120, 190, 190, 30));

        verticalLayout->addWidget(skinWidget);


        retranslateUi(PosInfoSetPage);

        QMetaObject::connectSlotsByName(PosInfoSetPage);
    } // setupUi

    void retranslateUi(QWidget *PosInfoSetPage)
    {
        PosInfoSetPage->setWindowTitle(QApplication::translate("PosInfoSetPage", "Form", Q_NULLPTR));
        smartLabel->setText(QApplication::translate("PosInfoSetPage", "\346\231\272\350\203\275\347\211\210", Q_NULLPTR));
        skinSetLabel->setText(QApplication::translate("PosInfoSetPage", "\347\232\256\350\202\244\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        flatSkinLabel->setText(QApplication::translate("PosInfoSetPage", "\346\211\201\345\271\263\347\211\210", Q_NULLPTR));
        balckSkinLabel->setText(QApplication::translate("PosInfoSetPage", "\351\273\221\350\211\262\347\211\210", Q_NULLPTR));
        balckSkinButton->setText(QString());
        flatSkinButton->setText(QString());
        smartButton->setText(QString());
        posModelLabel->setText(QApplication::translate("PosInfoSetPage", "POS\346\234\272\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        posCodeLabel->setText(QApplication::translate("PosInfoSetPage", "28888824656", Q_NULLPTR));
        label_6->setText(QApplication::translate("PosInfoSetPage", "POS\346\234\272\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("PosInfoSetPage", "\351\227\250\345\272\227\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        shopNameLabel->setText(QApplication::translate("PosInfoSetPage", "\351\253\230\346\226\260\345\216\237\345\272\227", Q_NULLPTR));
        shopCodeLabel->setText(QApplication::translate("PosInfoSetPage", "23355568", Q_NULLPTR));
        label_4->setText(QApplication::translate("PosInfoSetPage", "\351\227\250\345\272\227\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        curVersionLabel->setText(QApplication::translate("PosInfoSetPage", "POS-1.2", Q_NULLPTR));
        label_2->setText(QApplication::translate("PosInfoSetPage", "\345\275\223\345\211\215\347\211\210\346\234\254\357\274\232", Q_NULLPTR));
        posTestButton->setText(QApplication::translate("PosInfoSetPage", "\346\265\213\350\257\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PosInfoSetPage: public Ui_PosInfoSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSINFOSETPAGE_H
