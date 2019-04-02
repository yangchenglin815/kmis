#include "KPosUpdate.h"
#include "../util/GlobalSignal.h"
#include "../util/FilePathManage.h"
#include "../util/KPosLog.h"
#include "../util/CommonFun.h"
#include <QProcess>
#include <QDebug>

KPosUpdate::KPosUpdate(QObject *parent)
    : QObject(parent)
    , m_pDownloadInterface(NULL)
    , m_pProgressWidget(NULL)
{
    m_pDownloadInterface = new HttpDownloadInterface(this);
    connect(m_pDownloadInterface, SIGNAL(sigDownloadProgress(int, int)),
            this, SLOT(slot_downloadProgress(int, int)));
    connect(m_pDownloadInterface, SIGNAL(sigDownFinished(bool, QString, int)),
            this, SLOT(slot_downFinished(bool, QString, int)));
}

KPosUpdate::~KPosUpdate()
{
    if (m_pProgressWidget != NULL)
    {
        m_pProgressWidget->deleteLater();
        m_pProgressWidget = NULL;
    }
}

void KPosUpdate::installUpdate(QString sAddress)
{
    QString sDir = FilePathManage::instance()->getKPosInstallPath();
    GlobalSignal::instance()->sigAddHttpDownTask(sAddress, sDir, m_pDownloadInterface);
}

void KPosUpdate::slot_downloadProgress(int nProgressPercent, int nTaskId)
{
    Q_UNUSED(nTaskId);
    qDebug()<<nProgressPercent;
    if (m_pProgressWidget == NULL)
    {
       m_pProgressWidget = new KPosUpdateProgressWidget;
       m_pProgressWidget->show();
    }
    m_pProgressWidget->setProgressValue(nProgressPercent);
}

void KPosUpdate::slot_downFinished(bool bSuccess, QString sFilePath, int nTaskId)
{
    Q_UNUSED(nTaskId)
    if (m_pProgressWidget != NULL)
    {
        m_pProgressWidget->deleteLater();
        m_pProgressWidget = NULL;
    }

    if (bSuccess)
    {
        if (m_pProcess == NULL)
        {
            m_pProcess = new QProcess(this);
        }
        m_pProcess->startDetached(QString("explorer %1").arg(sFilePath)); // 与主进程分离
        emit sigInstallStartSuccess();
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("安装包下载失败--%1").arg(sFilePath));
        emit sigDownloadError();
    }
}
