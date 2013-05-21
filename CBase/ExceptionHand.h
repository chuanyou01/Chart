#pragma once

class CExceptionHand
{
public:
	CExceptionHand(void);
	~CExceptionHand(void);
	int PostDumpFile(char* pStrFile);
	void SetHandLe(const char* lpStrFilePath );
	static long WINAPI ApplicationCrashHander( EXCEPTION_POINTERS *pException );
};
