#pragma once

#ifndef _DEBUG_MSG_FILE_
#define _DEBUG_MSG_FILE_

void wdebugstr(wchar_t* pszFormate, ...);

void debugstr(char* pszFormate, ...);


#ifdef _DEBUG

#define ERRORLINE debugstr("%s:%s", __FILE__, __LINE__)
#define ERRORLINE_THREAD debugstr("%d:  %s:%s",GetCurrentThreadId(), __FILE__, __LINE__)


#else

#define ERRORLINE 
#define ERRORLINE_THREAD 

#endif



#endif


