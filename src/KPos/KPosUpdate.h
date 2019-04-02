#ifndef KPOSUPDATE_H
#define KPOSUPDATE_H

#include <QObject>
#include <QProcess>
#include "../util/HttpDownloadInterface.h"
#include "KPosUpdateProgressWidget.h"

class KPosUpdate : public QObject
{
    Q_OBJECT
public:
    explicit KPosUpdate(QObject *parent = 0);
    ~KPosUpdate();
    void installUpdate(QString sAddress); // 安装包更新

private slots:
    void slot_downloadProgress(int nProgressPercent, int nTaskId); // 进度百分比的分子值
    void slot_downFinished(bool bSuccess, QString sFilePath, int nTaskId);

signals:
    void sigDownloadError();
    void sigInstallStartSuccess();

private:
    HttpDownloadInterface* m_pDownloadInterface;
    KPosUpdateProgressWidget* m_pProgressWidget;
    QProcess* m_pProcess;
};

#endif // KPOSUPDATE_H
