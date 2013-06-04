#pragma once

class CCtrlState
{
public:
	CCtrlState(void);
	~CCtrlState(void);

	bool Show();
	void SubShow();
	void Hide();
private:
	int		m_nRelateZindex;
	int		m_nAbsuluteZindex;
	int		m_nCtrlId;
	int		m_nCurZindex;
};
