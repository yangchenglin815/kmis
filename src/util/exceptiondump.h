#ifndef EXCEPTIONDUMP_H
#define EXCEPTIONDUMP_H

#include <dbghelp.h>
#include <shellapi.h>
#include <shlobj.h>
#include "../util/CommonFun.h"
#include "../util/KPosIni.h"
#include "FilePathManage.h"
#include <QDateTime>

static LONG WINAPI MyUnhandledExceptionFilter(struct _EXCEPTION_POINTERS* ExceptionInfo)
{
    //获取当前时间
    QString curDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss");

    //生成Dump文件名
    QString strFileName(QString("%1/KPos").arg(FilePathManage::instance()->getDumpPath()));
    strFileName += "_v";
    strFileName += CommonFun::getAppVersion();
    strFileName += "_t";
    strFileName += curDateTime;
    strFileName += "_u";
    strFileName += KPosIni::getUserCode();
    strFileName += "_p";
    strFileName += KPosIni::getPosCode();
    strFileName += ".dmp";

    HANDLE lhDumpFile = CreateFile(strFileName.toStdWString().c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);//L"TT_DumpFile.dmp"
    MINIDUMP_EXCEPTION_INFORMATION loExceptionInfo;
    loExceptionInfo.ExceptionPointers = ExceptionInfo;
    loExceptionInfo.ThreadId = GetCurrentThreadId();
    loExceptionInfo.ClientPointers = TRUE;

    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),lhDumpFile, MiniDumpNormal, &loExceptionInfo, NULL, NULL);
    CloseHandle(lhDumpFile);
    return EXCEPTION_EXECUTE_HANDLER;
}

#endif // EXCEPTIONDUMP_H

