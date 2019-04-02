#ifndef BARCODESCALESCTRL_H
#define BARCODESCALESCTRL_H

#include <QObject>
#include <QString>
#include "httpstructdata.h"
#include "ordergoodsdata.h"
#include "barcodescaledata.h"

class BarCodeScalesCtrl : public QObject
{
    Q_OBJECT
public:
    explicit BarCodeScalesCtrl(QObject *parent = 0);
    void checkBcsState(const QList<BarCodeScaleInfo>& infoList);
    void getAllCategoryRequest(); // 获取所有分类请求
    void getBcsGoods(QMap<int, QList<BCSGoodsInfo> > &bcsGoodsInfoMap);
    void sendDownBcs(QList<BarCodeScaleInfo> &infoList, QList<BCSGroupManageLeftInfo> &leftInfo);
    void createGoodsGroupRequest(QString sGroupName); // 创建商品组
    void getGoodsGroupListRequest(); // 获取商品组列表
    void saveGoodsGroupRequest(int nGroupId, const QList<QString>& pluList); // 保存商品组
    void getBarcodeScaleCodeRequest(); // 获取条码秤编号
    void addBarcodeScaleRequest(QString sCode, QString sType, QString sIp, int nGroupId); // 添加条码秤
    void getBarcodeScaleListRequest(); // 获取条码秤列表
    void updateScaleProductIssueRequest(const QList<QString>& scaleList);//更新条码秤下发时间
    void deleteScaleRequestRequest(QString scaleId);//删除条码秤

private slots:
    void slot_onGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList); // 获取商品组列表

private:
    void initConnect();
    void convertToBcsGoodsInfo(BCSGoodsInfo& bcsGoodsInfo, const GoodsInfo_s& goodsInfo);

signals:
    void sigOnGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>);
    void sigOnCheckBcsState(QString sKeyId, bool bState);
    void sigOnCheckBcsStateFinish(); // 条码秤状态检查完毕
    void sigOnSendDownBcsState(QString,bool);
    void sigOnSendDownBcsFinish(); // 条码秤下发完毕

    void sigOnCreateGoodsGroup(int nCode, QString sMsg, BCSGroupManageLeftInfo bcsGroupManageLeftInfo); // 创建商品组
    void sigOnGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList); // 获取商品组列表
    void sigOnGetBarcodeScaleCode(int nCode, QString sMsg, QString sBcsCode); // 获取条码秤编号
    void sigOnGetBarcodeScaleList(int nCode, QString sMsg, QList<BarCodeScaleInfo> scaleInfoList);//获取条码秤列表
    void sigOnAddBarcodeScale(int nCode, QString sMsg);//新增条码秤
    void sigOnDeleteScale(int nCode, QString sMsg, QString scaleId);//删除条码秤

};

#endif // BARCODESCALESCTRL_H
