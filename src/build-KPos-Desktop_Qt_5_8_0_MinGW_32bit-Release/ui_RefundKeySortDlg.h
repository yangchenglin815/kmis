/********************************************************************************
** Form generated from reading UI file 'RefundKeySortDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFUNDKEYSORTDLG_H
#define UI_REFUNDKEYSORTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RefundKeySortDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget;
    QPushButton *key1Button;
    QPushButton *key2Button;
    QPushButton *key3Button;

    void setupUi(QDialog *RefundKeySortDlg)
    {
        if (RefundKeySortDlg->objectName().isEmpty())
            RefundKeySortDlg->setObjectName(QStringLiteral("RefundKeySortDlg"));
        RefundKeySortDlg->resize(434, 164);
        RefundKeySortDlg->setStyleSheet(QStringLiteral("background-color: rgb(81, 80, 80);"));
        verticalLayout = new QVBoxLayout(RefundKeySortDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(RefundKeySortDlg);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 30));
        label->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        widget = new QWidget(RefundKeySortDlg);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setFont(font);
        widget->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/setImage/dlg_btn_normal.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(:/setImage/dlg_btn_press.png);\n"
"}"));
        key1Button = new QPushButton(widget);
        key1Button->setObjectName(QStringLiteral("key1Button"));
        key1Button->setGeometry(QRect(13, 9, 77, 44));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(key1Button->sizePolicy().hasHeightForWidth());
        key1Button->setSizePolicy(sizePolicy1);
        key1Button->setFont(font);
        key1Button->setStyleSheet(QStringLiteral(""));
        key2Button = new QPushButton(widget);
        key2Button->setObjectName(QStringLiteral("key2Button"));
        key2Button->setGeometry(QRect(96, 9, 77, 44));
        sizePolicy1.setHeightForWidth(key2Button->sizePolicy().hasHeightForWidth());
        key2Button->setSizePolicy(sizePolicy1);
        key2Button->setFont(font);
        key2Button->setStyleSheet(QStringLiteral(""));
        key3Button = new QPushButton(widget);
        key3Button->setObjectName(QStringLiteral("key3Button"));
        key3Button->setGeometry(QRect(179, 9, 77, 44));
        sizePolicy1.setHeightForWidth(key3Button->sizePolicy().hasHeightForWidth());
        key3Button->setSizePolicy(sizePolicy1);
        key3Button->setFont(font);
        key3Button->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(widget);


        retranslateUi(RefundKeySortDlg);

        QMetaObject::connectSlotsByName(RefundKeySortDlg);
    } // setupUi

    void retranslateUi(QDialog *RefundKeySortDlg)
    {
        RefundKeySortDlg->setWindowTitle(QApplication::translate("RefundKeySortDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("RefundKeySortDlg", "\350\257\267\351\200\211\346\213\251\346\214\211\351\224\256\347\232\204\344\275\215\347\275\256\346\216\222\345\272\217", Q_NULLPTR));
        key1Button->setText(QApplication::translate("RefundKeySortDlg", "\351\200\200\350\264\247", Q_NULLPTR));
        key2Button->setText(QApplication::translate("RefundKeySortDlg", "\346\225\264\345\215\225\351\200\200\350\264\247", Q_NULLPTR));
        key3Button->setText(QApplication::translate("RefundKeySortDlg", "\344\277\256\346\224\271\346\225\260\351\207\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RefundKeySortDlg: public Ui_RefundKeySortDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFUNDKEYSORTDLG_H
