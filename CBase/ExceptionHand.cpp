#include "StdAfx.h"
#include "ExceptionHand.h"
#include "Dbghelp.h"
#include "RTime.h"


static string strFilePath;
CExceptionHand::CExceptionHand(void)
{
}

CExceptionHand::~CExceptionHand(void)
{
}

int CExceptionHand::PostDumpFile(char* pStrFile)
{
	return 0;
}


long CExceptionHand::ApplicationCrashHander( EXCEPTION_POINTERS *pException )
{

	CRTime tmNow;
	string strTime = tmNow.GetCurrent();
	//string strTime= tm.Format("%Y-%m-%d-%H%M%S");
	string strTmpPath = strFilePath + strTime + ".dmp";

	HANDLE hDumpFile = CreateFileA(strTmpPath.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);  

	// Dump信息  
	//  
	MINIDUMP_EXCEPTION_INFORMATION dumpInfo;  
	dumpInfo.ExceptionPointers = pException;  
	dumpInfo.ThreadId = GetCurrentThreadId();  
	dumpInfo.ClientPointers = TRUE;  

	// 写入Dump文件内容  
	//  
	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL);  

	CloseHandle(hDumpFile); 

	//MessageBox("Error", "unexept")
	return EXCEPTION_CONTINUE_SEARCH/*EXCEPTION_EXECUTE_HANDLER*/;
}

void CExceptionHand::SetHandLe(const char* lpStrFilePath )
{
	strFilePath = lpStrFilePath;
	SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER) CExceptionHand::ApplicationCrashHander);
}