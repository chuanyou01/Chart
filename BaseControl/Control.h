#pragma once

class CControl
{
public:
	CControl(void);
	virtual ~CControl(void);

	virtual void Draw()=0;

	virtual void OnMouse(CControl* pObj, int nEvent)=0;

	virtual void OnLButton(CControl* pObj, int nEvent )=0;

	virtual void OnRButton(CControl* pObj, int nEvent)=0;

	virtual string GetType()=0;

	virtual CControl* Clone()=0;
};
