#ifndef _MACRO_DEFINE_FILE_
#define _MACRO_DEFINE_FILE_

#ifdef _DLL_IMPORT
#define _DLL_DEC  __declspec(dllimport)
#else
#define _DLL_DEC  __declspec(dllexport)
#endif

#endif