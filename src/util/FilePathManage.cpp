#include "FilePathManage.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

FilePathManage* FilePathManage::m_pInstance = NULL;

FilePathManage::FilePathManage()
{
    init();
}

FilePathManage *FilePathManage::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new FilePathManage;
    }
    return m_pInstance;
}

void FilePathManage::release()
{
    if (m_pInstance != NULL)
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

QString FilePathManage::getAppPath(){
    QString sDatabaseDirPath = QDir::currentPath() + "/";
    checkAndMkDir(sDatabaseDirPath);
    return sDatabaseDirPath;
}

QString FilePathManage::getDatabaseDirPath()
{
    QString sDatabaseDirPath = m_sDocumentsPath + "Databse/";
    checkAndMkDir(sDatabaseDirPath);
    return sDatabaseDirPath;
}

QString FilePathManage::getKPosIniPath()
{
    QString sKPosDirPath = m_sDocumentsPath + "Ini/";
    checkAndMkDir(sKPosDirPath);
    return sKPosDirPath;
}

QString FilePathManage::getReceiptPath()
{
    QString receiptPath = m_sDocumentsPath + "Receipt/";
    checkAndMkDir(receiptPath);
    return receiptPath;
}

QString FilePathManage::getKPosInstallPath()
{
    QString sDir = m_sDocumentsPath + "Update/Install/";
    checkAndMkDir(sDir);
    return sDir;
}

QString FilePathManage::getRemoteADPath()
{
    QString sDir = m_sDocumentsPath + "AD/Remote/";
    checkAndMkDir(sDir);
    return sDir;
}

QString FilePathManage::getLocalADPath()
{
    QString sDir = m_sDocumentsPath + "AD/Local/";
    checkAndMkDir(sDir);
    return sDir;
}

QString FilePathManage::getDumpPath()
{
    QString sDir = m_sDocumentsPath + "Dump/";
    checkAndMkDir(sDir);
    return sDir;
}

QString FilePathManage::getXMLPath()
{
    QString sDir = m_sDocumentsPath + "XML/";
    checkAndMkDir(sDir);
    return sDir;
}

void FilePathManage::init()
{
    m_sDocumentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/KPos/";
}

void FilePathManage::checkAndMkDir(QString &dirPath)
{
    QDir dir;
    if (dir.exists(dirPath))
    {
        return;
    }
    dir.mkpath(dirPath);
    dirPath = dir.toNativeSeparators(dirPath);
}

