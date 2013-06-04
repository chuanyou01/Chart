#pragma once

class CTypeInfo
{
public:
	CTypeInfo(void);
	~CTypeInfo(void);

	wchar_t* GetName();
	bool Init(wchar_t* pName, int nVirsion);
private:
	wchar_t*	m_pName;
	int			m_nVirsion;
};
