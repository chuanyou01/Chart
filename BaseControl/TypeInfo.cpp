#include "StdAfx.h"
#include "TypeInfo.h"


CTypeInfo::CTypeInfo(void):
m_pName(NULL),
m_nVirsion(1)
{
}

CTypeInfo::~CTypeInfo(void)
{
}

wchar_t* CTypeInfo::GetName()
{
	return m_pName;
}

bool CTypeInfo::Init( wchar_t* pName, int nVirsion )
{
	if (pName==NULL)
	{
		ERRORLINE;
		return false;
	}
	m_nVirsion = nVirsion;
	size_t nLength = wcslen(pName);
	m_pName = new wchar_t[nLength+1];
	wcscpy_s(m_pName, nLength+1, pName);

	m_nVirsion = nVirsion;
	return true;
}