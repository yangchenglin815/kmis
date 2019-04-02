#ifndef STRINGLISTWIDGET_H
#define STRINGLISTWIDGET_H

#include <QWidget>

namespace Ui {
class StringListWidget;
}

class StringListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StringListWidget(QWidget *parent = 0);
    ~StringListWidget();
    void initData(QList<QString> strList, int nItemHeight, int nWidth);
    void setFontSize(int nFontSize);

private:
    void initConnect();

signals:
    void sigClicked(QString sContent);

private:
    Ui::StringListWidget *ui;
};

#endif // STRINGLISTWIDGET_H
