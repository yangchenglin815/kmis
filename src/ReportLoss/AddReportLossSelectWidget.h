#ifndef ADDREPORTLOSSSELECTWIDGET_H
#define ADDREPORTLOSSSELECTWIDGET_H

#include <QWidget>
#include "../data/httpstructdata.h"

namespace Ui {
class AddReportLossSelectWidget;
}

class AddReportLossSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddReportLossSelectWidget(QWidget *parent = 0);
    ~AddReportLossSelectWidget();
    void initData(const QList<AddReportLossSelectInfo>& lossInfoList);
    void appendData(const AddReportLossSelectInfo& lossInfo);
    int getGoodsPosition(int nId);
    void removeSelectItem();
    int getGoodsListLength();
    bool getSeletedItem(AddReportLossSelectInfo& lossInfo);
    void getGoodsInfoList(QList<AddReportLossSelectInfo>& goodsInfoList);
    bool getSelectGoodsInfo(int nId, AddReportLossSelectInfo &goodsInfo);

private slots:
    void slot_showLastPage();
    void slot_showNextPage();

signals:
    void sigClickItem(AddReportLossSelectInfo selectlossInfo);
    void sig_Focus();

private:
    void updateUI(bool bToEndPage = false);
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();

private:
    Ui::AddReportLossSelectWidget *ui;
    QList<AddReportLossSelectInfo> m_lossInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // ADDREPORTLOSSSELECTWIDGET_H
