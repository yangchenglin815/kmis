/********************************************************************
(c) Copyright 2014-2015 Mettler-Toledo CT. All Rights Reserved.

File Name: 		MTScaleAPI.h
File Path:		C:\Works\CVSWork\retail\Standard\Domestic\PCSoftware\MT_Soft_Com\MTScaleKey\Code\MTScaleAPI

Description:	MTScaleAPI

Author:			Zhong Min
Created:		2015/7/3 11:56
Remark:	        MTScaleAPI
*********************************************************************/

#pragma once
#ifndef _MTScaleAPI_MTScaleAPI_H
#define _MTScaleAPI_MTScaleAPI_H
extern "C"
{
//#include "stdafx.h"

/************************************
// Method:     以文件为参数执行任务，Ansi版本
// FullName:   ExecuteTaskInFile
// Access:     public
// Returns:    调用成功：true 调用失败：false
// Qualifier:
// Parameter:  const char * szTaskID: 任务ID(用户指定)
// Parameter:  const char * szInputFile: 任务文件
// Parameter:  const char * szOutputFile: 保持结果的文件
// Parameter:  bool bSynch: 是否同步执行，true表示任务执行完毕后再返回，false表示任务进入任务队列后返回。
// Remark:
************************************/
bool __stdcall ExecuteTaskInFile(const char *szTaskID, const char *szInputFile, const char *szOutputFile, bool bSynch);

/************************************
// Method:     以文件为参数执行任务，Unicode版本
// FullName:   ExecuteTaskInFileW
// Access:     public
// Returns:    调用成功：true 调用失败：false
// Qualifier:
// Parameter:  const wchar_t * szTaskID: 任务ID(用户指定)
// Parameter:  const wchar_t * szInputFile: 任务文件
// Parameter:  const wchar_t * szOutputFile: 结果的文件
// Parameter:  bool bSynch: 是否异步执行，true表示任务执行完毕后再返回，false表示任务进入任务队列后返回。
// Remark:
************************************/
bool __stdcall ExecuteTaskInFileW(const wchar_t *szTaskID, const wchar_t *szInputFile, const wchar_t *szOutputFile, bool bSynch);

/************************************
// Method:     以输入的字符串为参数执行任务，Ansi版本
// FullName:   ExecuteTaskInString
// Access:     public
// Returns:    执行的结果字符串(需要调用者进行空间释放)
// Qualifier:
// Parameter:  const char * szTaskID: 任务ID(用户指定)
// Parameter:  const char * szInput: 任务数据字符串
// Parameter:  bool bSynch: 是否异步执行，true表示任务执行完毕后再返回，false表示任务进入任务队列后返回。
// Remark:
************************************/
char *__stdcall ExecuteTaskInString(const char *szTaskID, const char *szInput, bool bSynch);

/************************************
// Method:     以输入的字符串为参数执行任务，Unicode版本
// FullName:   ExecuteTaskInStringW
// Access:     public
// Returns:    执行的结果字符串(需要调用者进行空间释放)
// Qualifier:
// Parameter:  const wchar_t * szTaskID: 任务ID(用户指定)
// Parameter:  const wchar_t * szInput: 任务数据字符串
// Parameter:  bool bSynch: 是否异步执行，true表示任务执行完毕后再返回，false表示任务进入任务队列后返回。
// Remark:
************************************/
wchar_t *__stdcall ExecuteTaskInStringW(const wchar_t *szTaskID, const wchar_t *szInput, bool bSynch);

/************************************
// Method:     以文件为参数进行参数设置，Ansi版本
// FullName:   SetParamsInFile
// Access:     public
// Returns:    调用成功：true 调用失败：false
// Qualifier:
// Parameter:  const char * szTaskID: 任务ID(用户指定)
// Parameter:  const char * szInputFile: 任务文件
// Parameter:  const char * szOutputFile: 结果文件
// Remark:
************************************/
bool __stdcall SetParamsInFile(const char *szTaskID, const char *szInputFile, const char *szOutputFile);

/************************************
// Method:     以文件为参数进行参数设置，Unicode版本
// FullName:   SetParamsInFileW
// Access:     public
// Returns:    调用成功：true 调用失败：false
// Qualifier:
// Parameter:  const wchar_t * szTaskID: 任务ID(用户指定)
// Parameter:  const wchar_t * szInputFile: 任务文件
// Parameter:  const wchar_t * szOutputFile: 结果文件
// Remark:
************************************/
bool __stdcall SetParamsInFileW(const wchar_t *szTaskID, const wchar_t *szInputFile, const wchar_t *szOutputFile);

/************************************
// Method:     以字符串为参数进行参数设置，Ansi版本
// FullName:   SetParamsInString
// Access:     public
// Returns:    执行结果字符串(需要调用者进行空间释放)
// Qualifier:
// Parameter:  const char * szInput: 任务数据字符串
// Remark:     //2015/3/19 by wangbin modify bool to char*
************************************/
char *__stdcall SetParamsInString(const char *szInput);

/************************************
// Method:     以字符串为参数进行参数设置，Unicode版本
// FullName:   SetParamsInStringW
// Access:     public
// Returns:    执行结果字符串(需要调用者进行空间释放)
// Qualifier:
// Parameter:  const wchar_t * szInput: 任务数据字符串
// Remark:
************************************/
wchar_t *__stdcall SetParamsInStringW(const wchar_t *szInput);

/************************************
// Method:     查询任务状态，Ansi版本
// FullName:   QueryTask
// Access:     public
// Returns:    任务状态字符串(需要调用者进行空间释放)
// Qualifier:
// Parameter:  const char * szInput: 任务数据字符串
// Remark:
************************************/
char *__stdcall QueryTask(const char *szInput);

/************************************
// Method:     查询任务状态，Unicode版本
// FullName:   QueryTaskW
// Access:     public
// Returns:    任务状态字符串(需要调用者进行空间释放)
// Qualifier:
// Parameter:  const wchar_t * szInput: 任务数据字符串
// Remark:
************************************/
wchar_t *__stdcall QueryTaskW(const wchar_t *szInput);

/************************************
// Method:     查询MTScaleKey状态，Ansi版本
// FullName:   QueryStatus
// Access:     public
// Returns:    返回状态字符串(需要调用者进行空间释放)
// Qualifier:
// Parameter:  const char * szInput: 查询数据字符串
// Remark:
************************************/
char *__stdcall QueryStatus(const char *szInput);

/************************************
// Method:     查询MTScaleKey状态，Unicode版本
// FullName:   QueryStatusW
// Access:     public
// Returns:    返回状态字符串(需要调用者进行空间释放)
// Qualifier:
// Parameter:  const wchar_t * szInput: 查询数据字符串
// Remark:
************************************/
wchar_t *__stdcall QueryStatusW(const wchar_t *szInput);

/************************************
// Method:     删除任务，Ansi版本
// FullName:   CancelTask
// Access:     public
// Returns:    返回调用是否成功
// Qualifier:
// Parameter:  const char * szInput: 任务ID或者任务数据字符串
// Remark:
************************************/
bool __stdcall CancelTask(const char *szInput);

/************************************
// Method:     删除任务，Unicode版本
// FullName:   CancelTaskW
// Access:     public
// Returns:    返回调用是否成功
// Qualifier:
// Parameter:  const wchar_t * szInput: 任务ID或者任务数据字符串
// Remark:
************************************/
bool __stdcall CancelTaskW(const wchar_t *szInput);

/************************************
// Method:     关闭进程
// FullName:   CloseProcess
// Access:     public
// Returns:    成功关闭或者失败
// Qualifier:
// Remark:     //2015/7/1 zhongm 删除输入参数
************************************/
bool __stdcall CloseProcess();

/************************************
// Method:     释放动态库中生成的资源
// FullName:   Free
// Access:     public
// Returns:    DllAPI void __stdcall
// Qualifier:
// Parameter:  void * p: 需要释放的资源指针
// Remark:
************************************/
void __stdcall Free(void *p);

/************************************
// Method:     FreeMTScaleAPI
// FullName:   FreeMTScaleAPI
// Access:     public
// Returns:    DllAPI void __stdcall
// Qualifier:
// Remark:
************************************/
void __stdcall Release();

}

#endif // _MTScaleAPI_MTScaleAPI_H

