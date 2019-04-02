#ifndef CHECKORDERCATEGORYDETAILWIDGET_H
#define CHECKORDERCATEGORYDETAILWIDGET_H

#include <QWidget>
#include "../data/ordergoodsdata.h"
#include "CheckOrderGoodsDlg.h"

namespace Ui {
class CheckOrderCategoryDetailWidget;
}

class CheckOrderCategoryDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CheckOrderCategoryDetailWidget(QWidget *parent = 0);
    ~CheckOrderCategoryDetailWidget();
    void clearSelectId();
    void initData(const QList<CheckOrderCategoryDetailInfo*> categoryDetailInfoList);
    void removeCategory(int nCategoryId);
    void appendCategory(const QList<CheckOrderCategoryDetailInfo*> categoryDetailInfoList);
    void updateData();

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
//    void on_checkManyButton_clicked(); // 批量审核

    void slot_selectId(int nOrderCardId, bool bSelected);
    void slot_clickItem(bool search);

    void on_deleteButton_clicked(); // 删除
    void on_uploadButton_clicked(); // 上传
    void on_searchButton_clicked(); // 查看
    void on_editButton_clicked(); // 编辑
    void on_addButton_clicked(); // 新增

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void initButtons();

signals:
    void sigSearchOrderCard(int nOrderId); // 查看要货卡
    void sigEditOrderCard(QList<int> orderIdList); // 编辑要货卡
//    void sigCheckManyOrderCategoryDetailInfo(QList<int> orderCardIdList);
    void sigUploadOrderCard(QList<int> orderCardIdList); // 上传要货卡
    void sigRemoveOrderCard(QList<int> orderCardIdList); // 删除要货卡
    void sigAddCheckOrder(); // 新增要货卡

private:
    Ui::CheckOrderCategoryDetailWidget *ui;
    QList<CheckOrderCategoryDetailInfo*> m_checkOrderCategoryDetailInfoList;
    CheckOrderGoodsDlg* m_pCheckOrderGoodsDlg;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // CHECKORDERCATEGORYDETAILWIDGET_H
