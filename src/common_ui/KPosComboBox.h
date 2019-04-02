#ifndef KPOSCOMBOBOX_H
#define KPOSCOMBOBOX_H

#include <QWidget>
#include "StringListWidget.h"

class KPosComboBox : public QWidget
{
    Q_OBJECT

public:
    explicit KPosComboBox(QWidget *parent = 0);
    ~KPosComboBox();
    void initListWidget(QList<QString> strList);
    void initListWidget(QList<QString> strList, int nItemHeight);
    void setContent(QString sContent);
    QString getContent();
    void setOutline(bool bHasOutline = true, QString sColor = "#ea8852");
    void hideListWidget();
    void setFontSize(int nFontSize);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event); 

private slots:
    void slot_clicked(QString sContent);

private:
    void setListWidgetPosition(QPoint globalPoint);

signals:
    void sigClicked();

private:
    StringListWidget* m_pStringListWidget;
    QString m_sContent;
    QString m_sOutLineColor;
    bool m_bHasOutline;
    int m_nFontSize;
};

#endif // KPOSCOMBOBOX_H
