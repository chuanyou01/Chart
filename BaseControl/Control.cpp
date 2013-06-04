#include "StdAfx.h"
#include "Control.h"
#include "TypeInfo.h"

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
	return false;
}

inline wchar_t* CControl::GetType()
{
	return m_typeInfo->GetName();
}

bool CControl::Load( wchar_t* pXmlBuffer )
{
	return false;
}