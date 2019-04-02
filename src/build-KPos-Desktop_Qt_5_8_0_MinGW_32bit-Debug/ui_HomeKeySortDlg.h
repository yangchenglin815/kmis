/********************************************************************************
** Form generated from reading UI file 'HomeKeySortDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEKEYSORTDLG_H
#define UI_HOMEKEYSORTDLG_H

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

class Ui_HomeKeySortDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget;
    QPushButton *key3Button;
    QPushButton *key2Button;
    QPushButton *key5Button;
    QPushButton *key4Button;
    QPushButton *key1Button;
    QPushButton *key12Button;
    QPushButton *key11Button;
    QPushButton *key10Button;
    QPushButton *key9Button;
    QPushButton *key8Button;
    QPushButton *key7Button;
    QPushButton *key6Button;
    QPushButton *key13Button;

    void setupUi(QDialog *HomeKeySortDlg)
    {
        if (HomeKeySortDlg->objectName().isEmpty())
            HomeKeySortDlg->setObjectName(QStringLiteral("HomeKeySortDlg"));
        HomeKeySortDlg->resize(434, 220);
        HomeKeySortDlg->setStyleSheet(QStringLiteral("background-color: #505050;"));
        verticalLayout = new QVBoxLayout(HomeKeySortDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(HomeKeySortDlg);
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

        widget = new QWidget(HomeKeySortDlg);
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
        key3Button = new QPushButton(widget);
        key3Button->setObjectName(QStringLiteral("key3Button"));
        key3Button->setGeometry(QRect(179, 9, 77, 44));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(key3Button->sizePolicy().hasHeightForWidth());
        key3Button->setSizePolicy(sizePolicy1);
        key3Button->setFont(font);
        key3Button->setStyleSheet(QStringLiteral(""));
        key2Button = new QPushButton(widget);
        key2Button->setObjectName(QStringLiteral("key2Button"));
        key2Button->setGeometry(QRect(96, 9, 77, 44));
        sizePolicy1.setHeightForWidth(key2Button->sizePolicy().hasHeightForWidth());
        key2Button->setSizePolicy(sizePolicy1);
        key2Button->setFont(font);
        key2Button->setStyleSheet(QStringLiteral(""));
        key5Button = new QPushButton(widget);
        key5Button->setObjectName(QStringLiteral("key5Button"));
        key5Button->setGeometry(QRect(344, 9, 77, 44));
        sizePolicy1.setHeightForWidth(key5Button->sizePolicy().hasHeightForWidth());
        key5Button->setSizePolicy(sizePolicy1);
        key5Button->setFont(font);
        key5Button->setStyleSheet(QStringLiteral(""));
        key4Button = new QPushButton(widget);
        key4Button->setObjectName(QStringLiteral("key4Button"));
        key4Button->setGeometry(QRect(261, 9, 77, 44));
        sizePolicy1.setHeightForWidth(key4Button->sizePolicy().hasHeightForWidth());
        key4Button->setSizePolicy(sizePolicy1);
        key4Button->setFont(font);
        key4Button->setStyleSheet(QStringLiteral(""));
        key1Button = new QPushButton(widget);
        key1Button->setObjectName(QStringLiteral("key1Button"));
        key1Button->setGeometry(QRect(13, 9, 77, 44));
        sizePolicy1.setHeightForWidth(key1Button->sizePolicy().hasHeightForWidth());
        key1Button->setSizePolicy(sizePolicy1);
        key1Button->setFont(font);
        key1Button->setStyleSheet(QStringLiteral(""));
        key12Button = new QPushButton(widget);
        key12Button->setObjectName(QStringLiteral("key12Button"));
        key12Button->setGeometry(QRect(96, 126, 77, 44));
        sizePolicy1.setHeightForWidth(key12Button->sizePolicy().hasHeightForWidth());
        key12Button->setSizePolicy(sizePolicy1);
        key12Button->setFont(font);
        key12Button->setStyleSheet(QStringLiteral(""));
        key11Button = new QPushButton(widget);
        key11Button->setObjectName(QStringLiteral("key11Button"));
        key11Button->setGeometry(QRect(13, 126, 77, 44));
        sizePolicy1.setHeightForWidth(key11Button->sizePolicy().hasHeightForWidth());
        key11Button->setSizePolicy(sizePolicy1);
        key11Button->setFont(font);
        key11Button->setStyleSheet(QStringLiteral(""));
        key10Button = new QPushButton(widget);
        key10Button->setObjectName(QStringLiteral("key10Button"));
        key10Button->setGeometry(QRect(344, 67, 77, 44));
        sizePolicy1.setHeightForWidth(key10Button->sizePolicy().hasHeightForWidth());
        key10Button->setSizePolicy(sizePolicy1);
        key10Button->setFont(font);
        key10Button->setStyleSheet(QStringLiteral(""));
        key9Button = new QPushButton(widget);
        key9Button->setObjectName(QStringLiteral("key9Button"));
        key9Button->setGeometry(QRect(261, 67, 77, 44));
        sizePolicy1.setHeightForWidth(key9Button->sizePolicy().hasHeightForWidth());
        key9Button->setSizePolicy(sizePolicy1);
        key9Button->setFont(font);
        key9Button->setStyleSheet(QStringLiteral(""));
        key8Button = new QPushButton(widget);
        key8Button->setObjectName(QStringLiteral("key8Button"));
        key8Button->setGeometry(QRect(179, 67, 77, 44));
        sizePolicy1.setHeightForWidth(key8Button->sizePolicy().hasHeightForWidth());
        key8Button->setSizePolicy(sizePolicy1);
        key8Button->setFont(font);
        key8Button->setStyleSheet(QStringLiteral(""));
        key7Button = new QPushButton(widget);
        key7Button->setObjectName(QStringLiteral("key7Button"));
        key7Button->setGeometry(QRect(96, 67, 77, 44));
        sizePolicy1.setHeightForWidth(key7Button->sizePolicy().hasHeightForWidth());
        key7Button->setSizePolicy(sizePolicy1);
        key7Button->setFont(font);
        key7Button->setStyleSheet(QStringLiteral(""));
        key6Button = new QPushButton(widget);
        key6Button->setObjectName(QStringLiteral("key6Button"));
        key6Button->setGeometry(QRect(13, 67, 77, 44));
        sizePolicy1.setHeightForWidth(key6Button->sizePolicy().hasHeightForWidth());
        key6Button->setSizePolicy(sizePolicy1);
        key6Button->setFont(font);
        key6Button->setStyleSheet(QStringLiteral(""));
        key13Button = new QPushButton(widget);
        key13Button->setObjectName(QStringLiteral("key13Button"));
        key13Button->setGeometry(QRect(180, 127, 77, 44));
        sizePolicy1.setHeightForWidth(key13Button->sizePolicy().hasHeightForWidth());
        key13Button->setSizePolicy(sizePolicy1);
        key13Button->setFont(font);
        key13Button->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(widget);


        retranslateUi(HomeKeySortDlg);

        QMetaObject::connectSlotsByName(HomeKeySortDlg);
    } // setupUi

    void retranslateUi(QDialog *HomeKeySortDlg)
    {
        HomeKeySortDlg->setWindowTitle(QApplication::translate("HomeKeySortDlg", "HomeKeySortDlg", Q_NULLPTR));
        label->setText(QApplication::translate("HomeKeySortDlg", "\350\257\267\351\200\211\346\213\251\346\214\211\351\224\256\347\232\204\344\275\215\347\275\256\346\216\222\345\272\217", Q_NULLPTR));
        key3Button->setText(QApplication::translate("HomeKeySortDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        key2Button->setText(QApplication::translate("HomeKeySortDlg", "\346\214\202\345\215\225", Q_NULLPTR));
        key5Button->setText(QApplication::translate("HomeKeySortDlg", "\346\212\230\346\211\243", Q_NULLPTR));
        key4Button->setText(QApplication::translate("HomeKeySortDlg", "\346\225\264\345\217\226", Q_NULLPTR));
        key1Button->setText(QApplication::translate("HomeKeySortDlg", "\344\274\232\345\221\230", Q_NULLPTR));
        key12Button->setText(QApplication::translate("HomeKeySortDlg", "\344\277\256\346\224\271\346\225\260\351\207\217", Q_NULLPTR));
        key11Button->setText(QApplication::translate("HomeKeySortDlg", "\351\200\200\350\264\247", Q_NULLPTR));
        key10Button->setText(QApplication::translate("HomeKeySortDlg", "\351\222\261\347\256\261", Q_NULLPTR));
        key9Button->setText(QApplication::translate("HomeKeySortDlg", "\346\225\264\345\215\225\346\212\230\346\211\243", Q_NULLPTR));
        key8Button->setText(QApplication::translate("HomeKeySortDlg", "\346\270\205\351\233\266", Q_NULLPTR));
        key7Button->setText(QApplication::translate("HomeKeySortDlg", "\345\277\253\351\200\237\345\273\272\346\241\243", Q_NULLPTR));
        key6Button->setText(QApplication::translate("HomeKeySortDlg", "\344\270\212\345\274\240\345\260\217\347\245\250", Q_NULLPTR));
        key13Button->setText(QApplication::translate("HomeKeySortDlg", "\351\224\201\345\261\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomeKeySortDlg: public Ui_HomeKeySortDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEKEYSORTDLG_H
