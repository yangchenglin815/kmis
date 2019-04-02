#ifndef GLOBALSIGNAL_H
#define GLOBALSIGNAL_H

#include <QObject>
#include "enumData.h"
#include "HttpDownloadInterface.h"

class GlobalSignal : public QObject
{
    Q_OBJECT
public:
    static GlobalSignal* instance();

private:
    explicit GlobalSignal(QObject *parent = 0);

signals:
    void sigGoodsCellButtonClicked(QString strBarCode, GoodsWidgetType e_goodsWidget);
    void sigGoodsCellMovePosition(int nPosition);
    void sigCategoryCellButtonClicked(QString sCategoryId, CategoryWidgetType e_categoryWidget);
    void sigCategoryCellButtonDbClicked(QString sCategoryKeyId, CategoryWidgetType e_categoryWidget);
    void sigAddHttpDownTask(QString sUrl, QString sDir, HttpDownloadInterface *pDownloadInterface = NULL);
    void sigClickCheckOrderGoodsSortWidget(int nType);
    void sigReLogin(); // 重新登录

private:
    static GlobalSignal* m_pInstance;
};

#endif // GLOBALSIGNAL_H
