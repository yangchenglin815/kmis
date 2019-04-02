#ifndef FILEPATHMANAGE_H
#define FILEPATHMANAGE_H

#include <QString>

class FilePathManage
{
public:
    static FilePathManage* instance();
    void release();
    QString getDatabaseDirPath();
    QString getKPosIniPath();
    QString getReceiptPath();
    QString getKPosInstallPath(); // KPos更新目录
    QString getRemoteADPath();
    QString getLocalADPath();
    QString getDumpPath();
    QString getXMLPath();
    QString getAppPath();

private:
    FilePathManage();
    void init();
    void checkAndMkDir(QString& dirPath);

private:
    QString m_sDocumentsPath; // 应用程序路径
    static FilePathManage* m_pInstance;
};

#endif // FILEPATHMANAGE_H
