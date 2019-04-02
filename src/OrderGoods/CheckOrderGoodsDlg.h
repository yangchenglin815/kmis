#ifndef CHECKORDERGOODSDLG_H
#define CHECKORDERGOODSDLG_H

#include <QDialog>
#include "../data/ordergoodsdata.h"
#include "../Bussiness/OrderGoodsCheckCtrl.h"
#include "../common_ui/DlgCommon.h"

namespace Ui {
class CheckOrderGoodsDlg;
}

class CheckOrderGoodsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOrderGoodsDlg(QWidget *parent = 0);
    ~CheckOrderGoodsDlg();
//    void setUploadFinishedFlage(bool bUploadFinished);
//    void initData(CheckOrderCategoryDetailInfo* pCheckOrderCategoryDetailInfo);
    void initData(const QList<OrderCardDetailInfo_s>& orderCardDetailInfoList, bool bUploadFinish, const QList<int>& orderCardIdList, OrderGoodsCheckCtrl* pOrderGoodsCheckCtrl);

private slots:
    void slot_orderNumberChanged(QMap<int,int> changedMap);
    void slot_onUpdateOrderCardListDetail(int nCode, QString sMsg);

private:
    void setTitleText(QString titleText);
    void initConnect();

private:
    Ui::CheckOrderGoodsDlg *ui;
    OrderGoodsCheckCtrl* m_pOrderGoodsCheckCtrl;
    QList<int> m_orderCardIdList;
    DlgCommon* m_pDlgCommon;
};

#endif // CHECKORDERGOODSDLG_H
