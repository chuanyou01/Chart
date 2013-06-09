#include "StdAfx.h"
#include "Control.h"
#include "TypeInfo.h"
#include "TypeControl.h"

CTypeControl* CControl::m_pManage = NULL;

CControl::CControl(void)
:m_typeInfo(NULL)
{
	
}

CControl::~CControl(void)
{
}

CControl* CControl::Clone()
{
	return NULL;
}

void CControl::Draw()
{

}

void CControl::OnMouse( CControl* pObj, int nEvent )
{

}

void CControl::OnLButton( CControl* pObj, int nEvent )
{

}

void CControl::OnRButton( CControl* pObj, int nEvent )
{

}

bool CControl::RegisterControl()
{
	CTypeControl* pManage = GetManage();
	return pManage->RegisterControl(m_typeInfo->GetName(), this);
	
}

inline wchar_t* CControl::GetType()
{
	return m_typeInfo->GetName();
}

bool CControl::Load( wchar_t* pXmlBuffer )
{
	return false;
}

void CControl::Show()
{
	m_bvisable = true;
	m_nZindex = 0 - m_nZindex;
	Draw();
}

void CControl::Hide()
{
	m_bvisable = false;
	m_nZindex = 0 - m_nZindex;
}

CTypeControl* CControl::GetManage()
{
	if (CControl::m_pManage==NULL)
	{
		CControl::m_pManage = new CTypeControl();
	}
	return CControl::m_pManage;
}

void CControl::RealseManage()
{
	if (CControl::m_pManage!=NULL)
	{
		delete CControl::m_pManage;
		CControl::m_pManage = NULL;
	}
}

