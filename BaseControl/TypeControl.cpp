#include "StdAfx.h"
#include "TypeControl.h"
#include "Control.h"
//#include "debugmsg.h"

CTypeControl::CTypeControl(void)
{
}

CTypeControl::~CTypeControl(void)
{
	for (map<wchar_t*, CControl*>::iterator it= m_mapCtl.begin();
		it!=m_mapCtl.end(); it++)
	{
		CControl* pControl = it->second;
		delete pControl;
	}
	m_mapCtl.clear();
}

bool CTypeControl::RegisterControl( wchar_t* pCtrlName, CControl* pEntity )
{
	if (pCtrlName==NULL || pEntity==NULL)
	{
		return false;
	}
	m_mapCtl[pCtrlName] = pEntity;
	return true;
}

CControl* CTypeControl::CreateControl( wchar_t* pCtrlName )
{
	CControl* pReturn = NULL;
	map<wchar_t*, CControl*>::iterator it = m_mapCtl.find(pCtrlName);
	if (it!= m_mapCtl.end())
	{
		CControl* pContorl = it->second;
		pReturn = pContorl->Clone();
	}
	return pReturn;
}

CControl* CTypeControl::LoadControl( wchar_t* pStrXml )
{
	assert(0);
	wdebugstr(L"loadcontorl is empty");
	return NULL;
}

CControl* CTypeControl::LoadControl( string& strXml )
{
	assert(0);
	wdebugstr(_T("loadcontorl is empty"));
	return NULL;
}