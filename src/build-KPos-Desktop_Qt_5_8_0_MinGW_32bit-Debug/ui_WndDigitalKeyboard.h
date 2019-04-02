/********************************************************************************
** Form generated from reading UI file 'WndDigitalKeyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WNDDIGITALKEYBOARD_H
#define UI_WNDDIGITALKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WndDigitalKeyboard
{
public:
    QGridLayout *gridLayout;
    QPushButton *num9Button;
    QPushButton *dotButton;
    QPushButton *num8Button;
    QPushButton *confirmButton;
    QPushButton *num0Button;
    QPushButton *num7Button;
    QPushButton *num4Button;
    QPushButton *deleteButton;
    QPushButton *num5Button;
    QPushButton *clearButton;
    QPushButton *num6Button;
    QPushButton *num1Button;
    QPushButton *num2Button;
    QPushButton *num3Button;
    QPushButton *num00Button;

    void setupUi(QWidget *WndDigitalKeyboard)
    {
        if (WndDigitalKeyboard->objectName().isEmpty())
            WndDigitalKeyboard->setObjectName(QStringLiteral("WndDigitalKeyboard"));
        WndDigitalKeyboard->resize(230, 230);
        QFont font;
        WndDigitalKeyboard->setFont(font);
        WndDigitalKeyboard->setStyleSheet(QLatin1String("font-size:24px;\n"
"color: rgb(134, 134, 134);"));
        gridLayout = new QGridLayout(WndDigitalKeyboard);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        num9Button = new QPushButton(WndDigitalKeyboard);
        num9Button->setObjectName(QStringLiteral("num9Button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(num9Button->sizePolicy().hasHeightForWidth());
        num9Button->setSizePolicy(sizePolicy);
        num9Button->setMinimumSize(QSize(50, 50));
        num9Button->setMaximumSize(QSize(100, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        num9Button->setFont(font1);
        num9Button->setFocusPolicy(Qt::NoFocus);
        num9Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num9Button, 2, 2, 1, 1);

        dotButton = new QPushButton(WndDigitalKeyboard);
        dotButton->setObjectName(QStringLiteral("dotButton"));
        sizePolicy.setHeightForWidth(dotButton->sizePolicy().hasHeightForWidth());
        dotButton->setSizePolicy(sizePolicy);
        dotButton->setMinimumSize(QSize(50, 50));
        dotButton->setMaximumSize(QSize(100, 100));
        dotButton->setFont(font1);
        dotButton->setFocusPolicy(Qt::NoFocus);
        dotButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(dotButton, 3, 0, 1, 1);

        num8Button = new QPushButton(WndDigitalKeyboard);
        num8Button->setObjectName(QStringLiteral("num8Button"));
        sizePolicy.setHeightForWidth(num8Button->sizePolicy().hasHeightForWidth());
        num8Button->setSizePolicy(sizePolicy);
        num8Button->setMinimumSize(QSize(50, 50));
        num8Button->setMaximumSize(QSize(100, 100));
        num8Button->setFont(font1);
        num8Button->setFocusPolicy(Qt::NoFocus);
        num8Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num8Button, 2, 1, 1, 1);

        confirmButton = new QPushButton(WndDigitalKeyboard);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        sizePolicy.setHeightForWidth(confirmButton->sizePolicy().hasHeightForWidth());
        confirmButton->setSizePolicy(sizePolicy);
        confirmButton->setMinimumSize(QSize(50, 50));
        confirmButton->setMaximumSize(QSize(100, 16777215));
        confirmButton->setFont(font1);
        confirmButton->setFocusPolicy(Qt::NoFocus);
        confirmButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/confirm.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/confirm_pressed.png);\n"
"}"));

        gridLayout->addWidget(confirmButton, 2, 3, 2, 1);

        num0Button = new QPushButton(WndDigitalKeyboard);
        num0Button->setObjectName(QStringLiteral("num0Button"));
        sizePolicy.setHeightForWidth(num0Button->sizePolicy().hasHeightForWidth());
        num0Button->setSizePolicy(sizePolicy);
        num0Button->setMinimumSize(QSize(50, 50));
        num0Button->setMaximumSize(QSize(100, 100));
        num0Button->setFont(font1);
        num0Button->setFocusPolicy(Qt::NoFocus);
        num0Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num0Button, 3, 1, 1, 1);

        num7Button = new QPushButton(WndDigitalKeyboard);
        num7Button->setObjectName(QStringLiteral("num7Button"));
        sizePolicy.setHeightForWidth(num7Button->sizePolicy().hasHeightForWidth());
        num7Button->setSizePolicy(sizePolicy);
        num7Button->setMinimumSize(QSize(50, 50));
        num7Button->setMaximumSize(QSize(100, 100));
        num7Button->setFont(font1);
        num7Button->setFocusPolicy(Qt::NoFocus);
        num7Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num7Button, 2, 0, 1, 1);

        num4Button = new QPushButton(WndDigitalKeyboard);
        num4Button->setObjectName(QStringLiteral("num4Button"));
        sizePolicy.setHeightForWidth(num4Button->sizePolicy().hasHeightForWidth());
        num4Button->setSizePolicy(sizePolicy);
        num4Button->setMinimumSize(QSize(50, 50));
        num4Button->setMaximumSize(QSize(100, 100));
        num4Button->setFont(font1);
        num4Button->setFocusPolicy(Qt::NoFocus);
        num4Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num4Button, 1, 0, 1, 1);

        deleteButton = new QPushButton(WndDigitalKeyboard);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setMinimumSize(QSize(50, 50));
        deleteButton->setMaximumSize(QSize(100, 100));
        deleteButton->setFont(font1);
        deleteButton->setFocusPolicy(Qt::NoFocus);
        deleteButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/delete.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/delete_pressed.png);\n"
"}"));

        gridLayout->addWidget(deleteButton, 0, 3, 1, 1);

        num5Button = new QPushButton(WndDigitalKeyboard);
        num5Button->setObjectName(QStringLiteral("num5Button"));
        sizePolicy.setHeightForWidth(num5Button->sizePolicy().hasHeightForWidth());
        num5Button->setSizePolicy(sizePolicy);
        num5Button->setMinimumSize(QSize(50, 50));
        num5Button->setMaximumSize(QSize(100, 100));
        num5Button->setFont(font1);
        num5Button->setFocusPolicy(Qt::NoFocus);
        num5Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num5Button, 1, 1, 1, 1);

        clearButton = new QPushButton(WndDigitalKeyboard);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);
        clearButton->setMinimumSize(QSize(50, 50));
        clearButton->setMaximumSize(QSize(100, 100));
        clearButton->setFont(font1);
        clearButton->setFocusPolicy(Qt::NoFocus);
        clearButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/clear.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/clear_pressed.png);\n"
"}"));

        gridLayout->addWidget(clearButton, 1, 3, 1, 1);

        num6Button = new QPushButton(WndDigitalKeyboard);
        num6Button->setObjectName(QStringLiteral("num6Button"));
        sizePolicy.setHeightForWidth(num6Button->sizePolicy().hasHeightForWidth());
        num6Button->setSizePolicy(sizePolicy);
        num6Button->setMinimumSize(QSize(50, 50));
        num6Button->setMaximumSize(QSize(100, 100));
        num6Button->setFont(font1);
        num6Button->setFocusPolicy(Qt::NoFocus);
        num6Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num6Button, 1, 2, 1, 1);

        num1Button = new QPushButton(WndDigitalKeyboard);
        num1Button->setObjectName(QStringLiteral("num1Button"));
        sizePolicy.setHeightForWidth(num1Button->sizePolicy().hasHeightForWidth());
        num1Button->setSizePolicy(sizePolicy);
        num1Button->setMinimumSize(QSize(50, 50));
        num1Button->setMaximumSize(QSize(100, 100));
        num1Button->setFont(font1);
        num1Button->setFocusPolicy(Qt::NoFocus);
        num1Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num1Button, 0, 0, 1, 1);

        num2Button = new QPushButton(WndDigitalKeyboard);
        num2Button->setObjectName(QStringLiteral("num2Button"));
        sizePolicy.setHeightForWidth(num2Button->sizePolicy().hasHeightForWidth());
        num2Button->setSizePolicy(sizePolicy);
        num2Button->setMinimumSize(QSize(50, 50));
        num2Button->setMaximumSize(QSize(100, 100));
        num2Button->setFont(font1);
        num2Button->setFocusPolicy(Qt::NoFocus);
        num2Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num2Button, 0, 1, 1, 1);

        num3Button = new QPushButton(WndDigitalKeyboard);
        num3Button->setObjectName(QStringLiteral("num3Button"));
        sizePolicy.setHeightForWidth(num3Button->sizePolicy().hasHeightForWidth());
        num3Button->setSizePolicy(sizePolicy);
        num3Button->setMinimumSize(QSize(50, 50));
        num3Button->setMaximumSize(QSize(100, 100));
        num3Button->setFont(font1);
        num3Button->setFocusPolicy(Qt::NoFocus);
        num3Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num3Button, 0, 2, 1, 1);

        num00Button = new QPushButton(WndDigitalKeyboard);
        num00Button->setObjectName(QStringLiteral("num00Button"));
        sizePolicy.setHeightForWidth(num00Button->sizePolicy().hasHeightForWidth());
        num00Button->setSizePolicy(sizePolicy);
        num00Button->setMinimumSize(QSize(50, 50));
        num00Button->setMaximumSize(QSize(100, 100));
        num00Button->setFont(font1);
        num00Button->setFocusPolicy(Qt::NoFocus);
        num00Button->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num00Button, 3, 2, 1, 1);


        retranslateUi(WndDigitalKeyboard);

        QMetaObject::connectSlotsByName(WndDigitalKeyboard);
    } // setupUi

    void retranslateUi(QWidget *WndDigitalKeyboard)
    {
        WndDigitalKeyboard->setWindowTitle(QApplication::translate("WndDigitalKeyboard", "WndDigitalKeyboard", Q_NULLPTR));
        num9Button->setText(QApplication::translate("WndDigitalKeyboard", "9", Q_NULLPTR));
        dotButton->setText(QApplication::translate("WndDigitalKeyboard", ".", Q_NULLPTR));
        num8Button->setText(QApplication::translate("WndDigitalKeyboard", "8", Q_NULLPTR));
        confirmButton->setText(QString());
        num0Button->setText(QApplication::translate("WndDigitalKeyboard", "0", Q_NULLPTR));
        num7Button->setText(QApplication::translate("WndDigitalKeyboard", "7", Q_NULLPTR));
        num4Button->setText(QApplication::translate("WndDigitalKeyboard", "4", Q_NULLPTR));
        deleteButton->setText(QString());
        num5Button->setText(QApplication::translate("WndDigitalKeyboard", "5", Q_NULLPTR));
        clearButton->setText(QString());
        num6Button->setText(QApplication::translate("WndDigitalKeyboard", "6", Q_NULLPTR));
        num1Button->setText(QApplication::translate("WndDigitalKeyboard", "1", Q_NULLPTR));
        num2Button->setText(QApplication::translate("WndDigitalKeyboard", "2", Q_NULLPTR));
        num3Button->setText(QApplication::translate("WndDigitalKeyboard", "3", Q_NULLPTR));
        num00Button->setText(QApplication::translate("WndDigitalKeyboard", "00", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WndDigitalKeyboard: public Ui_WndDigitalKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WNDDIGITALKEYBOARD_H
