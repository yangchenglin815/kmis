#ifndef BARCODESCALESAGENT_H
#define BARCODESCALESAGENT_H

#include <QObject>
#include <QMutex>
#include "barcodescaledata.h"

class BarCodeScalesAgent : public QObject
{
    Q_OBJECT
public:
    static BarCodeScalesAgent* instance();
    void checkBcsState(const QList<BarCodeScaleInfo>& infoList);
    void sendDownBcs(QList<BarCodeScaleInfo>& infoList, QList<BCSGroupManageLeftInfo> &leftInfo);
    void createGoodsGroupRequest(QString sGroupName); // 创建商品组
    void getGoodsGroupListRequest(); // 获取商品组列表
    void saveGoodsGroupRequest(int nGroupId, const QList<QString>& pluList); // 保存商品组
    void getBarcodeScaleCodeRequest(); // 获取条码秤编号
    void addBarcodeScaleRequest(QString sCode, QString sType, QString sIp, int nGroupId); // 添加条码秤
    void getBarcodeScaleListRequest(); // 获取条码秤列表
    void updateScaleProductIssueRequest(const QList<QString>& scaleList);//更新条码秤下发时间
    void deleteScaleRequestRequest(QString scaleId);//删除条码秤
private slots:
    void slot_checkBcsState(QList<BarCodeScaleInfo>);
    void slot_sendDownBcs(QList<BarCodeScaleInfo> infoList, QList<BCSGroupManageLeftInfo> leftInfoList);
//    void slot_onGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList);
//    void slot_onGetBarcodeScaleList(int nCode, QString sMsg, QList<BarCodeScaleInfo> scaleInfoList);

private:
    explicit BarCodeScalesAgent(QObject *parent = 0);
    void initConnect();

signals:
    void sigCheckBcsState(QList<BarCodeScaleInfo> infoList);
    void sigOnCheckBcsState(QString sKey, bool bState);
    void sigOnCheckBcsStateFinish();
    void sigSendDownBcs(QList<BarCodeScaleInfo> infoList, QList<BCSGroupManageLeftInfo> leftInfo);
    void sigOnSendDownBcsState(QString sKeyId, bool bSuccess);
    void sigOnSendDownBcsFinish();

    void sigOnCreateGoodsGroup(int nCode, QString sMsg, BCSGroupManageLeftInfo bcsGroupManageLeftInfo); // 创建商品组
    void sigOnGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList); // 获取商品组列表
    void sigOnGetBarcodeScaleList(int nCode, QString sMsg, QList<BarCodeScaleInfo> scaleInfoList);//获取条码秤列表
    void sigOnGetBarcodeScaleCode(int nCode, QString sMsg, QString sBcsCode); // 获取条码秤编号
    void sigOnAddBarcodeScale(int nCode, QString sMsg);// 新增条码秤
    void sigOnDeleteScale(int nCode, QString sMsg, QString scaleId);// 删除条码秤
    void sigResetPasswd(int nCode, QString sMsg);//修改密码

private:
    static BarCodeScalesAgent* m_pInstance;
//    QList<BarCodeScaleInfo> m_infoList;
//    QList<BCSGroupManageLeftInfo> m_leftInfoList;

};

#endif // BARCODESCALESAGENT_H
