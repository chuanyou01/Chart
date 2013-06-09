#pragma once

class CControl;
class CTypeControl
{
public:
	CTypeControl(void);
	~CTypeControl(void);

	bool RegisterControl(wchar_t* pCtrlName, CControl* pEntity);

	CControl* CreateControl(wchar_t* pCtrlName);

	CControl* LoadControl(wchar_t* pStrXml);

	CControl* LoadControl(string& strXml);

private:
	map<wchar_t*, CControl*>	m_mapCtl;
};


