#include "stdafx.h"
#include "debugmsg.h"



void wdebugstr(wchar_t* pszFormate, ...)
{
	va_list pArglist;
	va_start(pArglist, pszFormate);
	wchar_t pStrOut[MAX_PATH] = {0};
	swprintf_s((wchar_t*)pStrOut, MAX_PATH, pszFormate, pArglist);
	OutputDebugString(pStrOut);
}

void debugstr(char* pszFormate, ...)
{
	va_list pArglist;
	va_start(pArglist, pszFormate);
	char pStrOut[MAX_PATH] = {0};
	sprintf_s((char*)pStrOut, MAX_PATH, pszFormate, pArglist);
	OutputDebugStringA(pStrOut);
}

