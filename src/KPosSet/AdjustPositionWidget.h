#ifndef ADJUSTPOSITIONWIDGET_H
#define ADJUSTPOSITIONWIDGET_H

#include <QWidget>

namespace Ui {
class AdjustPositionWidget;
}

class AdjustPositionWidget : public QWidget
{
    Q_OBJECT

public:
    static AdjustPositionWidget *instance();
    ~AdjustPositionWidget();
    void setPosition(int nPosition);
    void setOwnerType(int nOwnerType);

private slots:
    void on_num0Button_clicked();
    void on_num1Button_clicked();
    void on_num2Button_clicked();
    void on_num3Button_clicked();
    void on_num4Button_clicked();
    void on_num5Button_clicked();
    void on_num6Button_clicked();
    void on_num7Button_clicked();
    void on_num8Button_clicked();
    void on_num9Button_clicked();
    void on_deleteButton_clicked();
    void on_enterButton_clicked();
    void on_leftArrowButton_clicked();
    void on_rightArrowButton_clicked();

private:
    explicit AdjustPositionWidget();
    void setLineEditText(QString sNum);

signals:
    void sigMovePosition(int nNewPosition, int nOldPosition, int nOwnerType);

private:
    Ui::AdjustPositionWidget *ui;
    static AdjustPositionWidget* m_pInstance;
    QString m_curText;
    int m_nPosition;
    int m_nOwnerType;
};

#endif // ADJUSTPOSITIONWIDGET_H
