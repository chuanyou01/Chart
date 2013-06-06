#pragma once

class CTypeInfo;
class _DLL_DEC CControl
{
public:
	CControl(void);
	virtual ~CControl(void);

	virtual void Draw();

	virtual void OnMouse(CControl* pObj, int nEvent);

	virtual void OnLButton(CControl* pObj, int nEvent );

	virtual void OnRButton(CControl* pObj, int nEvent);

	virtual wchar_t* GetType();
	
	CControl* Clone() ;

	virtual bool RegisterControl() ;

	bool Load(wchar_t* pXmlBuffer);

private:
	HDC		     m_hDC;
	CTypeInfo*	 m_typeInfo;
	int			 m_nId;

	RECT		m_rect;
	DWORD		m_dwBkColor;
	wchar_t*	m_pBckImg;
	bool		m_visable;
};
