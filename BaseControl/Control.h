#pragma once

class CTypeInfo;
class CTypeControl;
class _DLL_DEC CControl
{
public:
	CControl(void);
	virtual ~CControl(void);

	virtual void Draw();

	virtual void OnMouse(CControl* pObj, int nEvent);

	virtual void OnLButton(CControl* pObj, int nEvent );

	virtual void OnRButton(CControl* pObj, int nEvent);

	wchar_t* GetType();
	
	CControl* Clone() ;

	virtual bool RegisterControl() ;

	virtual bool Load(wchar_t* pXmlBuffer);

	void Show();
	void Hide();

protected:
	CTypeInfo*	 m_typeInfo;
	int			 m_nId;

	RECT		m_rect;
	DWORD		m_dwBkColor;
	DWORD		m_dwFrameColor;
	wchar_t*	m_pBckImg;


	bool		m_bvisable;
	int			m_nZindex;
public:
	CTypeControl* GetManage();
	void RealseManage();
	static CTypeControl*	m_pManage;

};
